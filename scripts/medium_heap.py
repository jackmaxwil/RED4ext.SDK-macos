#!/usr/bin/env python3
"""Find and verify the engine allocator's medium heap entry points, and optionally add them to the address DB.

    scripts/medium_heap.py [--binary PATH] [--db cyberpunk2077_addresses.json]

The engine's memory pools route allocations over 0x200 bytes (or aligned over 16) to a TLSF heap at pool +0xcd80. Each
entry point takes the heap's writer spinlock (a byte at heap +0x80: WFE until 0, then CAS 0 -> 0x80), calls the TLSF
operation, and releases the lock. With 16 job workers allocating temporary arrays in the ray tracing pool, workers spend
about 9% of their time spinning on that lock (MetalFX Denoiser docs/LATENCY_PROFILE.md). Entries (2.3.1):

  Memory/MediumHeap/Alloc         0x10000a8a8  (heap, size, align) -> {ptr, usable}   inner 0x10000a2bc
  Memory/MediumHeap/AllocDefault  0x10000a82c  (heap, size) -> {ptr, usable}          inner 0x10000a248
  Memory/MediumHeap/Free          0x10000aa54  (heap, {ptr, size}*)                   inner 0x10000a568 (TLSF free)
  Memory/MediumHeap/Init          0x10000a7ac  (heap, region)                         inner 0x10000a0b4
  Memory/MediumHeap/Release       0x10000a7f4  (heap)                                 inner 0x10000a230

Verified when each is a function start (LC_FUNCTION_STARTS), its first 12 instructions compute x0 + 0x80 and call the
spinlock routine, the routine's 10 instructions are the exact writer lock (mov w8, #-0x80 ... casalb ... ret), the
function calls its inner routine, and exactly one function in __TEXT,__text calls both the lock and that inner routine
(the five are told apart by it). Also checked, because a cache in front of the heap relies on them: the TLSF block
header (the free routine reads the size word at ptr - 8, usable = (size - 0x10) & ~3) and the allocation result (block
+ 0x10). --db adds the five as verified macOS-only entries: hash FNV1a32(name), offset "1:<offset in __TEXT>".
"""
import argparse
import array
import json
import sys
from pathlib import Path

from validate_addresses import DEFAULT_BINARY, read_macho

LOCK = 0x1000020C0
LOCK_WORDS = [0x12800FE8, 0x14000003, 0xD503205F, 0xD5033F5F, 0x085FFC09, 0xB5FFFFA9, 0x08E9FC08, 0x35FFFF89,
              0xD5033F5F, 0xD65F03C0]
ENTRIES = [
    ("Memory/MediumHeap/Alloc", 0x10000A8A8, 0x10000A2BC),
    ("Memory/MediumHeap/AllocDefault", 0x10000A82C, 0x10000A248),
    ("Memory/MediumHeap/Free", 0x10000AA54, 0x10000A568),
    ("Memory/MediumHeap/Init", 0x10000A7AC, 0x10000A0B4),
    ("Memory/MediumHeap/Release", 0x10000A7F4, 0x10000A230),
]
# The TLSF parts the plugin's cache depends on (2.3.1 words).
TLSF_FREE = 0x10000AFF8        # free(control, {ptr, size}*): reads ptr[-1], size = (w - 0x10) & ~3
TLSF_FIND = 0x10000B098        # alloc result: block + 0x10, usable = (block->size - 0x10) & ~3


def fnv1a32(text):
    h = 0x811C9DC5
    for c in text.encode():
        h = ((h ^ c) * 0x01000193) & 0xFFFFFFFF
    return h


