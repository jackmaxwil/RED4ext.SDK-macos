#!/usr/bin/env python3
"""Find and verify the engine's dynamic resolution update, DRS::Update, and optionally add it to the address DB.

    scripts/drs_update.py [--binary PATH] [--db cyberpunk2077_addresses.json]

DRS::Update(state, outputRectLo, outputRectHi, frameContext) runs once per view setup and writes the render size into
the DRS state (state +0x00 width, +0x04 height, +0x10/+0x14 max/min width, +0x18/+0x1c max/min height; see the MetalFX
Denoiser's docs/DRS_RECON.md). Verified when its first 64 instructions, with ADRP pages and branch targets masked, occur
exactly once in __TEXT,__text at a function start (LC_FUNCTION_STARTS), and the function reads the DRS/Enable and
DRS/Freeze config variables' bool values (+0x29) and DRS/StepSize (+0x2c): checked by the config variable objects'
names. --db adds it as a verified macOS-only entry: hash FNV1a32("DRS/Update"), offset "1:<offset in __TEXT>".

Also "Renderer/Global", the pointer to the renderer (its MetalFX upscaler state at +0x7680: +0x19 enabled, +0x1a
dynamic, +0x1b recreate request). Verified when exactly one instruction in __TEXT,__text stores to it, and the MetalFX
upscale node loads it and reads the upscaler's dynamic byte (ldr [x, #0x7680]; ldrb [x, #0x1a]). Offset
"3:<offset in __DATA>".
"""
import argparse
import array
import json
import sys
from pathlib import Path

from validate_addresses import DEFAULT_BINARY, read_macho

NAME = "DRS/Update"
# The function in 2.3.1 (A6656ADCFBE236A49B9DB4A9DE645089); the signature is taken from it, then searched everywhere.
KNOWN = 0x1010CD188
LENGTH = 64


def fnv1a32(text):
    h = 0x811C9DC5
    for c in text.encode():
        h = ((h ^ c) * 0x01000193) & 0xFFFFFFFF
    return h


def mask(w):
    if (w & 0x9F000000) == 0x90000000:  # adrp: page
        return w & 0x9F00001F
    if (w & 0x7C000000) == 0x14000000:  # b / bl: target
        return w & 0xFC000000
    if (w & 0x3B000000) == 0x39000000 or (w & 0xFF000000) == 0x91000000:  # ldr/str/add imm12 (page offsets)
        return w & 0xFFC003FF
    return w


def adrp_loads(words, base):
    """(pc, address) for each adrp + ldr/ldrb with the same register within 4 instructions."""
    out = []
    for i, w in enumerate(words):
        if (w & 0x9F000000) != 0x90000000:
            continue
        pc = base + 4 * i
        imm = ((w >> 29) & 3) | (((w >> 5) & 0x7FFFF) << 2)
        page = (pc & ~0xFFF) + ((imm - (1 << 21) if imm & (1 << 20) else imm) << 12)
        for u in words[i + 1: i + 5]:
            if ((u >> 5) & 31) == (w & 31) and (u & 0x3B400000) == 0x39400000:
                size = u >> 30 if not (u & 0x04000000) else 2
                out.append((pc, page + (((u >> 10) & 0xFFF) << size)))
                break
    return out


