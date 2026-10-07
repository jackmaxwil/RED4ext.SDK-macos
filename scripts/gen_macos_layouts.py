#!/usr/bin/env python3
"""Emit macOS struct layouts into the generated SDK headers, from the live macOS RTTI dump.

  gen_macos_layouts.py [--dump data/rtti_layout_macos.json] [--check] [--verify] [--report FILE]

For every class in include/RED4ext/Scripting/Natives/Generated/** whose macOS layout (data/rtti_layout_macos.json)
differs from what clang makes of the Windows header, the field block and the size assert become

    #ifdef __APPLE__
        <the header's own fields at their macOS offsets, uint8_t unkXX[] for every byte the dump does not describe>
    #else
        <the Windows block, unchanged>
    #endif

followed by RED4EXT_ASSERT_SIZE and one RED4EXT_ASSERT_OFFSET per field for macOS (the Windows assert stays in #else).
The input is always the Windows block, so a second run is a no-op.

Rules:
  * Offsets come only from the dump. A Windows field the dump does not have is reported and becomes padding; a macOS
    property the Windows header does not name stays opaque (its C++ type is not known here). 2.3.1 registers some
    base-class properties on every derived class instead (questPuppetNodeType::puppetRef); such a field stays in the
    base when all derived registrations inside the base agree on offset and type.
  * Field types are the header's own; padding sizes come from the dump's type sizes.
  * Itanium reuses a base's tail padding. A derived class's padding therefore starts at the base's *data* end as clang
    lays it out (dsize), not at sizeof(base). When a derived class puts a field inside its base's sizeof, the base
    stops its trailing padding at that field (dsize <= offset < sizeof) instead of padding to sizeof, so clang reuses
    the tail exactly like the game. Two things C++ needs spelled out for that: the base's alignment when the dump's
    fields do not imply it (`alignas(N)` on its first padding), and, for a base without a base class, that it is not a
    POD (clang never reuses a POD's tail; a user-provided destructor, no vptr). Hand-written bases (the redirect
    headers, ISerializable, IScriptable, the engines) are measured by compiling a probe.
  * A class the macOS game does not have keeps its Windows layout and gets no macOS assert.
  * --verify compiles every generated header with RED4EXT_ENABLE_MACOS_LAYOUT_ASSERTS, so every emitted offset and
    size is checked by clang.

The dump is the source of truth; regenerate it on patch day (tools/cp-run rttidump), then rerun this script.
"""

from __future__ import annotations

import argparse
import json
import re
import subprocess
import sys
import tempfile
from concurrent.futures import ThreadPoolExecutor
from dataclasses import dataclass, field
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
INCLUDE = ROOT / "include"
GENERATED = INCLUDE / "RED4ext/Scripting/Natives/Generated"
CPP_KEYWORDS = {"auto", "double", "enum", "float", "operator", "struct", "void"}
MAX_ALIGN = 16  # no game type is aligned to more than 16, so tail padding is shorter than that
HOLDER = 1 << 0x15  # CProperty::Flags inValueHolder: the value lives in the script holder, not in the instance

NAME = re.compile(r'static constexpr const char\* NAME = "([^"]+)";')
STRUCT = re.compile(r"^struct (?:__declspec\(align\((0x[0-9A-Fa-f]+)\)\) )?(\w+)(?:\s*:\s*([\w:<>, ]+))?\s*$", re.M)
BODY = re.compile(r"(    static constexpr const char\* ALIAS = [^;\n]+;\n\n)(.*?)(^};\n)", re.S | re.M)
SIZE_LINE = re.compile(r"^RED4EXT_ASSERT_SIZE\((\w+), (0x[0-9A-Fa-f]+)\);\n", re.M)
APPLE_BLOCK = re.compile(r"^#ifdef __APPLE__\n(.*?)^#else\n(.*?)^#endif\n", re.S | re.M)
FIELD = re.compile(r"^    (alignas\(\d+\) )?(.+) (\w+)((?:\[[^\]]*\])?); // ([0-9A-F]+)(?: -- (.+))?$")
PAD = re.compile(r"^    uint8_t unk[0-9A-F]+\[0x[0-9A-F]+ - 0x[0-9A-F]+\]; // [0-9A-F]+$")


