# charcustom: CharacterCustomization hooks (macOS 2.3.1 arm64)

All 17 old DB values are wrong (none are the named function). Addresses below are absolute; DB form is `1:<abs-0x100000000>`. Every new address is an LC_FUNCTION_STARTS entry, and its first four instructions are non-PC-relative prologue (sub/stp/add/mov), so a 16-byte patch is safe.

| name | hash | old | new seg:off (absolute) | verdict | arm64 signature vs plugin declaration |
|---|---|---|---|---|---|
| CharacterCustomizationFeetController_CheckState | 3015323410 | 1:0x423DE2C | 1:0x24436D0 (0x1024436D0) | confirmed | `void(this, u32* lifted, u32* flat)`: matches |
| CharacterCustomizationGenitalsController_OnAttach | 1782982010 | 1:0x2DEAC58 | 1:0x2440418 (0x102440418) | confirmed | `void(this, x1)`: plugin omits x1; harmless for HookBefore |
| CharacterCustomizationHairstyleController_CheckState | 2652844338 | 1:0x2DEBB90 | 1:0x2442D8C (0x102442D8C) | confirmed | `void(this, u32* hairState)`: matches |
| CharacterCustomizationHairstyleController_OnDetach | 2249860539 | 1:0x2DEBB90 | 1:0x24415C0 (0x1024415C0) | confirmed (shared body, see note) | `void(this, x1)`: matches |
| CharacterCustomizationHelper_GetHairColor | 3414699684 | 1:0x1441630 | none: inlined | refuted (no out-of-line function exists) | plugin calls it, so it must be reimplemented (see evidence) |
| CharacterCustomizationState_GetArmsAppearances1 | 110771572 | 1:0x4357924 | 1:0x2451F2C (0x102451F2C) | confirmed (1/2 order: likely) | `bool(this, CName, bool fpp, DynArray<AppearanceDescriptor>*)`: plugin says void |
| CharacterCustomizationState_GetArmsAppearances2 | 4059182261 | 1:0x4357924 | 1:0x2452144 (0x102452144) | confirmed (1/2 order: likely) | same: returns bool |
| CharacterCustomizationState_GetBodyAppearances1 | 4014159024 | 1:0x204218 | 1:0x2451AFC (0x102451AFC) | confirmed (1/2 order: likely) | same: returns bool |
| CharacterCustomizationState_GetBodyAppearances2 | 56573295 | 1:0x204218 | 1:0x2451D14 (0x102451D14) | confirmed (1/2 order: likely) | same: returns bool |
| CharacterCustomizationState_GetHeadAppearances1 | 4051123539 | 1:0x28B94DC | 1:0x2451620 (0x102451620) | confirmed (1/2 order: likely) | same: returns bool |
| CharacterCustomizationState_GetHeadAppearances2 | 3766105236 | 1:0x28B94DC | 1:0x24518E4 (0x1024518E4) | confirmed (1/2 order: likely) | same: returns bool |
| CharacterCustomizationSystem_GetResource | 4275058446 | 1:0x21AC670 | 1:0x2459710 (0x102459710) | confirmed identity, but it has **0 callers** | `Handle<InfoResource> (this, bool isMale)`, with the result written through x8. Plugin declares `(this, SharedPtr&, bool)`, so x1/w2 are misread |
| CharacterCustomizationSystem_Initialize | 2341291776 | 1:0x3F20314 | 1:0x24593DC (0x1024593DC) | confirmed | `void(this, Handle<Puppet>*, bool isMale, Functor* cb)`: matches |
| CharacterCustomizationSystem_InitializeAppOption | 1092645213 | 1:0x1E3F8F4 | 1:0x2464ED4 (0x102464ED4) | confirmed | `(this, part, Handle<Option>*, X* stateOpts, Map* uiSlots)`: **container X is a red::Map, not a SortedUniqueArray** |
| CharacterCustomizationSystem_InitializeMorphOption | 3776734053 | 1:0x1E3F8F4 | 1:0x24652D8 (0x1024652D8) | confirmed | `(this, Handle<Option>*, X* stateOpts, Map* uiSlots)`: same container mismatch |
| CharacterCustomizationSystem_InitializeSwitcherOption | 2229107513 | 1:0x1E3F8F4 | 1:0x24661A0 (0x1024661A0) | confirmed | `bool(this, part, Handle<Option>*, i32 idx, u64, Map*)`: matches; always returns 1 |
| CharacterCustomizationSystem_Uninitialize | 402202441 | 1:0x3F98478 | 1:0x2459F78 (0x102459F78) | confirmed | `void(this)`: matches |

