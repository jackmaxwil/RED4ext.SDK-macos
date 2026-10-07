# re_gamesystem — GameInstance / GetGameSystem chain on macOS (2.3.1 arm64)

All addresses are absolute (image base 0x100000000). This was static analysis only.

## Crash root cause (confirmed)

The ArchiveXL `GetGameSystem<ITransactionSystem>` is at dylib 0x37858. It runs `x8=[engine]; x8=[x8+0x308]; x0=[x8+0x10]; br [[x0]+0x10]`.
- On macOS, `engine+0x308` is **not** the framework. It belongs to BaseGameEngine: the ctor 0x1035F087C stores (at 0x1035F08C4) a heap pointer to a **16-byte** `{ptr, u8}` holder there. That holder wraps a 0x58-byte thread object (helpers 0x103DA5D1C/0x103DA5FD8).
- `[holder+0x10]` reads past that 16-byte block into the next heap block, which starts with a vptr (crash x0 = 0x106FA6C28, a vtable used by 0x101ED041C).
- `[[x0]]` is therefore a code pointer (0x101ED04E8), and `[code+0x10]` returns instruction bytes. That gives PC = 0x9103e108f00286a8. The crash register state matches every step.

## Table

| name | hash | old | new seg:off (absolute) | verdict | arm64 signature vs plugin declaration |
|---|---|---|---|---|---|
| CGameEngine::framework (field) | n/a | +0x308 | **+0x338** | confirmed | `CGameFramework*`. The SDK puts it at 0x308, which is wrong on mac |
| CGameFramework layout | n/a | {?,?,gi@0x10,scene@0x18} | same: vptr@0 (0x10728CD18), +0x08 obj, **+0x10 GameInstance\***, **+0x18 worldRuntimeScene\***, +0x20 | confirmed | size 0x28 matches the SDK |
| GameInstance vtable | n/a | — | 2:0x1D1FA0 (0x106FB1FA0) | confirmed | Itanium: dtors at +0x00 and +0x08 |
| GameInstance::GetSystem | n/a | vt+0x10 | vt+0x10 → 1:0x331543C (0x10331543C) | confirmed | `IScriptable* GetSystem(GameInstance*, const CBaseRTTIType*)`. Returns the raw pointer in **x0**, not via x8. The SDK and ArchiveXL already match |
| GameInstance layout | n/a | map@08, inst@38, impl@48, size 0x138 | map@0x08, inst@0x38, impl@0x48, **size 0x140** | confirmed | the SDK size assert is off by 8 (harmless unless allocated) |
| framework+0x18 runtime scene | n/a | unk18 | correct: `Handle<IRuntimeSystem>[65]` at +0x000, count at +0x410 | confirmed | `GetRuntimeSystem` math is correct |
| ITS::GetItemAppearance | n/a | MSVC 0x1D0 | vt+0x1D8 → 0x103889E20 | confirmed | **mismatch**: mac is `CName (this, IScriptable* owner, ItemID id /*by value x2:x3*/)`. ArchiveXL does not use it |
| ITS::ResetItemAppearance | n/a | MSVC 0x1D8 | vt+0x1E0 → 0x103889EE0 | confirmed | **mismatch**: `void (this, IScriptable* owner, ItemID id /*by value x2:x3*/)`. The SDK passes `const ItemID&` |
| ITS::IsSlotSpawning | n/a | MSVC 0x3C8 | vt+0x3D0 → 0x1038966A8 → 0x103510644 | confirmed | `bool (this, IScriptable*, TweakDBID)` matches |
| ITS::FindSlotData | n/a | MSVC 0x448 | vt+0x450 → 0x103897C14 → 0x103511654 (unlocked) | confirmed | `AttachmentSlotData* (this, IScriptable*, std::function<bool(const AttachmentSlotData&)>*)` matches. The locked twin is at +0x448 |
| ITS::RegisterSlotListener | n/a | MSVC 0x490 | vt+0x498 → 0x10389B34C → 0x103513164 | confirmed | `void (this, IScriptable*, Handle<IAttachmentSlotsListener>* (indirect))` matches |
| ITS::UnregisterSlotListener | n/a | MSVC 0x498 | vt+0x4A0 → 0x10389B3C0 → 0x103513248 | confirmed | matches |
| ITS::MatchVisualTag | n/a | MSVC 0x4D8 | **vt+0x4D8** → 0x10389154C | confirmed | `bool (this, const Handle<ItemObject>&, CName, bool)`. **The SDK+8 puts it at 0x4E0, which is wrong** |
| ITS::MatchVisualTagByItemID | n/a | MSVC 0x4D0 | **vt+0x4E0** → 0x1038919E8 | confirmed | `bool (this, const ItemID&, const Handle<IScriptable>&, CName)`. **The SDK+8 puts it at 0x4D8, which is wrong** |
| scene idx 27 WorldStreaming | n/a | 27 | +0x1B0 | confirmed | — |
| scene idx 35 NodeInstanceRegistry | n/a | 35 | +0x230 | confirmed | FindNode is vt+0x198 with x8 sret, as in WorldNode.hpp |

