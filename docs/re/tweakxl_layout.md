# TweakXL memory-layout audit — macOS 2.3.1 arm64 (static only)

Binary: `Cyberpunk2077` (UUID A6656ADC-…; `.orig` copy has an identical `__TEXT`, md5-checked). All addresses are absolute.
Scope: every struct/container layout TweakXL (`cp2077-tweak-xl/src` + `lib/`) and the vendored SDK headers it inlines read or write.
The vendored SDK `include/` is byte-identical to `RED4ext.SDK/include` (`diff -rq` clean).

Verdicts: **match**, **MISMATCH** (macOS value given), **unknown**. "Startup" = the path TryLoad hook → ImportMetadata → EnsureRuntimeAccess → ApplyPatches → LoadTweaks.

## Summary table

| # | Item | Verdict | Startup? |
|---|---|---|---|
| 1 | TweakDB size 0x168, ctor 0x102B73DB8 | match | yes |
| 1a | +0x00 staticFlatDataBuffer (+0x08 u32 cap, +0x0C u32 align, +0x10 deleter obj) | match (ptr); SDK leaves +0x08 stale on upsize (benign) | yes |
| 1b | mutex00 @0x20 / mutex01 @0x21 (1-byte SharedSpinLock, macOS encoding) | match | yes |
| 1c | unk28 (0x158-byte obj) / unk30 (0xF8-byte obj) / unk38 bool=1 | match | TryLoad arg0 = `db->unk28` |
| 1d | flats SortedUniqueArray<TweakDBID> @0x40 (entries/cap/size/flags@0x50) | match | yes |
| 1e | recordsByID HashMap @0x58 | match | yes |
| 1f | recordsByType HashMap @0x88 | match | yes |
| 1g | queries Map @0xB8 | match (not used by TweakXL) | no |
| 1h | groups Map<TweakDBID,GroupTag(int8)> @0xE0 | match (not used by TweakXL) | no |
| 1i | defaultValues HashMap<CName,FlatValue*> @0x108 | match | yes (SDK SetFlatDataBuffer ForEach) |
| 1j | unk138 DynArray<CString> @0x138 | match (elem 0x20) | no |
| 1k | flatDataBuffer @0x148 / capacity u32 @0x150 / end @0x158 | match | yes |
| 1l | unk160 (uint8) | match as a byte; **semantics = generation counter**, not a flag | yes (EnsureRuntimeAccess) |
| 1m | unk164 (u32) | match (zeroed in ctor, no TweakXL use) | no |
| 2a | DynArray {ptr,cap,size}, allocator-in-ptr when cap 0, allocator after buffer | match | yes |
| 2b | SortedArray compare (hash, then length) / NotSorted bit 0 | match | yes |
| 2c | HashMap layout + NodeList + hash fns (TweakDBID, pointer FNV1a32, CName lo^hi) | match | yes |
| 2d | HashMap grow policy / NodeList::GetNextAvailNode | grow match; **SDK GetNextAvailNode differs** (no `size++` on last node) — SDK-side inserts only | no |
| 2e | Map {keys, values, flags@0x20} | match | no |
| 2f | CString (0x20; len@0x14, mode bits 30-31) | match | yes |
| 2g | Handle / RefCnt / WeakHandle; ISerializable ref @0x08 | match; SDK macOS `Handle(T*)` never reuses an existing RefCnt (game does) | yes (ExecuteTweaks) |
| 2h | IAllocator vtable (7 slots, no dtor) / AllocationResult in x0:x1 | match | yes |
| 2i | TweakDBID (hash, len, 3-byte BE offset) + CRC32 + Derive | match | yes |
| 2j | FlatValue object layout ([vft][pad?][data], 8/16 alignment) | match | yes |
| 2k | FlatValue vtable: dtor pair 0/1, GetValue 28 (0xE0), GetDataPtr 30 (0xF0) | match | yes |
| 2l | FlatValue getters, slots 2..27 order | **MISMATCH** (reverse order on macOS) — benign today | no |
| 2m | FlatValue::GetTypeName (slot 29, 0xE8) signature | **MISMATCH** — game: `CName GetTypeName()` returned in x0 | latent |
| 2n | GroupTag int8 | match | no |
| 3 | StatsDataSystem 0xD8 / 0xE8 / 0xFC, StatParams stride 12; StatRecord::EnumValue @0xD8 | match | no (session start) |
| 4a | gamedataTweakDBRecord: recordID @0x40, size 0x48, props 12-byte entries from 0x48 | match | yes |
| 4b | ISerializable/IScriptable vtable (Itanium): GetNativeType 0, GetType 1 (nativeType @0x30), GetAllocator 2, dtors 3/4, CanBeDestructed 0xD8, GetTweakBaseHash 0x118 | match | yes |
| 4c | CClass layout (parent 0x10, name 0x18, props 0x28, funcs 0x48, staticFuncs 0x58, size 0x68, flags 0x70, align 0x74, …0x158) | match | yes |
| 4d | CClass vtable (GetName 0x10, GetSize 0x18, GetAlignment 0x20, GetType 0x28, Construct 0x40, Destruct 0x48, IsEqual 0x50, Assign 0x58, Construct/DestructCls 0xE0/0xE8) | match | yes |
| 4e | CBaseFunction (fullName 0x08, shortName 0x10, returnType 0x18, params 0x28, flags 0xA8); CProperty (type 0x00, valueOffset 0x20) | match (shortName/fullName order: likely, see note) | yes |
| 4f | CRTTIArrayType: innerType @0x10, name @0x18; GetInnerType 0xC8, GetLength 0xD8 | match for fields used; **object is 0x20 bytes on macOS, SDK declares 0x40** | yes |
| 4g | CRTTIWeakHandleType innerType @0x10 (0x28 bytes) | match | yes |
| 4h | CEnum hashList @0x28 / valueList @0x38 / actualSize @0x20 | match | no (stats) |
| 4i | CRTTISystem slots GetType 0x00 / GetClass 0x10 / GetEnum 0x18 | match | yes |
| 4j | CClass flags.isAbstract (bit 0 @0x70), CBaseFunction flags.hasUndefinedBody (bit 5 @0xA8) | **unknown** (offsets match, bit meaning unverified) | yes (ExecuteTweaks) |
| 4k | Record-class native function order that `CollectRecordInfo` relies on (skips +1..+4 helper funcs) | **unknown** (registered at runtime; not statically recoverable cheaply) | yes (ApplyPatches → CloneRecord) |

