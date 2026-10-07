#!/usr/bin/env python3
"""Validate Cyberpunk 2077 macOS address tables against the game's Mach-O (RESUME_PLAN Phase 2.2).

Sources (any mix, given as paths; default = this repo's canonical DB):
  *.json with "Addresses": [{"hash": "<dec>", "offset": "<seg>:0x<off>"}]   seg-relative,
        seg 1=__TEXT 2=__DATA_CONST 3=__DATA (as in Addresses.cpp / Relocation-inl.hpp)
  *.json with "hooks":     legacy hook lists (same offset format, carry names)
  *.cpp  with m_addressTable[<dec>] = 0x<off>;  plugin resolvers, image-base relative

Checks: zero offsets, segment bounds, function in __text + 4-byte aligned + listed in
LC_FUNCTION_STARTS + recognisable prologue (warning only: leaf functions have none),
data in __DATA*, shared addresses, stats vs contents, and same hash -> same address
across sources. Without the game binary, only checks the embedded 2.3.1 layout supports.

Exit 1 on any error. `--self-test` runs the built-in check.
"""

from __future__ import annotations

import argparse
import json
import os
import re
import struct
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
DEFAULT_BINARY = Path.home() / "Library/Application Support/Steam/steamapps/common/Cyberpunk 2077/Cyberpunk2077.orig"

# Steam 2.3.1 build 5314028, UUID A6656ADC-FBE2-36A4-9B9D-B4A9DE645089. Used when the binary is absent (CI).
KNOWN_LAYOUT = {
    "segments": {
        "__TEXT": (0x100000000, 0x6DE0000, 0),
        "__DATA_CONST": (0x106DE0000, 0x5B4000, 115212288),
        "__DATA": (0x107394000, 0x1D7C000, 121192448),
    },
    "sections": {("__TEXT", "__text"): (0x100002070, 0x4A37630)},
}

SEGS = {1: "__TEXT", 2: "__DATA_CONST", 3: "__DATA"}

# hash -> justification. Zero offset = deliberately unresolved on macOS.
ALLOW_ZERO = {
    1239944840: "g_DeviceData: D3D12 device data, no Metal equivalent",
    2508272872: "Allocator_CreateResource: D3D12MA, no Metal equivalent",
}
# frozenset of hashes -> justification. Hashes that may legitimately share one address.
ALLOW_SHARED: dict[frozenset[int], str] = {}


# --------------------------------------------------------------------------- Mach-O


def read_macho(path: Path) -> dict:
    data = path.read_bytes()
    magic, _, _, _, ncmds, _, _, _ = struct.unpack_from("<IiiIIIII", data, 0)
    if magic != 0xFEEDFACF:
        raise SystemExit(f"{path}: not a thin 64-bit Mach-O (magic 0x{magic:08X})")
    segments, sections, starts_cmd, uuid = {}, {}, None, None
    off = 32
    for _ in range(ncmds):
        cmd, size = struct.unpack_from("<II", data, off)
        if cmd == 0x19:  # LC_SEGMENT_64
            seg = data[off + 8 : off + 24].rstrip(b"\0").decode()
            vmaddr, vmsize, fileoff, _, _, _, nsects, _ = struct.unpack_from("<QQQQiiII", data, off + 24)
            segments[seg] = (vmaddr, vmsize, fileoff)
            for i in range(nsects):
                s = off + 72 + i * 80
                sect = data[s : s + 16].rstrip(b"\0").decode()
                addr, sz = struct.unpack_from("<QQ", data, s + 32)
                sections[(seg, sect)] = (addr, sz)
        elif cmd == 0x26:  # LC_FUNCTION_STARTS
            starts_cmd = struct.unpack_from("<II", data, off + 8)
        elif cmd == 0x1B:  # LC_UUID
            uuid = data[off + 8 : off + 24].hex().upper()
        off += size

    starts = set()
    if starts_cmd:
        p, end = starts_cmd[0], starts_cmd[0] + starts_cmd[1]
        addr = segments["__TEXT"][0]
        while p < end:
            delta = shift = 0
            while True:
                b = data[p]
                p += 1
                delta |= (b & 0x7F) << shift
                shift += 7
                if b < 0x80:
                    break
            if delta == 0:
                break
            addr += delta
            starts.add(addr)
    return {"segments": segments, "sections": sections, "starts": starts, "uuid": uuid, "data": data}


