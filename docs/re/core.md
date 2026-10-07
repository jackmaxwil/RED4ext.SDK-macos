# RE group "core" — macOS 2.3.1 arm64 (static analysis only)

Binary: Steam `Cyberpunk2077` (byte-identical to `Cyberpunk2077.orig` in __TEXT/__DATA_CONST; only header/linkedit differ).
Every function below is an exact `LC_FUNCTION_STARTS` entry (checked). Data entries are in __DATA_CONST/__DATA.

| name | hash | old | new seg:off (absolute) | verdict | arm64 signature vs plugin declaration |
|---|---|---|---|---|---|
| TweakDB_Get | 914361828 | 1:0x2B89D18 | **1:0x2B73C7C** (0x102B73C7C) | confirmed | `TweakDB*()` — matches |
| CStack_vtbl | 882511585 | 1:0x146BC10 | **2:0x21AEA0** (0x106FFAEA0, __const) | confirmed | data (vptr address point) — matches SDK use |
| CBaseFunction_ExecuteNative | 3778157291 | 1:0x9501DC | **1:0x21732DC** | confirmed | `bool(CBaseFunction*, CStack*)` — matches |
| CBaseFunction_ExecuteScripted | 3791200470 | 1:0x950AB8 | **1:0x2172BF4** | confirmed | `bool(CBaseFunction*, CStack*, void*)` — matches (3rd arg may be null) |
| CClass_CreateInstance | 1518341917 | 1:0x37FFC8 | **1:0x2197AAC** | confirmed | `ScriptInstance(const CClass*, uint32 size /*ignored*/, bool zero)` — matches |
| CClass_sub_80 | 298916620 | 1:0x6C3E9D3 | **1:0x2199B10** | confirmed | `bool(CClass*, int64, ScriptInstance)` — matches |
| CClass_sub_88 | 1272912818 | 1:0x6C3E9DD | **1:0x2199D18** | confirmed | `bool(CClass*, int64, ScriptInstance)` — matches |
| CClass_GetProperty | 2399343890 | 1:0x219929C | **1:0x2198B40** | confirmed | `CProperty*(CClass*, CName)` — matches |
| CClass_GetProperties | 1652956141 | 1:0x2199548 | **1:0x2197928** | likely | `void(CClass*, DynArray<CProperty*>&)` — matches (SDK typedef says returns CProperty*, harmless) |
| CClass_InitializeProperties | 2257327441 | 1:0x6C3EA57 | **1:0x2197BE4** | confirmed | `void(CClass*, ScriptInstance)` — matches |
| CClass_AssignDefaultValuesToProperties | 2547979664 | 1:0x6C3EA5E | **1:0x2197D40** | confirmed | `void(CClass*, ScriptInstance)` — matches |
| ISerializable_Counter | 2630817091 | 1:0x7500000 | **3:0x1C774F8** (0x10900B4F8, __common) | confirmed | data int64; SDK InterlockedIncrement64 = game `ldaddal +1` — matches |
| ISerializable_sub_30 | 114701897 | 1:0x2185F18 | **1:0x2186078** | confirmed | `bool(ISerializable*)` — matches |
| ISerializable_sub_40 | 2293436409 | 1:0x2186208 | **1:0x2185F34** | confirmed | `bool(ISerializable*, BaseStream*)` — matches |
| ISerializable_sub_78 | 2715367827 | 1:0x218604C | **1:0x21862CC** | confirmed | **MISMATCH**: arm64 = `Handle<ISerializable> (x8 sret)(this, a2, uint8 a3, CName a4, void* a5)`; SDK passes 6 regs (a1 in x1) and no x8 |
| ISerializable_sub_A0 | 3978435378 | 1:0x21864F8 | **1:0x2186230** | confirmed | `void*(ISerializable*)` — matches |
| ISerializable_sub_C0 | 2149588021 | 1:0x2186258 | **1:0x2186208** | confirmed | arm64 = `void*(ISerializable*)` (no 2nd arg, result in x0); SDK's `a1` is ignored and never written — semantic mismatch only |
| IScriptable_sub_D8 | 4175699423 | 1:0xCFFC | **1:0x2238918** | confirmed | `void(IScriptable*, int64 a1 /*unused*/, int64 a2)` — matches |
| IScriptable_DestructValueHolder | 55710513 | 1:0x217FFD8 | **1:0x22384BC** | confirmed | `void(IScriptable*)` — matches |
| Handle_DecWeakRef | 859509764 | 1:0x243CC4 | **1:0x21048C4** | confirmed | `void(SharedPtrBase*)` — matches |
| Handle_ctor | 3121353053 | 1:0x243C88 | **none** (always inlined on macOS) | refuted (no address) | SDK must inline `Handle(T*)` on macOS (recipe below) |
| CGameEngine | 2549221846 | 1:0x31FE4 | **3:0x1D483A0** (0x1090DC3A0, __common) | confirmed | data `CBaseEngine*` global — matches `UniversalRelocPtr<CGameEngine*>`; **struct size differs** (0x380 vs SDK 0x350) |
| ResourceDepot | 1704595399 | 1:0x17043A4 | **3:0x9D8538** (0x107D6C538, __bss) | confirmed | data `ResourceDepot*` global — matches ptr semantics; **struct layout differs** (see below) |
| ResourceLoader | 2017202228 | 1:0x21BC5D0 | **3:0x1C77580** (0x10900B580, __common) | confirmed | data `ResourceLoader*` global — matches (object 0x80 = SDK size) |
| ResourcePath_Create | 3998356057 | 1:0x34094E4 | **1:0x21C90A4** | confirmed (identity) | **MISMATCH**: arm64 = `uint64 /*ResourcePath*/ (const char* str /*x0*/, uint32 len /*x1*/)` (StringView by value, hash returned in x0); ArchiveXL declares `ResourcePath*(ResourcePath* out, StringView* in)` |
| BufferReader_MakeType0 | 1299073554 | 1:0xBE6FA8 | **1:0x22643C0** | confirmed | **MISMATCH**: arm64 = `UniquePtr<BufferReader> (x8 sret)(const void* payload /*x0*/)`; ArchiveXL passes (out in x0, payload in x1) |
| BufferReader_MakeType1 | 3578095989 | 1:0xBE6FA8 | **1:0x226442C** | confirmed | same MISMATCH as MakeType0 |

