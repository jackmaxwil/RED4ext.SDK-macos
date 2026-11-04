#!/usr/bin/env python3
"""Port the verified entries of the address DB from one game binary to the next (patch day).

  port_addresses.py OLD_BINARY NEW_BINARY [--db DB] [--out OUT] [--game-version X.Y.Z] [--report FILE]

OLD_BINARY must be the build the DB was verified against (its UUID must equal the DB's uuid). Only entries with
"verified": true are ported. Every other entry, and every entry that cannot be ported, keeps its old offset without
"verified" (the loader refuses plugins that need it). Entries the generator scripts own (config variables, medium heap,
DRS, upscaler scale table) are re-derived by running those scripts on the new binary afterwards (tools/cp-patchday).

Function matching (old function start -> new function start), in rounds:
  anchors   an exported symbol with the same name in both binaries; or the old function's whole body with
            position-dependent immediates masked (B/BL, B.cond, CBZ/TBZ, ADR/ADRP, LDR literal, the ADD/LDR/STR offset
            paired with an ADRP) equal to exactly one new function's, the old body unique too, and at least MIN_BODY
            instructions long.
  calls     for each matched pair, the two bodies are aligned (identical bodies by index, others by their longest
            common runs of masked instructions) and each aligned BL pair votes old callee -> new callee. A callee is
            matched when all its votes agree and the new function is not claimed by another; a single vote also needs
            the two bodies to be similar (SIMILAR).
Data and mid-function code: aligned ADRP+ADD/LDR/STR pairs in matched functions vote old address -> new address. Data
needs at least two votes for the same address. Entries that get conflicting votes or none stay unverified.
"""

from __future__ import annotations

import argparse
import bisect
import difflib
import hashlib
import json
import struct
import subprocess
import sys
from collections import Counter, defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from validate_addresses import ROOT, SEGS, load_names, read_macho  # noqa: E402

MIN_BODY = 8
MAX_BODY = 4096
SIMILAR = 0.75  # SequenceMatcher ratio of the masked bodies a single vote needs
ROUNDS = 8
PREFIX = 24
DOMINANT = 0.97
SHARED = 100
MANY_VOTES = 20


def sx(v: int, bits: int) -> int:
    return v - (1 << bits) if v & (1 << (bits - 1)) else v


def is_bl(w: int) -> bool:
    return (w & 0xFC000000) in (0x94000000, 0x14000000)