def is_prologue(insn: int) -> bool:
    return (
        (insn & 0xFFC003E0) in (0xA98003E0, 0xA90003E0)  # STP Xt1, Xt2, [sp, #imm](!)
        or (insn & 0xFFC003E0) in (0x6D8003E0, 0x6D0003E0)  # STP Dt1, Dt2, [sp, #imm](!)
        or (insn & 0xFF8003FF) == 0xD10003FF  # SUB sp, sp, #imm
        or (insn & 0xFFE00FE0) == 0xF8000FE0  # STR Xt, [sp, #imm]!
    )


# --------------------------------------------------------------------------- sources


def load_names(paths: list[Path]) -> tuple[dict[int, str], set[str]]:
    """hash -> name from `constexpr ... uint32_t Name = value`; plus names used as data (RelocPtr/Vtbl)."""
    names: dict[int, str] = {}
    data_names: set[str] = set()
    rx = re.compile(r"constexpr\s+(?:std::)?uint32_t\s+(\w+)\s*=\s*(0x[0-9A-Fa-f]+|\d+)")
    for p in paths:
        for f in [p] if p.is_file() else [*p.rglob("*.hpp"), *p.rglob("*.cpp")]:
            text = f.read_text(errors="replace")
            for n, v in rx.findall(text):
                names.setdefault(int(v, 0), n)
            data_names.update(re.findall(r"UniversalReloc(?:Ptr|Vtbl)\b[^;]*?AddressHashes::(\w+)", text, re.S))
    data_names.update(n for n in names.values() if n.endswith("_vtbl"))
    return names, data_names


def parse_seg_offset(s: str) -> tuple[int, int]:
    seg, off = s.split(":")
    return int(seg, 0), int(off, 16)


def load_source(path: Path) -> tuple[list[dict], dict | None]:
    """Returns (entries, stats). entry: hash, name, seg (None = image-relative), off, raw."""
    if path.suffix == ".cpp":
        entries, name = [], None
        for line in path.read_text(errors="replace").splitlines():
            if m := re.match(r"\s*//\s*(\w+)\s*\(", line):
                name = m.group(1)
            elif m := re.search(r"m_addressTable\[(\d+)\]\s*=\s*(0x[0-9A-Fa-f]+|\d+)", line):
                off = int(m.group(2), 0)
                entries.append({"hash": int(m.group(1)), "name": name, "seg": None, "off": off, "raw": hex(off)})
                name = None
        return entries, None
    obj = json.loads(path.read_text())
    rows = obj.get("Addresses") if "Addresses" in obj else obj.get("hooks")
    if not isinstance(rows, list):
        raise SystemExit(f"{path}: no 'Addresses' or 'hooks' list")
    entries = []
    for r in rows:
        seg, off = parse_seg_offset(r["offset"])
        entries.append({"hash": int(str(r["hash"]), 0), "name": r.get("name"), "seg": seg, "off": off, "raw": r["offset"],
                        "verified": r.get("verified") is True})
    return entries, obj.get("stats") if "Addresses" in obj else None


# --------------------------------------------------------------------------- validation


def locate(layout: dict, addr: int) -> tuple[str | None, str]:
    """(segment, "segment,section" or just segment)"""
    seg = next((n for n, (va, sz, _) in layout["segments"].items() if va <= addr < va + sz), None)
    sect = next((s for (sg, s), (va, sz) in layout["sections"].items() if sg == seg and va <= addr < va + sz), None)
    return seg, f"{seg},{sect}" if sect else str(seg)


