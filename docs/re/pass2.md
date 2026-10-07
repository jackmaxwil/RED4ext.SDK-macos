# RE group "pass2": macOS 2.3.1 arm64 (static only)

This pass builds on `docs/re/{appearance,resources,world,core}.md`.
- Binary: the Steam `Cyberpunk2077`. In the checked ranges it is byte-identical to `Cyberpunk2077.orig`.
- Every "new" address is an exact entry in `xcrun dyld_info -function_starts`, re-checked on the Steam binary.
- Absolute address = 0x100000000 + offset.
- ArchiveXL declarations are in `cp2077-archive-xl-macos/src/Red/*.hpp`.
- "sret x8" means the callee writes its by-value result through x8. Every argument after it moves one register earlier than in the Windows declaration.

| name | hash | old | new seg:off (absolute) | verdict | arm64 signature vs plugin declaration |
|---|---|---|---|---|---|
| GarmentAssembler_ProcessGarment | 29053464 | 1:0xAE4004 | 1:0xAE4004 (0x100AE4004) | confirmed | **MISMATCH**: `SharedPtr<GarmentProcessingContext> (sret x8) (const Handle<AppearanceDefinition>& x0, opts* x1, GarmentLoadingParams* x2)`. Plugin: `(SharedPtr& aProcessor, a2, a3, aParams)`, where aProcessor is the Windows hidden return. |
| AppearanceDefinition_ExtractPartComponents | 39206067 | 1:0xCD2B90 | 1:0xACCA30 (0x100ACCA30) | confirmed (newly found) | **MISMATCH**: `DynArray<Handle<ISerializable>> (sret x8) (const SharedPtr<ResourceToken<EntityTemplate>>& x0)`. Plugin: `(DynArray& aOut, const SharedPtr& aToken)`. |
| AppearanceChanger_GetSuffixes | 63057648 | 1:0x370D924 | 1:0x370D924 (0x10370D924) | confirmed | **MISMATCH**: `CString (sret x8) (Handle<GameObject>& x0, Handle<GameObject>& x1, const Handle<Item_Record>& x2, const ItemID& x3)`. Arg 3 is a **Handle**, not `TweakDBRecord&`. |
| EntityBuilder_ScheduleExtractComponentsJob | 437791594 | 1:0xCA08A0 | 1:0xCA08A0 (0x100CA08A0) | confirmed (as the scheduling site) | **MISMATCH**: `void (EntityBuilder* x0, JobQueue& x1)`. The out-of-line `(JobQueue&, ?, Params*)` dispatcher that Windows hooks is inlined here. |
| InkWidgetLibrary_SpawnFromExternal | 506278179 | 1:0x4965EC0 | 1:0x4965EC0 (0x104965EC0) | confirmed | **MISMATCH**: `Handle<ItemInstance> (sret x8) (lib* x0, ResourcePath x1, CName x2)`. Plugin passes `Handle&` in x1. |
| GarmentAssembler_OnGameDetach | 709304039 | 1:0x23A74F0 | 1:0x36F6F4C (0x1036F6F4C) | confirmed (newly found) | `void (GarmentItemAggregator* x0, RuntimeScene* x1 /*unused*/)`. Plugin `void(uintptr_t)` is OK. |
| QuestLoader_ProcessPhaseResource | 790570700 | 1:0x2ED6090 | 1:0x2ED6090 (0x102ED6090) | confirmed | `void (loader* x0, ResourcePath x1, Handle<questQuestPhaseResource>& x2)`. Matches. |
| QuestRootInstance_Start | 797843833 | 1:0x2D01878 | 1:0x2D01878 (0x102D01878) | confirmed | `bool (questRootInstance* x0, QuestContext* x1, const Handle<questQuestResource>& x2)`. Plugin declares void; harmless for HookBefore if w0 is preserved. |
| JournalTree_ProcessJournalIndex | 837162664 | 1:0x1EA3410 | 1:0x1EA3410 (0x101EA3410) | confirmed | `void (capture* x0, const RunContext/JobGroup& x1)`. Matches. |
| GarmentAssemblerState_ChangeCustomItem | 956641309 | 1:0x36FE44C | — (inlined). Hook **1:0x36F890C (0x1036F890C)** instead | inlined (no live function) | Live site: `bool (GarmentItemAggregator* x0, WeakHandle<Entity>& x1, ChangeCustomRequest& x2)`. The dead out-of-line copy 0x1036F89A4 has the plugin's signature but no callers. |
| InkWidgetLibrary_SpawnFromLocal | 1158555307 | 1:0x4965DE0 | 1:0x4965DE0 (0x104965DE0) | confirmed | **MISMATCH**: `Handle<ItemInstance> (sret x8) (lib* x0, CName x1)`. |
| AttachmentSlots_IsSlotSpawning | 1283201918 | 1:0x3510644 | 1:0x3510644 (0x103510644) | confirmed | `bool (AttachmentSlots* x0, TweakDBID x1)`. Matches. |
| CClass_GetProperties | 1652956141 | 1:0x2197928 | 1:0x2197928 (0x102197928) | confirmed | `void (CClass* x0, DynArray<CProperty*>& x1)`. Matches. The SDK typedef's `CProperty*` return is harmless. |
| GarmentAssembler_RemoveItem | 1863723270 | 1:0x36FE44C | 1:0x36F8744 (0x1036F8744) | confirmed (newly found) | `bool (GarmentItemAggregator* x0, WeakHandle<Entity>& x1, RemoveRequest& x2)`. Matches. On mac the request is `{u64 hash, u32 index}`; the plugin reads only `hash`. |
| GarmentAssemblerState_AddItem | 2294423397 | 1:0x36FE44C | 1:0x36F8208 (0x1036F8208) | confirmed (newly found) | `bool (GarmentAssemblerState* x0, AddRequest& x1)`. Matches, layout included (offset @0x18). |
| EntitySpawner_SpawnFromTemplate | 2509382878 | 1:0x33E4040 | 1:0x14084B0 (0x1014084B0) | confirmed (newly found) | **MISMATCH**: `Ticket (sret x8) (EntitySpawner* x0, Request* x1, ResourcePath x2)`. **Also a layout mismatch**: mac `appearanceName @0xA0` and `recordID @0xC0`; the plugin uses 0xC0/0xE0. |
| ResourceSerializer_Load | 2577814646 | 1:0x2255B4C | 1:0x2255B4C (0x102255B4C) | confirmed | `void (loader* x0, const SharedPtr<IAsyncSource>& x1, const Request& x2, const CallbackContext& x3, CompletionDeferral&& x4)`. Matches. |
| GarmentAssembler_FindState | 2594581880 | 1:0x36F8A34 | **1:0x36F8030 (0x1036F8030)**. The old address is refuted. | confirmed | **MISMATCH**: `GarmentAssemblerState{0x18} (sret x8) (GarmentItemAggregator* x0, WeakHandle<Entity>& x1)`. Plugin: `(uintptr, State* aOut, WeakHandle&)`. |
| AnimatedComponent_InitializeAnimations | 2855474741 | 1:0xB97524 | 1:0xB97524 (0x100B97524) | confirmed | `void (entAnimatedComponent* x0)`. Matches. |
| FactoryIndex_ResolveResource | 3040549301 | 1:0xCC0BEC | 1:0xCC0BEC (0x100CC0BEC) | confirmed | **MISMATCH**: `ResourcePath (index* x0, CName x1)`, with the result in **x0**. Plugin: `(index, ResourcePath& out, CName)`. |
| GarmentAssemblerState_AddCustomItem | 3128897273 | 1:0x36FE44C | 1:0x36F82F4 (0x1036F82F4) | confirmed (newly found) | `bool (GarmentAssemblerState* x0, AddCustomRequest& x1)`. Matches, layout included. |
| AppearanceChanger_RegisterPart | 3169139695 | 1:0xCD2B90 | 1:0xCD1F50 (0x100CD1F50) | confirmed (newly found) | `void (ent::Assembler-parts* x0, Handle<EntityTemplate>& x1, Handle<ComponentsStorage>& x2, Handle<AppearanceDefinition>& x3)`. Matches. |
| GarmentAssemblerState_ChangeItem | 3740082313 | 1:0x36FE44C | — (inlined). Hook **1:0x36F87E4 (0x1036F87E4)** instead | inlined (no live function) | Live site: `bool (GarmentItemAggregator* x0, WeakHandle<Entity>& x1, ChangeRequest& x2)`. The dead copy 0x1036F887C has no callers. |
| ObjectPackageExtractor_ExtractAsync | 3819248393 | 1:0x2150A60 | 1:0x2150A60 (0x102150A60) | confirmed | **MISMATCH**: `{?, JobHandle@+8} (sret x8, 16 bytes) (extractor* x0)`. SDK: `void(extractor*, JobHandle&)`. |

