# RE group "appearance": ArchiveXL appearance hooks (macOS 2.3.1 arm64)

All addresses were checked statically against `Cyberpunk2077.orig`. Every "new" address is a function start that `LC_FUNCTION_STARTS` lists, and none is a static initializer.

The helper scripts are in `scratchpad/app/` (`r.py` plus the xref, pointer, constant and ADR indexes).

The C++ vtables came from each RTTI class registration:
- `TTypedClass` vtable slot 28 holds the placement ctor, and that ctor stores the C++ vtable.
- Itanium layout: slot 3 and slot 4 are the destructors, so `PostLoad` is slot 6 (`+0x30`).
- `IComponent::OnAttach` is slot 49 (`+0x188`). Its base implementation sets bit `0x2` of the flags at `+0x88`.

| name | hash | old | new seg:off (absolute) | verdict | arm64 signature vs plugin declaration |
|---|---|---|---|---|---|
| AnimatedComponent_InitializeAnimations | 2855474741 | 1:0x24DF14C (static initializer) | 1:0xB97524 (0x100B97524) | likely | `void(entAnimatedComponent*)`. Matches. |
| AppearanceChangeSystem_ChangeAppearance1 | 735526026 | 1:0xAD043C | 1:0xD43218 (0x100D43218) | confirmed | `(System&, AppearanceChangeRequest*, callback* x2, x3)`. It has 4 args; the plugin declares 3. Harmless for HookBefore. |
| AppearanceChangeSystem_ChangeAppearance2 | 386815609 | 1:0xAD043C | 1:0xD45FD0 (0x100D45FD0) | confirmed | **MISMATCH**: `(System&, WeakHandle<Puppet>&, Desc* oldBegin x2, Desc* oldEnd x3, Desc* newBegin x4, Desc* newEnd x5, cb* x6, u8 w7)`. Both `Range`s are passed by value in register pairs, not as `Range&`. |
| AppearanceChanger_ComputePlayerGarment | 3243419919 | 1:0xACA488 | 1:0x3710560 (0x103710560) | confirmed | 8 args, `x0..x6` plus `bool w7`. Matches. |
| AppearanceChanger_GetSuffixValue | 1003499294 | 1:0x370E9AC (static initializer) | — | refuted (inlined) | Inlined into GetSuffixes `0x10370D924`. No standalone function exists. |
| AppearanceChanger_GetSuffixes | 63057648 | 1:0x2ABCDD0 (TweakDB record flat init) | 1:0x370D924 (0x10370D924) | likely | **MISMATCH**: the `CString` result comes back through `x8`, not as the first argument. The other 4 args move to `x0..x3`. |
| AppearanceChanger_RegisterPart | 3169139695 | 1:0xCD2B90 | — | refuted-unknown | The old address is a 3-argument `ent::Assembler` merge function (component name-conflict log). Its arity does not fit the 4-argument RegisterPart. |
| AppearanceChanger_SelectAppearanceName | 2770550105 | 1:0xAD043C | 1:0x3732C68 (0x103732C68) | confirmed | **MISMATCH**: the `CName` is returned in `x0` and there is no `aOut`. Args: `x0`=record&, `x1`=ItemID&, `x2`=Handle<AppRes>&, `x3`=a5, `x4`=name. |
| AppearanceDefinition_ExtractPartComponents | 39206067 | 1:0xCD2B90 | — | refuted-unknown | The old address is the same Assembler function as RegisterPart. Not found. |
| AppearanceNameVisualTagsPreset_GetVisualTags | 1186798404 | 1:0x2BF8BD0 (unrelated vtable function) | 1:0x3CD7234 (0x103CD7234) | confirmed | `(preset*, ResourcePath, CName, TagList&)`. Matches. It has no prologue: `cbz` is at `+4` and it ends in a tail-call `b`. |
| AppearanceResource_FindAppearanceDefinition | 549398675 | 1:0xAD043C | 1:0xAD7048 (0x100AD7048) | confirmed | **MISMATCH**: the `Handle<AppearanceDefinition>` is returned through `x8`. Args: `x0`=res, `x1`=CName, `w2`=u32, `w3`=u8. |
| AppearanceResource_OnLoad | 3141736993 | 1:0xACE140 ("AppearanceDefinition_LoadData" function) | 1:0xAD88A8 (0x100AD88A8) | confirmed | PostLoad `(this, params*)`. Only `x0` is used. Matches. |
| AttachmentSlots_InitializeSlots | 3224838039 | 1:0x14E6D44 ("too many slots") | 1:0x3508DB0 (0x103508DB0) | confirmed | `(AttachmentSlots*, DynArray<TweakDBID>&)`. Matches. |
| AttachmentSlots_IsSlotEmpty | 4231927464 | 1:0x14E6D44 | 1:0x35104E4 (0x1035104E4) | confirmed | `bool(AS*, TweakDBID)`. Matches. |
| AttachmentSlots_IsSlotSpawning | 1283201918 | 1:0x14E6D44 | 1:0x3510644 (0x103510644) | likely | `bool(AS*, TweakDBID)`. Matches. |
| EntityBuilder_ScheduleExtractComponentsJob | 437791594 | 1:0xD4DC20 (RuntimeSystemEntityTransforms vtable function) | 1:0xCA08A0 (0x100CA08A0) | likely | **MISMATCH**: `(EntityBuilder* x0, JobQueue& x1)`. The function builds `EntityBuilderJobParams` itself; the plugin expects `(JobQueue&, void*, Params*)`. |
| EntitySpawner_SpawnFromTemplate | 2509382878 | 1:0x33E4040 (world node type registry) | — | refuted-unknown | Not found. |
| EntityTemplate_FindAppearance | 36838056 | 1:0xC7493C (garment validation) | 1:0xCB12BC (0x100CB12BC) | confirmed | `TemplateAppearance*(EntityTemplate*, CName)`. Matches. |
| EntityTemplate_OnLoad | 2741376473 | 1:0xAE4070 (garment ProcessGarment core) | 1:0xCB2A6C (0x100CB2A6C) | confirmed | PostLoad `(this, params*)`. Matches. |
| Entity_Reassemble | 1560690857 | 1:0xC95744 | 1:0xC95744 (unchanged) | confirmed | 6 args `x0..x5`. Matches. |
| GarmentAssemblerState_AddCustomItem | 3128897273 | 1:0x36FE44C (request vtable log function) | — | refuted-unknown | Not found. |
| GarmentAssemblerState_AddItem | 2294423397 | 1:0x36FE44C | — | refuted-unknown | Not found. |
| GarmentAssemblerState_ChangeCustomItem | 956641309 | 1:0x36FE44C | — | refuted-unknown | Not found. |
| GarmentAssemblerState_ChangeItem | 3740082313 | 1:0x36FE44C | — | refuted-unknown | Not found. |
| GarmentAssembler_ExtractComponentsJob | 809178766 | 1:0xAE6348 | 1:0xAE6348 (unchanged) | confirmed | `(Params*, JobGroup&)`. **LAYOUT MISMATCH**: `params+0x00` is a `SharedPtr<ResourceToken<EntityTemplate>>`, not a `Handle<EntityTemplate>`. |
| GarmentAssembler_FindState | 2594581880 | 1:0x36FE44C | 1:0x36F8A34 (0x1036F8A34) | likely | **MISMATCH**: the 24-byte state is returned through `x8`. Args: `(tracker x0, WeakHandle<Entity>& x1, u32 w2)`. |
| GarmentAssembler_OnGameDetach | 709304039 | 1:0x23A74F0 (gameui garment preview controller) | — | refuted-unknown | Not found. |
| GarmentAssembler_ProcessGarment | 29053464 | 1:0xAFA378 (debug string builder) | 1:0xAE4004 (0x100AE4004) | likely | **MISMATCH**: the JobHandle is returned through `x8`. Args: `(SharedPtr<Ctx>* x0, a x1, GarmentLoadingParams* x2)`. |
| GarmentAssembler_ProcessMorphedMesh | 1567972572 | 1:0xAFA378 | 1:0xAE3CC0 (0x100AE3CC0) | confirmed | 6 args `(ctx*, u32, &tmpl, &token, &comp, JobGroup&)`. Matches. |
| GarmentAssembler_ProcessSkinnedMesh | 1663588463 | 1:0xAFA378 | 1:0xAE3840 (0x100AE3840) | confirmed | Same signature as ProcessMorphedMesh. Matches. |
| GarmentAssembler_RemoveItem | 1863723270 | 1:0x36FE44C | — | refuted-unknown | Not found. |
| ItemFactoryAppearanceChangeRequest_LoadAppearance | 3392610574 | 1:0xAD043C | 1:0x36FCE14 (0x1036FCE14) | confirmed | `bool(req*)`. Matches. |
| ItemFactoryAppearanceChangeRequest_LoadTemplate | 1291460507 | 1:0xCD2B90 | 1:0x36FCA88 (0x1036FCA88) | confirmed | `bool(req*)`. Matches. |
| ItemFactoryRequest_LoadAppearance | 3659799256 | 1:0xACA488 | 1:0x37034A4 (0x1037034A4) | confirmed | `bool(req*)`. Matches. This is the garment request variant. |
| TPPRepresentationComponent_IsAffectedSlot | 678894266 | 1:0x23D9DF4 (PreGame UI listener) | — | refuted (inlined) | No function exists. The check is inlined at `0x1035A56DC` and `0x1035A6174`. |
| TPPRepresentationComponent_OnAttach | 4129169021 | 1:0x35AD5D0 (static initializer) | 1:0x35A0604 (0x1035A0604) | confirmed | `(comp*, ctx*)`. Matches. |
| TPPRepresentationComponent_RegisterAffectedItem | 3037343626 | 1:0x37DF568 | 1:0x35A0E10 (0x1035A0E10) | confirmed | `(comp*, TweakDBID, const Handle<ItemObject>&)`. Matches. |

