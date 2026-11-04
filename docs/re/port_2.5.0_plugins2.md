# 2.5.0 macOS addresses for upstream TweakXL, ArchiveXL and Codeware (patch 2.5)

Game 2.5.0, binary UUID 7D7382D0-EADD-36F0-BA1C-CEBEC1D5BEBC. Each section below is one RE batch: a table, then the
evidence for every FOUND entry (two independent pieces at least, plus an arm64 signature check against the upstream
declaration). FOUND entries are `"verified": true` in `cyberpunk2077_addresses.json`; NOT FOUND entries are present
with `"verified": false` so the plugin gate refuses any build that still compiles them in.

Held back although found: CGameFramework_InitializeGameInstance (4007601841, 1:0x1578050). It is the first of two
twin job lambdas and choosing it assumes the Windows build orders them the same way.

Renamed upstream hashes replaced the old ones at the same verified addresses: CMesh_LoadMaterialsAsync,
CharacterCustomizationSystem_Initialize, FactoryIndex_LoadFactoryAsync, InkSpawner_FinishAsyncSpawn,
InkWidgetLibrary_AsyncSpawnFromExternal/FromLocal, ResourceDepot_InitializeArchives/LoadArchives,
ResourceSerializer_OnDependenciesReady and TweakDB_Init/Load/TryLoad.


---

## Batch 1: 2.5.0 macOS addresses (ArchiveXL, also Codeware for the Entity_* and ExtractComponentsJob hashes)

Binary: `Cyberpunk2077-2.5.0-stock` (UUID 7D7382D0...). Every FOUND address below is in LC_FUNCTION_STARTS.

**Note on the hints:** every `verified=False` "old hash ... on 2.5.0" offset in batch1.tsv is the 2.3.1 DB offset copied over unchanged. Most of those 2.3.1 offsets were already junk on 2.3.1 too (`docs/re/*.md` col 3: for example 1:0xAD043C and 1:0x1E3F8F4 are each shared by several unrelated names). I did not use any of them as evidence.

| hash | name | new address (vmaddr) | DB offset (seg:0xOFF) | FOUND/NOT FOUND | signature same? |
| --- | --- | --- | --- | --- | --- |
| 3842971216 | AISpotPersistentDataArray_Reserve | - | - | NOT FOUND (still inlined) | n/a: plugin must rebuild it |
| 4219677283 | AppearanceChanger_GetBaseMeshOffset | - | - | NOT FOUND | n/a (upstream hook is commented out) |
| 3294244838 | AppearanceChanger_GetSuffixValue | 0x10201E330 | 1:0x201E330 | FOUND | yes (`const TweakDBID&` in x3, bool w0) |
| 2050568765 | AttachmentSlots_UpdateWithExclusiveLock | - | - | NOT FOUND | n/a: the `Hook<>().OrThrow()` must be guarded |
| 479081020 | CMesh_LoadMaterialsAsync | 0x10519C6DC | 1:0x519C6DC | FOUND | **no**: token returned via x8 (known 2.3.1 macOS ABI difference, unchanged) |
| 2878476560 | CNamePool_GetStringView | - | - | NOT FOUND | n/a (unused upstream) |
| 627643257 | CNamePool_RegisterName | - | - | NOT FOUND | n/a (unused upstream) |
| 2347184335 | CharacterCustomizationGenitalsController_CheckState | 0x104BAE524 | 1:0x4BAE524 | FOUND | yes `(this, u32&, u32&)` (upstream hook commented out) |
| 3414699684 | CharacterCustomizationHelper_GetHairColor | 0x102045774 | 1:0x2045774 | FOUND | **no**: `CName(WeakHandle& x0, bool w1)`, CName returned in x0 |
| 716262863 | CharacterCustomizationState_FinalizePart | - | - | NOT FOUND | n/a (unused upstream) |
| 787099588 | CharacterCustomizationSystem_EnsureState | - | - | NOT FOUND | n/a (unused upstream) |
| 4275058446 | CharacterCustomizationSystem_GetResource | 0x104BC7B24 | 1:0x4BC7B24 | FOUND (0 callers, so the hook never fires) | **no**: `Handle(x8; this x0, bool w1)` vs plugin `(this, SharedPtr&, bool)` |
| 2343126786 | CharacterCustomizationSystem_Initialize | 0x104BC779C | 1:0x4BC779C | FOUND | yes `(this, Handle<Puppet>*, bool, functor*)` |
| 1168449474 | CharacterCustomizationSystem_InitializeOptionsFromState | - | - | NOT FOUND | n/a (unused upstream) |
| 489494088 | EntityBuilder_ExtractComponentsJob | 0x1019B74B0 | 1:0x19B74B0 | FOUND | yes `(EntityBuilderJobParams* x0, ctx x1)` |
| 2182550867 | Entity_Assemble | - | - | NOT FOUND | n/a (Codeware hooks it; guard it) |
| 4248638169 | Entity_Attach | 0x10529EC50 | 1:0x529EC50 | FOUND | yes `(Entity* x0, params* x1)` |
| 2263681375 | Entity_Detach | 0x1019AB4DC | 1:0x19AB4DC | FOUND | yes `(Entity* x0)` |
| 2515274237 | Entity_Dispose | 0x1019AB7F8 | 1:0x19AB7F8 | FOUND | yes `(Entity* x0)` |

Re-check commands below use `re/d.py` (disassemble with string notes), `re/x.sh new call|adrp` (xref_scan), and `re2/b1_*.py` (run with `/opt/homebrew/bin/python3`; it has numpy).

## AppearanceChanger_GetSuffixValue -> 0x10201E330
- Upstream 2.5 changed the 4th argument from `TweakDBID` to `const TweakDBID&` (the reason for the rehash). In 2.3.1 macOS the function was inlined into GetSuffixes. In 2.5.0 it is out of line again (this was noted as a candidate in port_2.5.0_plugins.md).
- Called from the verified GetSuffixes 0x10201DCC8 at 0x10201E0D4: `x0=x19, x1=x23, x2=csel(handle), x3=sp+0x60 (&TweakDBID), x4=sp+0x80 (&CString)`, then `tbz w0`.
- Body: `cbz x1 -> return 0` (the "a2 must be non-zero" comment in upstream), `ldr x8,[x2]; cbz` (Handle<GameObject>&), `ldr w9,[x3]; ldrb w11,[x3,#4]` compared with static TweakDBIDs (so a 40-bit TweakDBID **by reference**). It writes the literals "TPP" 0x107533DEC, "FPP" 0x107533DF0 and "Full" 0x107533DE2 into the x4 CString, and returns `mov w0,#0/#1`.
- 0x10201E32C is a one-instruction `b 0x10201E330` thunk, used by 0x101CC4378. Hooking 0x10201E330 covers both entry points.

## CharacterCustomizationSystem_Initialize -> 0x104BC779C
- Slot +0x240 of the CCS vtable: 2.3.1 slot 0x10702D1F0 = 0x1024593DC (verified), 2.5.0 slot 0x107CB5C80 = 0x104BC779C. The vtable layouts match: 57 of 92 slots map 1:1 through fmap, including +0x238 InitializeOptionsFromFinalizedState and +0x248 Uninitialize (0x104BC83A8).
- The body matches 2.3.1: `mov x23,x3; x22,x2; x21,x1; x20,x0`, lock +0x70, +0x98, functor at +0x238/+0x278, `strb #1,[+0x230]`, `csel` of 0x48/0x58 on w2 (isMale). New in 2.5.0 is the 0x109CC59A0 interceptor call (`vt+0x58`). The arguments are unchanged.

## CharacterCustomizationSystem_GetResource -> 0x104BC7B24
- It directly follows Initialize, as in 2.3.1 (0x102459710 followed 0x1024593DC). The two bodies are instruction-identical: `mov x19,x8; cmp w1,#0; csel 0x48/0x58; bl 0x1010EF264` (= fmap of 0x1021C4D44, token Get) `; bl 0x104CD5494` (type getter; the same getter is used by the inlined copy in Initialize at 0x104BC7914) `; bl 0x1010C6BF4` (IsA), then the Handle is copied to [x8].
- It has no BL/B, ADRP or fixup references (as in 2.3.1), and no duplicate copy exists (a byte search of the body finds only this one). A HookBefore here never fires. Its macOS signature is `Handle<InfoResource>(x8; this x0, bool w1)`; upstream declares `(this, SharedPtr& x1, bool w2)`.

## CMesh_LoadMaterialsAsync -> 0x10519C6DC
- The old hash 701648326 at this address is verified on 2.5.0 (port_2.5.0_plugins.md: two callers in LoadMaterialSetupAsync, lock `+0x218` = plugin `MaterialLock`, ends with the "CMesh/IssueLoadMaterials/OnLoaded" descriptor).
- Upstream Mesh.hpp did not change in the 2.5 commit (205accc), so the rehash comes from a Windows body change. The macOS body is also twice the 2.3.1 size because token construction is now inlined.
- Signature: `mov x19,x2; x21,x1; x27,x0; x20,x8`, i.e. `MeshMaterialsToken(x8; CMesh* x0, const DynArray<CName>& x1, u8 w2)`. The plugin declares `void*(CMesh*, MeshMaterialsToken& aOut, names&, u8)`, the same ABI mismatch documented for 2.3.1 (resources.md). The plugin's macOS adaptation must stay.

## CharacterCustomizationHelper_GetHairColor -> 0x102045774 (body 0x10204577C)
- "ItemFactory.HairColors.hairColors" (0x1075340AF) has exactly one reference in 2.5.0: 0x1020457A8 in 0x10204577C. In 2.3.1 the only reference was inside 0x1037349E0, where the logic was inlined.
- 0x10204577C: `x8=sret; blr [[x0]+0x1F8]` (CCS vtable slot +0x1F8 = GetState(isMale), 0x104BC7228, which fmap maps from the 2.3.1 slot 0x102458ECC). It then iterates the flat and calls `state->vtbl[0x240](name)` (HasOption) and returns the first match in **x0**. These are the same three steps charcustom.md recorded for the 2.3.1 inline copy.
- 0x102045774 is `ldr x0,[x0]; b 0x10204577C`, so it takes the WeakHandle by reference. Caller 0x101CC4760 does `ldrb w1,[x19]; adr x0,0x108487AF0; bl 0x102045774; str x0,[x19,#0x18]`.
- **Plugin change needed:** macOS is `CName(WeakHandle<ISerializable>& x0, bool w1)`. Upstream `void(CName& aOut, WeakHandle&, bool)` would pass &CName as the handle, which crashes. Use `data.hairColor = fn(system->ref, data.isMale)`.

## CharacterCustomizationGenitalsController_CheckState -> 0x104BAE524
- Genitals vtable: the verified OnAttach 0x104BAE148 is at slot 0x107CB1D18 = vt+0x188, so vt = 0x107CB1B90 (2.3.1: 0x107029100, OnAttach 0x102440418 at +0x188).
- Update slot +0x2A0 = 0x104BAE474 (2.3.1: 0x102440754). It does `add x1,sp,#0x1c; add x2,sp,#0x18; bl 0x104BAE524`, then stores both results at `+0xCC/+0xD0` and applies them through `vtbl+0x2B0`. This is the same pattern as the verified Feet CheckState/update pair.
- fmap: 2.3.1 0x102440814 (the callee in the same spot of 0x102440754) maps to 0x104BAE524 (prefix). Body: `mov x20,x2; x23,x1; x22,x0`, `str wzr,[x23]; str wzr,[x20]`, then a transaction-system query (`vtbl+0x440`). It matches upstream `(this, CharacterBodyPartState&, CharacterBodyPartState&)`. Upstream has this hook commented out.

## EntityBuilder_ExtractComponentsJob -> 0x1019B74B0
- The verified ScheduleExtractComponentsJob 0x1019B3E70 installs exactly one job function: `adrp/add x8 -> 0x1019B74B0; str x8,[sp,#0x30]`. The 0x18-byte heap closure `{builder*, WeakPtr{ptr,rc}}` (= EntityBuilderJobParams) goes at [sp+0x38]. 0x1019B74B0 has no other reference.
- 2.3.1 is the same: lambda 0x100CA41E0, referenced only at 0x100CA0998 in Schedule 0x100CA08A0 (pass2.md / appearance.md). Old and new bodies have the same prologue, `ldr x0,[x1,#0x20]` job-ctx check, and 150 BLs each.
- Body: `x20=x0` (params), `ldr x23,[x20]` = builder, then a WeakPtr lock via `[x20+0x10]` refcount (`ldapr/casal`) and `ldur q0,[x20,#8]`. This matches Codeware/ArchiveXL `(EntityBuilderJobParams* aParams, void* a2)` and `entityBuilderWeak @+8`.

## Entity_Attach -> 0x10529EC50
- EntityStatus at +0x156 (SDK enum: Attaching=3, Attached=4). b1_status.py lists every `strb #imm,[xN,#0x156]`. 0x10529EC50 is the only 2.5.0 function that stores both 3 and 4 (0x10529EC70: 3, 0x10529EDA4: 4). In 2.3.1 the only such function was 0x100C99368, which fmap maps to 0x10529EC50 ("callee set (9)").
- It stores `[x1]` (scene) at `+0xB8` (Codeware `Scene` OffsetPtr 0xB8). The arguments are x0 = Entity and x1 = attach params, so `void(Entity*, uintptr_t)` matches.
- It has 3 BL callers in RuntimeSystemEntity: 0x101A0BEB4, 0x101A0D2CC and 0x101A10EC0, each `ldr x0,[xN]; mov x1,sp`. 2.3.1 had 3 callers too. The 2.3.1 OnAttach ret-stub vtable slot (0x100C99364, entEntity vt 0x106ED2D20 +0x158) maps to the new +0x160 (0x1019AB370). The non-virtual body moved away from the cluster.

## Entity_Detach -> 0x1019AB4DC
- It is the only function that stores 5 (Detaching) and then 2 (Detached) to +0x156. 2.3.1: 0x100C996C0 maps to 0x1019AB4DC (prefix). Its OnDetach ret-stub 0x1019AB4D8 sits directly before it and is entEntity vtable slot +0x168 (2.3.1: 0x100C996BC, +0x160).
- It uses only x0, so it matches `void(Entity*)`. Callers 0x101A0D348 and 0x101A0D434 check `ldrb w8,[x0,#0x156]; cmp #4 (Attached)` / `cmp #2` before the call.

## Entity_Dispose -> 0x1019AB7F8
- Body: `ldrb [x0,#0x156]; sub #2; cmp #3; b.hi` (status 2..5). If `[x0+0xB8]` (scene) is set, it hands the entity to the scene (`bl 0x101A11F48`). Otherwise it runs the inline uninitialize sequence (store 6, ..., `str xzr,[+0xB0]`, store 7). In all cases it ends with `orr #8` on `+0x15C`.
- This is exactly the condition Codeware's OnDispose tests (`status < Uninitializing && !scene` means Dispose uninitializes inline). It takes x0 only, matching `void(Entity*)`.
- 2.3.1: 0x100C999E0 (same 6/7 pattern, 46 callers) maps to 0x1019AB7F8 (call round 1, 13 votes). The 2.5.0 function has 46 callers.
- By-product (not in this batch): Entity_Uninitialize = 0x1019AB2D4. It has the same 6->7 body without the status/scene gate, its OnUninitialize stub 0x1019AB2D0 is at vt+0x158, and fmap maps 2.3.1 0x100C992C4 to it.