Counts: 24 entries.
- 22 confirmed, of which:
  - 14 keep their current DB address;
  - 8 get a new address: FindState (old refuted) plus 7 that were "not found" (ExtractPartComponents, OnGameDetach, RemoveItem, State_AddItem, State_AddCustomItem, RegisterPart, SpawnFromTemplate).
- 2 have no live function because they are inlined (ChangeItem, ChangeCustomItem). Their caller-level hook sites are given.
- 0 likely and 0 unknown.

There are 10 ABI signature mismatches (sret through x8 or a different argument order). QuestRootInstance_Start also returns bool where the plugin declares void. EntitySpawner_SpawnFromTemplate also has a request layout mismatch, and GetSuffixes also has a parameter-type mismatch.

## Evidence

### Garment group: class = `game::GarmentItemAggregator`

The GOT slot 0x106E27408 `DynArray<game::GarmentItemAggregator::OwnerAppearanceParts>::MoveAfterReallocation` is used only by the owner-insert function 0x1036F6FA4, which reallocates `this+0x8` with elemSize 0x60. FindState and every wrapper below index `this+0x8/+0x14` with stride 0x60. ArchiveXL's "GarmentAssembler" is this aggregator. It lives at `ItemFactorySystemLowLevel+0x5AB0`.

The aggregator code is uniform:
- Each tracker-level op is `op(aggr x0, WeakHandle<Entity>& x1, req& x2)`.
- It does `state = FindState(aggr, x1)` (sret into a 0x18 stack slot, x8 = sp+8).
- It then calls `StateOp(&state, req)` or an inlined copy of it.