## Anchors
- RTTI type statics, found through the GetNativeType getters next to each class-name string:
  - gameuiCharacterCustomizationSystem `0x1090CC840`; vtable `0x10702CFB0` (slot 0 = `0x10244D930`).
  - gameuiCharacterCustomizationState `0x1090CC838`; vtable `0x10702CD58`.
  - gameuiCharacterCustomizationOption: vtable `0x10702CC08`. Its slots `+0x110`/`+0x118`/`+0x120` = GetMorphInfo/GetAppearanceInfo/GetSwitcherInfo (`0x10244F090`/`0x10244F13C`/`0x10244F1E8`). Each IsA-checks gameuiMorphInfo/AppearanceInfo/SwitcherInfo (type statics `0x10900A5D8`/`5E8`/`5F8`).
  - Hairstyle/Feet/Genitals controllers: type statics `0x1090CC778`/`780`/`768`; vtables `0x1070293C8`/`0x107029698`/`0x107029100`.
- Script natives of ICharacterCustomizationSystem (registration `0x101FEA4E8`) pin the slots: InitializeState `+0x1C8`, FinalizeState `+0x1D0`, ReFinalizeState `+0x1D8`, CancelFinalizedStateUpdate `+0x1E8`, InitializeOptionsFromFinalizedState `+0x238` (`0x10245F9AC`).
- Base entIComponent vtable slots (e.g. vtable `0x106EB0778`, used by 29 vtables at `+0x188`):
  - `+0x188` = `0x100CA627C`: sets attached bit 1 at `+0x88`. This is **OnAttach**.
  - `+0x198` = `0x100CA62AC`: clears bit 1 and sets bit 3. This is **OnDetach**.

## Evidence

**Initialize `0x1024593DC`** is system vtable slot `+0x240`.
- It takes x1/x2/x3. `isMale` selects the resource token at `+0x48` (male) or `+0x58` (female); `csel` sits at `0x102459500`.
- It stores the resource handle at `+0xA0` and the callback functor at `+0x238`/`+0x258`, and sets `+0x230=1`.
- x1 is the puppet. The sub-inits `0x1024597A4`/`8C4`/`AC8` look up `AttachmentSlots.TppHead` on it.
- It then builds the UI option lists for parts 0, 1 and 2 (`0x102459BE8`).
- Caller: gameuiCharacterCreationPuppetPreviewGameController (vtable `0x10701FB48`, class string `0x106CCDE60`). It calls `sys->vtbl[0x240](sys, puppet, puppet->vtbl[0x128]() /*isMale*/, &functor)` at `0x1023E3168` and `0x1023E350C`.

**Uninitialize `0x102459F78`** is system vtable slot `+0x248`, the next slot after Initialize.
- It takes the same `+0x98` lock as Initialize.
- It calls `0x102459FBC`, which tears down puppet-side listeners, then `0x102455940(this, true)`. That function clears the `+0xA0` resource handle and the option arrays and resets per-part state.
- Caller: the same preview controller's teardown slot `0x1023E35BC` (vtable `+0x130`). It fetches the system via the ICharacterCustomizationSystem type getter `0x101FEA4D0` and calls `vtbl[0x248]()` on it only.

**GetResource `0x102459710`.**
- Body: `csel(isMale ? 0x48 : 0x58)`, then `token->Get` (`0x1021C4D44`), then IsA CharacterCustomizationInfoResource. It copies the 16-byte Handle to `[x8]`.
- It has **no B/BL, ADR/ADRP or fixup references at all**. The same body is inlined at `0x1024594FC` (Initialize), `0x102456CD4` (`0x102456C9C`) and `0x10245F404` (system slot `+0x2C0`).
- A hook here never fires.

**InitializeAppOption / Morph / Switcher.** All three are called only from the per-part dispatcher `0x1024644AC(this, part, stateA, stateB)`. The dispatcher's callers are InitializeOptionsFromFinalizedState (`0x10245F9AC`) and `0x102456C9C`, three calls each, one per part.
- For each UI option:
  - If `opt->GetAppearanceInfo()` is non-null, it calls `0x102464ED4(this, part, &opt, stateA, &uiMap)` (`0x102464598`).
  - Otherwise, if `GetMorphInfo()` is non-null, it calls `0x1024652D8(this, &opt, stateB, &uiMap)` (`0x1024655CC`).