**Counts:**
- 20 confirmed:
  - 2 of them unchanged: Entity_Reassemble and GarmentAssembler_ExtractComponentsJob.
  - 18 newly located.
- 7 likely.
- 10 with no usable function:
  - 2 refuted because the code is inlined.
  - 8 refuted-unknown.

Every old address except those two unchanged ones was wrong.

## Evidence

**AnimatedComponent_InitializeAnimations → 0x100B97524**
- Only caller: AnimatedComponent::OnInitialize, vtable `0x106EB4BE0` slot 47, at `0x100B96A38`. It is called right after the rig check.
- Single argument, `this`. It rebuilds the runtime anim setup at `+0x1B8`/`+0x1C8`/`+0x1D8` by copying `animations` from `+0x190` via `0x1043BA4E4`. The copy includes `gameplay` at `+0x1A0`, which is what the plugin pushes into.
- The later `Anim_BuildRuntimeAnimSetup` job (lambda `0x100BA1030`) consumes this setup.
- Rated likely: the semantics match, but no name string ties it to InitializeAnimations.

**ChangeAppearance1 → 0x100D43218**
- The profiler label "Entity/QueueAppearanceChange" is referenced inside the function, at `0x100D4388C`.
- `x1` matches the request layout:
  - it is checked as a WeakHandle: `[x1+8]` refcount with `ldapr`;
  - it reads `[x1+0x10..0x2F]` (old and new descriptors).
