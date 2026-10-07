#!/usr/bin/env python3
"""List the address-DB hashes a plugin dylib can resolve, and whether each is verified.

A plugin resolves game addresses by 32-bit hash. Those hashes are compiled into its code as immediates
(MOVZ/MOVK pairs or literal-pool loads) or into its data tables. Any DB hash found there is a requirement: the plugin
is only safe to load when all of them are verified.

Usage: plugin_requirements.py PLUGIN.dylib [--db cyberpunk2077_addresses.json] [--names HEADER ...]
Exit 1 if any requirement is unverified.
"""

from __future__ import annotations

import argparse
import json
import struct
from pathlib import Path

from validate_addresses import ROOT, load_names


def sections(data: bytes) -> dict[tuple[str, str], tuple[int, int]]:
    """(segment, section) -> (file offset, size) for a thin arm64 Mach-O."""
    magic, _, _, _, ncmds = struct.unpack_from("<IiiII", data, 0)
    if magic != 0xFEEDFACF:
        raise SystemExit("not a thin 64-bit Mach-O")
    out, off = {}, 32
    for _ in range(ncmds):
        cmd, size = struct.unpack_from("<II", data, off)
        if cmd == 0x19:  # LC_SEGMENT_64
            nsects = struct.unpack_from("<I", data, off + 64)[0]
            for i in range(nsects):
                s = off + 72 + i * 80
                seg = data[s + 16 : s + 32].rstrip(b"\0").decode()
                sect = data[s : s + 16].rstrip(b"\0").decode()
                _, sz, foff = struct.unpack_from("<QQI", data, s + 32)
                out[(seg, sect)] = (foff, sz)
        off += size
    return out


def constants(data: bytes) -> set[int]:
    """32-bit values the code can materialize, plus aligned 32-bit words in constant data."""
    secs = sections(data)
    found: set[int] = set()
    foff, size = secs[("__TEXT", "__text")]
    words = struct.unpack_from(f"<{size // 4}I", data, foff)
    pending: dict[int, int] = {}  # register -> low half from MOVZ
    for w in words:
        if (w & 0x7F800000) == 0x52800000:  # MOVZ (32/64-bit)
            rd, imm, hw = w & 31, (w >> 5) & 0xFFFF, (w >> 21) & 3
            if hw == 0:
                pending[rd] = imm
                found.add(imm)
        elif (w & 0x7F800000) == 0x72800000:  # MOVK
            rd, imm, hw = w & 31, (w >> 5) & 0xFFFF, (w >> 21) & 3
            if hw == 1 and rd in pending:
                found.add(pending.pop(rd) | (imm << 16))
        elif (w & 0x7F800000) == 0x12800000:  # MOVN
            rd, imm, hw = w & 31, (w >> 5) & 0xFFFF, (w >> 21) & 3
            if hw == 0:
                found.add(~imm & 0xFFFFFFFF)
    for key in (("__TEXT", "__const"), ("__TEXT", "__literal4"), ("__DATA_CONST", "__const"), ("__DATA", "__data")):
        if key in secs:
            foff, size = secs[key]
            found.update(struct.unpack_from(f"<{size // 4}I", data, foff))
    return found


def requirements(dylib: Path, db: dict) -> list[tuple[int, bool]]:
    hashes = {int(e["hash"]): e.get("verified") is True for e in db["Addresses"]}
    used = constants(dylib.read_bytes())
    return sorted((h, v) for h, v in hashes.items() if h in used)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("dylib", type=Path)
    ap.add_argument("--db", type=Path, default=ROOT / "cyberpunk2077_addresses.json")
    ap.add_argument("--names", type=Path, action="append", default=[])
    args = ap.parse_args()

    names, _ = load_names([ROOT / "include/RED4ext", *args.names])
    reqs = requirements(args.dylib, json.loads(args.db.read_text()))
    missing = [h for h, v in reqs if not v]
    for h, v in reqs:
        print(f"{'verified  ' if v else 'UNVERIFIED'} {h:>10} {names.get(h, '?')}")
    print(f"{args.dylib.name}: {len(reqs)} required, {len(missing)} unverified")
    return 1 if missing else 0


if __name__ == "__main__":
    raise SystemExit(main())