def bl_target(w, pc):
    if (w & 0xFC000000) != 0x94000000:
        return None
    imm = w & 0x03FFFFFF
    if imm & 0x02000000:
        imm -= 0x04000000
    return pc + imm * 4


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--binary", type=Path, default=DEFAULT_BINARY)
    ap.add_argument("--db", type=Path)
    a = ap.parse_args()
    L = read_macho(a.binary)
    text_addr, text_size = L["sections"][("__TEXT", "__text")]
    seg_addr, _, seg_off = L["segments"]["__TEXT"]
    off = text_addr - seg_addr + seg_off
    words = array.array("I", L["data"][off: off + text_size])
    starts = L["starts"]

    def word(addr):
        return words[(addr - text_addr) // 4]

    ok = True

    def check(cond, msg):
        nonlocal ok
        print(("ok   " if cond else "FAIL ") + msg)
        ok = ok and cond

    check([word(LOCK + 4 * i) for i in range(10)] == LOCK_WORDS and LOCK in starts,
          f"0x{LOCK:x}: the writer spinlock (WFE until 0, CAS 0 -> 0x80)")
    # Callers: function start -> set of BL targets, for the uniqueness check.
    sorted_starts = sorted(s for s in starts if text_addr <= s < text_addr + text_size)
    calls_lock_and = {}
    for i, s in enumerate(sorted_starts):
        end = sorted_starts[i + 1] if i + 1 < len(sorted_starts) else text_addr + text_size
        if end - s > 4096:
            continue
        targets = set()
        for pc in range(s, end, 4):
            t = bl_target(word(pc), pc)
            if t is not None:
                targets.add(t)
        if LOCK in targets:
            for t in targets:
                calls_lock_and.setdefault(t, []).append(s)
    found = {}
    for name, fn, inner in ENTRIES:
        head = [word(fn + 4 * i) for i in range(12)]
        adds = any((w & 0xFFFFFFE0) == 0x91020000 for w in head)  # add xN, x0, #0x80
        lock_call = any(bl_target(head[i], fn + 4 * i) == LOCK for i in range(12))
        callers = calls_lock_and.get(inner, [])
        check(fn in starts and adds and lock_call and callers == [fn],
              f"{name} 0x{fn:x}: function start, lock at x0 + 0x80, calls 0x{inner:x}; functions calling both: "
              f"{[hex(c) for c in callers]}")
        found[name] = fn
    free_head = [word(TLSF_FREE + 4 * i) for i in range(8)]
    # ldr x?, [x1]; cbz; ldur x?, [x?, #-8]; sub w?, w?, #0x10; and x?, x?, #0xfffffffc (register numbers masked)
    check(any((w & 0xFFFFFC00) == 0xF85F8000 for w in free_head) and
          any((w & 0xFFFFFC00) == 0x51004000 for w in free_head),
          f"0x{TLSF_FREE:x}: TLSF free reads the size word at ptr - 8 and subtracts the 0x10 header")
    find_words = [word(TLSF_FIND + 4 * i) for i in range(21)]
    check(any((w & 0xFFFFFC00) == 0x91004000 for w in find_words) and
          any((w & 0xFFFFFC00) == 0x51004000 for w in find_words),
          f"0x{TLSF_FIND:x}: allocation returns block + 0x10, usable = size - 0x10")
    if not ok:
        sys.exit("not verified")
    if a.db:
        db = json.load(open(a.db))
        entries = {e["hash"]: e for e in db["Addresses"]}
        for name, fn in found.items():
            entry = {"hash": str(fnv1a32(name)), "offset": f"1:0x{fn - seg_addr:X}", "verified": True}
            if entry["hash"] in entries and entries[entry["hash"]].get("verified") and entries[entry["hash"]] != entry:
                sys.exit(f"hash {entry['hash']} already in the DB as {entries[entry['hash']]}")
            if entry["hash"] in entries:
                entries[entry["hash"]].update(entry)
            else:
                db["Addresses"].append(entry)
                print(f"added {name}: {entry}")
        db["stats"]["total"] = len(db["Addresses"])
        db["stats"]["resolved"] = sum(1 for e in db["Addresses"] if not e["offset"].endswith(":0x0"))
        db["stats"]["unresolved"] = db["stats"]["total"] - db["stats"]["resolved"]
        db["stats"]["verified"] = sum(1 for e in db["Addresses"] if e.get("verified"))
        json.dump(db, open(a.db, "w"), indent=2)
        open(a.db, "a").write("\n")


if __name__ == "__main__":
    main()
