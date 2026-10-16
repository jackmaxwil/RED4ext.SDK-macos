# Address rows for New Game Plus (cp2077-mac, codeman101 / skyman3215)

Game: Cyberpunk 2077 2.3.1 for macOS, the build this database names (UUID A6656ADC-FBE2-36A4-9B9D-B4A9DE645089). Offsets are
`segment:offset` as in `cyberpunk2077_addresses.json` (segment 1 = `__TEXT`, offset = image RVA; segment 3 = `__DATA`,
offset = image RVA - 0x7394000).

This is a separate document from the evidence document of PR #2, because that one is not on `main`. It covers 13 rows that our
port of New Game Plus (NG+, alphanin9's mod, with his SharedPunk library) resolves through the database and that your database does not have. None of
the 13 hashes is in `cyberpunk2077_addresses.json` on `main` (`f657158c0`).

## Names

The database carries no name field and the repository has no names file or header for these hashes, so the names below exist only
in this document (they are our names, from the NG+ port, not from the database). The rows themselves follow the file's format:
`{"hash", "offset", "verified": true}`, inserted at their place in the hash-sorted part of the file.

## How the rows were found and checked

The Windows RVA is the offset at the same hash in the Windows database of the same game version (Steam build 20383525), converted
to an image RVA. The Mac function is the twin of the Windows function at that hash (the `addr-match` tools of the cp2077-mac workspace, not public,
compare the two builds) and was read in disassembly. For the functions whose macOS registers differ from SharedPunk's prototypes, the registers were read from the Mac
body and the port calls them through its own wrappers. The checker rating of PR #2 (STRONG, OK, REVIEWED) was not run for these
13 rows, so none is given here. The two instance rows hold the address of the game's pointer to the instance.

## The rows

| hash | name | Mac offset | Mac image RVA | Windows RVA |
|---|---|---|---|---|
| 3923848734 | Telemetry LoadFactMap | 1:0x2CE34D0 | 0x2ce34d0 | 0x273a5e0 |
| 2393518559 | CharacterCustomization OnNewGame | 1:0x245733C | 0x245733c | 0xeecf40 |
| 4293661415 | GetSaveFolder | 1:0x170CFE0 | 0x170cfe0 | 0x7ebb98 |
| 836113218 | MergeDirToPath | 1:0x3449908 | 0x3449908 | 0x7eba98 |
| 1194333091 | MergeFileToPath | 1:0x344993C | 0x344993c | 0x676f6c |
| 3788966949 | RedFileManager instance (data) | 3:0x1C6F1F8 | 0x90031f8 | 0x3438978 (.data) |
| 1917464012 | OpenFileStream | 1:0x170E538 | 0x170e538 | 0x7ead50 |
| 4051576167 | FindFiles | 1:0x170EC50 | 0x170ec50 | 0x7eb1cc |
| 1617892594 | QuestsSystem::AddQuest | 1:0x2EF9D9C | 0x2ef9d9c | 0x270437c |
| 188748408 | SessionData AddArgument | 1:0x3F106C8 | 0x3f106c8 | 0x2046434 |
| 1357913210 | StartSession | 1:0x3F339B8 | 0x3f339b8 | 0x7e536c |
| 1002050525 | GameDefinition::ToWorldID | 1:0x3F2D4D0 | 0x3f2d4d0 | 0xbe0fd4 |
| 2635337807 | InkSystem instance (data) | 3:0x19C9830 | 0x8d5d830 | 0x3495c70 (.data) |

Per row: identification and runtime use. Registers are the Mac calling convention as read from the body.

1. **3923848734, Telemetry LoadFactMap** (hooked). The Telemetry function that loads the facts map; NG+ hooks it. Hook installed in the autotest run (see Runtime evidence) and in the hand test.
2. **2393518559, CharacterCustomization OnNewGame** (hooked). NG+ hooks it. Layout checked
   in the Mac body: lock 0x70, state 0x78, IsNewGame 0x200, GetLifePath 0x148. Hook installed; used in the hand test (character creation of a new NG+ run).
3. **4293661415, GetSaveFolder.** No arguments, the `CString&` result in x0. Part of the NG+ save-reading gate.
4. **836113218, MergeDirToPath.** x0 source, x1 chars, w2 length, x8 result. Save-reading gate.
5. **1194333091, MergeFileToPath.** Same registers as MergeDirToPath. Save-reading gate.
6. **3788966949, RedFileManager instance** (data, address of the pointer). Save-reading gate; the file calls below go through it.
7. **1917464012, OpenFileStream.** x1 path, w2 flags, x8 result, x0 unused. The buffered stream destructor is inlined into it on the
   Mac, so the port does not call that one. Save-reading gate.
8. **4051576167, FindFiles.** x0 this, x1 root, x2 chars, w3 length, x4 array, w5 recurse. Save-reading gate.
9. **1617892594, QuestsSystem::AddQuest** (vtable +0x1f8). Used by LoadExpansionIntoSave. The QuestsSystem mutex at +0x60 was checked
   against the game's own lock function (vtable +0x238 takes this+0x60).
10. **188748408, SessionData AddArgument.** Part of LaunchNewGamePlus. The validator warns "no STP/SUB sp prologue" (first
    instruction `mov x4, x3`), the usual leaf heuristic; the row is a function start in LC_FUNCTION_STARTS.
11. **1357913210, StartSession.** Copies the session it is given; the caller destroys its copy (the SessionData destructor is
    inlined on the Mac). Used by LaunchNewGamePlus; ran in the hand test (both start types).
12. **1002050525, GameDefinition::ToWorldID.** x0 definition, x8 result. Part of LaunchNewGamePlus.
13. **2635337807, InkSystem instance** (data, address of the pointer). Part of LaunchNewGamePlus; the requests handler's weak
    handle at +0x370 was checked against the game's own lock helper.

The functions whose Mac registers differ from SharedPunk's prototypes (3 to 5, 7, 8, 12) are called through wrappers on the
port's side.

## Runtime evidence

- Autotest scenario `ngplus_world`, 2026-10-15, NG+ built with your SDK 1.0, on your loader (`main` `cd693be` plus your loader
  PR #6 plus local trial patches), with your database plus these 13 rows: 8 of 8 checks passed. The checks: the NG+ system is
  defined; the current save is not an NG+ save; the save scan finds valid saves; the resolve picks the qualifying save among
  EndGameSave-0, EndGameSave-1 and ManualSave-197; save data loads from EndGameSave-0 (level 50, street cred 50, 70 perk points,
  225 inventory items, 6 stash items); save data loads from ManualSave-197 (level 50, 166 inventory items, 6 stash items).
  This exercises the save-reading rows (3 to 8) and the two hooks; it does not start an NG+ run.
- By hand on our private loader with the same offsets, 2026-10-14 and 2026-10-15: a New Game Plus run started from the main menu
  (both start types), character creation, LaunchNewGamePlus and StartSession, loading into the world, progression transfer;
  saved and loaded.
- Not run: LoadFactMap writing its three facts into the global map that the game filled to capacity (the insert grows the map);
  saving and loading inside an NG+ run was checked by hand only.

## Validator

`scripts/validate_addresses.py --binary <Cyberpunk2077>` (read only): 36 errors and 41 warnings before, 36 and 42 after. The one new
warning is the leaf-function heuristic on row 10. No error on a new row; the `stats` block checks out. With `--verified-only`:
0 errors before and after.

## Windows RVA column

The Windows RVAs come from the Windows database of the same build, as kept in the cp2077-mac workspace; the Windows RVA of a data
row is the `.data` section address (section base + offset).
