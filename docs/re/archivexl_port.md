# RE group "archivexl_port": hook targets for the ArchiveXL macOS port (macOS 2.3.1 arm64)

Static analysis of the Steam `Cyberpunk2077.orig` (UUID A6656ADC). The game was not launched. Absolute addresses use
image base 0x100000000. Every address below is an `LC_FUNCTION_STARTS` entry (checked with `xcrun dyld_info
-function_starts`), and its first instruction is not PC-relative.

These entries replace functions that the earlier groups found inlined or unsafe to patch on macOS. Hash names are new
where the signature differs from the Windows function that the old hash named.

| name | hash | seg:off (absolute) | verdict | arm64 signature |
|---|---|---|---|---|
| GarmentAssembler_ChangeItem | 1833321597 (new) | 1:0x36F87E4 (0x1036F87E4) | confirmed | `bool(GarmentItemAggregator* x0, WeakHandle<Entity>& x1, ChangeRequest& x2)` |
| GarmentAssembler_ChangeCustomItem | 3778698806 (new) | 1:0x36F890C (0x1036F890C) | confirmed | `bool(GarmentItemAggregator* x0, WeakHandle<Entity>& x1, ChangeCustomRequest& x2)` |
| TPPRepresentationComponent_OnItemEquipped | 4010810747 | 1:0x35A6174 (0x1035A6174) | confirmed | `void(TPPRepresentationComponent* x0, TweakDBID item x1, TweakDBID slot x2)` |
| TPPRepresentationComponent_OnItemUnequipped | 1933319146 | 1:0x35A56DC (0x1035A56DC) | confirmed | `void(TPPRepresentationComponent* x0, TweakDBID item x1, TweakDBID slot x2)` |
| TPPRepresentationComponent_UnregisterAffectedItem | 4029647147 (new) | 1:0x35A6654 (0x1035A6654) | confirmed | `void(TPPRepresentationComponent* x0, TweakDBID item x1)` |
| MappinResource_GetMappinData | 1231151050 (new) | 1:0x429EED0 (0x10429EED0) | confirmed | `CookedMappinData*(gameMappinResource* x0, uint32 hash w1)` |
| PointOfInterestMappinResource_GetMappinData | 3428782773 (new) | 1:0x42BE574 (0x1042BE574) | confirmed | `CookedPointOfInterestMappinData*(gamePointOfInterestMappinResource* x0, uint32 hash w1)` |

## Evidence

**GarmentAssembler_ChangeItem 0x1036F87E4 / ChangeCustomItem 0x1036F890C**
- pass2.md already identified both as the live tracker-level wrappers into which the state-level ChangeItem
  (0x1036F887C) and ChangeCustomItem (0x1036F89A4) are inlined; those state-level copies have no callers.
- Callers (B/BL index): 0x1036F87E4 has one, `bl` at 0x1036FDEE8; 0x1036F890C has one, `bl` at 0x1036FDFF8. Both are
  in the ItemFactoryAppearanceChangeRequest step 0x1036FDDD4.
- The aggregator op shape matches the verified GarmentAssembler_RemoveItem (0x1036F8744): `FindState(aggr, x1)` into a
  0x18-byte stack slot, then the state operation on the request in x2.

