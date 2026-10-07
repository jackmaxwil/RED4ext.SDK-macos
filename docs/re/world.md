# RE group "world": macOS 2.3.1 arm64 address verification

The binary is `Cyberpunk2077.orig`. Its code is byte-identical to `Cyberpunk2077.app/Contents/MacOS/Cyberpunk2077`: `cmp` finds differences only in the header and code signature. Absolute addresses use image base `0x100000000`. Every new address is in `LC_FUNCTION_STARTS`, and each is at the real function start (no prologue offsets).

The tools are in the scratchpad: `xr.py` (cached ADRP/BL/data-pointer index), `d.py` (annotated disassembly), `vt.py` (vtable dump) and `cls.py` (RTTI class name → registration → class-pointer global → vtable).

## Table

| name | hash | old | new seg:off (absolute) | verdict | arm64 signature vs plugin declaration |
|---|---|---|---|---|---|
| AISpotPersistentDataArray_Reserve | 3842971216 | 1:0x3040DEC | **none**: the reserve is inlined at every call site | old **refuted**; no standalone function exists (unknown) | Synthesize it: `DynArray_Realloc(arr, cap, 0x20, 8, size? MoveAfterReallocation : null)`. See the evidence. |
| AIWorkspotManager_RegisterSpots | 2515346652 | 1:0x3DFFF44 | 1:0x3D515D0 (0x103D515D0) | confirmed | `void(AIWorkspotManager*, const DynArray<AISpotPersistentData>&)`. Matches. |
| InkSpawner_FinishAsyncSpawn | 2698985195 | 1:0xEECB90 | 1:0x49799B8 (0x1049799B8) | confirmed | Mac returns **void**; the plugin declares `bool`. This is harmless for HookBefore, because the virtual call site ignores the result. |
| InkWidgetLibrary_AsyncSpawnFromExternal | 1396063719 | 1:0xEECB90 | 1:0x4965B38 (0x104965B38) | confirmed | **MISMATCH**: mac is `bool(lib*, info*, ResourcePath, CName, bool w4)`. There is an extra 5th bool argument. |
| InkWidgetLibrary_AsyncSpawnFromLocal | 118698863 | 1:0xEECB90 | 1:0x4965980 (0x104965980) | confirmed | **MISMATCH**: mac is `bool(lib*, info*, CName, bool w3)`. There is an extra 4th bool argument. |
| InkWidgetLibrary_SpawnFromExternal | 506278179 | 1:0x596DBC | 1:0x4965EC0 (0x104965EC0) | likely | **MISMATCH (sret)**: mac is `Handle<ItemInstance> (lib*, ResourcePath x1, CName x2)`, with the result returned via **x8**. The plugin passes `Handle&` in x1. |
| InkWidgetLibrary_SpawnFromLocal | 1158555307 | 1:0x228794 | 1:0x4965DE0 (0x104965DE0) | likely | **MISMATCH (sret)**: mac is `Handle<ItemInstance> (lib*, CName x1)`, with the result returned via **x8**. |
| JournalManager_LoadJournal | 1964512489 | 1:0x378B8 | 1:0x1EAE820 (0x101EAE820) | confirmed | **MISMATCH (sret)**: mac is `JobHandle (IScriptable* x0)`, with the result returned via **x8**. The plugin passes `JobHandle&` in x1, so the callee writes through a garbage x8. |
| JournalManager_TrackQuest | 3274382593 | 1:0x2D3AD64 | 1:0x1EB17C0 (0x101EB17C0) | confirmed | `void(JournalManager*, Handle<JournalEntry>&)`. Matches, and a null handle is handled. |
| JournalRootFolderEntry_Initialize | 1945256833 | 1:0x1E7528C | 1:0x1E7528C (unchanged) | confirmed | Mac takes 3 args `(root, x1 handle&, JobQueue& x2)`; the plugin declares 4 with `JobQueue&` 4th. The plugin's hook uses only arg0, so this is harmless today. |
| JournalTree_ProcessJournalIndex | 837162664 | 1:0x1E9FE34 | 1:0x1EA3410 (0x101EA3410) | likely (old = the dispatcher, wrong) | `void(lambdaCapture*, JobGroup& x1)`. Matches the 2-arg declaration. The old function is `(owner, SharedPtr<JournalTree>&, JobQueue&)`, so the hook would build a JobQueue from a SharedPtr. |
| Localization_LoadLipsyncs | 1488657506 | 1:0x1405BC4 | 1:0x1AF9CCC (0x101AF9CCC) | confirmed | `void(ctx*, uint8 priority)`. Matches; the token is at ctx+0x188. |
| Localization_LoadOnScreens | 3550098299 | 1:0x13F68E0 | 1:0x2F67DB4 (0x102F67DB4) | confirmed | **MISMATCH (sret)**: mac is `Handle<OnScreenEntries> (ResourcePath x0)`, with the result returned via **x8**. The plugin passes `(Handle&, path)` in x0/x1. |
| Localization_LoadSubtitles | 772484645 | 1:0x13F68E0 | 1:0x2F67BE0 (0x102F67BE0) | confirmed | **MISMATCH (sret)**: mac is `Handle<SubtitleMap> (ResourcePath x0)`, with the result returned via **x8**. |
| Localization_LoadVoiceOvers | 4223669659 | 1:0x4293E48 | 1:0x1405334 (0x101405334) | confirmed | `void(jobCtx*, RunContext& x1)`. Matches; the HashMap is at ctx+0x8. |
| MappinSystem_GetMappinData | 3299551353 | 1:0x1D83A68 | 1:0x42A3E38 (0x1042A3E38) | confirmed | `CookedMappinData*(MappinSystem*, uint32)`. Matches. The function is only 16 bytes; see the hook risk below. |
| MappinSystem_GetPoiData | 620961393 | 1:0x2D3D108 | 1:0x42A3E68 (0x1042A3E68) | confirmed | `CookedPointOfInterestMappinData*(MappinSystem*, uint32)`. Matches. The function is only 16 bytes. |
| MappinSystem_OnStreamingWorldLoaded | 140387944 | 1:0x3314AE4 | 1:0x42A71A4 (0x1042A71A4) | confirmed | Mac is `(this, RuntimeScene*, a2, JobGroup&)`. The plugin declares only 2 args. This is harmless because x2/x3 are unused in the body. |
| PersistencySystem_SetPersistentStateData | 546121377 | 1:0x144EEFC | 1:0x3FEBC30 (0x103FEBC30) | confirmed | `void(x0 a1, DataBuffer* x1, x2 a3, w3 a4)`. Matches. |
| QuestLoader_ProcessPhaseResource | 790570700 | 1:0x2ED27D0 | 1:0x2ED6090 (0x102ED6090) | likely | `void(loader*, ResourcePath, Handle<questQuestPhaseResource>&)`. Matches. |
| QuestRootInstance_Start | 797843833 | 1:0x2EFD700 | 1:0x2D01878 (0x102D01878) | likely | Mac returns **bool**; the plugin declares void. Args `(root*, QuestContext*, const Handle<questQuestResource>&)` match. |
| QuestsSystem_OnGameRestored | 2048921710 | 1:0x2F03328 | 1:0x2EF8C58 (0x102EF8C58) | confirmed | Mac returns **bool** (always 1); the plugin declares void. A void-typed detour may hand back a garbage w0. |
| StreamingSector_PostLoad | 3972601611 | 1:0x3421748 | 1:0x3426204 (0x103426204) | confirmed | `void(sector*, const PostLoadParams& x1)`. Matches (as uint64). |
| StreamingWorld_Serialize | 410718963 | 1:0x3340510 | 1:0x342AD40 (0x10342AD40) | confirmed | `void(world*, BaseStream*)`. Matches. |