## Evidence

**CGameEngine::framework = +0x338**
- The CGameEngine vtable is 0x10728D218. Its slot 40 (+0x140) is 0x103F20814, which carries the label "CGameEngine/Initialization/GameFramework" (string ref at 0x103F2148C).
- That slot schedules the job lambda 0x103F23330 (ref at 0x103F20E44). The lambda captures the engine in x22.
- The lambda calls the framework factory 0x103F0A180 at 0x103F233D4. Then: `ldr x21,[x22,#0x338]; str x8,[x22,#0x338]` (0x103F233E0/E4), which swaps a UniquePtr.
- HeadlessGameEngine does the same at 0x103F2834C, but stores at **+0x310** (its RTTI size is 0x318).
- The CGameEngine ctor 0x103F22F3C calls BaseGameEngine ctor 0x1035F087C. It then initialises its own fields from 0x310 to 0x378 and zeroes 0x338.
- RTTI agrees: BaseGameEngine is 0x310 (Windows SDK 0x2F0) and CGameEngine is 0x380.

**CGameFramework layout**
- Factory 0x103F0A180 allocates 0x28 bytes and calls the ctor 0x103F0D2AC through thunk 0x103F0D71C.
- The ctor stores:
  - vptr 0x10728CD18 at +0;
  - a 0x18-byte object at +0x08;
  - `+0x10` = a **0x140-byte GameInstance** (ctor 0x101F2D640);
  - `+0x18` = a **0x4B8-byte worldRuntimeScene** (ctor 0x1033E81BC; RTTI worldRuntimeScene size 1208 = 0x4B8);
  - `+0x20` = 0.
- Its init jobs carry the labels "CGameFramework/GameInstance", "/RuntimeScene" and "/StateMachine" (0x103F0D5C0, 0x103F0D634, 0x103F0D6B0).

**GameInstance**
- Ctor 0x101F2D640: base ctor 0x103313F4C, then vptr 0x106FB1FA0, then zeroes +0x130/+0x138.
- The base ctor initialises a HashMap at +0x08 (with 0xFFFFFFFF at +0x28 and the allocator at +0x30), a DynArray at +0x38 and a HashMap at +0x48.
- GetSystem 0x10331543C:
  - It hashes the type with FNV-1a32.
  - It probes systemMap: indexTable +0x08, size +0x10, capacity +0x14, nodes +0x18, stride +0x24.
  - If that fails, or the type flag `[type+0x70]&1` is set, it maps through systemImplementations (+0x48/+0x50/+0x54/+0x58/+0x64) and probes systemMap again.
  - It returns `[node+0x10]` (Handle.instance) in x0, or 0.
- The game's own call shape is in 0x101F3A8A8, the helper of the "GetTransactionSystem" native 0x101F3A6E0: `x0=[sgi]; x1=GetType<TS>(); blr [vt+0x10]; cbz x0`, then it builds the Handle from x0.
- IGameSystem+0x40 = GameInstance\*: MatchVisualTag 0x1038919E8 does `ldr x23,[x0,#0x40]` and then `[vt+0x10]`. ScriptGameInstance callers read `[system+0x40]`, e.g. 0x103FD1BE8.

**Runtime scene**
- Ctor 0x1033E81BC: count at +0x410, and the destructor walks `[+0x410]` handles of 16 bytes from +0.
- 0x1020B3FAC `ldr x22,[scene,#0x1B0]` sits next to the string "could not get RuntimeSystemWorldStreaming from Runtime Scene" (index 27).
- 0x1020B434C `[scene+0x60]` sits next to "...RuntimeSystemPhysics..." (index 6).
- 0x101F42640 and 0x10369FA68 do `[scene+0x230]`, then vt+0x198 with x8 sret and x1 = node ID. That is the NodeInstanceRegistry FindNode (index 35).

**TransactionSystem vtable 0x1072173A0**
- The vtable ends at +0x4F0; MSVC's last slot is 0x4E8, so the +8 shift holds overall.
- ArchiveXL as built uses 0x3D0, 0x450, 0x498, 0x4A0, 0x4D8, 0x4E0 and 0x1E0. All of these are MSVC+8.
- **Swap.** The script natives were mapped from the name strings:
  - "MatchVisualTag" → native 0x10389AB34 calls **+0x4D8** (0x10389AC2C);
  - "MatchVisualTagByItemID" → native 0x10389AC98 calls **+0x4E0** (0x10389ADA8).
