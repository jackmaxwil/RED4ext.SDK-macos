# Address port 2.3.1 -> 2.5.0: plugin addresses found by hand

The automatic port (port_2.5.0.md) left 74 entries unmatched that TweakXL, ArchiveXL or MetalFXDenoiser need. Each was
re-identified on 2.5.0 from its 2.3.1 evidence in this folder. The evidence standard was two independent anchors or more:
a mapped caller or callee in the same call position, a unique string, a slot in a matched vtable, or an instruction-level
body match. Every address is a function start in LC_FUNCTION_STARTS, except the data entries. One entry from each batch
was re-checked independently during review.

Held back (unverified): `DRS/Update` (1921175500). The address is 0x10147A864, but MetalFX's hook does not fit it yet.
The function now starts with `ldrb w8,[x0,#0xa0]; tbnz` before `sub sp`, and `State.fixed` moved from +0x38 to +0xA0.

Plugin changes these findings require:

- **TweakXL**
  - `TweakDB_Load` takes a flag in w1 before the path.
  - `TweakDB_TryLoad` takes a fifth bool in w4.
  - The base stat count is 1712 (`StatType::Count`).
- **ArchiveXL**
  - The `InkSpawningContext` given to FinishAsyncSpawn has no vtable, and its request is at +0x10.
  - `worldStreamingSector` fields from +0xA0 moved by +8 (comes with the generated-layout regeneration).
  - CMesh is 0x220 bytes.
- **SDK**: ResourceDepot is 0xF0 bytes, with its lock at +0xE8.


## Batch 1

## batch1 result: TweakXL + MetalFXDenoiser, 2.3.1 (A6656ADC) -> 2.5.0 (7D7382D0)

New segment bases: `__TEXT` 0x100000000, `__DATA_CONST` 0x107758000, `__DATA` 0x107d30000.
Every code address below is in LC_FUNCTION_STARTS.

| hash | name | new address (vmaddr) | DB offset (seg:0xOFF) | FOUND/NOT FOUND | signature same? |
| --- | --- | --- | --- | --- | --- |
| 1299190886 | StatsDataSystem_InitializeRecords | 0x1023B2F68 | 1:0x23B2F68 | FOUND | yes (stat count 1709 -> 1712, see notes) |
| 1444748215 | StatsDataSystem_GetStatRange | 0x1023B3CB0 | 1:0x23B3CB0 | FOUND | yes |
| 1482886888 | TTypedClass_IsEqual | 0x100F611F8 | 1:0xF611F8 | FOUND | yes |
| 2193429752 | JobQueue_ctor_FromParams | 0x104DDEF64 | 1:0x4DDEF64 | FOUND | yes |
| 2621709954 | JobDispatcher_DispatchJob | 0x104DE3088 | 1:0x4DE3088 | FOUND | yes |
| 3123320294 | StatsDataSystem_GetStatFlags | 0x1023B34B4 | 1:0x23B34B4 | FOUND | yes |
| 3512345737 | TweakDB_TryLoad | 0x1037D60CC | 1:0x37D60CC | FOUND | **NO: new 5th arg (w4 bool)** |
| 3523744305 | CClass_sub_C0 | 0x1010C6388 | 1:0x10C6388 | FOUND | yes |
| 3720157672 | CRTTIRegistrator_RTTIAsyncId | 0x108055A60 (data, `__bss`) | 3:0x325A60 | FOUND | n/a (uint32 counter) |
| 565328916 | Memory/MediumHeap/Alloc | 0x10528E764 | 1:0x528E764 | FOUND | yes (body reshaped, see notes) |
| 1391946771 | Upscaler/ScaleTable | 0x1073C2BE0 (`__TEXT,__const`) | 1:0x73C2BE0 | FOUND | n/a (data) |
| 1678240335 | ConfigVar/@bool | 0x107827410 (vptr) | 2:0xCF410 | FOUND | n/a (vtable) |
| 1921175500 | DRS/Update | 0x10147A864 | 1:0x147A864 | FOUND | args yes; **state layout and first instruction changed** |
| 2019025759 | ConfigVar/@float | 0x107838B90 (vptr) | 2:0xE0B90 | FOUND | n/a (vtable) |
| 3407732393 | Memory/MediumHeap/AllocDefault | 0x10528E720 | 1:0x528E720 | FOUND | yes (body reshaped, see notes) |
| 3908306212 | ConfigVar/@int | 0x107829F30 (vptr) | 2:0xD1F30 | FOUND | n/a (vtable) |

Re-check helpers are in `re/b1/`: `fm.py old|new ADDR` (containing function + fmap), `cc.py OLD NEW...` (do mapped old
callers call the candidate), `inter.py new T...` (functions calling every T), `vt.py old|new VT N` (vtable slots),
`seq.py` (word-sequence search), `ncall.py` (caller counts). Disassembly: `xcrun llvm-objdump -d --no-show-raw-insn
--start-address=A --stop-address=B <bin>`.

---

## TweakXL

### StatsDataSystem_GetStatRange / GetStatFlags (and the ported CheckStatFlag as anchor)

- Vtable: the ported CheckStatFlag `0x1023B3438` (1:0x23B3438, "vtable slot") sits in slot `0x107988800`. The old
  vtable `0x107239DF0..0x107239E70` and the new `0x107988780..0x107988800` align slot by slot: every old slot that fmap
  knows maps to the new slot at the same index (e.g. old `0x103A94788`->`0x1023B3D0C`, `0x103A93B40`->`0x1023B3104`,
  `0x103A947D0`->`0x1023B3D54`, `0x103A94410`->`0x1023B39B4`). Old `+e60` GetStatRange / `+e68` GetStatFlags /
  `+e70` CheckStatFlag -> new `0x1079887F0` = `0x1023B3CB0`, `0x1079887F8` = `0x1023B34B4`, `0x107988800` = `0x1023B3438`.
- Bodies identical except the bound: `cmp w1,#0x6ac` -> `cmp w1,#0x6af`; `add x?,x0,#0xfc` (reader lock),
  `ldr x8,[this,#0xe8]`, `umaddl x8,w19,#0xc,x8`, then `ldp s0,s1,[x8]` (Range) / `ldr w0,[x8,#0x8]` (Flags),
  `ldaddalb -1` unlock. Same as 2.3.1 `0x103A9472C` / `0x103A93EF0`.
- Signature unchanged: Range `(x0 this, w1 stat)` -> `{s0,s1}`; Flags `(x0, w1)` -> `w0`. The `cmp/b.hi` before the
  prologue is also unchanged from 2.3.1. Offsets +0xE8 / +0xFC unchanged.

### StatsDataSystem_InitializeRecords `0x1023B2F68`

- Call position: old caller `0x103A951C4` does `bl InitializeRecords (0x103A9532C); bl InitializeParams (0x103A95334)`
  after a loop calling `0x10121F61C`, `0x1021C639C`, then `0x1021C4BEC`, `0x1021C4D44`. Their fmap images
  (`0x101E9A9FC`, `0x1010F0D2C`, `0x1010EF100`, `0x1010EF264`) are all called by exactly one new function, `0x1023B4A88`,
  which does `mov x0,x20; bl 0x1023B2F68; mov x0,x20; bl 0x1023B29A0` at `0x1023B4BEC` (same spot).
- Body: same 0xC0 frame, same CRTTISystem getter thunk (`0x1010B3288`, mapped to old `0x1021885A0`), same type hash
  `0x743066319F27468D` through vt+0x18, array at `+0xD8`, `ldr w8,[x19,#0xe0]`, reserve `mov w1,#count; w2=8; w3=4`.
- Signature unchanged: `void(x0 system)`.
- **Layout/enum change:** the reserve went from `#0x6ad` (1709) to `#0x6b0` (1712); all stat bounds checks are now
  `0x6af`. 2.5.0 has 3 more base stats. The SDK's `game::data::StatType::Count = 1709` (TweakXL's `BaseStatCount`,
  StatService.cpp:9) is stale for 2.5.0, so custom stat ids would collide with the new base stats / Count. Fix needed.
- Bonus (not in batch, NOT added to JSON): InitializeParams is the next call, `0x1023B29A0`.

### TweakDB_TryLoad `0x1037D60CC`

- Strings: "Binary blob not found" (`0x1075D0E3A`, unique) and "Binary blob header is not valid" (`0x1075D0E50`,
  unique) are referenced at `0x1037D62CC` / `0x1037D6320` = +0x200 / +0x254 in `0x1037D60CC` (2.3.1: +0x1F0 / +0x244
  in `0x102B7CC9C`). The two other users of the second string are the fmap images of the other two old users.
- Callers: exactly the ported TweakDB_Load `0x1037CE05C` (1:0x37CE05C), twice (`0x1037CE10C`, `0x1037CE128`), as in
  2.3.1 (`0x102B7561C`, `0x102B75634`). Same prologue shape (frame 0x130 -> 0x140).
- **Signature CHANGED.** 2.3.1: `bool(x0, TweakDB* x1, CString& x2, x3)`. 2.5.0 saves `mov x20,x4` and tests
  `cbz w20` at `0x1037D6280`; TweakDB_Load passes `x4 = <Load's x1>` on the first call and `mov w4,#0` on the second.
  New type: `bool (*)(void* a1, TweakDB*, CString&, void* a4, bool aFlag)`. Returns bool in w0 (callers `tbnz/cbz w0`).
  TweakXL's `Raw::TryLoadTweakDB` (Raws.hpp:15) must add the 5th arg or the hook will forward garbage in w4.
- **Related, outside this batch:** the ported TweakDB_Load is now `(TweakDB* x0, w1 flag, CString& x2)`: engine init
  calls it with `mov w1,#1; add x2,x19,#0x48` (`0x101EF6514`), and the other caller passes the path in x2. TweakXL's
  `Raw::LoadTweakDB` `void(TweakDB*, CString&)` is wrong on 2.5.0.

### JobQueue_ctor_FromParams `0x104DDEF64`

- Callees: old body calls Counter ctor `0x1009D4824` x2, TLS param getter `0x1009E5FBC`, `0x1009D4B04` x2. Their fmap
  images `0x104DDF648`, `0x104DF0D3C`, `0x104DDF930` are called together by 6 new functions: the twins
  `0x104DDEED0`/`0x104DDEF64` (FromParams), `0x104DDEFF8`/`0x104DDF080` (1-byte variant), `0x104DDF108`/`0x104DDF1C4`
  (FromGroup; the ported FromGroup is `0x104DDF1C4`, so the layout of the twin pairs is the same as 2.3.1).
- Body of `0x104DDEF64` = 2.3.1 `0x1009D40C8`: `stp x8,x3,[x0],#0x10`, two Counter ctors, `strb w22,[x19,#0x28]`,
  `strb w20,[x19,#0x29]`, `cmp w20,#0xff` -> TLS param, `str wzr,[+0x2c]`, `strh wzr,[+0x30]`, returns x19.
- Callers: `0x104DDEF64` has 2 BL callers, its twin `0x104DDEED0` has 0. Both old callers (`0x100CE1D68`,
  `0x102150A60`) map (body / prefix) to `0x1019F7DC8` and `0x101075B34`, and both call `0x104DDEF64` (`cc.py`).
- Signature unchanged: `Builder*(x0, w1 prio, w2 param, x3 unk)`; Builder layout (0x38) unchanged.

### JobDispatcher_DispatchJob `0x104DE3088`

- The dispatch wrapper (old `0x1009D46F0` -> fmap `0x104DDF514`, 22 votes) loads the ported JobDispatcher global
  `0x109D0E550` (3:0x1FDE550), moves args exactly as before and ends `b 0x104DE3088` (old `b 0x1009D8690`).