class Image:
    def __init__(self, path: Path):
        m = read_macho(path)
        self.path = path
        self.uuid = m["uuid"]
        self.segs = m["segments"]
        self.sections = m["sections"]
        self.data = m["data"]
        self.tvm, tsz = m["sections"][("__TEXT", "__text")]
        self.base = self.segs["__TEXT"][0]
        self.words = struct.unpack_from(f"<{tsz // 4}I", m["data"], self.tvm - self.base)
        self.end = self.tvm + tsz
        self.starts = sorted(a for a in m["starts"] if self.tvm <= a < self.end)
        self.start_set = set(self.starts)
        self.masked = self._mask()

    def idx(self, addr: int) -> int:
        return (addr - self.tvm) >> 2

    def func_of(self, addr: int) -> int | None:
        i = bisect.bisect_right(self.starts, addr) - 1
        return self.starts[i] if i >= 0 and addr < self.end else None

    def func_end(self, s: int) -> int:
        i = bisect.bisect_right(self.starts, s)
        return self.starts[i] if i < len(self.starts) else self.end

    def _mask(self) -> list[int]:
        out = list(self.words)
        adrp_at: dict[int, int] = {}  # Rd -> index of the last ADRP that wrote it
        for i, w in enumerate(self.words):
            if (w & 0x7C000000) == 0x14000000:  # B, BL
                out[i] = w & 0xFC000000
            elif (w & 0xFF000010) == 0x54000000 or (w & 0x7E000000) == 0x34000000:  # B.cond, CBZ/CBNZ
                out[i] = w & 0xFF00001F
            elif (w & 0x7E000000) == 0x36000000:  # TBZ/TBNZ
                out[i] = w & 0xFFF8001F
            elif (w & 0x1F000000) == 0x10000000:  # ADR, ADRP
                out[i] = w & 0x9F00001F
                if w & 0x80000000:
                    adrp_at[w & 31] = i
            elif (w & 0x3B000000) == 0x18000000:  # LDR literal
                out[i] = w & 0xFF00001F
            elif i - adrp_at.get((w >> 5) & 31, -9) <= 4 and (
                (w & 0x7F800000) == 0x11000000 or (w & 0x3B000000) == 0x39000000  # ADD imm, LDR/STR uimm
            ):
                out[i] = w & 0xFFC003FF
        return out

    def body(self, s: int) -> list[int]:
        i = self.idx(s)
        return self.masked[i : i + min(self.idx(self.func_end(s)) - i, MAX_BODY)]

    def body_key(self, s: int) -> tuple[int, bytes]:
        b = self.body(s)
        return (self.func_end(s) - s) >> 2, hashlib.blake2b(struct.pack(f"<{len(b)}I", *b), digest_size=16).digest()

    def call_target(self, k: int) -> int | None:
        w = self.words[k]
        return self.tvm + 4 * k + (sx(w & 0x3FFFFFF, 26) << 2) if is_bl(w) else None

    def ref_target(self, k: int) -> int | None:
        """Address an ADD/LDR/STR at index k forms from an ADRP within the 4 instructions before it."""
        w = self.words[k]
        rn = (w >> 5) & 31
        if (w & 0x7F800000) == 0x11000000:
            lo = (w >> 10) & 0xFFF
        elif (w & 0x3B000000) == 0x39000000:
            lo = ((w >> 10) & 0xFFF) << (4 if (w & 0x04000000) and ((w >> 23) & 1) else w >> 30)
        else:
            return None
        for j in range(k - 1, max(k - 5, -1), -1):
            p = self.words[j]
            if (p & 0x9F000000) == 0x90000000 and (p & 31) == rn:
                imm = ((p >> 29) & 3) | (((p >> 5) & 0x7FFFF) << 2)
                return ((self.tvm + 4 * j) & ~0xFFF) + (sx(imm, 21) << 12) + lo
        return None

    def string_refs(self) -> dict[bytes, int | None]:
        """C string content -> the one function referencing it (None if several do). Unique strings only."""
        sv, ssz = self.sections[("__TEXT", "__cstring")]
        raw = self.data[sv - self.base : sv - self.base + ssz]
        at: dict[int, bytes] = {}
        count: Counter = Counter()
        p = 0
        while p < len(raw):
            q = raw.find(b"\0", p)
            if q < 0:
                break
            if q - p >= 6:
                at[sv + p] = raw[p:q]
                count[raw[p:q]] += 1
            p = q + 1
        out: dict[bytes, int | None] = {}
        for k, w in enumerate(self.words):
            if (w & 0x7F800000) != 0x11000000:
                continue
            a = self.ref_target(k)
            if a is None or a not in at or count[at[a]] != 1:
                continue
            f = self.func_of(self.tvm + 4 * k)
            text = at[a]
            out[text] = f if text not in out or out[text] == f else None
        return out

    def data_refs(self) -> tuple[dict[int, set[int]], dict[int, set[int]]]:
        """Function -> addresses it forms with ADRP+ADD/LDR/STR, and the reverse."""
        refs: dict[int, set[int]] = defaultdict(set)
        users: dict[int, set[int]] = defaultdict(set)
        for k, w in enumerate(self.words):
            if (w & 0x7F800000) != 0x11000000 and (w & 0x3B000000) != 0x39000000:
                continue
            a = self.ref_target(k)
            if a is None:
                continue
            f = self.func_of(self.tvm + 4 * k)
            refs[f].add(a)
            users[a].add(f)
        return refs, users

    def unique_strings(self) -> dict[bytes, int]:
        """C string content -> its address, for strings that occur once."""
        sv, ssz = self.sections[("__TEXT", "__cstring")]
        raw = self.data[sv - self.base : sv - self.base + ssz]
        at: dict[bytes, int] = {}
        dup: set[bytes] = set()
        p = 0
        while p < len(raw):
            q = raw.find(b"\0", p)
            if q < 0:
                break
            if q - p >= 4:
                s = raw[p:q]
                if s in at:
                    dup.add(s)
                at[s] = sv + p
            p = q + 1
        return {s: a for s, a in at.items() if s not in dup}

    def call_graph(self) -> tuple[dict[int, set[int]], dict[int, set[int]]]:
        callees: dict[int, set[int]] = defaultdict(set)
        callers: dict[int, set[int]] = defaultdict(set)
        for k, w in enumerate(self.words):
            if (w & 0xFC000000) == 0x94000000:  # BL only: a B is often a tail call into the same function
                d = self.call_target(k)
                if d in self.start_set:
                    f = self.func_of(self.tvm + 4 * k)
                    callees[f].add(d)
                    callers[d].add(f)
        return callees, callers

    def code_pointers(self) -> tuple[dict[int, int], dict[int, list[int]]]:
        """Data slots holding a function start (chained-fixup rebase: target in the low 36 bits)."""
        slot: dict[int, int] = {}
        of: dict[int, list[int]] = defaultdict(list)
        for seg in ("__DATA_CONST", "__DATA"):
            vm, sz, fo = self.segs[seg]
            n = min(sz, len(self.data) - fo) // 8
            for i, v in enumerate(struct.unpack_from(f"<{n}Q", self.data, fo)):
                if v >> 63:
                    continue
                t = v & 0xFFFFFFFFF
                if t < self.base:
                    t += self.base
                if t in self.start_set:
                    slot[vm + 8 * i] = t
                    of[t].append(vm + 8 * i)
        return slot, of

    def symbols(self) -> dict[str, int]:
        out: dict[str, int] = {}
        dup: set[str] = set()
        nm = subprocess.run(["nm", "-U", str(self.path)], capture_output=True, text=True, check=True).stdout
        for line in nm.splitlines():
            f = line.split()
            if len(f) == 3:
                if f[2] in out:
                    dup.add(f[2])
                out[f[2]] = int(f[0], 16)
        return {k: v for k, v in out.items() if k not in dup}