- Function bodies confirm it:
  - 0x10389154C: `[x1]` is a Handle instance, x2 is the tag (used at 0x103891968), w3 is a bool.
  - 0x1038919E8: `[x1]` gets a TweakDBID validity test (`w!=0 && byte4!=0`), x2 is the owner Handle\* (passed to 0x10370D924), x3 is the tag.
- This is the MSVC rule for overloaded virtuals (emitted in reverse declaration order). It does not apply on Itanium.
- **ItemID by value.**
  - In GetItemAppearance 0x103889E20, the lambda captures x2:x3 (vt 0x107217AD0). Its operator 0x1038A0C5C compares them as one 16-byte ItemID against `ItemObject+0x288`, using ItemID== 0x101FAB228.
  - ResetItemAppearance 0x103889EE0 forwards x2:x3.
  - ItemID is 16 bytes, trivially copyable, align 4, so it is passed in two GPRs.
- **FindSlotData** has three neighbours:
  - +0x440 → 0x103511488 is a locked for-each (void).
  - +0x448 → 0x103511500 is the locked find. It takes the reader lock at slots+0x100 and clones the std::function.
  - +0x450 → 0x103511654 is the same find without the lock.
  - Both finds return a slot\* (stride 0x90) or null. The predicate is a libc++ `std::function*`: `__f_` at +0x18, call at `__base` vt+0x30, clone at +0x10/+0x18, destroy at +0x20/+0x28. That is layout-compatible with ArchiveXL's libc++.
- **AttachmentSlotData** (0x90) matches the RTTI: slotID 0, itemObject 8, activeItemID 0x28, prevItemID 0x38, appearanceItemID 0x58. spawningItemID 0x18 comes from IsSlotSpawning 0x103510644.

## Exact fixes

1. **SDK `include/RED4ext/GameEngine.hpp`** (fixes ArchiveXL, TweakXL, `ScriptGameInstance()` default ctor and `ExecuteFunction(CClass*,…)`):
   ```cpp
   struct CGameEngine : BaseGameEngine {
       /* CGameFramework unchanged: unk00 is really the vptr; gameInstance @0x10, unk18 = worldRuntimeScene* */
   #ifdef __APPLE__
       uint8_t unk2F0[0x338 - 0x2F0];   // mac BaseGameEngine is 0x310; +0x308 is a 16-byte thread holder
       CGameFramework* framework;       // 338 - stored at 0x103F233E4 (CGameEngine init job 0x103F23330)
       uint8_t unk340[0x380 - 0x340];   // gameServices position unknown on mac: do not use
   #else
       ... existing fields ...
   #endif
   };
   #ifdef __APPLE__
   RED4EXT_ASSERT_OFFSET(CGameEngine, framework, 0x338);
   #else
   RED4EXT_ASSERT_OFFSET(CGameEngine, framework, 0x308);
   #endif
   ```
   Optional: on Apple, GameInstance size is 0x140 (`unk78[(0x140-0x78)>>3]`).
2. **SDK `Scripting/Natives/gameITransactionSystem.hpp`**, on Apple only:
   - Declare `MatchVisualTag(const Handle<IScriptable>&, CName, bool)` **before** `MatchVisualTagByItemID(const ItemID&, const Handle<IScriptable>&, CName)`, so they land at mac +0x4D8 and +0x4E0.
   - Change `ResetItemAppearance(IScriptable*, ItemID)` and `CName GetItemAppearance(IScriptable*, ItemID)` to take ItemID by value. The latter drops the `CName&` out-param; the CName comes back in x0.
3. Nothing else needs to change: GetSystem slot +0x10, IsSlotSpawning +0x3D0, FindSlotData +0x450, Register/Unregister +0x498/+0x4A0, scene indices 27 and 35, and IGameSystem.gameInstance +0x40 are all correct.

## Dangerous (would crash next)
- With the current SDK, `MatchVisualTag` (IsVisualTagActive 0x38254, ResolveFeetState, IsHighHeels, IsFlatSole) calls ByItemID with x2 = a CName value used as `const Handle&`. That dereferences the hash and causes a SEGV.
- `MatchVisualTagByItemID` (HidesFootwear 0xD7EA4, RollsUpSleeves 0xD7FDC) calls MatchVisualTag with x1 = &ItemID, so `ItemID.tdbid` is used as an `ItemObject*` (`[x0+0x50]`). That causes a SEGV.
- ResetItemAppearance (RefreshItemAppearance 0xD8B70) passes &ItemID in x2. It is a silent no-op or the wrong item, not a crash.
- TweakXL's `lib/Red/Engine/Framework.hpp` and `TypeInfo/Definition.hpp` have the same +0x308 dereference. `SystemBuilder::RegisterSystem` would also write into the thread holder's neighbour.
