# RE results: group "resources" (macOS 2.3.1 arm64, UUID A6656ADC-...)

All "new" addresses are in LC_FUNCTION_STARTS (checked with the function-start list, 32/32). Absolute = 0x100000000 + offset.
Static analysis only. Tools/index used: `scratchpad/res/` (q.py over B/BL, ADRP+ADD/LDR, ADR, chained-fixup pointer indexes).

**ABI reminder for this group.** Every function the Windows build declares as "returns a struct through a hidden out-pointer" (SharedPtr, Handle, JobHandle, ResourcePath, ObjectPackageHeader, MeshMaterialsToken) uses **x8** for that pointer on arm64. The out-pointer is not passed as x1, so every argument after `this` moves up one register. ResourcePath (8 bytes, trivially copyable) comes back in **x0** as a value. To get x8 from clang, declare the return by value with a non-trivial type (SDK `SharedPtr`/`Handle`/`JobHandle` have destructors, so they qualify). A trivially-copyable 16-byte struct would come back in x0/x1 instead.

| name | hash | old | new seg:off (absolute) | verdict | arm64 signature vs plugin declaration |
|---|---|---|---|---|---|
| CBaseEngine_InitEngine | 3273923080 | 1:0x3D73CF8 | 1:0x3D9E494 (0x103D9E494) | confirmed | `bool(CBaseEngine*, CGameOptions*)`: matches |
| CBaseEngine_LoadGatheredResources | 3729789488 | 1:0x3D9F0F8 | 1:0x3D9EFC8 (0x103D9EFC8) | confirmed | `bool(CBaseEngine*)`: matches |
| CMesh_AddStubAppearance | 555290091 | 1:0xACAE08 | 1:0xE16E68 (0x100E16E68) | confirmed | `void(CMesh*)`: matches |
| CMesh_FindAppearance | 3007126651 | 1:0xACAE08 | 1:0xE189F4 (0x100E189F4) | confirmed | `Handle<MeshAppearance>&(CMesh*, CName)`: matches |
| CMesh_GetAppearance | 773462733 | 1:0xACAE08 | 1:0xE199D8 (0x100E199D8) | confirmed | `Handle<MeshAppearance>&(CMesh*, CName)`: matches |
| CMesh_LoadMaterialsAsync | 701648326 | 1:0x23AC3C | 1:0xE18C28 (0x100E18C28) | confirmed | **MISMATCH**: `MeshMaterialsToken(x8 out; CMesh* x0, const DynArray<CName>& x1, u8 w2)` vs plugin `(mesh, token&, names, a4)` |
| CMesh_PostLoad | 2272530537 | 1:0x1DF1EC | 1:0xE16B28 (0x100E16B28) | confirmed | `void(CMesh*, PostLoadParams*)`: matches |
| CMesh_ShouldPreloadAppearances | 503977943 | 1:0xC27788 | 1:0xE173FC (0x100E173FC) | confirmed | `bool(CMesh*)`: matches |
| DeferredDataBuffer_LoadAsync | 4125893577 | 1:0x2189040 | 1:0x226258C (0x10226258C) | confirmed | **MISMATCH**: `x0=buffer, x1=int64 arg, x8=16-byte result (JobHandle at +8)` vs SDK `(buffer, JobHandle*, 0)` |
| FactoryIndex_LoadFactoryAsync | 1886854234 | 1:0x417704C | 1:0xCC0710 (0x100CC0710) | confirmed | `void(index*, ResourcePath, JobHandle* ctx)`: matches (plugin uses uintptr_t for ctx) |
| FactoryIndex_ResolveResource | 3040549301 | 1:0x7B4670 | 1:0xCC0BEC (0x100CC0BEC) | likely | **MISMATCH**: `ResourcePath(index* x0, CName x1)`, returned in x0, vs plugin `(index, ResourcePath& out, CName)` |
| GameApplication_InitResourceDepot | 2923109755 | 1:0x1704194 | 1:0x1704194 (unchanged) | confirmed | `void(CGameApplication*, params*)`: matches |
| MeshAppearance_LoadMaterialSetupAsync | 1419388740 | 1:0xB30B3C | 1:0xE1F7B4 (0x100E1F7B4) | confirmed | **MISMATCH**: `Handle<MeshAppearance>(x8 out; MeshAppearance* x0, u8 w1)` vs plugin `(app&, Handle& out, u8)` |
| MeshMaterialBuffer_LoadMaterialAsync | 1609519068 | 1:0x3D73CF8 | 1:0xE27A4C (0x100E27A4C) | confirmed | **MISMATCH**: `SharedPtr<ResourceToken<IMaterial>>(x8 out; buf x0, const Handle<CMesh>& x1, u16 w2, u64 x3, u8 w4)` vs plugin `(buf, out&, mesh, idx, a5, a6)` |
| MorphTargetMesh_PostLoad | 1523127443 | 1:0x1DF1EC | 1:0xE467BC (0x100E467BC) | confirmed | `void(MorphTargetMesh*, PostLoadParams*)`: matches |
| ObjectPackageExtractor_ExtractAsync | 3819248393 | 1:0x21001B4 | 1:0x2150A60 (0x102150A60) | likely | **MISMATCH**: `x0=extractor, x8=16-byte result (JobHandle at +8)` vs SDK `(extractor, JobHandle&)` |
| ObjectPackageExtractor_ExtractSync | 2038372664 | 1:0x21000F0 | 1:0x2150CE4 (0x102150CE4) | confirmed | `void(ObjectPackageExtractor*)`: matches |
| ObjectPackageExtractor_Initialize | 2318998714 | 1:0x20FFF50 | 1:0x2150648 (0x102150648) | confirmed | `void(extractor*, const params&)`: matches |
| ObjectPackageReader_OnReadHeader | 1632836642 | 1:0x21003BC | 1:0xCAAB24 (0x100CAAB24) | confirmed | `void(reader*, u64, stream*)`: matches the SDK's (this, a1, a2) |
| ObjectPackageReader_ReadHeader | 1285757088 | 1:0x21004E4 | 1:0xCAAA74 (0x100CAAA74) | confirmed | **MISMATCH**: `ObjectPackageHeader(x8 out 0x70; reader* x0)` vs SDK `(reader, header&)` |
| ResourceDepot_CheckResource | 43194193 | 1:0x3ED9E9C | 1:0x3ED9E9C (unchanged) | confirmed | `bool(depot*, ResourcePath)`: matches |
| ResourceDepot_InitializeArchives | 2885423437 | 1:0x3ED96B0 | 1:0x3ED96B0 (unchanged) | confirmed | `void(depot*)`: matches |
| ResourceDepot_LoadArchives | 2517385486 | 1:0x3EDA488 | 1:0x3EDA488 (unchanged) | confirmed | minor: macOS has a **6th arg w5** (fatal-error exit code; callers pass 2). Plugin passes 5 args, so w5 is garbage, but it is read only on the fatal path. x0 is unused, so the plugin's nullptr is fine |
| ResourceDepot_RequestResource | 2450934495 | 1:0x3ED9B94 | 1:0x3ED9B94 (unchanged) | confirmed | **MISMATCH**: `SharedPtr<...>(x8 out; depot x0, ResourcePath x1, const ArchiveHandle* x2)` vs plugin `(depot, out*, path, archive*)`. This is a full Hook, so it is dangerous |
| ResourceLoader_FindTokenFast | 3362732471 | 1:0x21BC5D0 | 1:0x21B80F4 (0x1021B80F4) | confirmed | **MISMATCH**: `SharedPtr<Token>(x8 out; loader x0, ResourcePath x1)` vs SDK `(loader, out*, path)` |
| ResourceLoader_IssueLoadingRequest | 2365013187 | 1:0x21BC6D4 | 1:0x21B71CC (0x1021B71CC) | confirmed | **MISMATCH**: `SharedPtr<Token>(x8 out; loader x0, const ResourceRequest* x1)` vs SDK/plugin `(loader, out&, request&)`. The same hash is ArchiveXL's `ResourceLoader_RequestResource` (HookBefore) |
| ResourceLoader_IssueLoadingRequestByPath | 1250309504 | 1:0x21BC74C | 1:0x21B7130 (0x1021B7130) | confirmed | **MISMATCH**: `SharedPtr<Token>(x8 out; loader x0, ResourcePath x1)` vs SDK `(loader, out&, path)` |
| ResourceLoader_OnUpdate | 1303056161 | 1:0x2D9766C | none | refuted / unknown | old candidate is workspot code; no verified replacement |
| ResourceSerializer_Deserialize | 2901686778 | 1:0x21AC670 | 1:0x225921C (0x10225921C) | confirmed | 8 args in x0..x7, same order: matches |
| ResourceSerializer_Load | 2577814646 | 1:0x21AC670 | 1:0x2255B4C (0x102255B4C) | likely | `(this, source x1, request& x2, cbctx x3, deferral x4)`: matches the plugin order |
| ResourceSerializer_OnDependenciesReady | 1185093671 | 1:0x20AB510 | 1:0x22575C0 (0x1022575C0) | confirmed | `void(ResourceSerializerContext*)`: matches |
| ResourceToken_CancelUnk38 | 4142009574 | 1:0x12F0800 | 1:0x418FB00 (0x10418FB00) | confirmed | `void(void* unk38)`: matches |
| ResourceToken_DestructUnk38 | 2508398574 | 1:0x12F080C | none (inlined) | refuted / unknown | no standalone function on macOS (see evidence) |
| ResourceToken_OnLoaded | 3947570603 | 1:0x12F0604 | 1:0x21C4E84 (0x1021C4E84) | confirmed | **MISMATCH**: `JobHandle(x8 out; token x0, LoadedCallback* x1)` vs SDK `(token, JobHandle*, callback*)` |

