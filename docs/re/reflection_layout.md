# Reflection object layout for a live dumper: macOS 2.3.1 arm64 (static analysis only)

Binary: Steam `Cyberpunk2077.orig` (the same bytes as the app binary in __TEXT/__DATA_CONST). All addresses are absolute, with image base 0x100000000. The game was not launched.

## Summary

| # | Question | Verdict | Value on macOS |
|---|---|---|---|
| 1 | CProperty layout | **confirmed**; identical to the SDK | type @0x00, name (CName) @0x08, group (CName) @0x10, parent CClass* @0x18, **valueOffset u32 @0x20** (u32 @0x24 is zeroed), flags u64 @0x28. sizeof = 0x30 |
| 2 | Which CClass array is used | **confirmed** | Native registration appends to **props @0x28** (entries @0x28, cap @0x30, size @0x34). `unk118` is really **@0x118** (entries/cap/size @0x118/0x120/0x124). It is a **lazily built, flattened cache** (parent props + overrides + own props). The cache is **empty until the class is first used**. GetProperty never reads it. |
| 3 | Enumerating types | **confirmed (a)** | `CRTTISystem::Get()` 0x102188E8C returns the singleton at 0x107D6A288; its vtable is 0x106FFBD70. The slots have **the same offsets as the SDK** (the dtor pair sits at the end, +0x138/+0x140). Use **GetClasses @+0x70** and **GetEnums @+0x60**, which take the type lock. GetNativeTypes @+0x40 does not take the lock. |
| 4 | CBaseRTTIType vtable | **confirmed** | **Every slot is SDK+8**, because Itanium has two destructor slots. GetName **+0x10**, GetSize **+0x18**, GetAlignment **+0x20**, GetType **+0x28**, GetTypeName +0x30, GetComputedName +0x38, Assign +0x58. This holds for the base class and all 17 kinds. The ERTTIType values 0..16 match the SDK enum exactly. |
| 5 | `re_tools/rtti_dumper.js` | not used | Its CRTTISystem::Get (0x3452734) and valueOffset +0x18 are wrong. The correct values are 0x2188E8C and +0x20. |

## 1. CProperty: valueOffset is +0x20, and the whole layout matches the SDK

How the offset passed at registration ends up at CProperty+0x20, using all four inkWidgetLibraryResource properties from register fn **0x104964FC8**:

| property | name string ref | `mov w2` (offset) | factory BL |
|---|---|---|---|
| libraryItems | 0x104965038 → 0x106DB6A21 | 0x104965084 `mov w2,#0x40` | 0x104965094 |
| externalLibraries | 0x1049650A8 → 0x106DB6A30 | 0x1049650F4 `mov w2,#0x50` | 0x104965104 |
| rootDefinitionIndex | 0x1049651F0 → 0x106DB7F55 | 0x104965234 `mov w2,#0x3c` | 0x104965244 |
| rootResolution | 0x1049652C8 → 0x106DB6979 | 0x10496530C `mov w2,#0x39` | 0x10496531C |

The same function also registers animationLibraryResRef 0x60, sequences 0x78, externalDependenciesForInternalItems 0x88 and version 0x98. The class itself is created by `0x102196F40(cls=0x108D8B240, "inkWidgetLibraryResource", size 0xA0, flags 2)`; the SDK says 0xA8.

Each property goes through these steps:
1. **Factory `0x102176740(builder x0, cls x1, u32 offset w2, CName name x3, group x4, type x5, x6)`.**
   - `stp x3,x4,[sp,#0x30]`; `stp x1,x5,[sp,#0x40]`; `stp x2,x8,[sp,#0x50]`. The descriptor is {name, group, cls, type, offset}, with the offset at descriptor+0x20.
   - The descriptor is swapped into the builder with `ldr q1,[sp,#0x50]; str q1,[x19,#0x20]` at 0x10217682C/0x102176838.
2. **`CClass_AddProperty` 0x102196C28 calls commit `0x102176CBC(builder)`.**
   - The commit allocates **0x30** bytes (`mov w0,#0x30` at 0x102176CD8).
   - It loads `ldp x2,x1,[x19,#0x10]` (x2 = cls, x1 = type), `ldr w3,[x19,#0x20]` (offset), `ldp x4,x7,[x19]` (name, group) and `orr x5, flags, #0x4000`.
   - It then calls the CProperty ctor 0x10217606C, followed by `0x102198134(cls, prop)`.
