#!/usr/bin/env python3
"""Optional static cross-check: extract native RTTI class layouts from the macOS game binary (no game run).

  rtti_layout_scan.py [-o rtti_layout_static.json] [--self-test] [--compare data/rtti_layout_macos.json]

The live dump (data/rtti_layout_macos.json, RED4EXT_DUMP_RTTI) is the source of truth for SDK layouts
(scripts/gen_macos_layouts.py, scripts/sdk_layout_diff.py). This scanner only reads the binary, so it can check a dump,
or a new build before a dump exists, but it misses classes whose registration it cannot follow. --compare reports
every property both sources have and where they disagree.

Binary: $CP2077_BINARY or the Steam default. Output:
  {"uuid": ..., "stats": {...}, "unresolved": [...],
   "classes": {rttiName: {"parent", "size", "align", "props": {name: {"offset", "type"}}}}}

How the game registers native classes (2.3.1, evidence in docs/re/core.md / world.md):
  creation fn   CClass_ctor(cls /*x0, static TNativeClass*/, CName name /*x1*/, u32 size /*w2*/, u32 flags /*w3*/)
                CClass_SetAlign(cls, u32 align /*w1*/)    stores max(align, 4) at +0x74
                str cls -> [G]                            (G = class pointer global, read by tiny getters)
  register fn   x0 = cls (caller loads it from [G]); parent = getter() stored at [cls+0x10]
                per property:  name = CName_FromString("str"); type = TypeGetter(w0 = GetNativeTypeHash<T>::nativeTypeHash)
                               CProperty_Build(builder /*x0*/, cls /*x1*/, u32 offset /*w2*/, CName name /*x3*/,
                                               group /*x4*/, CBaseRTTIType* type /*x5*/, x6)
                               CClass_AddProperty(cls, builder)
Types are identified by the C++ type in the GetNativeTypeHash<T> symbol (resolved through the chained-fixup imports);
class types are mapped back to their RTTI name via the creation fn, which uses the same symbol.

The primitive addresses below are pinned to one binary build (EXPECTED_UUID). On a new build, re-derive them from the
"inkWidgetLibraryResource"/"libraryItems" string refs (creation fn and register fn) and run --self-test.
"""

import argparse
import bisect
import collections
import json
import os
import struct
import subprocess
import sys
from pathlib import Path

from validate_addresses import DEFAULT_BINARY, read_macho

PRIM = {  # absolute addresses, macOS 2.3.1
    "CName_FromString": [0x102188524, 0x103452DDC],
    "CClass_ctor": [0x102196F40, 0x102196C80],  # second = abstract-class wrapper (flags |= 3)
    "CClass_SetAlign": [0x102198100],
    "CProperty_Build": [0x102176740],
    "CClass_AddProperty": [0x102196C28],  # called at least once by every register fn, even propertyless ones
}
KNOWN = [  # (class, prop, macOS offset) verified by hand-reading the register fns
    ("inkWidgetLibraryResource", "libraryItems", 0x40),
    ("inkWidgetLibraryResource", "rootResolution", 0x39),
    ("inkWidgetLibraryResource", "externalDependenciesForInternalItems", 0x88),
]
ARG = "arg"  # value tags: int = constant, (tag, ...) = symbolic


def fnv1a64(b: bytes) -> int:
    h = 0xCBF29CE484222325
    for c in b:
        h = ((h ^ c) * 0x100000001B3) & 0xFFFFFFFFFFFFFFFF
    return h


def decode_bitmask(n, imms, immr, width):
    length = (n << 6 | (~imms & 0x3F)).bit_length() - 1
    if length < 1:
        return None
    esize = 1 << length
    s, r = imms & (esize - 1), immr & (esize - 1)
    elem = (1 << (s + 1)) - 1
    elem = ((elem >> r) | (elem << (esize - r))) & ((1 << esize) - 1)
    v = 0
    for i in range(0, width, esize):
        v |= elem << i
    return v


