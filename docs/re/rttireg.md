# RE group "rttireg": TweakXL RedLib native-type registration (macOS 2.3.1, arm64)

This was static analysis only. Nothing was launched and no repo or game files were edited.
Every function address below is in LC_FUNCTION_STARTS. The data entry points into `__DATA` (`__bss`).

| name | hash | old | new seg:off (absolute) | verdict | arm64 signature vs plugin declaration |
|---|---|---|---|---|---|
| CClass_sub_90 | 2725066574 | 1:0x6C3E9E6 | **1:0x2199548** (0x102199548) | confirmed | `bool(CClass*, int64 a1, ScriptInstance, CString& a3, int64 a4)`. Matches. |
| CClass_sub_A0 | 368188783 | 1:0x6C3E9F3 | **1:0x2199880** (0x102199880) | confirmed | `bool(CClass*, int64 a1, CString& a2, bool* a3)`. **MISMATCH:** the SDK declares `bool a3` by value, but the game writes through x3 (`strb w19,[x20]`). |
| CClass_sub_B0 | 2693863796 | 1:0x6C3E9F8 | **1:0x219E390** (0x10219E390) | confirmed | `void(CClass*, ScriptInstance a1, int64 a2)`. Matches. The SDK func_t says `bool` and discards the result, which is harmless. |
| CClass_sub_C0 | 3523744305 | 1:0x6C3EA07 | **1:0x219A254** (0x10219A254) | confirmed | `void(CClass*)`. Matches. |
| CClass_GetMaxAlignment | 3511554608 | 1:0x6C3EA0D | **1:0x2199F48** (0x102199F48) | confirmed | `uint32(const CClass*)`, returned in w0. Matches. |
| CClass_sub_D0 | 930418367 | 1:0x6C37108 | **1:0x219A3E8** (0x10219A3E8) | confirmed | `bool(const CClass*)`. Matches. |
| CClass_ToString | 1697201926 | 1:0x74617C | **1:0x21975E4** (0x1021975E4) | confirmed | `bool(const CClass*, ScriptInstance, CString& out)`. Matches. There is no x8 sret because the CString is passed by reference. |
| CClass_Unserialize | 3836349613 | 1:0x7460A8 | **1:0x21999DC** (0x1021999DC) | confirmed | `bool(const CClass*, BaseStream*, ScriptInstance, int64)`. Matches. The slot holds a `b` thunk; the body at 1:0x21999E0 is equivalent. |
| TTypedClass_IsEqual | 1482886888 | 1:0x2189040 | **1:0x93FCAC** (0x10093FCAC) | confirmed | `bool(CClass*, ScriptInstance lhs, ScriptInstance rhs, uint32 a3)`. Matches. This is a `b` thunk; the body at 1:0x2197FE4 is equivalent. |
| CClassFunction_ctor | 1613572595 | 1:0x21FCEE0 | **1:0x2173760** (0x102173760) | confirmed | `CClassFunction*(this, CClass* parent, CName full, CName short, <member-fn-ptr {fn x4, adj x5}>, Flags w6)`. **MISMATCH (critical):** the SDK passes Flags in x5 and nothing in w6. |
| CClassStaticFunction_ctor | 2920426135 | 1:0x21FC61C | **1:0x2173864** (0x102173864) | confirmed | `CClassStaticFunction*(this, CClass* parent, CName full, CName short, fn x4, Flags w5)`. Matches the SDK exactly. |
| CRTTIRegistrator_RTTIAsyncId | 3720157672 | 1:0x345A000 | **3:0x9D5E50** (0x107D69E50) | confirmed | **Data**: a `uint32` counter, which matches `UniversalRelocPtr<uint32_t>` plus `InterlockedIncrement`. The old entry was in segment 1 (code), which was wrong. |

