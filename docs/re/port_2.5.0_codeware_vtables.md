# 2.5.0 macOS port: Codeware vtable slots (batch 9)

Static analysis of the 2.5.0 binary (UUID 7D7382D0). Nothing was launched. The main session spot-checked GetEntryByHash (JournalManager.GetEntry native at 0x105254834 calls vt+0x220 with x8 sret) and GetPoiMappinPhase (vt+0x438 = 0x1030FEBEC returns the phase halfword or 5 = Invalid). These are vtable offsets used by Codeware RawVFunc declarations, not DB entries.


Binary: `~/Development/cyberpunk-backups/2026-11-03/Cyberpunk2077-2.5.0-stock`. All slot offsets are from the vtable address point (the value the ctor stores in `[this]`). Slots were read from `<scratch>/fixups.txt` with `re2/b9_vt.py VTBL N START`. Disassembly comes from `re/d.py new ADDR`, and natives were resolved with `re2/b7_native.py REFPC`.

| file:line | method | Windows offset | macOS offset | macOS arm64 signature (args, return reg or x8 sret) | FOUND/NOT FOUND |
| --- | --- | --- | --- | --- | --- |
| JournalManager.hpp:10 | GetEntries | 0x210 | 0x218 | `void(x0 this, x1 const gameJournalRequestContext*, x2 DynArray<WeakHandle<gameJournalEntry>>*)`; nothing useful in x0 | FOUND |
| JournalManager.hpp:15 | GetEntryByHash | 0x220 | 0x220 | `Handle<gameJournalEntry> (x0 this, w1 hash)`, **returned via x8 sret** (Windows passes the out Handle as arg 1) | FOUND, **sig change** |
| JournalManager.hpp:20 | ChangeEntryState | 0x268 | 0x268 | `bool w0 (x0 this, x1 Handle<entry>*, w2 state, w3 notifyOption, w4 u32)` | FOUND |
| JournalManager.hpp:27 | GetEntryState | 0x2B0 | 0x2B8 | `gameJournalEntryState w0 (x0 this, x1 Handle<entry>*)` | FOUND |
| JournalManager.hpp:31 | GetEntryTimestamp | 0x2C8 | 0x2D0 | `uint32 w0 (x0 this, x1 Handle<entry>*)` | FOUND |
| CommunitySystem.hpp:89 | ActivateCommunity | 0x1B0 | 0x1B8 | `void(x0 this, x1 u64 communityID, x2 CName entry)` | FOUND |
| CommunitySystem.hpp:93 | DeactivateCommunity | 0x1B8 | 0x1C0 | `void(x0 this, x1 u64 communityID, x2 CName entry)` | FOUND |
| CommunitySystem.hpp:97 | SetCommunityPhase | 0x1C0 | 0x1C8 | `void(x0 this, x1 u64 communityID, x2 CName entry, x3 CName phase)` | FOUND |
| CommunitySystem.hpp:101 | ResetCommunity | 0x1C8 | 0x1D0 | `void(x0 this, x1 u64 communityID, x2 CName entry)` | FOUND |
| CommunitySystem.hpp:105 | GetCommunity | 0x228 | 0x230 (0x228 is a byte-identical twin) | `WeakPtr<Community> (x0 this, x1 u64 communityID **by value**)`, **returned via x8 sret** | FOUND, **sig change** |
| CommunitySystem.hpp:110 | ActivateSpawner | 0x1D8 | 0x1E0 | `void(x0 this, x1 u64 spawnerID)` | FOUND |
| CommunitySystem.hpp:114 | DeactivateSpawner | 0x1E0 | 0x1E8 | `void(x0 this, x1 u64 spawnerID)` | FOUND |
| CommunitySystem.hpp:118 | ResetSpawner | 0x1E8 | 0x1F0 | `void(x0 this, x1 u64 spawnerID)` | FOUND |
| CommunitySystem.hpp:122 | GetSpawner | 0x260 | 0x268 | `WeakPtr<Spawner> (x0 this, x1 u64 spawnerID)`, **returned via x8 sret** | FOUND, **sig change** |
| MappinSystem.hpp:17 | SetPoiMappinPhase | 0x1D0 | 0x1D8 | `void(x0 this, w1 journalPathHash, w2 gamedataMappinPhase)` | FOUND |
| MappinSystem.hpp:22 | GetPoiMappinPhase | 0x3C8 | **0x438** (the last slot) | `gamedataMappinPhase w0 (x0 this, w1 journalPathHash)`; returns 5 (Invalid) if not found | FOUND |
| QuestsSystem.hpp:299 | QuestPhaseInstance::ExecutePath | 0x120 | 0x128 | `uint8 w0 (x0 this, x1 QuestContext*, x2 const QuestNodePath*, w3 QuestNodeID u16, x4 CName socket, x5 DynArray<QuestNodeSocket>*)` | FOUND |
| Mesh.hpp:33 | MeshComponent::LoadResource | 0x260 | 0x268 | `(x0 component, x1 JobQueue*)`; Codeware ignores the return | FOUND |
| Mesh.hpp:37 | MeshComponent::RefreshAppearance | 0x280 | 0x288 | `void(x0 component)` | FOUND |