## Per-entry evidence

**TweakDB_Get 0x102B73C7C** — `ldapr x0,[0x1080C92D0]`; if null calls `0x102B73B50` (allocates 0x168 = SDK `sizeof(TweakDB)`, ctor `0x102B73DB8`, `swpal` into 0x1080C92D0 under the macOS spinlock). TweakDB init lambda `0x1035F1BAC` calls it at `0x1035F1BE0` and `0x1035F1BF4` (result → x0 of TweakDB_Load `0x102B75570`). 7899 BL callers. Old 0x2B89D18 unrelated.

**CStack_vtbl 0x106FFAEA0** — found via `CStack::GetResultAddr` byte pattern (`ldr x8,[x0,#0x40]; cbz; ldr x0,[x8,#8]`) at `0x1021746F8`, only vtable ref at 0x106FFAEB0. Slots: D1 `0x1000276D8`, D0 `0x100008D80`, +0x10 GetResultAddr, +0x18 GetResultType `0x102174710`, +0x20 sub_18 (ret), +0x28 sub_20 `0x102174558`, +0x30 GenerateCode `0x102174684` (emits opcode 0x1B + 16-byte arg per arg, then 0x26). Game CStack ctor `0x102174490` stores base vptr 0x106FFADE0 then this one, `unk28 = GetTypeObject<IScriptable>()`, args@0x30, argsCount@0x38, result@0x40 — exactly the SDK layout.

**CBaseFunction_ExecuteNative 0x1021732DC** — `stack->vtbl[+0x30]` GenerateCode into a 0x108-byte stack buffer, builds CStackFrame (`0x1021FEF48(frame, stack->GetContext(), code, stack->unk10)`), frame+0x58 = stack->unk08, then `0x102172F90(func, stack, frame)` (native invoker: non-static → handler table 0x10900B798 indexed by `func->GetRegIndex()` (vt+0x20); no context → `GetInvokable()` vt+0x28; static → table 0x10908B798). Same code is inlined in the dispatcher `0x1021733A8` (= SDK `CBaseFunction::Execute`, tests `flags@0xA8` bit0).

**CBaseFunction_ExecuteScripted 0x102172BF4** — called by dispatcher `0x1021733A8` as `(func, stack, 0)` when `!isNative`; alloca of `func->unkAC` locals, `stack->vtbl[+0x28]` fills locals, builds frame, runs bytecode via `0x102172D54` (opcode table 0x10908B798), returns 1. `0x102173390` (323 callers) is a thin `(func,stack,unk)→true` wrapper around it — also usable.

**CClass vtable (address point 0x106FFBB10, used by 8958 class vtables)** — 31 slots = MSVC 30 + 1 (D1/D0 at +0/+8). Field reads confirm the shift: +0x10 GetName `ldr x0,[x0,#0x18]`, +0x18 GetSize `[#0x68]`, +0x20 GetAlignment `[#0x74]`, +0x28 GetType `=2`, +0x60 Move calls +0x58 Assign.
- **sub_80 0x102199B10** (slot +0x88, `b 0x102199B14`): `(cls,a1,inst)`; walks `unk118` props, recurses with type vt+0x88.
- **sub_88 0x102199D18** (slot +0x90, `b 0x102199D1C`): `(cls,a1,inst)`; recurses with type vt+0x90. Both are the CClass base (`final`) impls; old values pointed into `__cstring`.