- The ported JobHandle_Join `0x104DDF868` ends with `bl 0x104DE3058` (EmptyJob, mapped from old `0x1009D8660`) then
  `ldr x0,[x21]; mov x1,sp; mov w2,#3; mov x3,x20; mov x4,x19; bl 0x104DE3088`, same as old `0x1009D4AA4`.
- Body: `cbz x4`; `add x0,x4,#0x18; mov w1,#1; bl` atomic inc; `tbz w0`; `add x0,x19,#0x1c; bl`; then tail call to
  the queue routine `0x104DE30F4`. Same as 2.3.1. 2 callers in both builds.
- Signature unchanged: `(Dispatcher* x0, const JobInstance& x1, u8 w2, Counter* x3, Counter* x4)`, void.

### CClass_sub_C0 `0x1010C6388` and TTypedClass_IsEqual `0x100F611F8`

- Vtable slots: taking every vtable whose +0x88 holds the ported CClass_sub_80 `0x1010C5B40` (9072 vtables in 2.5.0, 8958
  in 2.3.1): +0x88 sub_80 and +0xA8 the ported sub_A0 `0x1010C58AC` are uniform (cross-checks the slot map), and
  - +0xC8 = `0x1010C6388` in 9071 of 9072 (2.3.1: `0x10219A254` in 8957 of 8958);
  - +0x50 = `0x100F611F8` in 8351, base `0x1010C28B0` (`mov w0,#0; ret`) in 716 (2.3.1: `0x10093FCAC` in 8241, base
    `0x102196CAC` in 712).
- sub_C0 body = old instruction for instruction: props `@0x28/@0x34`, flag `[prop+0x2a]` bit5, `parent@0x10`,
  `size@0x68`, `parent->vt[+0xc8]`, `this->vt[+0xd0]`, `alignment@0x74 = max(.., 4)`, `holderSize@0x6c`.
  Signature `void(x0 cls)` unchanged; CClass field offsets unchanged.
- IsEqual: `0x100F611F8` is `b 0x1010C3BC8` (as 2.3.1's `b 0x102197FE4`). The body saves x0..x3, calls the prop-cache
  builder with `w1=0`, loops `unk118@0x118` / count `@0x124`, `[prop+0x2a]` bit5, `[prop+0x20]` offset,
  `type->vt[+0x50](type, lhs+off, rhs+off, x3)`, returns 1 only if all equal. Signature
  `bool(cls, lhs, rhs, uint32 a3)` unchanged. The DB entry is the vtable value (the thunk), as on 2.3.1.

### CRTTIRegistrator_RTTIAsyncId `0x108055A60` (3:0x325A60)

- `RTTIRegistrator::GetNextId` is `0x1010AF5DC`: guard `ldaprb [0x108055A68]`, then `mov w9,#1; ldaddal w9,w8,[x8 =
  0x108055A60]; add w0,w8,#1`, the exact words of 2.3.1 `0x102184D9C` (`0x52800029 0xB8E90108 0x11000500`). Of the 7
  functions with that sequence it is the only one with callers in the thousands (15667; 2.3.1 `0x102184D7C`: 33510).
- Its callers store w0 into `GetNativeTypeHash<T>()::nativeTypeHash` GOT slots, e.g. `0x100F61F30` -> GOT `0x1077B1C00`
  = `__ZZ17GetNativeTypeHashIN15FunctionalTests29State_InternalFunctionalTestsEEyvE14nativeTypeHash`.
- Only GetNextId and its init stub `0x1010B0418` (`str wzr,[0x108055A60],#8`) reference the counter, as in 2.3.1.
  It is in `__DATA,__bss`: 0x108055A60 - 0x107D30000 = 0x325A60.

## MetalFXDenoiser

The hashes are FNV1a32 of the names in the plugin source (HeapCache.cpp, ConfigVars.cpp, EngineDrs.cpp):
565328916 = Memory/MediumHeap/Alloc, 3407732393 = Memory/MediumHeap/AllocDefault, 1391946771 = Upscaler/ScaleTable,
1921175500 = DRS/Update, 1678240335 / 3908306212 / 2019025759 = ConfigVar/@bool / @int / @float.

### Memory/MediumHeap/AllocDefault `0x10528E720` and Alloc `0x10528E764`

- Inner TLSF routines map by body: AllocDefault inner 2.3.1 `0x10000A248` -> `0x100009ECC`, Alloc inner `0x10000A2BC`
  -> `0x100009F40`. Each new inner has exactly one caller: `0x10528E74C` (in `0x10528E720`) and `0x10528E798` (in
  `0x10528E764`).
- Callers: 11 of 11 mapped old callers of AllocDefault and 7 of 7 mapped old callers of Alloc call the new candidate
  (`cc.py 0x10000a82c ...`, `cc.py 0x10000a8a8 ...`). 18 BL callers each in 2.5.0.
- Body: `stp` prologue; `bl 0x10000A6C4` (outlined `add x19,x0,#0x80; mov x0,x19; b 0x1000015F0` = writer spinlock,
  same `mov w8,#-0x80 ... casalb` as 2.3.1 `0x1000020C0`); `ldrb w8,[heap,#0x81]` (`tbnz` -> `{0,0}`); inner call with
  `(heap,size)` / `(heap,size,align)`; `bl 0x10000A6E8` (unlock `ldclralb #-0x80,[x19]`); outlined epilogue.
- Signature unchanged: AllocDefault `(x0 heap, x1 size)`, Alloc `(x0 heap, x1 size, x2 align)`, both return
  `{x0 ptr, x1 usable}` (unlock does not touch x0/x1).
- Changes to note: the functions moved out of the heap's code block into `0x10528Exxx`; lock/unlock/epilogue are machine
  outlined, so `scripts/medium_heap.py`'s "first 12 instructions compute x0+0x80 and bl lock" check needs an update for
  2.5.0. The 2.3.1 thread-local "in allocator" byte store (`blr` TLV getter, `strb #1`) is gone. The plugin hooks the
  entry; the first instructions are plain `stp`, fine for a trampoline.

### Upscaler/ScaleTable `0x1073C2BE0` (1:0x73C2BE0)

- `scripts/upscaler_scale_table.py --binary <2.5.0>`: the 16 bytes `(1.5, 1.7, 2.0, 3.0)` occur once in `__TEXT,__const`, at
  `0x1073C2BE0`, with 6 ADRP+ADD refs (2.3.1: 6 refs too).
- The refs sit at the same function offsets as in 2.3.1 (+0x10, +0x50, +0x10, +0x44/+0x48, +0x10, +0x50/+0x5c). The first
  reader `0x10121BC78` is the same lookup as `0x100E4D824` (`sub w8,w0,#1; cmp w8,#3; b.hi; adrp/add; ldr s0,[x9,w8,..#2]`),
  and the next function uses the same 64-bit hash `0xACAA3F2A9837A719` in both builds.

### ConfigVar/@bool `0x107827410`, @int `0x107829F30`, @float `0x107838B90`

- `scripts/config_var_dump.py --binary <2.5.0>` finds the CConfigVar ctor `0x104F20D94` by its exact body (layout
  name +8, group +0x10, flags +0x28 unchanged) and 1403 variables; type by default values: float `0x107838B90` (637),
  bool `0x107827410` (461), int `0x107829F30` (247). 946 variables pass the +0x2C == default(+0x38) store check.
- Name bijection: across both builds, every variable with the same group/name maps old vtable -> new vtable with no
  conflicts: float 614, bool 433, int 242 (also the two non-value types 51 / 7).
- Vtable slots: each old vtable's fmap-known slots land on the new vtable at the same index (bool +0x10/+0x20/+0x30 ->
  `0x100FF6CF0/6DCC/6E98`; int 8 of 8; float 7 of 8). The new bool getter/setter use `[obj,#0x29]` (`0x100FF6D20`,
  `0x100FF6E00`) and +0x2C for the default, as the plugin expects.
- The DB value is the vptr stored in the object (vtable + 0x10), as on 2.3.1 (`0x106E9E828`).

### DRS/Update `0x10147A864`

- Config vars (from the 2.5.0 dump): DRS/Enable `0x109D1FB08`, DRS/Freeze `0x109D1FB38`, DRS/StepSize `0x109D1FCC8`.
  The one non-initializer function that reads all three is `0x10147A864`: `ldrb [Enable,#0x29]` at +0x70 (2.3.1 also
  +0x70), `ldrb [Freeze,#0x29]` at +0x518, `ldr [StepSize,#0x2c]` at +0x640.
- It loads the ported, verified Renderer/Global `0x109D231F0` (3:0x1FF31F0) and calls `renderer->vt[+0x410]` (2.3.1:
  `0x109003068`, vt+0x3A8), with the same arithmetic as 2.3.1 `0x1010CD188`: `mov x20,x3; mov x19,x0; lsr x8,x2,#32;
  lsr x9,x1,#32; sub w10,w2,w1; sub ..; stp w10,w22,[x0,#0x20]; ldr d0,[x0]; str d0,[x0,#8]`. One caller in each build.
- Signature unchanged: `void(State* x0, u64 x1, u64 x2, ctx x3)`.
- **Changes the plugin must handle (EngineDrs.cpp):**
  1. The first instruction is now `ldrb w8,[x0,#0xa0]` followed by `tbnz w8,#0,<ret>` before the `sub sp,sp,#0x80`. The
     plugin's `0xD10203FF` first-word check will refuse to hook (fails closed). The trampoline must relocate a `tbnz`.
  2. The State grew: +0x00..+0x34 is the same (w,h,prev,max/min,out,window,skip,sum@+0x30,count@+0x34). New float history
     at +0x38..+0x94, counters at +0x98/+0x9C, and the `fixed` byte moved **+0x38 -> +0xA0** (both early-exit to `ret`).
     The plugin's `static_assert(offsetof(State, fixed) == 0x38)` must change.
  3. The ctx field read moved `[x3,#0x98]` -> `[x3,#0xf8]` (not used by the plugin).
  4. New DRS config vars exist in 2.5.0 (AdaptToCpuTime, TargetTimeScale, FixedTargetFrameTime, ...).

---

## Summary

- 16 entries, 16 FOUND, 0 NOT FOUND (CBaseFunction_ExecuteScripted / InternalExecute were skipped as instructed).
- **Signature change: TweakDB_TryLoad** gains a 5th arg (w4 bool). TweakXL `Raw::TryLoadTweakDB` must become
  `bool(void*, TweakDB*, CString&, void*, bool)`. Also, outside the batch, the ported TweakDB_Load is now `(TweakDB*, w1 flag, CString& x2)`.
- **Enum change:** 2.5.0 has 1712 base stats (bounds `0x6af`), not 1709. TweakXL's `BaseStatCount` (SDK `StatType::Count = 1709`) is stale.
- **DRS/Update:** the address is right, but the entry now starts with `ldrb [x0,#0xa0]; tbnz`, and State.fixed moved +0x38 -> +0xA0.
  EngineDrs.cpp's prologue check and static_assert must change before hooking. MediumHeap Alloc/AllocDefault moved and are outlined, and `medium_heap.py` verification needs an update. Signatures are unchanged.
- No other layout changes: StatsDataSystem +0xD8/+0xE8/+0xFC, Builder 0x38, CClass fields and CConfigVar +8/+0x10/+0x29/+0x2C are unchanged.

## Batch 2

## Batch 2 result: ArchiveXL appearance, garment, character customization, attachment (2.3.1 -> 2.5.0)