def align(old: Image, new: Image, s: int, t: int, ratio_out: list | None = None) -> list[tuple[int, int]]:
    """Aligned instruction index pairs (old k, new k) of two matched functions."""
    a, b = old.body(s), new.body(t)
    i0, j0 = old.idx(s), new.idx(t)
    if a == b:
        if ratio_out is not None:
            ratio_out.append(1.0)
        return [(i0 + i, j0 + i) for i in range(len(a))]
    sm = difflib.SequenceMatcher(None, a, b, autojunk=False)
    if ratio_out is not None:
        ratio_out.append(sm.ratio())
    return [(i0 + x + n, j0 + y + n) for x, y, size in sm.get_matching_blocks() for n in range(size)]


def dominant(c: Counter) -> int | None:
    """The candidate all votes agree on, or that has at least DOMINANT of them (and 10+): difflib occasionally pairs
    the wrong BL or ADRP, so a few stray votes are expected among thousands."""
    if len(c) == 1:
        return next(iter(c))
    (b, n), = c.most_common(1)
    return b if n >= 10 and n >= DOMINANT * sum(c.values()) else None


def similar(old: Image, new: Image, s: int, t: int) -> float:
    a, b = old.body(s), new.body(t)
    if not a or not b or not 0.5 <= len(a) / len(b) <= 2:
        return 0.0
    if len(a) < MIN_BODY or len(b) < MIN_BODY:  # tiny bodies only count when identical
        return 1.0 if a == b else 0.0
    return 1.0 if a == b else difflib.SequenceMatcher(None, a, b, autojunk=False).ratio()