## NOT FOUND
- **AISpotPersistentDataArray_Reserve:** still inlined, as in 2.3.1. The SpotPersistentData move-callback GOT slot 0x1077A78F8 is used at only three sites: RegisterSpots 0x10267F100 (inline grow of +0x48), 0x10267E950 (inline grow of +0x50; fmap of 2.3.1 0x103D50E70), and 0x10471D5B8 (shrink-to-fit of +0x68, not a reserve). Rebuild it as `DynArray_Realloc(arr, cap, 0x20, 8, cap ? Move : nullptr)`. Move is the exported `__ZN3red8DynArrayIN2AI18SpotPersistentDataEE21MoveAfterReallocationEPvS4_jPKv` (0x102683398 in 2.5.0).
- **AttachmentSlots_UpdateWithExclusiveLock:** a new upstream function, and no lead is conclusive.
  - The AttachmentSlots exclusive lock is `bl 0x1000015F0` on `this+0x100` (shared: 0x1000015C8, as in IsSlotEmpty 0x101E0D97C). There are 21 such lock holders in 0x101DF0000-0x101E30000 (`b1_excl.py`).
  - Two of them are 4-argument wrappers that return x0: 0x101E07B64 and 0x101E0D41C.
  - No static (BL/B) path from any of the 21 reaches GetSuffixValue/GetSuffixes within 6 levels, and none performs a virtual call at the TS/other vtable offsets through which GetSuffixes callers are reached.
  - The plugin's `Hook<UpdateWithExclusiveLock>().OrThrow()` makes the Attachment extension fail to load unless it is guarded.
- **Entity_Assemble (Codeware "Entity_OnAssemble"):** no function in the entEntity cluster stores a status for it. The only shape-match, 0x1019AB72C (after ret-stub vt+0x150; it inits the components storage +0x70 from [x1] and calls 0x1019B9FF8 per component), returns void and has zero callers or references. Not conclusive.
- **GetBaseMeshOffset, CNamePool_RegisterName, CNamePool_GetStringView, CharacterCustomizationState_FinalizePart, CharacterCustomizationSystem_EnsureState, CharacterCustomizationSystem_InitializeOptionsFromState:**
  - upstream ArchiveXL does not reference any of them outside Library.hpp (GetBaseMeshOffset's hook is commented out);
  - none had a 2.3.1 macOS identification;
  - no string anchor exists (only "InitializeOptionsFromFinalizedState", which is slot +0x238 and a different function).

---

## Batch 2 result: ArchiveXL 2.5 entries on Cyberpunk 2077 2.5.0 macOS (7D7382D0)

Segments in 2.5.0: `__TEXT` 0x100000000, `__DATA_CONST` 0x107758000, `__DATA` 0x107d30000.
Every code address below is in LC_FUNCTION_STARTS, none starts with a PC-relative instruction, and `b2_twin.py` finds no identical dead copy for any of them.

| hash | name | new address (vmaddr) | DB offset (seg:0xOFF) | FOUND/NOT FOUND | signature same? |
| --- | --- | --- | --- | --- | --- |
| 3490519617 | Entity_Initialize | 0x1019AA7D8 | 1:0x19AA7D8 | FOUND | yes `void(entity x0, JobQueue& x1, EntityInitializeRequest* x2)` |
| 2296260874 | Entity_RequestComponents | 0x1019A4D04 | 1:0x19A4D04 | FOUND | yes `void(entity x0, a2 x1, DynArray<Handle<IComponent>>* x2)` |
| 3596356635 | Entity_Uninitialize | 0x1019AB2D4 | 1:0x19AB2D4 | FOUND | yes `void(entity x0)`; **note: Dispose inlines a copy, see notes** |
| 1350506587 | ExtensionLoader_AddConfig | 0x101CBDDDC | 1:0x1CBDDDC | FOUND | **NO: `bool(loader x0, const fs::path& x1)`; no aDir (x2 unused), returns bool** (upstream does not use it) |
| 660606521 | ExtensionLoader_Configure | 0x101CBD304 | 1:0x1CBD304 | FOUND | yes `void(loader x0)` |
| 1523060616 | ExtensionService_Bootstrap | 0x101D10778 | 1:0x1D10778 | FOUND | yes `void(service x0)` |
| 1255673638 | ExtensionService_Shutdown | 0x101D11820 | 1:0x1D11820 | FOUND | yes `void(service x0)` |
| 1931943018 | FactoryIndex_LoadFactoryAsync | 0x1019D50C8 | 1:0x19D50C8 | FOUND | yes `void(index x0, ResourcePath x1 (by value), ctx x2)` |
| 956641309 | GarmentAssemblerState_ChangeCustomItem | 0x102008864 | 1:0x2008864 | FOUND | yes `bool(state* x0, ChangeCustomRequest& x1)` |
| 3740082313 | GarmentAssemblerState_ChangeItem | 0x1020085B4 | 1:0x20085B4 | FOUND | yes `bool(state* x0, ChangeRequest& x1)` |
| 1828854026 | IPlacedComponent_SetTransform | 0x1019545C8 | 1:0x19545C8 | FOUND | yes `void(comp x0, const WorldTransform& x1)` |
| 4002093843 | ImpostorComponent_OnAttach | 0x1020F3B84 | 1:0x20F3B84 | FOUND | yes `void(comp x0, ctx x1)` |
| 2890273101 | InkSpawner_ControllerInjectionEnabled | 0x109D03E78 (data, `__DATA,__common`) | 3:0x1FD3E78 | FOUND | n/a (bool byte) |
| 4097515464 | InkSpawner_FinishAsyncSpawn | 0x104368F34 | 1:0x4368F34 | FOUND | yes, ctx layout now matches upstream; returns void (plugin says bool, harmless for HookBefore) |
| 225197914 | InkWidgetLibrary_AsyncSpawnFromExternal | 0x104353D74 | 1:0x4353D74 | FOUND | **NO: extra 5th arg `bool w4` (same as 2.3.1 mac)** |
| 2342073570 | InkWidgetLibrary_AsyncSpawnFromLocal | 0x104353A7C | 1:0x4353A7C | FOUND | yes `bool(lib x0, info x1, CName x2, bool w3)` |
| 2254060789 | InkWorldLayer_UpdateComponents | - | - | NOT FOUND | - (candidate patch site noted) |
| 2052144225 | JournalTree_ProcessJournalIndex | - | - | NOT FOUND | - (no mac function has the new `(tree, indexToken, JobQueue&)` shape) |
| 647500563 | LootResourceData_Read | - | - | NOT FOUND | - (no upstream declaration or use) |

Helpers (in `re2/`): `b2_env.sh` (`fn`, `fm`, `xc` wrappers), `b2_q.py new ADDR N` (raw qwords),
`b2_page.py new PAGE` (ADRP+ADD/LDR to a page), `b2_twin.py ADDR...` (dead-copy check), `b2_strb.py new OFF` (stores of
immediates to `[xN,#OFF]`), `b2_fix-new.txt` (`dyld_info -fixups`), `b2_indirect.txt` (`otool -Iv` stub names).

---

## Key finding: 2.5.0 ships a native ArchiveXL

2.5.0 contains a native port of ArchiveXL's extension framework (no log strings, but the structure is the same as
`App::ExtensionService` / `App::ExtensionLoader` from the plugin source). Its configs use the extension `u".json"` (UTF-16 at
`0x107724B70`) instead of `.xl`. Its extensions keep the ArchiveXL names and keys: "FactoryIndex"/"factories",
"Journal"/"journal", "localization"/"onscreens"/"subtitles", "WorldStreaming"/"sectors", "ResourcePatch",
"garment/extension/OnProcessGarmentSkinnedMesh", "Bad format. Expected resource path or list of paths." (`0x107525FB1..0x1075268F2`).
This is what upstream's new `ExtensionService_*` / `ExtensionLoader_*` / `ControllerInjectionEnabled` entries disable.

## ExtensionService_Bootstrap -> 0x101D10778, ExtensionService_Shutdown -> 0x101D11820
- The service ctor `0x101D1072C` (called from the feature registrar `0x101D1B0D8`; the other copy is `0x101D106E0`) stores vtable
  `0x107901510` and builds the same layout as `App::ExtensionService`: `m_loader` at +0x18, `m_bundleDir` (moved
  `fs::path`) at +0x20, `std::mutex` at +0x38 (`0x32AAABA7` signature).
- The vtable follows `Core::Feature`: [0] `~D1` 0x101D11890, [1] `~D0` 0x101D118E4, [2]/[3] OnRegister/OnInitialize are
  nullsubs, **[4] OnBootstrap = 0x101D10778**, **[5] OnShutdown = 0x101D11820**, [6] 0x101D11860 (reload).
- Bootstrap body: `m_loader = MakeUnique<ExtensionLoader>(this+0x20, u".json")` (`bl 0x101D10838`, `x1=0x107724B70`),
  then 11 `Add<T>()` calls on `[x19+0x18]`. The 4th is `0x101D10E40` -> make_shared `0x101D120EC`, which builds the extension whose
  vtable `0x107900AB8` has GetName `0x101CBEDD0` = `"FactoryIndex"` (len 12) and AddConfig `0x101CBE9B4`, which matches the key
  `"factories"`. The order is ResourceMeta, ResourceLink, ResourcePatch, Mesh, FactoryIndex..., as in the plugin source. It
  ends with `bl 0x101CBD304` (Configure) and `bl 0x101CBE130` (Load).
- Shutdown body: `ldr x0,[x0,#0x18]; bl 0x101CBE24C` (Unload: `if(m_loaded) for modules: vt+0x20; m_loaded=0` at +0x50),
  then `m_loader = nullptr` (dtor `0x101D11AB8` + `operator delete`). This is `m_loader->Unload(); m_loader = nullptr;`.
- Both functions are referenced only from the vtable (0x107901530 / 0x107901538).

## ExtensionLoader_Configure -> 0x101CBD304
- Callers: Bootstrap `0x101D1081C` and loader Reload `0x101CBE2A8` (`if(m_loaded){Configure(); for configurables: vt+0x48; vt+0x50}`).
- Body: `for configurables ([x0+0x10], count [x0+0x1C], stride 0x10): vt+0x40` (ResetConfigs), then depot groups and
  `fs::path::__compare`, and two loops that each call `0x101CBDDDC` (AddConfig). One loop runs over the dir iterator and one over
  the file list, and the second loop builds `__parent_path` first, the same as `AddConfig(configFile, configFile.parent_path())`.
- Loader layout: modules +0x00, configurables +0x10, bundleDir +0x20, configExt +0x38, m_loaded +0x50.

## ExtensionLoader_AddConfig -> 0x101CBDDDC  (signature differs)
- Only called from Configure (`0x101CBD868`, `0x101CBD9FC`) with `x0=loader, x1=path`.
- Body: `bl fs::path::__filename(x1)` (stub `0x1052A830C`), which gives `name = aPath.filename().string()`, then opens and
  parses the file, then `for configurables: success &= vt+0x38(module, name, config)` (`0x101CBDFE4..0x101CBE004`, `and w19,w19,w0`).
- x2 is never read: the first call clobbers it. **mac: `bool(loader, const std::filesystem::path&)`**. Upstream declares
  `void(loader, path, dir)` and neither hooks nor calls it, so nothing breaks today.

## InkSpawner_ControllerInjectionEnabled -> 0x109D03E78 (3:0x1FD3E78)
- A byte in `__DATA,__common`. All 7 readers do `ldrb; cmp #1; b.ne`: AsyncSpawnFromLocal `0x104353A98` (+0x1C), the External
  thunk `0x104353D58`, `0x104353DB0`, SpawnFromLocal `0x104354044`, `0x104354220`, `0x10435427C`, and FinishAsyncSpawn
  `0x104368F50` (+0x1C). When the byte is set they go to the native path, which does `strchr(req->itemName(+0x48).ToString(), ':')`
  (`mov w1,#0x3a; bl _strchr` at `0x10415615C`). That is ArchiveXL's controller separator.
- The only writers are `0x104156600` (`strb #1`) and `0x104156610` (`strb wzr`). They are slots [4]/[5] (OnBootstrap/OnShutdown)
  of a 7-slot `Core::Feature` vtable at `0x107BEA428`. That is the native InkSpawner feature turning the injection on at bootstrap.
- Note: no code or fixup references vtable `0x107BEA428`, so on mac the game may never set the byte. Upstream setting it to false is harmless either way.

## FactoryIndex_LoadFactoryAsync (new hash) -> 0x1019D50C8
- This is the verified old-hash address. Body (from port_2.5.0_plugins.md): `mov x19,x2; mov x21,x0; str x1,[sp,#0x20]`, then
  IssueLoadingRequest `0x1010E710C` and a "ParseFile" job with `x3=ctx`.
- New independent evidence: the native FactoryIndex extension calls it the same way the plugin's `OnLoadFactoryAsync` does.
  The CreateEntryMap job `0x1019D596C` calls `bl 0x1019D50C8` at `0x1019D5A80` and then the interceptor
  `[0x109CC59A0]->vt+0xD8(index,&path,&ctx)`. That reaches `0x101D1884C` -> `0x101CBF6D4`, which checks
  `*path == 0xF94FAAB4FF97393A` (the LastFactory hash) and loops `bl 0x1019D50C8(x0=index, x1=[entry+8] path, x2=ctx)` (`0x101CBF79C`).
- Signature matches upstream `void(uintptr index, ResourcePath, uintptr ctx)`.

## GarmentAssemblerState_ChangeItem -> 0x1020085B4, ChangeCustomItem -> 0x102008864
- They are no longer inlined. The verified wrappers GarmentAssembler_ChangeItem `0x10200857C` / ChangeCustomItem `0x10200882C`
  (`aggr x0, WeakHandle& x1, req& x2`) do `bl 0x102007BC4` (FindState, verified; sret x8 = `{entry+0x10, entry+0x20, entry+0x50}`
  = the 0x18-byte GarmentAssemblerState), then `add x0,sp,#8; mov x1,x19(req); bl 0x1020085B4 / 0x102008864`.
- ChangeItem body: `ldr x21,[x1,#0x10]` (hash), `ldr w4,[x1,#0x18]`, `ldr x27,[x0]` (state.unk00). Later it calls
  `0x102008DCC(.., x1=req)` and `0x10200938C(.., req)`, and returns `w0 = and(...)`.
- ChangeCustomItem body: hash `[x1,#0x20]`, `w4=[x1,#0x28]`, `0x102008DCC(req)` and `0x102009678(x1=req+0x10 overrides)`.
- The same helper pairs are used by the verified AddItem `0x102007DCC` (`0x102008DCC` + `0x10200938C`) and AddCustomItem
  `0x102007EBC` (`0x102008DCC` + `0x102009678`).
- Layout: apperance @0, hash @0x10 (custom: overrides @0x10, hash @0x20), as in upstream. Mac requests carry an extra u32 (+0x18 / +0x28),
  which the plugin does not read.

## InkSpawner_FinishAsyncSpawn (new hash) -> 0x104368F34
- This is the verified old-hash address. It is slot [0] of the functor ops table `0x107E81078` (ADRP `0x104368CF8` in the spawn job).
- Body: `x0` = `{WeakHandle @0 (refcnt @+8), SharedPtr<request> @0x10 (refcnt @0x18)}`, and it reads the flag byte at +0x1C. This is
  exactly upstream's new `InkSpawningContext {WeakHandle unk00; SharedPtr request @0x10}`, size 0x20. The plugin's new struct is correct on mac.

## InkWidgetLibrary_AsyncSpawnFromLocal (new hash) -> 0x104353A7C
- This is the verified old-hash address. Mapped callers `0x1042CE8C4` / `0x1042D36E4` (fmap of old `0x1048D6584` / `0x1048DB32C`) tail-call it,
  and the native path `0x10415659C` also calls it. The flag check is at +0x1C.
- Upstream's new 4th `bool a4` = mac w3. Same signature.

## InkWidgetLibrary_AsyncSpawnFromExternal (new hash) -> 0x104353D74  (5th arg)
- This is the verified old-hash address. Callers `0x1042CE91C` / `0x1042D390C` reach the flag thunk `0x104353D58` (ADRP first), and its
  only non-flag exit is `b 0x104353D74`.
- **mac takes `bool w4` (`mov x19,x4` -> `bl 0x10431D76C(item,x20,x19)`)**. Upstream declares 4 args and full-hooks it. The fork
  must keep its 5-arg hook/trampoline call, or w4 is garbage. When the byte is 1, calls bypass this body; with the plugin forcing 0, they do not.