| hash | name | new address (vmaddr) | DB offset (seg:0xOFF) | FOUND/NOT FOUND | signature same? |
|---|---|---|---|---|---|
| 36838056 | EntityTemplate_FindAppearance | 0x1019C4808 | 1:0x19C4808 | FOUND | yes |
| 39206067 | AppearanceDefinition_ExtractPartComponents | 0x1017D3158 | 1:0x17D3158 | FOUND | yes |
| 56573295 | CharacterCustomizationState_GetBodyAppearances2 | 0x104BBF9B8 | 1:0x4BBF9B8 | FOUND | yes |
| 63057648 | AppearanceChanger_GetSuffixes | 0x10201DCC8 | 1:0x201DCC8 | FOUND | yes |
| 110771572 | CharacterCustomizationState_GetArmsAppearances1 | 0x104BBFC78 | 1:0x4BBFC78 | FOUND | yes |
| 386815609 | AppearanceChangeSystem_ChangeAppearance2 | 0x101A5C6E0 | 1:0x1A5C6E0 | FOUND | yes |
| 437791594 | EntityBuilder_ScheduleExtractComponentsJob | 0x1019B3E70 | 1:0x19B3E70 | FOUND | yes |
| 549398675 | AppearanceResource_FindAppearanceDefinition | 0x1017DD6C0 | 1:0x17DD6C0 | FOUND | yes |
| 735526026 | AppearanceChangeSystem_ChangeAppearance1 | 0x101A59E30 | 1:0x1A59E30 | FOUND | yes |
| 809178766 | GarmentAssembler_ExtractComponentsJob | 0x1017EE098 | 1:0x17EE098 | FOUND | yes |
| 1092645213 | CharacterCustomizationSystem_InitializeAppOption | 0x104BD3F5C | 1:0x4BD3F5C | FOUND | yes |
| 1283201918 | AttachmentSlots_IsSlotSpawning | 0x101E0DADC | 1:0x1E0DADC | FOUND | yes |
| 1663588463 | GarmentAssembler_ProcessSkinnedMesh | 0x1017EB4AC | 1:0x17EB4AC | FOUND | yes |
| 1833321597 | GarmentAssembler_ChangeItem | 0x10200857C | 1:0x200857C | FOUND | yes |
| 1863723270 | GarmentAssembler_RemoveItem | 0x102008310 | 1:0x2008310 | FOUND | yes |
| 2229107513 | CharacterCustomizationSystem_InitializeSwitcherOption | 0x104BD53AC | 1:0x4BD53AC | FOUND | yes |
| 2294423397 | GarmentAssemblerState_AddItem | 0x102007DCC | 1:0x2007DCC | FOUND | yes |
| 2594581880 | GarmentAssembler_FindState | 0x102007BC4 | 1:0x2007BC4 | FOUND | yes |
| 3128897273 | GarmentAssemblerState_AddCustomItem | 0x102007EBC | 1:0x2007EBC | FOUND | yes |
| 3141736993 | AppearanceResource_PostLoad | 0x1017DF10C | 1:0x17DF10C | FOUND | yes |
| 3243419919 | AppearanceChanger_ComputePlayerGarment | 0x102020A80 | 1:0x2020A80 | FOUND | yes |
| 3659799256 | ItemFactoryRequest_LoadAppearance | 0x1020133F4 | 1:0x20133F4 | FOUND | yes |
| 3766105236 | CharacterCustomizationState_GetHeadAppearances2 | 0x104BBF438 | 1:0x4BBF438 | FOUND | yes |
| 3776734053 | CharacterCustomizationSystem_InitializeMorphOption | 0x104BD448C | 1:0x4BD448C | FOUND | yes |
| 3778698806 | GarmentAssembler_ChangeCustomItem | 0x10200882C | 1:0x200882C | FOUND | yes |
| 4014159024 | CharacterCustomizationState_GetBodyAppearances1 | 0x104BBF6F8 | 1:0x4BBF6F8 | FOUND | yes |
| 4051123539 | CharacterCustomizationState_GetHeadAppearances1 | 0x104BBF004 | 1:0x4BBF004 | FOUND | yes |
| 4059182261 | CharacterCustomizationState_GetArmsAppearances2 | 0x104BBFF38 | 1:0x4BBFF38 | FOUND | yes |
| 4231927464 | AttachmentSlots_IsSlotEmpty | 0x101E0D97C | 1:0x1E0D97C | FOUND | yes |

"signature same?" compares the 2.5.0 function with the verified 2.3.1 one (argument registers, x8 sret, w0/x0 return). All 29 are unchanged from 2.3.1. The macOS ABI differences from the Windows declarations that `docs/re/appearance.md`, `pass2.md` and `charcustom.md` already list for 2.3.1 still apply unchanged (sret in x8 for FindAppearanceDefinition, GetSuffixes, FindState, ExtractPartComponents; ChangeAppearance2 passes ranges as 4 raw pointers; ScheduleExtractComponentsJob is `(EntityBuilder*, JobQueue&)`; Get*Appearances return bool; Initialize{App,Morph}Option take a red::Map; ExtractComponentsJob params hold a token SharedPtr).

Every address is in LC_FUNCTION_STARTS and none starts with a PC-relative instruction (checked from the `__text` words). Segment 1 (`__TEXT`) for all; offset = vmaddr - 0x100000000.

Re-check helpers: `re/b2/h.py` (loads both images through `scripts/port_addresses.py`, the fmap, call graph, data refs, code pointers; first run builds `re/b2/cache.pkl`), `re/b2/dis.sh old|new ADDR` (disassembles one function), `re/b2/hookglob.py`. `h.cmp(old, new)` prints the BL target sequences of both functions with old callees translated through fmap; "mapped-seq ratio 1.00" means every mapped callee sits in the same order.

## Garment aggregator (game::GarmentItemAggregator)

Structural change in 2.5.0: every tracker-level op is now an out-of-line 0x38-byte wrapper `state = FindState(aggr, x1) /*x8 = sp+8*/; return StateOp(&state, x2)`. In 2.3.1 the ChangeItem/ChangeCustomItem/RemoveItem state ops were inlined into their wrappers; in 2.5.0 they are separate functions (0x1020085B4, 0x102008864, 0x102008348). The four wrappers are masked-identical; they differ only in their BL targets, which is how they are told apart below.

**GarmentAssembler_FindState 0x102007BC4** (old 0x1036F8030)
- Old callers 0x1036F8528 and 0x1036F85B0 map (fmap) to 0x1020080F4 and 0x10200817C; each calls exactly one unmapped function, 0x102007BC4, in the same spot.
- Its callee 0x102006DF4 is fmap(old callee 0x1036F7238, the owner lookup). 8 callers in both builds (all op wrappers).
- Body unchanged: `mov x19,x8` (sret), locks the WeakHandle in x1 (entity status `+0x156 == 4` / `+0x15C` bit 3), owner array `[x0+8]`, count `[x0+0x14]`, stride 0x60, writes `{entry+0x10, entry+0x20, entry+0x50}` (0x18 bytes) to `[x8]`.
- New in 2.5.0: a call through the global `0x109CC59A0` (`vt+0xE0`, see Observations) before the store.

**GarmentAssemblerState_AddItem 0x102007DCC** (old 0x1036F8208)
- Only caller is the wrapper 0x102007B64, called from 0x102014884 = fmap(old 0x10370485C, the old caller of the old AddItem wrapper 0x1036F7FF8).
- Body is the same as old: `ldr x2,[x1,#0x10]; ldp w3,w4,[x1,#0x18]; bl 0x102008DCC` (addPart), then `ldr w3,[x1,#0x1C]; bl 0x10200938C` (addOverrides), `and w0,w19,w20`.

**GarmentAssemblerState_AddCustomItem 0x102007EBC** (old 0x1036F82F4)
- Only caller is the wrapper 0x102007E84 (also called from 0x102014884).
- It reads `hash @0x20` (`ldr x2,[x20,#0x20]`) and calls addPart 0x102008DCC, then the custom overrides 0x102009678 instead of 0x10200938C. That matches the old AddItem/AddCustomItem split (0x1036F9358 vs 0x1036F96AC).

**GarmentAssembler_RemoveItem 0x102008310** (old 0x1036F8744)
- Its callers 0x102010854 and 0x102014C3C are fmap(old callers 0x103700904 and 0x103704BF4). Each calls 0x102008310 in the slot where the old function called RemoveItem.
- Wrapper `(aggr x0, WeakHandle& x1, req& x2)`: `bl 0x102007BC4` (FindState), then `bl 0x102008348`. The state op reads `[x1]` (hash) and `[x1+8]` (index), the same `{u64 hash, u32 index}` request.

**GarmentAssembler_ChangeItem 0x10200857C / ChangeCustomItem 0x10200882C** (old 0x1036F87E4 / 0x1036F890C)
- The old caller 0x1036FDDD4 (unmapped) matches the new 0x10200DD68: both have 19 BLs, and the 14 mapped ones sit in identical order (`h.cmp(0x1036fddd4, 0x10200dd68)`, ratio 1.00).
- Position 2 is old 0x1036F87E4 and new 0x10200857C. Position 11 is old 0x1036F890C and new 0x10200882C.
- 0x10200857C → state op 0x1020085B4: `ldr x21,[x1,#0x10]` (hash), `ldr w4,[x1,#0x18]` (index), and later calls 0x10200938C (the AddItem overrides).
- 0x10200882C → 0x102008864: `ldr x21,[x1,#0x20]`, `ldr w4,[x1,#0x28]`, and later calls 0x102009678 (the custom overrides). These are the same offsets as the 2.3.1 inlined code.
- Hook the wrappers, as on 2.3.1. Signature `bool(aggr x0, WeakHandle<Entity>& x1, req& x2)`.

## Item factory requests

**ItemFactoryRequest_LoadAppearance 0x1020133F4** (old 0x1037034A4)
- fmap already had it (callee set). It was rejected only for one stray vote from neighbor 0x102012F50 (= old 0x103703034).
- Only caller 0x102012984 = fmap(old caller 0x103702A7C).
- 45 BLs in both. The 39 mapped ones are identical in order (ratio 1.00), and the 3 calls to EntityTemplate_FindAppearance sit at the same positions.
- Request offsets are unchanged: `+0x18`, `+0x138` (template token), `+0x158` (name), `+0x160` (record), `+0x148`.
- New: an entry call through `0x109CC59A0` (`vt+0x118`, x1 = req).

**EntityTemplate_FindAppearance 0x1019C4808** (old 0x100CB12BC)
- It is the callee in all 3 positions above. 4 of its 5 callers are fmap of the 5 old callers (0x100B58708, 0x100CA2378, 0x1036FCE14, 0x1037034A4).
- Its two callees 0x10161A1AC/0x10161A168 are fmap(old 0x10174762C/0x1017475E8), the random pick for "random".
- Same EntityTemplate layout: `ldr w8,[x19,#0x5C]` (count), `[x19,#0x50]` (appearances), stride 0x18, `[x19,#0x60]` (defaultAppearance). It compares x1 with the "default"/"random"/third CName globals at 0x109CC2620/628/630.
- Returns the entry pointer in x0.
- New: if `[0x109CC59A0]` is non-null, it returns `obj->vt[0x120](obj, tmpl, &name)` instead of searching.

## Appearance resource / definition