TweakXL defines no `RawVFunc` and indexes no vtable by hand. Every virtual call goes through the SDK declarations, which clang lays out under Itanium. So every slot depends only on the SDK *declaration order* matching the game, and the rows above check exactly that.

---

## 1. RED4ext::TweakDB

**Ctor `0x102B73DB8`** (called from the creator `0x102B73B50` after `operator new(0x168)` at `0x102B73BC0`; the singleton lives at `0x1080C92D0`, read by `TweakDB::Get` `0x102B73C7C`):
- `stp q0,q0,[x0]` zeroes +0x00..+0x1F; `strh wzr,[x0,#0x20]` covers the two 1-byte locks.
- +0x28 is `new(0x158)` (344), +0x30 is `new(0xF8)` (248), and `strb #1,[+0x38]`.
- +0x40: DynArray init `0x1000285E0` (stores the allocator vptr in entries, cap=0), then `stur d0,[+0x4C]` (size and flags).
- +0x58 and +0x88: 32 bytes zeroed, `d8=0x00000000FFFFFFFF` stored at +0x78/+0xA8 (`nextIdx=-1`, `size=0`), allocator vptr at +0x80/+0xB0.
- +0xB8 and +0xE0: two DynArrays plus flags at +0xD8/+0x100. +0x108: HashMap pattern (+0x128, +0x130).
- +0x138: DynArray, then `str xzr,[+0x148]; str wzr,[+0x150]; str xzr,[+0x158]; strb wzr,[+0x160]; str wzr,[+0x164]`.

The clear routine `0x102B73FA8` confirms the element sizes: queries values 0x10 (`uxtw #4`), unk138 elements 0x20 (`lsl #5`), defaultValues index table reset to -1 over `cap@+0x114`.