- `x2` is a small-buffer callback (`[x2+0x18]==x2`).
- Callers include the CharacterCustomization UI (`0x1023DA0DC` and others).

**ChangeAppearance2 → 0x100D45FD0**
- It iterates `x2..x3` and `x4..x5` with stride `0x10` (AppearanceDescriptor) and stores `x6` and `w7`.
- It builds 0x68-byte requests and calls QueueAppearanceChanges `0x100D46770`, which holds the label "Entity/QueueAppearanceChanges" at `0x100D46BAC`.
- Example caller at `0x10243D04C`: `x2..x5` are begin/end pointers and `w7=0`.

**ComputePlayerGarment → 0x103710560**
- Called only from the job lambda `0x103710968`. That lambda is dispatched under the label "DoStartChangeAppearance_ComputePlayerGarment" (`0x103710410`).
- The lambda locks the entity WeakHandle (status `+0x156`) and passes `x0` through `x6` plus `w7=bool`.
- `x3` is dereferenced, and the result is used at `+0x10/+0x20/+0x30/+0x40`. Those are exactly the components, meshes, templates and resources fields of GarmentProcessingContext.

**GetSuffixes → 0x10370D924; GetSuffixValue inlined**
- The function references the "AppearanceDefinitions"/"SuffixSeparator" config through `0x10370E4B8`.
- It has 19 callers: TPP `0x1035A2020`, TransactionSystem, CharacterCustomization and others.
- The CString goes out through `x8`.
- The built-in Camera suffix ("TPP"/"FPP") and the scripted-suffix call (`0x10370E5B0`, which executes a script function from the record) are both inline in this function. No other code references "TPP"/"FPP" except static initializers, so GetSuffixValue does not exist as a separate function.