**CClass_CreateInstance 0x102197AAC** — returns null if `flags@0x70` isAbstract; size = align_up(`size@0x68`, `alignment@0x74`), allocator from `GetAllocator` (vt+0xC0) else `AllocMemory` (vt+0xF0); bzero if w2; `ConstructCls` (vt+0xE0); then InitializeProperties + AssignDefaultValues. 152 callers; engine creator `0x103D8BFC4` calls it as `(cls, cls->GetSize(), 0)` — x1 is ignored inside (recomputed).

**CClass_InitializeProperties 0x102197BE4 / AssignDefaultValuesToProperties 0x102197D40** — called back-to-back by CreateInstance and by game `IScriptable::GetValueHolder` `0x102238BDC` (if `valueHolder@0x38` null: `InitializeProperties(cls,this)` then tail-call AssignDefault) — identical to SDK `GetValueHolder`. 0x102197BE4 allocates `holderSize@0x6C`, stores `{nativeType,holder}` via `0x102238880` (`stp x1,x2,[x0,#0x30]`), constructs scripted props (type vt+0x40). 0x102197D40 recurses to parent, iterates `defaults` map @0x158/0x168, `GetProperty`, type vt+0x58 Assign.

**CClass_GetProperty 0x102198B40** — `propsByName` hashmap @0xE8, fallback linear scan `props@0x28` (count @0x34) comparing `prop->name@8`, then parent @0x10, handles `overriddenProps@0x38`. 86 callers. Old 0x219929C was inside another function's prologue.

**CClass_GetProperties 0x102197928** (likely) — recurse parent, append all `props@0x28` (`DynArray_Realloc 0x1000286E8`, elem 8), replace overridden ones. Sibling `0x102198670` is the same walk filtered on prop flag (+0x2B bit4); chose the unfiltered one. Old 0x2199548 is CClass vtable slot +0x98 (sub_90), not GetProperties.

**ISerializable vtable 0x106FFBA20** (stored by ISerializable ctor `0x102185D0C`, 2758 callers) — 28 slots = MSVC 27 + 1. Trivial slots match SDK bodies exactly (sub_20/PostLoad/sub_38 `ret`; sub_48→type vt+0x88; sub_50→type vt+0x90; sub_58/60/68 false; sub_70 true; sub_A8 → GetType; sub_B8 builds name string via x8; CanBeDestructed true). Therefore: sub_30=+0x38 `0x102186078`, sub_40=+0x48 `0x102185F34` (reads `stream+8` bit1), sub_78=+0x80 `0x1021862CC` (`mov x19,x8` sret; builds `{obj, RefCnt}` handle), sub_A0=+0xA8 `0x102186230` (GetType()→ default object `cls+0xE0`, lazily CreateInstance), sub_C0=+0xC8 `0x102186208` (resolves owner via weak handle, returns `[obj+0x30]`). Same entries inherited in IScriptable vtable.

**ISerializable_Counter 0x10900B4F8** — ctor: `unk28 = 0x102186B30()`; `0x102186B30` = `ldaddal #1,[0x10900B4F8]; add x0,old,#1` (only ADRP ref). Old value was a fabricated round number.

**IScriptable vtable 0x107000F00** (ctors `0x102238444`/`0x102238468`: ISerializable ctor, then this vptr, zero +0x30/+0x38). Slots +0xE0..+0x108 = SDK sub_D8..sub_100. **sub_D8 0x102238918**: `GetType()` then tail-call `0x102198FF4(cls, a2)`. **DestructValueHolder 0x1022384BC**: called from IScriptable dtor `0x10223848C` exactly like SDK `~IScriptable`; destructs scripted props (type vt+0x48 Destruct), frees holder through class allocator (vt+0xC0), nulls +0x38.

**Handle_DecWeakRef 0x1021048C4** — `if (p->refCount) { if (ldaddal(-1, &rc->weak@+4)==1) { Free<PoolRefCount>(rc,1); p->refCount=0; } }`. 82,132 BL callers (ISerializable dtor uses it on +0x18 and +0x08). Byte-identical twin `0x100914668` (15,232 callers) — either works.

**Handle_ctor — no out-of-line instance on macOS.** 1190 functions inline it: `rc = PoolStorageProxy<PoolRefCount>::Allocate(8)`; `rc = {strong 1, weak 1}`; `handle = {obj, rc}`; for ISerializable-derived T also `IncWeak(rc)`, swap `obj->ref`(@0x08) with `{obj,rc}`, release the old weak with DecWeakRef (see `0x1021863B4..0x102186400`). SDK should implement `Handle(T*)` inline on macOS using the exported `__ZN3red6memory16PoolStorageProxyINS_12PoolRefCountEE8AllocateEy` / `__ZN3red6memory4FreeINS_12PoolRefCountEEEvPKvj` (dlsym). Old 0x243C88 was inside an unrelated function.