Counts: 34 entries. 32 resolved (29 confirmed, 3 likely). 5 old addresses were already right: 4 ResourceDepot and 1 GameApplication. 2 entries have no address: OnUpdate is unknown and DestructUnk38 does not exist as a function. 12 hard signature mismatches: 11 from x8 / indirect return, and ResolveResource returns in x0. LoadArchives also has a minor extra 6th argument.

## Evidence

**CBaseEngine_InitEngine → 0x103D9E494**
- CBaseEngine vtable (stored by ctor 0x103D98258 at `str x8,[x0]`, address point 0x10726FC28), slot 39 (0x10726FD60).
- The game-engine override 0x1035F0A08 (vtable 0x1071DDE18) reads `[x1+0x10]` (watchdogTimeout) and `[x1+2]` (renderPreset) of CGameOptions, then tail-calls `b 0x103D9E494`.
- The body inits subsystems with labels "ViewportManager", "GameServices", "RendererInit", "GatheredResources", "InkSystem", and "FAILED - Renderer"/"FAILED - InkSystem". It returns w0.
- Old 0x103D73CF8 has 0 callers and references "engine\materials\internal\multilayered_baked.mt" and "engine\materials\fallback.remt". It is engine material setup, not InitEngine and not MeshMaterialBuffer.

