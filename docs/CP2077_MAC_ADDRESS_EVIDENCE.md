# Address rows from the cp2077-mac stack (codeman101 / skyman3215)

Game: Cyberpunk 2077 2.3.1 for macOS, the build this database names (UUID A6656ADC-FBE2-36A4-9B9D-B4A9DE645089). Offsets are
`segment:offset` as in `cyberpunk2077_addresses.json` (segment 1 = `__TEXT`, offset = VA - 0x100000000).

Method: every row is the Mac twin of the Windows function at that hash (Windows build 20383525 as the reference). Our checker
(`tools/addr-match/check-rows.py` in the cp2077-mac workspace) compares the two bodies: function starts (LC_FUNCTION_STARTS and .pdata),
shared string literals, shared struct field offsets, call counts and sizes. Ratings: STRONG (shared strings, or most offsets shared), OK
(some evidence), REVIEWED (a weak heuristic rating with a hand-written reason). The rows below are the ones our plugins resolve through the
database and that run in game in our stack (in-world test passes on this loader, see the PR text).

`scripts/validate_addresses.py --binary <Cyberpunk2077>` on this file (rebased on main f657158c0): 36 errors and 41 warnings before
this change, 30 errors and 38 warnings after. No error is on a row this change touches; three warnings are, all the validator's leaf-function heuristic ("no STP/SUB
sp prologue"): the two 16-byte mappin getter stubs (`ldr` first) and IPlacedComponent_SetTransform (`mov` first). 6 errors of the old
entries go away: shared addresses at 0xD4DC20 and 0x36FE44C, and four entries that were not function starts. With `--verified-only`:
0 errors before and after.

## 1. Five verified rows that point at another function than the Windows twin

From a read-only disassembly comparison of both Mac stacks against the Windows build (decision rule: the right Mac row is the Mac twin of the
Windows function at that hash).

| hash | name | before | after | why |
|---|---|---|---|---|
| 809178766 | GarmentAssembler_ExtractComponentsJob | 1:0xAE6348 | 1:0xAE6660 | 0xAE6348 is stage 1 ('ProcessLoadedAppearanceParts'), 0xAE6660 is stage 2 ('ExtractGarmentComponent'), the twin of the Windows job; both free their own closure (see the ArchiveXL PR) |
| 3299551353 | MappinSystem_GetMappinData | 1:0x42A3E38 | 1:0x42A3E68 | by hash identity: Windows 0x9067A0 reads this+0x68; the two names were crossed; neither stack hooks these stubs |
| 620961393 | MappinSystem_GetPoiData | 1:0x42A3E68 | 1:0x42A3E38 | the mirror of the row above |
| 797843833 | QuestRootInstance_Start | 1:0x2D01878 | 1:0x2D00870 | Windows has two Start functions; 0x2D01878 is the non-virtual bool one called only from the bulk start job, so a hook there misses the "Started new quest" path |
| 3224838039 | AttachmentSlots_InitializeSlots | 1:0x3508DB0 | 1:0x3508DF8 | 0x3508DB0 is the lock wrapper around the function |

One row went the other way and is not changed here: `CString_copy` 1:0x2AACC (yours) is right; ours was the copy constructor.

Two more verified rows name an inner function rather than the Windows twin, and stay as they are, because ArchiveXL on macOS hooks
them with the signature of the function they point at today:

| hash | name | row (kept) | Windows twin on the Mac | why it stays |
|---|---|---|---|---|
| 709304039 | GarmentAssembler_OnGameDetach | 1:0x36F6F4C | 1:0x371FE6C, `void(this, a2)`, called only from the entity appearance system's detach virtual | 0x36F6F4C is its callee that clears the per-entity states; ArchiveXL's macOS declaration is `void(uintptr_t)`, which fits the callee |
| 1945256833 | JournalRootFolderEntry_Initialize | 1:0x1E7528C | 1:0x1E75A24, the virtual `(this, a2, a3, JobQueue&)` that calls 0x1E7528C and tail-branches to 0x1E75660, as Windows 0x950620 calls 0x9507FC and jumps to 0x950660 | ArchiveXL's macOS declaration `(root, handle&, JobQueue&)` fits the inner function; the virtual takes a fourth argument (the JobQueue, x3) that this declaration does not forward; tried with the row on the virtual: a crash in the job system called from 0x1E75A48 at session start |

Moving either row needs the matching ArchiveXL signature change in the same release. In the cp2077-mac port both hooks sit on the
Windows twins with the Windows signatures and pass the in-world tests.

## 2. Twenty-seven unverified rows, verified with our offsets