All 12 old values are refuted. The six `CClass_sub_*` and GetMaxAlignment entries pointed into `__cstring`, at the unit names "length", "mass", "power", "speed", "temperature" and "torque". The others are unrelated functions: ToString's old value is a typeinfo or dynamic_cast compare, Unserialize's is a 0x18-byte object clone, and IsEqual's old value is a CRTTISystem routine working on +0x100. The two old ctor values are script-loader routines that call `red::VTable` closures. `0x10345A000` is not a function start.

## Slot map (CClass base vtable 0x106FFBB10; macOS slot = SDK comment + 8)

The scan found 8958 vtables that share GetName/GetSize/GetType (0x1021975BC/CC/D4). Each slot below holds the **same pointer in all 8958 of them**. That means each is the `final` CClass implementation, not a per-type override.

| SDK slot | SDK name | mac slot | target |
|---|---|---|---|
| 0x48 | IsEqual | +0x50 | 0x10093FCAC in 8241 TTypedClass vtables. 712 vtables have the CClass base 0x102196CAC (`mov w0,#0; ret`). |
| 0x60 | Unserialize | +0x68 | 0x1021999DC |
| 0x68 | ToString | +0x70 | 0x1021975E4 |
| 0x80 / 0x88 | sub_80 / sub_88 | +0x88 / +0x90 | 0x102199B10 / 0x102199D18. These are already confirmed in core.md, which cross-checks the map. |
| 0x90 | sub_90 | +0x98 | 0x102199548 |
| 0x98 | sub_98 | +0xA0 | 0x1021996C0 (not in the worklist) |
| 0xA0 | sub_A0 | +0xA8 | 0x102199880 |
| 0xB0 | sub_B0 | +0xB8 | 0x10219E390 |
| 0xB8 | GetAllocator | +0xC0 | varies per type (293 distinct values) |
| 0xC0 | sub_C0 | +0xC8 | 0x10219A254. One vtable overrides it, with 0x1021A2FA0. |
| 0xC8 | GetMaxAlignment | +0xD0 | 0x102199F48 |
| 0xD0 | sub_D0 | +0xD8 | 0x10219A3E8 |
| 0xD8 / 0xE0 / 0xE8 | ConstructCls / DestructCls / AllocMemory | +0xE0 / +0xE8 / +0xF0 | varies per type |

## Evidence

**CClass_sub_90 0x102199548**
- This is the shared slot +0x98 pointer. Its arguments are x0 = cls, x1 = a1, x2 = inst, x3 = CString&, x4 = a4.
- It calls `CString::IsEmpty` 0x10002B9D4 (`ldr w8,[x0,#0x14]; tst #0x3fffffff`) on x3, parses the next path segment, and calls `GetProperty` 0x102198B40.
- It recurses through `prop->type->vt[+0x98]` with `(type, a1, inst+valueOffset@0x20, rest, a4)`, which is the same slot.
- On failure it calls `a1->vt[+0x10]` with "Expected property name in path" (0x106CC32E0) or "Property '%hs' not found" (0x106CC329E).

**CClass_sub_A0 0x102199880**
- This is slot +0xA8. Its arguments are x1 = a1 (error sink), x2 = CString& path (passed to IsEmpty), x3 = **out pointer**.
- It walks the path through GetProperty. If prop flags@0x28 bit1 is set, it does `strb #1,[x3]` and returns 1. If the path is exhausted, it does `strb wzr,[x3]` and returns 1. Otherwise it recurses through `type->vt[+0xA8](type, a1, rest, x3)` and passes x3 through.
- **ABI flag:** `a3` is `bool*` (or `bool&`), not `bool`. The SDK's `CClass::sub_A0(int64, CString&, bool)` final override receives the pointer in a `bool` parameter. It then forwards it to the game, which dereferences it. This only survives if clang passes x3 through untouched. Change the SDK declaration to `bool* a3` (and the func_t to match).