Counts:
- 17 confirmed and 5 likely: 22 resolved.
- 1 old value kept (JournalRootFolderEntry_Initialize).
- 1 with no standalone function (AISpotPersistentDataArray_Reserve).

Of the 24 old values, 23 were wrong: 22 replaced with new addresses, plus the Reserve entry, whose old value was refuted with nothing to replace it.

The shared-address bugs are resolved: `0xEECB90` (3 names) and `0x13F68E0` (2 names) each become distinct functions.

## Per-entry evidence

**AISpotPersistentDataArray_Reserve.**
- The old `0x103040DEC` returns `CName("AIbehaviorFreeReservedWorkspotNodeDefinition")`.
- There are only 3 code references to the GOT slot `0x106E262B8` (`red::DynArray<AI::SpotPersistentData>::MoveAfterReallocation`), and all are inline reallocations: `0x103D5160C` (in RegisterSpots), `0x103D510F8`, and `0x10149DC94` (a shrink of a different array at +0x68).
- No standalone reserve function exists.
- Recommended replacement: call the verified `DynArray_Realloc` (`1:0x286E8`) as `(arr, newCap, 0x20, 8, size ? Move : nullptr)`.
  - The move callback is the exported symbol `__ZN3red8DynArrayIN2AI18SpotPersistentDataEE21MoveAfterReallocationEPvS4_jPKv` at `0x10149EEE0` (resolve it with dlsym).
  - The element size is 0x20, which matches the SDK `ASSERT_SIZE`.