def renderer_global(L, words, addr):
    """The global the MetalFX node reads the upscaler's dynamic byte through; exactly one store to it."""
    loads = {}
    for i, w in enumerate(words):
        if (w & 0xFFFFFC00) != 0xF97B4000:  # ldr xT, [xN, #0x7680]
            continue
        rt, rn = w & 31, (w >> 5) & 31
        if not any((u & 0xFFFFFC00) == 0x39406800 and ((u >> 5) & 31) == rt for u in words[i + 1: i + 4]):
            continue  # not followed by ldrb [xT, #0x1a]
        # adrp xA, page ; add xA, xA, #lo ; ldr xN, [xA] ; ldr xT, [xN, #0x7680]
        regs = {}
        for k in range(max(0, i - 6), i):
            u, pc = words[k], addr + 4 * k
            if (u & 0x9F000000) == 0x90000000:
                imm = ((u >> 29) & 3) | (((u >> 5) & 0x7FFFF) << 2)
                regs[u & 31] = (pc & ~0xFFF) + ((imm - (1 << 21) if imm & (1 << 20) else imm) << 12)
            elif (u & 0xFFC00000) == 0x91000000 and ((u >> 5) & 31) in regs:
                regs[u & 31] = regs[(u >> 5) & 31] + ((u >> 10) & 0xFFF)
            elif (u & 0xFFC00000) == 0xF9400000 and ((u >> 5) & 31) in regs and (u & 31) == rn:
                a = regs[(u >> 5) & 31] + (((u >> 10) & 0xFFF) << 3)
                loads[a] = loads.get(a, 0) + 1
    if len(loads) != 1:
        sys.exit(f"Renderer/Global: {len(loads)} candidate globals: {[hex(a) for a in loads]}")
    glob = next(iter(loads))
    stores = 0
    for i, w in enumerate(words):
        if (w & 0x9F000000) != 0x90000000:
            continue
        pc = addr + 4 * i
        imm = ((w >> 29) & 3) | (((w >> 5) & 0x7FFFF) << 2)
        page = (pc & ~0xFFF) + ((imm - (1 << 21) if imm & (1 << 20) else imm) << 12)
        if page != glob & ~0xFFF:
            continue
        for u in words[i + 1: i + 5]:
            if ((u >> 5) & 31) == (w & 31) and (u & 0xFFC00000) == 0xF9000000 and page + (((u >> 10) & 0xFFF) << 3) == glob:
                stores += 1  # adrp + str x, [xN, #lo]
                break
            if ((u >> 5) & 31) == (w & 31) and (u & 0xFFC00000) == 0x91000000:
                break  # adrp + add: an address taken, not a store
    if stores != 1:
        sys.exit(f"Renderer/Global: {stores} stores to {hex(glob)} (need exactly one)")
    return glob


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--binary", default=str(DEFAULT_BINARY))
    ap.add_argument("--db")
    args = ap.parse_args()
    L = read_macho(Path(args.binary))
    data = L["data"]
    tvm, _, tfo = L["segments"]["__TEXT"]
    addr, size = L["sections"][("__TEXT", "__text")]
    words = array.array("I", data[addr - tvm + tfo: addr - tvm + tfo + size])
    k = (KNOWN - addr) // 4
    sig = [mask(w) for w in words[k: k + LENGTH]]
    first = sig[0]
    hits = [addr + 4 * i for i in range(len(words) - LENGTH)
            if mask(words[i]) == first and [mask(w) for w in words[i: i + LENGTH]] == sig]
    if len(hits) != 1:
        sys.exit(f"{NAME}: signature matches {len(hits)} times (need exactly one): {[hex(h) for h in hits[:8]]}")
    fn = hits[0]
    if fn not in L["starts"]:
        sys.exit(f"{NAME}: {hex(fn)} is not a function start")
    # The config variables it must read, identified by group and name from their constructor calls (config_var_dump).
    import subprocess, tempfile
    with tempfile.NamedTemporaryFile(suffix=".json") as tmp:
        subprocess.run([sys.executable, str(Path(__file__).with_name("config_var_dump.py")), "--binary", args.binary,
                        "--json", tmp.name], check=True, capture_output=True)
        names = {int(v["address"], 16): f"{v['group']}/{v['name']}" for v in json.load(open(tmp.name))}
    def var_name(obj):
        return names.get(obj)
    body = words[(fn - addr) // 4: (fn - addr) // 4 + 0x100]
    reads = {(var_name(a - off), off) for _, a in adrp_loads(body, fn) for off in (0x29, 0x2C)}
    need = {("DRS/Enable", 0x29), ("DRS/Freeze", 0x29), ("DRS/StepSize", 0x2C)}
    if not need <= reads:
        sys.exit(f"{NAME}: {hex(fn)} does not read {sorted(need - reads)}")
    print(f"{NAME}: {hex(fn)} (__TEXT offset {hex(fn - tvm)}), unique {LENGTH}-instruction signature, reads "
          f"DRS Enable/Freeze (+0x29) and StepSize (+0x2c)")
    entries_new = [("DRS/Update", f"1:0x{fn - tvm:X}")]
    glob = renderer_global(L, words, addr)
    print(f"Renderer/Global: {hex(glob)}")
    dvm = L["segments"]["__DATA"][0]
    entries_new.append(("Renderer/Global", f"3:0x{glob - dvm:X}"))
    if args.db:
        db = json.load(open(args.db))
        if db.get("uuid", "").replace("-", "").upper() != (L.get("uuid") or "").replace("-", "").upper():
            sys.exit(f"address DB is for {db.get('uuid')}, the binary is {L.get('uuid')}")
        entries = {e["hash"]: e for e in db["Addresses"]}
        for name, offset in entries_new:
            entry = {"hash": str(fnv1a32(name)), "offset": offset, "verified": True}
            if entry["hash"] in entries and entries[entry["hash"]].get("verified") and entries[entry["hash"]] != entry:
                sys.exit(f"hash {entry['hash']} already in the DB as {entries[entry['hash']]}")
            if entry["hash"] in entries:
                entries[entry["hash"]].update(entry)
            else:
                db["Addresses"].append(entry)
            print(f"address DB: {name} {entry}")
        if True:
            if "stats" in db:
                db["stats"]["total"] = len(db["Addresses"])
                db["stats"]["resolved"] = sum(1 for e in db["Addresses"] if not e["offset"].endswith(":0x0"))
                db["stats"]["verified"] = sum(1 for e in db["Addresses"] if e.get("verified"))
            json.dump(db, open(args.db, "w"), indent=2)


if __name__ == "__main__":
    main()