**RegisterPart / ExtractPartComponents (old 0x100CD2B90)**
- The old address is a 3-argument `ent::Assembler` function: `x0`=ctx with fields `+0x30/+0x38/+0x40/+0x4C/+0x70`, plus `x1` and `x2`. It holds the log "Component name conflict for appearance component".
- It does not fit either 4-argument RegisterPart or ExtractPartComponents `(DynArray&, const SharedPtr<Token>&)`.
- Neither function was found.

**SelectAppearanceName → 0x103732C68**
- When `x4` (name) is non-zero, it calls `FindAppearanceDefinition(*x2, x4, 0, 0)` and returns `def->name` (`+0x30`) in `x0`.
- Otherwise it collects the record's tags (`[*x0]+0x240`) plus `x3`, and picks among definitions matching those tags (`0x100AD7254`) using the ItemID seed (`[x1+8]`). The fallback is "default".
- 4 item-factory callers.

**GetVisualTags → 0x103CD7234**
- An FNV-1a hash of `x1` (ResourcePath) indexes the preset map at `+0x30..0x4C`. The function then tail-calls `0x103CD2F60(entry+0x10, name x2, tags x3)`.
- Caller `0x103703A44` passes `(preset, templateToken->path, req[0x180] name, &TagList)`. The other callers include population and the garment requests.

**FindAppearanceDefinition → 0x100AD7048**
- It takes the reader lock at `+0xF0`; that matches the plugin's `AppearanceResource::Mutex` offset.
- It walks alternate-appearance mapping (`+0x60`/`+0x78`) when `w3` is set and censorship mapping (`+0xA8`) when `w2` is set, then fills the out-Handle at `x8`.
- 8 callers, for example `0x1037038E8`: `x0=res, x1=req[0x158], w2=0, w3=0, x8=&out`.

**AppearanceResource_OnLoad → 0x100AD88A8** (vtable `0x106EA2380` slot 6)
- The vtable comes from the `appearanceAppearanceResource` registration `0x100ADA860` → TTypedClass vtable `0x106EA26F0` → slot 28 → ctor `0x100AD69AC`.
- The function calls the base PostLoad, then, if `appearances` (`+0x98`, size `+0xA4`) is empty, allocates a `0x1D8` AppearanceDefinition and appends a default.

**EntityTemplate_OnLoad → 0x100CB2A6C** (vtable `0x106ED47C8` slot 6)
- Reached the same way, through ctor `0x100CAF188`.
- It rebuilds `+0x140/+0x1B0/+0x248` (includeInstanceBuffer, compiledData) and calls `0x100CB3C34`, which holds the "EntityTemplate_Compilation"/"ResolveAndPreload" labels.

**AttachmentSlots** (TransactionSystem natives, mapped from registration `0x10388180C`)
- **InitializeSlots:**
  - The script native `0x103894ABC` → TS vtable `0x1072173A0`+`0x380` → `0x103894A40` → **`0x103508DB0`**.
  - That function takes the write lock at `+0x100`, then calls the inner `0x103508DF8`, which rebuilds the slot array at `+0xB0` (stride 0x90) from the `DynArray<TweakDBID>`.
- **IsSlotEmpty:**
  - Path: script native → TS `+0x3C8` → **`0x1035104E4`**.
  - It takes the reader lock, finds the slot by its 40-bit TweakDBID, and returns `found && !itemObject && !IsValid(spawningItemID)`.
- **IsSlotSpawning:**
  - "IsSlotEmptySpawningItem" → TS `+0x3D0` → **`0x103510644`**, which returns `found && !itemObject && IsValid(spawningItemID)`.
  - Rated likely, because the Windows name is ambiguous.
  - "IsSlotSpawningItem" → TS `+0x3D8` → `0x103510774` takes an extra ItemID argument, so it does not fit.