def match_functions(old: Image, new: Image, log, holdout: bool = False):
    fmap: dict[int, int] = {}
    how: dict[int, str] = {}
    osym, nsym = old.symbols(), new.symbols()
    truth: dict[int, int] = {}
    for name, a in osym.items():
        b = nsym.get(name)
        if b is not None and a in old.start_set and b in new.start_set:
            truth[a] = b
    if holdout == "symbols":
        # Half the symbol pairs stay anchors (so call evidence can reach the other half); the rest are ground truth.
        keep = {a: b for a, b in truth.items() if (a >> 2) % 2 == 0}
        truth = {a: b for a, b in truth.items() if a not in keep}
        log(f"holdout: {len(keep)} symbol anchors, {len(truth)} symbol pairs kept out as ground truth")
    else:
        keep = truth
    for a, b in keep.items():
        fmap[a], how[a] = b, "symbol"
    log(f"symbol anchors: {len(fmap)}")
    okeys = Counter(old.body_key(s) for s in old.starts)
    nidx: dict[tuple[int, bytes], list[int]] = defaultdict(list)
    for s in new.starts:
        nidx[new.body_key(s)].append(s)
    taken = set(fmap.values())
    for s in old.starts:
        if s in fmap:
            continue
        k = old.body_key(s)
        c = nidx.get(k)
        if k[0] >= MIN_BODY and okeys[k] == 1 and c and len(c) == 1 and c[0] not in taken:
            fmap[s], how[s] = c[0], "body"
            taken.add(c[0])
    log(f"+ body anchors: {len(fmap)}")

    # Strings: a C string (same content, unique in both binaries) referenced by exactly one function in each votes
    # for that pair. Accepted with 2+ agreeing votes, or 1 and similar bodies.
    ostr, nstr = old.string_refs(), new.string_refs()
    svotes: dict[int, Counter] = defaultdict(Counter)
    for text, fo in ostr.items():
        fn = nstr.get(text)
        if fo is not None and fn is not None:
            svotes[fo][fn] += 1
    n0 = len(fmap)
    if holdout == "strings":
        # Functions named by 2+ unique strings: half are ground truth (not anchored), so call edges can reach them.
        truth = {s: next(iter(c)) for s, c in svotes.items() if len(c) == 1 and max(c.values()) >= 2
                 and (s >> 2) % 2 and s not in fmap}
        log(f"holdout: {len(truth)} string pairs kept out as ground truth")
    for s, c in svotes.items():
        if s in fmap or len(c) != 1 or (holdout == "strings" and s in truth):
            continue
        t, n = next(iter(c.items()))
        if t not in taken and (n >= 2 or similar(old, new, s, t) >= SIMILAR):
            fmap[s], how[s] = t, f"strings ({n})"
            taken.add(t)
    log(f"+ string anchors: {len(fmap)} (+{len(fmap) - n0})")

    # Prefix: the first PREFIX masked instructions unique in both binaries, and similar bodies.
    def pkey(img: Image, s: int):
        b = img.body(s)
        return tuple(b[:PREFIX]) if len(b) >= PREFIX else None

    opk = Counter(pkey(old, s) for s in old.starts)
    npk: dict[tuple, list[int]] = defaultdict(list)
    for s in new.starts:
        k = pkey(new, s)
        if k:
            npk[k].append(s)
    n0 = len(fmap)
    for s in old.starts:
        if s in fmap:
            continue
        k = pkey(old, s)
        c = npk.get(k) if k else None
        if c and opk[k] == 1 and len(c) == 1 and c[0] not in taken and similar(old, new, s, c[0]) >= SIMILAR:
            fmap[s], how[s] = c[0], "prefix"
            taken.add(c[0])
    log(f"+ prefix anchors: {len(fmap)} (+{len(fmap) - n0})")

    ocallees, _ = old.call_graph()
    ncallees, ncallers = new.call_graph()
    oslot, oslots_of = old.code_pointers()
    nslot, nslots_of = new.code_pointers()
    log("call graph and vtable slots indexed")

    orefs, _ = old.data_refs()
    nrefs, nusers = new.data_refs()
    # Data map: unique strings by content, then data addresses whose code references vote dominantly (each round).
    nus = new.unique_strings()
    dmap: dict[int, int] = {a: nus[s] for s, a in old.unique_strings().items() if s in nus}
    log(f"data references indexed; {len(dmap)} strings mapped")

    data_votes: dict[int, Counter] = defaultdict(Counter)
    frontier = list(fmap.items())
    for r in range(ROUNDS):
        votes: dict[int, Counter] = defaultdict(Counter)
        for s, t in frontier:
            for i, j in align(old, new, s, t):
                ow = old.words[i]
                if is_bl(ow):
                    if is_bl(new.words[j]):
                        votes[old.call_target(i)][new.call_target(j)] += 1
                else:
                    a = old.ref_target(i)
                    if a is not None:
                        b = new.ref_target(j)
                        if b is not None:
                            data_votes[a][b] += 1
        added = []
        for a, c in votes.items():
            if a in fmap or a not in old.start_set:
                continue
            b = dominant(c)
            if b is None or b in taken or b not in new.start_set:
                continue
            n = c[b]
            # Holdout against string-identified functions: votes alone picked look-alike siblings and dissimilar
            # functions (5 of 94 wrong), so a call match needs a similar body that is unique in both binaries.
            # Many independent callers agreeing (MANY_VOTES+) stand on their own.
            if n >= MANY_VOTES or (okeys[old.body_key(a)] == 1 and len(nidx.get(new.body_key(b), ())) <= 1
                                   and similar(old, new, a, b) >= SIMILAR):
                kind = "call" if len(c) == 1 else f"call dominant ({n} of {sum(c.values())})"
                fmap[a], how[a] = b, f"{kind} round {r + 1} ({n} votes)"
                taken.add(b)
                added.append((a, b))
        # A matched function whose call votes point elsewhere must not hide: recorded for the report.
        for a, c in votes.items():
            if a in fmap and dominant(c) != fmap[a] and any(b != fmap[a] for b in c):
                how[a] = how[a] + f" [conflicting call votes {dict((hex(k), v) for k, v in c.most_common(4))}]"

        def accept(a: int, b: int, why: str, min_sim: float) -> None:
            if a in fmap or b in taken or a not in old.start_set or b not in new.start_set:
                return
            if similar(old, new, a, b) >= min_sim:
                fmap[a], how[a] = b, f"{why} round {r + 1}"
                taken.add(b)
                added.append((a, b))

        # Residual callee: a matched pair where exactly one callee on each side is still unmatched.
        rvotes: dict[int, Counter] = defaultdict(Counter)
        for s, t in fmap.items():
            uo = {c for c in ocallees.get(s, ()) if c not in fmap}
            if len(uo) != 1:
                continue
            un = {c for c in ncallees.get(t, ()) if c not in taken}
            if len(un) == 1:
                rvotes[next(iter(uo))][next(iter(un))] += 1
        for a, c in rvotes.items():
            if len(c) == 1:
                b, n = next(iter(c.items()))
                accept(a, b, f"residual callee ({n} votes)", SIMILAR)

        # Callee set: the new functions calling all of an unmatched function's matched callees (2+ distinct).
        for s in old.starts:
            if s in fmap:
                continue
            mc = {fmap[c] for c in ocallees.get(s, ()) if c in fmap}
            if len(mc) < 2:
                continue
            cand = None
            for c in sorted(mc, key=lambda c: len(ncallers.get(c, ()))):
                cs = ncallers.get(c, set())
                cand = set(cs) if cand is None else cand & cs
                if len(cand) <= 1:
                    break
            cand = {x for x in cand or () if x not in taken}
            if len(cand) == 1:
                accept(s, next(iter(cand)), f"callee set ({len(mc)})", 0.6)

        # Data-ref set: the new functions referencing all of an unmatched function's mapped data (2+ addresses).
        for d, c in data_votes.items():
            if d not in dmap:
                v = dominant(c)
                if v is not None and c[v] >= 2:
                    dmap[d] = v
        for s in old.starts:
            if s in fmap:
                continue
            md = {dmap[d] for d in orefs.get(s, ()) if d in dmap}
            if len(md) < 2:
                continue
            cand = None
            for d in sorted(md, key=lambda d: len(nusers.get(d, ()))):
                cand = set(nusers.get(d, set())) if cand is None else cand & nusers.get(d, set())
                if len(cand) <= 1:
                    break
            cand = {x for x in cand or () if x not in taken}
            if len(cand) == 1:
                accept(s, next(iter(cand)), f"data-ref set ({len(md)})", SIMILAR)

        # Vtable slots: an old slot pointing at an unmatched function is located in the new binary by its neighbours
        # (slots +-8*d that point at matched functions); all slots of the function must agree.
        vvotes: dict[int, Counter] = defaultdict(Counter)
        for t, slots in oslots_of.items():
            if t in fmap:
                continue
            # A virtual in SHARED+ vtables is a base-class implementation (e.g. a CClass virtual in every RTTI type's
            # vtable): its slot is located in a few of them, through neighbours that are shared just as widely.
            shared = len(slots) >= SHARED
            for p in slots[: 3 if shared else 20]:
                pv: Counter = Counter()
                voters = 0
                for d in range(-16, 17):
                    f = oslot.get(p + 8 * d)
                    if d == 0 or f is None or f not in fmap:
                        continue
                    qs = nslots_of.get(fmap[f], ())
                    if len(qs) > (20000 if shared else 50):
                        continue
                    voters += 1
                    for q in qs:
                        pv[q - 8 * d] += 1
                if not pv:
                    continue
                n = max(pv.values())
                tops = {nslot.get(q) for q, v in pv.items() if v == n}
                # Every best-placed slot (one per vtable that matches as well) must hold the same function.
                if n >= 3 and n >= 0.9 * voters and len(tops) == 1 and None not in tops:
                    vvotes[t][next(iter(tops))] += 1
        for a, c in vvotes.items():
            if len(c) == 1:
                b, n = next(iter(c.items()))
                # Sibling classes' vtables hold look-alike virtuals: the slot only counts when the body identifies
                # one function in each binary.
                if len(oslots_of[a]) >= SHARED and n >= 3:
                    accept(a, b, f"shared vtable slot ({n} slots of {len(oslots_of[a])})", 0.5)
                elif okeys[old.body_key(a)] == 1 and len(nidx.get(new.body_key(b), ())) == 1:
                    accept(a, b, f"vtable slot ({n} slots)", SIMILAR)
        log(f"round {r + 1}: +{len(added)} functions, total {len(fmap)}")
        if not added:
            break
        frontier = added
    if holdout:
        # Error rate per kind of evidence, against the exported symbols (same name = same function).
        res: dict[str, Counter] = defaultdict(Counter)
        for a, b in truth.items():
            if a in fmap:
                k = how[a].split(" round")[0].split(" (")[0]
                res[k]["right" if fmap[a] == b else "WRONG"] += 1
                if fmap[a] != b:
                    log(f"holdout WRONG {how[a]}: old {a:#x} -> {fmap[a]:#x}, symbol says {b:#x}; "
                        f"similar(pred)={similar(old, new, a, fmap[a]):.2f} similar(truth)={similar(old, new, a, b):.2f} "
                        f"len {(old.func_end(a) - a) // 4}/{(new.func_end(fmap[a]) - fmap[a]) // 4}/{(new.func_end(b) - b) // 4}")
        for k, c in sorted(res.items()):
            log(f"holdout {k}: {dict(c)}")
    return fmap, how, data_votes


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("old", type=Path)
    ap.add_argument("new", type=Path)
    ap.add_argument("--db", type=Path, default=Path(__file__).resolve().parents[1] / "cyberpunk2077_addresses.json")
    ap.add_argument("--out", type=Path)
    ap.add_argument("--game-version")
    ap.add_argument("--report", type=Path)
    ap.add_argument("--map", type=Path, help="write the function map (old -> new, evidence) as JSON")
    ap.add_argument("--holdout", choices=["symbols", "strings"],
                    help="evaluate the matcher against half of the exported symbols, or of the 2+-string pairs; no output")
    a = ap.parse_args()
    log = lambda m: print(m, file=sys.stderr, flush=True)  # noqa: E731

    db = json.loads(a.db.read_text())
    log("reading binaries ...")
    old, new = Image(a.old), Image(a.new)
    if db["uuid"].replace("-", "").upper() != old.uuid:
        raise SystemExit(f"{a.old} ({old.uuid}) is not the binary the DB was verified against ({db['uuid']})")
    fmap, how, data_votes = match_functions(old, new, log, a.holdout)
    if a.holdout:
        return 0
    if a.map:
        a.map.write_text(json.dumps({hex(k): [hex(v), how[k]] for k, v in fmap.items()}))

    def absaddr(img: Image, off: str) -> tuple[int, int]:
        s, o = off.split(":")
        return int(s), img.segs[SEGS[int(s)]][0] + int(o, 16)

    out_entries, report, stats = [], [], Counter()
    names, _ = load_names([ROOT / "include"])
    for e in db["Addresses"]:
        ne = {k: v for k, v in e.items() if k != "verified"}
        if e.get("verified"):
            seg, t = absaddr(old, e["offset"])
            c, why = None, "no evidence"
            if t in old.start_set:
                if t in fmap and "conflicting" not in how[t]:
                    c, why = fmap[t], how[t]
                elif t in fmap:
                    why = how[t]
            elif old.tvm <= t < old.end:
                f = old.func_of(t)
                if f in fmap and "conflicting" not in how[f]:
                    hit = [j for i, j in align(old, new, f, fmap[f]) if i == old.idx(t)]
                    if hit:
                        c, why = new.tvm + 4 * hit[0], f"inside matched function ({how[f]})"
            else:
                v = data_votes.get(t)
                if v and dominant(v) is not None and v[dominant(v)] >= 2:
                    c = dominant(v)
                    why = f"data refs ({v[c]} of {sum(v.values())} votes)"
                elif v and dominant(v) is not None:
                    # One referencing function is not enough: on 2.5.0, 12 of 150 config variables ported by a single
                    # vote landed on a neighbouring variable (checked against config_var_dump.py's name-based dump).
                    why = f"data refs (1 vote, {dominant(v):#x}): too weak"
                elif v:
                    why = f"conflicting data refs {dict((hex(k), n) for k, n in v.most_common(4))}"
            if c is not None:
                sv, ss, _ = new.segs[SEGS[seg]]
                if not sv <= c < sv + ss:
                    c, why = None, f"candidate {c:#x} outside {SEGS[seg]}"
            if c is not None:
                ne["offset"] = f"{seg}:0x{c - new.segs[SEGS[seg]][0]:X}"
                ne["verified"] = True
                stats["ported"] += 1
            else:
                stats["not ported"] += 1
            report.append(f"| {e['hash']} | {names.get(int(e['hash']), '')} | {e['offset']} | "
                          f"{ne['offset'] if c else '-'} | {'ported' if c else 'NOT PORTED'}: {why} |")
        out_entries.append(ne)

    out = dict(db)
    u = new.uuid
    out["uuid"] = f"{u[:8]}-{u[8:12]}-{u[12:16]}-{u[16:20]}-{u[20:]}"
    if a.game_version:
        out["game_version"] = a.game_version
    out["Addresses"] = out_entries
    if "stats" in out:
        out["stats"] = dict(out["stats"], verified=sum(1 for x in out_entries if x.get("verified")))
    if a.out:
        a.out.write_text(json.dumps(out, indent=2) + "\n")
    if a.report:
        head = (f"# Address port {db.get('game_version', '?')} -> {out.get('game_version', '?')}\n\n"
                f"Generated by `scripts/port_addresses.py` from {old.uuid} to {new.uuid}. Every entry verified on the old "
                "build is listed with the evidence that ported it (see the script's docstring for what each kind "
                "requires); NOT PORTED entries lost `verified`.\n\n"
                f"{dict(stats)}\n\n| hash | name | old | new | evidence |\n| --- | --- | --- | --- | --- |\n")
        a.report.write_text(head + "\n".join(report) + "\n")
    log(str(dict(stats)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