**TPPRepresentationComponent_OnItemEquipped 0x1035A6174 / OnItemUnequipped 0x1035A56DC**
- The slot listener vtable 0x1071D5A20 (allocated by TPPRepresentationComponent::OnAttach 0x1035A0604) dispatches
  through two thunks:
  - 0x1035A762C: `ldr x0,[x0,#0x40]` (the component), `ldr x1,[x1]` (the item's TweakDBID), `b 0x1035A6174`.
  - 0x1035A7638: same, `b 0x1035A56DC`.
  - x2 (the slot TweakDBID) passes through unchanged.
- Both bodies start with the inlined IsAffectedSlot check: `and x8,x2,#0xffffffffff`, then compare with the Head and
  Eyes TweakDBIDs at 0x108768490/0x108768498 (`cmp`/`ccmp`), at 0x1035A61A8 and 0x1035A56F8.
- 0x1035A6174 then reads the owner (`[x19+0x50]`), IsA-checks it, and queries the transaction system
  (`vtbl+0x428`, slot in x2) for the item object. It is the only path besides OnAttach that leads to
  RegisterAffectedItem 0x1035A0E10, so it is the **equip** handler.
- 0x1035A56DC calls 0x1035A6654(component, item) on that branch, so it is the **unequip** handler.
- Callers: 0x1035A6174 only via thunk 0x1035A762C; 0x1035A56DC via thunk 0x1035A7638 and directly from 0x10359E850.
- appearance.md labels these two the other way round in its IsAffectedSlot note; the call targets above settle it.
- The old shared value 1:0x37DF568 is refuted (it is not either handler).

**TPPRepresentationComponent_UnregisterAffectedItem 0x1035A6654**
- appearance.md calls it the 2-argument unregister twin of RegisterAffectedItem.
- Its only caller is the unequip handler (`bl` at 0x1035A5724, with x0 = component, x1 = item).
- It has the same recursive-lock prologue as RegisterAffectedItem: it fetches the thread ID from the TLS getters at
  0x106E43B70/0x106E43B78, then `ldaddalh` on `+0x124`, the owner at `+0x120` and the lock byte at `+0x127`.

**MappinResource_GetMappinData 0x10429EED0 / PointOfInterestMappinResource_GetMappinData 0x1042BE574**
- world.md: MappinSystem_GetMappinData (0x1042A3E38) and GetPoiData (0x1042A3E68) are 16-byte stubs
  `ldr x0,[x0,#0x58|0x68]; cbz; b <lookup>; ret`. A patch there would overwrite the next function, so these
  resource-level lookups are the hook targets instead.
- Both bodies are identical leaf scans: `ldr x8,[x0,#0x40]` (cookedData entries), `ldr w9,[x0,#0x4c]` (size),
  stride 0x20, compare the first u32 with w1, and return the entry pointer or null.
- Callers of 0x10429EED0: the stub 0x1042A3E40 and GetMappinPosition 0x1042B2748 (system vtable +0x260), which loads
  `[system+0x58]` before the call. Caller of 0x1042BE574: the stub 0x1042A3E70 only.
- The first instruction is `ldr`, so a 4-byte near patch is safe. The functions are 0x48 bytes.

## Not mapped (fail closed)

These hashes stay unverified. ArchiveXL's macOS build no longer references them:
- ResourceToken_DestructUnk38: inlined (resources.md). The SDK now releases the reference inline on macOS
  (`Detail::ReleaseUnk38`) and deliberately keeps the last one.
- CharacterCustomizationHelper_GetHairColor: inlined (charcustom.md). ArchiveXL reimplements it with system vtable
  +0x1F8 (0x102458ECC, `mov x20, x8` sret, x1 = isMale) and state vtable +0x240 (0x1024536D4, scan of `+0xB0`).
- AppearanceChanger_GetSuffixValue: inlined into GetSuffixes 0x10370D924. Camera: the result starts as "TPP"
  (0x10370DD80, string 0x106C6DED7), and with a TPPRepresentationComponent present it is "TPP" when
  `0x1035A1C18(comp)` returns true (mode u32 at `+0x188`, `ldapr`, in 2..4) and "FPP" otherwise (0x10370DDB4).
- AISpotPersistentDataArray_Reserve: inlined (world.md); rebuilt from DynArray_Realloc and the exported move callback.
- ResourceLoader_OnUpdate: unknown (resources.md); ArchiveXL's hot reload is disabled on macOS.
- TPPRepresentationComponent_IsAffectedSlot, GarmentAssemblerState_ChangeItem/ChangeCustomItem: replaced by the
  entries above.

## Other macOS ABI findings used by the port (no DB change)

- **IJournalManager vtable 0x106FA5A90**: +0x200 (0x101EB2F70) and +0x210 (0x101EB2F88) copy the tracked quest/POI
  Handle (`this+0x128`/`+0x138`) to `[x8]`; +0x228 (0x101EB3300) tail-calls a lookup that dereferences x1 as a path,
  not a hash; +0x2A8 (0x101EB5A38) stores the Handle in x1 at `+0x138`. The by-hash lookup ArchiveXL uses on Windows
  (MSVC 0x220) is not identified on macOS.
- **worldNodeInstanceRegistry vtable 0x10719FA60** +0x198 (0x1033425AC): FindNode returns the Handle through x8
  (`mov x19, x8`), x1 = node ID.
- **gameItemObject vtable 0x1071FA570** +0x288 (0x10373A494): `ldr x0,[x0,#0x50]; ret` returns the appearance CName
  in x0.
- **entMeshComponent vtable 0x106ECE998**: +0x268 (0x100C685FC) LoadResource(this, JobQueue& x1);
  +0x288 (0x100C699AC) RefreshAppearance(this).
- **questQuestsSystem vtable 0x107148E60** +0x248 (0x102EFB134): ForceStartNode(this, const QuestNodeKey& x1,
  sockets x2); it hashes `[x1]` into the map at `+0x78` under the lock at `+0x60`.
- **gameuiCharacterCustomizationSystem InitializeAppOption/MorphOption**: before the lookup, the game sorts the state
  container if bit 0 of `+0x20` is set (insertion sort on u64 keys at `+0`, moving the values at `+0x10` in step;
  0x102464F34, 0x102465334). The value is not read afterwards, only whether the key exists.
- **worldRuntimeSystemWorldStreaming**: the StreamingWorld Handle is at `+0x270` on macOS too (getter 0x10341FDFC is
  `add x0, x0, #0x270`). The system pointer is RuntimeScene `+0x1B0` (index 27), as RedLib's mapping assumes.
- **ResourceDepot (ResourceGameDepot)**: ctor 0x103ED9578 and dtor 0x103ED9A00 give the macOS layout used in
  ResourceDepot.hpp: second vptr `+0x08`, groups `+0x10` (stride 0x38, scope at `+0x30`), sort flag `+0x20`,
  CString arrays `+0x28`/`+0x38`, rootPath `+0x48`, 0x140-byte entries `+0x68`, lock byte `+0x78`.
- **DeferredDataBuffer::LoadAsync 0x10226258C / ObjectPackageExtractor::ExtractAsync 0x102150A60**: only `[x8+8]` is
  written (JobHandle move 0x1009D4874, `ldr x8,[x1]; str x8,[x0]; str xzr,[x1]`); `[x8]` is left untouched.
- **CEnum (vtable 0x106FFC2B8)**: Unserialize +0x68 = 0x1021A39B0, ToString +0x70 = 0x1021A3BC0,
  FromString +0x78 = 0x1021A3D4C. FromString takes the string as a **StringView by value** in x2/x3
  (`stp x2, x3, [sp]` at 0x1021A3D64), not `const CString&`. The SDK's CEnum overrides are therefore not safe on
  macOS; CEnum_ToString/FromString/Unserialize and the CBaseRTTIType_sub_80..sub_A0 base slots (0x1021AFD4C,
  0x1021AFE0C, 0x1021AFED4, 0x1021B007C, 0x1021B01E0, shared by the base vtable 0x106FFDF40 and the enum vtable) stay
  unverified until that signature is fixed.