**AppearanceResource_FindAppearanceDefinition 0x1017DD6C0** (old 0x100AD7048)
- 5 mapped old callers (0x100CA2518, 0x100CB9CC0, 0x1036FF3F8, 0x1037038E8, 0x103732C68) each call it in the same position (`h.votes`).
- Same body: `mov x20,x8` (sret), `add x19,x0,#0xF0` + reader lock (0x1000015C8 = fmap(0x100002098)), alt-appearance map `+0x60/+0x78/+0x84` when w3, censorship `+0xA8/+0xB4` when w2, appearances `+0x98/+0xA4`.
- Args `x0 = res, x1 = CName, w2, w3`. 9 callers (8 in 2.3.1).

**AppearanceResource_PostLoad 0x1017DF10C** (old 0x100AD88A8)
- Slot 6 (`+0x30`) of the new AppearanceResource vtable 0x107895738.
- That vtable is identified by its 4 class-specific slots 18/19/20/31 = fmap(old 0x100AD8A24/8F58/90EC/A5CC), the only vtable they all sit in, plus 28 more mapped base slots at identical indices out of the first 40.
- Body is the same as old: calls the base PostLoad 0x1010B0854 (= fmap(0x102185F28)), and if `[x19+0xA4]==0` allocates `0x1D8` and appends to `+0x98`. The AppearanceDefinition size is unchanged at 0x1D8.
- New: an entry call through `0x109CC59A0` (`vt+0xC8`).

**AppearanceDefinition_ExtractPartComponents 0x1017D3158** (old 0x100ACCA30)
- The old caller, the parts job 0x100AD043C, matches the new 0x1017D6888 (46 of 47 mapped callees; 107 vs 108 BLs, 83 mapped in identical order, ratio 0.99).
- The old job calls ExtractPartComponents at BL index 25 and 54. The new job calls 0x1017D3158 at 26 and 55 (one extra mapped call was inserted before it).
- 0x1017D3158: 38 BLs, all 28 mapped in identical order (ratio 1.00), size 0x410 vs 0x40C.
- `mov x19,x8` (sret), `ldr x0,[x0]` (token), then IsFailed (0x1010EF100 = fmap(0x1021C4BEC)), then ObjectPackageExtractor (0x1010763F0 = fmap(0x102151414)), and 0x101076170 = fmap(0x10215118C) with x8 = out.

## Garment processing jobs

**GarmentAssembler_ExtractComponentsJob 0x1017EE098** (old 0x100AE6348)
- The label "ExtractGarmentComponent" (0x10750DC03) is referenced only by the guard init 0x1017EF13C, whose only caller is 0x1017EE098. In 2.3.1 the label was referenced inside 0x100AE6348.
- It is ADRP-referenced only by the ProcessGarment core 0x1017EC094 (the only callee of ProcessGarment 0x1017EBFF0 = fmap(0x100AE4004)).
- That core references 5 lambdas. 4 of them are fmap of the old core's lambda refs (0x100AE5C9C, 0x100AE5DB4, 0x100AE6194, 0x100AE73E4); the fifth is 0x1017EE098, matching the old 0x100AE6348.
- 23 mapped BLs in order (ratio 0.98). Params layout is unchanged: `[x1+0x20]`, `[x0]` token (IsFailed, Fetch, IsA EntityTemplate), `+0x2A8`, `[x19+0x20/0x28]`, `+0x30`, `+0x35`. The token-SharedPtr caveat from appearance.md still applies.

**GarmentAssembler_ProcessSkinnedMesh 0x1017EB4AC** (old 0x100AE3840)
- Mapped old caller 0x100AE5C9C → 0x1017EDA2C calls it at the same index (14 BLs, 12 mapped, ratio 1.00).
- Second caller lambda 0x1017EEE74 passes `(cap[0], w cap[0x40], cap+0x10, +0x20, +0x30, x1 jobgroup)`, exactly like the old lambda 0x100AE72EC.
- 25 BLs, all 21 mapped in identical order (ratio 1.00). Args x0..x5 (`mov x19,x5; mov x20,x4; mov x4,x3; mov x21,x2; mov x24,x1; mov x22,x0`).
- It is distinct from ProcessMorphedMesh, which the porter mapped to 0x1017EBC80.

**EntityBuilder_ScheduleExtractComponentsJob 0x1019B3E70** (old 0x100CA08A0)
- The label "EntityBuilder_ExtractComponents" (0x107516522) is referenced only by the guard init 0x1019B882C, called only from 0x1019B3E70. In 2.3.1 it was referenced inside 0x100CA08A0.
- Its only caller 0x1019B33D8 matches the old caller 0x100C9FDE4: 18 mapped BLs in order (ratio 0.95), and the call sits at BL index 20 in both.
- 0x1019B33D8 is itself called by 0x101A5FBBC = fmap(0x100D49670), the old caller of 0x100C9FDE4.
- Body is the same: WeakPtr lock on `[x0+8]` (`ldapr`/`casal`), x1 = JobQueue&, then the dispatch/SyncWait pair 0x104DDF514/0x104DDF354 = fmap(0x1009D46F0/0x1009D451C).

## Appearance change

**AppearanceChangeSystem_ChangeAppearance1 0x101A59E30** (old 0x100D43218)
- 9 caller votes from mapped callers (CharacterCustomization UI etc.).
- The label "Entity/QueueAppearanceChange" (0x1075197A9) is referenced only by the guard init 0x101A61080, whose only caller is 0x101A59E30.
- Same entry: `[x1+8]` WeakHandle `ldapr`, `ldp q0,q1,[x22,#0x10]` + `ldur w8,[x22,#0x2F]`, x2 callback (`[x23+0x18]`), x3.

**AppearanceChangeSystem_ChangeAppearance2 0x101A5C6E0** (old 0x100D45FD0)
- 15 caller votes. 20 callers in both builds.
- It ends by calling 0x101A5CE5C, the only caller of the guard init 0x101A61208 for "Entity/QueueAppearanceChanges" (2.3.1: 0x100D46770). It sits in the same position in a mapped BL list of identical order.
- Same 8 args: `mov x21,x5; x22,x4; x24,x3; x25,x2; x23,x1; x19,x0; str w7; str x6`, plus the 0x68-byte request.

**AppearanceChanger_GetSuffixes 0x10201DCC8** (old 0x10370D924)
- 8 caller votes. 18 callers in both builds.
- The strings "AppearanceDefinitions"/"SuffixSeparator" are referenced by exactly 3 functions in each build. Among them, old 0x10370E4B8 maps to new 0x10201E230, and old 0x10370D924 matches the new 0x10201DCC8.
- Same entry: `mov x19,x3; mov x20,x1; mov x21,x0; mov x22,x8` (sret), `ldr x23,[x2]`, `add x0,x23,#0x318`.
- Size 0x568 vs 0xB94, because the GetSuffixValue logic is out of line again in 2.5.0 (see Observations).

**AppearanceChanger_ComputePlayerGarment 0x102020A80** (old 0x103710560)
- Only caller, the job lambda 0x102020DEC = fmap(old 0x103710968), calls it in the same position. It passes x0..x6 + `ldrb w7,[x19,#0x60]`.
- 21 vs 23 BLs, 14 mapped in order (ratio 0.97), job API callees mapped. Same prologue order `x7..x0`.
- `ldr x25,[x3]`, then `+0x10/+0x20/+0x40/+0x30` (GarmentProcessingContext offsets unchanged).

## Attachment slots (TransactionSystem)

The TransactionSystem vtable is 0x1072173A0 in 2.3.1 and 0x107965BE0 in 2.5.0 (87 mapped slots agree). **A new virtual was inserted near +0x330: every old slot ≥ +0x338 is now +8** (every uniquely-mapped slot agrees).

**AttachmentSlots_IsSlotEmpty 0x101E0D97C** (old 0x1035104E4)
- Its only caller is 0x1021ADB74 (TS slot +0x3D0, old +0x3C8 → 0x103896458).
- Both wrappers call 0x10219F9DC = fmap(0x103887F7C), then the target.
- The body matches the old one instruction for instruction: lock `+0x100` (0x1000015C8), slots `+0xB0`/count `+0xBC`, stride 0x90, 40-bit TweakDBID compare, `[x10+8]` itemObject, `bl 0x101712AF4` (= fmap(0x101FAB1B4), IsValid), then `eor w0,w0,#1`.

**AttachmentSlots_IsSlotSpawning 0x101E0DADC** (old 0x103510644)
- Its only caller is 0x1021ADD94 (TS slot +0x3D8, old +0x3D0).
- Same body without the `eor`, so it returns `IsValid(spawningItemID)`.
- The neighbor layout is identical to 2.3.1 (sizes 0xC4/0x9C/0xC0/0x70/0xE4, uncalled twins between them). The old "likely" naming caveat from appearance.md still applies.

## Character customization

**State vtable**: 0x10702CD58 (2.3.1) → 0x107CB57E8 (2.5.0). Same indices: the class-specific slots 34–42, 47–50, 57, 64, 65 all map into this vtable only. Slot → function:

| slot | 2.3.1 | 2.5.0 | name |
|---|---|---|---|
| +0x198 | 0x102451620 | 0x104BBF004 | GetHeadAppearances1 |
| +0x1A0 | 0x102451AFC | 0x104BBF6F8 | GetBodyAppearances1 |
| +0x1A8 | 0x102451F2C | 0x104BBFC78 | GetArmsAppearances1 |
| +0x1B0 | 0x1024518E4 | 0x104BBF438 | GetHeadAppearances2 |
| +0x1B8 | 0x102451D14 | 0x104BBF9B8 | GetBodyAppearances2 |
| +0x1C0 | 0x102452144 | 0x104BBFF38 | GetArmsAppearances2 |

- Each is referenced only by its vtable slot and has no BL callers, as in 2.3.1.
- Bodies: `(x0 this, x1 CName, w2 fpp, x3 DynArray*)`, lock `+0x40`, remap `+0xA0/+0xAC` (stride 0x18), group array Head `+0x70/+0x7C`, Body `+0x80/+0x8C`, Arms `+0x90/+0x9C`. They return `w0 = 0/1`.
- Size 0x2C0 vs 0x218, because the loop is unrolled 4x.
- The 1/2 pairs are masked-identical again, so the 1-vs-2 assignment follows the slot order, the same caveat as charcustom.md.

**System vtable**: 0x10702CFB0 → 0x107CB5A40, slots +0x228..+0x248 map 1:1. InitializeOptionsFromFinalizedState (+0x238) = 0x104BCE2C0.
- It calls the per-part dispatcher 0x104BD3540 at the same 3 BL indices (13/24/35) where the old one called 0x1024644AC.
- The second dispatcher caller is 0x104BC5098 = fmap(0x102456C9C).
- The dispatcher has 64 BLs in both builds, and all 55 mapped ones are in identical order (ratio 1.00):

**CharacterCustomizationSystem_InitializeAppOption 0x104BD3F5C** (old 0x102464ED4)
- Dispatcher BL position 4.
- Args `x0..x4` (`mov x23,x3; x20,x2; x21,x1; x19,x0`), the same field-offset multiset (`+0x40` name, `+0x5C` isActive, `+0x128`, `+0x14C`…).
- Its only caller is the dispatcher.

**CharacterCustomizationSystem_InitializeMorphOption 0x104BD448C** (old 0x1024652D8)
- Dispatcher BL position 5, after `opt->vt[0x110]` (GetMorphInfo).
- Args x0..x3. The same red::Map state container sort: flags `+0x20` bit 0, keys `+0`, values `+0x10`, count `+0xC`.

**CharacterCustomizationSystem_InitializeSwitcherOption 0x104BD53AC** (old 0x1024661A0)
- Dispatcher BL positions 29 and 38, plus a recursive self-call, as in 2.3.1.
- 6 args `x0..x5` (`mov x23,x5; x24,x4; x20,x3; x22,x2; x21,x1; x19,x0`).