**GarmentAssembler_FindState → 0x1036F8030** (the old 0x1036F8A34 is refuted)
- It locks the WeakHandle (entity status `+0x156`/`+0x15C`) and finds the owner entry via 0x1036F7238. It does not create one.
- It writes `{entry+0x10, entry+0x20, entry+0x50}`, or zeros, to `[x8]`. That is 0x18 bytes, matching the plugin's `RED4EXT_ASSERT_SIZE(GarmentAssemblerState, 0x18)`.
- It has 8 callers, all of them the op wrappers below.
- The old 0x1036F8A34 is a different function: `(aggr, weak, u32 index)` returning a 0x28-byte `{&parts[idx], &overrides[idx], resref}`.
- That old function is decisive against the old address. Its `unk00` (`entry.parts.data + idx*16`) differs from the key that AddItem's state carries (`entry+0x10`). With the old address, `LinkEntityToPointer` and `FindEntityState(aState->unk00)` would never match.

**GarmentAssemblerState_AddItem → 0x1036F8208**
- Wrapper 0x1036F7FF8 is `FindState` then `bl 0x1036F8208(&state, req)`. 0x1036F8208's only caller is that wrapper.
- Body:
  - `addPart(state, &req.handle@0, req.hash@0x10, req.offset@0x18, req.index@0x1C)` via 0x1036F8D24;
  - `addOverrides(state, &handle, hash, index)` via 0x1036F9358;
  - returns `w0 = a & b`.
- The request is built at 0x103704974 inside 0x10370485C (ItemFactoryRequest):
  - `+0x00` = `Handle<AppearanceDefinition>`;
  - `+0x10` = ItemID hash;
  - `+0x18` = `req[0x58]` (offset);
  - `+0x1C` = index.