- **+0x00 (staticFlatDataBuffer).** The flats loader `0x102B15EC0` allocates the value buffer from `PoolGMPL_TDB_Data::AllocateAligned` (GOT `0x106E21D08`), then bzeroes it. It moves a `{ptr, u32 cap, u32 align, deleter}` descriptor into db+0x00..0x1F (`0x1009148CC`). It then copies `[db]` into +0x148, `cap` into +0x150 (32-bit `str w24`), and `[db]` into +0x158 (`0x102B161D8..E4`). Game readers use **db+0x00** as the base: the flat lookup tail `0x102B76800`, the record getter `0x100A25FC8`, the getter override `0x10096C704` (`ldr w8,[x0]`). The SDK `SetFlatDataBuffer` updates +0x00/+0x148/+0x150/+0x158 but not +0x08 (cap) or the deleter. That is benign: same pool, and no capacity reader was found.
- **mutex00 @0x20.** The flat resolver `0x100A272EC` takes it shared (`0x100002098`) for the lookup and exclusive (`0x1000020C0`) when it lazily creates a default value. **mutex01 @0x21**: AddRecord `0x102B74408` takes it exclusive, GetRecord `0x102B745D0` shared, and the records loader `0x102B16ABC` uses it too.
- **flats @0x40.** The lookup `0x102B76708` → lower_bound `0x102B139B8` sorts when `[+0x10]&1` (NotSorted) is set, then clears the bit. Its comparator (`0x102B13AB0..C8`) is `elem.hash < key.hash || (elem.hash == key.hash && elem.len < key.len)`, which is exactly SDK `TweakDBID::operator<`. The loader shrinks the array with `DynArray_Realloc(+0x40, size, 8, 4, null)` and sorts with `0x102B467BC`.
- **recordsByID @0x58** (GetRecord `0x102B745D0`): `size [+0x60]`, `cap [+0x64]`, `index [+0x58]`, `nodes [+0x68]`, `stride [+0x74]`. The bucket is `(u32)id % cap`. A node holds `next@0`, `hashed@4`, `key@8` (compared on the low 40 bits), and a `Handle@0x10`.
- **recordsByType @0x88** (`0x102B746A4`): FNV-1a32 over the 8 key bytes (basis `0x811C9DC5`, prime `0x01000193`), with `size [+0x90]`, `cap [+0x94]`, `nodes [+0x98]`, `stride [+0xA4]`, key compared on all 64 bits, value at +0x10. A miss returns a static empty DynArray (`0x1080C93E0`).
- **queries/groups.** Queries loader `0x102B16D0C`: keys at +0xB8 (size +0xC4), values at +0xC8 (size +0xD4), flags at +0xD8. Groups loader `0x102B172FC`: keys at +0xE0 (realloc 8/align 4), values at +0xF0 with **1-byte** elements (`DynArray_Realloc(+0xF0, n, 1, 1)`, `strb`), flags at +0x100.
- **defaultValues @0x108** (`0x100A273C0`): the hash is `lo32^hi32` of the CName, index at +0x108, `size +0x110`, `cap +0x114`, `nodes +0x118`, `stride +0x124`, node `key@8`, `FlatValue*@0x10`. The reserve `0x10096CA74` uses stride 0x18 (`mov w3,#0x18`), which equals the SDK `sizeof(Node<CName,FlatValue*>)`. A missing default is appended at `AlignUp(+0x158, 8)` under the mutex00 writer lock.
- **unk160.** `TweakDB_Load 0x102B75650`: `ldrb; add #1; strb` after a successful TryLoad, so it is a **uint8 generation counter**. The record resolver `0x100A273A4` copies `db->unk160` into each property entry at +9. The record getter `0x100A25F64..8C` compares the entry's generation with `0x102B743C0` (`ldrb [db,#0x160]`) and re-resolves the flat by name when they differ.
  - TweakXL's `unk160 = 0` is a memory-safe 1-byte store.
  - It does not "enable runtime access". It only decides which cached entries get re-resolved. Records created inside TryLoad are tagged 0 before Load increments the counter.
  - Correctness still depends on TweakXL calling `UpdateRecord` for the records it changes, which it does. Incrementing the counter instead would invalidate every cached entry. That is an option, not required.
