# 2.5.0 macOS port: game-system vtables (DynamicEntitySystem crash)

Static analysis of the 2.5.0 binary (UUID 7D7382D0). Nothing was launched. All addresses are unslid. Slot offsets are from the vtable address point (the value the ctor stores in `[this]`). Slots come from the cached fixups (`re2/b9_vt.py`). Disassembly comes from `re2/b5_h.py`.

## Verdict

The slots are right. The signature is wrong. `GetPersistentState` returns the Handle through **x8 sret** on macOS. The SDK declares it MSVC-style, with the out Handle as argument 1. Codeware therefore calls the right function with every argument shifted by one register, and x8 holds the call target. The function writes the empty Handle to `[x8]`, which is its own first instruction in `__TEXT`.

IGameSystem did not gain a virtual in 2.5.0. No derived slot shifts.

## The crash

- Fault pc 0x102D0E790 is inside **0x102D0E588-0x102D0E9F4**. That function is `gamePersistencySystem::GetPersistentState`.
- Exactly one pointer to it exists: 0x107A5A6A0. That is slot **+0x1B8** of the gamePersistencySystem vtable 0x107A5A4E8.
- Codeware.dylib 0xBEA70-0xBEA8C: `ldr x0,[x19,#0x110]; ldr x3,[x19,#0xf0]; ldr x8,[x0]; ldr x8,[x8,#0x1b8]; add x2,…; add x1,x19,#0xf8; mov w4,#1; blr x8`. So x1 = &m_persistentState, x2 = &SystemPersistentID, x3 = CClass*, w4 = true, and **x8 = the target 0x102D0E588**.
- 0x102D0E5A4 `mov x19,x8` takes x8 as the sret pointer. 0x102D0E5A8 `ldr x8,[x1]` reads the PersistentID. Codeware's x1 points at an empty Handle, so this is 0. 0x102D0E5AC `cbz x8,0x102D0E790` jumps to the "return empty Handle" exit.
- 0x102D0E790 `stp xzr,xzr,[x19]` writes 16 zero bytes to 0x102D0E588. That is the reported fault address, in `__TEXT`. The `ldaddalb` at 0x102D0E78C only precedes it in the listing. The crashing path arrives by the branch at 0x102D0E5AC.
- Codeware meant to call this function. The slot is correct. Only the calling convention differs.

## gamePersistencySystem (vtable 0x107A5A4E8)

How it was found:
- The ctor 0x102D0D610 calls IGameSystem ctor 0x101AEB288. Then 0x102D0D62C-0x102D0D638 does `adrp/add #0x4d8; add #0x10; str x8,[x0]`, which stores 0x107A5A4E8.
- Slot +0x00 is 0x102D157C0. It returns the static class at 0x109CD14E8. The neighbouring registration function 0x102D15750 references the string "gamePersistencySystem" (0x10756BE55).
- The derived slots run from +0x1B8 to +0x260 (22 slots). The vtable ends at +0x268, where the next one starts (two empty words, then 0x100F611E0).

GetPersistentState is **+0x1B8** (0x102D0E588). Its real arm64 signature is `Handle<PersistentState> (x0 this, x1 const PersistentID*, x2 CClass*, w3 bool create)`, returned via x8.
- x1. 0x102D0E5A8 reads `[x1]`, which is the 64-bit entityHash, and returns empty when it is 0. 0x102D0E5C4 hashes x1 through 0x1016F2400.
- x2. 0x102D0E5D0 reads `[x23+0x70]` and tests 0x400. That is a CClass flags word.
- w3. w24 picks one of two paths: find-or-create 0x102D06A88, or find-only 0x102D06D64 (branch at 0x102D0E5F4).
- Lock. The lock is at this+0x1E0 (0x102D0E61C), with a hash map at +0x1E8..+0x204. It is released with `ldaddalb -1` (0x102D0E694, 0x102D0E78C).
- Return. 0x102D0E6B8 does `stp xzr,xzr,[x19]`. 0x102D0E6C4-0x102D0E6E8 increments the state's refcount and copies its 16-byte Handle at `+0x60` into `[x19]`.