- These locked functions each have only one caller (the TS vtable function). Unlocked twins with no callers sit next to them (`0x1035105A8`, `0x103510704`, `0x10351085C`). Game-internal callers probably inline the logic, so the hooks only catch the script path.

**EntityBuilder_ScheduleExtractComponentsJob → 0x100CA08A0**
- It holds the job label "EntityBuilder_ExtractComponents". The guard and lambda are at `0x107599088`/`0x100CA41E0`.
- It locks `builder->self` (WeakPtr at `+0`), allocates a 0x18-byte `{EntityBuilder*, WeakPtr}` (that is EntityBuilderJobParams), and dispatches into the JobQueue passed in `x1`. There is one caller.

**EntityTemplate_FindAppearance → 0x100CB12BC**
- Null name or "default" (`0x108DCB830`) uses `defaultAppearance` at `+0x60`. "random" (`0x108DCB828`) picks a random entry.
- Otherwise it does a linear search of `appearances` (`+0x50`, count `+0x5C`, stride 0x18) and returns the entry.
- Callers: EntityBuilder `0x100CA2378`, and the item-factory LoadAppearance functions `0x1037034A4` and `0x1036FCE14`.

**Entity_Reassemble → 0x100C95744** (unchanged)
- The function references "Entity/ReassembleAppearance/InitializeComponents".
- It stores `x2` and `x3` at entity `+0x50`, iterates `x4` as a `DynArray<Handle>` (stride 0x10) and uses `x5` (the params handle). There is one caller, `0x100CA18D4`.

**GarmentAssembler_ExtractComponentsJob → 0x100AE6348** (unchanged)
- It is the job lambda for "ExtractGarmentComponent". The creator is `0x100AE50CC` inside ProcessGarment-core `0x100AE4070`.
- `params[0]` is read as a ResourceToken: `IsFailed` reads `[token+0x5C]`; the resource handle is at `token+0x28`. It is then checked IsA EntityTemplate.
- It copies `params+0x20` and `params+0x30..0x3D`, then dispatches the "ProcessLoaded…" job `0x100AE6660`.
- The plugin's hook replaces `params->partTemplate` with a Handle and re-invokes the job. **That would corrupt the token SharedPtr.**

**ProcessSkinnedMesh → 0x100AE3840, ProcessMorphedMesh → 0x100AE3CC0**
- Inside job `0x100AE6660`, the guard `0x107548008` holds "CharacterResourceEditor/Garment/ProcessLoadedMesh" (`0x100AE6F74`). It creates lambda `0x100AE72EC`, which calls `0x100AE3840`.
- The guard `0x107548010` holds "…ProcessLoadedMorphedMesh" (`0x100AE6FDC`). It creates lambda `0x100AE7368`, which calls `0x100AE3CC0`.
- Both lambdas pass `(cap[0] ctx*, w=cap[0x40], &cap[0x10], &cap[0x20], &cap[0x30], jobgroup)`.

**ProcessGarment → 0x100AE4004**
- It creates a job builder, then calls the core `0x100AE4070` (the label "CharacterResourceEditor/Garment/ProcessLoadedAppearanceParts") with `x8=ret`.
- 5 callers: all 4 garment item-factory requests and `0x100AFE41C`.
- Caller `0x103703B98` passes `x0=&req[0x48]->+8` (the SharedPtr ctx) and `x2=&{Handle<Entity>, …}`, then stores the returned JobHandle at `req+0x118`.
- Rated likely: the Windows hidden-return layout is inferred, not proven.

**FindState → 0x1036F8A34**
- 7 callers, all garment requests.
- It locks a `WeakHandle<Entity>` (`x1`) and checks status `+0x156`/`+0x15C`. It then searches the owner list at `this+0x8` (stride 0x60) and indexes a sub-array with `w2`.
- It writes the 24-byte result `{this, ownerEntry, handle}` through `x8`.
- Neighbouring symbols suggest the macOS class is `game::CustomizableItemsTracker`.
- AddItem, ChangeItem, AddCustomItem, ChangeCustomItem and RemoveItem were not identified. The garment requests apply overrides through `0x100ACB79C`/`0x100ACB21C`, which are AppearanceDefinition-side functions. Their roles are unverified, so no mapping is reported.