| hash | name | our offset | verdict | his entry before | needed by | Windows RVA |
|---|---|---|---|---|---|---|
| 68817558 | CEnum_ToString | 1:0x21A3BC0 | OK | 1:0x2214898 (unverified) | ArchiveXL,Codeware | 0x599BFC |
| 422530722 | UpdateRegistrar_RegisterBucketUpdate | 1:0x3D95924 | OK | 1:0x2000100 (unverified) | ArchiveXL,Codeware | 0x62575C |
| 489494088 | EntityBuilder_ExtractComponentsJob | 1:0xCA41E0 | OK | 1:0xD4DC20 (unverified) | ArchiveXL,Codeware | 0x1CD4A8 |
| 566894273 | CEnum_FromString | 1:0x21A3D4C | OK | 1:0x21B13AC (unverified) | ArchiveXL,Codeware | 0x75DF94 |
| 633871992 | MorphTargetManager_ApplyMorphTarget | 1:0xC6C0C4 | OK | 1:0x1C5226C (unverified) | ArchiveXL,Codeware | 0x1607FC |
| 787099588 | CharacterCustomizationSystem_EnsureState | 1:0x2456C9C | OK | 1:0x2F2D360 (unverified) | ArchiveXL | 0xEED694 |
| 898639042 | ScriptValidator_Validate | 1:0x21FBF90 | OK | 1:0x3D96BF4 (unverified) | Codeware | 0x3CCBA0 |
| 956641309 | GarmentAssemblerState_ChangeCustomItem | 1:0x36F89A4 | STRONG | 1:0x36FE44C (unverified) | ArchiveXL | 0xB56A1C |
| 1087575974 | CEnum_Unserialize | 1:0x21A39B0 | OK | 1:0x2213FD4 (unverified) | ArchiveXL,Codeware | 0x1487A4 |
| 1303056161 | ResourceLoader_OnUpdate | 1:0x21B5548 | OK | 1:0x2D9766C (unverified) | ArchiveXL | 0x270ACC |
| 1411585028 | CBitfield_ToString | 1:0x2196930 | OK | 1:0x21E9C58 (unverified) | ArchiveXL,Codeware | 0x2076F18 |
| 1693194103 | InkWorldLayer_UpdateComponents | 1:0x491DDB0 | OK | 1:0x3DA0574 (unverified) | ArchiveXL | 0x29EEBC |
| 1828854026 | IPlacedComponent_SetTransform | 1:0xC417F0 | OK | 1:0x1443324 (unverified) | ArchiveXL,Codeware | 0x574FC8 |
| 2182550867 | Entity_Assemble | 1:0xC97E28 | STRONG | 1:0xCCEDEC (unverified) | ArchiveXL,Codeware | 0x8AB708 |
| 2263681375 | Entity_Detach | 1:0xC996C0 | OK | 1:0x15EDE88 (unverified) | ArchiveXL,Codeware | 0x1B3A1C |
| 2296260874 | Entity_RequestComponents | 1:0xC95E24 | OK | 1:0xD4DC20 (unverified) | ArchiveXL,Codeware | 0x8B116C |
| 2347184335 | CharacterCustomizationGenitalsController_CheckState | 1:0x2440814 | OK | 1:0x2DEAC58 (unverified) | ArchiveXL | 0x8586B4 |
| 2349406410 | ResourceToken_Fetch | 1:0x21C4D4C | REVIEWED | 1:0x12F06B0 (unverified) | ArchiveXL,Codeware | 0x261F24 |
| 2515274237 | Entity_Dispose | 1:0xC999E0 | OK | 1:0xCF5E98 (unverified) | ArchiveXL,Codeware | 0x8B5540 |
| 2694518184 | CBitfield_FromString | 1:0x2196A2C | OK | 1:0x21FC47C (unverified) | ArchiveXL,Codeware | 0x2076E00 |
| 2794985748 | CBitfield_Unserialize | 1:0x21967A0 | REVIEWED | 1:0x21F7FC0 (unverified) | ArchiveXL,Codeware | 0x33B6C0 |
| 3121353053 | Handle_ctor | 1:0x2104788 | OK | 1:0x243C88 (unverified) | ArchiveXL,Codeware,TweakXL | 0x1456C0 |
| 3490519617 | Entity_Initialize | 1:0xC985EC | OK | 1:0x3641A50 (unverified) | ArchiveXL,Codeware | 0x8B0190 |
| 3596356635 | Entity_Uninitialize | 1:0xC992C4 | OK | 1:0xCC45EC (unverified) | ArchiveXL,Codeware | 0x402F74 |
| 3740082313 | GarmentAssemblerState_ChangeItem | 1:0x36F887C | STRONG | 1:0x36FE44C (unverified) | ArchiveXL | 0xB57FD8 |
| 4248638169 | Entity_Attach | 1:0xC99368 | OK | 1:0x180C9D8 (unverified) | ArchiveXL,Codeware | 0x1CDBB0 |
| 4254156293 | UpdateRegistrar_RegisterGroupUpdate | 1:0x3D95800 | OK | 1:0x1FFFF8C (unverified) | ArchiveXL,Codeware | 0x624D54 |

Checker detail per row:

- `CEnum_ToString` 1:0x21A3BC0 OK: offsets:1/6~17%, calls w6 m7, size w137 m396
- `UpdateRegistrar_RegisterBucketUpdate` 1:0x3D95924 OK: offsets:3/8~38%, calls w7 m7, size w333 m304
- `EntityBuilder_ExtractComponentsJob` 1:0xCA41E0 OK: offsets:16/35~46%, calls w49 m159, size w1800 m4632
- `CEnum_FromString` 1:0x21A3D4C OK: offsets:1/6~17%, calls w2 m1, size w79 m528
- `MorphTargetManager_ApplyMorphTarget` 1:0xC6C0C4 OK: offsets:1/11~9%, calls w4 m11, size w201 m972
- `CharacterCustomizationSystem_EnsureState` 1:0x2456C9C OK: offsets:1/15~7%, calls w7 m82, size w173 m1696
- `ScriptValidator_Validate` 1:0x21FBF90 OK: offsets:1/6~17%, calls w10 m19, size w302 m532
- `GarmentAssemblerState_ChangeCustomItem` 1:0x36F89A4 STRONG: offsets:2/4~50%, calls w4 m4, size w164 m144
- `CEnum_Unserialize` 1:0x21A39B0 OK: offsets:1/7~14%, calls w5 m2, size w186 m528
- `ResourceLoader_OnUpdate` 1:0x21B5548 OK: offsets:3/21~14%, calls w11 m37, size w365 m1164
- `CBitfield_ToString` 1:0x2196930 OK: offsets:1/2~50%, calls w6 m5, size w192 m252
- `InkWorldLayer_UpdateComponents` 1:0x491DDB0 OK: offsets:2/5~40%, calls w7 m14, size w205 m500
- `IPlacedComponent_SetTransform` 1:0xC417F0 OK: offsets:4/13~31%, calls w2 m0, size w198 m204
- `Entity_Assemble` 1:0xC97E28 STRONG: offsets:5/9~56%, calls w6 m7, size w162 m176
- `Entity_Detach` 1:0xC996C0 OK: offsets:3/20~15%, calls w5 m11, size w192 m320
- `Entity_RequestComponents` 1:0xC95E24 OK: offsets:1/4~25%, calls w2 m2, size w85 m88
- `CharacterCustomizationGenitalsController_CheckState` 1:0x2440814 OK: offsets:4/30~13%, calls w33 m39, size w1132 m1676
- `ResourceToken_Fetch` 1:0x21C4D4C REVIEWED: ResourceToken_Fetch: the IsFinished test and the add x0,x19,#0x28 return match Windows 0x261f24; Mac 312 bytes against 85 because the waiting path is inlined; the SDK calls it as a direct function [heuristic: WEAK offsets:0/7~0%, calls w3 m9, size w85 m312]
- `Entity_Dispose` 1:0xC999E0 OK: offsets:3/7~43%, calls w4 m7, size w96 m208
- `CBitfield_FromString` 1:0x2196A2C OK: offsets:1/6~17%, calls w9 m11, size w278 m508
- `CBitfield_Unserialize` 1:0x21967A0 REVIEWED: CBitfield_Unserialize: Windows 144 bytes, Mac 400 bytes (stream reads inlined); the reflect matcher found it in the CBitfield vtable (Mac 0x6FFBEC8, slot 0x68 = Windows 0x60 + 8) next to CBitfield_ToString and FromString, and it is the exact twin of the CEnum_Unserialize shape; not run live (no bitfield is deserialized in a boot) [heuristic: WEAK offsets:0/3~0%, calls w2 m4, size w144 m400]
- `Handle_ctor` 1:0x2104788 OK: offsets:1/4~25%, calls w1 m8, size w262 m312
- `Entity_Initialize` 1:0xC985EC OK: offsets:21/75~28%, calls w34 m111, size w994 m3028
- `Entity_Uninitialize` 1:0xC992C4 OK: offsets:2/10~20%, calls w7 m6, size w225 m160
- `GarmentAssemblerState_ChangeItem` 1:0x36F887C STRONG: offsets:2/3~67%, calls w4 m4, size w163 m144
- `Entity_Attach` 1:0xC99368 OK: offsets:7/20~35%, calls w8 m16, size w336 m508
- `UpdateRegistrar_RegisterGroupUpdate` 1:0x3D95800 OK: offsets:3/8~38%, calls w8 m7, size w332 m292

## 3. One macOS-only row

| hash | name | offset | why |
|---|---|---|---|
| 3235778566 (0xC0DE1006, synthetic) | AppearanceNameVisualTagsPreset_GetVisualTagsByRecord | 1:0x3CD7118 | the record-based visual tags entry. Windows 0x3F12F0 is a 68-byte wrapper that tail-jumps into GetVisualTags 0x3F1334; the Mac twin 0x3CD7118 (284 bytes) inlines the map find and branches into the shared value method 0x3CD2F60 (the twin of Windows 0x3F1380) without calling GetVisualTags 0x3CD7234. Both wrappers resolve the flat of the record field first (Windows `lea rcx,[rdx+0xE8]; call 0x3F1CAC`, Mac `add x0,x1,#0xE4; bl 0x9C8520`). Needed by the ArchiveXL PR's record hook; there is no Windows hash, so the id is synthetic |