## Entity_Initialize -> 0x1019AA7D8
- `b2_strb.py new 0x156` shows this is the only non-trivial function that stores `Initializing(1)` to `entity+0x156`
  (Raw::Entity::Status). Its 2.3.1 counterpart `0x100C985EC` maps here by fmap "callee".
- Body reads upstream's `EntityInitializeRequest` layout: `[x2+0x38]` isDynamic (to the +0x15C bit), `[x2+0x20]` entityID (to entity+0x48),
  `[x2+0xB0]` (to +0x155), `[x2+0xCC]` unkCC (to +0x158), `[x2+0x70]` entityParams Handle (to +0xC8), `[x2+0x68]`. It stores the
  transform component to `entity+0xB0` (Raw::Entity::TransformComponent).
- x1 is a JobQueue: `ldrb [x19,#0x28]`, `add x2,x19,#0x10; add x3,x19,#0x18; bl 0x104DDF514/0x104DDF53C; bl 0x104DDF354(x19)`.
  This matches Codeware's `(Entity*, JobQueue&, Request*)`. Callers: `0x1019BF8EC`, `0x1019BF918`, `0x1019F8920`.

## Entity_RequestComponents -> 0x1019A4D04
- Initialize calls it at `0x1019AA944` with `x0=entity, x1=[req+0x68], x2=GetComponents(entity+0x70)`. `0x10189A014` is
  `add x0,x0,#0x30`, so x2 = entity+0xA0 = `entity->components` (SDK entEntity). This is the case Codeware's hook tests
  (`aComponents == &aEntity->components`).
- The other caller, `0x1019A7A24` (reached from `0x1019B4CC0`), passes `a2=0` and a different array (`obj+0xC0`). That is the
  reassemble-style case. `0x1019A57E0` passes its own components.
- Body: x2 is used as a DynArray (`ldr x21,[x19]; w8=[x19,#0xC]; stride 0x10`). x1, when non-null, is entity-like (its +0x70
  components are merged). It calls component virtuals +0x118 / +0xE0. 2.3.1 fmap: `0x100C92C50` -> here (callee set).

## Entity_Uninitialize -> 0x1019AB2D4  (note)
- Body: status `6` (Uninitializing), `+0xD8` cleanup `0x101022748`, `0x1019A492C`, `vt+0x160`, component loop `0x1019B9434`,
  storage reset `0x1018997E4`, `str xzr,[x19,#0xB0]`, then status `7` (Uninitialized). These are the plugin's enum values.
- Callers `0x101A0D4A4`, `0x101A11270`, `0x101A11284` (scene side). 2.3.1 `0x100C992C4` maps here (fmap callee).
- **Flag:** Dispose `0x1019AB7F8` (50+ callers) runs an inlined copy of this body when the entity has no scene
  (`[x0+0xB8]==0`), so a hook on `0x1019AB2D4` does not see those uninitializations. Codeware's EntityUninitializeHook may miss events on mac.

## IPlacedComponent_SetTransform -> 0x1019545C8
- Body: compares and stores a **WorldTransform**: fixed-point `int32 x3` position from `[x1]` (the diff is scaled by 2^-17, `movi #0x37,lsl#24`) into
  `+0xC0..+0xC8`, and the Quaternion `[x1+0x10]` into `+0xD0`. Then `ldr x0,[x0,#0x50]` (owner) and `b 0x10529E784` (transform-dirty notify).
  These are SDK `IPlacedComponent.localTransform` @0xC0.
- Sibling setters that call the same notify: `0x101954210` (Vector3 pos), `0x1019542D8` (quat), `0x101954380` (float Transform),
  `0x101954478` (pos, quat). Script natives SetLocalOrientation `0x101956788` and SetLocalTransform `0x1019568A8` inline the same code.
- Caller: entity thunk `0x1019A9CAC`: `ldr x0,[x0,#0xB0]; cbz; b 0x1019545C8`. That is SetTransform on the entity's transform component
  (+0xB0), which is what Codeware's EntityEx does. The other callers are `0x102B60288` and `0x102B60434`.

## ImpostorComponent_OnAttach -> 0x1020F3B84
- The verified TPPRepresentationComponent_OnAttach `0x101E9FF18` sits at `0x107923D10` = vtable `0x107923B88` + 0x188 (slot 49, as on 2.3.1).
  Its first call is base OnAttach `0x1019B9540` (fmap of 2.3.1 `0x100CA627C`, 37 votes).
- Of the 60 functions calling `0x1019B9540`, only `0x1020F3B84` reads the gameImpostorComponent fields: `ldrb [x19,#0xB2]`
  (isCharacterReplica). Its slot is `0x10795AE08` = vtable `0x10795AC80` + 0x188, also slot 49.
- Vtable `0x10795AC80` is installed by ctor `0x1020F39C4` (and twin ctor `0x1020F3A98`). The ctor sets `+0xB0` = 0x01010000, so
  `+0xB2`/`+0xB3` = 1, `+0xB4` = 1, and a TweakDBID array at `+0xB8`. That matches the RTTI props isCharacterReplica 0xB2,
  addHead 0xB3, ignorePlayerHeadSlot 0xB4, slotIDsToOmit 0xB8 (size 0xF0).
- `mov x19,x0; bl base` keeps x1, so the signature is `(comp, ctx)`, as declared.

## NOT FOUND

**InkWorldLayer_UpdateComponents (2254060789).** The macOS fork skips this patch (`#ifdef _WIN32`). No function has the Windows
shape (a `cmp 10; jae` in its first 0x100 bytes). The only "<10" check in inkWorldLayer code is in the parallel-for job lambda
`0x1043181C8`: `cmp x22,#0x9; b.hi 0x10431838C` at `0x1043182F4`/`0x1043182F8`. Index < 10 calls `0x104315560`, and the rest call
`0x10431422C`. The lambda is dispatched by `0x104317FB4`, which is launched from `0x104313AA4` ("UI/WorldLayer/Tick/SetComponentRenderMode"
profiler label `0x108EF43D0`). It is the same in 2.3.1 (`0x10491DDB0`, fmap body). This is the likely arm64 patch site (NOP the `b.hi`),
but nothing ties it to the Windows-hashed function, so no DB entry. The stale DB value 1:0x3DA0574 is an unrelated 2.3.1 overlay
registration function.

**JournalTree_ProcessJournalIndex (2052144225).** Upstream now hooks `void(tree, indexToken, JobQueue&)`. On mac:
- The job lambda `0x1052360B4` (old hash 837162664, verified) is still `(capture x0, JobGroup& x1)`. It calls the native
  interceptor `[0x109CC59A0]->vt+0x30(tree=[x0], x1)`, builds its own JobQueue at `sp+0x40` (`0x104DDF1C4`), and processes the
  index tokens (capture +0x8..+0x28) inline. No out-of-line `(tree, token, JobQueue&)` call exists.
- The dispatcher `0x105231F3C` has the 3-arg shape `(tree, SharedPtr x1, JobQueue& x2)`, but its x1 is not an index token (it
  requests the two `index.reslist` tokens itself), and it runs before they exist.
- Fail-closed: keep the fork's old 2-arg `OnLoadJournal(uintptr, JobGroup&)` hook on 837162664 -> 0x1052360B4.

**LootResourceData_Read (647500563).** Upstream only defines the hash; nothing declares or uses it, so no signature check is possible.
For reference, the gameLootResourceData vtable is `0x10786B158` (GetNativeType `0x101716E28`). Its only serializer override is slot 9 (+0x48),
`0x1017173F0`. That function takes `(this, stream)`, sets version=1 when writing, calls base `0x1010B0860`, then
`b 0x10171744C(stream, this+0x38)` for the custom blob. Whether "Read" is that override or `0x10171744C` cannot be decided.

## Summary
- 19 entries: 16 FOUND, 3 NOT FOUND (InkWorldLayer_UpdateComponents, JournalTree_ProcessJournalIndex, LootResourceData_Read).
- 2.5.0 has a native ArchiveXL (configs in `.json`): the service, loader, Configure, AddConfig and the controller-injection byte are now identified. The 2.3.1 DB values for the Entity_*/SetTransform/Impostor hashes were stale and are replaced.
- Signature changes: AsyncSpawnFromExternal keeps the mac-only 5th `bool w4`; ExtensionLoader_AddConfig is `bool(loader, const fs::path&)` with no dir arg (not used upstream); FinishAsyncSpawn returns void (harmless); journal must stay on the old 2-arg lambda hook.
- Layout: upstream's new InkSpawningContext (+0x10 request, 0x20 size) now matches mac. The garment state ops are live out of line, so upstream's GarmentAssemblerState hooks work, but don't also hook the fork's GarmentAssembler_Change* wrappers (double processing). Mac garment requests carry an extra u32 the plugin ignores.
- Behaviour: Entity Dispose `0x1019AB7F8` inlines Uninitialize, so Codeware's Uninitialize hook can miss disposals. The world-widget limit patch site on arm64 is likely `b.hi` at `0x1043182F8`, unconfirmed.

---

## Batch 3 result (2.5.0 macOS)

| hash | name | new address (vmaddr) | DB offset (seg:0xOFF) | FOUND/NOT FOUND | signature same? |
| --- | --- | --- | --- | --- | --- |
| 3603701972 | MappinSystem_GetMappinData | 0x1030F7934 | 1:0x30F7934 | FOUND | yes: `void*(system x0, uint32 w1)`. The macOS fork must hook at system level (see section). |
| 2918455690 | MappinSystem_GetPoiData | 0x1030F7C54 | 1:0x30F7C54 | FOUND | yes: `void*(system x0, uint32 w1)`. Same fork note. |
| 633871992 | MorphTargetManager_ApplyMorphTarget | 0x10197F17C | 1:0x197F17C | FOUND | yes: x0, x1, x2, s0, w3 |
| 2892763485 | ResourceDepot_InitializeArchives | 0x10151A118 | 1:0x151A118 | FOUND | yes: `void(depot*)`. The depot lock moved to +0xE8. |
| 3573367139 | ResourceDepot_LoadArchives | 0x10151B18C | 1:0x151B18C | FOUND | yes for the new upstream 6-argument form. It returns w0 status; upstream declares void, which is harmless. |
| 3955625134 | ResourceLoader_OnUpdate | none | none | NOT FOUND | n/a |
| 3892979844 | ResourceSerializer_OnDependenciesReady | 0x1012090B0 | 1:0x12090B0 | FOUND | yes: `bool(ctx*)` (new bool return) |
| 1147149338 | ResourceSerializer_OnResourceReady | none (inlined) | none | NOT FOUND | n/a |
| 1350901460 | ResourceSerializer_PostLoad | 0x10120B670 | 1:0x120B670 | FOUND | args yes. Returns bool in w0; ArchiveXL declares void (harmless), Codeware declares bool (matches). |
| 2872059340 | RuntimeSystemWorldStreaming_LoadWorldJob | 0x101C0077C | 1:0x1C0077C | FOUND | yes: `void(WorldLoadJobData* x0, const JobGroup& x1)` |
| 678894266 | TPPRepresentationComponent_IsAffectedSlot | none (inlined) | none | NOT FOUND | n/a |
| 63182599 | TweakDB_Load | 0x1037CE05C | 1:0x37CE05C | FOUND | yes: `void(TweakDB* x0, bool w1, CString& x2)` (new upstream form) |
| 2744524784 | CBaseFunction_InternalExecute | 0x101099C44 | 1:0x1099C44 | FOUND | yes: `bool(CBaseFunction* x0, CBaseStack* x1, CStackFrame* x2)` |
| 1745688837 | CBaseStack_ResolveContext | 0x10109D20C | 1:0x109D20C | FOUND | yes: `IScriptable*(CBaseStack* x0)` |
| 4007601841 | CGameFramework_InitializeGameInstance | 0x101578050 | 1:0x1578050 | FOUND | yes: `void(closure* x0, jobctx* x1)` |
| 1559565515 | CommunitySystem_Update | 0x10472C880 | 1:0x472C880 | FOUND | yes: `void(ICommunitySystem* x0, bool w1)` |
| 3151104823 | EngineTime_Frequency | 0x1099DC4F8 | 3:0x1CAC4F8 | FOUND | yes: data, `double` (value 1e9) |
| 2091718968 | EntitySpawnerToken_GetWaitHandle | 0x1019F6E34 | 1:0x19F6E34 | FOUND | `const JobHandle&(token* x0)`, returned in x0. Codeware declares no type and does not call it. |
| 552341017 | EntitySpawnerToken_dtor | 0x1019F6CA8 | 1:0x19F6CA8 | FOUND | yes: `void(EntitySpawnerToken*)`. Returns `this`, which is harmless. |

Totals: 19 entries, 16 FOUND, 3 NOT FOUND.

Segment bases (otool -l, new binary): `__TEXT` 0x100000000, `__DATA_CONST` 0x107758000, `__DATA` 0x107D30000. Every text address above is a function start (checked with re/f.py against LC_FUNCTION_STARTS).

## Evidence

### MappinSystem_GetMappinData: 0x1030F7934
- The hint 1:0x42A3E38 is the unported 2.3.1 stub. On 2.5.0 the body starts `mov x19,x0; stur w1,...; ldr x0,[x0,#0x58]; bl 0x1030F2FF0`. 0x1030F2FF0 is the verified MappinResource lookup.
- If that lookup returns null, the body runs a new fallback through `[this+0x40]`. This new behaviour explains the rehash.
- Callers:
  - GetMappinPosition 0x103106D24, with a `bl` at 0x103106D3C (rmap gives old 0x1042B2748).
  - A 0x14-byte null-check stub at 0x1030F7920 (`ldr x8,[x0,#0x58]; cbz; b 0x1030F7934; mov x0,#0; ret`), called from 0x1031456CC. This stub is the 2.5 counterpart of the old stub 0x1042A3E38.
- I chose the body over the stub because it covers both call paths and is patchable (it starts `sub sp`).
- **Plugin change:** the macOS fork currently hooks the resource-level lookup, with x0 = resource. It must hook this system-level function, with x0 = system as upstream does. Otherwise the hook runs before the new fallback.

### MappinSystem_GetPoiData: 0x1030F7C54
- The body is instruction-for-instruction the same as 0x1030F7934, with two differences: it loads `[x0,#0x68]` and calls `bl 0x1031138F4`, the verified POI lookup.
- Its only entry is the stub 0x1030F7C40 (`ldr x8,[x0,#0x68]; cbz; b 0x1030F7C54`). That stub has 3 callers, one of them 0x10313B83C inside the mapped 0x10313B808 (old 0x1042E6244).
- The same system-level hook note applies.

### MorphTargetManager_ApplyMorphTarget: 0x10197F17C
- The body scans the entries at +0x98 (count at +0xA4, stride 0x18) and compares target x1 and region x2.
- If no entry matches, it inserts `{target, region, 1.0f (0x3f800000)}`. It stores s8 at entry+0x10, and `tbnz w3,#0` is the force flag. This matches entMorphTargetWeightEntry (`m_targetName`, `m_regionName`, `m_weight`).
- There are 9 call sites, including 0x104BC0EC0, 0x104BC120C and 0x104BC14A0. These are char-customization functions that pass `mov.16b v0,v8; mov w3,#0`.
- They get the component through 0x104BC0258, which calls the class getter 0x10197E68C on global 0x109CC2318. That global holds class 0x108413B00, which is registered with "entMorphTargetManagerComponent" (0x10751572F) and size 0x110 (0x10197FF14 / 0x10197FC48).

### ResourceDepot_InitializeArchives: 0x10151A118
- The hint is verified=True. fmap maps it from old 0x103ED96B0, and the mapped-callee sequence ratio is 0.98.
- Caller: the ctor body 0x101519F6C, which is reached by a `b` from the ctor at 0x10151A4E0.
- It calls the stub 0x101520F9C, which carries the strings "Failed to find any archives in the base data directory '%hs'" and "!baseSet.archives.Empty()".
- It locks depot+0xE8, so the depot lock offset moved.