## Observations (not DB entries)

- **New global `0x109CC59A0`** (`__DATA,__common`) is consulted at the entry of many functions that ArchiveXL hooks: FindState `vt+0xE0`, AddItem wrapper `+0xE8`, LoadAppearance `+0x118`, FindAppearance `+0x120`, ProcessSkinnedMesh `+0x128`, FindAppearanceDefinition `+0x68`, PostLoad `+0xC8`, ChangeAppearance1 `+0x60`, Entity_Reassemble 0x1019A7A30 `+0x138`, RegisterPart 0x1019E7BC0 `+0x108`, CharacterCustomizationSystem_Initialize 0x104BC779C `+0x58`, ScheduleExtractComponentsJob `+0x90`, and others (`re/b2/hookglob.py` lists 52 functions).
  - In FindAppearance a non-null object *replaces* the original search.
  - No direct ADRP+STR writer was found, so its setter and meaning are unknown. A trampoline at the entry runs before it either way, so this does not affect the hooks.
- **GetSuffixValue (hash 1003499294, not in this batch)** is out of line again in 2.5.0: 0x10201E330 references "Full"/"Part"/"TPP"/"FPP" and is called only from GetSuffixes. It is a candidate, not verified here.
- **GarmentAssemblerState_ChangeItem / ChangeCustomItem (3740082313 / 956641309, not in this batch)** now exist as live out-of-line state ops: 0x1020085B4 / 0x102008864, `(state x0, req x1)`. The State RemoveItem op is 0x102008348. These are candidates, not verified here.
- **TransactionSystem vtable**: old slots ≥ +0x338 moved +8. A grep of `cp2077-archive-xl-macos/src` for 0x3C8/0x3D0/0x428/0x448 finds no hard-coded TS offsets. Any SDK or plugin code that calls TS virtuals by a fixed offset in that range needs a review.

## Summary

- 29 entries: 29 FOUND, 0 NOT FOUND. All are in `__TEXT` (seg 1) and in LC_FUNCTION_STARTS, and none starts with a PC-relative instruction.
- Signatures: all 29 are unchanged from 2.3.1. The 2.3.1 macOS-vs-Windows mismatches already documented (sret x8, ChangeAppearance2 register ranges, ScheduleExtractComponentsJob args, bool returns, red::Map containers, token SharedPtr in job params) still apply and need no new plugin change.
- Layout: all field offsets used by these functions are unchanged. This covers ItemFactoryRequest (+0x138/+0x148/+0x158/+0x160), EntityTemplate (+0x50/+0x5C/+0x60), AppearanceResource (+0x98/+0xA4/+0xF0 lock), AppearanceDefinition (0x1D8), the garment request structs, the GarmentProcessingContext (+0x10..+0x40), AttachmentSlots (+0xB0/+0x100, stride 0x90) and the CC state (+0x40/+0x70..+0xAC).
- Structure changes: the garment Change/Remove state ops are now out of line behind 0x38-byte wrappers (hook the wrappers listed above). GetSuffixValue is out of line again. A new interceptor global 0x109CC59A0 is checked at the entry of the hooked functions.
- Plugin action: none for these 29. Note that the TransactionSystem vtable gained a slot (old ≥ +0x338 → +8); ArchiveXL src hard-codes none of those offsets, but any SDK virtual declarations past +0x330 must shift.

## Batch 3

## Batch 3 results: ArchiveXL mesh / resource loader / serializer / depot / package / factory (2.3.1 -> 2.5.0 macOS arm64)

Old = `Cyberpunk2077-2.3.1`, new = `Cyberpunk2077-2.5.0-stock`. Every new address is in LC_FUNCTION_STARTS (checked by `re/mk.py` against `re/fs-new.txt`) and none is the target of any other entry in `fmap.json`. Helpers: `re/d.py old|new ADDR` (disassemble the containing function with ADRP string notes), `re/x.sh old|new call|adrp ADDR` (xref_scan wrapper), `re/vt.py old|new SLOTADDR` (print vtable slots from `re/fx-*.txt`, the `dyld_info -fixups` dumps), `re/f.py` (containing function).