The other persistency slots Codeware uses match the SDK clang layout. Their signatures are unchanged:

| SDK method | macOS slot | fn | evidence |
| --- | --- | --- | --- |
| (sub_1B0) | +0x1C0 | 0x102D0EA48 | 5 args (x1..x4), not used by Codeware |
| ResetPersistentState(const PersistentID&, bool) | +0x1D8 | 0x102D0F0F4 | x1 is hashed by 0x1016F23D0, then looked up in the map at +0x48 by 0x102D06D64. w2 = x21 |
| RemoveDynamicEntityState(u32) | +0x1F0 | 0x102D133F0 | w1 is hashed mod the bucket count at +0x1F4, in the map at +0x1E0 |
| GetEntityStatus(EntityID) | +0x1F8 | 0x102D138FC | returns 0 if x1 == 0, and 2 (Persisted) if `x1>>24 != 0`. That is the EntityPersistenceStatus enum |
| EnableDynamicEntityPersistence(u32) | +0x200 | 0x102D139F0 | w1, the same map at +0x1E0 |
| DisableDynamicEntityPersistence(u32) | +0x208 | 0x102D13C24 | w1, the same map at +0x1E0 |

## gameEntitySpawnerEventsBroadcasterImpl (vtable 0x107C68A78)

How it was found:
- The implementation class is "gameEntitySpawnerEventsBroadcasterImpl" (0x107614540). It is registered by 0x104743A90.
- Its GetNativeType 0x104743B00 sits at 0x107C68A78, which is slot +0x00.
- The ctor 0x104743C90 calls IGameSystem ctor 0x101AEB288. Then 0x104743CA8-0x104743CB0 does `adrp/add #0xa78; str x8,[x0]`.
- The derived slots run from +0x1B8 to +0x1D8. That is 5 slots, which is the count the SDK declares. The vtable ends at +0x1E0.

RegisterListener is **+0x1B8** (0x104743F20). Its signature is `u32 w0 (x0 this, x1 EntitySpawnerCallback&&, x2 const char*)`, the same as the SDK.
- Gate. It returns 0 unless the byte at this+0x78 is 1 (0x104743F48-0x104743F50 → 0x10474405C).
- Id. The id is `++[this+0x74]` (0x104743F5C-0x104743F68). It is returned in w0 (0x104744078).
- Callback. It moves the 32-byte-buffer Callback: `ldr x8,[x1,#0x20]; str xzr,[x1,#0x20]` loads and clears the handler, then calls `handler+0x10` (move) at 0x104743F78-0x104743F94. This matches Callback.hpp, with `buffer[32]` at +0 and `handler` at +0x20.
- Storage. It appends a 0x30-byte element {callback, u32 id @+0x28} to the DynArray at this+0x48 (0x104743FEC `mov w2,#0x30`). The element's id is stored at 0x104744038. The lock is at +0x70.
- x2 (the name) is never read.

UnregisterListener is **+0x1C0** (0x1047440B0). Its signature is `void (x0 this, w1 id)`.
- It searches the 0x30-byte elements for `[+0x28] == w1` (0x1047440F8, unrolled at 0x104744120-0x104744144).
- It swap-removes the match, destroys the callback through `handler+0x18`, and decrements the count at +0x54.

Codeware calls +0x1B8 (Codeware 0xBEA3C) and +0x1C0 (OnBeforeWorldDetach, Codeware 0xBFBF8). Both are correct. RegisterListener runs, and returns, before the crash.

## IGameSystem base (vtable 0x1078DED90)

- The ctor 0x101AEB288 calls IUpdatableSystem ctor 0x104D74D4C. That ctor stores 0x107CD77E8. The IGameSystem ctor then stores 0x1078DED90 (0x101AEB294-0x101AEB29C).
- The vtable has **55 slots, +0x00..+0x1B0**. +0x1B0 is 0x101AEB36C. The next vtable's two empty header words are at 0x1078DEF48/0x1078DEF50.
- The SDK chain compiled by clang gives the same count:
  - ISerializable: 27 declared slots plus a second dtor slot, so +0x00..+0xD8.
  - IScriptable: +0xE0..+0x108.
  - IUpdatableSystem::OnRegisterUpdates: +0x110.
  - IGameSystem: OnWorldAttached through OnUninitialize, 0x118..0x1B0.