The QuestsSystem.hpp:239-250 entries (StopPhase, PreparePhase, RestartPhase) are commented out in Codeware and were not attempted.

## Vtables used

| class | vtable (address point) | how it was found |
| --- | --- | --- |
| game::JournalManager | 0x107D2CBB0 | "gameJournalManager" registration 0x10525C66C (size 0x300, type vtbl 0x107D2D7B0). Its slot +0xF0 thunk 0x10525623C jumps to ctor 0x10523FAEC, whose `str x8,[x0]` at 0x10523FB14 stores this vtable. |
| game::CommunitySystem | 0x107C67818 | "gameCommunitySystem" registration 0x10472F70C (size 0x110, type vtbl 0x107C67B90). The +0xE0 thunk 0x10472E66C jumps to ctor 0x10472AF44, which stores it at 0x10472AF64. |
| game::mappins::MappinSystem | 0x107A9B098 | given in the brief. Script natives on the same object call +0x1B8, +0x420, +0x428 and +0x430 (natives 0x10310AB64, 0x10310AA20, 0x10310AB28, 0x10310AAEC). |
| questPhaseInstance | 0x1079E3240 | "questPhaseInstance" registration 0x1028110B8 (size 0x110, type vtbl 0x1079E33B0). The +0xE0 thunk 0x10280E4D8 jumps to ctor 0x102804A98, which stores it at 0x102804ABC. |
| entMeshComponent | 0x1078C22A8 | "entMeshComponent" registration 0x10197DB4C (size 0x1E0, type vtbl 0x1078C2558). The +0xE0 construct callback 0x10197CCC4 stores it at 0x10197CCE4. |

The JournalManager natives are registered in 0x10523D16C. Each native takes `x0` = the script context (the system itself), and the vtable it reads is `[x0]`.

## JournalManager

**GetEntries → +0x218 (0x10524470C).**
1. Body. It clears the out DynArray (`x2`, 16-byte elements). For each entry in the `+0x108` table it fetches the Handle through vt+0x220. It then applies the request context exactly as `gameJournalRequestContext` lays it out:
   - state 1/2/3/4 is tested against bytes `x1+0/+1/+2/+3` (inactive/active/succeeded/failed);
   - `x1+8` (classFilter CName) is compared with the entry's class name;
   - an optional filter object sits at `x1+0x10`.

   It then appends the entry to `x2`.
2. Vtable neighbourhood. +0x200 = GetTrackedQuest (0x1052446DC, copies `+0x128` to `[x8]`) and +0x210 = GetTrackedPOI (0x1052446F4, `+0x138` to `[x8]`). These are Windows 0x1F8 and 0x208, which puts the next slot, Windows 0x210 = GetEntries, at macOS 0x218. The script native GetQuests (0x10524DE9C → 0x10524AEDC) is a specialised copy of the same loop.

**GetEntryByHash → +0x220 (0x10524495C).**
1. Body. It takes the lock at `+0x68`, looks `w1` up in the hash map at `+0x70..+0x8C` (key at `+4` and `+8`), and writes the 16-byte Handle to `[x8]` (`mov x20,x8` … `str q0,[x20]`).
2. Natives. `JournalManager.GetEntry(Uint32)` (0x1052547C0) does `ldr w1,[sp,#0x2c]; ldr x9,[x8,#0x220]; mov x8,sp; blr x9`. `ChangeEntryStateByHash` (0x105252F2C) does the same at 0x10525301C. Internal callers 0x10524479C and 0x10524AFC8 use the same pattern.

**Signature change.** The Handle comes back in x8, and the hash is in w1, not w2.

**ChangeEntryState → +0x268 (0x105244EDC).**
1. Native. `ChangeEntryStateByHash` 0x105253030-0x105253048 runs `ldp w3,w2,[sp,#0x14]; ldr x8,[x8,#0x268]; mov x1,sp` (the Handle just returned by +0x220), then `mov w4,#1; blr x8`.
2. Body. It does `ldr x25,[x1]` (Handle deref), then vt+0x238(x1) for the entry hash. It returns `cset w0,ne` (entry != null).

+0x270 is the by-path overload, which the String `ChangeEntryState` native 0x105252BB4 calls after the +0x228 path lookup. Do not confuse the two. The signature is unchanged.