3. **CProperty ctor 0x10217606C:**
   - `str x1,[x0]` stores the **type @0x00**.
   - `stp x0(name),x7(group),[x23,#0x8]` stores the **name @0x08** and **group @0x10**.
   - `str x22(cls),[x23,#0x18]` stores the **parent @0x18**.
   - **`stp w21(offset),wzr,[x23,#0x20]`** stores the **valueOffset @0x20**.
   - `str x20(flags),[x23,#0x28]` stores the **flags @0x28**.
4. **The game reads it back in CClass::AssignDefaultValuesToProperties 0x102197D40:**
   - `ldr x21,[x22]` reads the type.
   - `ldr x8,[x0,#0x28]` reads the flags. `tbz w8,#5` tests isScripted, and `tbz w8,#0x15` tests inValueHolder; when that bit is set, the holder comes from 0x102176328.
   - **`ldr w8,[x22,#0x20]` (0x102197E6C) is followed by `add x1, x0, x8` (0x102197E10).** This adds the offset to the instance (or holder) pointer.
   - The value is assigned through `type->vt[+0x58]` (Assign).
   - The flag bits used here (5 = isScripted, 0x15 = inValueHolder) match the SDK's `CProperty::Flags`.
5. **The SDK's GetValuePtr is therefore correct on macOS as written.**

## 2. CClass arrays: props @0x28 vs unk118 @0x118

**Registration writes props @0x28.**
- `0x102198134(cls, prop)` loads `ldr x21,[x20,#0x28]!`, grows the array with `DynArray_Realloc 0x1000286E8` (elem 8, align 8), stores `str w22,[x19,#0x34]` and appends.
- It then clears bits 0 and 2 of `byte @0x2C9` (`and #0xFA`), which invalidates the cache.

**GetProperty 0x102198B40 (86 callers) never reads 0x118.** It looks in three places, in order:
1. `propsByName` HashMap @0xE8, only when its size @0xF0 is non-zero.
2. A linear scan of **props @0x28** (count @0x34), comparing `prop->name @+8`.
3. Recursion into the parent @0x10, then **overriddenProps @0x38** (count @0x44).

**The overriddenProps elements are 16 bytes on macOS**, not 8 as the SDK's `DynArray<CProperty*>` declares. The code is `add x24,x23,x8,lsl #4`, with `CProperty*` @+0 and a u32 @+8 (`ldr w2,[x23,#8]`).

**unk118 is @0x118 exactly.** It is built only by the lazy cache builder **0x10219DCE0(cls, bool force)**:
- It takes the CClass spinlock **@0x2C8**. If bit0 of **@0x2C9** is already set and force is 0, it skips the rebuild.
- It clears `unk118.size @0x124`, the propsByName map @0xE8 and `unk138 @0x138` (size @0x144).
- It calls **CClass::GetProperties 0x102197928(cls, &cls->unk118)**. GetProperties recurses into the parent first, applies overriddenProps @0x38, then appends own props @0x28 (from `ldr x1,[x19,#0x28]` at 0x102197A38). This upgrades the core.md "likely" verdict for GetProperties to confirmed.
- It rebuilds propsByName from unk118 and fills unk138 with the props whose `type->vt[+0x80]` returns true.
- It sets bit0 of 0x2C9 and releases the lock (`ldclralb #0x80`).

The builder has 11 callers, for example InitializeProperties 0x102197C6C (`mov w1,#0` then `ldr w8,[x20,#0x124]`) and sub_80/sub_88. **A class that has never been instantiated or reflected has an empty unk118 at the main menu.** The SDK dumper loop `for i < unk118.size` (Dump/Reflection-inl.hpp:93) therefore silently drops every such class.

**Recommendation for the live dumper:**
- Read **props @0x28** for each class and walk `parent @0x10`.
- Apply the 16-byte overriddenProps @0x38 entries yourself, or skip them, since they only change defaults or flags.
- This path is read-only and takes no lock.
- Avoid calling 0x10219DCE0 or GetProperties: both write to the class (the 0x2C9 flags and cache arrays).