- **unk164.** Only the ctor (`0x102B73F8C`) touches it in the TweakDB code range.

**TryLoad `0x102B7CC9C`** is called from Load as `TryLoad(db->unk28, db, CString* path, errlog*)` (`0x102B7560C..1C`), which matches TweakXL's `bool(void*, TweakDB*, CString&, void*)`. It reads the blob header section offsets at +0x10/+0x14/+0x18/+0x1C and calls the four loaders `0x102B15EC0` (flats), `0x102B16A48` (records; it calls CreateRecord `0x1026B8DB8` at `0x102B16B64`), `0x102B16D0C` (queries) and `0x102B172FC` (groups).

**CreateRecord `0x1026B8DB8`** has the signature `(db, w1 hash, x2 id)`:
- It dispatches on `hash & 0x1F` to a per-type factory (for example `0x1027052AC`).
- The factory runs the record ctor. Record ctors read flats through the **global** `TweakDB::Get()`, not through the db argument.
- It wraps the record in a Handle (`0x102104788`).
- It inserts through `0x102B74408(db, id, type, &handle)`, which touches only +0x21, +0x58 and +0x88.

This is why the SDK `UpdateRecord` "fake TweakDB" trick works on macOS. The game's HashMap reserve (`0x100CDAEF8`) calls only allocator slot 1 (AllocAligned, through `0x10001AFAC`) and slot 4 (Free, through `0x10001AFD0`), both of which the SDK `FakeAllocator` implements. The record Assign is CClass slot 11 (0x58). On the record class vtable `0x107050CC0`, slot 11 `0x1027063B8` copies `recordID@0x40` and each 12-byte entry.

