#!/usr/bin/env python3
"""Dump every engine config variable (CConfigVar) registered by the macOS game binary, with the evidence for each.

    scripts/config_var_dump.py [--binary PATH] [--json out.json]
    scripts/config_var_dump.py --db cyberpunk2077_addresses.json --groups '^RayTracing' --audit docs/CONFIG_VAR_AUDIT.md

A config variable is a global object built by a static initializer:

    adrp/add x1, "<group>" ; adrp/add x2, "<name>" ; x0 = &var ; mov w3, #flags
    bl  CConfigVar::CConfigVar(this, group, name, flags)   stores vtable0 +0x0, name +0x8, group +0x10, flags +0x28
    str x<vtable>, [var]                                    the value type's vtable
    str w<default>, [var, #0x2c] ; str w<default>, [var, #0x38]   current value, default value (4-byte types)
    bl  <register>(var)                                     applies a value from the config storage, if any

The constructor is found by its body (stp x8,x2,[x0]; stp xzr,xzr,[x0,#0x18]; str x1,[x0,#0x10];
strb w3,[x0,#0x28]; ret). Each call site is replayed with a small arm64 register tracker (adrp/add/mov/movz/movn/movk/
fmov/str) from the start of its function. A variable is listed only when x0, x1 and x2 at the call resolve to an
object in __DATA and two C strings, and a store after the call puts a data-segment pointer (the vtable) in the same
object. It is "verified" when that vtable is one of the bool/int/float value types (identity and type proven, so the
value is at +0x2c); "value_checked" when its value store at +0x2c (4 bytes; bool: one halfword with the default byte
at +0x2d) also resolves and equals the default store at +0x38 (floats copied as a 16-byte value/min/max/default block
are not followed). Types come from
the vtable: the most common vtable whose defaults are 0/1 is bool, the one with float bit patterns is float, ...
(listed per vtable in the summary; the value offset +0x2c is checked against the default stored at +0x38).

--db adds the verified variables of the groups matching --groups to the address DB as verified macOS-only entries:
hash FNV1a32("ConfigVar/<group>/<name>"), offset "3:<offset in __DATA>" (the object; the value is at +0x2c). --audit
writes the evidence for each. Plugins resolve a variable by that hash and must still check the object's name and
group pointers (+0x8, +0x10) against the expected strings before reading or writing it.
"""
import argparse
import re
import collections
import json
import struct
import sys

from validate_addresses import DEFAULT_BINARY, read_macho

CTOR_BODY = [None, None, 0xA9000808, 0xA901FC1F, 0xF9000801, 0x3900A003, 0xD65F03C0]  # adrp/add x8 unchecked


def sext(v, bits):
    return v - (1 << bits) if v & (1 << (bits - 1)) else v