**CBaseEngine_LoadGatheredResources → 0x103D9EFC8**
- Calls `engine->vtbl[0xD8]`, then a bool check.
- On failure it asserts "Not all Gathered Resources were loaded!" (baseEngineInit.cpp:0x45F, stub 0x103DA2A64). It returns 1.
- Its only callers are 2 call sites inside InitEngine, right before the "GatheredResources" label.
- Old 0x103D9F0F8 is CBaseEngine vtable slot 40, which registers the "BaseEngine/Initialization/*" jobs. Refuted.

**CMesh_PostLoad → 0x100E16B28**
- "CMesh" is registered by 0x100E1B3C4 (class size 0x230). The class pointer is stored at 0x108DCCB20. GetNativeType 0x100E12A00 loads it.
- That getter is slot 0 of the vtable at 0x106EF0990. Slot 6 (+0x30) = 0x100E16B28.
- The engine calls PostLoad through `vtbl+0x30`: ExtractSync 0x102150E34 and OnDependenciesReady use it.
- The function first calls base ISerializable::PostLoad (0x102185F28, a bare `ret`). It then writes `appearance+0x50 = this` for every appearance in `+0x1E0/+0x1EC`. That matches ArchiveXL `MeshAppearance::Owner` at 0x50.
- Old 0x1001DF1EC is PhysX TriangleMeshBuilder. Refuted.