"Signature same?" compares the 2.5.0 arm64 register use with 2.3.1 (the plugin's `__APPLE__` declarations already encode the 2.3.1 macOS ABI, x8 sret included).

| hash | name | new address (vmaddr) | DB offset (seg:0xOFF) | FOUND/NOT FOUND | signature same? |
|---|---|---|---|---|---|
| 503977943 | CMesh_ShouldPreloadAppearances | 0x10519ADA4 | 1:0x519ADA4 | FOUND | yes, `bool(CMesh* x0)` |
| 555290091 | CMesh_AddStubAppearance | 0x10519A844 | 1:0x519A844 | FOUND | yes, `void(CMesh* x0)` |
| 701648326 | CMesh_LoadMaterialsAsync | 0x10519C6DC | 1:0x519C6DC | FOUND | yes, `MeshMaterialsToken(x8; mesh x0, names& x1, u8 w2)` |
| 1185093671 | ResourceSerializer_OnDependenciesReady | 0x1012090B0 | 1:0x12090B0 | FOUND | yes, `void(ctx* x0)` |
| 1419388740 | MeshAppearance_LoadMaterialSetupAsync | 0x1051A3C24 | 1:0x51A3C24 | FOUND | yes, `Handle(x8; app x0, u8 w1)` |
| 1523127443 | MorphTargetMesh_PostLoad | 0x1051CA1A4 | 1:0x51CA1A4 | FOUND | yes, `void(x0, params* x1)` |
| 1632836642 | ObjectPackageReader_OnReadHeader | 0x1019BE410 | 1:0x19BE410 | FOUND | yes, `void(reader x0, u64 x1, stream* x2)` (body byte-for-byte the same) |
| 1886854234 | FactoryIndex_LoadFactoryAsync | 0x1019D50C8 | 1:0x19D50C8 | FOUND | yes, `void(index x0, ResourcePath x1, ctx x2)` |
| 2038372664 | ObjectPackageExtractor_ExtractSync | 0x101075DBC | 1:0x1075DBC | FOUND | yes, `void(extractor* x0)` |
| 2272530537 | CMesh_PostLoad | 0x10519A58C | 1:0x519A58C | FOUND | yes, `void(CMesh* x0, PostLoadParams* x1)` |
| 2450934495 | ResourceDepot_RequestResource | 0x10151A748 | 1:0x151A748 | FOUND | yes, `16B(x8; depot x0, path x1, archiveHandle* x2)` |
| 2517385486 | ResourceDepot_LoadArchives | 0x10151B18C | 1:0x151B18C | FOUND | args the same (x1..x4, w5 exit code; x0 unused); **now also returns w0** (0 ok / 1 early stop), callers ignore it |
| 2577814646 | ResourceSerializer_Load | 0x101207588 | 1:0x1207588 | FOUND | yes, `(this x0, source x1, request& x2, cbctx x3, deferral x4)` |
| 2923109755 | GameApplication_InitResourceDepot | 0x10442D290 | 1:0x442D290 | FOUND | yes, `void(app x0, params x1)` |
| 3007126651 | CMesh_FindAppearance | 0x10519C4B0 | 1:0x519C4B0 | FOUND | yes, `Handle&(CMesh* x0, CName x1)` -> x0 |
| 3362732471 | ResourceLoader_FindTokenFast | 0x1010E7F6C | 1:0x10E7F6C | FOUND | yes, `SharedPtr(x8; loader x0, path x1)` (body the same) |
| 3947570603 | ResourceToken_OnLoaded | 0x1010EF37C | 1:0x10EF37C | FOUND | yes, `JobHandle(x8; token x0, callback* x1)` |
| 4125893577 | DeferredDataBuffer_LoadAsync | 0x101215524 | 1:0x1215524 | FOUND | yes, `16B(x8, JobHandle at +8; buffer x0, int64 x1)` |
| 4142009574 | ResourceToken_CancelUnk38 | 0x104153D5C | 1:0x4153D5C | FOUND | yes, `void(unk38* x0)`; the object's internal fields moved +0x20 |

A new global appears all over this code: `0x109CC59A0`. When it is non-null, the game calls into it as an observer (`vtbl+0x70/0x80/0x98/0xA0/0xA8/0xC0/0xD0`) from FindAppearance, ShouldPreload, CMesh/MorphTargetMesh PostLoad, Serializer Load and OnDependenciesReady. It changes no arguments.

## Evidence

### CMesh_PostLoad -> 0x10519A58C
- "CMesh" string `0x10765CF8C` is used by the class init `0x1051A2230`, which builds the class object at `0x1098E24F0` (`mov w2,#0x220`; 2.3.1 used `#0x230`). `0x10519F9DC` stores it to the class global `0x109D247F8`.
- GetNativeType `0x105197370` (`ldr x0,[0x109D247F8]`) is slot 0 of the vtable at address point `0x107D1D310`. Slot 6 (`0x107D1D340`, +0x30) = `0x10519A58C`. In 2.3.1, slot 6 of `0x106EF0990` was `0x100E16B28`.
- Body: calls base ISerializable::PostLoad `0x1010B0854` (fmap of 2.3.1 `0x102185F28`). It tests `+0x38`, loops over `+0x1E0/+0x1EC` doing `str x19,[app,#0x50]`, calls AddStub `0x10519A844` when the count is 0, tests `+0x60` as a float, and reads `[x1]` and `[x1+8]` of the params. That is the same flow as 2.3.1.
- 2.5.0 calls ShouldPreload out of line from here (`0x10519A6C8`). In 2.3.1 it was inlined, so the ArchiveXL ShouldPreload hook now also fires from PostLoad.

### CMesh_AddStubAppearance -> 0x10519A844
- Its only caller is `0x10519A684` in PostLoad, on the `+0x1EC == 0` branch, the same as 2.3.1 (`0x100E16BF4`, the only caller).
- Body: `mov w0,#0xa8` alloc; MeshAppearance ctor `0x1051A37F0(app, mesh, [0x109D24818] "default" CName)`; append to `+0x1E0` (`bl 0x10519BC44`, the neighbour of fmap `0x100E18174 -> 0x10519BC34`). Instruction for instruction the same as 2.3.1 `0x100E16E68`.

### CMesh_FindAppearance -> 0x10519C4B0
- GetAppearance (fmap 2.3.1 `0x100E199D8 -> 0x10519E118`, "body") calls `bl 0x10519C4B0`. On a null result it tail-calls `b 0x10519C4B0` with the default CName `0x109D24818`. That is the same position and pattern as the 2.3.1 calls to `0x100E189F4`.
- Body: a scan of `+0x1E0` (count `+0x1EC`, stride 0x10) comparing `[h]+0x30` with x1, returning a Handle* in x0, with the empty-handle statics on a miss. It has 4 callers, as in 2.3.1. 2.5.0 adds an observer call only.

### CMesh_ShouldPreloadAppearances -> 0x10519ADA4
- The only reference to "forceLoadAllMeshAppearances" (`0x10765D24A`) is at `0x10519AE08`. The body is the same as 2.3.1: `+0x6D` bit / `+0x1EC==1` gives true; otherwise a hash lookup with magic `0x9A29BCD2` and `mov w3,#0x1b`. The result is passed to an observer `vtbl+0x80` (tail-call) when `0x109CC59A0` is set, otherwise it returns w0.
- Callers: `0x1051A3D40` (in LoadMaterialSetupAsync, the same spot as 2.3.1 `0x100E1F8CC`), `0x1051A4170` (B thunk, as in 2.3.1 `0x100E1FD60`), `0x1051A45B0` (in `0x1051A44EC` = fmap of 2.3.1 `0x100E20070`, as in 2.3.1 `0x100E20138`), and `0x10519A6C8` (PostLoad, see above).

### MeshAppearance_LoadMaterialSetupAsync -> 0x1051A3C24
- Prologue `mov x21,x1; mov x19,x0; mov x20,x8`, the same as 2.3.1. It uses fields `+0xA0/+0x98/+0x9C/+0x48/+0x90/+0x50`.
- The callee sequence is in the same order as 2.3.1, with these mapped callees: `0x104DF0D3C` (`0x1009E5FBC`), `0x1010B0E90` (`0x1021864F8`, 333 votes), `0x104DDF8E8` (`0x1009D4ABC`), ShouldPreload, `0x1010B1280` (`0x1021868D8`, 170 votes), `0x104DDF080` (`0x1009D420C`), then `bl 0x10519C6DC` with `x8=sp+0x68, x0=[x19+0x50], x1=names, x2=prio`.
- It ends at `bl 0x1051A5830`, the descriptor init that references "MeshAppearance/IssueLoadRenderMaterialSetup/ProcessResults" (`0x1051A584C`). It has 30 callers (28 in 2.3.1).

### CMesh_LoadMaterialsAsync -> 0x10519C6DC
- It has two callers: LoadMaterialSetupAsync `0x1051A3DBC` and `0x1051A4600` (inside fmap `0x100E20070 -> 0x1051A44EC`). 2.3.1 had the same two callers.
- Prologue `mov x19,x2 (prio, later str w19,[sp,#0x14]); mov x21,x1 (names, ldr w1,[x21,#0xc]); mov x27,x0; mov x20,x8`.
- It locks `add x0,x27,#0x218` (matching the plugin's `MaterialLock` OffsetPtr<0x218>) and uses `+0xE0/+0xF0/+0x110` as in 2.3.1. It ends with `bl 0x1051A21EC`, the descriptor init of "CMesh/IssueLoadMaterials/OnLoaded" (`0x1051A220C`).
- The body is about twice as large as in 2.3.1 because the token construction is now inlined.

### MorphTargetMesh_PostLoad -> 0x1051CA1A4
- Class init `0x1051CB5F8`: "MorphTargetMesh" `0x10765DFB6`, `mov w2,#0xd0` (size unchanged). It stores class `0x1098ECC80` to global `0x109D249B0` (`0x1051CA9A0`).
- GetNativeType `0x1051C961C` is slot 0 of the vtable at address point `0x107D21AD8`. Slot 5 = `0x1051CA1A0` (`b 0x1010B0850`, the base, as 2.3.1 slot 5 `b 0x102185F24`). Slot 6 = `0x1051CA1A4`.
- The body has the same eight 64-bit CName constants (`0x0D6A8A92ED62461B`, ...), and calls GetAppearance `0x10519E118` and `0x1051A3A60` (fmap of `0x100E1F6A4`) in the 2.3.1 positions.

### ObjectPackageReader_OnReadHeader -> 0x1019BE410
- Reader ctor `0x1019BE2FC` is instruction-identical to 2.3.1 `0x100CAAA10` (`strh #0xffff,[x0,#0x18]`, zeroing up to +0x84). It installs vtable `0x1078C7948`, and slot 2 = `0x1019BE410` (2.3.1 slot 2 = `0x100CAAB24`).
- The body is identical to 2.3.1: `read(x2, sp+0xc, 4)` via `vtbl+0x10`, then CRUID span `stp x0,x9,[x20,#0x20]`, `strh w8,[x20,#0x18]`. ReadHeader `0x1019BE360` (fmap "body" of `0x100CAAA74`) sits right next to it.

### FactoryIndex_LoadFactoryAsync -> 0x1019D50C8
- It is the only function between fmap anchors `0x100CC0530 -> 0x1019D4FC8` and `0x100CC090C -> 0x1019D5264`. 2.3.1 had LoadFactoryAsync in that slot.
- Body: `mov x19,x2; mov x21,x0; str x1,[sp,#0x20]` (path). It calls IssueLoadingRequest `0x1010E710C` (fmap of `0x1021B71CC`), then `0x1010EF62C` (fmap of `0x1021C51B0`), and dispatches a job with `x3 = ctx` (`0x104DDF514`). The descriptor init `0x1019D61A4` references "ParseFile".
- Callers: the "CreateEntryMap" job `0x1019D596C` (it also calls the "CreateEntryMap" descriptor `0x1019D6298`), and a new 2.5.0 caller `0x101CBF6D4`. The new caller loops over a global table and calls it with `(x0, [entry+8], x2)`.
- The stack ResourceRequest it builds grew: archive handle at +0x20 (was +0x18), a byte at +0x19, a zero at +0x28. That does not touch this signature.

### ObjectPackageExtractor_ExtractSync -> 0x101075DBC
- It lies between fmap anchors `0x102150B4C -> 0x101075C20` and `0x10215118C -> 0x101076170`, and its first call is `bl 0x101075C20` (load imports), as in 2.3.1.
- It uses the same field offsets as 2.3.1 `0x102150CE4`: `+0xB9` disableImports, the token loop `+0xD0/+0xDC` with IsFinished `0x1010EF0B4`, `+0x78/+0x68/+0xA8/+0xF0 vtbl+0x30`, `+0x110`, `+0x80`, `+0xB8` disablePostLoad, `+0xBA` -> params, `objects +0xC0/+0xCC -> vtbl+0x30`.
- It has 3 callers (3 in 2.3.1). One small difference: params byte 0 is now written with `strh`, so byte 1 = 0.

### ResourceSerializer_Load -> 0x101207588
- It is slot 2 of the binary loader vtable at address point `0x1078382F8`: `0x101207474, 0x101207478, 0x101207588, 0x10120748C` (`mov w0,#1; ret`). That is the same shape as 2.3.1 `0x1070018B8` (D1, D0, Load, ret 1).
- It calls the ctx ctor `0x101207494` (fmap of `0x102255A50`), copies `[x3]` into ctx+0, moves the deferral x4 (`0x104DE16C0`), source x1 -> ctx+0x1A0, request x2 -> ctx+0x1D0..+0x22A, then `+0x190`, `+0x1B0`, `+0x230`, `+0x250`, and calls the scheduler `0x101207ED4` (2.3.1 `0x10225646C`).
- The request copy now reads `ldur q3,[x2,#0x4a]` (0x5A bytes; 2.3.1 used 0x59), which still fits the 0x60 struct.

### ResourceSerializer_OnDependenciesReady -> 0x1012090B0
- The WaitForDependencies lambda `0x101209038` (fmap "body" of `0x102257548`) is instruction-identical to 2.3.1. It loads `[ctx+0x1E0]` and passes `adr x1 = 0x1012090B0` to the throttler `0x1010EBEE0`; 2.3.1 passed `0x1022575C0`.
- Body: token state `0x104153F10(ctx+0x190, 8)` and `(…,9)`, then `0x10120B670(ctx+0xB0, ctx+0x1D0, &job)`, `+0x23C/+0x230` serializables, and the completion `blr x21(ctx+0x230, ctx+0x10, ctx+0x1D0, ctx+0x20, …)`. These are the 2.3.1 offsets. ResourceSerializerContext is unchanged at request 0x1D0 and serializables 0x230.

### DeferredDataBuffer_LoadAsync -> 0x101215524
- It lies between fmap anchors `0x10226242C -> 0x1012153C0` and `0x102262C58 -> 0x101215B9C`, in the same order as 2.3.1.
- Prologue `mov x21,x1; mov x20,x0; mov x19,x8`, then calls `0x104DF0D3C` and `0x104DDF080` (both fmap callees of the 2.3.1 body). Spin lock `swpalb` on `+0x55`, increment of `+0x50`. The descriptor init `0x101216198` references "DeferredDataBuffer/CreateLoadingJobs".
- The JobHandle is moved into `x19+8` (`add x0,x19,#0x8; bl 0x104DDF698`). It has 13 callers (12 in 2.3.1).

### ResourceLoader_FindTokenFast -> 0x1010E7F6C
- The internal request function `0x1010E7190` (fmap of `0x1021B7250`) takes the shared lock `x0+0x40` and calls `0x1010E7F6C` with `x8=sp+0x10, x0=loader, x1=path`, then `ldaddalb -1` on `+0x40`. That is the 2.3.1 pattern.
- The body is instruction-equivalent to 2.3.1 `0x1021B80F4`: a HashMap at loader+0 with key `hi^lo`, node `+4` hash / `+8` key / `+0x10` WeakPtr, then a lock into a SharedPtr written to `[x8]`. It has 7 callers (7 in 2.3.1).

### ResourceToken_OnLoaded -> 0x1010EF37C
- It is the only function between fmap anchors `0x1021C4D44 -> 0x1010EF264` (+ `0x1010EF26C`) and `0x1021C51B0 -> 0x1010EF62C`.
- The body matches 2.3.1 step by step: weak-self lock at `+8`, `0x104DDF080`, `+0x50` job, callback moved from x1 (`+0x18`, `+0x28` size), alloc 0x40, dispatch `0x104DDF514`, capture into x8 (`0x104DDF3C4`). The token dtor `0x1010EEF3C` sits at the same spots as 2.3.1 `0x1021C4A14`.
- The descriptor init `0x1010F0230` references "ResourceToken/OnLoaded". It has 47 callers (46 in 2.3.1).

### ResourceToken_CancelUnk38 -> 0x104153D5C
- The token dtor `0x1010EEF3C` runs `if (!ldapr[tok+0x58] && !tok[+0x5C]) bl 0x104153D5C([tok+0x38])`. That is the 2.3.1 condition and call site (`0x1021C4A48`); the token offsets are unchanged.
- The body has the same shape as 2.3.1 `0x10418FB00`: `0x10413ACC0(8)` check, `[+0x68] != -1`, cancel byte `+0x76`, then `[+0x18] vtbl+0x30` tail. In 2.3.1 these offsets were `+0x48/+0x56`, so the Unk38 object's fields shifted +0x20.
- Second caller `0x1012160A0` (DeferredDataBuffer area), as 2.3.1 `0x10095EF0C`. 2 callers in both builds.

### ResourceDepot_RequestResource -> 0x10151A748
- CheckResource `0x10151AA2C` (fmap "body" of `0x103ED9E9C`) is slot 4 of the ResourceGameDepot vtable at address point `0x107846F30`, and slot 3 = `0x10151A748`. 2.3.1: `0x10728A630`, slots 3 and 4.
- Prologue `mov x21,x2; mov x22,x1; mov x23,x0; mov x20,x8; stp xzr,xzr,[x20]`, the same as 2.3.1. It walks groups at depot `+0x10/+0x1C` with flags `+0x20`, stride 0x38, and reads `[x2]`, `[x2+8]`.
- New reads: `ldrb w4,[x2,#0x10]` on the archive-handle struct, which the plugin only passes through.
- **Layout:** the depot shared lock moved from `+0x78` to `+0xE8`.

### ResourceDepot_LoadArchives -> 0x10151B18C
- Its callers are the depot enumerators `0x10151ADCC` (4), `0x10151B5A8` (3) and `0x10151BA04` (3); these are the fmaps of 2.3.1 `0x103EDA0C8/0x103EDA684/0x103EDAAE8`, with the same 4/3/3 counts. New: `0x10151B468` (1, called from InitializeArchives `0x10151A118`) and `0x10151BC90` (2).
- The call sites are the same as 2.3.1: `x1=group, x2=&paths, x3=out, w4=memoryResident (1/0), w5=#2`.
- Body: paths stride 0x20 (`add x8,x23,x8,lsl #5`), alloc 0x70 archive (`0x105074BE8` ctor), open with x3, `cmp w19(x4),#1` for the memory-resident path, append a 0x50-byte entry to the group's DynArray (in 2.3.1 this was out of line in `0x103EDAD74`, also 0x50 bytes). The fatal stubs use `ldr w1,[sp,#4]` (w5).
- Change: the function now sets w0. It returns 0 on normal completion and 1 when a path check (`0x105071410`) or an open (`0x105074CF8`) fails. On those failures it stops iterating instead of hitting the fatal path. The game's callers ignore w0.

### GameApplication_InitResourceDepot -> 0x10442D290
- CGameApplication vtable at `0x107C2D6F8`: `…, 0x10442D290, 0x10442D420, 0x10442D4AC`. fmap maps `0x101704318 -> 0x10442D420` and `0x1017043A4 -> 0x10442D4AC` (both "body"), which pins the preceding slot as 2.3.1 `0x101704194`.
- The body matches 2.3.1: `ldr w8,[x1,#0xc0]; cmp #2`, `x1+0xC8` path, alloc, ctor `0x10151A4E0`, swap into `app+0x198`, then setter `0x1010F123C` on `[app+0x198]`.
- **Layout:** ResourceGameDepot is now allocated with `mov w0,#0xf0`; in 2.3.1 it was `0x80`.

## Summary
1. 19/19 FOUND, 0 NOT FOUND. Each has at least two independent anchors (vtable slot or mapped caller/callee plus a unique string or an identical instruction body).
2. No plugin signature change is required. The argument registers and the x0/x8 returns match 2.3.1 for all 19. LoadArchives now also returns a status in w0, which ArchiveXL's `void` declaration ignores safely.
3. Layout changes the SDK must take: ResourceDepot grew 0x80 -> 0xF0 and its lock moved 0x78 -> 0xE8 (`groups` at +0x10 and flags at +0x20 are unchanged), so update `RED4EXT_ASSERT_SIZE/OFFSET(ResourceDepot …)`. CMesh RTTI size went 0x230 -> 0x220 (the old DynArray at +0x220 is gone; +0x1E0, +0x218, +0x60, +0x6D and +0x38 are unchanged), so update `RED4EXT_ASSERT_SIZE(CMesh, 0x230)`.
4. ResourceToken Unk38 internals moved +0x20 (cancel flag 0x56 -> 0x76). Any inline DestructUnk38 replacement in the SDK must use the 2.5.0 holder layout (functor check now at `+0x60`, was `+0x40`). The token's own fields (+0x38/+0x40/+0x50/+0x58/+0x5C) are unchanged.
5. Behaviour notes. CMesh::PostLoad now calls ShouldPreloadAppearances out of line, so ArchiveXL's hook also runs there (as on Windows). The stack-built ResourceRequest grew: the archive handle is at +0x20 instead of +0x18. The serializer request copy grew to 0x5A bytes, still inside 0x60.

## Batch 4

## Batch 4 results (2.3.1 -> 2.5.0, macOS arm64)

| hash | name | new address (vmaddr) | DB offset (seg:0xOFF) | FOUND/NOT FOUND | signature same? |
| --- | --- | --- | --- | --- | --- |
| 118698863 | InkWidgetLibrary_AsyncSpawnFromLocal | 0x104353A7C | 1:0x4353A7C | FOUND | yes `bool(lib x0, info x1, CName x2, bool w3)` |
| 140387944 | MappinSystem_OnStreamingWorldLoaded | 0x1030FB9F0 | 1:0x30FB9F0 | FOUND | yes `(this x0, scene x1, ...)` |
| 772484645 | Localization_LoadSubtitles | 0x101C2B4C8 | 1:0x1C2B4C8 | FOUND | yes (still sret x8, as on 2.3.1) |
| 790570700 | QuestLoader_ProcessPhaseResource | 0x1029E8C48 | 1:0x29E8C48 | FOUND | yes `void(loader x0, path x1, Handle& x2)` |
| 1158555307 | InkWidgetLibrary_SpawnFromLocal | 0x10435402C | 1:0x435402C | FOUND | yes `(lib x0, CName x1) -> x8 sret` (as on 2.3.1) |
| 1231151050 | MappinResource_GetMappinData | 0x1030F2FF0 | 1:0x30F2FF0 | FOUND | yes `void*(resource x0, u32 w1)` |
| 1396063719 | InkWidgetLibrary_AsyncSpawnFromExternal | 0x104353D74 | 1:0x4353D74 | FOUND | yes `bool(lib, info, path x2, CName x3, bool w4)` |
| 1652956141 | CClass_GetProperties | 0x1010C352C | 1:0x10C352C | FOUND | yes `void(cls x0, DynArray<CProperty*>& x1)` |
| 1945256833 | JournalRootFolderEntry_Initialize | 0x105207E14 | 1:0x5207E14 | FOUND | yes `(root x0, handle& x1, JobQueue& x2)` |
| 2547979664 | CClass_AssignDefaultValuesToProperties | 0x1010C3934 | 1:0x10C3934 | FOUND | yes `void(cls x0, instance x1)` |
| 2698985195 | InkSpawner_FinishAsyncSpawn | 0x104368F34 | 1:0x4368F34 | FOUND | regs same `void(ctx x0, Handle& x1)`, **ctx LAYOUT CHANGED** |
| 3428782773 | PointOfInterestMappinResource_GetMappinData | 0x1031138F4 | 1:0x31138F4 | FOUND | yes `void*(resource x0, u32 w1)` |
| 3550098299 | Localization_LoadOnScreens | 0x101C2B6DC | 1:0x1C2B6DC | FOUND | yes (still sret x8, as on 2.3.1) |
| 3972601611 | StreamingSector_PostLoad | 0x101C05360 | 1:0x1C05360 | FOUND | yes `void(sector x0, params x1)`; **sector fields >= 0xA0 moved +8** |
| 4223669659 | Localization_LoadVoiceOvers | 0x103FE6C94 | 1:0x3FE6C94 | FOUND | yes `void(ctx x0, RunContext& x1)` |

All 15 are LC_FUNCTION_STARTS entries in 2.5.0. None starts with a PC-relative instruction.

Re-check helpers live in `re/b4/`. `fn.py old|new ADDR` disassembles the whole function that holds ADDR. `fm.py old|new ADDR` prints the fmap entry for the function that holds ADDR. `vt.py OLDAP NEWAP N` compares vtable slots through fmap. `findvt.py OLDAP N` votes for the new vtable. `rb-old.txt` and `rb-new.txt` hold the rebase fixups.

2.5.0 has a new feature-flag byte at `0x109D03E78`. Several ink library entry points check it inline, and when it is 1 they jump to a new path near `0x104156xxx`. That path splits the item name at `':'` (strchr with 0x3A at `0x10415615C`), which is the same as ArchiveXL's `ControllerSeparator`. So the game now seems to ship its own version of the InkSpawner controller injection, gated by this flag. It does not change the addresses below, but the plugin's InkSpawner extension may be redundant, or may double-apply, when the flag is set.

---

## InkWidgetLibrary_AsyncSpawnFromLocal -> 0x104353A7C
- Mapped caller: old `0x1048D6584` maps to new `0x1042CE8C4` by fmap "body". Old `+0x24` is `B 0x104965980`, and new `+0x24` (`0x1042CE8E8`) is `B 0x104353A7C`. The second mapped caller (`0x1048DB32C` -> `0x1042D36E4`) also tail-calls `0x104353A7C`, at `0x1042D373C`.
- Body: the same item search as 2.3.1. It reads `ldr [x0,#0x40]` / `ldr w,[x0,#0x4C]` with stride `#0x38`, calls the name getter `0x10431E478` (old `0x1049239DC`, fmap), and then calls `0x10431D76C(item, x1, x3)`. It returns `mov w0,#1` or `#0`.
- The extra flag check at entry (`adrp 0x109D03000; add #0xE78; ldrb; cmp #1; b.ne`) is new.
- Twin `0x104353BA8` is the same body without the flag check. It has no BL/B callers, no ADRP refs and no rebase, so it is the dead copy and is not used.

## InkWidgetLibrary_AsyncSpawnFromExternal -> 0x104353D74
- Mapped callers `0x1042CE91C` and `0x1042D390C` tail-call the 0x1C-byte flag thunk `0x104353D58`. That thunk does `ldrb [0x109D03E78]`, branches to `0x1041565B4` if the flag is set, and otherwise does `b 0x104353D74`. The thunk's B is the only reference to `0x104353D74`.
- Body: the prologue is the same as old `0x104965B38`: `mov x19,x4; mov x21,x3; mov x20,x1; mov x8,sp; mov x1,x2; bl 0x104353EDC`. `0x104353EDC` is the external-library resolver, which is old `0x104965C90` by fmap. The function then runs the same item search and `bl 0x10431D76C(item, x20, x19)`.
- I chose the body rather than the thunk because the thunk's first instruction is an ADRP. The memory notes say the hook relocator mishandles PC-relative instructions. Every non-flag call reaches `0x104353D74`.

## InkWidgetLibrary_SpawnFromLocal -> 0x10435402C
- The controller helper `0x1042CE278` (unmapped) does `BL 0x10435402C` at `+0x4C`, which matches old `0x1048D5F80+0x4C` -> `0x104965DE0`. At `+0xC0` it calls the root spawn `0x104354000` (old `0x104965DB4`, fmap "body"). The second helper `0x1042D3070` uses the same pattern.
- Body: the same item search on `+0x40/+0x4C/0x38`. It tail-calls `b 0x10431DC00` (WidgetLibraryItem::Spawn, old `0x104923164` by fmap) with x8 preserved, and zeroes `[x8]` when the item is not found.
- Twin `0x10435413C` has no flag check and is called only from the new flag path `0x104155CF0`. Do not use it.
- The neighbour order is preserved: `0x104354000` is the root spawn (fmap), and the External body `0x10435424C` was already ported.

## InkSpawner_FinishAsyncSpawn -> 0x104368F34  (LAYOUT CHANGE)
- The new async-spawn job `0x104368B58` is the only caller of `0x1042146CC` (old `0x104831224` by fmap, same spawn call; request reads `+0x48/+0x80/+0xA0` unchanged).
- It now stores an ops table on the stack instead of heap-allocating a 0x28-byte context with a vtable: `adrp 0x107E81000; add #0x78; str x8,[sp,#0x70]` at `0x104368CF8`.
- The table at `0x107E81078` has 4 slots: `[0]=0x104368F34` invoke, `[1]=0x1043691D0` copy, `[2]=0x104369214` move, `[3]=0x10436929C` destroy.
- The completion lambda `0x10431EA84` (old `0x1049240C0` by fmap) calls `ldr x8,[table]; blr x8` with `x1=&instance`. On 2.3.1 it called `vtbl[+0x30]`.
- The body of `0x104368F34` matches old `0x1049799B8`. It does `req = [x0+0x10]`, stores the instance at `req+0x90`, the root widget at `req+0x60` (getter `0x10431E470` = old `0x1049239D4`, fmap) and the controller at `req+0x70`, then does `swpalb #3` on `req+0x1AC`. It also has a new flag-gated call to `0x104156130`, the ':' controller path.
- **Plugin fix needed:** x0 is now a 0x20-byte functor storage `{WeakHandle @0x00, SharedPtr<InkSpawningRequest> @0x10}` with no vtable. `Red::InkSpawningContext` (vtable + `request @0x18`) is wrong on 2.5.0, and `aContext.request` would read the refcount pointer. Use `request` at +0x10. The request field offsets (0x48/0x60/0x70/0x90/0x1AC) are unchanged.

## MappinSystem_OnStreamingWorldLoaded -> 0x1030FB9F0
- The new MappinSystem vtable address point is `0x107A9B098`. It was found from mapped slot +0x260 (old `0x1042B2748` maps to new `0x103106D24` by fmap "vtable slot", data `0x107A9B2F8`). `vt.py 0x1072D9888 0x107A9B098 80` shows about 50 slots agreeing through fmap.
- Slot +0x180 (data `0x107A9B218`) is `0x1030FB9F0`. That is the same slot as old `0x1072D9A08` -> `0x1042A71A4`.
- Body: `ldr x0,[x1,#0x1B0]`, then `bl 0x101BFE958` (old `0x10341FDFC`, fmap). It runs two IsA checks (`0x1010C6BF4` = old `0x10219AC60`) and stores handles at `this+0x58` and `this+0x68`, the same offsets as before. The function has no BL callers; it is reached only through the vtable.

## MappinResource_GetMappinData -> 0x1030F2FF0
- Chain: GetMappinPosition `0x103106D24` (mapped vtable slot +0x260) calls `bl 0x1030F7934`. `0x1030F7934` is the new out-of-line MappinSystem lookup: `ldr x0,[x0,#0x58]; bl 0x1030F2FF0`, and if the result is null it uses a new fallback path. The 16-byte stub `0x1030F7920` (`ldr x8,[x0,#0x58]; cbz; b 0x1030F7934`) is called at `0x1031456CC`, which is `+0x288` in `0x103145444`. That matches old `0x1042EF87C+0x288` -> stub `0x1042A3E38`.
- Body: a leaf scan with `ldr x8,[x0,#0x40]`, `ldr w11,[x0,#0x4C]` and stride 0x20 (unrolled ×4). It compares `ldr w,[x8]` with w1 and returns the entry or 0, the same as old `0x10429EED0`.
- It sits between mapped neighbours `0x1030F246C` (old `0x10429E068`) and `0x1030F3BC4` (old `0x10429F888`).
- Behaviour note: on 2.5.0 a null result is no longer final. `0x1030F7934` then tries its own fallback through `[this+0x40]`. Hooking the resource lookup still runs first.

## PointOfInterestMappinResource_GetMappinData -> 0x1031138F4
- Mapped caller `0x1042E6244` -> `0x10313B808`. Both have identical prologues, and at `+0x34` both do `ldr w1,[x0]; mov x0,x2; bl <GetPoiData>`.
- The new GetPoiData is `0x1030F7C40` (`ldr x8,[x0,#0x68]; cbz; b 0x1030F7C54`). `0x1030F7C54` does `ldr x0,[x0,#0x68]; bl 0x1031138F4`. `0x1030F7C70` is the only caller of `0x1031138F4`.
- Body: byte-identical to `0x1030F2FF0` (+0x40/+0x4C, stride 0x20).
- It sits between mapped neighbours `0x103113428` (old `0x1042BDF8C`) and `0x103113BF8` (old `0x1042BE7A0`).
- The sibling stubs `0x1030F7C20` and `0x1030F7C30` match the old multi-data and GPS stubs.

## Localization_LoadSubtitles -> 0x101C2B4C8 / Localization_LoadOnScreens -> 0x101C2B6DC
- Both are 0x1F4-byte twin templates: `stp xzr,xzr,[x8]; cbz x0`, then ResourceLoader `[0x1099DC690]` `->` LoadAsync `0x1010E7060`, then Wait, then IsA against a class global. They differ only in the class global:
  - `0x101C2B558: ldr x1,[0x109CC58C8]`
  - `0x101C2B76C: ldr x1,[0x109CC58E8]`
- `0x109CC58C8` is SubtitleMap. Registration `0x101C2BD90` stores class object `0x10847C2A0` there with `str x20,[x8,#0x8C8]`. Static init `0x101C2E200` builds that object with the string `"localizationPersistenceSubtitleMap"` (`0x10752344A`).
- `0x109CC58E8` is OnScreenEntries. Registration `0x101C2C758` stores `0x10847CDE0`, and static init `0x101C2E488` builds it with `"localizationPersistenceOnScreenEntries"` (`0x107523523`). The CName getters next to each one return these same globals (`0x101C29958`, `0x101C2A420`).
- Mapped caller `0x102F6EF5C` -> `0x101C33724` calls OnScreens: old `bl 0x102F67DB4`, new `0x101C339D4 bl 0x101C2B6DC`.
- The neighbour order is preserved: `0x101C2B6BC` is the 0x20-byte loader stub, the same as old `0x102F67D94` (fmap "body").
- These are still sret through x8. That mismatch with the plugin is already in the 2.3.1 notes and is unchanged.

## QuestLoader_ProcessPhaseResource -> 0x1029E8C48
- Size 0x184, the same as old. After masking addresses, the diff is register allocation and stack slots only: lock at `+0x18`, HashMap at `+0x20/+0x28/+0x2C/+0x30/+0x3C`, insert of `{handle,1}`.
- 4 BL callers, as on 2.3.1. Two of them are fmap-mapped: `0x1029ED3C4` (old `0x102EDAD1C`) and `0x1029ED804` (old `0x102EDB148`).
- It holds the same index (12 of 14) between mapped neighbours `0x1029E7E14` and `0x1029E8E18`.

## JournalRootFolderEntry_Initialize -> 0x105207E14
- `"descriptor.journaldesc"` (`0x10765EF84`) is referenced at `0x105207EA8` = `+0x94`, the same offset as old `0x101E7528C+0x94`.
- The job descriptor guard `0x1099BD2D8` is tested at `0x105207F88`. Its init `0x105209324` names the descriptor with `"JournalRootFolderEntry/Initialize/LoadRootResource"` (`0x10765EF47`).
- The only caller is `0x10520856C`, at `+0x20` in `0x10520854C`. That function is old `0x101E75A24` (fmap "body"), whose `+0x20` called the old address.
- Args: `mov x19,x2 / x20,x1 / x21,x0`, `ldr x0,[x20]`, `ldrb [x19,#0x28]`, `x19+0x10/+0x18`. These are unchanged.

## StreamingSector_PostLoad -> 0x101C05360  (layout change)
- The new vtable `0x1078F9D40` was found with `findvt.py 0x1071B3490 40`. Slot 0 is `adrp 0x109CC5000; ldr x0,[#0x1D8]` (class getter, same shape as old). The ISerializable slots +0x38…+0x118 agree through fmap.
- Slot +0x30 (data `0x1078F9D70`) is `0x101C05360`.
- Body: `bl 0x1010B0854` (base PostLoad, old `0x102185F28`, fmap), then `add x0,x19,#0x40; bl 0x101A8F5B4` (NodeBuffer), then the same local-inplace-resource loop with IsA. It has no BL callers.
- **Layout:** the fields after NodeBuffer moved +8. The extern RaRef went from `+0xC0` to `+0xC8`. The local inplace DynArray went from `+0xA0/+0xAC` to `+0xA8/+0xB4`, and the temp array from `+0xB0` to `+0xB8`. The SDK `world::StreamingSector` macOS block (localInplaceResource 0xA0, externInplaceResource 0xC0, level 0xD8) needs +8.
- NodeBuffer is still at +0x40 but now spans 0x68 bytes instead of 0x60. Re-verify `Raw::StreamingSector::NodeBuffer` internals (nodeSetups etc.) before `PatchSector` touches them.
- New: the function ends by calling a global listener, `[0x109CC59A0]->vt[+0x28](listener, this)`.

## Localization_LoadVoiceOvers -> 0x103FE6C94
- Dispatcher `0x103FE07E4`: at `0x103FE181C` it tests guard `0x108E35230`. That guard is initialised by `0x103FE7A4C` with the label `"VoDatabase/LoadLanguageDataMaps"` (`0x1075F13DF`). The dispatcher then installs the lambda with `adrp/add 0x103FE6C94` at `0x103FE182C`. On 2.3.1 the label and the lambda ADRP were both in `0x1013FDC1C`.
- Body: the prologue is `ldr x0,[x1,#0x20]` followed by the job-context pair `0x104DDF924/0x104DF0D14`, the same pair the ink job uses.
  - It reads the HashMap at ctx+0x8: `ldp w9,w8,[x21,#0x10]`, `ldp x26,x10,[x21]`, `ldr [x21,#0x18]`.
  - It runs the IsA check `ldr x1,[0x109D02220]; bl 0x1010C6BF4`.
  - It copies into `VoDatabase+0x90`.
- It holds the same index (12 of 13) between mapped neighbours `0x103FE5A60` and `0x103FE7450`. Size is 0x7BC (old 0x7CC).

## CClass_GetProperties -> 0x1010C352C
- CClass_ToString `0x1010C31EC` (porter-mapped from old `0x1021975E4`) calls it with its 7th BL. That is the same position where old ToString calls `0x102197928`.
- Body: the same as old. It reads parent `+0x10` and self-recurses (`bl 0x1010C352C`). It walks overridden props `+0x38/+0x44` with flag `+0x2C9 bit3`, calls `GetProperty 0x1010C4C14` (the porter's CClass_GetProperty), and appends `props +0x28/+0x34` with elem 8. There is no `+0x2B` filter, so this is not the persistent-only sibling.

## CClass_AssignDefaultValuesToProperties -> 0x1010C3934
- CClass_CreateInstance `0x1010C36A0` (porter-mapped) does `bl 0x1010C37D8` (InitializeProperties, porter-mapped) and then `bl 0x1010C3934`. That is the same back-to-back pair as old `0x102197B90/0x102197B9C`.
- The GetValueHolder tail call `0x1011E50A8: b 0x1010C3934` mirrors old `0x102238C38`.
- Body: the same as old. It recurses through the parent, then works on the defaults map: keys `+0x158`, count `+0x164`, values `+0x168`, sort flag `+0x178`. It calls `GetProperty`, tests `prop+0x28` bits 5/21, and calls type `vt+0x58` Assign.

---

## Summary
1. 15/15 FOUND, 0 NOT FOUND. All are `__TEXT` (seg 1) function starts with at least two independent pieces of evidence.
2. Argument registers and returns are unchanged for all 15. The sret-x8 problems already known for LoadSubtitles, LoadOnScreens and SpawnFromLocal remain.
3. **InkSpawner_FinishAsyncSpawn:** the context is now a vtable-less functor, with `SharedPtr<InkSpawningRequest>` at **+0x10** (it was +0x18). `Red::InkSpawningContext` must change, or `OnFinishAsyncSpawn` dereferences a refcount block.
4. **worldStreamingSector:** fields from 0xA0 moved +8 (localInplaceResource 0xA8, externInplaceResource 0xC8), and NodeBuffer at +0x40 grew by 8. Re-check NodeBuffer internals before enabling `PatchSector`.
5. Behaviour changes to note:
   - Ink library entry points and FinishAsyncSpawn now have a native ':' controller path gated by byte `0x109D03E78`.
   - Mappin lookups now fall back when the resource returns null.
   - Several targets lie below image offset 0x2C00000, so the island-reach issue from the hooking notes may apply: 0x1C2B4C8, 0x1C2B6DC, 0x1C05360, 0x29E8C48, and 0x10C352C/0x10C3934 if hooked.
