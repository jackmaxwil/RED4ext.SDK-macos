#!/usr/bin/env python3
"""Find code references to addresses in the game's __text (no disassembler needed).

  xref_scan.py adrp 0x10726F0C0 ...   ADRP+ADD pairs that materialize an address (or address+0x10)
  xref_scan.py call 0x103D8B6F0 ...   B/BL instructions that branch to an address

Addresses are absolute (image base 0x100000000). Binary: $CP2077_BINARY or the Steam default.
"""

import os
import struct
import sys
from pathlib import Path

from validate_addresses import DEFAULT_BINARY, read_macho


def main() -> int:
    if len(sys.argv) < 3 or sys.argv[1] not in ("adrp", "call"):
        print(__doc__)
        return 2
    mode, targets = sys.argv[1], {int(a, 16) for a in sys.argv[2:]}
    layout = read_macho(Path(os.environ.get("CP2077_BINARY", DEFAULT_BINARY)))
    tvm, tsz = layout["sections"][("__TEXT", "__text")]
    words = struct.unpack_from(f"<{tsz // 4}I", layout["data"], tvm - layout["segments"]["__TEXT"][0])
    pages = {t & ~0xFFF for t in targets}

    for i, w in enumerate(words):
        pc = tvm + 4 * i
        if mode == "call" and (w & 0x7C000000) == 0x14000000:
            imm = w & 0x3FFFFFF
            dest = pc + ((imm - (1 << 26) if imm & (1 << 25) else imm) << 2)
            if dest in targets:
                print(f"{pc:#x} {'BL' if w >> 31 else 'B'} -> {dest:#x}")
        elif mode == "adrp" and (w & 0x9F000000) == 0x90000000:
            imm = ((w >> 29) & 3) | (((w >> 5) & 0x7FFFF) << 2)
            page = (pc & ~0xFFF) + ((imm - (1 << 21) if imm & (1 << 20) else imm) << 12)
            if page not in pages:
                continue
            rd = w & 31
            for n in words[i + 1 : i + 6]:
                if (n & 0xFFC00000) == 0x91000000 and ((n >> 5) & 31) == rd:  # ADD Xd, Xn, #imm12
                    full = page + ((n >> 10) & 0xFFF)
                    if full in targets or full - 0x10 in targets:
                        print(f"{pc:#x} ADRP+ADD -> {full:#x}")
                    break
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