**MorphTargetMesh_PostLoad → 0x100E467BC**
- "MorphTargetMesh" is registered by 0x100E470E4 (class size 0xD0). The class pointer is at 0x108DCCCD0. GetNativeType 0x100E459FC is in vtable 0x106EF5148, and slot 6 = 0x100E467BC.
- Slot 5 = 0x100E467B8, which is `b` to the base sub_20. This pins the slot numbering.

**CMesh_AddStubAppearance → 0x100E16E68**
- Its only caller is CMesh::PostLoad (0x100E16BF4), taken when `appearances.size == 0`.
- It allocates a MeshAppearance, constructs it with the static CName at 0x108DCCB40 (the same "default" name that GetAppearance falls back to), and appends it to `+0x1E0`.
- On macOS the game already gates this on `size==0`. ArchiveXL's replacement adds its own condition (blob / surfaceArea), so behaviour differs but stays safe.
- Old 0x100ACAE08 references "engine\fallback\helper_no_appearance_proxy.mesh" (entity proxy helper). Refuted for all three names that shared it.

**CMesh_FindAppearance → 0x100E189F4** (4 callers)
- Linear scan of `+0x1E0` comparing `appearance+0x30` (name) with x1. Returns a pointer to the Handle slot.
- On a miss it returns a static empty Handle (0x10769AE10/…E18).

**CMesh_GetAppearance → 0x100E199D8** (57 callers)
- Calls FindAppearance(name). If the Handle is null it tail-calls FindAppearance(mesh, static CName 0x108DCCB40), i.e. falls back to "default".

**CMesh_ShouldPreloadAppearances → 0x100E173FC**
- Returns true when `appearances.size == 1 && !mesh[+0x6D]`. Otherwise it looks up the command-line switch "forceLoadAllMeshAppearances".
- Called from MeshAppearance::LoadMaterialSetupAsync with the owner mesh. Old 0x100C27788 is entity-static warning code. Refuted.

**CMesh_LoadMaterialsAsync → 0x100E18C28**
- Job label "CMesh/IssueLoadMaterials/OnLoaded". Takes the lock at `mesh+0x218`, which matches ArchiveXL `CMesh::MaterialLock` OffsetPtr<0x218>.
- `str w2,[sp,#0x4c]` (a4), x1 = names, and the result goes through x8.
- Callers: MeshAppearance::LoadMaterialSetupAsync (0x100E1F948, `x8=sp+0x50`) and 0x100E20070. Old 0x10023AC3C is PhysX NpShape. Refuted.

**MeshAppearance_LoadMaterialSetupAsync → 0x100E1F7B4** (28 callers)
- Job label "MeshAppearance/IssueLoadRenderMaterialSetup/ProcessResults". Prologue: `mov x20,x1 (priority u8); mov x21,x0; mov x19,x8`.
- Writes its own Handle (from ISerializable weak self) to `[x19]`. Uses owner `[x0+0x50]` to call CMesh::LoadMaterialsAsync.
- Old 0x100B30B3C is "Mesh Material Parameter" RTTI. Refuted.