**CGameEngine 0x1090DC3A0** — engine creator `0x103D8BFC4`: `CRTTISystem::GetClass(name)` (name from app state vtable 0x106E4B258 slot "CGameEngine" `0x100031FE4`), IsA CBaseEngine, `CreateInstance` → `str x0,[0x1090DC3A0]`. 522 code refs. Old 0x31FE4 was the `CName("CGameEngine")` getter (code). CGameEngine RTTI size on mac is **0x380** (`0x103F22EFC`), SDK asserts 0x350; `framework@0x308` still matches (BaseGameEngine ctor `0x1035F087C`).

**ResourceDepot 0x107D6C538** — `GameApplication::InitResourceDepot` `0x101704194` allocates 0x80, ctor `0x103ED9578`, stores at `app+0x198`, calls setter `0x1021C682C` (`str x0,[0x107D6C538]`); getter `0x1021C6820` has 53 callers; assert string "Core: Failed to initialise a resource depot!". Old 0x17043A4 was the ResourceLoader-init function (code).

**ResourceLoader 0x10900B580** — `0x1017043A4` creates the loader via `0x1021B9B58` (allocates 0x80 = SDK size), stores `app+0x1A0`, then `str x8,[0x10900B580]`. 215 code refs.

**ResourcePath_Create 0x1021C90A4** — strips leading quote, collapses `/` and `\` runs to `\`, `tolower`, stops at quote, FNV-1a64 (0xCBF29CE484222325 / 0x100000001B3) → x0. 244 callers; tail-called by constant-path thunks (e.g. `0x102023738`). Old 0x34094E4 unrelated.

**BufferReader_MakeType0 0x1022643C0 / MakeType1 0x10226442C** — the only heap constructors of the two reader vtables: type-0 vtable 0x107001D80 (slot +0x28 `0x1022638FC` = `mov w0,#0`), allocates 0x28, copies `{SharedPtr, u64, u32}` payload from x0 (+inc ref); type-1 vtable 0x107001D40 (slot +0x28 `0x102263868` = `mov w0,#1`), allocates 0x40, copies 0x18 payload + inits. Both write the new object to `[x8]`. Payload layout = reader+8, as ArchiveXL assumes. Old shared value 0xBE6FA8 was an RTTI property-registration function.

## Signature / ABI problems (must fix before enabling)

1. **ISerializable_sub_78** — x8 sret (MSVC member-fn hidden return was the SDK's `a1`). Calling with the SDK typedef passes garbage x8 → arbitrary write. Override in plugin classes receives shifted args.
2. **ISerializable::sub_B0 (+0xB8, `0x102185F2C`) and sub_C8 (+0xD0, `0x10093FB88`)** (not in worklist, but dangerous): the game versions write the result via **x8** (`stp xzr,xzr,[x8]` / memset x8). The SDK overrides `sub_B0(void* a1)`/`sub_C8(void* a1)` memset **x1** → any plugin class derived from ISerializable/IScriptable that the game calls through these slots will memset a garbage pointer.
3. **ISerializable_sub_C0** — returns its value in x0; SDK's `a1` is never written.
4. **BufferReader_MakeType0/1** — out pointer must go in x8, payload in x0 (e.g. declare return type as a non-trivially-copyable 8-byte wrapper so clang uses x8).
5. **ResourcePath_Create** — `uint64(const char*, uint32)`; wrap: `out->hash = fn(sv->data, sv->size)`.
6. **Layouts**: CGameEngine is 0x380 on mac (SDK 0x350). ResourceDepot is 0x80 with a second vptr at +0x08: DynArrays at +0x10/+0x28/+0x38, CString rootPath at **+0x48** (SDK 0x30), DynArray of 0x140-byte entries at +0x68, bool at **+0x78** (SDK hasModArchives 0x50) — ArchiveXL reading `groups`/`rootPath` by SDK offsets will misread.
7. **Handle_ctor** has no address; leaving it unresolved makes every `Handle<T>(T*)` in the SDK call null.

## Useful extras found
CClass base vtable 0x106FFBB10; ISerializable vtable 0x106FFBA20; IScriptable vtable 0x107000F00; `CBaseFunction::Execute` dispatcher 0x1021733A8; native invoker 0x102172F90; IScriptable::GetValueHolder 0x102238BDC; ResourceDepot::Get 0x1021C6820; engine creator 0x103D8BFC4; GetTypeObject<IScriptable> 0x10223809C; ResourceDepot ctor 0x103ED9578 (its next function 0x103ED96B0 = current DB `ResourceDepot_InitializeArchives`).