**Flat buffer headroom** (for the SDK's unchecked `CreateFlatValue`): parsing `r6/cache/tweakdb_ep1.bin` gives about 4.29 MB of flat values (22 types). The first SDK upsize goes to 0xFFFFFF, which leaves about 12 MB of headroom.

## 2. Containers and algorithms

- **DynArray.** The game ctor `0x1000285E0` stores the allocator vptr in `entries` with cap 0, which matches the SDK `DynArray(IAllocator*)`. `DynArray_Realloc 0x1000286E8`:
  - When `entries==null` it fetches the default allocator (`0x1000224A4`), so the SDK's null-allocator locals are safe.
  - It keeps the allocator at `buf + AlignUp(cap*elem, 8)`, which matches SDK `GetAllocator()` (SortedArray omits the AlignUp, but that is fine for 8-byte TweakDBID).
  - With a null move callback it uses slot 3 (ReallocAligned).
  - The game passes alignment 4 for TweakDBID arrays where the SDK passes 8. That is benign (stricter).
- **IAllocator.** Game vtables `0x1070D3370`, `0x1070D3448` and `0x1070D3298` have 7 slots: Alloc(size) `0x102B03F0C`, AllocAligned(size, align) `0x102B04020`, Realloc, ReallocAligned, Free(Block&) `0x102B043F4`, sub_28, GetHandle `0x102B04494` (`ldr w0,[pool,#0x20]`). There is no destructor slot, and the `{ptr,size}` Block comes back in x0:x1, the same as the SDK.
- **HashMap.** NodeList init `0x10091838C` sets `{nodes, cap=bytes/stride, stride, nextIdx = nodes ? 0 : -1, size 0}` at 0/8/0xC/0x10/0x14. Emplace `0x102B46F14` grows to `max(size + size/2, 4)` (`0x102B46FBC`), the same as the SDK. A reserve allocates `cap*(stride+4)` with the index table after the nodes and fills it with 0xFF (`0x102B47098..EC`), the same as SDK `Reserve`.
  - **Difference:** game `GetNextAvailNode 0x1009183CC` always does `size++`, setting `nextIdx=-1` when full. The SDK does not increment `size` when it hands out the last free node. This only matters for SDK-side `Emplace` into game maps, which TweakXL does not do; it only calls `Get`/`ForEach` on game maps and `dtor`/`Clear` on the fake maps.
- **Hash functions:**
  - TweakDBID: low 32 bits (`0x102B74604`).
  - Pointer: FNV-1a32 over 8 bytes (`0x102B746BC..24`).
  - CName: `lo ^ hi` (`0x100A273FC`).
  - CName itself: FNV-1a64 (`"gamedataStatType"` gives `0x743066319F27468D`, which is the constant at `0x103A939E0`).
- **TweakDBID.** The getter override `0x10096C70C..18` stores the offset into bytes 5..7 big-endian, and readers decode `b5<<16 | b6<<8 | b7` (`0x100A25FBC..D8`). The CRC is at `0x1034535C0`: its table at `0x106C0BC80` equals the standard reflected CRC32, the input is `crc = ~seed` with `~crc` as the result, and the length byte is `(base.len + n) & 0xFF`. All of this matches SDK `operator+`/`CRC32`.
- **CString.** The dtor `0x100029228` and reserve `0x10002C524` keep the length at +0x14 with mode = bits 30–31 (0 is inline, 2 is non-owning). The inline capacity is 19. This matches the SDK `IsInline`/`c_str`/`Length`.
- **Handle/RefCnt.** The game Handle ctor `0x102104788`:
  - It first tries to lock the object's existing self weak-ref at obj+0x08/+0x10 (`0x102186638`).
  - Otherwise it allocates an 8-byte RefCnt `{1,1}` from `PoolRefCount::Allocate` (GOT `0x106E22A80`) and sets obj+0x08 through `0x1021868F8` (weak+1).
  - It destroys in this order: DecWeakRef `0x1021048C4` (verified hash), `CanBeDestructed` at vtable+0xD8, `GetAllocator` at +0x10, complete dtor at +0x18, then allocator Free.

  The SDK macOS `Handle(T*)` always allocates a new RefCnt and does not reuse an existing one. It is equivalent for a freshly created instance, which is TweakXL's only use (`TweakExecutor` → `CreateInstance`).
- **FlatValue objects.** The loader (`0x102B143E0..F8`) does `end = AlignUp(end, 8)`, runs the base ctor `0x102B73D9C`, stores the vft and data, and sets `end += 0x10`. Quaternion aligns to 16 (`0x102B15394`). This matches the SDK `CreateFlatValue` and TweakXL's `SyncBufferData` stride, `AlignUp(8 + size, max(8, align))`.
- **FlatValue vtable.** The base vtable is at `0x1070D5AF0` with 31 slots: slots 0/1 are `brk` dtors, slots 2..27 are 26 `return false` getters (`0x102B73CCC..D94`), and slots 28..30 are pure (bind). The 26 derived vtables were each identified from their `GetTypeName` CName string. Each overrides exactly one getter:

  | slot | 2 | 3 | 4 | 6 | 8 | 10 | 14 | 24 | 26 |
  |---|---|---|---|---|---|---|---|---|---|
  | type | Int32 | array:Int32 | Float | String | Bool | CName | LocKey | Quaternion (data at +0x10, own GetDataPtr `0x100EDE494`) | TweakDBID |

  So **the macOS order is the exact reverse of the SDK's** (the SDK lists array_TweakDBID first; MSVC reverses overload groups). This is benign today, because every SDK `FlatValueImpl` override has the same body (returns true and writes `offset + offsetof(data)`) and TweakXL never calls a getter by name. It would break if the SDK ever gave these overrides type-specific bodies. Slots 28 GetValue (`0x10096C72C`: returns `{rtti->GetType(name), this+8}` in x0:x1), 29 and 30 GetDataPtr (`0x100643F9C`: `add x0,x0,#8`) sit in the same position in the game and the SDK.
- **GetTypeName — MISMATCH.** The game implementation (`0x10096C7E0`, `0x100988914`, …) takes only `this` and returns the CName **in x0** (`ldr x0,[x8]; ret`). The SDK declares `CName* GetTypeName(CName* aName)` and its impl writes `*aName` through x1. If the game ever calls slot 29 on an SDK-created flat, the SDK writes 8 bytes through whatever is in x1.
  - A scan of every `ldr xN,[xM,#0xE8]` + `blr` site inside functions that call `TweakDB::Get` or the flat lookup found only one, at `0x102FF83F4`, and it is unrelated (3 arguments).
  - So this is a latent mismatch. Fix: under `__APPLE__`, declare `virtual CName GetTypeName() = 0;` and return `N`.

## 3. Stats

- `InitializeRecords 0x103A939A0`: `+0xD8` is a `DynArray<TweakDBID>` (cap at +0xE0, size at +0xE4; realloc elem 8, align 4). It fills 1709 entries from `"BaseStats." + CEnum value name`, using `rtti` slot 0x18 = GetEnum.
- `GetStatFlags 0x103A93EF0` and `GetStatRange 0x103A9472C`: they take the reader lock at `+0xFC` (`0x100002098`, released with `ldaddalb -1`), index `[+0xE8] + stat*12`, read `flags` at +8, and range with `ldp s0,s1,[x8]`. Their `cmp w1,#0x6AC; b.hi` comes before the prologue, which is why TweakXL must hook them for stats beyond 1709.
- **Raw::StatRecord::EnumValue @0xD8.** gamedataStat_Record is registered at `0x10287F8C8` (size 0x140, CClass vtable `0x107083A68`). In its default ctor `0x102878058` the property entries run …0xC0, 0xCC, then 0xDC, leaving a 4-byte gap at 0xD8. The id-ctor `0x1028782D0` stores `str w0,[x19,#0xD8]` from `0x10271EF3C(hash("gamedataStatType"), enumName)`. Assign `0x10287F9E8` copies `w[0xD8]` as a plain u32. This is a match.

## 4. RTTI and vtables (Itanium shift confirmed everywhere)

- **Record vtable** `0x10704E968` (base `0x1070D59C0`):
  - Slot 0 GetNativeType (static CClass*), slot 1 GetType (`ldr x8,[x0,#0x30]`, else slot 0), slot 2 GetAllocator.
  - Slots 3/4 are the complete and deleting dtors (`0x102706070`, `0x102706080`).
  - Slot 27 (0xD8) CanBeDestructed (`mov w0,#1`), slot 34 (0x110) sub_108 (`ret`).
  - **Slot 35 (0x118) GetTweakBaseHash** is `0x1026EDC7C`: `mov w0,#0x8A8607A0`, the same hash its CreateRecord factory dispatches on.
  - This matches SDK `ISerializable`/`IScriptable`/`TweakDBRecord` under Itanium. The base record ctor `0x102B73AC0` stores `recordID` at +0x40, and the first property entry is at +0x48 with a 12-byte stride (`0x1026EDBF8/24/50`).
- **CClass.**
  - The ctor `0x102196F40` writes: vptr, +0x10 parent=0, +0x18 name, +0x20, DynArrays at 0x28/0x38/0x48/0x58, +0x68 size, +0x6C 0, +0x70 flags, +0x74 align=4, HashMaps at 0x78/0xA8, 0xD8/0xE0, HashMap at 0xE8, DynArrays at 0x118/0x128/0x138/0x148, and the Map at 0x158. Every field matches the SDK.
  - Vtable `0x106E8FA00`:
    - Slots 0/1: dtors.
    - Slots 2–5 (0x10..0x28): GetName (`[0x18]`), GetSize (`[0x68]`), GetAlignment (`[0x74]`), GetType (=2).
    - Slots 7–9 (0x38..0x48): GetComputedName (`[0x20]`), Construct (calls `vtbl+0xE0`), Destruct (calls `vtbl+0xE8`).
    - Slots 10–12 (0x50..0x60): IsEqual, Assign, Move (calls `vtbl+0x58`).
  - A scan found 8959 vtables with this shape.
- **CBaseFunction.** The ctor `0x1021739E8` stores `[0]=vt`, `[8]=x1`, `[0x10]=x2`, zeroes 0x18/0x20, DynArrays at 0x28/0x38, and a HashMap at 0x48 (nextIdx at +0x68). `InternalExecute 0x102173120` tests `[+0xA8]` bit 0 and reads `[+0xAC]`. The param setup `0x102172880` walks `[f+0x28]` (size `[f+0x34]`), takes `prop->type` at +0x00 and `prop->valueOffset` at +0x20, and calls `type` vtbl+0x40 (Construct) and +0x28 (GetType, compared with 3 = Array).
  - **shortName/fullName order is only "likely".** The ctor stores its second name argument at +0x10. For native functions both arguments are the same CName (example caller `0x100CA9684`: `mov x2,x1`), so TweakXL's `func->shortName` is safe for native record getters either way.
- **CRTTIArrayType.** The factory for `"array:"` is `0x1021959B8` (registered at `0x102191AB4`). It does `new(0x20)`, then ctor `0x1021A53B8`: vptr `0x106FFC4B8`, innerType at +0x10, name at +0x18 (inner name with the `array:` prefix).
  - **The object is 0x20 bytes. The SDK declares parent/unk28/unk30/unk38 out to 0x40, and those fields do not exist on macOS.** TweakXL only reads `innerType` and the virtuals, so this is benign. Nothing may read or write SDK fields at offset 0x20 or beyond.
  - Vtable: GetName `[0x18]`, GetSize 0x10, GetAlignment 8, GetType 3, slot 25 (0xC8) GetInnerType `[0x10]`, slot 26 returns 1, slot 27 (0xD8) GetLength `[arr+0xC]`, slot 28 GetMaxLength -1, slots 29/30 GetElement.
- **CRTTIWeakHandleType.** The factory `0x102195E00` does `new(0x28)`, then ctor `0x1021AE058`: inner at +0x10, name at +0x18, computedName at +0x20. Vtable `0x106FFD660` has GetType 10 and GetInnerType at slot 25 (`[0x10]`). This matches the SDK.
- **CEnum.** Value→name `0x1021A37CC`: count is `[e+0x34]` (the size of hashList at 0x28), values are `int64[e+0x38]`, names are `CName[e+0x28]`, and `actualSize` is at `[e+0x20]` (`0x1021A3838`). This matches RedLib `EnumDescriptor` HasOption/AddOption.
- **CRTTISystem.** The flat GetValue calls `rtti` vtbl+0x00 (GetType). InitializeRecords calls vtbl+0x18 (GetEnum). The earlier audit already established GetClass at +0x10.
- **Unknown, startup-relevant:**
  1. **Function-order assumption.** `CollectRecordInfo` assumes each record class's `funcs` lists a getter followed by fixed helper functions (+1 Handle, +2/+3/+4 Count/Item/ItemHandle/Contains). That order is set at runtime registration, so it cannot be confirmed statically. If it were wrong, the prop types would be wrong. That means type-confused flats, not a direct overwrite.
  2. **Flag bit meanings.** `CClass.flags.isAbstract` (bit 0 of +0x70) and `CBaseFunction.flags.hasUndefinedBody` (bit 5 of +0xA8): the offsets are confirmed, but the bit meanings are not.

## Other notes (not macOS-specific)

- **`FlatValueImpl` always returns true.** Every `GetValueOffset_*` in the SDK returns true, while the game's return true only for their own type. The game's type check (`0x100A27368` → fallback to the default) therefore accepts any SDK-created flat.
- **Upsized buffer padding.** The SDK `UpsizeFlatDataBuffer` does not zero the new tail. The game bzeroes its buffer. TweakXL's `SyncBufferData` treats a zero qword as Quaternion padding. A non-zero garbage pad before an SDK-created Quaternion would be dispatched as a vtable. This is safe only if the 16 MB pool block comes back zeroed, which is likely for a fresh large allocation but not guaranteed. Fix: `memset` the tail after the `memcpy`.
- **MetadataImporter overflow.** It reads `propNameLen` (up to 255) into `char propName[254]`, so a crafted file can cause a 1-byte stack overflow.

## Addendum (2026-10-07): flag bits confirmed live
The live RTTI dump confirms the `CClass` flags at `+0x70`:
- **Bit 0 is `isAbstract`.** It is set on ScriptableTweak, TweakXL, ISerializable and CResource, which are declared abstract. It is clear on gameObject, entEntity and PlayerPuppet.
- **Bit 1 is `isNative`.** It is clear on the scripted PlayerPuppet.

`hasUndefinedBody` (`+0xA8` bit 5) is not in the dump. TweakXL's scriptable-tweak path selects `OnApply` by that bit and ran correctly in game: `tweakxl_scriptable_tweak` passed in `runs/20261007-090912-tweakxl`.
The function-order guard in `CollectRecordInfo` logged no errors in that run.
