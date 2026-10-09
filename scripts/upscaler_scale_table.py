#!/usr/bin/env python3
"""Find and verify the engine's upscaler scale table in the macOS game binary, and optionally add it to the address DB.

    scripts/upscaler_scale_table.py [--binary PATH] [--db cyberpunk2077_addresses.json]

The engine maps an upscaler quality index q (1..4) to a render scale with a table of four floats, [1.5, 1.7, 2.0, 3.0]
(lookup q - 1; `<upscaler>/OverrideEnable` with `<upscaler>/Quality` picks q; see the MetalFX Denoiser's
PIPELINE_TRACE_FINDINGS.md). Verified when the 16 bytes occur exactly once in __TEXT,__const and code in __TEXT,__text
addresses them with an ADRP + ADD (or ADRP + LDR) pair. --db adds it as a verified macOS-only entry: hash
FNV1a32("Upscaler/ScaleTable"), offset "1:<offset in __TEXT>". Plugins must still compare the four values in memory
before reading or writing them.
"""
import argparse
import array
import json
import struct
import sys

from validate_addresses import DEFAULT_BINARY, read_macho

NAME = "Upscaler/ScaleTable"
VALUES = (1.5, 1.7, 2.0, 3.0)


def fnv1a32(text):
    h = 0x811C9DC5
    for c in text.encode():
        h = ((h ^ c) * 0x01000193) & 0xFFFFFFFF
    return h


def xrefs(L, target):
    """ADRP + ADD/LDR pairs in __TEXT,__text that compute target (the add/ldr within 8 instructions, same register)."""
    data = L["data"]
    tvm, _, tfo = L["segments"]["__TEXT"]
    addr, size = L["sections"][("__TEXT", "__text")]
    words = array.array("I", data[addr - tvm + tfo: addr - tvm + tfo + size])
    page, low = target & ~0xFFF, target & 0xFFF
    found = []
    for i, w in enumerate(words):
        if (w & 0x9F000000) != 0x90000000:
            continue
        pc = addr + 4 * i
        imm = ((w >> 29) & 3) | (((w >> 5) & 0x7FFFF) << 2)
        if imm & (1 << 20):
            imm -= 1 << 21
        if (pc & ~0xFFF) + (imm << 12) != page:
            continue
        rd = w & 31
        for j in range(i + 1, min(i + 9, len(words))):
            u = words[j]
            if (u & 0xFFC00000) == 0x91000000 and ((u >> 5) & 31) == rd and ((u >> 10) & 0xFFF) == low:
                found.append((pc, "add"))  # add xd, xn, #imm12
                break
            if (u & 0x3B400000) == 0x39400000 and ((u >> 5) & 31) == rd:  # ldr (unsigned offset), any size
                scale = 4 if (u & 0x04000000) and (u >> 30) == 0 and (u >> 23) & 1 else (u >> 30)
                if ((u >> 10) & 0xFFF) << scale == low:
                    found.append((pc, "ldr"))
                    break
    return found


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--binary", default=str(DEFAULT_BINARY))
    ap.add_argument("--db")
    args = ap.parse_args()
    from pathlib import Path
    L = read_macho(Path(args.binary))
    data = L["data"]
    tvm, _, tfo = L["segments"]["__TEXT"]
    caddr, csize = L["sections"][("__TEXT", "__const")]
    blob = data[caddr - tvm + tfo: caddr - tvm + tfo + csize]
    pattern = struct.pack("<4f", *VALUES)
    hits, start = [], 0
    while (k := blob.find(pattern, start)) >= 0:
        hits.append(caddr + k)
        start = k + 1
    if len(hits) != 1:
        sys.exit(f"{NAME}: {len(hits)} matches in __TEXT,__const (need exactly one): {[hex(h) for h in hits]}")
    table = hits[0]
    refs = xrefs(L, table)
    print(f"{NAME}: {hex(table)} (__TEXT offset {hex(table - tvm)}), values {VALUES}, "
          f"{len(refs)} code references: {', '.join(f'{hex(p)} {k}' for p, k in refs[:8])}")
    if not refs:
        sys.exit(f"{NAME}: no ADRP + ADD/LDR reference in __TEXT,__text; not verified")
    if args.db:
        db = json.load(open(args.db))
        if db.get("uuid", "").replace("-", "").upper() != (L.get("uuid") or "").replace("-", "").upper():
            sys.exit(f"address DB is for {db.get('uuid')}, the binary is {L.get('uuid')}")
        entry = {"hash": str(fnv1a32(NAME)), "offset": f"1:0x{table - tvm:X}", "verified": True}
        entries = {e["hash"]: e for e in db["Addresses"]}
        if entry["hash"] in entries and entries[entry["hash"]] != entry:
            sys.exit(f"hash {entry['hash']} already in the DB as {entries[entry['hash']]}")
        if entry["hash"] not in entries:
            db["Addresses"].append(entry)
            if "stats" in db:
                db["stats"]["total"] = len(db["Addresses"])
                db["stats"]["resolved"] = sum(1 for e in db["Addresses"] if not e["offset"].endswith(":0x0"))
                db["stats"]["verified"] = sum(1 for e in db["Addresses"] if e.get("verified"))
            json.dump(db, open(args.db, "w"), indent=2)
        print(f"address DB: {entry}")


if __name__ == "__main__":
    main()