- That is exactly `GarmentItemAddRequest {Handle@0, hash@0x10, offset@0x18}`.

**GarmentAssemblerState_AddCustomItem → 0x1036F82F4**
- Wrapper 0x1036F82BC → 0x1036F82F4 (single caller).
- It uses `hash@0x20` and `offset@0x28`, and calls `0x1036F96AC(state, &req.overrides@0x10, …)`, which iterates stride 0x18 (`AppearancePartOverrides`).
- The request is built at 0x103704A3C–0x103704ADC with a DynArray of overrides at +0x10.
- That matches `GarmentItemAddCustomRequest {Handle, DynArray overrides@0x10, hash@0x20, offset@0x28}`.

**GarmentAssembler_RemoveItem → 0x1036F8744**
- Body: `FindState`, then `0x1036F920C(state, [req], [req+8])` & `0x1036F9810(state, [req], [req+8])`. These remove the parts and overrides for that hash.
- Callers: 0x103700904 and 0x103704BF4 (the garment item-factory requests).
- Matches `RemoveItem(uintptr, WeakHandle<Entity>&, GarmentItemRemoveRequest&)`.

**GarmentAssemblerState_ChangeItem / ChangeCustomItem: inlined on macOS**
- The out-of-line state-level copies exist and have the plugin's signature:
  - ChangeItem: 0x1036F887C, `(state x0, req x1)`: remove(hash@0x10) ×2, addPart(…, 0, index@0x18), addOverrides.
  - ChangeCustomItem: 0x1036F89A4, the same with `hash@0x20`, `index@0x28` and `0x1036F96AC(&req.overrides@0x10)`.
  - A matching RemoveItem state copy is 0x1036F8798.
- All three have **0 BL/B callers, 0 ADRP/ADR refs and 0 data pointers**, so a hook there never fires.
- The live code is the same sequence inlined into the tracker-level wrappers:
  - **0x1036F87E4** (ChangeItem);
  - **0x1036F890C** (ChangeCustomItem).
- Each wrapper has one caller, both in the ItemFactoryAppearanceChangeRequest step 0x1036FDDD4 (`bl` at 0x1036FDEE8 and 0x1036FDFF8). That step is reached from 0x1036FD0E0.
- The ArchiveXL handlers only need the entity state. In the wrappers the entity is `x1` (WeakHandle), as it is in OnRemoveItem.

**GarmentAssembler_OnGameDetach → 0x1036F6F4C**
- Body: `for i in count@+0x14 .. 0: destroy OwnerAppearanceParts(+0x8 + i*0x60) (0x1036F9DA4); count = 0`. It clears all aggregator state.
- Its only caller is 0x10371FE6C (ItemFactorySystemLowLevel detach). That function forwards x1 to three members:
  - +0x5AB0 aggregator → this function;
  - +0x5AC8 CustomizableItemsTracker → 0x1036F4F28;
  - +0x5C08 → 0x10373C928.
- 0x10371FE6C is called from 0x103712FF8, which is gameItemFactorySystem vtable slot +0x120 (data 0x1071F9E48; address point 0x1071F9D28).
- +0x120 is MSVC 0x118, which is `IGameSystem::OnBeforeWorldDetach(RuntimeScene*)`.

**GarmentAssembler_ProcessGarment → 0x100AE4004** (upgraded from likely)
- The outer function builds a JobQueue, then calls the core 0x100AE4070 with the same x8.
- The core allocates the **0x150-byte context** (ctor 0x100AE3354) and writes `{ctx, refcount}` to `[x8]`. The result is a `SharedPtr<GarmentProcessingContext>`, not a JobHandle.
- It stores the `[x0]` handle (the AppearanceDefinition) at **ctx+0x58**, which matches the plugin's `GarmentProcessingContext::definition @0x58`.
- x2 (params) is null-checked and `{Handle<Entity>@0, …}` is copied.
- Caller 0x103703B98 moves the result into `req+0x118`.
- So the Windows `aProcessor` is the MSVC hidden-return pointer. Windows `(ret, a2, a3, params)` maps to mac `(x8, x0, x1, x2)`.