**AIWorkspotManager_RegisterSpots → 0x103D515D0.**
- It is slot +0x2A8 (data `0x10726B450`) of the vtable at address point `0x10726B1A8`. That vtable's slot 0 returns the class pointer `0x1090DB878`, which the `"AIWorkspotManager"` registration `0x103D553C4` sets.
- Body:
  - It reserves `this+0x48` to `new.size` when the capacity is too small. It uses DynArray_Realloc with elemSize 0x20, align 8, and the SpotPersistentData move callback.
  - It appends `new[i]` (stride 0x20).
  - If the dirty bit at `+0x58` is set, it stable-sorts (`0x103D55AE8`).
- The reserve is sized to `new.size`, not `size + new.size`. That is exactly the bug that ArchiveXL's pre-reserve works around, which confirms the identity.
- The old `0x103DFFF44` is a 0x5A4-byte function with a 256 KB stack frame, unrelated to this.

**InkSpawner_FinishAsyncSpawn → 0x1049799B8.**
- The async spawn job `0x104979398` (`ctx = {WeakHandle, SharedPtr<request>}`):
  - It allocates 0x28 bytes and stores vtable `0x107380E60` at +0, the weak handle at +8 and the request at +0x18. This is exactly `InkSpawningContext`.
  - It then calls the async spawn path with `req+0x80` (library), `req+0xA0` (externalLibrary) and `req+0x48` (itemName).
- Vtable `0x107380E60` slots: D1, D0, Clone, CloneInto, Destroy×2, and **slot 6 = 0x1049799B8**. The completion lambda `0x1049240C0` calls it as `ctx->vtbl[+0x30](ctx, &instance)`.
- Body: `req=[ctx+0x18]`, then:
  - `req->instance(+0x90) = inst`
  - `req->rootWidget(+0x60) = inst->rootWidget`
  - `req->gameController(+0x70) = inst->gameController`
  - `req+0x1AC = 3` (status)
- The plugin's offsets 0x18/0x48/0x60/0x70/0x90 are correct. The status byte is at 0x1AC, not the commented 0x184.