class Image:
    def __init__(self, path):
        L = read_macho(path)
        self.L, self.data, self.uuid = L, L["data"], L["uuid"]
        self.segs = L["segments"]
        self.starts = sorted(L["starts"])
        tvm, tsz = L["sections"][("__TEXT", "__text")]
        self.tvm, self.tend = tvm, tvm + tsz
        self.words = memoryview(self.data)[tvm - self.segs["__TEXT"][0] : tvm - self.segs["__TEXT"][0] + tsz].cast("I")
        self.cstr = L["sections"][("__TEXT", "__cstring")]
        self.got = self._got_symbols()

    def off(self, a):
        for n, (va, sz, fo) in self.segs.items():
            if n != "__PAGEZERO" and va <= a < va + sz:
                return a - va + fo
        return None

    def string(self, a):
        lo, sz = self.cstr
        if not lo <= a < lo + sz:
            return None
        o = self.off(a)
        e = self.data.find(b"\0", o)
        try:
            return self.data[o:e].decode()
        except UnicodeDecodeError:
            return None

    def fn(self, a):
        i = bisect.bisect_right(self.starts, a) - 1
        return self.starts[i], self.starts[i + 1] if i + 1 < len(self.starts) else self.tend

    def _got_symbols(self):
        """GOT slot address -> demangled symbol, from LC_DYLD_CHAINED_FIXUPS imports."""
        d = self.data
        ncmds = struct.unpack_from("<I", d, 16)[0]
        off, fx = 32, None
        for _ in range(ncmds):
            cmd, size = struct.unpack_from("<II", d, off)
            if cmd == 0x80000034:
                fx = struct.unpack_from("<I", d, off + 8)[0]
            off += size
        if fx is None:
            return {}
        _, _, imp_off, sym_off, imp_cnt, imp_fmt, _ = struct.unpack_from("<7I", d, fx)
        stride = {1: 4, 2: 8, 3: 16}[imp_fmt]
        names = []
        for i in range(imp_cnt):
            p = fx + imp_off + i * stride
            no = struct.unpack_from("<Q", d, p)[0] >> 32 if imp_fmt == 3 else struct.unpack_from("<I", d, p)[0] >> 9
            s = fx + sym_off + no
            names.append(d[s : d.find(b"\0", s)].decode())
        gva, gsz = self.L["sections"][("__DATA_CONST", "__got")]
        go = self.off(gva)
        slots = {}
        for i in range(gsz // 8):
            v = struct.unpack_from("<Q", d, go + 8 * i)[0]
            if v >> 63:
                slots[gva + 8 * i] = names[v & 0xFFFFFF]
        want = sorted({n for n in slots.values() if "GetNativeTypeHash" in n})
        out = subprocess.run(["xcrun", "c++filt"], input="\n".join(want), capture_output=True, text=True).stdout.split("\n")
        dem = dict(zip(want, out))
        return {a: dem.get(n, n) for a, n in slots.items()}

    def bl_index(self):
        calls = collections.defaultdict(list)
        w, tvm = self.words, self.tvm
        for i in range(len(w)):
            x = w[i]
            if (x & 0xFC000000) == 0x94000000:  # BL only
                imm = x & 0x3FFFFFF
                calls[tvm + 4 * i + ((imm - (1 << 26) if imm & (1 << 25) else imm) << 2)].append(tvm + 4 * i)
        return calls


def native_type(sym):
    # "unsigned long long GetNativeTypeHash<T>()::nativeTypeHash" -> T
    a, b = sym.find("GetNativeTypeHash<"), sym.rfind(">()::")
    return sym[a + 18 : b] if a >= 0 and b > a else None


def track(img, start, end, special):
    """Forward constant tracker over [start,end): register state flows along fallthrough and forward branches
    (merged by agreement); backward edges are ignored. Returns events at BL/store sites."""
    w, tvm = img.words, img.tvm
    R = [(ARG, i) if i < 8 else None for i in range(32)]
    ev, snaps, dead = [], {}, False

    def fork(t):
        if pc < t < end:
            snaps[t] = R[:] if t not in snaps else [a if a == b else None for a, b in zip(snaps[t], R)]

    for pc in range(start, end, 4):
        if pc in snaps:
            R = snaps.pop(pc) if dead else [a if a == b else None for a, b in zip(snaps.pop(pc), R)]
        elif dead:
            R = [None] * 32
        dead = False
        x = w[(pc - tvm) >> 2]
        rd = x & 31
        if (x & 0xFF000010) == 0x54000000:  # B.cond
            fork(pc + (((x >> 5) & 0x7FFFF) - (1 << 19 if x & (1 << 23) else 0)) * 4)
            continue
        if (x & 0x7E000000) == 0x34000000:  # CBZ/CBNZ
            fork(pc + (((x >> 5) & 0x7FFFF) - (1 << 19 if x & (1 << 23) else 0)) * 4)
            continue
        if (x & 0x7E000000) == 0x36000000:  # TBZ/TBNZ
            fork(pc + (((x >> 5) & 0x3FFF) - (1 << 14 if x & (1 << 18) else 0)) * 4)
            continue
        if (x & 0xFC000000) == 0x14000000:  # B
            imm = x & 0x3FFFFFF
            fork(pc + ((imm - (1 << 26) if imm & (1 << 25) else imm) << 2))
            dead = True
            continue
        if (x & 0xFFDFFC1F) == 0xD65F0000 or (x & 0xFFE00000) == 0xD4200000:  # RET/BR, BRK
            dead = True
            continue
        if (x & 0x9F000000) == 0x90000000:  # ADRP
            imm = ((x >> 29) & 3) | (((x >> 5) & 0x7FFFF) << 2)
            R[rd] = (pc & ~0xFFF) + ((imm - (1 << 21) if imm & (1 << 20) else imm) << 12)
        elif (x & 0x7F800000) in (0x11000000, 0x51000000):  # ADD/SUB imm
            rn, imm = (x >> 5) & 31, ((x >> 10) & 0xFFF) << (12 if x & (1 << 22) else 0)
            v = R[rn] if rn != 31 else None
            R[rd] = (v + imm if (x & 0x40000000) == 0 else v - imm) if isinstance(v, int) else None
            if rd == 31:
                R[31] = None
        elif (x & 0x1F800000) == 0x12800000:  # MOVN/MOVZ/MOVK
            opc, hw, imm = (x >> 29) & 3, (x >> 21) & 3, (x >> 5) & 0xFFFF
            mask = 0xFFFFFFFFFFFFFFFF if x >> 31 else 0xFFFFFFFF
            if opc == 2:
                R[rd] = imm << (16 * hw)
            elif opc == 0:
                R[rd] = ~(imm << (16 * hw)) & mask
            elif opc == 3 and isinstance(R[rd], int):
                R[rd] = (R[rd] & ~(0xFFFF << (16 * hw)) | imm << (16 * hw)) & mask
            else:
                R[rd] = None
        elif (x & 0x7F2003E0) == 0x2A0003E0 and ((x >> 10) & 0x3F) == 0:  # MOV reg (ORR rd, zr, rm)
            R[rd] = R[(x >> 16) & 31]
        elif (x & 0x7F8003E0) == 0x320003E0:  # MOV bitmask imm (ORR rd, zr, #imm)
            R[rd] = decode_bitmask((x >> 22) & 1, (x >> 10) & 0x3F, (x >> 16) & 0x3F, 64 if x >> 31 else 32)
        elif (x & 0xFC000000) == 0x94000000:  # BL
            imm = x & 0x3FFFFFF
            t = pc + ((imm - (1 << 26) if imm & (1 << 25) else imm) << 2)
            ev.append(("bl", pc, t, R[:8]))
            a0 = R[0]
            if t in special["cname"]:
                s = img.string(a0) if isinstance(a0, int) else None
                ret = ("cname", s) if s is not None else None
            elif isinstance(a0, tuple) and a0[0] == "nth":
                ret = ("type", a0[1])
            elif t in special["getter"]:
                ret = ("mem", special["getter"][t])
            else:
                ret = ("ret", t)
            for i in range(18):
                R[i] = None
            R[0] = ret
        elif (x & 0xFFFFFC1F) == 0xD63F0000:  # BLR
            for i in range(18):
                R[i] = None
        elif (x & 0x1C000000) == 0x14000000:  # other branches/system: no GPR writes we care about
            pass
        elif (x & 0x0A000000) == 0x08000000:  # loads/stores
            simd = x & (1 << 26)
            if (x & 0x3B000000) == 0x39000000:  # unsigned imm
                size, opc, rn = x >> 30, (x >> 22) & 3, (x >> 5) & 31
                a = R[rn] + (((x >> 10) & 0xFFF) << size) if isinstance(R[rn], int) and rn != 31 else None
                if opc == 0:
                    if not simd:
                        ev.append(("str", pc, R[rn] if rn != 31 else None, ((x >> 10) & 0xFFF) << size, R[rd]))
                elif not simd:
                    base = R[rn] if rn != 31 else None
                    if a is not None and a in img.got:
                        R[rd] = ("got", img.got[a])
                    elif isinstance(base, tuple) and base[0] == "got" and native_type(base[1]):
                        R[rd] = ("nth", native_type(base[1]))
                    elif a is not None:
                        R[rd] = ("mem", a)
                    else:
                        R[rd] = None
            elif (x & 0x3B000000) == 0x18000000:  # literal
                if not simd:
                    R[rd] = None
            elif (x & 0x3A000000) == 0x28000000:  # pairs
                if x & (1 << 22) and not simd:
                    R[rd] = R[(x >> 10) & 31] = None
                if x & (1 << 23) or (x & 0x3B800000) == 0x28800000:  # writeback
                    rn = (x >> 5) & 31
                    if rn != 31:
                        R[rn] = None
            else:
                if not simd:
                    R[rd] = None
                    if (x & 0x3F000000) == 0x08000000:
                        R[(x >> 16) & 31] = None
                if (x & 0x3B200C00) in (0x38000400, 0x38000C00):  # pre/post index writeback
                    rn = (x >> 5) & 31
                    if rn != 31:
                        R[rn] = None
        else:  # data processing: clobber rd
            if rd != 31:
                R[rd] = None
    return ev


def getter_shape(img, a):
    """adrp xN, G@PAGE; ldr x0, [xN, #G@OFF]; ret  ->  G"""
    o = (a - img.tvm) >> 2
    if not img.tvm <= a < img.tend - 12:
        return None
    w0, w1, w2 = img.words[o], img.words[o + 1], img.words[o + 2]
    if (w0 & 0x9F000000) != 0x90000000 or (w1 & 0xFFC0001F) != 0xF9400000 or w2 != 0xD65F03C0:
        return None
    if ((w1 >> 5) & 31) != (w0 & 31):
        return None
    imm = ((w0 >> 29) & 3) | (((w0 >> 5) & 0x7FFFF) << 2)
    page = (a & ~0xFFF) + ((imm - (1 << 21) if imm & (1 << 20) else imm) << 12)
    return page + (((w1 >> 10) & 0xFFF) << 3)


def scan(path):
    img = Image(path)
    calls = img.bl_index()
    cname_fns = set(PRIM["CName_FromString"])
    getters = {}
    for t in calls:
        g = getter_shape(img, t)
        if g is not None:
            getters[t] = g
    special = {"cname": cname_fns, "getter": getters}
    hashes = None

    def cname(v):
        nonlocal hashes
        if isinstance(v, tuple) and v[0] == "cname":
            return v[1]
        if isinstance(v, int) and v > 0xFFFFFFFF:  # literal hash
            if hashes is None:
                lo, sz = img.cstr
                blob = img.data[img.off(lo) : img.off(lo) + sz]
                hashes = {fnv1a64(s): s.decode(errors="replace") for s in set(blob.split(b"\0")) if s}
            return hashes.get(v)
        return None

    tracked = {}

    def events(f):
        if f not in tracked:
            tracked[f] = track(img, f, img.fn(f)[1], special)
        return tracked[f]

    # 1. classes: ctor + alignment + G stores
    objs = {}  # cls obj -> {name, size, align, type}
    gstore = {}  # global slot -> cls obj
    unresolved = []
    ctor_ts, align_t, build_t = set(PRIM["CClass_ctor"]), PRIM["CClass_SetAlign"][0], PRIM["CProperty_Build"][0]
    fns = {img.fn(pc)[0] for t in (*ctor_ts, align_t) for pc in calls.get(t, [])} - ctor_ts
    for f in sorted(fns):
        for e in events(f):
            if e[0] == "bl" and e[2] in ctor_ts:
                a = e[3]
                n = cname(a[1])
                if not isinstance(a[0], int) or n is None:
                    unresolved.append({"site": hex(e[1]), "kind": "class", "reason": f"cls={a[0]} name={a[1]}"})
                    continue
                objs.setdefault(a[0], {})
                objs[a[0]].update(name=n, size=a[2] if isinstance(a[2], int) else None)
            elif e[0] == "bl" and e[2] == align_t and isinstance(e[3][0], int):
                objs.setdefault(e[3][0], {})["align"] = e[3][1] if isinstance(e[3][1], int) else None
    for f in list(tracked):
        for e in tracked[f]:
            if e[0] == "str" and isinstance(e[2], int) and isinstance(e[4], int) and e[4] in objs:
                gstore[e[2] + e[3]] = e[4]
    ntype_of = collect_native_types(img, tracked, ctor_ts)

    def resolve_cls(v):
        if isinstance(v, int):
            return v if v in objs else None
        if isinstance(v, tuple) and v[0] == "mem":
            return gstore.get(v[1])
        return None

    # 2. properties
    props = collections.defaultdict(dict)
    parents = {}
    regfns = {img.fn(pc)[0] for t in (build_t, PRIM["CClass_AddProperty"][0]) for pc in calls.get(t, [])}
    nprop = 0
    for f in sorted(regfns):
        ev = events(f)
        builds = [e for e in ev if e[0] == "bl" and e[2] == build_t]
        cls_vals = {e[3][0] for e in ev if e[0] == "bl" and e[2] == PRIM["CClass_AddProperty"][0]}
        owners = {}
        for cv in cls_vals:
            if isinstance(cv, tuple) and cv[0] == ARG:
                # resolve through direct callers
                found = set()
                for cpc in calls.get(f, []):
                    for ce in events(img.fn(cpc)[0]):
                        if ce[0] == "bl" and ce[1] == cpc:
                            o = resolve_cls(ce[3][cv[1]])
                            found.add(o)
                found.discard(None)
                owners[cv] = found.pop() if len(found) == 1 else None
            else:
                owners[cv] = resolve_cls(cv)
        for e in builds:
            nprop += 1
            a = e[3]
            o = owners.get(a[1])
            n = cname(a[3])
            if o is None or n is None or not isinstance(a[2], int):
                unresolved.append({"site": hex(e[1]), "fn": hex(f), "kind": "property",
                                   "reason": ("class unresolved " if o is None else "") + ("name unresolved " if n is None else "")
                                   + ("offset not constant" if not isinstance(a[2], int) else ""),
                                   "name": n, "offset": a[2] if isinstance(a[2], int) else None})
                continue
            t = a[5][1] if isinstance(a[5], tuple) and a[5][0] == "type" else None
            props[o][n] = {"offset": a[2], "type": t}
        # parent: str <getter result> -> [cls + 0x10]
        for e in ev:
            if e[0] == "str" and e[3] == 0x10 and isinstance(e[2], tuple) and e[2] in owners and owners[e[2]]:
                pv = e[4]
                p = resolve_cls(pv) if not (isinstance(pv, tuple) and pv[0] == "ret") else None
                if p is not None:
                    parents[owners[e[2]]] = p

    rtti_of_native = {nt: objs[o]["name"] for nt, o in ntype_of.items() if o in objs and "name" in objs[o]}
    classes = {}
    for o, c in objs.items():
        if "name" not in c:
            continue
        pp = {}
        for n, p in sorted(props.get(o, {}).items(), key=lambda kv: kv[1]["offset"]):
            pp[n] = {"offset": p["offset"], "type": rtti_of_native.get(p["type"], p["type"])}
        par = parents.get(o)
        classes[c["name"]] = {"parent": objs[par]["name"] if par in objs and "name" in objs[par] else None,
                              "size": c.get("size"), "align": c.get("align"), "props": pp}
    stats = {
        "class_ctor_calls": sum(1 for t in ctor_ts for pc in calls.get(t, []) if img.fn(pc)[0] not in ctor_ts),
        "classes": len(classes),
        "classes_with_parent": sum(1 for c in classes.values() if c["parent"]),
        "classes_with_props": sum(1 for c in classes.values() if c["props"]),
        "property_build_calls": len(calls.get(build_t, [])),
        "property_sites_tracked": nprop,
        "properties_resolved": sum(len(c["props"]) for c in classes.values()),
        "properties_with_type": sum(1 for c in classes.values() for p in c["props"].values() if p["type"]),
        "unresolved": len(unresolved),
    }
    return {"binary": str(path), "uuid": img.uuid, "stats": stats, "unresolved": unresolved, "classes": classes}


def collect_native_types(img, tracked, ctor_ts):
    """GetNativeTypeHash<T> (C++ type) -> cls obj, from creation fns that touch exactly one such symbol."""
    out = {}
    for f, ev in tracked.items():
        objs = [e[3][0] for e in ev if e[0] == "bl" and e[2] in ctor_ts and isinstance(e[3][0], int)]
        if len(objs) != 1:
            continue
        nts = set()
        end = img.fn(f)[1]
        for pc in range(f, end - 4, 4):
            x, y = img.words[(pc - img.tvm) >> 2], img.words[(pc - img.tvm + 4) >> 2]
            if (x & 0x9F000000) == 0x90000000 and (y & 0xFFC00000) == 0xF9400000 and ((y >> 5) & 31) == (x & 31):
                imm = ((x >> 29) & 3) | (((x >> 5) & 0x7FFFF) << 2)
                a = (pc & ~0xFFF) + ((imm - (1 << 21) if imm & (1 << 20) else imm) << 12) + (((y >> 10) & 0xFFF) << 3)
                s = img.got.get(a)
                if s and s.startswith("unsigned long long GetNativeTypeHash<") and native_type(s):
                    nts.add(native_type(s))
        if len(nts) == 1:
            out[nts.pop()] = objs[0]
    return out


def self_test(res):
    c = res["classes"]
    for cls, prop, off in KNOWN:
        got = c.get(cls, {}).get("props", {}).get(prop, {}).get("offset")
        assert got == off, f"{cls}.{prop}: scan {got!r} != known {off:#x}"
    assert c["inkWidgetLibraryResource"]["parent"] == "CResource", c["inkWidgetLibraryResource"]["parent"]
    assert c["CGameEngine"]["size"] == 0x380, hex(c["CGameEngine"]["size"] or 0)
    # internal consistency
    bad = []
    for n, k in c.items():
        if k["size"] is not None and k["align"] and k["size"] % max(k["align"], 1):
            bad.append((n, "size % align"))
        for pn, p in k["props"].items():
            if k["size"] is not None and p["offset"] >= max(k["size"], 1):
                bad.append((n, f"{pn} offset {p['offset']:#x} >= size {k['size']:#x}"))
        # flattened chain: two different names at one offset means a misattributed register fn
        # (derived classes may legitimately re-register base fields under the same name)
        seen, p = {}, n
        while p in c:
            for pn, pr in c[p]["props"].items():
                if seen.setdefault(pr["offset"], pn) != pn:
                    bad.append((n, f"offset {pr['offset']:#x}: {seen[pr['offset']]} vs {pn} (from {p})"))
            p = c[p]["parent"]
    print(f"self-test: known offsets OK; {len(bad)} consistency issues")
    for b in bad[:30]:
        print("  ", *b)
    return bad


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("-o", "--out", default="rtti_layout_static.json")
    ap.add_argument("--compare", type=Path, help="live dump to cross-check against (data/rtti_layout_macos.json)")
    ap.add_argument("--binary", default=os.environ.get("CP2077_BINARY", DEFAULT_BINARY))
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args()
    res = scan(Path(a.binary))
    Path(a.out).write_text(json.dumps(res, indent=1))
    print(json.dumps(res["stats"], indent=1))
    reasons = collections.Counter(u["reason"].strip() for u in res["unresolved"])
    for r, n in reasons.most_common(10):
        print(f"  unresolved {n:6d}  {r}")
    if a.self_test:
        self_test(res)
    if a.compare:
        return compare(res, json.loads(a.compare.read_text()))
    return 0


def compare(res, dump):
    """Properties present in both the scan and the live dump: same offset? Exit 1 on any disagreement."""
    both = bad = 0
    for name, cls in res["classes"].items():
        live = {p["name"]: p["offset"] for p in dump["classes"].get(name, {}).get("props", [])}
        for prop, p in cls["props"].items():
            if prop in live:
                both += 1
                if live[prop] != p["offset"]:
                    bad += 1
                    print(f"  {name}.{prop}: static {p['offset']:#x}, live {live[prop]:#x}")
    print(f"compare: {both} properties in both, {bad} disagree")
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