**AppearanceDefinition_ExtractPartComponents → 0x100ACCA30**
- Steps:
  1. `x0` is a token SharedPtr; on IsFailed it returns an empty array.
  2. Fetch → EntityTemplate → compiled data via 0x100CB6C5C.
  3. Clear the root-object bit (`ldrsh` rootIndex) from the include mask, so components only.
  4. ObjectPackageExtractor factory 0x102151414, ExtractSync 0x102150CE4, then `0x10215118C(extractor, x8=out)`.
- Its only callers are in the AppearanceDefinition parts job 0x100AD043C (`bl` at 0x100AD0640 and 0x100AD0854). That job is dispatched from 0x100ACCE3C, which is called from the AppearanceDefinition load path 0x100ACE140.

**AppearanceChanger_RegisterPart → 0x100CD1F50**
- In the same job, for each part token:
  1. `tmpl` is IsA EntityTemplate.
  2. `comps = ExtractPartComponents(token)`.
  3. Allocate **0x40 bytes**. That is `entComponentsStorage`, SDK size 0x40; adder 0x100B8C73C appends to `+0x30` with the `DynArray<THandle<ent::IComponent>>` move fn.
  4. `0x100CD1F50(parts, &tmpl, &storage, &capture.definition@+0x10)`.
- The body takes the spinlock at `+0x88`, copies the 3 handles into a 0x30 entry and appends it to `+0x40`. The append uses GOT `DynArray<ent::Assembler::AppearancePartEntry>::MoveAfterReallocation`, elem 0x30.
- Second caller: thunk 0x100CB98E8 (`ldr x0,[x0,#8]; b`), referenced from vtable data 0x106ED4EC8. Hooking 0x100CD1F50 covers both.

**EntitySpawner_SpawnFromTemplate → 0x1014084B0**
- Body:
  - `if (!this->+0x50 || !x2) { [x8]=0; return }`, so x2 = ResourcePath must be non-zero.
  - It builds the spawn params with `params+0 = x2` (the template path), transform from `req+0x10`, `req+0xA0`, `req+0xB8/+0xC0`, etc.
  - It calls the spawn service 0x100CDD130, allocates a 0x110 ticket and writes it to `[x8]`.
- 9 callers. They include:
  - SpawnFromRecord 0x101408860: resolves record → template path (0x101408A70, gender-aware), **stores the recordID at `req+0xC0`**, adds a RecordIdSpawnModifier, then calls `0x1014084B0(this, req, path)` with x8;
  - gameClientEntitySpawnSystem vtable thunks (data 0x107222B40 → SpawnFromRecord, 0x107222B48 → SpawnFromTemplate) via `this+0x48`.
- How the appearance offset was found:
  - `req+0xA0` lands at `params+0x38`. The spawn-service builders take this params type: slot 0x100CDC618 reads `+0x78…+0xE5`, the same fields that 0x100CDD130 reads.
  - They copy `params+0x38` to the internal `+0x28`.
  - The template-only builder 0x100CDCA60 writes CName "default" (0x108DCB830) to that same internal `+0x28`.
  - So on mac `appearanceName = req+0xA0` and `recordID = req+0xC0`. Each is the Windows value minus 0x20.

### Upgrades of first-pass "likely" entries

**CClass_GetProperties 0x102197928**
- The sibling 0x102198670 has the same parent recursion but filters on `ldrb [prop,#0x2b]; tbz #4`.
- With CProperty flags at +0x28, that tests bit 0x1C = SDK `isPersistent`. So the sibling is the persistent-only variant, and 0x102197928 (no filter) is GetProperties.

**ResourceSerializer_Load 0x102255B4C**
- It is the only reference to it: vtable data 0x1070018C8, slot 2 of the binary ILoader (address point 0x1070018B8: D1, D0, Load, 0x102255A48 `ret 1`).
- It is the sole caller of the context ctor 0x102255A50 (0x270-byte SDK ResourceSerializerContext) and of the WaitForDependencies scheduler 0x10225646C.
- That scheduler's job reaches the confirmed OnDependenciesReady 0x1022575C0.
- Arguments:
  - x1 = source SharedPtr → ctx+0x1A0;
  - x3 = callback context (SharedPtr at +0x10);
  - x4 = CompletionDeferral, moved with 0x1009D6D88.