- The switcher pass calls `0x1024661A0(this, part, &entry.opt, entry.idx, optList, &uiMap)` (`0x10246496C`, `0x102464A88`, and recursively `0x102466354`).
- App and morph both look up `info+0x40` (name) in the state container and write `opt+0x5C` (isActive).
- Switcher sets `opt+0x5C` and calls `opt->vtbl[0x128](idx)`, then returns `w0=1`.

**Get{Head,Body,Arms}Appearances 1/2** are state vtable slots `+0x198`/`+0x1A0`/`+0x1A8` and `+0x1B0`/`+0x1B8`/`+0x1C0`.
- Bodies: remap the group via `+0xA0` (`{name, tpp, fpp}` × 0x18), search the group array at `+0x70`/`+0x80`/`+0x90` (0x28-byte entries), and append 16-byte descriptors to `DynArray* x3`. They return w0 (1 = found).
- The pairs are **byte-identical bodies** (diffed `0x102451620` against `0x1024518E4`). Which one is "1" and which "2" cannot be told from code. I assigned the first triple as 1. Both get the same ArchiveXL callback, so the assignment does not change behavior.

**HairstyleController_CheckState `0x102442D8C`.**
- It is the hair-only vtable slot `+0x2B8`; only the hairstyle vtable at `0x107029680` references it, and the hair vtable is one slot longer than the other two.
- The head-part base update `0x10244252C` (`+0x2A0`) calls `vtbl[0x2B8](this, &state)` and then applies the state.
- The body starts with `str wzr,[x1]` and then computes the state.

**FeetController_CheckState `0x1024436D0`.**
- It zeroes `*x1` and `*x2`, then queries the transaction system (`vtbl+0x448` with a lambda). It sets `lifted = found ? 2 : 1` and `flat = found ? 1 : 2`.
- Its only caller is the feet update slot `0x102443618` (`+0x2A0`), which applies `lifted` to `+0xB8`/`+0xC8` and `flat` to `+0xC0`/`+0x118`.

**GenitalsController_OnAttach `0x102440418`.** It is genitals vtable slot `+0x188`; no other vtable overrides that slot with it. It tail-calls either the controller base OnAttach `0x10243E768` or IComponent `0x100CA627C`, depending on the global at `0x10900B230`.

**HairstyleController_OnDetach `0x1024415C0`** is hair vtable slot `+0x198`, the OnDetach slot. The **same function** sits in the HeadParts, Beard and Face controller vtables, as an inherited head-controller override. PuppetState's `OnDetachPuppet` uses only `owner`, so firing for those classes is idempotent and harmless.

**GetHairColor: no standalone function exists.**
- The hair-colour logic is inlined into `0x1037349E0`. Its callers are at `0x1036FDF64` (in function `0x1036FDDD4`) and `0x103704A38` (in function `0x10370485C`).
- What the inlined code does:
  1. `state = sys->vtbl[0x1F8](isMale)`. That is system `0x102458ECC` = GetState(isMale), returning a Handle via x8, or null if the gender differs.
  2. It then iterates the TweakDB flat `ItemFactory.HairColors.hairColors` (string `0x106D5F209`, the only reference to it).
  3. It returns the first name for which `state->vtbl[0x240](name)` is true. That is state `0x1024536D4` = HasOption(CName), which scans `+0xB0`.
- Nothing else in the binary references that string, an ADR to it, or its TweakDBID (`0x21E300C961`).

## Dangerous / must-fix in the plugin
1. **GetHairColor**: `Garment/Dynamic.cpp:652` calls it unconditionally. With the hash unresolved (fail-closed), that call jumps to pc 0. Reimplement the three steps above in the plugin, or guard the call.
2. **InitializeApp/MorphOption state container layout**: on macOS, x3 (app) and x2 (morph) point to a `red::Map<CName, 8-byte>`.
   - Layout: keys DynArray at `+0`, values DynArray at `+0x10`, flags at `+0x20` with bit 0 = NotSorted. The builder is `0x102463CB8`; keys come from `entry+0x10` and values from `entry+0x20`.
   - The plugin's `SortedUniqueArray<CName>::Emplace` writes flags at `+0x10`, which is `values.entries`, and grows keys without values. **That corrupts memory.** Use `Red::Map<CName, CName/uint64>` and insert a key and value together.
3. **GetResource never executes.** `OnPrepareResource` → `MergeCustomEntries` will never run, so custom customization entries silently never merge. Move the merge into the Initialize HookBefore. Initialize reads `+0x48`/`+0x58` itself, and so do `0x102456C9C` and slot `+0x2C0` (`0x10245F3C4`).
4. **State Get*Appearances return bool.** HookAfter wrappers declared `void` must preserve w0. Otherwise the caller sees a clobbered "found" result.
