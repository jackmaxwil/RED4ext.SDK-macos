#!/usr/bin/env python3
"""Move function offsets that point inside a prologue back to the real function start.

Earlier address discovery walked back from a string/call site to the `stp x29, x30` frame
setup and stopped there, missing the register saves and `sub sp` that come before it. For
every __TEXT entry that is not in LC_FUNCTION_STARTS, if every instruction between the
containing function start and the entry is a prologue store, the entry is rewritten to that
start. Anything else is reported and left alone for manual work.

Usage: snap_prologue_offsets.py [--binary PATH] [--write] DB.json [DB.json ...]
"""

import argparse
import bisect
import json
import struct
from pathlib import Path

from validate_addresses import DEFAULT_BINARY, is_prologue, read_macho


def snap(layout: dict, off: int) -> tuple[int | None, str]:
    text_vm, _, text_fileoff = layout["segments"]["__TEXT"]
    addr = text_vm + off
    if addr in layout["starts"]:
        return None, "ok"
    starts = layout["sorted_starts"]
    i = bisect.bisect_right(starts, addr)
    if not i:
        return None, "no containing function"
    start = starts[i - 1]
    data = layout["data"]
    for a in range(start, addr, 4):
        (insn,) = struct.unpack_from("<I", data, text_fileoff + (a - text_vm))
        if not is_prologue(insn):
            return None, f"not inside a prologue (containing start {start - text_vm:#x}, +{addr - start})"
    return start - text_vm, f"snapped -{addr - start}"


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--binary", type=Path, default=DEFAULT_BINARY)
    ap.add_argument("--write", action="store_true", help="rewrite the DB files in place")
    ap.add_argument("dbs", nargs="+", type=Path)
    args = ap.parse_args()

    layout = read_macho(args.binary)
    layout["sorted_starts"] = sorted(layout["starts"])
    text_size = layout["segments"]["__TEXT"][1]

    for db_path in args.dbs:
        db = json.loads(db_path.read_text())
        snapped = left = 0
        for e in db["Addresses"]:
            seg, off = e["offset"].split(":")
            off = int(off, 16)
            if seg != "1" or off == 0 or off >= text_size:
                continue
            new, why = snap(layout, off)
            if new is not None:
                e["offset"] = f"1:0x{new:X}"
                snapped += 1
                print(f"{db_path.name}: {e['hash']} {off:#x} -> {new:#x} ({why})")
            elif why != "ok":
                left += 1
                print(f"{db_path.name}: {e['hash']} {off:#x} LEFT: {why}")
        print(f"{db_path.name}: {snapped} snapped, {left} left for manual work")
        if args.write and snapped:
            db_path.write_text(json.dumps(db, indent=2) + "\n")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