**MeshMaterialBuffer_LoadMaterialAsync → 0x100E27A4C**
- Formats "localmaterial_%08X[%08X].res" from w2 (index), locks `buffer+0x68`, and looks up the token. Writes 16 bytes to `[x8]`.
- Call site 0x100E18EE4: `ldrh w2,[x21,#0x28]; x8=out; x1=&meshHandle; x3=0; w4=a4`.

**DeferredDataBuffer_LoadAsync → 0x10226258C** (12 callers)
- Job label "DeferredDataBuffer/CreateLoadingJobs". Spin-locks `+0x55` and bumps `+0x50`, which matches the SDK layout (state 0x54, lock 0x55).
- Captures a JobQueue and moves the JobHandle into `[x8+8]`. Callers read `out+8` as the JobHandle (0x100AD2888, 0x104012C74).
- Old 0x102189040 is the DeferredDataBuffer RTTI type registration (strings "DeferredDataBuffer", "serializationDeferredDataBuffer"). It is also the shared LoadRefAsync value, so that entry is wrong too.

**FactoryIndex_LoadFactoryAsync → 0x100CC0710**
- Job label "ParseFile". Issues `IssueLoadingRequest(loader, {path})` and queues a parse job into the x2 context.
- Its only caller is the "CreateEntryMap" job 0x100CC10DC, which calls it once per factory row: `x0=index, x1=ResourcePath(row[0]), x2=&JobHandle`.
- Old 0x10417704C is unrelated (ping/audio array code). Refuted.

**FactoryIndex_ResolveResource → 0x100CC0BEC** (likely)
- Hash-map lookup on `index+0x68/+0x70/+0x74/+0x78` keyed by x1. Returns `entry->[+0x18]->[0]` (ResourcePath) in x0, or 0. 12 callers.
- Sibling 0x100CC0C6C returns {path, bool} in x0/x1.
- Not "confirmed" because no string ties it to the Windows name. Old 0x1007B4670 is ICU number formatting. Refuted.

**GameApplication_InitResourceDepot = 0x101704194** (unchanged)
- CGameApplication vtable slot (0x106F4FF30). Reads `params+0xC0/0xC8/0x100`, allocates 0x80 bytes, and calls the ResourceGameDepot ctor (0x103ED99FC → 0x103ED9578). Stores the result to `app+0x198`.
- The next slot, 0x1017043A4, creates the ResourceLoader and stores it to the global 0x10900B580. The DB entry "ResourceDepot" (1:0x17043A4) therefore points at code, not data. That entry is not in this worklist.

**ResourceDepot_InitializeArchives = 0x103ED96B0** (unchanged)
- Its only caller is the ResourceGameDepot ctor (0x103ED9680). It locks `+0x78`.
- Reaches "Failed to find any archives in the base data directory" (stub 0x103EDED18) and the add-content loader 0x103EDAFCC. The ctor then asserts `!m_archives.Empty()`.

**ResourceDepot_LoadArchives = 0x103EDA488** (unchanged)
- References "Could not open archive %hs…", "Failed to create the archive", "Failed to load archive %hs, error %u…" and "LoadEntireArchiveIntoMemory failed" (through its stubs). Its ten callers are in the 0x103EDA0C8, 0x103EDA684 and 0x103EDAAE8 enumerators, after "*.archive".
- Arguments: x1 = group, x2 = paths (stride 0x20), x3 = loaded-paths output, w4 = memoryResident (`cmp w20,#1`), w5 = exit code passed to `0x100002E94(3, w5)` on fatal error.

**ResourceDepot_RequestResource = 0x103ED9B94 / CheckResource = 0x103ED9E9C** (unchanged)
- ResourceGameDepot vtable 0x10728A630, slots 3 and 4.
- RequestResource: `mov x20,x8` (out), x1 = path value, x2 → archive handle (`ldr w8,[x21]`). Shared lock at `+0x78`. Stores {ptr, refcount} to `[x20]`.
- CheckResource: `bool(depot, path)` through lookup helper 0x103ED9EEC.