**GetEntryState → +0x2B8 (0x1052476F4).**
1. Native. GetEntryState 0x1052523F4 does `ldr x8,[x8,#0x2b8]; mov x1,sp; blr x8` (0x105252504) and stores w0.
2. Body. It runs `vt+0x238(x1)` (GetEntryHash), then tail-calls `vt+0x2C0` (state-by-hash).

**GetEntryTimestamp → +0x2D0 (0x105247924).**
1. Native. GetEntryTimestamp 0x10525251C does `ldr x8,[x8,#0x2d0]; mov x1,sp; blr x8` (0x10525262C) and stores w0.
2. Body. It runs `vt+0x238(x1)`, then looks the hash up in the map at `+0xD8..+0xF4` (lock `+0xD0`) and reads the 20-byte record at `+0x108`.

GetEntryHash itself is +0x238: native 0x10525276C calls `[x8,#0x238]`. That is Windows 0x230 + 8. The +8 rule holds for 0x230→0x238, 0x2B0→0x2B8 and 0x2C8→0x2D0, but not for 0x220 or 0x268, which is consistent with MSVC grouping overloads.

## CommunitySystem (vtable 0x107C67818)

**Community requests +0x1B8/+0x1C0/+0x1C8/+0x1D0** (0x10472C380, 0x10472C534, 0x10472C5DC, 0x10472C688). Each one first runs the exists-check 0x10472C424(x1), which is a by-value search of the u64 ID table `+0x68/+0x74`. It then pushes a 0x20-byte request onto `+0x48/+0x54` (lock `+0xA0`) laid out as `{+0 x2 entry, +8 phase (x3 or 0), +0x10 x1 id, +0x18 type}`. The types are 0, 1, 2 and 3 respectively.

The consumer is in CommunitySystem_Update 0x10472C880, at 0x10472CAEC. It resolves the community through 0x10472CCCC(id), then dispatches on the type:
- 0 → 0x104709A18 → per entry 0x1047087F4: sets the active flag `+0x28` from 0 to 1 and calls entry vt+0x20. This is **Activate**.
- 1 → 0x104709AB0 → 0x104708818: clears the flag and calls vt+0x28. This is **Deactivate**.
- 2 → 0x104709CD8(entry, phase) → 0x104708838: finds the phase CName in the entry's phase list and stores the index at `+0x2C`. This is **SetPhase**.
- 3 → 0x104709B18 → 0x10471418C: this is **Reset**.

So the evidence is the body semantics, the argument count (SetPhase alone takes x3), and the Windows +8 order.

**Spawner requests +0x1E0/+0x1E8/+0x1F0** (0x10472C740/748/750). Each does `ldr x0,[x0,#0xd8]` and tail-calls 0x1047CF720, 0x1047CF8D0 or 0x1047CFA80. Those queue `{id, type}` with types 2, 3 and 4 respectively (0x1047CF8B0, 0x1047CFA60, 0x1047CFC10).
1. Consumer. 0x1047D0814 dispatches type 2 to 0x101667480 (spawner `+0x10` active from 0 to 1, then vt+0x40: **activate**), type 3 to 0x101667460 (active from 1 to 0, then vt+0x48: **deactivate**), and type 4 to 0x1047C85BC (broadcaster reset, clears `+0x94`: **reset**).
2. Independent caller. The `FunctionalTestsGameSystem.ActivateSpawner` native 0x1040359C4 gets the system by the ICommunitySystem type. Type var 0x109CBE778 is set in 0x101668100, guarded by `GetNativeTypeHash<game::ICommunitySystem>` (GOT 0x107768CB0 and 0x1077BAF18). The native then calls `ldr x8,[x8,#0x1e0]; mov x1,x20; blr x8`. `DeactivateSpawner` 0x104035ACC calls `[x8,#0x1e8]`.

Reset (+0x1F0) rests on the consumer semantics plus the slot order, because no game caller of it was found.

**GetCommunity → +0x230 (0x10472BF60).**
1. Body. It searches the same u64 ID table (`+0x68/+0x74`) that Activate and the consumer use. The comparator 0x101667C74 is `cmp x0,x1`, so **x1 is the ID by value**. It returns `+0x78[i]` as a WeakPtr into `[x8]`: it increments the strong count to lock, then the weak count `+4` for the result.
2. Order. Windows 0x228→0x230 fits the +8 rule, and the GetCommunity-to-GetSpawner distance (7 slots) is the same on both platforms.

+0x228 (0x10472D204) is byte-identical apart from addresses (diffed), so either slot behaves the same.

**Signature change.** The out WeakPtr is in x8, and the ID is passed by value in x1. Codeware's `const uint64_t&` must become a value.

