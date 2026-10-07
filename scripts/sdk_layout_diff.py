#!/usr/bin/env python3
"""Compare the SDK's generated struct headers (Windows reflection) with the live macOS RTTI layout dump.

  sdk_layout_diff.py [--dump data/rtti_layout_macos.json] [--plugin-sources DIR ...] [--classes NAME ...] [--self-test]

Gated classes (named with --classes, or used by the plugin sources) fail on: a different class size, or any named SDK
field that is missing on macOS or at another offset. Comparing only fields present on both sides would hide fields that
macOS lays out elsewhere, so a missing field is a failure. Everything else is reported, not gated: Windows and macOS
legitimately differ (Itanium tail-padding reuse, pthread_mutex_t vs CRITICAL_SECTION). Exit 1 if a gated class differs.
The dump comes from RED4EXT_DUMP_RTTI (tools/cp-run rttidump); regenerate it on patch day.
"""

from __future__ import annotations

import argparse
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
GENERATED = ROOT / "include/RED4ext/Scripting/Natives/Generated"

STRUCT = re.compile(r"^struct (\w+)(?:\s*:\s*[\w:<>, ]+)?\s*$", re.M)
NAME = re.compile(r'static constexpr const char\* NAME = "([^"]+)";')
FIELD = re.compile(r"^\s+[\w:<>, *]+?\s+(\w+)(?:\[[^\]]*\])?;\s*//\s*([0-9A-Fa-f]+)\b", re.M)
SIZE = re.compile(r"RED4EXT_ASSERT_SIZE\((\w+),\s*(0x[0-9A-Fa-f]+)\)")
NAMESPACE = re.compile(r"^namespace ([\w:]+)\s*$", re.M)
ALIAS = re.compile(r"^using (\w+) = ([\w:]+);", re.M)


def parse_header(text: str) -> dict | None:
    """One generated header -> {rtti, cpp names, size, fields{name: offset}} (unkXX padding is skipped)."""
    name = NAME.search(text)
    struct = STRUCT.search(text)
    if not name or not struct:
        return None
    size = SIZE.search(text)
    ns = [m.group(1) for m in NAMESPACE.finditer(text) if m.start() < struct.start()]
    cpp = {struct.group(1), "::".join([*ns[-1:], struct.group(1)]) if ns else struct.group(1)}
    cpp |= {m.group(1) for m in ALIAS.finditer(text)}
    body = text[struct.end() : size.start() if size else len(text)]
    fields = {m.group(1): int(m.group(2), 16) for m in FIELD.finditer(body) if not m.group(1).startswith("unk")}
    return {"rtti": name.group(1), "cpp": cpp, "size": int(size.group(2), 16) if size else None, "fields": fields}


def load_sdk() -> dict[str, dict]:
    out = {}
    for path in GENERATED.rglob("*.hpp"):
        parsed = parse_header(path.read_text(errors="ignore"))
        if parsed:
            out[parsed["rtti"]] = parsed
    return out


def diff_class(sdk: dict, mac: dict | None) -> list[str]:
    if mac is None:
        return ["class not found in the macOS dump"]
    problems = []
    if sdk["size"] is not None and sdk["size"] != mac["size"]:
        problems.append(f"size {sdk['size']:#x} (SDK) vs {mac['size']:#x} (macOS)")
    props = {p["name"]: p["offset"] for p in mac["props"]}
    for field, offset in sdk["fields"].items():
        if field not in props:
            problems.append(f"{field}: SDK {offset:#x}, not a macOS property")
        elif props[field] != offset:
            problems.append(f"{field}: SDK {offset:#x}, macOS {props[field]:#x}")
    return problems


def used_by(sources: list[Path], sdk: dict[str, dict]) -> set[str]:
    text = "\n".join(p.read_text(errors="ignore") for d in sources for p in d.rglob("*") if p.suffix in (".hpp", ".cpp", ".h"))
    tokens = set(re.findall(r"[A-Za-z_][\w:]*", text))
    tails = {t.split("::", 1)[1] for t in tokens if t.startswith(("Red::", "RED4ext::"))}
    return {rtti for rtti, s in sdk.items() if s["cpp"] & tails or rtti in tails}


def self_test() -> int:
    sdk = load_sdk()
    wlr = sdk["inkWidgetLibraryResource"]
    mac = {"size": 0xA0, "props": [{"name": n, "offset": o} for n, o in
           [("rootResolution", 0x39), ("rootDefinitionIndex", 0x3C), ("libraryItems", 0x40), ("externalLibraries", 0x50)]]}
    problems = diff_class(wlr, mac)
    assert any(p.startswith("rootResolution: SDK 0x40, macOS 0x39") for p in problems), problems
    assert any(p.startswith("libraryItems: SDK 0x48, macOS 0x40") for p in problems), problems
    assert any(p.startswith("version:") and "not a macOS property" in p for p in problems), problems
    assert any(p.startswith("size 0xa8") for p in problems), problems
    assert diff_class({"size": 8, "fields": {"a": 0}}, {"size": 8, "props": [{"name": "a", "offset": 0}]}) == []
    print("self-test ok")
    return 0


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--dump", type=Path, default=ROOT / "data/rtti_layout_macos.json")
    ap.add_argument("--plugin-sources", type=Path, action="append", default=[])
    ap.add_argument("--classes", nargs="*", default=[])
    ap.add_argument("--self-test", action="store_true")
    ap.add_argument("-v", "--verbose", action="store_true", help="list every differing class, not only gated ones")
    args = ap.parse_args()
    if args.self_test:
        return self_test()

    dump = json.loads(args.dump.read_text())
    mac = dump["classes"]
    sdk = load_sdk()
    gated = set(args.classes) | used_by(args.plugin_sources, sdk)

    differing = {name: problems for name, s in sdk.items() if (problems := diff_class(s, mac.get(name)))}
    print(f"dump {dump.get('uuid')}: {len(sdk)} SDK classes, {len(sdk) - len(differing)} match macOS, "
          f"{len(differing)} differ")
    failed = sorted(gated & differing.keys())
    for name in sorted(differing if args.verbose else failed):
        print(f"{'GATED ' if name in gated else ''}{name}:")
        for p in differing[name]:
            print(f"    {p}")
    if gated:
        print(f"gated: {len(gated)} classes, {len(failed)} differ")
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