**The rest of the CClass header matches the SDK on macOS:**
- parent @0x10, name @0x18 (slot +0x10 is `ldr x0,[x0,#0x18]`).
- size @0x68 and holderSize @0x6C. The ctor 0x102196F40 does `stp w22(size),wzr,[x19,#0x68]`.
- flags @0x70 and alignment @0x74. The ctor does `stp w21(flags),#4,[x19,#0x70]`. The alignment setter 0x102198100 stores `max(align,4)`.
- defaults Map @0x158 (keys @0x158, count @0x164, values @0x168, flag @0x178), per AssignDefaultValues.
- Spinlock @0x2C8 and flag byte @0x2C9 match the SDK's unk2C8/unk2C9.
- Flags: bit0 = isAbstract, from the GetClasses test `ldrb w8,[x8,#0x70]; tbnz #0`. bit1 = isNative: the native ctor passes `w3=2`, and the abstract wrapper 0x102196C80 does `orr w3,w3,#3`.

## 3. Enumerating all types: use the vtable (option a)

**The singleton.** `CRTTISystem::Get` 0x102188E8C:
- On first use it runs the ctor 0x102188634, guarded by 0x107D6A270, and registers the dtor 0x102188E74 with atexit.
- It returns `&0x107D6A288`. The ctor stores vptr **0x106FFBD70**.

**The vtable.** Its slots are at the SDK offsets 0x00..0x130. Then come **D1 @+0x138 (0x102188E74, the same function Get passes to `__cxa_atexit`) and D0 @+0x140**, so no slot before the destructor shifts. Checked slots:

| SDK slot | macOS fn | evidence |
|---|---|---|
| +0x00 GetType(CName) | 0x1021927A8 | flushes pending registrations (0x102191BB4), then looks the name up via 0x102192D08. That lookup takes the shared lock **@this+0x220**, searches map @+0x10 by CName, falls back to @+0x70 → @+0x40, and releases with `ldaddalb -1`. |
| +0x10 GetClass(CName) | 0x102192770 | `GetType()` then `vt[+0x28]()==2 ? t : null` |
| +0x40 GetNativeTypes(DynArray&) | 0x102193178 | copies every value (node+0x10) of the map @+0x40 into the array. **No lock and no flush.** |
| +0x60 GetEnums(DynArray&, bool scriptedOnly) | 0x102193E50 | flush, lock @+0x220, keeps types whose `vt[+0x28]()==5`, tests `ldrb [enum,#0x21]` when scriptedOnly is set |
| +0x70 GetClasses(CClass* isA, DynArray&, filter, bool inclAbstract) | 0x1021938DC | args x1..x4 match the SDK; flush, lock @+0x220, iterates map @+0x40, `vt[+0x28]()==2`, IsA 0x10219AC60 when isA is non-null, skips `flags@0x70 bit0` unless inclAbstract, calls the filter if set |

**Recommendation:** call `GetClasses(nullptr, out, nullptr, true)` and then `GetEnums(out, false)` through the vtable.

**Option (b), reading the maps directly:**
- The `types` map is @+0x10, with the same HashMap layout as the SDK: indexTable @0, size @8, capacity @0xC, nodes @0x10, stride @0x1C. A node is {next u32, hash u32 = hi32^lo32, key @8, value @0x10}.
- The type maps sit before any lock. The ctor zero-initialises six 0x30-byte maps at +0x10, +0x40, +0x70, +0xA0, +0xD0 and +0x100.
- However, the lock is at **+0x220** and a mutex is at **+0x228**, against the SDK's 0x208/0x210. So CRTTISystem's size and tail layout differ from the SDK (0x238), and +0x100 is a map where the SDK puts unkF8 at 0xF8.
- Read only +0x10 or +0x40 if you must use (b).

## 4. CBaseRTTIType vtable and ERTTIType values

**The base vtable 0x106FFDF40** (stored by the base ctor 0x1021AFCAC, `stp vptr,xzr,[x0]`):