**InkWidgetLibrary_AsyncSpawnFromLocal → 0x104965980.**
- `(lib x0, info x1, CName x2, bool w3)`. If the name is 0, it uses `rootDefinitionIndex @+0x3C`.
- It linearly searches `libraryItems @+0x40` (count @+0x4C, stride 0x38, name via `0x1049239DC`), then calls `WidgetLibraryItem::AsyncSpawnFromDefPack 0x104922C90` (label "UI/WidgetLibraryItem/AsyncSpawnFromDefPack") with `(item, info, w3)`.
- The callers `0x1048D6584` and `0x1048DB32C` compute w3 from `[obj+0x171]` or a virtual call.
- Chain: script `AsyncSpawnFromLocal` → job `0x104979398` → `0x104831224` → `0x1048E48E0` → thunk → here.

**InkWidgetLibrary_AsyncSpawnFromExternal → 0x104965B38.**
- `(lib, info, path x2, CName x3, bool w4)`.
- `0x104965C90(lib, path)` resolves the external library (sret handle). It then does the same item search and calls `0x104922C90`.
- Called from the same job via `0x104831378` (`req+0xA0` = path).

**InkWidgetLibrary_SpawnFromLocal → 0x104965DE0.**
- `(lib x0, CName x1) → x8 sret Handle`. It does the same item search on `+0x40/0x4C/0x38` and tail-calls `WidgetLibraryItem::Spawn 0x104923164` with x8. If not found, it zeroes `[x8]`.
- Sibling: `0x104965DB4` spawns the root item (no name).
- Under the Windows/MSVC member ABI (`this`, sret, name), the plugin's `uintptr(lib&, Handle& out, CName)` is a Windows-ABI artifact.

**InkWidgetLibrary_SpawnFromExternal → 0x104965EC0.**
- `(lib, path x1, CName x2) → x8`. It calls `0x104965C90` to resolve the external library, does the item search, then `0x104923164(item, x8)`.
- Sibling `0x104966554` = HasExternalItem (bool).

**JournalManager_LoadJournal → 0x101EAE820.**
- `x8 = sret JobHandle`, `x0 = this`.
- Steps:
  1. Creates a JobQueue (`0x1009D420C`).
  2. Allocates the 0xC8-byte JournalTree (`0x101E9FB60`) into `this+0x58`.
  3. Calls tree-load `0x101EA05FC(tree, &selfHandle, &queue)`. That function loads `base\journal\index.reslist`.
  4. Calls `queue.Finish → x8` (`0x1009D4590`).
- Caller: `gameJournalManager` vtable slot 39 (`0x101EAE7DC`, data `0x106FA5C38`). The vtable address point is `0x106FA5A90`; its slot 0 returns `0x109009C88`, which the "gameJournalManager" registration `0x101EAA670` sets.
- The old `0x1000378B8` is a static initializer.

**JournalManager_TrackQuest → 0x101EB17C0.**
- It fires the `"OnQuestEntryUntracked"` / `"OnQuestEntryTracked"` events, IsA-checks the entry, and handles a null handle.
- It has 13 callers. One is JournalManager vslot +0x2A0 (`0x101EB59BC`): `entry = this->vfunc(+0x228)(path); TrackQuest(this, &entry)`.
- The old `0x102D3AD64` returns `String("Journal Quest")`.

**JournalRootFolderEntry_Initialize = 0x101E7528C (kept).**
- It contains the job label `"JournalRootFolderEntry/Initialize/LoadRootResource"` and the `"descriptor.journaldesc"` path build.
- Args: `x0` root, `x1` handle (`ldr x0,[x1]`), `x2` JobQueue (`ldrb [x2+0x28]`, `Wait(x2, job)`).

**JournalTree_ProcessJournalIndex → 0x101EA3410.**
- The dispatcher `0x101E9FE34` (the old value) loads `base\journal\index.reslist` and `test\journal\index.reslist`, then dispatches two jobs:
  - descriptor `0x107CAF9B0` = "JournalTree/ProcessJournalIndex" → lambda **0x101EA3410**;
  - descriptor `0x107CAF9F0` = "JournalTree/ProcessJournalRoots" → lambda `0x101EA3BD4`.