@dataclass
class Field:
    prefix: str  # "alignas(16) " or ""
    type: str
    cpp: str
    array: str
    suffix: str  # " -- real name" or ""
    rtti: str
    pragma: str  # "#pragma warning(suppress : 4324)\n" kept in front of alignas fields, or ""

    def line(self, offset: int) -> str:
        return f"{self.pragma}    {self.prefix}{self.type} {self.cpp}{self.array}; // {offset:02X}{self.suffix}"


@dataclass
class Header:
    path: Path
    text: str
    rtti: str
    cpp: str
    align: int  # __declspec(align) on the struct, 0 if none
    win_lines: list[str]
    fields: list[Field] = field(default_factory=list)


def pad(start: int, end: int) -> str:
    return f"    uint8_t unk{start:02X}[0x{end:X} - 0x{start:X}]; // {start:X}"


def windows_parts(text: str) -> tuple[re.Match, str, re.Match, str] | None:
    """The struct body and size-assert matches, and their Windows contents (unwrapping a previous run's #ifdef)."""
    body = BODY.search(text)
    if not body:
        return None
    lines = body.group(2)
    if (block := APPLE_BLOCK.fullmatch(lines)) is not None:
        lines = block.group(2)
    rest = text[body.end() :]
    if (block := APPLE_BLOCK.match(rest)) is not None:
        size = SIZE_LINE.fullmatch(block.group(2))
        return (body, lines, block, size.group(0)) if size else None
    size = SIZE_LINE.match(rest)
    return (body, lines, size, size.group(0)) if size else None


def parse(path: Path) -> Header | None:
    text = path.read_text()
    if "\n/*\n" in text:  # redirect header: the struct is hand-written elsewhere
        return None
    name, struct = NAME.search(text), STRUCT.search(text)
    parts = windows_parts(text)
    if not name or not struct or not parts:
        return None
    hdr = Header(path, text, name.group(1), struct.group(2), int(struct.group(1) or "0", 16), parts[1].splitlines())
    pragma = ""
    for line in hdr.win_lines:
        if PAD.match(line):
            continue
        if line.startswith("#pragma warning"):
            pragma = f"{line}\n"
            continue
        m = FIELD.match(line)
        if not m:
            raise SystemExit(f"{path}: cannot parse field line {line!r}")
        prefix, typ, cpp, array, _, real = m.groups()
        hdr.fields.append(Field(prefix or "", typ, cpp, array, f" -- {real}" if real else "", real or cpp, pragma))
        pragma = ""
    return hdr


def probe_handwritten(dump: dict) -> dict[str, tuple[int, int, int]]:
    """sizeof, alignof and dsize (clang) of the hand-written classes the redirect headers point at, and of the roots."""
    rows = [("ISerializable", "RED4ext::ISerializable", "RED4ext/ISerializable.hpp"),
            ("IScriptable", "RED4ext::IScriptable", "RED4ext/Scripting/IScriptable.hpp"),
            ("BaseGameEngine", "RED4ext::BaseGameEngine", "RED4ext/GameEngine.hpp"),
            ("CGameEngine", "RED4ext::CGameEngine", "RED4ext/GameEngine.hpp")]
    for path in sorted(GENERATED.rglob("*.hpp")):
        text = path.read_text()
        if "\n/*\n" not in text:
            continue
        head = text.split("\n/*\n")[0]
        cls = re.search(r"RED4EXT_ASSERT_SIZE\(([\w:]+),", head).group(1)
        ns = re.findall(r"^namespace ([\w:]+)$", head, re.M)
        rows.append((NAME.search(text).group(1), "::".join(["RED4ext", *ns[1:], cls]), str(path.relative_to(INCLUDE))))
    def measure(row: tuple[str, str, str], tmp: str) -> tuple[str, tuple[int, int, int] | None]:
        rtti, cpp, inc = row  # RED4ext.hpp first: some headers do not compile on their own
        src, exe = Path(tmp, f"{rtti}.cpp"), Path(tmp, rtti)
        src.write_text(f"#include <RED4ext/RED4ext.hpp>\n#include <{inc}>\n#include <cstdio>\n#include <cstddef>\n"
                       f"struct D_ : {cpp} {{ char c; }};\n"
                       f'int main() {{ printf("%zu %zu %zu", sizeof({cpp}), alignof({cpp}), offsetof(D_, c)); }}\n')
        r = subprocess.run(["clang++", "-std=c++20", "-w", f"-I{INCLUDE}", f"-I{ROOT / 'vendor/D3D12MemAlloc'}",
                            str(src), "-o", str(exe)], capture_output=True, text=True)
        if r.returncode:
            print(f"probe: {rtti} ({inc}) does not compile, its derived classes keep the Windows layout", file=sys.stderr)
            return rtti, None
        return rtti, tuple(int(v) for v in subprocess.run([str(exe)], capture_output=True, text=True).stdout.split())

    with tempfile.TemporaryDirectory() as tmp, ThreadPoolExecutor() as pool:
        return {k: v for k, v in pool.map(lambda row: measure(row, tmp), rows) if v}