**ItemFactoryRequest_LoadAppearance → 0x1037034A4**
- It reads the record (`+0x160`) and the template token (`+0x138`), checks IsA EntityTemplate, and calls `EntityTemplate::FindAppearance(tmpl, req[0x158])`.
- It loads the appearance resource and swaps the token into `+0x148`.
- The next state, `0x1037038E8`, consumes `+0x148`/`+0x158`. All offsets match the plugin's OffsetPtrs.

**ItemFactoryAppearanceChangeRequest_LoadAppearance → 0x1036FCE14**
- It reads the record handle (`+0x100`) and the template token (`+0xA8`), and calls FindAppearance with the name at `+0x48`.
- It stores the token to `+0xB8` and the name to `+0xF0`/`+0xC8`.
- It is called from the state machine `0x1036FC4C8`, case 4.

**ItemFactoryAppearanceChangeRequest_LoadTemplate → 0x1036FCA88**
- It reads the target entity at `+0xD0` (matching the plugin's ItemEntityOffset) and checks entity status at `+0x156`.
- It resolves the entity's template path (`0x100C99EB8`), loads it into the token at `+0xA8`, and returns `bool` (not failed).
- State machine case 2.
- The record is at `+0x100`. The pointer read at `+0x128` may not be the factory at `+0x120` that the plugin expects; that is unverified.

**TPPRepresentationComponent_OnAttach → 0x1035A0604** (vtable `0x1071D5B60` slot 49)
- It calls the base `0x100CA627C`, which sets the attached flag.
- It allocates a 0x48-byte listener (vtable `0x1071D5A20`) and stores its handle at `+0x148`. That matches the plugin's `SlotListener` OffsetPtr.
- For Head and Eyes (TweakDBIDs at `0x108768490`/`0x108768498`) it queries TS `+0x428`, reads `itemObject+0x288` (ItemID), and calls RegisterAffectedItem.

**RegisterAffectedItem → 0x1035A0E10**
- Callers: OnAttach (twice) and the equip handler `0x1035A6174`.
- It takes the `+0x124` lock and inserts into a 0x18-stride array at `+0x128`.
- Its 2-argument unregister twin is `0x1035A6654`.

**IsAffectedSlot (inlined)**
- The only code that uses the Head/Eyes globals is OnAttach and two inline checks: `and x8,x2,#0xffffffffff; cmp Head; ccmp Eyes` at `0x1035A56F8` (equipped handler) and `0x1035A61A8` (unequipped handler).
- Those handlers are reached through the listener thunks `0x1035A7638`/`0x1035A762C`.
- There is no out-of-line function. ArchiveXL's slot-extension logic would have to hook those two handlers, which correspond to the separate hashes `TPPRepresentationComponent_OnItemEquipped`/`OnItemUnequipped`.

## Danger list (do not enable these with the current plugin declarations)
- **ChangeAppearance2:** the plugin reads two `Range&` in `x2`/`x3`. The real registers are 4 raw pointers in `x2..x5`, with `a5`/`a6` in `x6`/`w7`.
- **FindAppearanceDefinition:** the plugin's `aDefinition` (`x1`) is actually the CName. The out-Handle is in `x8`.
- **SelectAppearanceName (full Hook) and GetSuffixes (full Hook):** the result is returned in `x0` or `x8`, not through a first-argument out pointer. Every argument is shifted by one register.
- **FindState (HookAfter):** the state goes out through `x8`. The plugin's `aOut` would be the WeakHandle, and `aEntityWeak` would be a `u32`.
- **ProcessGarment (full Hook):** the JobHandle comes back through `x8`. The plugin's `aParams` would land in `x3`, which is garbage.
- **ScheduleExtractComponentsJob:** the arguments are `(EntityBuilder*, JobQueue&)`, not `(JobQueue&, void*, Params*)`.
- **GarmentAssembler_ExtractComponentsJob:** the job params hold a ResourceToken SharedPtr, not a Handle. The plugin's re-invoke trick would corrupt it.
- **IsAffectedSlot and GetSuffixValue:** no function exists. Any hook needs a different target.
- **GetVisualTags:** it has no prologue and a PC-relative `cbz` at `+4`. The trampoline must relocate that branch.