- This is the same `(source, LoadingContext, CallbackContext, CompletionDeferral&&)` shape as the exported `json::LoadJsonFormatResource<…>` lambdas.

**ObjectPackageExtractor_ExtractAsync 0x102150A60**
- The alternative 0x102150F5C is `void(extractor, JobQueue& x1)`. It dispatches into the caller's queue (`[x1+0x28]`, `0x1009D46F0(…, x1+0x10, x1+0x18)`) and returns nothing, and it has 1 caller.
- 0x102150A60 builds its own queue and returns via x8 (7 callers). That is the SDK `JobHandle ExtractAsync()` variant.
- The JobHandle (8 bytes; move = 0x1009D4874) lands at `[x8+8]`. Callers read `out+8`, for example 0x100CA302C.

**FactoryIndex_ResolveResource 0x100CC0BEC**
- Item-factory caller 0x103703168 passes `x1 = *(CName*)(record+0x30C flat)`, the record's entityName. That is the same use as ArchiveXL Transmog: `ResolveResource(factory, out, *entityFlat)`.
- The sibling 0x100CC0C6C returns `{path, bool}` (x0, x1) and is used only by 4 inventory/UI sites.

**AnimatedComponent_InitializeAnimations 0x100B97524**
- It resets the runtime setup at `+0x1B8/+0x1C8/+0x1D8`.
- For each attachment in `[+0x70]` (range `+0x80`/`+0x7C`) that is IsA `entAnimationExtensionAttachment` (class global 0x108DCA730, registration string at 0x100B4EA9C), it merges the source's AnimSetup through 0x100B4E7C8 → 0x1043BA4E4.
- It then merges its own `animations @+0x190` (SDK `anim::AnimSetup animations // 190`) and finalizes (0x1043BA610).
- Single caller: OnInitialize 0x100B96A38.
- The plugin's HookBefore push into `animations.gameplay` is consumed here.

**AppearanceChanger_GetSuffixes 0x10370D924**
- It is the only function using "AppearanceDefinitions"/"SuffixSeparator" (0x10370DAF4) and the TPP/FPP camera suffixes (0x10370DD7C). It has 19 callers.
- Caller 0x1035A249C:
  - `x8=&CString`;
  - `x0=&ownerHandle`, `x1=&overrideHandle` (zeroed);
  - `x2=&Handle<Item_Record>`, from 0x103739104, which copies `[itemObj+0x278]+0x50` as a Handle;
  - `x3=&ItemID`.
- The callee does `ldr x19,[x2]` and then reads the Item_Record (SDK size 0x478) cached flat at `+0x318`.

**EntityBuilder_ScheduleExtractComponentsJob 0x100CA08A0**
- It holds the only "EntityBuilder_ExtractComponents" descriptor init (guard 0x107599088) and creates lambda 0x100CA41E0 with a 0x18-byte `{EntityBuilder*, WeakPtr}` = EntityBuilderJobParams.
- It dispatches inline through `0x1009D46F0(desc, prio=[x1+0x28], x1+0x10, x1+0x18)`.
- No out-of-line `(JobQueue&, ?, Params*)` dispatcher exists. Hook this function and rebuild the weak pointer from `builder->self @+0`.

**InkWidgetLibrary_SpawnFromLocal 0x104965DE0 / SpawnFromExternal 0x104965EC0**
- The library API on mac is a closed set that maps 1:1 to the plugin's four hashes:
  - AsyncLocal 0x104965980 (confirmed);
  - AsyncExternal 0x104965B38 (confirmed);
  - Local (lib, name) → x8;
  - External (lib, path, name) → x8;
  - RootSpawn 0x104965DB4 (lib) → x8.