class Planner:
    def __init__(self, dump: dict, headers: dict[str, Header], handwritten: dict[str, tuple[int, int, int]]):
        self.classes, self.types, self.headers, self.hand = dump["classes"], dump["types"], headers, handwritten
        self.layout: dict[str, tuple[int, int, int] | None] = {}  # rtti -> (sizeof, alignof, dsize) as clang lays it out
        self.plans: dict[str, tuple[list[str], list[tuple[str, int]], int] | str] = {}  # or "absent"
        self.report: dict[str, list[str]] = {}
        self.children: dict[str, list[str]] = {}
        for name, cls in self.classes.items():
            self.children.setdefault(cls["parent"], []).append(name)
        self.hoisted = {rtti: self._hoist(rtti) for rtti in headers if rtti in self.classes}
        self.bound = self._tail_bounds()

    def own(self, rtti: str) -> dict[str, dict]:
        return {p["name"]: p for p in self.classes[rtti]["props"] if not p["flags"] & HOLDER}

    def size_of(self, prop: dict) -> int:
        return self.types[prop["type"]]["size"]

    def descendants(self, rtti: str):
        for child in self.children.get(rtti, []):
            yield child
            yield from self.descendants(child)

    def _hoist(self, rtti: str) -> dict[str, dict]:
        """Windows fields of `rtti` that 2.3.1 registers on its derived classes instead (e.g. questPuppetNodeType's
        puppetRef). One is kept only when every derived registration inside this class's sizeof agrees on offset and
        type; that offset is then data from the dump, not a guess."""
        own, out = self.own(rtti), {}
        for f in self.headers[rtti].fields:
            if f.rtti in own:
                continue
            size = self.classes[rtti]["size"]  # a registration past this class is the derived class's own field
            seen = {(p["offset"], p["type"]) for d in self.descendants(rtti) for p in self.own(d).values()
                    if p["name"] == f.rtti and p["offset"] < size}
            if len(seen) == 1 and (off_type := seen.pop())[1] in self.types:
                prop = {"name": f.rtti, "offset": off_type[0], "type": off_type[1]}
                if prop["offset"] + self.size_of(prop) <= size:
                    out[f.rtti] = prop
        return out

    def known_end(self, rtti: str) -> int:
        """End of the last field the dump knows for rtti or its bases."""
        chain = [rtti, *self._ancestors(rtti)]
        props = [p for c in chain for p in (*self.own(c).values(), *self.hoisted.get(c, {}).values())]
        return max((p["offset"] + self.size_of(p) for p in props if p["type"] in self.types), default=0)

    def in_tail(self, rtti: str, offset: int) -> bool:
        """Can `offset` be in rtti's tail padding? Tail padding is shorter than the alignment, and the alignment
        (at most MAX_ALIGN) divides sizeof; it also has to come after every field the dump knows for the class."""
        size = self.classes[rtti]["size"]
        return 0 < size - offset < min(MAX_ALIGN, size & -size) and offset >= self.known_end(rtti)

    def _tail_bounds(self) -> dict[str, int]:
        """rtti -> lowest offset at which some SDK descendant stores its own data inside this class's tail padding."""
        bound: dict[str, int] = {}
        for rtti in self.headers:
            if rtti not in self.classes:
                continue
            for p in self.own(rtti).values():
                parent = self.classes[rtti]["parent"]
                while parent in self.classes and self.classes[parent]["size"] > p["offset"]:
                    if self.in_tail(parent, p["offset"]):
                        bound[parent] = min(bound.get(parent, p["offset"]), p["offset"])
                    parent = self.classes[parent]["parent"]
        return bound

    def type_align(self, name: str) -> int:
        if name.startswith("["):
            return self.type_align(name[name.index("]") + 1 :])
        if name in self.headers and (lay := self.clang(name)):
            return lay[1]
        if name in self.hand:
            return self.hand[name][1]
        return self.types.get(name, {}).get("align", 1)

    def clang(self, rtti: str) -> tuple[int, int, int] | None:
        if rtti in self.hand:
            return self.hand[rtti]
        if rtti not in self.headers:
            return None
        if rtti not in self.layout:
            self.layout[rtti] = None  # cycle guard
            self.layout[rtti] = self._plan(rtti)
        return self.layout[rtti]

    def _plan(self, rtti: str) -> tuple[int, int, int] | None:
        hdr, mac, notes = self.headers[rtti], self.classes.get(rtti), self.report.setdefault(rtti, [])
        if mac is None:
            notes.append("not in the macOS dump (not a macOS class): Windows layout kept, no macOS assert")
            self.plans[rtti] = "absent"
            return None
        parent = mac["parent"]
        if parent:
            base = self.clang(parent)
            if base is None:
                notes.append(f"base {parent} has no known clang layout: Windows layout kept")
                return None
            base_size, align, start = base
        else:
            base_size, align, start = 0, 1, 0
        align = max(align, hdr.align)

        props, hoisted = self.own(rtti), self.hoisted[rtti]
        placed = []
        for f in hdr.fields:
            p = props.get(f.rtti) or hoisted.get(f.rtti)
            if p is None:
                notes.append(f"{f.rtti}: named by the Windows header, not a macOS property -> padding")
            elif p["type"] not in self.types:
                notes.append(f"{f.rtti}: type {p['type']} has no size in the dump -> padding")
            elif self.types[p["type"]]["kind"] == 13 and p["offset"] % self.size_of(p):
                # A BitField is a struct of uintN_t bit members in the SDK (N-aligned); the game packs some at odd
                # offsets (worldLightChannelShapeNode::channels at 0x4D), which C++ cannot place there.
                notes.append(f"{f.rtti}: bitfield {p['type']} at {p['offset']:#x} is not {self.size_of(p)}-aligned "
                             f"as its C++ type is -> padding")
            else:
                if f.rtti in hoisted:
                    notes.append(f"{f.rtti}: registered on the derived classes at {p['offset']:#x}, kept here")
                placed.append((p["offset"], self.size_of(p), f, p["type"]))
        placed.sort(key=lambda x: x[0])
        named = {f.rtti for f in hdr.fields}
        inherited = {n for a in self._ancestors(rtti) for n in self.hoisted.get(a, {})}
        extra = sorted(n for n in props if n not in named and n not in inherited)
        if extra:
            notes.append(f"macOS properties the Windows header does not name (kept opaque): {', '.join(extra)}")

        lines, asserts, cursor = [], [], start
        for off, size, f, typ in placed:
            if off < start:
                if parent and self.in_tail(parent, off):
                    notes.append(f"{f.rtti} at {off:#x} reuses the tail padding of {parent}, but clang gives that base "
                                 f"dsize {start:#x}: fix the base, Windows layout kept")
                    return None
                notes.append(f"{f.rtti} at {off:#x} lies inside the base's data (dsize {start:#x}) -> padding")
                continue
            if off < cursor:
                notes.append(f"{f.rtti} at {off:#x} overlaps the data before it (ends {cursor:#x}): Windows layout kept")
                return None
            if off > cursor:
                lines.append(pad(cursor, off))
            lines.append(f.line(off))
            if f.cpp not in CPP_KEYWORDS:  # e.g. a field named `operator` (the header does not compile anyway)
                asserts.append((f.cpp, off))
            cursor = off + size
            align = max(align, self.type_align(typ))

        size = mac["size"]
        bound = self.bound.get(rtti)
        if bound is not None:
            if bound < cursor:
                notes.append(f"a derived class stores data at {bound:#x}, inside this class's fields: Windows kept")
                return None
            if bound > cursor:
                lines.append(pad(cursor, bound))
            cursor = bound
            # The game's class is more aligned than the fields the dump names (a vptr or a native member in the opaque
            # part). Make that explicit on the first padding that starts on such a boundary.
            need = next((a for a in (1, 2, 4, 8, 16) if a >= align and -(-cursor // a) * a == size), None)
            if need and need > align:
                for i, line in enumerate(lines):
                    m = re.match(r"    uint8_t unk([0-9A-F]+)\[", line)
                    if m and int(m.group(1), 16) % need == 0:
                        lines[i] = f"    alignas({need}) {line[4:]}"
                        align = need
                        break
            if not parent:
                # Itanium (Apple: the C++11 POD rule) never reuses a POD's tail padding. The game's class is not a POD
                # (its opaque head is a vptr); a user-provided destructor makes ours non-POD too, without a vptr.
                lines.append(f"    ~{hdr.cpp}() {{}} // non-POD, so clang reuses the tail padding like the game")
        elif placed or hdr.win_lines or base_size != size:
            if size > cursor:
                lines.append(pad(cursor, size))
            cursor = max(cursor, size)
        else:
            cursor = start  # no own data: sizeof/dsize are the base's
        sizeof = max(-(-cursor // align) * align, base_size)
        if sizeof != size:
            notes.append(f"clang would make this {sizeof:#x}, the dump says {size:#x}: Windows layout kept")
            return None
        self.plans[rtti] = (lines, asserts, size)
        return size, align, cursor

    def _ancestors(self, rtti: str):
        while rtti := self.classes.get(rtti, {}).get("parent"):
            yield rtti


def render(hdr: Header, plan: tuple[list[str], list[tuple[str, int]], int] | str | None) -> str:
    body, win_lines, size_match, size_line = windows_parts(hdr.text)
    win = "".join(f"{line}\n" for line in hdr.win_lines)
    if plan == "absent":
        new_body = win
        new_size = (f"#ifdef __APPLE__\n// {hdr.rtti} is not in the macOS RTTI dump: no macOS layout to assert\n"
                    f"#else\n{size_line}#endif\n")
    elif plan is None or ("\n".join(plan[0]) == "\n".join(hdr.win_lines)  # lines may carry a #pragma line
                          and plan[2] == int(SIZE_LINE.match(size_line).group(2), 16)):
        new_body, new_size = win, size_line
    else:
        lines, asserts, size = plan
        apple = "".join(f"{line}\n" for line in lines)
        new_body = f"#ifdef __APPLE__\n{apple}#else\n{win}#endif\n"
        cls = SIZE_LINE.match(size_line).group(1)
        checks = "".join(f"RED4EXT_ASSERT_OFFSET({cls}, {m}, 0x{o:X});\n" for m, o in asserts)
        new_size = f"#ifdef __APPLE__\nRED4EXT_ASSERT_SIZE({cls}, 0x{size:X});\n{checks}#else\n{size_line}#endif\n"
    t = hdr.text
    return t[: body.start(2)] + new_body + t[body.end(2) : size_match.start() + body.end()] + new_size + \
        t[size_match.end() + body.end() :]


REDIRECT_SIZE = re.compile(r"^(?:#ifdef __APPLE__\nRED4EXT_ASSERT_SIZE\([\w:]+, 0x[0-9A-F]+\);\n#else\n)?"
                           r"(RED4EXT_ASSERT_SIZE\(([\w:]+), (0x[0-9A-Fa-f]+)\);\n)(?:#endif\n)?", re.M)


def render_redirect(text: str, classes: dict, hand: dict[str, tuple[int, int, int]]) -> str:
    """A redirect header asserts the hand-written class's size. Give macOS the dump's size once the hand-written class
    has it (probed); until then the Windows assert stays, so sdk_layout_diff.py keeps reporting the class."""
    head, sep, rest = text.partition("\n/*\n")
    rtti = NAME.search(rest)
    m = REDIRECT_SIZE.search(head)
    if not sep or not rtti or not m or rtti.group(1) not in classes:
        return text
    win, cls, size = m.group(1), m.group(2), int(m.group(3), 16)
    mac = classes[rtti.group(1)]["size"]
    fixed = rtti.group(1) in hand and hand[rtti.group(1)][0] == mac
    new = win if mac == size or not fixed else \
        f"#ifdef __APPLE__\nRED4EXT_ASSERT_SIZE({cls}, 0x{mac:X});\n#else\n{win}#endif\n"
    return head[: m.start()] + new + head[m.end() :] + sep + rest


def verify() -> int:
    """Compile every generated header with the macOS layout asserts on; returns the number of failing asserts."""
    includes = [f"#include <{p.relative_to(INCLUDE)}>\n" for p in sorted(GENERATED.rglob("*.hpp"))]
    with tempfile.TemporaryDirectory() as tmp:
        src = Path(tmp, "all.cpp")
        while True:  # a fatal error (missing include) stops clang: drop that header and go again
            src.write_text("#include <RED4ext/RED4ext.hpp>\n" + "".join(includes))
            r = subprocess.run(["clang++", "-std=c++20", "-fsyntax-only", "-ferror-limit=0", "-w",
                                "-DRED4EXT_ENABLE_MACOS_LAYOUT_ASSERTS", f"-I{INCLUDE}",
                                f"-I{ROOT / 'vendor/D3D12MemAlloc'}", str(src)], capture_output=True, text=True)
            fatal = re.search(rf"In file included from {re.escape(str(src))}:(\d+):(?:(?!\n[^\n]*In file included from "
                              rf"{re.escape(str(src))}).)*?fatal error", r.stderr, re.S)
            if not fatal:
                break
            print(f"verify: skipped {includes.pop(int(fatal.group(1)) - 2).strip()} (fatal error)")
    failures = [l for l in r.stderr.splitlines() if "error: static assertion failed" in l]
    other = [l for l in r.stderr.splitlines() if "error:" in l and "static assertion" not in l]
    for line in failures + other:
        print(line)
    print(f"verify: {len(failures)} failing layout asserts, {len(other)} other compile errors")
    return len(failures)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--dump", type=Path, default=ROOT / "data/rtti_layout_macos.json")
    ap.add_argument("--check", action="store_true", help="write nothing; exit 1 if a header would change")
    ap.add_argument("--verify", action="store_true", help="compile all generated headers with the macOS asserts on")
    ap.add_argument("--report", type=Path, help="write the per-class notes here")
    args = ap.parse_args()

    dump = json.loads(args.dump.read_text())
    # Hand-written classes can embed generated ones, so their probed layout depends on what this script writes:
    # repeat until the probe is stable, which makes the next run a no-op.
    hand, changed_total = None, set()
    for _ in range(5):
        headers = {h.rtti: h for p in sorted(GENERATED.rglob("*.hpp")) if (h := parse(p))}
        probed = probe_handwritten(dump)
        if probed == hand:
            break
        hand, planner = probed, Planner(dump, headers, probed)
        for rtti in headers:
            planner.clang(rtti)
        changed = set()
        for rtti, hdr in headers.items():
            if (new := render(hdr, planner.plans.get(rtti))) != hdr.text:
                changed.add(rtti)
                if not args.check:
                    hdr.path.write_text(new)
        changed_total |= changed
        if args.check or not changed:
            break
    for path in sorted(GENERATED.rglob("*.hpp")):
        text = path.read_text()
        if "\n/*\n" in text and (new := render_redirect(text, dump["classes"], hand)) != text:
            changed_total.add(path.stem)
            if not args.check:
                path.write_text(new)
    planned = sum(isinstance(planner.plans.get(r), tuple) for r in headers)
    apple = sum(isinstance(p := planner.plans.get(r), tuple) and "#ifdef __APPLE__" in render(h, p)
                for r, h in headers.items())
    changed = len(changed_total)
    notes = {k: v for k, v in planner.report.items() if v}
    kept = sorted(k for k, v in notes.items() if any("Windows layout kept" in n or "Windows kept" in n for n in v))
    print(f"dump {dump.get('uuid')}: {len(headers)} classes, {planned} laid out from the dump ({apple} need a macOS "
          f"block, the rest match the Windows header), {changed} files "
          f"{'would change' if args.check else 'written'}, {len(kept)} left on the Windows layout")
    for rtti in kept:
        print(f"  {rtti}: {'; '.join(n for n in notes[rtti] if 'kept' in n)}")
    if args.report:
        args.report.write_text("".join(f"{k}\n" + "".join(f"    {n}\n" for n in v) for k, v in sorted(notes.items())))
    if args.verify and verify():
        return 1
    return 1 if args.check and changed else 0


if __name__ == "__main__":
    sys.exit(main())