**CClass_sub_B0 0x10219E390**
- This is slot +0xB8. It runs an IsA check against 0x102185C24 (ISerializable type) and then calls 0x102186554(inst, a2).
- It builds the flattened prop cache with 0x10219DCE0(cls, 0), the same routine IsEqual uses, then iterates `unk118@0x118` (count @0x124).
- It recurses through `type->vt[+0xB8](type, inst+off, a2)`, which is the same slot.

**CClass_sub_C0 0x10219A254**
- This is slot +0xC8, with signature `void(cls)`. It collects props from `props@0x28`/`@0x34` that have flag 0x2A bit5 set. If `size@0x68 == 0`, it calls `parent->vt[+0xC8]` (the same slot) and copies `parent->size`.
- It then calls `this->vt[+0xD0]` (GetMaxAlignment), stores `alignment@0x74 = max(align, ret, 4)`, and recomputes `holderSize@0x6C` with 0x102176168. This is the layout finalizer.

**CClass_GetMaxAlignment 0x102199F48**
- This is slot +0xD0, called by sub_C0 above. It starts from `alignment@0x74`. For scripted classes (flags@0x70 & 0xC) it walks `parent@0x10` until it reaches a native class.
- It calls `GetProperties` 0x102197928, takes the max of each `prop->type->vt[+0x20]` (GetAlignment), and returns the result in w0.

**CClass_sub_D0 0x10219A3E8**
- This is slot +0xD8, with signature `bool(cls) const`. It calls GetProperties, and for each prop it compares `valueOffset@0x20 + type->GetSize()` (vt+0x18) against `size@0x68` (or `holderSize@0x6C` for scripted props).
- It also checks each prop pairwise for overlaps and returns the AND as `w0 & 1`. It is a layout validity check.

**CClass_ToString 0x1021975E4**
- This is slot +0x70, with signature `(cls, x1 = inst, x2 = CString& out)`. It converts `name@0x18` to a string and appends it to out together with "[" (0x106C168C1).
- It then calls GetProperties 0x102197928 and recurses through `type->vt[+0x70](type, inst+off, tmp)`, which is the same slot.

**CClass_Unserialize 0x1021999DC**
- This is slot +0x68 and holds `b 0x1021999E0`. The body takes `(cls, x1 = stream, x2 = inst, x3 = a3)`.
- It runs an IsA check (0x10219AC60), then lazily creates the default object at `cls+0xE0` with `CreateInstance` 0x102197AAC.
- It reads one byte through `stream->vt[+0x18](stream, buf, 1)` and tests `stream+8` bit1, which is the same stream flag ISerializable sub_40 reads.

**TTypedClass_IsEqual 0x10093FCAC**
- In 8241 of the 8958 CClass-derived vtables, +0x50 = 0x10093FCAC. Those vtables also have their own per-type Assign (+0x58) and ConstructCls/DestructCls/AllocMemory (+0xE0/E8/F0), which is exactly the shape of the SDK `TTypedClass<T>`. The base CClass vtable has `mov w0,#0; ret` (0x102196CAC) in that slot.
- 0x10093FCAC is `b 0x102197FE4`. The body takes `(x0 = cls, x1 = lhs, x2 = rhs, x3 = a3)`.
- It calls the prop-cache builder 0x10219DCE0(cls, 0), which is the "something extra" mentioned in the SDK comment.
- It then iterates `unk118@0x118`/`@0x124` and calls `prop->type->vt[+0x50](type, lhs+off, rhs+off, a3)`. It returns 1 only if every prop compares equal.
- Both addresses are valid. 0x93FCAC is the exact vtable entry.