- The lambda is `(capture x0, RunContext/JobGroup x1)`, with the standard `[x1+0x20]` prologue. That is the shape of the plugin's `(uintptr, JobGroup&)`.
- The dispatcher's x1 is a `SharedPtr<JournalTree>*`, so hooking it would construct a JobQueue from the wrong object.
- Verdict: likely. The label-to-lambda link is certain; it is inferred that Windows hooks the job body.

**Localization_LoadLipsyncs → 0x101AF9CCC.**
- `(ctx, w1)`. It gets the LocalizationManager singleton (`0x108FEEDB0`) and language, and builds the path via `0x1043DFA60` (`"base\localization\"` + lang + `"lipmap"`).
- It stores the path at `ctx+0x180` and the token from `0x1021C63A4(path, w1 priority, x8)` at **ctx+0x188**. This matches the plugin's `LipMapToken` offset.
- Sibling `0x101AF9F28` reads `[ctx+0x188]` and IsA-checks it against `animLipsyncMapping`.
- The old `0x101405BC4` is a static initializer that hashes the volanguagedatamap paths.

**Localization_LoadOnScreens → 0x102F67DB4 / LoadSubtitles → 0x102F67BE0.**
- The two bodies are identical templates:
  1. Zero `[x8]`.
  2. `ResourceLoader(0x10900B580)->LoadAsync(x0 path)` via `0x1021B7130`.
  3. Wait (`0x1021C4D4C`).
  4. IsA against the class-pointer global, then move the handle into `[x8]`.
- The only difference is the class global:
  - `0x1090D1520`, set by the `"localizationPersistenceOnScreenEntries"` registration `0x102F68FB4`;
  - `0x1090D1500`, set by the `"localizationPersistenceSubtitleMap"` registration `0x102F68490`.
- The old `0x1013F68E0` (shared by both names) is `LocalizationManager::LoadEP1Data`, which dispatches the "ReloadOnScreensAndSubtitles" job.

**Localization_LoadVoiceOvers → 0x101405334.**
- It is the job lambda dispatched by `0x1013FDC1C` under label `"VoDatabase/LoadLanguageDataMaps"`. That dispatcher loads the `volanguagedatamap{,_rewinded,_holocall,_helmet}.json` tokens for base and ep1 into a `HashMap<uint32, DynArray<SharedPtr<ResourceToken>>>`.
- The lambda iterates the HashMap at **ctx+0x8** (fields +0x10/0x14/0x18/0x24) and IsA-checks JsonResource and the `VoLanguageDataMap` class (`0x108FEEE10`). It then copies into `VoDatabase+0x90`.
- The old `0x104293E48` is an inlined FNV hash of `"ep1\sound\localization\voicetaglist.voicetags"`.

**MappinSystem_GetMappinData → 0x1042A3E38 / GetPoiData → 0x1042A3E68.**
- Each is 16 bytes:
  - `ldr x0,[x0,#0x58]` (POI: `#0x68`)
  - `cbz`
  - `b` to the resource lookup `0x10429EED0` (POI: `0x1042BE574`)
- The lookup scans `cookedData @+0x40`, stride 0x20, compares the first u32 with w1, and returns the pointer or null.
- The sibling stubs `0x1042A3E48` and `0x1042A3E58` cover multi data (+0x50, stride 0x18) and GPS data (+0x60), which matches the SDK MappinResource.
- `0x1042A3E38` is called from `0x1042EFB04`. The virtual `0x1042B2748` (slot +0x260) is a different method: GetMappinPosition → bool.
- The old values were a 9.5 KB function and the `"Change POI Mappin Phase"` name string getter.

**MappinSystem_OnStreamingWorldLoaded → 0x1042A71A4.**
- It is gamemappinsMappinSystem vtable slot 48 (+0x180 = MSVC 0x178 + 8; data `0x1072D9A08`). The address point is `0x1072D9888`, with the D1/D0 pair at slots 3/4.
- It reads `scene+0x1B0`, loads two resource refs, IsA-checks them, and stores the handles into `this+0x58` (and `+0x68`), matching CookedMappinResource and CookedPoiResource.
- The old `0x103314AE4` is the generic "OnStreamingWorldLoaded" job dispatcher.