### ResourceDepot_LoadArchives: 0x10151B18C
- The hint is verified=True.
- Argument use:
  - x0 is unused.
  - x1 is the group, x2 the paths and x3 the out list.
  - w4 is the mode (`mov x19,x4; cmp w19,#1`).
  - w5 is the fail severity (`str w5,[sp,#4]`, later passed as w1 to the fail stubs).
- This matches upstream ArchiveXL commit 205accc: `(depot, group, paths, loaded, int32 aMode, uint8 aFailSeverity)`, called with `(nullptr, group, paths, loaded, 0, 2)`.
- Existing callers pass `w4=1/0, w5=2`. The new callers in 0x10151BEBC and 0x10151C214 pass w5=0.
- It returns a status in w0. Upstream declares void, which is harmless.

### ResourceLoader_OnUpdate: NOT FOUND
- The hint 0x102D9766C is inside 0x102D97268, a static initializer (it builds "base\journal\" paths). This is the same refutation as on 2.3.1 (docs/re/resources.md).
- No per-frame loader method has string or vtable evidence.
- The loader global 0x1099DC690 has 233 references. The engine tick functions 0x104D7A460 and 0x104D82608 load it, but no single callee is conclusively "OnUpdate".
- The macOS fork already disables hot reload, which is the only use (`ExtensionService::Configure`, `#ifdef __APPLE__`).

### ResourceSerializer_OnDependenciesReady: 0x1012090B0
- The hint is verified=True.
- The function has a single return path, `mov w0,#1; ret`. The old 0x1022575C0 never set w0. The change from void to bool explains the rehash and matches upstream 205accc.
- The WaitForDependencies lambda 0x101209038 passes it with `adr x1` to the throttler 0x1010EBEE0.

### ResourceSerializer_OnResourceReady: NOT FOUND (inlined)
- The sequence is:
  1. observer `[0x109CC59A0]` vt+0xA8/+0xC0 on ctx+0x230;
  2. `0x104153F10(ctx+0x190, 9)`;
  3. `blr completion(ctx+0x230, ctx+0x10, ctx+0x1D0, ctx+0x20, x20)`;
  4. `0x101209A90(ctx)`;
  5. free.
- This sequence is inlined in OnDependenciesReady, in the WaitForEditorPostLoadJobs lambda 0x1012092E0, in 0x1012093BC, in 0x101209618, in Load 0x101207588, and four times in the scheduler 0x101207ED4. There is no standalone function.
- ArchiveXL declares it but never uses it.

### ResourceSerializer_PostLoad: 0x10120B670
- Arguments: x0 = ctx+0xB0, x1 = request&, x2 = JobQueue&.
- It returns bool w0 = !(request.flags+0x58 & 2).
- The body loops over the objects at +0x38/+0x44 (stride 0x28) and calls `obj vt+0x30` (PostLoad) with params from request+0x39. That read is now `ldurh` (2 bytes); it was 1 byte on 2.3.1.
- Callers: OnDependenciesReady (`bl` at 0x1012090F4) and 0x1012086DC (`bl` at 0x101208828).
- The old twin is 0x102259888. The old OnDependenciesReady calls it at 0x102257610 with the same arguments, and its body has the same structure.

### RuntimeSystemWorldStreaming_LoadWorldJob: 0x101C0077C
- There is a single ADRP reference, at 0x101BF9A88 inside 0x101BF97F4. That function:
  - issues the world load request through IssueLoadingRequest 0x1010E710C with loader 0x1099DC690;
  - builds a 0x60-byte closure, with the system at +0 and the token at +8/+0x10;
  - dispatches under descriptor guard 0x108476DE8. The descriptor init 0x101C01280 uses the string "LoadStreamingWorldResource" (0x107522418).
- The body:
  - fetches the token through 0x1010EF264;
  - IsA-checks it against class global 0x109CC5200, next to the "worldStreamingWorld" CName getter 0x101C07DA8;
  - stores the handle at system+0x270. The getter for that field is 0x101BFE958 (`add x0,x0,#0x270`).
- This matches upstream 4f513b1: `void(WorldLoadJobData* {system@0, SharedPtr token@8}, const JobGroup&)`, used with HookBefore.

### TPPRepresentationComponent_IsAffectedSlot: NOT FOUND (inlined)
- The Head/Eyes TweakDBID pair 0x1084ED2B0/0x1084ED2B8 is referenced only in three places:
  - OnAttach 0x101E9FF18;
  - the inline checks in OnItemUnequipped 0x101EA50BC (at 0x101EA50D8);
  - the inline checks in OnItemEquipped 0x101EA5B54 (at 0x101EA5B88).
- There is no standalone `bool(TweakDBID)` function to HookAfter.

### TweakDB_Load: 0x1037CE05C
- The hint is verified=True.
- The body starts `mov x20,x2; mov x21,x1; mov x19,x0` and references the "cache" string.
- It calls TryLoad 0x1037D60CC twice: the first call passes x4 = w1, the second passes 0.
- Callers: 0x101EF651C (`mov w1,#1; add x2,x19,#0x48`) and 0x1037CF134.
- This matches upstream 205accc: `void(TweakDB*, bool, CString&)`.

### CBaseFunction_InternalExecute: 0x101099C44
- Codeware names this "rtti::Function::InternalCallNative", with type `bool(CBaseFunction*, CBaseStack*, CStackFrame*)`.
- fmap maps it from the 2.3.1 native invoker 0x102172F90.
- InternalExecute 0x101099FBC calls it on the native path (func+0xA8 bit 0) at 0x10109A0C0, passing a stack object built at x19+0x108.
- The body:
  1. calls ResolveContext 0x10109D20C;
  2. gets the native from table 0x1099DC940, indexed through func vt+0x20;
  3. calls `native(ctx, frame, ret = stack vt+0x10, retType = stack vt+0x18)`;
  4. returns 1 or 0.
- It has 3 callers.
- The identity relies on the CBaseFunction field +0xA8. That field moved, because the struct grew from 0xB0 to 0xF0.

### CBaseStack_ResolveContext: 0x10109D20C
- The body is the same as the old 0x1021742CC:
  - if `[+0x18]` is set, return it;
  - otherwise, if the type at `[+0x28]` IsA IScriptable, return `[+0x20]`;
  - otherwise return null.
- Its callees 0x1011E46D8 and 0x1010C6BF4 are the mapped GetTypeObject<IScriptable> and IsA.
- It has 8 callers, including the mapped 0x101099C44 and 0x10109B16C.

### CGameFramework_InitializeGameInstance: 0x101578050
- Codeware's removed IDA pattern (commit 4070e2a2) decodes to a job lambda:
  - `mov r9,[rdx+?]; mov rbx,rcx; …; test r9,r9; jz; gs:TLS …` sets the job-scope TLS from the job ctx;
  - `mov rax,[rcx]` loads the closure field 0 (the framework);
  - `mov r8,rdx` passes the job ctx as the 3rd argument.
- The pattern matched 2 functions, and Codeware used index 0.
- The macOS lambda 0x101578050 has exactly this shape:
  - `ldr x0,[x1,#0x20]; cbz; bl 0x104DDF924; bl 0x104DF0D14` sets the job scope;
  - `ldr x8,[x19]; ldr x0,[x8,#0x10]` loads framework->gameInstance (+0x10);
  - it then does `strb` of closure byte +8 to the stack, `ldr x3,[x19,#0x10]`, `mov x2,x20` (job ctx), and `blr [vt+0x28]` (GameInstance initialize).
- Its twin is the RuntimeScene lambda 0x1015780D4, which loads framework+0x18. That twin explains "expected 2", and 0x101578050 comes first.
- Both lambdas are referenced only from the framework init 0x101577BA8. That function allocates GameInstance (0x140) into +0x10 and RuntimeScene (0x4B8) into +0x18, and takes 0x101578050 by `adrp/add` at 0x101577C88 under guard 0x108322D58. That guard is the "CGameFramework/GameInstance" descriptor, initialised at 0x101578388.
- rmap gives old 0x103F0D900.
- Codeware hooks it with HookAfter and only reacts to the call, so the `(void*, void*)` signature matches.

### CommunitySystem_Update: 0x10472C880
- This is the only `(system x0, bool w1)` callee on the CommunitySystem update path.
  - The "CommunitySystem/Update" job lambda 0x10472EA54 (descriptor guard 0x109206BC0, init 0x10472F76C, dispatched from UpdateKick 0x10472E7D4) does `ldrb w1,[x20,#0x109]; mov x0,x20; bl 0x10472C880`.
  - The synchronous wrapper 0x10472C810 does the same at 0x10472C84C.
- The bool sets the time budget: `cmp w20,#0; fcsel d8, DBL_MAX, 0.001` (0x3F50624DD2F1A9FC). When the bool is true, every pending item is processed.
- The pending items are the StreamInOutRequestEntry queue at +0x58/+0x64, stride 0x28 (helper 0x10472EEC0, a `DynArray<game::CommunitySystem::StreamInOutRequestEntry>` symbol), and a second queue at +0x48/+0x50. The function locks +0xA1 and +0xA0.
- That fits Codeware's use, `Update(system, true)` right after DeactivateCommunity or ResetCommunity: flush the stream requests now.
- The old twin is 0x1014AD374 (rmap). Its prologue and budget constants are the same.

### EngineTime_Frequency: 0x1099DC4F8 (data, `__DATA`)
- The EngineTime.ToDouble script native 0x1010715F4 computes `scvtf d0,ticks; ldr d1,[0x1099DC4F8]; fdiv d0,d0,d1`.
- It is registered at 0x1010711C8 under the "ToDouble" name string 0x1074D40A7, in the EngineTime natives block 0x101070D50.
- The writer is 0x101070F38: `clock_gettime(4,…)`, then `str w(1e9)` to 0x1099DC4F0 and `str x(0x41CDCD6500000000 = 1e9 double)` to 0x1099DC4F8.
- The old twins have the same code: init 0x10214C1F0 writes 0x10900B408, and ToDouble 0x10214C694 reads it with `fdiv`.
- The global has 300+ readers.
- The type is `double`, as Codeware's `RawPtr<double>` expects.
- Offset: 0x1099DC4F8 - 0x107D30000 = 3:0x1CAC4F8.

### EntitySpawnerToken_GetWaitHandle: 0x1019F6E34
- The body is `ldr x0,[x0]` (the token's state SharedPtr at +0); if that is set, it does `b 0x1019F7884` (`add x0,x0,#0x78; ret`). Otherwise it returns the static empty JobHandle 0x108425A90.
- That static is initialised by 0x1019F71E8 through the JobHandle ctor 0x104DDF648 (x1=0), with dtor 0x104DDF828.
- All 4 callers (0x101A261B4, 0x1045B1D30, 0x104CA7FF0, 0x104CA8008) pass x0 as x1 to the job wait functions 0x104DDF3BC or 0x104DDF868.
- In 0x101A26xxx the token it is called on comes from `[x20+0x90]`, right after the verified token dtor thunk 0x1019F6D50.
- It sits in the EntitySpawner token cluster next to the dtor. The neighbouring accessors use token +0x10, +0x21 and +0x22, which match Codeware's token layout (entity at +0x10, failed at +0x21).
- Codeware declares no function type for it and never calls it.

### EntitySpawnerToken_dtor: 0x1019F6CA8 (body)
- fmap maps the old thunk 0x100CE0DD0 and the old body 0x100CE0D28.
- On 2.5.0 the thunk is 0x1019F6D50 (`b 0x1019F6CA8`, 53 callers), and the body is 0x1019F6CA8. The body:
  1. releases the entity Handle at +0x10/+0x18, calling 0x1019AB7F8 when entity+0x156 is in 2..5;
  2. releases the SharedPtr at +0/+8 (inner dtor 0x1019F7630, then free);
  3. returns `this`.
- It is called after the token refcount drops in the spawn service 0x1019F2F3C. That is the mapped spawn service from old 0x100CDD130, which the verified SpawnFromTemplate 0x1046E03B8 calls.
- Either the thunk or the body is safe to call; the body is the one to patch.

## Summary
1. 19 entries: 16 FOUND (15 functions plus one `__DATA` global, EngineTime_Frequency at 3:0x1CAC4F8) and 3 NOT FOUND (ResourceLoader_OnUpdate, ResourceSerializer_OnResourceReady, TPPRepresentationComponent_IsAffectedSlot). The last two are inlined and have no standalone function.
2. ArchiveXL macOS fork: hook MappinSystem GetMappinData/GetPoiData at system level (x0 = system), as upstream does, not the resource-level lookup. On 2.5.0 the system function adds a fallback after the resource lookup.
3. Use the new upstream signatures: LoadArchives takes 6 args (w4 mode, w5 fail severity) and returns a status; OnDependenciesReady returns bool; TweakDB_Load is `(TweakDB*, bool w1, CString&)`; Serializer PostLoad returns bool (it now reads the request params at +0x39 as 2 bytes).
4. Layout: the ResourceDepot lock moved to +0xE8, and the CBaseFunction native flag sits at +0xA8 (the struct grew). The IsAffectedSlot hook has no target, so keep it disabled. Hot reload (OnUpdate) stays unavailable on macOS.
5. Codeware: InitializeGameInstance is the "CGameFramework/GameInstance" job lambda `(closure, jobctx)`; CommunitySystem_Update is `(system, bool)`; EngineTime frequency is a double (1e9). No Codeware signature changes are needed.

---

## Batch 4 result (Codeware, 19 entries)

| hash | name | new address (vmaddr) | DB offset (seg:0xOFF) | FOUND/NOT FOUND | signature same? |
| --- | --- | --- | --- | --- | --- |
| 3068279668 | EntitySpawner_SpawnEntity | 0x1019F2F3C | 1:0x19F2F3C | FOUND | NO: token returned via x8 sret, request in x1 |
| 525805301 | Entity_ResolveRecordID | - | - | NOT FOUND | - |
| 1559305924 | GetScriptGameInstance | 0x1016A5BA8 | 1:0x16A5BA8 | FOUND | yes |
| 3370191745 | IComponent_Toggle | 0x1019B95F4 | 1:0x19B95F4 | FOUND | yes (x0 this, w1 bool) |
| 2487884020 | IScriptable_CheckClass | 0x1011E4ED4 | 1:0x11E4ED4 | FOUND | yes |
| 1797004238 | IScriptable_CheckExactClass | 0x1011E4F94 | 1:0x11E4F94 | FOUND | yes |
| 2601784524 | ISerializable_Clone | - | - | NOT FOUND | - |
| 2050958960 | InkLayer_AttachWidgetTree | 0x1042CEBA4 | 1:0x42CEBA4 | FOUND | yes (x0 layer, x1 &widget, x2 &proxy) |
| 4792499 | InkLayer_RegisterListener | 0x1042CD324 | 1:0x42CD324 | FOUND | yes |
| 3589084925 | InkLogicController_OnArrangeChildrenComplete | 0x1041ABEA4 | 1:0x41ABEA4 | FOUND | yes |
| 2671382832 | InkLogicController_OnInitialize | 0x1041ABBF4 | 1:0x41ABBF4 | FOUND | yes (24-byte stub, see notes) |
| 1159862457 | InkLogicController_OnUninitialize | 0x1041ABD94 | 1:0x41ABD94 | FOUND | yes |
| 2635337807 | InkSystem_Instance | 0x108ECE4D0 (data) | 3:0x119E4D0 | FOUND | n/a (global pointer) |
| 4284882427 | InkSystem_ProcessCharacterEvent | 0x10427028C | 1:0x427028C | FOUND | yes (x0, w1, w2, returns w0) |
| 673454961 | InkSystem_ProcessInputEvents | 0x10426C760 | 1:0x426C760 | FOUND | yes (x0, x1, x2) |
| 1667176558 | InkWidget_GetLayer | 0x10439C7E8 | 1:0x439C7E8 | FOUND | NO: result via x8 sret, not x1 |
| 3558023194 | InkWidget_ScriptAddChild | 0x1043931A0 | 1:0x43931A0 | FOUND | yes (script native ctx/frame/ret/type) |
| 492509908 | InkWidget_ScriptReparent | 0x1043A7644 | 1:0x43A7644 | FOUND | yes (script native) |
| 2516523266 | InkWidget_SetLayer | 0x1043A0288 | 1:0x43A0288 | FOUND | yes (x0 widget, x1 &proxy) |

Every FOUND text address is in LC_FUNCTION_STARTS (`grep -c "^0x...$" b4_fs.txt` returns 1 for each).
`__DATA` vmaddr is 0x107d30000 (`otool -l`).

Tools in this directory: `B=~/Development/cyberpunk-backups/2026-11-03/Cyberpunk2077-2.5.0-stock`
- `./b4_x $B ref 0xADDR` lists ADRP+ADD/LDR references and B/BL calls to an address.
- `./b4_x $B str "Name"` gives a string's vmaddr.
- `python3 b4_reg.py 0xADDR` lists the natives that the RTTI registration function containing ADDR registers (name, init, fn pointer, ctor).
- `python3 b4_fn.py 0xADDR` disassembles one whole function.

Native registration anchors:
- CClassFunction ctor 0x10109b8a4.
- CClassStaticFunction ctor 0x10109b974.
- CGlobalFunction ctor 0x10109baa8.
- CName-from-string 0x1010b3160.

## Important 2.5 finding: CDPR shipped native Codeware-equivalent code

Version 2.5 macOS contains engine-side ports of Codeware's widget-building and character-input features, gated by global bytes:

- **Gate 0x109D03E64 (widget building).** The ports are:
  - AttachWidgetTree 0x104153F54
  - AttachController 0x104154158
  - AfterReparent 0x1041543C4
  - AfterAddChild 0x1041544C4
  - IsLegacyController 0x10415468C, which checks "detachedWidget"/"gameController"

  The setters 0x10415413C and 0x10415414C sit in a function-pointer table at 0x107BEA188.
- **Gate 0x109D03E68 (character input).** OnCharacterInput port 0x104154790 fires "OnInputKey" with inkKeyInputEvent.

inkAnimBuilder and inkAnimController are also ported, around 0x104156000.

These ports call several functions in this batch in exactly the order that Codeware's `WidgetBuildingService.cpp` calls them, which gives strong caller-position evidence.

Risk: if the engine gates are on, Codeware's hooks on Reparent, AddChild, OnInitialize and ProcessCharacterEvent can double-apply. The plugin owner should decide whether Codeware's hooks should defer to the engine path.

## EntitySpawner_SpawnEntity 0x1019F2F3C
- **Request field offsets** match Codeware's static_asserted EntitySpawnerRequest layout: templatePath +0, callback +0x48 (flags +0x70), priority +0xE1.
- **Factory side.** Vtable 0x1078C9DE0, slot 0x1019F2454, reads transform +0x10, entityID +0x30, appearanceName +0x38 and detached +0x78.
- **Token.** The token ctor 0x1019F6C60 builds a 0x28-byte object with entity +0x10, detached +0x20 and failed/aborted +0x21/+0x22. This matches Codeware's EntitySpawnerToken (size 0x28).
- **Callers and TU.** Nine callers; the EntitySpawner profiler strings are in the same translation unit.
- **Signature change.** On macOS, x0=this, x1=&request, x8=&SharedPtr<Token> (sret). The Windows declaration passes the out SharedPtr as the 2nd argument. The plugin must declare it as returning `SharedPtr<EntitySpawnerToken>` by value, or hook with an x8-aware trampoline.

## Entity_ResolveRecordID: NOT FOUND
- **No anchor.** Codeware resolves the record ID from Puppet::RecordID / Vehicle::RecordID. I found no common resolver that is passed this+0x25C or this+0x658 and has a mapped caller, so there is no second independent piece of evidence. Fail-closed.
- **Layout change.** The gamePuppetBase recordID is at **0x25C** on macOS 2.5: the GetRecordID native 0x1020A0AE8 loads [x0+0x25c]. Codeware uses Puppet::RecordID = 0x260, so that offset needs fixing. The vehicle recordID at 0x658 matches (native 0x102B19790).

## GetScriptGameInstance 0x1016A5BA8
- **Registration.** The global native "GetGameInstance" is registered by 0x1016A6C7C, which calls init 0x1016A9090, then 0x1010295B8, then CGlobalFunction ctor. The fn pointer is in x3 (ADRP+ADD at 0x1016a90b0).
- **Body.** It increments frame->code, then compares [frame+0x28] with the constant 0x415643FF7B. That is the same constant as the Windows byte pattern `48 BA 7B FF 43 56 41 00 00 00`. It then writes 0x18 bytes to ret (ScriptGameInstance).
- **Signature.** Standard script-native signature, unchanged.

## IComponent_Toggle 0x1019B95F4
- **Body.** If byte [x0+0x8B] differs from w1, it stores w1. If bit 1 of [x0+0x88] is set, it tail-calls vt+0x1E8. The SDK puts IComponent isEnabled at 0x8B (unchanged).
- **Callers.** 135 callers, plus an identical inlined body inside the script native IComponent.Toggle 0x1019BA498 (registration fn 0x1019B8C8C, string "Toggle").
- **Caveat.** Script-initiated Toggle calls run the inlined copy and bypass a hook on this address. There is another inline copy at 0x1019B959C.

## IScriptable_CheckClass 0x1011E4ED4
- **Registration.** "IsA" (string 0x1074EFC62) is registered under IScriptable by registration fn 0x1011E46F0, init 0x1011E5CA0 and wrapper 0x1011E5BDC. The wrapper calls CClassFunction ctor 0x10109b8a4 with flags 0x2000. Sibling natives are ToString, GetClassName, IsExactlyA and DetectScriptableCycles.
- **Body.** Reads a CName parameter, calls GetClass (vt+0x10), calls CClass::IsA 0x1010C6BF4, then `strb w0,[x2]`. Script-native signature is unchanged.

## IScriptable_CheckExactClass 0x1011E4F94
- **Registration.** "IsExactlyA" is registered by the same function; init 0x1011E5CEC, ADRP+ADD at 0x1011e5d10.
- **Body.** Compares GetType()->name (vt+0x8, then 0x1010C31C4) with the CName parameter, then `cset` and stores the result to ret. Signature is unchanged.

## ISerializable_Clone: NOT FOUND
- **No anchor.** There is no string anchor and no RTTI native named Clone.
- **Candidates rejected.** I checked the sret-shaped callers of CClass::CreateInstance 0x1010C36A0 (b4_ci.txt, 156 callers): 0x10108C550, 0x10108C690, 0x101097A04 and 0x1010D89E0. All are create-by-name or lazy-create helpers, not clones. AICommand.Copy 0x10514D204 dispatches through a virtual (vt+0x110), not a free Clone function.
- **Fail-closed.** Note for later: the Windows `Handle& out` return would likely become x8 sret on macOS.

## InkLayer_AttachWidgetTree 0x1042CEBA4
- **Caller position.** Called from CDPR's AttachWidgetTree port at 0x1041540FC, immediately after SetLayer. This is the same sequence as Codeware's flow.
- **Body.** Reserves a DynArray of capacity 0x400, matching the Windows pattern `BA 00 04 00 00`.
- **Signature.** x0 layer, x1 &widget handle, x2 &proxy, the same as the declaration. The return value is unused by the port and not verified.

## InkLayer_RegisterListener 0x1042CD324
- **Caller position.** Called from CDPR's AttachController port at 0x104154324, right before the controller's OnInitialize virtual (vt+0x110).
- **Body.** Takes the lock at layer+0x108, copies the handle, and appends it to the DynArray at +0xA8. This matches the Windows pattern. Signature (x0 layer, x1 &handle) is unchanged.

## InkLogicController_OnArrangeChildrenComplete 0x1041ABEA4
- **Vtable.** In the IWidgetLogicController vtable it is the slot 0x10 bytes after OnInitialize; the vtable is base-shared by about 180 vtables.
- **Body.** Loads the global InkSystem [0x108ECE4D0], checks byte +0x209, applies the CName guard and fires the event. This matches the Windows pattern. Signature (x0 this) is unchanged.

## InkLogicController_OnInitialize 0x1041ABBF4
- **Vtable.** It is the slot at 0x107BEBD48, shared by about 180 vtables and called as the base by many overrides. Its neighbours are OnUninitialize (+8) and OnArrangeChildrenComplete (+0x10).
- **2.5 gate.** It tests byte 0x109D03E64. When set, it calls 0x10415468C (CDPR's IsLegacyController port). Otherwise it continues into the old body at 0x1041ABC10, which matches the 2.0 Windows pattern (`[rcx+70h]`, `[rcx+48h]`) and fires "OnInitialize".
- **Hook caveat.** The entry is a 24-byte stub that contains a `b.ne`. A trampoline must relocate that branch correctly, or the hook should go on the old body 0x1041ABC10.
- **Layout change.** The OnInitialize virtual sits at +0x110 in the IWidgetLogicController vtable on macOS, versus SDK 0x108, because of the two Itanium dtor slots.

## InkLogicController_OnUninitialize 0x1041ABD94
- **Vtable.** Slot +8 after OnInitialize.
- **Body.** Fires "OnUninitialize" (CName 0xd3e7ce8f5e9069a9), then `bl 0x1041A9754(this)`. This matches the Windows pattern of an event call followed by a tail call. Signature is unchanged.

## InkSystem_Instance data 0x108ECE4D0 (3:0x119E4D0)
- **Ctor.** The InkSystem ctor does `swpal wzr,[x19+0x644]; str x19,[0x108ece4d0]; mov w0,#0x148; bl ...`, which matches the Windows instance-store pattern.
- **Dtor and users.** The dtor clears it (`str xzr` at 0x10426AF78). It is read by OnArrangeChildrenComplete and by the ink paths.
- **Not a function.** This is a data slot, so it correctly does not appear in LC_FUNCTION_STARTS.

## InkSystem_ProcessCharacterEvent 0x10427028C
- **2.5 gate.** It tests byte 0x109D03E68, which leads to CDPR's OnCharacterInput port 0x104154790 (string "OnInputKey").
- **Body.** Locks inputWidget +0x2E8; keyboardState is at +0x2F8.
- **Caller.** Its only caller is ProcessInputEvents at 0x10426D330.
- **Signature.** x0 this, w1, w2, returns a bool in w0, the same as the declaration.

## InkSystem_ProcessInputEvents 0x10426C760
- **Body.** Saves d8–d11 (the Windows build saves xmm6–8). It checks the layerManagers count [this+0x38C] (DynArray at 0x380), makes RawInputBuffer virtual calls vt+0x10/0x18, and calls ProcessCharacterEvent at 0x10426D330.
- **Caller.** Its single caller is 0x10426C65C.
- **Signature.** x0, x1, x2, unchanged. The RawInputBuffer vtable has two Itanium dtor slots, so any Codeware vtable indexing into that buffer shifts by one slot.

## InkWidget_GetLayer 0x10439C7E8
- **Caller position.** It is the first call in CDPR's AttachWidgetTree port 0x104153F54, the same position as in Codeware's flow.
- **Body.** Checks layerProxy +0x148, then walks parentWidget +0x168 under the lock at +0x1F4. This matches the Windows `lea rbx,[rcx+148h]; mov rdi,rdx; cmp [rbx],0`, where rdx is the MSVC hidden return pointer.
- **Signature change.** The result Handle is written through x8 (sret), not x1. The plugin must declare it as returning `Handle<inkLayerProxy>` by value.

## InkWidget_ScriptAddChild 0x1043931A0
- **Registration.** The inkCompoundWidget "AddChild" native (by CName) is registered by 0x1043909D0, init 0x104393EF4 (ADRP+ADD at 0x104393f18). It is distinct from AddChildWidget 0x104393324.
- **Body.** Codeware's error message names "inkCompoundWidget::AddChild". The Windows 2.0–2.12 pattern has an 8-byte local and keeps r8 (ret) in rsi; the macOS body likewise uses an 8-byte local and preserves ret/type.
- **2.5 gate.** At 0x104393290 it calls CDPR's AfterAddChild 0x1041544C4 with four arguments. Script-native signature is unchanged.

## InkWidget_ScriptReparent 0x1043A7644
- **Registration.** The inkWidget "Reparent" native is registered by 0x104394B58, init 0x1043AFEB0 (ADRP+ADD at 0x1043afedc).
- **Body.** Reads a handle parameter and an int parameter (default -1), then calls internal 0x10439C164.
- **2.5 gate.** At 0x1043A77A8 it calls CDPR's AfterReparent 0x1041543C4. Script-native signature is unchanged.

## InkWidget_SetLayer 0x1043A0288
- **Caller position.** Called from CDPR's AttachWidgetTree port at 0x1041540EC, between GetLayer and AttachWidgetTree.
- **Body.** Assigns the handle at +0x148, takes the lock at +0x1F5, then propertyManager +0x40 calls 0x10437183C.
- **Callers and signature.** 24 callers. x0 widget, x1 &proxy, unchanged.

## Other layout notes
- **inkWidget size.** inkWidget is 0x200 on macOS, versus 0x210 in the Windows SDK. The offsets used here (0x148, 0x168, 0x1F4, 0x1F5) match.
- **Unverified.** InkSystem requestsHandler at 0x370 is not verified.

---

| hash | name | new address (vmaddr) | DB offset (seg:0xOFF) | FOUND/NOT FOUND | signature same? |
|---|---|---|---|---|---|
| 3357288308 | InkWidget_TriggerEvent | 0x104154974 | 1:0x4154974 | FOUND | yes (but the instance is specific to inkKeyInputEvent, see notes) |
| 1337 | MagicSizeLimit | - | - | NOT FOUND (constant, not an address) | n/a |
| 15 | MaxParams | - | - | NOT FOUND (constant, not an address) | n/a |
| 1679234269 | MeshAppearance_ReleaseReference | (candidate 0x1051a31d0) | - | NOT FOUND | no upstream declaration to check |
| 3491172781 | NodeRef_Create | 0x101b17694 | 1:0x1B17694 | FOUND | **NO: changed** |
| 1944983789 | ObjectSerializer_Prepare | - | - | NOT FOUND | - |
| 125247621 | ObjectSerializer_ReadFromStrean | - | - | NOT FOUND | - |
| 2646156567 | ObjectSerializer_WriteToBuffer | - | - | NOT FOUND | - |
| 3442350580 | PersistentObject_InitializeState | 0x1016f3714 | 1:0x16F3714 | FOUND | yes |
| 2394822845 | PhysicsTraceResult_GetHitObject | - | - | NOT FOUND | - |
| 2050111212 | PlayerSystem_OnPlayerSpawned | 0x100fffcb8 | 1:0xFFFCB8 | FOUND | yes |
| 803085170 | PointOfInterestMappin_SetPhase | 0x103140998 | 1:0x3140998 | FOUND | yes |
| 1567104722 | QuestLoader_PhasePreloadCheck | - | - | NOT FOUND | - |
| 779107884 | QuestPhaseInstance_ExecuteGraph | 0x10280b7d0 | 1:0x280B7D0 | FOUND | yes |
| 3227858325 | QuestPhaseInstance_ExecuteNode | 0x10280df0c | 1:0x280DF0C | FOUND | yes |
| 3423879019 | QuestPhaseInstance_Initialize | - | - | NOT FOUND | - |
| 3144298192 | QuestsSystem_CreateContext | 0x102a0c7e8 | 1:0x2A0C7E8 | FOUND | **NO: ABI changed (sret in x8)** |
| 2996308699 | RenderData_Release | 0x104fe0fb8 | 1:0x4FE0FB8 | FOUND | yes |
| 1093803822 | RenderProxy_SetHighlightParams | - | - | NOT FOUND | - |

Binary: `~/Development/cyberpunk-backups/2026-11-03/Cyberpunk2077-2.5.0-stock`. Every FOUND address is in LC_FUNCTION_STARTS. `b5_dup.py` shows each one has exactly one byte-identical copy.

Re-check helper: `python3 b5_h.py 'print(dis(0xADDR))'`. Others: `callers()`, `ptrs()`, `size()`. The Windows patterns quoted below come from `git -C cp2077-codeware show 8099ceea^:tools/ida/scan.py`.

## InkWidget_TriggerEvent: 0x104154974

**Upstream declaration:** `bool(void* manager, CName, Handle<Event>)`. The manager is widget+0x50. Codeware calls it only with an `inkKeyInputEvent` handle (WidgetInputService.cpp:30-32).

**Evidence 1: the game's own call.** The game's key-input dispatcher 0x104154790 does three things:
- It builds an inkKeyInputEvent: 0xB8 bytes, key/action at +0x90/+0x94, char at +0x98, keyboard state at +0x68.
- It loads CName "OnInputKey" (0x1075fd8e8).
- It calls 0x104154974 with x0 = widget+0x50.

**Evidence 2: type data.** The function's GOT refs are type-specific:
- 0x1077B4110 = GetNativeTypeHash<ink::KeyInputEvent>
- 0x10775BA18 = GetTypeObject<THandle<ink::KeyInputEvent>>

These are visible in `fx-new.txt`.

**Signature check:** bool in w0 (`cmp x19,#0; cset w0,ne`). The Handle arrives as a pointer in x2 (Itanium: a non-trivial by-value Handle is passed by pointer). This matches.

**Note:** this is a template instance, and other masked-identical instances exist for other event types: 0x1043261bc IScriptable, 0x1043ab394 Widget, 0x1043abcd8 FocusEvent, 0x1043ac60c CharacterEvent, 0x1043acf40 PointerEvent. Use 0x104154974 only with inkKeyInputEvent, which is all Codeware does.

## MagicSizeLimit (1337), MaxParams (15)

These are not addresses. 1337 is a literal in Serialization.hpp (`constexpr uint32_t MagicSizeLimit = 1337`), and 15 is a constant. There is nothing to resolve.

## MeshAppearance_ReleaseReference: NOT FOUND (candidate 0x1051a31d0)

The candidate behaves like a release:
- Under the lock at +0x98 it decrements +0x9c.
- At zero it releases renderData +0x48 through RenderData_Release and clears the map at +0x68.
- It pairs with the +0x9c increment in LoadMaterialSetupAsync.
- Its callers are RAII wrappers 0x1051a3170, 0x1051a32ac and 0x1051a3340.

Codeware has only the ID (Library.hpp:81). There is no declaration and no use, so the brief's required signature check cannot be done. Under fail-closed rules this is NOT FOUND. Nothing in Codeware calls it.

## NodeRef_Create: 0x101b17694 (SIGNATURE CHANGED)

**Evidence 1: it is the parser.** It is the NodeRef string parser: it handles the `#`, `$`, `~` and `/` prefixes and hashes the path segments. Script native ParseNodeRef 0x101b18060 calls it.

**Evidence 2: Windows shape.** The Windows pattern `mov edi,[rdx+8] ... movzx r12d,r8b; mov r14,rcx; test edi,edi` takes 3 params, the third a bool. The macOS body takes 3 params as well.

**Signature on macOS:** `uint64_t NodeRef_Create(const char* str /*x0*/, uint32_t len /*w1*/, bool flag /*w2*/)`. The NodeRef (a u64 hash) is returned in x0. Codeware declares `NodeRef* (NodeRef& out, StringView& ref)`, which is wrong on macOS. **Plugin change:** call it as `(ref.data, ref.size, false)` and take the return value.

## ObjectSerializer_Prepare / _WriteToBuffer / _ReadFromStrean: NOT FOUND

There is no string anchor and no Windows pattern in the history. These were added after the address-library switch.

I scanned for the WriteToBuffer shape (`b5_ws.py`): w2 stored to the sizeLimit slot of a stack params block, then that block passed to a call in x1. It found only unrelated hits: 0x100911068, 0x102118abc, 0x103e9bc44 and 0x10503fbdc.

Not resolved. Codeware's ScriptableServiceContainer state save/load needs these, so that feature stays off on macOS.

## PersistentObject_InitializeState: 0x1016f3714

**Evidence 1: params layout.** It reads all five PersistentStateParams fields at Codeware's offsets: system +0, mergeStates +8, objectType +0x10, persistentId +0x18, unk28 +0x28.

**Evidence 2: behaviour.** It calls obj vt[0x10] (GetPersistentStateType) and system vt[0x1b8] and vt[0x1c0]. Its merge path is 0x1016f4a78, and it stores the state handle at obj+8. Its caller 0x1016ec180 builds the params block (objects at entity+0x160 and component+0x90).

**Signature:** `void(PersistentObject*, PersistentStateParams*)`, same as upstream. Layout unchanged.

## PhysicsTraceResult_GetHitObject: NOT FOUND

The physicsTraceResult RTTI at 0x104527068 has properties only and no natives. Codeware adds GetHitObject itself as an RTTI method, so there is no script native to anchor on. No conclusive candidate.

## PlayerSystem_OnPlayerSpawned: 0x100fffcb8

**Evidence 1: spawn completion.** It is the target of the spawn-completion closure. Spawner 0x100fff458 creates the closure (vtable 0x107827948), and its invoker 0x101003c80 calls 0x100fffcb8.

**Evidence 2: player object.** Under lock this+0x60590 it stores this+0x60580, the main game object. That is the same field the native GetLocalPlayerMainGameObject 0x100ffc4c0 reads. It then calls the request callback functor.

**Signature:** 4 args, `void*(void*,void*,void*,void*)`. This matches the Windows pattern, which saves r9. Same as upstream; hooked After.

## PointOfInterestMappin_SetPhase: 0x103140998

**Evidence 1: virtual slot.** It sits only at vtable 0x107a9e860 slot +0x1d0 (class size 0x100, ctor 0x103142cd8). The MappinSystem request executor 0x10310cd44 calls target vt[0x1d0](phase) for type-5 requests. Those requests are queued by MappinSystem vtable 0x107A9B098 slot +0x1D8 (0x1030fe028): hash at +0x18, phase at +0x1c.

**Evidence 2: saved state.** It writes saved-state halfword 0. Restore function 0x10314187c bounds that halfword to ≤3, so it is the phase. It also special-cases CompletedPhase=0.

**Layout:** +0x88 is the mappin hash (matcher 0x1031406ec). +0x8C is the Murmur3 journal hash (seed 0x5EEDBA5E), which is Codeware's JournalHash at 0x8C. Unchanged.

**Signature:** (x0, w1 phase), returns in x0. Same as upstream; hooked Before.

**Note:** Codeware's MappinSystem RawVFunc offsets are not in this batch and need their own macOS re-derivation. Slot 0x1D8 on macOS is the SetPhase request, not 0x1D0.

## QuestLoader_PhasePreloadCheck: NOT FOUND

The upstream hook is commented out (QuestPhaseRegistry.cpp:25). Not attempted to conclusion.

## QuestPhaseInstance_ExecuteGraph: 0x10280b7d0

**Evidence 1: Windows shape.** Windows `mov r11,rsp ... mov rax,[r8+?]; mov r13,r9` is 6 args with the 3rd a WeakHandle&. The macOS function saves x0 through x5:
- x2 is a 16-byte WeakHandle: copied with `ldr q0,[x21]` plus weak AddRef 0x101025e1c.
- x3 is a 16-byte socket.
- w4 is the bool. It selects which of the two work stacks (sp+0x60 or sp+0x70) the {node, socket} 0x20-byte item is pushed onto.
- x5 is the output DynArray.

**Evidence 2: call chain.** It loops the work stack and calls step 0x10280d760. The step checks for infinite loops: 0x10286b8d8 on ctx+0x110, logging "Quest System: infinite loop detected at node %hs [%hs]". The step then calls ExecuteNode (below). The 9 callers are the phase-node vtable functions at 0x1079e3330 to 0x1079e3390, plus 0x10280b32c and 0x10280b540.

**Signature:** `uint8_t(phase, QuestContext&, const WeakHandle<node>&, const QuestNodeSocket&, bool, DynArray<QuestNodeSocket>&)`. Same as upstream.

## QuestPhaseInstance_ExecuteNode: 0x10280df0c

**Evidence 1: Windows shape.** Windows `mov rax,[rdx]; mov rbp,rcx; mov rcx,rdx; mov rbx,r9; mov rdi,r8; mov rsi,rdx` loads the node vtable first and takes 5 args. macOS does the same:
- It loads x1->vt[8] (GetType) first, then an IsA check through 0x1010c6bf4.
- x0 is the phase (set at +0xc8, keyed by node id halfword node+0x40).
- x2 is the ctx: it uses ctx+0x110 (QuestPhaseContext, matching Codeware's QuestContext layout), ctx+0x70, and the state byte ctx+1.
- x3 is the socket.
- x4 is the output DynArray.

**Evidence 2: only caller.** Its only caller is the graph step 0x10280d760, which calls it as `(x0=phase, x1=node, x2=ctx, x3=&item.socket, x4=out)`. On result 0, that caller appends 16-byte {CName, u8} QuestNodeSocket entries to the out array. Return values are 0 to 3 in w0 (uint8).

**Signature:** `uint8_t(phase*, questNodeDefinition*, QuestContext&, const QuestNodeSocket&, DynArray<QuestNodeSocket>&)`. Same as upstream.

## QuestPhaseInstance_Initialize: NOT FOUND

The upstream hook is commented out. Not attempted to conclusion.

## QuestsSystem_CreateContext: 0x102a0c7e8 (ABI CHANGED)

**Evidence 1: Windows shape.** Windows `mov rax,[rcx+?]; lea r10,[rcx+????]; mov [rsp+?],rax` reads a field of the system, takes the address of a large offset, and calls the QuestContext ctor. The macOS function (0x44 bytes) does the same:
- `ldr x5,[x0,#0xe8]`, `add x10,x0,#0x1d0`, `ldr [x0,#0x2c8]`, `ldr [x0,#0x40]`, `add x6/x7,x0,#0xa8/#0xb8`.
- Then `mov x0,x8; bl 0x10280379c`. 0x10280379c is a thunk to the QuestContext ctor 0x102803660, which stores w1 at ctx+0 and ctx+1, w2 at +2, and w3/w4 at +4/+8.

**Evidence 2: the game's own use.** 
- QuestsSystem vtable methods 0x102a0c704 to 0x102a0d6a0 (vtable 0x107a2f480 to 0x107a2f4b0) inline the same sequence with 0x360-byte frames. They then lock sys+0x60 and read the root phase at sys+0x68, which matches Codeware's Mutex 0x60 and RootPhase 0x68 offsets.
- The only out-of-line caller, 0x102a16184, has a 0x340-byte frame, which is `sizeof(QuestContext)`. It calls `CreateContext(x8=sp, w1=11, w2=0, w3=-1, w4=-1)`, then passes the ctx to a root-phase call, then calls dtor 0x102a12b7c.

**ABI change:** the context is returned by value through **x8** (sret), and the four scalars move to w1 to w4. Codeware's `void*(sys, QuestContext* x1, int32, int8, int32, int32)` would put the ctx pointer in x1 and is wrong on macOS.

**Plugin change:** declare it as returning a 0x340-byte struct by value, for example `QuestContextStorage(*)(questIQuestsSystem*, uint8_t a3, uint8_t a4, int32_t a5, int32_t a6)`. Any struct over 16 bytes is returned through x8 under AAPCS64. Alternatively, a shim can set x8 to &context before the call. Codeware's call `(sys, &ctx, 1, 0, -1, -1)` becomes `ctx = CreateContext(sys, 1, 0, -1, -1)` with the result built in place.

## RenderData_Release: 0x104fe0fb8

**Evidence 1: the body.** `add x8,x0,#8; ldaddal -1`. If the old count was 1, it does `br [vt+8]`. That is an intrusive refcount release. Its AddRef sibling is 0x104fe0fa8. It has 969 callers and one copy.

**Evidence 2: MeshAppearance.** The MeshAppearance dtor 0x1051a39bc (vtable 0x107d1d690) releases renderData +0x48 through it. 0x1051a31d0 has the same `ldr x0,[x19,#0x48]; str xzr; cbz; bl` sequence that Codeware MeshAppearanceEx uses.

**Signature:** `void(RenderData*)`, same as upstream. MeshAppearance layout 0x48/0x90/0x98/0xa0 is unchanged (confirmed in the verified function 0x1051a3c24).

## RenderProxy_SetHighlightParams: NOT FOUND

Unused upstream: it is declared in Rendering.hpp:54 but never called. Not searched to conclusion.

---

## Batch 6 result (Cyberpunk 2.5.0 macOS arm64)

| hash | name | new address (vmaddr) | DB offset (seg:0xOFF) | FOUND/NOT FOUND | signature same? |
|---|---|---|---|---|---|
| 429336746 | RenderProxy_SetMaterialOverride | - | - | NOT FOUND | n/a |
| 2838044016 | RenderProxy_SetScanningState | - | - | NOT FOUND | n/a |
| 1790971865 | RenderProxy_SetVisibility | - | - | NOT FOUND | n/a |
| 2124419179 | RenderProxy_UpdateVisibility | - | - | NOT FOUND | n/a |
| 2288918343 | ResourceBank_ForgetResource | 0x1010e4454 | 1:0x10E4454 | FOUND | NO (Handle returned via x8 sret) |
| 4272634361 | ResourceSerializer_ScheduleFinalizeJobs | - | - | NOT FOUND | n/a (no macOS equivalent) |
| 3599579551 | ResourceSerializer_SchedulePostLoadJobs | - | - | NOT FOUND | n/a (no macOS equivalent) |
| 2840271332 | RuntimeEntityRegistry_RegisterEntity | 0x101a2bb60 | 1:0x1A2BB60 | FOUND | yes (returns bool; void decl is fine) |
| 3878623943 | RuntimeEntityRegistry_UnregisterEntity | 0x101a2bf84 | 1:0x1A2BF84 | FOUND | yes |
| 3800374702 | RuntimeScene_AttachEntity | - | - | NOT FOUND | n/a (no upstream decl) |
| 1732384813 | RuntimeScene_DetachEntity | - | - | NOT FOUND | n/a (no upstream decl) |
| 1576214475 | RuntimeSystemEntity_AttachEntity | 0x101a3d6fc | 1:0x1A3D6FC | FOUND | yes |
| 2597397686 | RuntimeSystemEntity_DetachEntity | 0x101a3d704 | 1:0x1A3D704 | FOUND | NO (no reason arg; x2 ignored) |
| 1471948702 | RuntimeSystemWeather_GetEnvironmentDefinition | 0x101a71abc | 1:0x1A71ABC | FOUND | NO (Handle returned via x8 sret) |
| 2679119876 | RuntimeSystemWeather_GetWeatherState | 0x101a71548 | 1:0x1A71548 | FOUND | NO (Handle returned via x8 sret) |
| 2987664085 | RuntimeSystemWeather_SetWeatherByIndex | 0x101a70298 | 1:0x1A70298 | FOUND | yes |
| 2334794340 | RuntimeSystemWeather_SetWeatherByName | 0x101a730fc | 1:0x1A730FC | FOUND | yes |
| 3993832650 | ScriptBundle_dtor | 0x10111cc00 | 1:0x111CC00 | FOUND | yes (returns this); struct LAYOUT CHANGED |
| 2439126103 | ScriptOpCodes_Handlers_Cast | 0x101202b54 | 1:0x1202B54 | FOUND | yes |

Counts: 11 FOUND, 8 NOT FOUND (19 total).

## RenderProxy_SetMaterialOverride / SetScanningState / SetVisibility / UpdateVisibility: NOT FOUND
None of these four has an old-hash hint or a macOS DB entry. Codeware declares all four in src/Red/Rendering.hpp but never calls them.
- I scanned for small functions that read and write the flags byte [x0+0x23]. That gives a cluster at 0x104fe43fc..0x104fe4f78.
- Two setters there:
  - 0x104fe4ca0 sets or clears bit 0x2 from w1.
  - 0x104fe4f3c does the same for bit 0x4.
  - Both tail-call 0x104fe4ce0 when the visible state ((flags&6)==6) changes.
- 0x104fe46a4 (x0..x3) stores a handle at +0x8, bit 0x2 from w2 and a value at +0x18.
- Nothing shows which bit is "SetVisibility" and which is "UpdateVisibility". 0x104fe4ce0 takes only x0, so it does not match the (proxy, bool) UpdateVisibility declaration. I found no SetScanningState or SetMaterialOverride candidate.
- Leads only. Not found, fail-closed.

## ResourceBank_ForgetResource: FOUND 1:0x10E4454 (signature changed)
- Body:
  - calls 0x1010e45b8(bank+0x60, &path);
  - takes the exclusive lock bank+0x98 (bl 0x1000015f0; release `ldclralb #0x80`);
  - looks up the hashmap at bank+0 with key hi^lo;
  - promotes the weak ref to strong into [x8], then erases the entry and decrements the count at +8.
- Callers 0x1010e8374 and 0x1010e8ecc do `ldr x0,[loader,#0x48]; mov x8,sp; x1=path`.
  - fmap maps them to 2.3.1 0x1021b8334 and 0x1021b8ecc. In 2.3.1 the same spot calls 0x1021b4ab8.
  - They use the same bank object as thunk 0x1010e888c (`ldr x0,[x0,#0x48]; b 0x1010e3b28`).
- Rejected twins:
  - 0x1010e3a34, a Find that takes the shared lock and does not erase;
  - 0x1010e3990, an unlocked Find.
- Signature: macOS is `Handle<T> ForgetResource(bank x0, ResourcePath x1)` with an x8 sret. The plugin's `(bank, Handle& out, path)` must change to sret form.

## ResourceSerializer_SchedulePostLoadJobs / ScheduleFinalizeJobs: NOT FOUND (no equivalent)
macOS 2.5.0 keeps the 2.3.1 pipeline:
- Load 0x101207588;
- scheduler 0x101207ed4;
- WaitForDependencies lambda 0x101209038;
- OnDependenciesReady 0x1012090B0.
  - It runs the post-load pass synchronously: 0x10120b670(ctx+0xB0, ctx+0x1D0, &queue).
  - It then dispatches the completion lambda 0x1012092e0, which calls `blr x22(ctx+0x230, ctx+0x10, ctx+0x1D0, ctx+0x20, x21)`.

The serializer region 0x101207400–0x10120c600 has only six ADR-taken lambdas: 0x101209618, 0x101209038, 0x1012090b0, 0x1012092e0, 0x1012093bc and 0x101207ed4. None is a separate schedule-post-load or schedule-finalize stage.

The Windows hook ABI (a1, u8, a3=&queue.unk10, a4, captures**) does not match the macOS job shim (captures** x0, ctx x1).

Recommendation: on macOS keep the pre-2.5 Codeware hooks:
- OnDependenciesReady (1185093671, verified 1:0x12090B0);
- the completion stage.

Lead, not in this batch: 0x10120b670 is probably ExecutePostLoad.

## RuntimeEntityRegistry_RegisterEntity: FOUND 1:0x1A2BB60
- Body:
  - takes the exclusive lock at reg+0x43;
  - uses key [entity+0x48] (EntityID) and takes a weak handle (0x1010b0e90);
  - inserts into the map at reg+0x48 (0x101a2d108), then unlocks;
  - calls notify 0x101a2bc84(reg, ent, 1).
- Callers 0x1016ec498, 0x101fb32b4 and 0x1040500f4 pass x0 = [[[ent+0xb8]+8]+0x68]. That is cached scene system index 13 = RuntimeEntityRegistry.
- The function lies between the "worldRuntimeEntityRegistry" RTTI string refs 0x101a2b754 and 0x101a2d4b0, and the RTTI size 0xB0 fits.
- Callers 0x101fb1014 and 0x101fb3250 run an IsA check before register and unregister, as Codeware does.
- Signature: (reg, Entity*). It returns bool; the plugin declares void, which is harmless.

## RuntimeEntityRegistry_UnregisterEntity: FOUND 1:0x1A2BF84
- Body: same lock and map as RegisterEntity. It finds key entity+0x48, erases the entry and decrements [+0x50], then calls notify 0x101a2bc84(reg, ent, 0).
- Callers 0x1016ec680 and 0x101fb10dc reach it through the same index-13 cache.
- Signature: same.

## RuntimeScene_AttachEntity / DetachEntity: NOT FOUND
Codeware never calls these and has no signature for them, so I cannot check a candidate against upstream. Fail-closed.

## RuntimeSystemEntity_AttachEntity: FOUND 1:0x1A3D6FC
- Body: thunk `ldr x0,[x0,#0x48]; b 0x101a0e054`. 0x101a0e054 checks a flag, then calls the queue 0x101a0e070(mgr, req, 1).
- Caller 0x101a26840 loads x0 = [scene,#0xa0] (system index 10). It builds the request at sp+0x38 in exactly the Codeware layout, then destroys it (0x1019bfeb0):
  - entity handle at +0;
  - null handles at +0x10 and +0x20;
  - `strh wzr` at +0x30.
- A second caller, 0x1019bfc70, gets the system through [ctx+0x50] (cached index 10).
- Signature: (sys, const Request&). Same.

## RuntimeSystemEntity_DetachEntity: FOUND 1:0x1A3D704 (signature changed)
- Body: thunk `ldr x0,[x0,#0x48]; b 0x101a0e16c`. It sits directly after the AttachEntity thunk and uses the same manager.
- 0x101a0e16c(mgr, Handle<Entity>& x1) builds the request {handle, null, null, u16 0}, then calls the same queue 0x101a0e070(mgr, &req, 2): mode 2 = detach, where attach uses mode 1.
- Caller 0x101a26840 is an attach/detach toggle. Its w1==0 branch tail-calls this function with x1 = &handle; 0x1019bfcd8 tail-calls it too.
- Signature: macOS has no reason parameter, so x2 is ignored and the reason is always 0. Codeware always passes 0, which makes the call harmless. Still, the declaration should drop the arg on macOS.

## RuntimeSystemWeather_GetEnvironmentDefinition: FOUND 1:0x1A71ABC (signature changed)
- Body: `mov x19,x8; ldr x0,[x0,#0x60]; bl 0x101b695cc`, then copies the handle to [x19].
- The handle's object is a worldEnvironmentDefinition: weatherStates sit at +0x188 per RTTI, and 0x101a72ccc indexes [def+0x188]/[+0x194].
- Callers 0x1046b0b34 and 0x1046cfe60 load [scene,#0x280] (Weather, index 40), then call it with x8 set.
- Signature: the plugin declares `void*(sys, Handle& out)`. macOS needs `Handle<T>(sys)` with an x8 sret.

## RuntimeSystemWeather_GetWeatherState: FOUND 1:0x1A71548 (signature changed)
- Body: `ldrb w9,[x0,#0x84]; csel 0x88/0x90; ldr w1,[x0,x9]; b 0x101a72ccc`. The target is GetWeatherStateByIndex, which returns via x8 sret and reads the [def+0x188] states.
- Caller 0x102737cc0 (quest weather condition) compares the result's name (0x101ae0ae4) with the condition's weather.
- Rejected: 0x101a72f3c, which reads [0xB8], the previous state.
- Signature: Handle returned via x8 sret.
- Note: the current index is the override index at +0x88 when byte +0x84 is set, otherwise +0x90. Codeware's CycleWeather OffsetPtr 0x8C does not match this macOS layout. I have not verified this; check before use.

## RuntimeSystemWeather_SetWeatherByIndex: FOUND 1:0x1A70298
- Body: copies the state block 0x90..0xB8 to 0xB8 (previous), then `str x24,[x19,#0x98]` (source) and `str w8,[x19,#0x90]` (index).
- Called from SetWeatherByName with 7 args, plus 8 other callers.
- Signature: (sys, w1 index, x2 source, s0 blend, w3, w4, w5 notify). Same.

## RuntimeSystemWeather_SetWeatherByName: FOUND 1:0x1A730FC
- Body:
  - loops over the states, comparing each state name (0x101ae0ae4) with x1;
  - calls ByIndex with `mov w5,#1` (notify);
  - compares [sys+0x98] (CurrentSource);
  - references "weather_state_events" (0x107519dd7).
- Callers 0x102921150 and 0x1029211ec are in questPlayEnv_SetWeather code.
- Signature: (x0 sys, x1 name, x2 source, s0 blend, x3, x4), returns bool. Same.

## ScriptBundle_dtor: FOUND 1:0x111CC00 (struct layout changed)
- The function is reached only through the 4-byte alias 0x10111d434 (`b 0x10111cc00`). The alias has 8 BL callers, all in the CScriptingSystem script-load area: 0x1011e7788, 0x1011e7790, 0x1011e9878, 0x1011e9d80, 0x1011e9fa8, 0x1011ea1dc, 0x1011eb254 and 0x1011ec070. The "Failed to load scripts" refs are at 0x1011e7260 and 0x1011e9374.
- Neither address has a data pointer or ADR reference.
- Hook the D2 at 0x10111cc00; the alias tail-calls into it, so hook-after also works there.
- The body matches the ScriptBundle fields one by one:
  - calls 0x10111d010(this);
  - dependencies DynArray at 0x1A0 (count 0x1AC): for each ref with isOwned (byte +8 == 1), frees ref->environment via 0x1052a73a0 (red::memory::Free<PoolScript>), then frees the ref;
  - DynArrays at 0x1F8, 0x1E8, CString at 0x1C0, DynArrays at 0x1B0, 0x1A0, DynArray<CString> at 0x180;
  - pthread_mutex_destroy(this+0x140);
  - HashMap<CString,u32> at 0x108;
  - DynArray<CString> at 0xF8;
  - DynArrays at 0xE8, 0xD8, 0xC8, 0xB8, 0xA8, 0x98;
  - HashMaps at 0x68, 0x38, 0x08;
  - returns this.
- Signature `void(ScriptBundle*)`: same.
- LAYOUT: the macOS mutex is 0x40 bytes (Windows 0x28), so every field after 0x140 moves +0x18:
  - filePaths 0x180, baseBundle ~0x198, dependencies 0x1A0, extraTypes 0x1B0;
  - unk1A8 CString 0x1C0, bundleIndex ~0x1E0, extraProperties 0x1E8, unk1E0 0x1F8;
  - isScriptMod ~0x208, size ~0x210.
- Codeware's ScriptBundle.hpp needs a macOS layout.

## ScriptOpCodes_Handlers_Cast: FOUND 1:0x1202B54
- Register site 0x10120454c/0x101204550: `adrp/add x1=0x101202b54; mov w0,#0x5a (opcode 90); bl 0x1011a9554`. That function stores into the verified OpcodeHandlers table 3:0x1D2C940 (`str x1,[table,w0,uxtw#3]`).
- Body is DynamicCast:
  - reads an 8-byte CClass* operand and a weak-flag byte;
  - evaluates the sub-expression through the table;
  - runs the IsA check `bl 0x1010c6bf4` with x1 = class;
  - writes the handle to x2.
- Signature: (ctx, frame x1, ret x2, type x3). Same.

---

## batch7 result: Codeware + TweakXL, 2.5.0 macOS (7D7382D0)

Every FOUND address is in LC_FUNCTION_STARTS, segment 1 (`__TEXT`). Helpers: `re/d.py` (disassembly with string notes),
`re/x.sh` (xref_scan), and `re2/b7_*.py` (`b7_rng.py` range refs, `b7_st2.py` store tracking, `b7_pat.py` call+vslot,
`b7_native.py` RTTI native resolver).

| hash | name | new address (vmaddr) | DB offset (seg:0xOFF) | FOUND/NOT FOUND | signature same? |
| --- | --- | --- | --- | --- | --- |
| 2669615409 | ScriptOpCodes_Handlers_New | 0x101202FDC | 1:0x1202FDC | FOUND | yes |
| 2070546748 | ScriptOpCodes_Register | 0x101203FA8 | 1:0x1203FA8 | FOUND | yes (`void()`) |
| 4224523662 | ScriptValidator_CompareType | 0x1011A9108 | 1:0x11A9108 | FOUND | yes |
| 1156189659 | ScriptValidator_CompareTypeName | - | - | NOT FOUND (inlined on macOS) | n/a, **hook needs a redesign** |
| 898639042 | ScriptValidator_Validate | 0x1011A7E28 | 1:0x11A7E28 | FOUND | yes. The DB's unverified 1:0x3D96BF4 is wrong. |
| 560604283 | ScriptValidator_ValidateProperty | 0x1011A8F30 | 1:0x11A8F30 | FOUND | yes (x0 is ignored) |
| 3961524856 | SoundBankManager_ReadSoundBanksJson | 0x1051D4F30 | 1:0x51D4F30 | FOUND (see the wrapper note) | yes |
| 1239092911 | TagSystem_AssignTag | 0x1040075E8 | 1:0x40075E8 | FOUND | yes |
| 1875775378 | TagSystem_UnassignTag | 0x104007B40 | 1:0x4007B40 | FOUND | yes |
| 1883248814 | VehicleController_ToggleAuxLights | 0x102B3DAC0 | 1:0x2B3DAC0 | FOUND | yes |
| 1159928678 | VehicleGarageComponent_LoadSummonSetup | 0x102AA79A8 | 1:0x2AA79A8 | FOUND | yes |
| 3027836941 | VehicleSystem_ToggleGarageVehicle | 0x102BBA088 | 1:0x2BBA088 | FOUND | yes |
| 1070077985 | VisionModeSystem_SetBraindanceMode | - | - | NOT FOUND | n/a (Codeware never calls it) |
| 2912168594 | VisualController_LoadDependencies | 0x10199E498 | 1:0x199E498 | FOUND | **NO: the JobHandle comes back through x8 (sret) and a3 is in w1** |
| 2234523611 | WorkspotSystem_GetWorkspotInstance | - | - | NOT FOUND | n/a (Codeware never calls it). **Layout flag below.** |
| 3652194890 | StatsDataSystem_InitializeParams | 0x1023B29A0 | 1:0x23B29A0 | FOUND | yes |
| 4053739225 | TweakDB_Init | 0x101EF64C8 | 1:0x1EF64C8 | FOUND | yes (`void(void*, void*)`) |
| 63182599 | TweakDB_Load | 0x1037CE05C | 1:0x37CE05C | FOUND | yes, matches the new upstream `(TweakDB*, bool, CString&)` |
| 464332086 | TweakDB_TryLoad | 0x1037D60CC | 1:0x37D60CC | FOUND | yes, matches the new upstream `(a1, TweakDB*, CString&, a4, bool a5)` |

## ScriptOpCodes_Register `0x101203FA8` and Handlers_New `0x101202FDC`

- The verified OpcodeHandlers table (961751128) sits at 3:0x1D2C940 = `0x109A5C940`. It is in `__common`, so it is filled at
  run time. Only two functions store into it: `0x1011A9554` (`add x8,table; str x1,[x8,w0,uxtw #3]; ret`, which is
  `RegisterOpcode(idx, fn)`) and `0x1011A9590` (an auto-index variant). Found with `python3 re2/b7_st2.py new re2/b7_tbl_refs.txt 1`.
- `0x101203FA8` is the only caller of `0x1011A9554`, with 107 calls. It runs `mov w0,#i; adrp/add x1,handler; bl` for
  i = 0..0x6A in order, and the last one is a tail `b`. It has one caller, `0x1011E6E6C`, in the script loader, which is
  the same function that calls Validate at `0x1011E71D8`. Through fmap it maps to old `0x102252EF4` (prefix).
- Opcode 48 is `0x1012042AC: add x1,..#0xfdc; mov w0,#0x30; bl` and gives **New = `0x101202FDC`**. Its body does
  `ldr x8,[x1]; ldr x21,[x8],#8; str x8,[x1]`, which reads a `CClass*` from `frame->code` and advances it by 8. It then
  calls CreateInstance `0x1010C36A0(cls,0x40,0)` (verified), with "Unable to create object '%s'" as the failure message,
  and moves the handle into `*x2` (aRet). This matches `ScriptOpCodeNew`.
- Opcode 90 is `0x10120454C` and gives Cast = `0x101202B54` (not in this batch). It reads `CClass*` at +0 and `isWeak` at
  +8, then advances code by 9 or 10, which matches Codeware's Cast parser.
- Signatures: Register is `void()`. The handlers are `(ctx x0, frame x1, ret x2, type x3)`.

## ScriptValidator_Validate `0x1011A7E28`

- It references "Validation failed for %u type" and "Validation failed for %u types" (`0x1074ECCB4`/`0x1074ECCD2`, unique) at
  `0x1011A7F70`/`0x1011A7F78`. fmap maps it to old `0x1021FBF90` by body.
- Signature: `x0` validator, `x1` bundle (passed to the definition collector `0x10111EBCC(bundle,&arr,0)`), `x2` report
  (reached through `report->vt[+0x10]`). It returns `w19` as bool. The call site `0x1011E71D8` passes `add x0,sp,#0x3f`
  (a stack validator), `add x1,sp,#0x270`, and `x2`, then `cbz w0`. This matches `bool(void*, ScriptBundle*, void*)`.
- It dispatches per definition kind. Kind 1 (class) goes to the class validator `0x1011A84B4(validator, def, report)`.

## ScriptValidator_ValidateProperty `0x1011A8F30`

- The class validator `0x1011A84B4`, in its property loop, does `GetProperty(cls, name)` (`0x1010C4C14`). If the result
  is null, it reports "Missing native property '%hs' in native class '%hs'". Otherwise it runs
  `mov x1,scriptProp; mov x2,nativeProp; bl 0x1011A8F30` at `0x1011A8B9C`. A false result (`tbnz w0` falls through) gives
  "Imported property '%hs.%hs' type '%hs' does not match with the native one '%hs'." (`0x1074ED0CA`) at `0x1011A8C10`.
- Body: `mov w0,#0` first, so **x0 is not read**. It loads `ldr x20,[x1,#0xb8]` (ScriptProperty::type, Codeware 0xB8)
  and `ldr x19,[x2]` (CProperty::type), then switches on `ScriptType::metaType` `[x20,#0x54]` (Codeware 0x54). For
  DynArray (4), native GetType()==3; for StaticArray (5), 6 or 7. Both branches tail-call CompareType(nativeInner,
  scriptInner) at `0x1011A90F4`. Return is bool in w0.
- Signature: Codeware's `bool(void* validator, ScriptProperty*, CProperty*)` is compatible. The validator in x0 is passed
  through and ignored.

## ScriptValidator_CompareType `0x1011A9108`

- It is the tail-call target from ValidateProperty (`0x1011A90F4 b 0x1011A9108`) with x0 = native inner type
  (vt+0xC8) and x1 = script `innerType` (+0x48).
- Body: `(x0 native, x1 script)`. It loops through arrays: native 3 needs metaType 4, native 6 needs 5, 9 needs 2 (handle),
  0xA needs 3 (whandle), 0xF needs 6 (ScriptRef). Each step goes to inner types (`[x19,#0x48]`, native vt+0xC8). The leaf
  compares the script name (+8) with native `GetName()` (vt+0x10). If they differ, it calls
  `CRTTISystem::Get()->vt[+0x120](scriptName) == nativeName`. Return is `cset w0,eq`. This matches
  `bool(CBaseRTTIType*, ScriptType*)`.

## ScriptValidator_CompareTypeName: NOT FOUND

- `(scriptName, nativeName)`: the check is `a == b || rtti->vt[+0x120](a) == b`. It is inlined at the leaf of both
  ValidateProperty (`0x1011A9090..0x1011A90AC`) and CompareType (`0x1011A9250..0x1011A926C`).
  `python3 re2/b7_pat.py new 0x1010B3288 0x120` finds the `bl CRTTISystem_Get` + `ldr x8,[x8,#0x120]` pattern **only** in those two
  functions. 2.3.1 is the same (`b7_pat.py old 0x1021885A0 0x120` gives only `0x1021FCFB8` and `0x1021FD144`). No
  standalone function exists, so there is nothing to hook.
- **Plugin change:** Codeware's `HookAfter<CompareTypeName>(OnValidateTypeName)` needs a replacement on macOS. Two
  options: hook `CompareType` (which handles the ResourceRef, ResourceAsyncRef and CurveData script aliases) and
  `ValidateProperty`, or patch the two inline sites.

## SoundBankManager_ReadSoundBanksJson `0x1051D4F30`

- The static initializer `0x1051D76A0` hashes "base\sound\event\soundbanks.json" (`0x10765E32C`, unique) into the
  ResourcePath global `0x109D249E0`. The only other user of that global is `0x1051D4F30` (`0x1051D4FB0`).
- Body: `mov x23,x0` (the manager). It opens the depot file, parses JSON fields "Name", "IsResident" and "ResourcePath",
  and formats "base\sound\soundbanks\%s.bnk". It allocates 0x18-byte entries `{CName, bool @+8, ResourcePath @+0x10}`,
  which matches `Red::SoundBankEntry`, and inserts them into the map at **this+0x68** (`add x0,x19,#0x68; bl 0x1051D71DC`).
  That matches Codeware's `RegisteredBanks` offset 0x68, so the layout is unchanged. It returns `w20` (0 when the file is
  missing). fmap maps it to old `0x100DC8D0C` (strings).
- **Wrapper note:** a separate function `0x1051D4F1C` does `ldrb w8,[x0,#0x1a8]; tbz -> b 0x1051D4F30; else return 0`.
  It is the only caller, called once from `0x103891030` with x0 = the manager. 2.3.1 has the same pair: `0x100DC8CF8` and
  `0x100DC8D0C`. I chose the inner function because it is the one that reads the JSON. Both are `bool(void*)`. Hooking the
  inner one means Codeware does not inject banks when the +0x1A8 flag skips loading. If the Windows hash names the
  wrapper, 0x1051D4F1C is the alternative, and either is crash-safe.

## TagSystem_AssignTag `0x1040075E8` / UnassignTag `0x104007B40`

- GameTagSystem holds an embedded redTagSystem at **+0x48**: the native GetAnyMatchingEntity `0x101709E88` does
  `add x0,x20,#0x48; bl 0x104008A34`. That matches Codeware's `OffsetPtr<0x48>`.
- There are two twin list wrappers, `0x104007AE8` and `0x104007FD0` (both `(sys, entityID, tagList)`, which iterate
  `0x104005EA8(tagList)`). They call `0x1040075E8(sys,x1=id,x2=tag)` and `0x104007B40(sys,x1,x2)` respectively, once per tag.
- Assign `0x1040075E8`: `cbz x2` (a null tag returns) and locks `this+0x60`. It looks up map[tag] (+0x00 table) and
  creates the entry if needed (`0x104009C0C`). It appends the id if it is absent (grow via `0x100028674`), then notifies
  the listener map (+0x30) through vt+0x10 for a new entry and vt+0x20 for an added id.
- Unassign `0x104007B40`: same lock and lookup. It finds the id, swap-removes it (`sub w8,w8,#1; str w8,[x25,#0x1c]`),
  and notifies vt+0x28. If the list becomes empty, it erases the entry (`0x103F032A8`) and notifies vt+0x18.
- fmap: old `0x1020CDE7C` and `0x1020CE358` (prefix). Signatures are `void(redTagSystem*, EntityID x1 by value, CName x2)`,
  which matches Codeware.

## VehicleController_ToggleAuxLights `0x102B3DAC0`

- The native vehicleController "ToggleLights" (`0x107564D9F` registration, init `0x102B3F738`, native `0x102B3EA78`)
  ends with `bl 0x102B3D974(this, w1=on, w2=type)`, the full ToggleLights.
- In `0x102B3D974`: if type bit 0 (Head = 1) is clear, it tail-calls `b 0x102B3DAC0` with the same args. Otherwise it
  handles headlights through `0x102B3C6D8` and calls `0x102B3DAC0(this, on, type & ~1)`. `0x102B3DAC0` is also called
  directly, twice, from `0x102B3CC18`. That is the "aux" (non-head) toggler.
- Upstream history backs this up. Commit `1bf1dd22` moved the hook from `ToggleLights` to `ToggleAuxLights` and dropped
  `GetLightType` (the type changes on the way down), keeping `IsLightType`.
- Body: `(x0 controller, w1 enable, w2 type)`. It reaches the light component through +0x98/+0xA0 and calls
  `0x102B41D50(comp,type)` or `0x102B41D04(comp,~type)`, then `0x102B3C244(this)`, and returns void. fmap: old
  `0x1012E6F44`. Its twin entry stub `0x102B3DABC` (`b 0x102B3DAC0`) has no callers.

## VehicleGarageComponent_LoadSummonSetup `0x102AA79A8`

- It reads 21 summon_setup flats, ".simpleSpawn" through ".replacementFreeMsgLocKey" (`0x107562252..0x10756242C`),
  from the record id at **this+0x330**. That id is seeded from "Vehicle.summon_setup" in the component ctor
  `0x102AA75D8`. It stores the results into fields from +0x33C.
- Signature `void(x0 component)`, with no other arguments read. Callers: `0x102AA87D0` and `0x102BBDE60`. fmap: old
  `0x10124FE1C` (strings 21).

## VehicleSystem_ToggleGarageVehicle `0x102BBA088`

- The native "EnablePlayerVehicle" (native `0x102BB9C80`) inlines the sequence: lock `this+0x20A50`, then
  `0x102AA9A7C([this+0x1D0][0], &GarageVehicleID, enable)`, then on success `0x102B30798(this+0xA0)`.
- `0x102BBA088` is exactly that sequence as a function: `(x0 VehicleSystem, x1 const GarageVehicleID&, w2 bool)`. It
  returns `w0=1` on success and 0 otherwise, which matches `bool(VehicleSystem*, const GarageVehicleID&, bool)`. Caller:
  `0x102AAB384`. fmap: old `0x101369A5C` (body).

## VisionModeSystem_SetBraindanceMode: NOT FOUND

- No string, native or caller ties any function to a braindance mode on VisionModeSystem. The VisionModeSystem natives
  are EnterMode, SetEntityVisionMode, and the others listed at `0x10750CDD9..`. Codeware declares the function but never
  calls it.

## VisualController_LoadDependencies `0x10199E498`: **signature change**

- The controller layout matches Codeware: dependencies at +0x10 (count `[x20,#0x1c]`, stride 0x30, mesh path at +0x20),
  lock at +0x7C, status at +0x78, job at +0x70.
- `0x10199E498` locks +0x7C and walks the dependencies. For each entry with a null token it requests one from the mesh
  path, with `x1` as the flag. It uses the profiler label "VisualControllerComponent_OnMeshLoaded" (`0x10841A208`).
- Its only caller is the job body `0x1019A067C` ("..._OnStreamingDone"): `ldrb w1,[x19,#0x10]; add x8,sp,#0x20;
  mov x0,x21; bl 0x10199E498`. It then waits on the job at sp+0x20 and sets status +0x78.
- **The arm64 signature is `JobHandle (VisualController* x0, uint8 x1)` with the JobHandle returned through x8 (sret).**
  Windows returns it through a hidden second pointer, which is where Codeware's `uintptr_t(*)(VC*, JobHandle&, uint8)`
  comes from. On macOS, that declaration would put `&jobHandle` in x1 and 0 in w2, leaving x8 as garbage, so the call
  crashes. Codeware must declare `Red::JobHandle (*)(Red::VisualController*, uint8_t)` (or pass x8 explicitly).

## WorkspotSystem_GetWorkspotInstance: NOT FOUND, **layout flag**

- The native IsActorInWorkspot (`0x10266FC28`) loads the runtime system from `gameInstance+0x40 -> +0x78 -> +0x1F0` and
  calls `0x1045E3470(sys, entityID-by-value)`.
- All 22 entity-keyed lookups in `0x104580000..0x104640000` take the EntityID **by value** in x1. None reads `[x1]`, and
  none just returns `entry+0x10`. Codeware's `(sys, const EntityID&) -> instance*` therefore has no out-of-line match. It
  is probably inlined, and Codeware never calls it anyway (WorkspotSystemEx inlines the lookup).
- **Layout:** on macOS these functions use the lock at **sys+0x4C** (`add x19,x0,#0x4c`) and the instance HashMap at
  **sys+0x68** (index table +0x68, size +0x70, capacity +0x74, nodes +0x78, stride +0x84). Codeware's `SpinLock =
  OffsetPtr<0x50>` and `InstanceMap = OffsetPtr<0x70>` do not match that. The object identity rests on the runtime-system
  slot +0x1F0, so check it against `GetRuntimeSystem<workWorkspotSystem>()` before shipping `WorkspotSystemEx::GetWorkspotInstance`.

## StatsDataSystem_InitializeParams `0x1023B29A0`

- Call position: `0x1023B4BEC bl InitializeRecords(0x1023B2F68)` (verified in batch1), then `0x1023B4BF4 bl 0x1023B29A0`.
  That is the same pair as 2.3.1 `0x103A9532C` / `0x103A95334`.
- Second caller: the locked wrapper `0x1023B2960` (locks +0xFC, clears +0xF4, calls this, then tail-calls). It mirrors
  2.3.1 `0x103A93268` -> `0x103A932A8` at `0x103A9328C`.
- Body: it reserves the array at +0xE8 with `DynArray_Realloc 0x100028674` (verified), using stride 0xC, from the record
  array at +0xD8 (`ldr x20,[x19,#0xd8]`). Offsets are unchanged. Signature `void(x0 system)`. The DB still holds the 2.3.1
  value 1:0x3A932A8 (unported).

## TweakDB_Init `0x101EF64C8` (old hash 3062572522, verified)

- It is the only ADRP target in engine init (`0x101EF5AAC`), the third of six job lambdas, which matches the 2.3.1
  evidence. Body: `(x0 captures, x1 job)` (`ldr x0,[x1,#0x20]`). It calls TweakDB_Get `0x1037CC900` (verified), then
  `0x1037CDD90(tdb, !captures[0x6a])` (new in 2.5), then `TweakDB_Get; add x2,x19,#0x48; mov w1,#1; bl TweakDB_Load`.
  This matches `void(void*, void*)`. The 2.5 rehash fits the changed body (the new 0x1037CDD90 call, and Load gaining w1).

## TweakDB_Load `0x1037CE05C` (old hash 3602585178, verified)

- Body: `mov x20,x2 (path); mov x21,x1 (flag); mov x19,x0 (tdb)`. It calls `TryLoad(tdb->+0x28, tdb, path, &ctx, x4=flag)`
  at `0x1037CE10C`, then on failure the "cache" fallback with `w4=0` at `0x1037CE128`. It bumps the generation byte at
  +0x160. This matches the new upstream `void(TweakDB*, bool, CString&)`. Callers: Init `0x101EF651C` and `0x1037CF134`.

## TweakDB_TryLoad `0x1037D60CC` (old hash 3512345737, verified)

- It uses "Binary blob not found" and "Binary blob header is not valid" (unique), as documented in port_2.5.0_plugins.md.
  Its only callers are Load's two sites. It saves `x4` and tests `cbz w20`, so it takes a 5th bool argument. This matches
  the new upstream `bool(void*, TweakDB*, CString&, void*, bool)`, and it returns bool in w0.