| slot | content |
|---|---|
| +0x00, +0x08 | D1/D0 (0x1021AFCC0/0x1021AFCC4) |
| +0x10..+0x28 | four `___cxa_pure_virtual` binds (GetName, GetSize, GetAlignment, GetType) |
| +0x30 | first concrete slot 0x1021AFCD4 (GetTypeName, SDK +0x28) |

This means **SDK slot + 8 everywhere**. Three independent confirmations:
- AssignDefaultValues calls Assign at `vt+0x58`, where the SDK has 0x50.
- core.md found the same +8 shift on CClass.
- An SDK compiled with clang for macOS gets this layout automatically, provided the destructor is declared first, as it is.

**Concrete vtables** (slot +0x10 GetName / +0x18 GetSize / +0x20 GetAlignment / +0x28 GetType):

| kind | vtable | GetName | GetSize | GetAlign | GetType |
|---|---|---|---|---|---|
| Name (CName) | 0x106FFDC68 | static CName | 8 | 8 | **0** |
| Fundamental (e.g. float) | 0x106FFCD90 | static CName | 4 | 4 | **1** |
| Class | 0x106FFBB10 / 0x106FF00C0 | `ldr x0,[x0,#0x18]` | `ldr w0,[x0,#0x68]` | `ldr w0,[x0,#0x74]` | **2** |
| Array | 0x106FFC4B8 | `[x0,#0x18]` | 0x10 | 8 | **3** |
| Simple | 0x106FFD9E0 (and 9 others) | static | per type | per type | **4** |
| Enum | 0x106FFC2B8 | `[x0,#0x10]` | `ldrb [x0,#0x20]` | 1 | **5** |
| StaticArray | 0x106FFC708 | `[x0,#0x20]` | fn 0x1021A6F74 | inner->vt+0x20 | **6** |
| NativeArray | 0x106FFC5E0 | `[x0,#0x20]` | fn 0x1021A6790 | inner->vt+0x20 | **7** |
| Pointer | 0x106FFD470 | `[x0,#0x18]` | 8 | 8 | **8** |
| Handle | 0x106FFD568 | `[x0,#0x18]` | 0x10 | 8 | **9** |
| WeakHandle | 0x106FFD660 | `[x0,#0x18]` | 0x10 | 8 | **10** |
| ResourceReference | 0x106FFD758 | `[x0,#0x10]` | 0x18 | 8 | **11** |
| ResourceAsyncReference | 0x106FFD830 | `[x0,#0x10]` | 8 | 8 | **12** |
| BitField | 0x106FFBEC8 | `[x0,#0x10]` | `ldrb [x0,#0x20]` | 1 | **13** |
| LegacySingleChannelCurve | 0x106FF5D50 | `[x0,#0x10]` | 0x38 | 8 | **14** |
| ScriptReference | 0x106FFD908 | `[x0,#0x20]` | 0x28 | 8 | **15** |
| FixedArray | 0x106FFC830 | `[x0,#0x20]` | fn 0x1021A7E04 | inner->vt+0x20 | **16** |

- **ERTTIType on macOS is 0..16 in exactly the SDK order.** The game also compares GetType with 2 (GetClass/GetClasses) and 5 (GetEnums).
- **Use the virtual GetName.** The name field moves between kinds (+0x10, +0x18 or +0x20), so the dumper should not read a fixed name offset for non-class types.

## Dumper checklist (macOS)

**Types**
- `rtti = CRTTISystem_Get()` (0x102188E8C).
- `vt[+0x70](rtti, nullptr, &classes, nullptr, true)` and `vt[+0x60](rtti, &enums, false)`.

**Each class**
- `name @0x18`, `parent @0x10`, `size @0x68`, `align @0x74`, `flags @0x70`.
- Own props: `entries @0x28`, `size u32 @0x34`.

**Each prop**
- `type @0`, `name @8`, `valueOffset u32 @0x20`, `flags @0x28`. inValueHolder is bit 0x15, and scripted props live in the holder, not the instance.
- Type name and size: `type->vt[+0x10]()` and `type->vt[+0x18]()`. Alignment is `vt[+0x20]` and kind is `vt[+0x28]`.

**Do not use unk118 @0x118**: it is an empty cache until the class is first used.