**GetSpawner → +0x268 (0x10472DB18).** It does `ldr x0,[x0,#0xd8]; b 0x1047CFFA0`, which keeps x8.
1. Body. 0x1047CFFA0 searches the spawner ID table `+0x2028/+0x2034` (the same table the three spawner request functions check) by value with x1, and returns `+0x2038[i]` into `[x8]`.
2. Order. Windows 0x260 + 8. +0x260 (0x10472DAC4) is a converting wrapper of the same lookup.

**Signature change.** The out WeakPtr moves from arg 1 to x8, and the ID is in x1.

## MappinSystem (vtable 0x107A9B098)

**SetPoiMappinPhase → +0x1D8 (0x1030FE028).**
1. Body. It allocates a 0x20-byte request. Ctor 0x1030F1844 sets type 5 and `str w1,[x0,#0x18]` (hash), then the function does `str w20,[x22,#0x1c]` (phase = w2), and enqueues the request.
2. Executor. 0x10310CD44 runs `ldr w1,[x0,#0x1c]` and calls the matched POI mappin's vt+0x1D0. That is PointOfInterestMappin::SetPhase, 0x103140998 (batch 5).

The signature is unchanged.

**GetPoiMappinPhase → +0x438 (0x1030FEBEC).** It is the only fixup pointing at this function (0x107A9B4D0), and it has no BL callers.
1. Body. `add x0,x0,#0x110` → 0x103114E5C(w1 hash, &state), which finds the hash in the POI saved-state store. It then runs `ldurh w8,[state]; mov w9,#5; csel w0,w8,w9,ne`. So it returns the phase halfword, or `gamedataMappinPhase::Invalid` (5) when the hash is missing.
2. Data link. The halfword it returns is the one PointOfInterestMappin::SetPhase 0x103140998 reads (0x1030FEC24 = the same store at `+0x110`) and writes (0x103105358) as the phase (batch 5: the halfword is bounded to ≤3). Script native GetPointOfInterestMappinSavedState 0x10310A428 reads the same store.

Slot +0x438 is contiguous with +0x420/+0x428/+0x430, which natives call on the same object, and +0x440/+0x448 is the next vtable's header. The previous guess +0x3D0 (0x10310370C) is not it. Windows 0x3C8 → macOS 0x438 is an offset of +0x70, so the +8 hint does not hold here.

## QuestPhaseInstance::ExecutePath → +0x128 (0x102808484)

1. Self-recursion. At 0x102808934 it calls `ldr x8,[x25]; ldr x8,[x8,#0x128]` on the child phase, with the same six arguments `x1,x2,x3,x4,x5` (ctx, path, nodeID, socket, out), bracketed by phase-stack push/pop 0x1028037A0/0x10280384C.
2. Leaf call. It looks the node up by `w3` in the node map `+0xE0..+0xFC`, builds `QuestNodeSocket{x4 name, 0}` (or a fixed CName for one node class), and calls ExecuteGraph 0x10280B7D0 (batch 5) as `(this, ctx, &node, &socket, w4=1, x5 out)`. The return `w0` is a u8 (`cmp w22,#2`).

+0x120 (0x102807BE4) is a sibling path walker with the same prologue but a different body. The signature is unchanged.

## MeshComponent (vtable 0x1078C22A8)

The 2.3.1 notes (RED4ext.SDK/docs/re/archivexl_port.md:87) put LoadResource at +0x268 (0x100C685FC) and RefreshAppearance at +0x288 (0x100C699AC). On 2.5.0:
- **+0x268 = 0x10197B314** matches 0x100C685FC instruction for instruction: `mov x19,x1; mov x20,x0; bl …; ldr x8,[x20,#0x150]; …ccmp…; add x0,x20,#0x150; mov w1,#0; bl …`, then the job added to the `x19` JobQueue.
- **+0x288 = 0x10197C6C4** matches 0x100C699AC: `mov x19,x0; bl helper; mov x0,x19; mov w1,#0; b …`.

So the evidence is the same slot in the RTTI-found vtable plus an identical body. The signatures are unchanged.

## Summary

19 of 19 FOUND; nothing is NOT FOUND (the 3 commented-out QuestsSystem slots were not attempted). The +8 hint holds for most entries. It fails for JournalManager GetEntryByHash (0x220) and ChangeEntryState (0x268), which keep their Windows offsets, and for GetPoiMappinPhase (0x3C8 → 0x438).

Codeware needs signature changes on macOS for three methods:
- GetEntryByHash: Handle returned via x8, hash in w1.
- GetCommunity: WeakPtr via x8, ID by value in x1.
- GetSpawner: WeakPtr via x8, ID in x1.

All other signatures match the Windows declarations register for register.