def validate(sources: list[Path], layout: dict, names: dict[int, str], data_names: set[str],
             verified_only: bool = False) -> list[tuple]:
    """Returns [(level, source, hash, name, raw, message)]."""
    out: list[tuple] = []
    text_va = layout["segments"]["__TEXT"][0]
    text_sect = layout["sections"][("__TEXT", "__text")]
    starts, macho = layout.get("starts"), layout.get("data")
    by_hash: dict[int, list[tuple[str, int]]] = {}

    for src in sources:
        entries, stats = load_source(src)
        sname = f"{src.parent.name}/{src.name}"
        for e in entries:
            if e["name"]:
                names.setdefault(e["hash"], e["name"])

        def issue(level, e, msg):
            # --verified-only: the loader and SDK refuse unverified entries, so their defects cannot reach the game.
            if verified_only and level == "ERROR" and not e.get("verified", True):
                level = "UNVER"
            out.append((level, sname, e["hash"], names.get(e["hash"], "?"), e["raw"], msg))

        seen_hash: set[int] = set()
        by_addr: dict[int, list[dict]] = {}
        zeros = 0
        for e in entries:
            h, name = e["hash"], names.get(e["hash"])
            if h in seen_hash:
                issue("ERROR", e, "duplicate hash in this source")
            seen_hash.add(h)
            if e["off"] == 0:
                zeros += 1
                if h not in ALLOW_ZERO:
                    issue("ERROR", e, "zero offset (unresolved)")
                continue
            if e["seg"] is None:
                addr = text_va + e["off"]
            elif e["seg"] in SEGS:
                addr = layout["segments"][SEGS[e["seg"]]][0] + e["off"]
            else:
                issue("ERROR", e, f"unknown segment index {e['seg']}")
                continue
            by_addr.setdefault(addr, []).append(e)
            by_hash.setdefault(h, []).append((sname, addr))

            seg, where = locate(layout, addr)
            if e["seg"] is not None and seg != SEGS[e["seg"]]:
                hint = ""
                img_seg, img_where = locate(layout, text_va + e["off"])
                if img_seg:
                    hint = f"; as an image-relative offset it would be in {img_where}"
                issue("ERROR", e, f"offset is outside {SEGS[e['seg']]}{hint}")
                continue
            if seg is None:
                issue("ERROR", e, f"address 0x{addr:X} is outside the image")
                continue

            is_data = name in data_names if name else e["seg"] in (2, 3)
            if is_data:
                if seg not in ("__DATA_CONST", "__DATA"):
                    issue("ERROR", e, f"data address lies in {where}, expected __DATA_CONST/__DATA")
                continue

            if not (text_sect[0] <= addr < text_sect[0] + text_sect[1]):
                issue("ERROR", e, f"function address lies in {where}, not __TEXT,__text")
                continue
            if addr % 4:
                issue("ERROR", e, "function address is not 4-byte aligned")
                continue
            if starts is not None and addr not in starts:
                issue("ERROR", e, "not a function start (LC_FUNCTION_STARTS)")
            if macho is not None:
                va, _, fileoff = layout["segments"]["__TEXT"]
                insn = struct.unpack_from("<I", macho, addr - va + fileoff)[0]
                if not is_prologue(insn):
                    issue("WARN", e, f"no STP/SUB sp prologue (first insn 0x{insn:08X}; leaf function?)")

        for addr, group in by_addr.items():
            hashes = frozenset(e["hash"] for e in group)
            if len(hashes) > 1 and hashes not in ALLOW_SHARED:
                who = ", ".join(f"{names.get(x, '?')}({x})" for x in sorted(hashes))
                issue("ERROR", group[0], f"address 0x{addr:X} shared by {len(hashes)} hashes: {who}")

        if stats is not None:
            want = {"total": len(entries), "resolved": len(entries) - zeros, "unresolved": zeros}
            bad = {k: (stats.get(k), v) for k, v in want.items() if stats.get(k) != v}
            if bad:
                msg = ", ".join(f"{k}={s} but contents say {v}" for k, (s, v) in bad.items())
                out.append(("ERROR", sname, 0, "stats", "-", msg))

    for h, locs in by_hash.items():
        if len({a for _, a in locs}) > 1:
            groups: dict[int, list[str]] = {}
            for s, a in locs:
                groups.setdefault(a, []).append(s)
            msg = "; ".join(f"0x{a - text_va:X} in {', '.join(ss)}" for a, ss in groups.items())
            out.append(("ERROR", "<cross-source>", h, names.get(h, "?"), "-", f"image offsets disagree: {msg}"))
    return out