def fmov_imm(imm8):
    sign = (imm8 >> 7) & 1
    exp = ((~imm8 >> 6) & 1) << 7 | (0x3F if (imm8 >> 6) & 1 else 0) << 1 | ((imm8 >> 4) & 3) >> 1
    # Single precision: sign, exponent = NOT(b6):b6 x5:b5:b4, fraction = b3..b0 << 19.
    b6 = (imm8 >> 6) & 1
    e = ((1 - b6) << 7) | ((b6 * 0x1F) << 2) | ((imm8 >> 4) & 3)
    return (sign << 31) | (e << 23) | ((imm8 & 0xF) << 19)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--binary", default=DEFAULT_BINARY)
    ap.add_argument("--json")
    ap.add_argument("--db")
    ap.add_argument("--groups", default="^$")
    ap.add_argument("--audit")
    args = ap.parse_args()
    L = read_macho(args.binary)
    data, base = L["data"], L["segments"]["__TEXT"][0]
    tvm, tsz = L["sections"][("__TEXT", "__text")]
    cvm, csz = L["sections"][("__TEXT", "__cstring")]
    dvm, dsz = L["segments"]["__DATA"][:2]
    words = struct.unpack_from(f"<{tsz // 4}I", data, tvm - base)

    def cstr(addr):
        if not cvm <= addr < cvm + csz:
            return None
        o = addr - base
        return data[o:data.index(b"\0", o)].decode("latin1")

    # The constructor, by its body.
    ctors = [tvm + 4 * i for i in range(len(words) - 7)
             if all(p is None or words[i + k] == p for k, p in enumerate(CTOR_BODY))]
    if len(ctors) != 1:
        sys.exit(f"constructor: expected one match, found {[hex(c) for c in ctors]}")
    ctor = ctors[0]
    ret = 0xD65F03C0

    results, rejects = [], collections.Counter()
    for i, w in enumerate(words):
        if (w & 0xFC000000) != 0x94000000 or tvm + 4 * i + 4 * sext(w & 0x3FFFFFF, 26) != ctor:
            continue
        # Replay from the start of the function (previous RET) to 40 instructions after the call.
        start = i
        while start > 0 and words[start - 1] != ret and i - start < 6000:
            start -= 1
        regs, call, stores = {}, None, []
        for j in range(start, min(len(words), i + 40)):
            x, pc = words[j], tvm + 4 * j
            rd, rn = x & 31, (x >> 5) & 31
            if (x & 0x9F000000) == 0x90000000:  # adrp
                imm = sext(((x >> 29) & 3) | (((x >> 5) & 0x7FFFF) << 2), 21)
                regs[rd] = (pc & ~0xFFF) + (imm << 12)
            elif (x & 0xFF800000) == 0x91000000:  # add (imm), 64-bit
                if rn in regs and regs[rn] is not None:
                    regs[rd] = regs[rn] + (((x >> 10) & 0xFFF) << (12 if (x >> 22) & 1 else 0))
                else:
                    regs[rd] = None
            elif (x & 0x7FE0FFE0) == 0x2A0003E0:  # mov (orr) reg
                regs[rd] = regs.get((x >> 16) & 31)
            elif (x & 0x7F800000) in (0x52800000, 0x12800000):  # movz / movn
                hw, imm = (x >> 21) & 3, (x >> 5) & 0xFFFF
                val = imm << (16 * hw)
                if (x & 0x7F800000) == 0x12800000:
                    val = ~val & (0xFFFFFFFFFFFFFFFF if x >> 31 else 0xFFFFFFFF)
                regs[rd] = val
            elif (x & 0x7F800000) == 0x72800000:  # movk
                hw, imm = (x >> 21) & 3, (x >> 5) & 0xFFFF
                if regs.get(rd) is not None:
                    regs[rd] = (regs[rd] & ~(0xFFFF << (16 * hw))) | (imm << (16 * hw))
            elif (x & 0xFFC00000) == 0xF9400000 and rn == 31:  # ldr x, [sp, #imm]
                regs[rd] = regs.get(("sp", ((x >> 10) & 0xFFF) * 8))
            elif (x & 0xFFC00000) == 0xF9000000 and rn == 31:  # str x, [sp, #imm] (spill)
                regs[("sp", ((x >> 10) & 0xFFF) * 8)] = 0 if rd == 31 else regs.get(rd)
            elif (x & 0xFFE01FE0) == 0x1E201000:  # fmov s, #imm
                regs[("s", rd)] = fmov_imm((x >> 13) & 0xFF)
            elif (x & 0xFC000000) == 0x94000000:  # bl
                if j == i:
                    call = (regs.get(0), regs.get(1), regs.get(2), regs.get(3))
                for r in list(regs):
                    if isinstance(r, int) and r <= 18:
                        regs[r] = None  # caller-saved registers are clobbered
            elif j > i and (x & 0xFFC00000) in (0xF9000000, 0xB9000000, 0xBD000000, 0x39000000, 0x79000000):
                # str x / str w / str s / strb / strh
                kind = {0xF9000000: ("x", 8), 0xB9000000: ("w", 4), 0xBD000000: ("s", 4), 0x39000000: ("b", 1),
                        0x79000000: ("h", 2)}[x & 0xFFC00000]
                off = ((x >> 10) & 0xFFF) * kind[1]
                val = 0 if rd == 31 and kind[0] != "s" else regs.get(("s", rd) if kind[0] == "s" else rd)
                stores.append((regs.get(rn), off, kind[0], val))
        if not call:
            continue
        var, group, name, flags = call
        group_s, name_s = cstr(group or 0), cstr(name or 0)
        if var is None or not dvm <= var < dvm + dsz or group_s is None or name_s is None:
            rejects["unresolved call arguments"] += 1
            continue
        mine = [(off, k, v) for b, off, k, v in stores if b == var]
        vtable = next((v for off, k, v in mine if off == 0 and k == "x"), None)
        value = next((v for off, k, v in mine if off == 0x2C), None)
        default = next((v for off, k, v in mine if off == 0x38), None)
        halfword = any(off == 0x2C and k == "h" for off, k, v in mine)
        if halfword and value is not None:
            # bool: one halfword store writes the value byte (+0x2c) and the default byte (+0x2d)
            value, default = value & 0xFF, value & 0xFF
        in_data = lambda a: any(L["segments"][seg][0] <= a < sum(L["segments"][seg][:2]) for seg in ("__DATA_CONST", "__DATA"))
        if vtable is None or not in_data(vtable):
            rejects["no vtable (a data pointer) stored after the call"] += 1
            continue
        results.append({"group": group_s, "name": name_s, "address": hex(var), "data_offset": hex(var - dvm),
                        "vtable": hex(vtable), "value": value, "default": default,
                        "flags": flags, "call": hex(tvm + 4 * i), "halfword": halfword,
                        "value_checked": value is not None and value == default})

    # Verified = identity: object, group and name from the constructor call, and a vtable of one of the value types
    # (bool, int, float), which fixes where the value is (+0x2c). value_checked: value and default stores also agree.
    types = vtable_types(results)
    for r in results:
        r["type"] = types.get(r["vtable"])
        r["verified"] = r["type"] is not None
    by_vtable = collections.defaultdict(list)
    for r in results:
        by_vtable[r["vtable"]].append(r)
    print(f"constructor {hex(ctor)}: {len(results)} variables, rejected {dict(rejects)}", file=sys.stderr)
    for vt, rs in sorted(by_vtable.items(), key=lambda kv: -len(kv[1])):
        sample = [f"{r['group']}/{r['name']}={r['default']}" for r in rs[:3]]
        print(f"  vtable {vt}: {len(rs)} variables, e.g. {sample}", file=sys.stderr)
    print(f"  verified (bool/int/float type): {sum(r['verified'] for r in results)}; value and default stores also "
          f"agree: {sum(r['value_checked'] for r in results)}", file=sys.stderr)
    if args.json:
        json.dump(results, open(args.json, "w"), indent=1)
    if args.db:
        add_to_db(args, L, results)