**CClassFunction_ctor 0x102173760** (called via thunk 0x102173860 `b`, which has **13332 callers**)
- It stores CBaseFunction base vptr 0x106FFAC48 at +0, `x2 → +8` (fullName), `x3 → +0x10` (shortName), and initializes the same DynArrays and fields as CGlobalFunction_ctor 0x1021739E8.
- It sets `flags@0xA8 = w6 | 1` (isNative), then the CClassFunction vptr 0x106FFAC78+0x10, then `parent x1 → +0xB0`.
- It registers the function with 0x1021FD4C8(x4, x5). That routine stores the **16-byte `{x4, x5}` pair** into the member table at 0x10900B798 (stride 16) and returns regIndex → +0xB8.
- The native invoker 0x102172F90 loads `{ptr, adj}` from that table, applies `this += adj >> 1`, and makes a virtual call through `[vtbl + ptr]` when `adj & 1` is set. This is the Itanium/AppleARM64 pointer-to-member-function ABI.
- A game call site at 0x1009417A0 does `mov x4, fn; mov x5, #0; mov w6, #0; bl 0x102173860`.
- **ABI flag (critical):** the SDK `func_t(CClassFunction*, CClass*, CName, CName, ScriptingFunction_t<T>, Flags)` puts Flags in w5. The game reads w5 as the member-pointer `adj` and takes flags from x6, which would be garbage. Any non-zero flags value with bit0 set makes the game treat the call as virtual and crash. Even values shift `this` by `adj >> 1`. On macOS the call must be `func(mem, parent, full, short, (void*)aFunc, (intptr_t)0, aFlags)`. On Windows (MSVC) the member pointer is a single 8-byte value, so the SDK declaration is only correct there.

**CClassStaticFunction_ctor 0x102173864** (called via thunk 0x10217395C `b`, which has **938 callers**)
- It is identical to the ctor above, except it sets `flags@0xA8 = w5 | 3` (isNative | isStatic) and `parent x1 → +0xB0`.
- It registers with 0x1021FD4F4(x4), which takes a single 8-byte pointer into the plain table 0x10908B798. This is the same registration routine CGlobalFunction_ctor uses.
- A game call site at 0x100A8EF20 does `mov x4, fn; mov w5, #0; bl 0x10217395C`. The signature matches the SDK exactly, with Flags as a uint32 bitfield struct in w5.
- Both class ctors store vtable 0x106FFAC78, so the static variant is distinguished by the flag alone. The other two users of the base vptr, 0x102173B48 and 0x102173C28, store vtable 0x106FFACF8 and take no native fn. They are CScriptedFunction ctors and were rejected.

**CRTTIRegistrator_RTTIAsyncId 0x107D69E50 (data)**
- On macOS, type ids live in `GetNativeTypeHash<T>()::nativeTypeHash` function-local statics. These are weak-coalesced and reached through the GOT, for example `__ZZ17GetNativeTypeHashI8TestStepEyvE14nativeTypeHash`.
- Their guarded initializer (for example 0x100952DA0) runs `nativeTypeHash = bl 0x102184D7C`, and that value is later passed as the asyncId to `CRTTISystem::RegisterType` (vt+0x80, through 0x1021885A4).
- 0x102184D7C (**33510 callers**) is `RTTIRegistrator::GetNextId`. It guards on 0x107D69E58, zero-initializes the counter once, then does `ldaddal w9(=1), w8, [0x107D69E50]; add w0, w8, #1`. That is Windows' `lock xadd; inc` exactly.
- Only this function references 0x107D69E50. It is a uint32 in `__DATA,__bss`: 0x107D69E50 − 0x107394000 = 3:0x9D5E50.
- **Note:** this is a guarded function-local static. It is initialized during the game's static init, which runs long before plugins load, so the SDK's raw `InterlockedIncrement(ptr)` is safe. A more robust alternative is to resolve and call 0x102184D7C directly, which handles the guard itself.

## Related SDK issue (outside the worklist)
- The SDK's `CClass::sub_98` reuses the `CClass_sub_90` hash and drops `a5`. On macOS, sub_98 has its own body at 0x1021996C0 (slot +0xA0, six args, recurses through vt+0xA0). Calling sub_90 instead does not crash, because sub_90 ignores x5, but the result differs from the real sub_98. The `CClass_sub_98` hash exists in AddressHashes.hpp but nothing uses it.