# --------------------------------------------------------------------------- main


def self_test() -> int:
    good, data_hash = 3791200470, 1518151849
    db = {
        "stats": {"total": 7, "resolved": 7, "unresolved": 0},
        "Addresses": [
            {"hash": str(good), "offset": "1:0x950AB8"},
            {"hash": "1", "offset": "1:0x6C3E9A1"},  # misaligned, outside __text
            {"hash": "2", "offset": "1:0x0"},  # zero
            {"hash": "3", "offset": "1:0x22EEAC"},  # shared with 4
            {"hash": "4", "offset": "1:0x22EEAC"},
            {"hash": str(data_hash), "offset": "1:0x6E50000"},  # beyond __TEXT
            {"hash": "5", "offset": "2:0x100"},  # data, fine
        ],
    }
    cpp = "// Foo (0x1)\nm_addressTable[1] = 0x22EEB0;\n// Main (0x0)\nm_addressTable[3791200470] = 0x950AB8;\n"
    with tempfile.TemporaryDirectory() as d:
        p, c = Path(d, "db.json"), Path(d, "t.cpp")
        p.write_text(json.dumps(db))
        c.write_text(cpp)
        res = validate([p, c], KNOWN_LAYOUT, {data_hash: "CGameEngine"}, {"CGameEngine"})
    errs = {(r[2], r[5].split(" ")[0]) for r in res if r[0] == "ERROR"}
    msgs = [r[5] for r in res if r[0] == "ERROR"]
    assert (1, "function") in errs, msgs  # 0x6C3E9A1 not in __text
    assert (2, "zero") in errs, msgs
    assert any("shared by 2 hashes" in m for m in msgs), msgs
    assert any(r[2] == data_hash and "outside __TEXT" in r[5] for r in res), msgs
    assert any("stats" == r[3] and "unresolved=0 but contents say 1" in r[5] for r in res), msgs
    assert any(r[1] == "<cross-source>" and r[2] == 1 for r in res), msgs  # 0x6C3E9A1 vs 0x22EEB0
    assert not any(r[2] in (good, 5) for r in res), msgs
    print("self-test ok")
    return 0


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("sources", nargs="*", type=Path)
    ap.add_argument("--binary", type=Path, default=Path(os.environ.get("CP2077_BINARY", DEFAULT_BINARY)))
    ap.add_argument("--names", type=Path, action="append", default=[], help="extra header/dir with hash constants")
    ap.add_argument("-q", "--quiet", action="store_true", help="hide warnings and unverified-entry findings")
    ap.add_argument("--verified-only", action="store_true",
                    help="fail only on entries marked \"verified\": true (what the loader and SDK will resolve)")
    ap.add_argument("--self-test", action="store_true")
    args = ap.parse_args()
    if args.self_test:
        return self_test()

    sources = args.sources or [ROOT / "cyberpunk2077_addresses.json"]
    if args.binary.is_file():
        layout = read_macho(args.binary)
        print(f"binary: {args.binary} (UUID {layout['uuid']}, {len(layout['starts'])} function starts)")
    else:
        layout = KNOWN_LAYOUT
        print(f"binary not found ({args.binary}): using embedded 2.3.1 layout; function-start/prologue checks skipped")

    names, data_names = load_names([ROOT / "include/RED4ext", *args.names])
    res = validate(sources, layout, names, data_names, args.verified_only)
    for level, src, h, name, raw, msg in sorted(res, key=lambda r: (r[1], r[0], r[3])):
        if level in ("WARN", "UNVER") and args.quiet:
            continue
        print(f"{level:5} {src}: {name} ({h}) {raw}: {msg}")
    nerr = sum(r[0] == "ERROR" for r in res)
    nunver = sum(r[0] == "UNVER" for r in res)
    print(f"{len(sources)} sources, {nerr} errors, {nunver} findings on unverified entries, "
          f"{len(res) - nerr - nunver} warnings")
    return 1 if nerr else 0


if __name__ == "__main__":
    sys.exit(main())