- So the first derived slot is +0x1B8 in the binary and in Codeware's compiled calls. 2.5.0 added **no base virtual**, and nothing shifts.
- D1/D0 sit where the SDK declares `~ISerializable`, at +0x18/+0x20:
  - IGameSystem: 0x101AEB2D4/0x101AEB2D8, both `b 0x104D74D8C`.
  - gamePersistencySystem: 0x102D16648/0x102D1664C.
  - Broadcaster: 0x1047444B8/0x1047444BC.
- Overloads. No virtual name is overloaded anywhere in ISerializable → IScriptable → IUpdatableSystem → IGameSystem → IPersistencySystem / IEntitySpawnerEventsBroadcaster. The `#ifdef __APPLE__` variants of sub_78/sub_B0/sub_C8 are alternatives, not overloads. The MSVC overload-reordering problem (seen on IRTTISystem +0x28/+0x30 and in JournalManager) does not apply to these classes. The slot bodies above confirm the order empirically.
- The SDK slot comments are inconsistent. IGameSystem's OnUninitialize says 1A8, and so does the first derived slot of each interface (both say "1A8"). This is harmless, because the compiler assigns slots. On macOS the first derived slot is 0x1B8.

## Other Codeware game-system calls

None move, because the base did not grow. The risk is a signature mismatch like GetPersistentState: an SDK virtual that models an MSVC hidden return pointer as an explicit `Handle&`/`T&` first argument. Codeware's interface calls on SDK game-system types are listed below. Only the persistency and broadcaster calls were verified in this pass.

| call site | SDK decl | status |
| --- | --- | --- |
| DynamicEntitySystem.cpp:32 GetPersistentState | `void* (Handle&, const PersistentID&, CClass*, bool)` | **broken: sret** |
| DynamicEntitySystem.cpp:29/80 Register/UnregisterListener | as in the SDK | OK, verified |
| OpenWorldSystem.cpp:323, DynamicEntitySystem.cpp:313/346 RemoveDynamicEntityState | `void (u32)` | OK, verified +0x1F0 |
| OpenWorldSystem.cpp:324/334 ResetPersistentState | `void (const PersistentID&, bool)` | OK, verified +0x1D8 |
| IPopulationSystem FindEntity / IsSpawning / RegisterEntity / RemoveEntity | `Handle<Entity> FindEntity(u32)` and others | not checked. It already returns by value, so clang uses x8 sret |
| IEntityStubSystem CreateStub / DeleteStub | returns EntityStubTokenPtr by value | not checked |
| IDynamicEntityIDSystem GetNextTransientID / GetNextPersistableID | returns EntityID (8 bytes, in x0) | not checked |

## Recommended fix (not applied)

The fix is a one-declaration change in `include/RED4ext/Scripting/Natives/gameIPersistencySystem.hpp`. It follows the same pattern as `ISerializable::sub_78` and keeps the slot position:

```cpp
#ifdef __APPLE__
    // arm64: Windows' hidden return slot (arg 1) is x8 here, so the Handle comes back by value.
    virtual Handle<PersistentState> GetPersistentState(const PersistentID& aPersistentID,
                                                       CClass* aPersistentStateType, bool aCreateState) = 0; // 1B8 mac
#else
    virtual void* GetPersistentState(Handle<PersistentState>& aState, const PersistentID& aPersistentID,
                                     CClass* aPersistentStateType, bool aCreateState) = 0;      // 1A8
#endif
```

Change the Codeware call site at DynamicEntitySystem.cpp:32 under `#ifdef __APPLE__` to `m_persistentState = m_persistencySystem->GetPersistentState(SystemPersistentID, m_persistentStateType, true);`.

Alternatively, add a non-virtual inline overload under `__APPLE__` that keeps the Windows-shaped API. It would do `aState = GetPersistentState(id, type, create); return aState.instance;`. A non-virtual overload does not occupy a vtable slot. With it, Codeware is unchanged.

Do not add slot padding. No slot is wrong.