**PersistencySystem_SetPersistentStateData → 0x103FEBC30.**
- It is called from gamePersistencySystem vtable slot +0x180 (OnStreamingWorldLoaded, `0x103FF0F6C`):
  1. `world = scene+0x1B0`.
  2. Load `world+0x98` (persistentStateData), IsA.
  3. Call `0x103FEBC30(this+0xE8, &res->buffer(+0x40), this+0x48, 0x400000)`.
- The 4-arg shape and the buffer offset (SDK `PersistentStateDataResource::buffer @0x40`) match the plugin.
- The old `0x10144EEFC` is a decompression stream routine.

**QuestLoader_ProcessPhaseResource → 0x102ED6090.**
- `(loader, path, Handle&)`. It locks `loader+0x18`, then looks up the path in `HashMap@loader+0x20`; it increments the refcount if present, else inserts `{handle, 1}`.
- It is called by the four phase-load completions (job lambdas `0x102EDAD1C` and `0x102EDB148`, plus callbacks `0x102EDA6B8` and `0x102EDB5A4`). Each of these first IsA-checks `questQuestPhaseResource` (class getter `0x102ED21E4`). Each then calls `0x102ED7E44`, which scans the phase graph for nested phases.
- A HookBefore here therefore patches before that scan.
- Verdict: likely (no symbol or label).
- The old `0x102ED27D0` returns `"Quest Phase"`.

**QuestRootInstance_Start → 0x102D01878.**
- It is the sole call site in the quest-start job `0x102F00ED4`:
  1. Build a QuestContext on the stack via `0x102CF313C`. The ctor writes `phaseStack @+0xF8`, `phaseContext @+0x110` and a back-pointer at `+0x330`, consistent with the plugin's 0x340-byte layout.
  2. Call `Start([qs+0x68] root, &ctx, &Handle<questQuestResource>)` after an IsA check with the `questQuestResource` getter `0x102ED3404`.
- It lives in the questRootInstance code block (vtable fns `0x102D00870`–`0x102D01784`, registration `0x102D02544`). It returns bool.
- The old `0x102EFD700` is a one-arg QuestsSystem method. It also confirms the QuestsSystem offsets: lock +0x60, map +0x78, list +0xA8.

**QuestsSystem_OnGameRestored → 0x102EF8C58.**
- It is questQuestsSystem vtable slot 43 (+0x158 = MSVC 0x150 + 8). The address point is `0x107148E60`, with D1/D0 `0x102EF58E8` and `0x102EF58EC`.
- Cross-check: slot +0x150 takes `(this, JobGroup&, bool&, stream)`, which is OnGameLoad.
- Body: call `[this+0x190]->vfunc(+0xB8)`, set the flags at `+0x1AC`/`+0x1AE`, then `return 1`.
- The old `0x102F03328` is a log-channel helper (`"GameSystem/QuestsSystem/PrefabHandler"`).

**StreamingSector_PostLoad → 0x103426204.**
- It is worldStreamingSector vtable slot 6 (+0x30 = MSVC PostLoad 0x28 + 8). The address point is `0x1071B3490`; its slot 0 returns the class global `0x1090D4DD0`, which the "worldStreamingSector" registration sets.
- It calls the base `ISerializable::PostLoad 0x102185F28`, then processes `NodeBuffer @+0x40` (`0x1032BCE38`).
- The old `0x103421748` is an unrelated token-load job lambda.