- Local and External use the same `+0x40/+0x4C/0x38` item search and then `WidgetLibraryItem::Spawn` 0x104923164.
- Local is reached from the controller spawn helper 0x1048D5F80: `[x1]` = library; name in x3; Local when the name is non-zero, else RootSpawn.
- That helper serves the script natives "SpawnFromLocal"/"SpawnFromExternal" (registration 0x1047C3C24).

**QuestLoader_ProcessPhaseResource 0x102ED6090**
- It is the only `(loader, ResourcePath, Handle<questQuestPhaseResource>&)` function in the phase-load completions. Callers 0x102EDA72C, 0x102EDADBC, 0x102EDB1E8 and 0x102EDB618 each IsA-check questQuestPhaseResource first.
- Two of those completions then call the nested-phase scan 0x102ED7E44 `(handle&, ctx)`. That scan takes no loader or path, so it cannot be the declared function.

**QuestRootInstance_Start 0x102D01878**
- x0 is `[QuestsSystem+0x68]`. 0x102EF5ED0 allocates 0x110 bytes there, runs ctor 0x102D00834 (which stores the questRootInstance vtable 0x1070FD348) and stores the Handle at `+0x68`.
- x2 is IsA-checked as questQuestResource. It returns bool.

**JournalTree_ProcessJournalIndex 0x101EA3410**
- It is the lambda behind the descriptor labelled "JournalTree/ProcessJournalIndex" (0x107CAF9B0).
- Standard job-lambda shape `(capture, RunContext&)`, matching the plugin's `(uintptr, JobGroup&)`.

**AttachmentSlots_IsSlotSpawning 0x103510644**
- The SDK `ITransactionSystem` declares `IsSlotEmpty @0x3C0` and `IsSlotSpawning @0x3C8` (MSVC).
- The mac TS vtable (address point 0x1072173A0):
  - +0x3C8 → 0x103896458 → `bl 0x1035104E4` (IsSlotEmpty, confirmed in pass 1);
  - +0x3D0 → 0x1038966A8 → `bl 0x103510644`.
- So the +8 Itanium shift independently pins IsSlotSpawning.

## Danger list (plugin declarations that corrupt memory or crash on mac)

1. **sret through x8.** The plugin passes the out-pointer as a normal argument, so the callee writes through whatever x8 holds and every later argument is shifted. Affected:
   - FindState (HookAfter: `aOut` = WeakHandle&, `aEntityWeak` = garbage);
   - ProcessGarment (full Hook: `aProcessor` is really `Handle<AppearanceDefinition>&`, `aParams` = x3 garbage, then `LinkEntityToAssembler` uses the wrong object);
   - ExtractPartComponents (HookAfter: `aResultObjects` = the token SharedPtr);
   - GetSuffixes;
   - SpawnFromLocal and SpawnFromExternal;
   - EntitySpawner_SpawnFromTemplate (HookBefore: `aRequest` = the ResourcePath hash, dereferenced → crash);
   - **SDK `ObjectPackageExtractor::ExtractAsync`**, which is called directly in ResourcePatch: arbitrary write through a stale x8.

   Any HookBefore/HookAfter trampoline must also preserve x8 when it calls the original.
2. **EntitySpawnerRequest offsets.** Writing `appearanceName` at +0xC0 overwrites the mac **recordID**. Use 0xA0/0xC0.
3. **GetSuffixes arg 3** is `const Handle<Item_Record>&`. `aItemRecord.recordID` reads beyond the 16-byte handle; use `aItemRecord->recordID`.
4. **FactoryIndex_ResolveResource** returns the path in x0. The plugin's `&overridePath` is read as the CName key, so the lookup misses and Transmog silently does nothing. It does not crash.
5. **ChangeItem/ChangeCustomItem.** Mapping these hashes to the dead copies 0x1036F887C/0x1036F89A4 would hook successfully and never fire. Hook the wrappers 0x1036F87E4/0x1036F890C with `(aggr, WeakHandle<Entity>&, req&)` instead.
6. **ScheduleExtractComponentsJob** is `(EntityBuilder*, JobQueue&)`. The plugin's `aParams->entityBuilderWeak` would read the JobQueue.
7. **Void declared, bool returned.** QuestRootInstance_Start returns bool; keep w0 intact in the detour.