**ResourceLoader_IssueLoadingRequestByPath → 0x1021B7130** (117 callers; callers load the loader from global 0x10900B580)
- Builds a ResourceRequest on the stack (path at +0, archiveHandle −1 at +0x18) and calls the internal 0x1021B7250 with x8.

**ResourceLoader_IssueLoadingRequest → 0x1021B71CC** (42 callers)
- Same flow, taking `request*` in x1.

**ResourceLoader_FindTokenFast → 0x1021B80F4**
- Internal 0x1021B7250 takes the shared lock on `loader+0x40` (the SDK's tokenLock), calls 0x1021B80F4 with `x8=out, x1=path`, then releases with `ldaddalb -1`.
- The body is the tokens HashMap at `loader+0` (key hash `hi^lo`, node stride `+0x1C`). It locks the WeakPtr into a SharedPtr written to `[x8]`.
- Old 1:0x21BC5D0 (also the DB "ResourceLoader" value) is the "ResourceLoaderThrottler" config registration. Old 0x21BC6D4 and 0x21BC74C are inside that same function. Refuted.

**ResourceToken_OnLoaded → 0x1021C4E84** (46 callers)
- Job label "ResourceToken/OnLoaded". Reads token weak count `+8` and job `+0x50`. Moves the callback from x1 (`[x1+0x18]`, size `[x1+0x28]`).
- Ends with JobQueue::Capture into x8 (0x1021C50C0).
- Old 0x1012F0604 is a vehicle-light function that uses tokens. Old 0x1012F0800 and 0x1012F080C are inside it. Refuted.

**ResourceToken_CancelUnk38 → 0x10418FB00**
- Token dtor 0x1021C4A14 (thunk 0x1021C4BC4, 1193 callers): `if (!finished && !error) 0x10418FB00([tok+0x38])`. That is exactly the SDK `~ResourceToken` condition.
- The target sets a cancel byte at `+0x56` and calls a virtual.

**ResourceToken_DestructUnk38: none**
- In the dtor, the SharedPtr<Unk38> release at `+0x38/+0x40` is inlined: `ldaddal -1` on `[+0x40]`, DeleteHelper, then destroy the object (`+0x40` vtbl[3], small-buffer functor `+0x18`) and free.
- 0x10095EEF4 has the same pattern for another holder (`+0x28`, probably DeferredDataBufferCopyToken) but is a whole object dtor.
- Fix: the SDK must implement the release inline or drop the call. Do not map this hash.

**ResourceSerializer_OnDependenciesReady → 0x1022575C0**
- The "Serialization/WaitForDependencies" job lambda 0x102257548 reads `ctx->loader` (`[ctx+0x1E0]` = request 0x1D0 + 0x10). It calls 0x1021BBAE8 (throttler) with fn = 0x1022575C0 and arg ctx.
- 0x1022575C0 uses `ctx+0x1D0` (request) and `ctx+0x230/0x23C` (serializables). It invokes the completion callback with `(ctx+0x230, …)`.
- Exact match to the SDK `ResourceSerializerContext` layout. Old 0x1020AB510 is "Scene was not ready" code. Refuted.

**ResourceSerializer_Deserialize → 0x10225921C**
- Uses `x4+0x28` (path), `x4+0x30` (path copy), `x4+0x58` (flags bits 3/5), and `x6` (results).
- Called by 0x10225646C with `x6 = ctx+0x230, x4 = request, x3 = &job`. Matches the ArchiveXL struct offsets.

**ResourceSerializer_Load → 0x102255B4C** (likely)
- Slot 2 of the binary loader vtable 0x1070018B8. Allocates the 0x270-byte context (ctor 0x102255A50 initialises `+0x1D0` and `+0x230`) and copies the 0x60-byte request from x2 into `ctx+0x1D0`.
- Calls the WaitForDependencies scheduler 0x10225646C.
- Old 0x1021AC670 is an RTTI wrapper ("Cannot cross pointer boundary…"). It was shared with Deserialize. Refuted.

**ObjectPackageExtractor_Initialize → 0x102150648**
- Factory 0x102151414 (11 callers) allocates 0x120 bytes (the SDK size), default-inits with 0x10215038C, then tail-calls 0x102150648(ext, params).
- That function copies the header (0x58 bytes) to `+0x10`, `params+0x58` (loader) to `+0xA0`, and the DynArray `+0x68`. Matches the SDK.

**ObjectPackageExtractor_ExtractSync → 0x102150CE4**
- If `!disableImports(+0xB9)`: loads imports (0x102150B4C) and spin-waits until the tokens at `+0xD0` are finished.
- Serializes synchronously (0x102151294), then, if `!disablePostLoad(+0xB8)`, calls `objects(+0xC0)[i]->vtbl[0x30]` with `{disablePreInit(+0xBA)}`.

**ObjectPackageExtractor_ExtractAsync → 0x102150A60** (likely, 7 callers)
- Imports and token-wait join, then `Serialize(0x10214FF4C "PackageObjectLoader_Serialize")` and `PostLoad(0x10215016C)` into a JobQueue. Captures it and moves the JobHandle to `[x8+8]`. Callers read `out+8`.
- Not "confirmed" because 0x102150F5C (extractor, JobQueue&) is a second async variant. The old values 0x1020FFF50…0x1021004E4 are all "redEvent"/"Event" RTTI registration. Refuted.

**ObjectPackageReader_ReadHeader → 0x100CAAA74** (21 callers)
- The reader ctor 0x100CAAA10 sets vtable 0x106ED4028 and `rootIndex(+0x18) = -1`.
- 0x100CAAA74 calls base PackageReader::ReadHeader (0x10214FA38, which returns a PackageHeader via x8). It then copies `reader+0x18…+0x88` (0x70 bytes) to `[x8]`.

**ObjectPackageReader_OnReadHeader → 0x100CAAB24**
- Slot 2 of the ObjectPackageReader vtable. Base ReadHeader dispatches through `vtbl+0x10`.
- Reads the CRUID count and sets the span at `reader+0x20/0x28` (`header.cruids`).

**ResourceLoader_OnUpdate: unknown**
- Old 0x102D9766C references "Unknown problem in workspot resource!…" (AI workspot). Refuted.
- No per-frame loader method was found with string or vtable evidence.
- Leads, unverified, do not ship: the thunks 0x1021B99A8 and 0x1021B99C8 (`loader->bank(+0x48)` → EvictResources 0x1021B5548 / 0x1021B5BE0), called with the loader global from engine code 0x103D99938 and CBaseEngine slot 15 (0x103DA1FC4).
- Recommend ArchiveXL trigger its reload from a verified per-frame hook instead.

## Not in this worklist but found along the way
These are useful anchors only. None of them is verified for the DB.
- ResourceToken dtor: 0x1021C4A14.
- ResourceToken::Fetch: 0x1021C4D4C. It returns `Handle&`; factory code uses it right after IssueLoadingRequest. The DB has 1:0x12F06B0, which is wrong (it is inside the vehicle function).
- ObjectPackageReader ctor: 0x100CAAA10. The DB has 1:0x2100250, which is wrong.
- ResourceLoader singleton: data pointer at 0x10900B580, written by 0x101704414.

## Crash 0x1D50D24
None of the old candidates in this worklist is near it. 0x101D50D24 is `ldr w12,[x9]` in 0x101D50CE8, a loop over `this+0x108` (count at `+0x114`). That code is game::input::ContextManager/ContextLoaderXML (caller chain 0x101D53500 ← 0x101D5300C / 0x101D6C2B0), so `this` was bad. That points at an input-context hook in another group, not at a resource hook.