def fnv1a32(text):
    h = 0x811C9DC5
    for b in text.encode():
        h = ((h ^ b) * 0x01000193) & 0xFFFFFFFF
    return h


def vtable_types(results):
    """vtable -> "bool" | "float" | "int" for the three value types plugins write: bool vtables are the ones whose
    variables store value and default with one halfword; float is the 4-byte vtable whose defaults are mostly float bit
    patterns; int the other 4-byte vtable with the most variables."""
    by = collections.defaultdict(list)
    for r in results:
        by[r["vtable"]].append(r)
    types = {}
    for vt, rs in by.items():
        if sum(r["halfword"] for r in rs) > len(rs) / 2:
            types[vt] = "bool"
    def floaty(v):
        return v is not None and (v == 0 or 0x30000000 <= v < 0x50000000 or 0xB0000000 <= v < 0xD0000000)
    four = sorted(((vt, rs) for vt, rs in by.items() if vt not in types and len(rs) >= 100), key=lambda kv: -len(kv[1]))
    for vt, rs in four:
        known = [r["default"] for r in rs if r["default"] is not None]
        kind = "float" if known and sum(floaty(v) for v in known) > 0.8 * len(known) and "float" not in types.values() \
            else "int"
        if kind not in types.values():
            types[vt] = kind
    return types


def add_to_db(args, L, results):
    db = json.load(open(args.db))
    if db.get("uuid", "").replace("-", "").upper() != (L.get("uuid") or "").replace("-", "").upper():
        sys.exit(f"address DB is for {db.get('uuid')}, the binary is {L.get('uuid')}")
    groups = re.compile(args.groups)
    chosen = [r for r in results if r["verified"] and groups.search(r["group"])]
    entries = {e["hash"]: e for e in db["Addresses"]}
    rows = []
    for r in chosen:
        h = str(fnv1a32(f"ConfigVar/{r['group']}/{r['name']}"))
        entry = {"hash": h, "offset": f"3:0x{int(r['data_offset'], 16):X}", "verified": True}
        if h in entries:
            if entries[h] != entry:
                sys.exit(f"hash {h} ({r['group']}/{r['name']}) already in the DB as {entries[h]}")
        else:
            db["Addresses"].append(entry)  # existing entries keep their order
            entries[h] = entry
        rows.append((r, h))
    # The value types' vtables, so a plugin can check a variable's type before writing it.
    data_const = L["segments"]["__DATA_CONST"][0]
    data = L["segments"]["__DATA"][0]
    for vt, kind in vtable_types(results).items():
        addr = int(vt, 16)
        seg, base = (2, data_const) if data_const <= addr < data else (3, data)
        h = str(fnv1a32(f"ConfigVar/@{kind}"))
        entry = {"hash": h, "offset": f"{seg}:0x{addr - base:X}", "verified": True}
        if h in entries and entries[h] != entry:
            sys.exit(f"vtable hash {h} ({kind}) already in the DB as {entries[h]}")
        if h not in entries:
            db["Addresses"].append(entry)
            entries[h] = entry
        count = sum(1 for r in results if r["vtable"] == vt)
        rows.append(({"group": "@", "name": kind, "address": vt, "call": f"{count} variables", "vtable": vt,
                      "default": "-"}, h))
    if "stats" in db:
        db["stats"]["total"] = len(db["Addresses"])
        db["stats"]["resolved"] = sum(1 for e in db["Addresses"] if not e["offset"].endswith(":0x0"))
        db["stats"]["verified"] = sum(1 for e in db["Addresses"] if e.get("verified"))
    json.dump(db, open(args.db, "w"), indent=2)
    print(f"address DB: {len(rows)} config variables (groups {args.groups!r})", file=sys.stderr)
    if args.audit:
        with open(args.audit, "w") as f:
            f.write("# Config variable addresses\n\nGenerated by `scripts/config_var_dump.py` "
                    f"(groups `{args.groups}`) from game binary {L.get('uuid')}. Each entry: the static initializer "
                    "calls the CConfigVar constructor with this object, group and name, stores the type's vtable in "
                    "the object; the vtable is the bool, int or float type's (`@` rows), so the value is at +0x2c.\n\n"
                    "| Hash | Variable | Object | Call site | vtable | Default |\n| --- | --- | --- | --- | --- | --- |\n")
            for r, h in rows:
                f.write(f"| {h} | `{r['group']}/{r['name']}` | `{r['address']}` | `{r['call']}` | `{r['vtable']}` | "
                        f"{r['default']} |\n")


if __name__ == "__main__":
    main()