**StreamingWorld_Serialize → 0x10342AD40.**
- It is worldStreamingWorld vtable slot 9 (+0x48 = MSVC `sub_40(BaseStream*)` + 8). The address point is `0x1071B3AA8`.
- Body: call the base serializer `0x102185F34(this, stream)` (it reads stream flags at `[x1+8]`), then `0x10342AD84(stream, this+0x1C8, tmp)` for native data.
- The old `0x103340510` returns `CName("worldPackageNodeRefSerializer")`.

## Cross-cutting dangers (beyond the addresses)

1. **Struct return on arm64 (sret in x8).** On Windows these functions take a hidden return pointer as a normal argument. On arm64 the result address goes in x8 instead. Five functions are affected: LoadJournal, LoadOnScreens, LoadSubtitles, SpawnFromLocal and SpawnFromExternal.
   - Called with the current declarations, the game writes the result through whatever x8 holds, and the plugin's out-argument lands in the parameter slot.
   - **The declarations must change to by-value returns** before these hashes are enabled:
     - `Handle<T> (*)(ResourcePath)`
     - `JobHandle (*)(IScriptable*)`
     - `Handle<ItemInstance> (*)(Lib*, [ResourcePath,] CName)`
2. **Extra bool parameter on the two AsyncSpawn functions.** The plugin's detour forwards only 3 or 4 arguments, so w3 or w4 reaches the game as garbage.
3. **ArchiveXL `RawVFunc` offsets are MSVC offsets.** `lib/Core/Raw.hpp` does no Itanium adjustment.
   - Affected: JournalManager `0x1F8, 0x208, 0x220, 0x230, 0x298, 0x2A0` and QuestsSystem::ForceStartNode `0x240`.
   - On macOS each is +8. For example, TrackQuestByPath is at +0x2A0 and TrackPointOfInterest at +0x2A8; both were checked by disassembly. The current code calls the wrong virtuals.
4. **Itanium tail-padding reuse changes SDK layouts.**
   - The `inkWidgetLibraryResource` RTTI property registration (`0x104964FC8`) gives these mac offsets:

     | Field | mac | SDK |
     |---|---|---|
     | rootResolution | 0x39 | 0x40 |
     | rootDefinitionIndex | 0x3C | 0x44 |
     | libraryItems | 0x40 | 0x48 |
     | externalLibraries | 0x50 | 0x58 |
     | animationLibraryResRef | 0x60 | 0x68 |
     | sequences | 0x78 | 0x80 |
     | externalDependenciesForInternalItems | 0x88 | 0x90 |

   - The cause: CResource ends with a 1-byte field at 0x38, and clang packs derived members into its tail padding.
   - ArchiveXL `InjectDependency` (`aLibrary.externalLibraries.EmplaceBack`) therefore writes into the wrong field on mac.
   - Any SDK struct deriving from a non-POD base with tail padding is suspect. The fields are packed only when the derived class's first member is less than 8-byte aligned; gameMappinResource, whose first member is a DynArray, is unaffected.
   - Also on mac: `InkSpawningInfo.context` is at **+0x18** (the plugin assumes +0x38; unused by the hooks).
5. **The Mappin stubs are exactly 16 bytes.** Each is `ldr`, `cbz`, `b`, `ret`, and the next function starts right after. The hook patch must fit in 16 bytes and must relocate the `cbz` and the tail `b`, otherwise it overwrites the next function. A safer alternative is to hook the resource-level lookups `0x10429EED0` and `0x1042BE574` (`(resource, hash)`, 0x48 bytes each).
6. `get_r8`/`set_r8` are no-ops on mac. That is fine: the arm64 caller of GetMappinData (`0x1042EFB04`) does not rely on extra result registers.
7. **Return type declared void where mac returns bool.** QuestsSystem_OnGameRestored and QuestRootInstance_Start return bool on mac; both are declared void.
   - The only caller of Start (`0x102F01004`) ignores the result.
   - OnGameRestored is a virtual (IGameSystem `bool OnGameRestored()`). Its dispatcher was not checked, so its caller may use the result.
   - Declare both as `bool` and return the original's value.
