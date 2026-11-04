# 2.5.0 macOS port: Codeware addresses (batch 8)

Static analysis of the 2.5.0 binary (UUID 7D7382D0-EADD-36F0-BA1C-CEBEC1D5BEBC). Nothing was launched. The main session spot-checked the CEnum (0x107831578) and IType (0x107833200) vtable slots, the job-descriptor strings and the Entity_Assemble body. CEnum_FromString is published together with the SDK func_t fix (StringView by value).


| hash | name | new address (vmaddr) | DB offset (seg:0xOFF) | FOUND/NOT FOUND | signature same? |
| --- | --- | --- | --- | --- | --- |
| 68817558 | CEnum_ToString | 0x1010CF304 | 1:0x10CF304 | FOUND | yes: `bool(CEnum* x0, const void* x1, CString& x2)` |
| 364779332 | CBaseRTTIType_sub_88 | 0x1010DBE68 | 1:0x10DBE68 | FOUND | yes: `bool(IType* x0, a1 x1, inst x2)` |
| 566894273 | CEnum_FromString | 0x1010CF45C | 1:0x10CF45C | FOUND, **held out of JSON** | same as 2.3.1, but **the SDK func_t is wrong**: the game takes a StringView by value (x2 = ptr, x3 = len), not `const CString&` |
| 1087575974 | CEnum_Unserialize | 0x1010CF100 | 1:0x10CF100 | FOUND | yes: `bool(CEnum* x0, BaseStream* x1, void* x2, int64 x3)` (x3 unused) |
| 2396396482 | CBaseRTTIType_sub_A0 | 0x1010DC240 | 1:0x10DC240 | FOUND | yes. It reads only x0 and x1; x2/x3 (`CString&`, `bool*`) are unused |
| 2757309857 | CBaseRTTIType_sub_90 | 0x1010DBF30 | 1:0x10DBF30 | FOUND | yes: x0..x4 used |
| 2930319133 | CBaseRTTIType_sub_98 | 0x1010DC0DC | 1:0x10DC0DC | FOUND | yes: x0..x4 used (x4 is dereferenced `ldr w8,[x4]`, as in 2.3.1); w5 unused |
| 3832485534 | CBaseRTTIType_sub_80 | 0x1010DBDA8 | 1:0x10DBDA8 | FOUND | yes: `bool(IType* x0, a1 x1, inst x2)` |
| 4007601841 | CGameFramework_InitializeGameInstance | 0x101578050 | 1:0x1578050 | FOUND | yes: `void(closure* x0, jobctx* x1)` |
| 2182550867 | Entity_Assemble | 0x1019AA048 | 1:0x19AA048 | FOUND | args yes `(Entity* x0, AssembleParams* x1)`. Return: **void**. w0 is not set, and both callers ignore it |
| 2601784524 | ISerializable_Clone | - | - | NOT FOUND | - |

Re-check helpers are in `re2/b8/`. `find.py new|old OFF=TARGET...` votes on vtable slots over all vtables that match the given slot values. `dump.py new|old VT` prints the vtable slots (and the fmap entry for old). `asm_scan.py new|old` runs the Entity_Assemble field-copy scan over every function start.

## CEnum vtable (group 1 anchor)
- **2.3.1 CEnum vtable 0x106FFC2B8** (archivexl_port.md) has GetType +0x28 = 0x1007D3EF0 `mov w0,#5; ret`.
- **2.5.0 CEnum vtable 0x107831578.** Its GetType +0x28 is 0x100B4F7FC, `mov w0,#5; ret` (Enum).
  - The CEnum ctor 0x1010CEB90 stores this vtable: `adrp/add x8,0x107831578; str x8,[x0]`, then name at +0x10, actualSize at +0x20 and flags at +0x21. That matches the `CEnum(CName, int8, Flags)` layout.
  - Its sibling 0x107831188 has GetType 13 (CBitfield). The same pair exists in 2.3.1: 0x106FFC2B8 and 0x106FFBEC8, both with GetName 0x10030F8DC → 0x10089BA4C.
- **Only one CEnum vtable exists.** CEnum is not templated, so each of the slot values Unserialize/ToString/FromString occurs exactly once in the rebase fixups, in both builds. The "many vtables" premise does not hold for CEnum.

## CEnum_Unserialize 0x1010CF100, ToString 0x1010CF304, FromString 0x1010CF45C
- **Evidence 1, vtable slot.** The CEnum vtable holds them at +0x68, +0x70 and +0x78 (SDK 0x60/0x68/0x70 + 8), in the same positions as 2.3.1's 0x1021A39B0, 0x1021A3BC0 and 0x1021A3D4C.
- **Evidence 2, the bodies match 2.3.1** (`re2/b8/{o,n}_{unser,tostr,from}.s`). The prologues are the same, and so are the field offsets:
  - actualSize `ldrb [x0,#0x20]` (a jump table in 2.3.1, a compare chain in 2.5.0);
  - hashList count `[+0x34]`, valueList `[+0x38]` and hashList `[+0x28]`;
  - Unserialize tests the stream flag `ldrb [x1,#8]; tbnz #1`.

  CEnum field offsets are unchanged.
- **FromString ABI.** Both builds start with `stp x2,x3,[sp]; mov x0,sp; mov w1,#'.'`, then compare against "None" (`cmp w8,#0x4e`).
  - Caller 0x101DD0CE0 passes `x2 = c_str()` and `w3 = length`.
  - So arg 2 is a StringView passed by value. The SDK's `bool(const CEnum*, void*, const CString&)` func_t is wrong on macOS.
  - The address is correct. It is held out of the JSON until the SDK fixes the wrapper (StringView{ptr,len}), as archivexl_port.md already required for 2.3.1.

## CBaseRTTIType_sub_80/88/90/98/A0 = 0x1010DBDA8 / 0x1010DBE68 / 0x1010DBF30 / 0x1010DC0DC / 0x1010DC240
- **Evidence 1, the base vtable.** The 2.5.0 abstract IType vtable is 0x107833200, the only vtable with `__cxa_pure_virtual` at +0x10..+0x28 and the ported +0x88. Its shape matches 2.3.1's 0x106FFDF40 slot for slot.
  - +0x88/+0x90/+0x98/+0xA0/+0xA8 hold these five values.
  - The same values sit in CEnum 0x107831578 and CBitfield 0x107831188.
- **Evidence 1b, the slot vote** (`find.py new 0x88=0x1010dbda8`).
  - 34 RTTI vtables carry the base sub_80. The counts per slot are +0x88 34/34, +0x90 34/34, +0x98 20/34, +0xA0 12/34 and +0xA8 34/34.
  - 2.3.1 has exactly the same counts (34; 34/34/20/12/34) with 0x1021AFD4C/E0C/ED4/B007C/B01E0.
  - These are the non-overriding values. They are not the CClass overrides (0x1010C5B40 etc.).
- **Evidence 2, bodies are opcode-identical to 2.3.1** (`re2/b8/{ob,nb}{0..4}.s`).
  - sub_80, sub_88, sub_98 and sub_A0 have 0 opcode differences.
  - sub_90 differs only by a 16-byte copy (`ldp/stp` became `ldr q0/str q0`) and the GOT offset.
  - sub_A0 references the unique string "Type does not contain any properties" (0x1074D7632; 2.3.1 0x106CC3871). It tail-calls `a1->vt[+0x10](a1, this, str)`.
  - sub_80 calls `this->vt[+0x70]` (ToString). sub_88 calls `a1->vt[+0x60]`.
- **The independent fmap agrees:** 0x1021AFD4C→0x1010DBDA8, …, 0x1021B01E0→0x1010DC240.

## CGameFramework_InitializeGameInstance 0x101578050 (twin decided)
- **Evidence 1** is from batch3: the shape of Codeware's Windows pattern (TLS job scope from `[x1+0x20]`, then closure field 0).
- **Evidence 2, the job-descriptor name string.** The framework init is 0x101577BA8.
  - It builds a job from lambda 0x101578050 (`adrp/add` at 0x101577C88) with descriptor 0x108323170 (0x101577CC4..CCC).
  - The static initializer 0x101578388 names that descriptor `"CGameFramework/GameInstance"` (0x1074FF4F1).
  - The twin 0x1015780D4 (0x101577D04) uses descriptor 0x1083231B0. Initializer 0x1015783C0 names it `"CGameFramework/RuntimeScene"` (0x1074FF50D).
  - A third descriptor is "CGameFramework/StateMachine" (lambda 0x101578150).
- **Evidence 3, body.** 0x101578050 loads `framework+0x10` (GameInstance) and makes a virtual call through `vt+0x28`. The twin loads `+0x18` (RuntimeScene) and calls 0x101BC4D44 directly.

## Entity_Assemble 0x1019AA048
- **Evidence 1, the Windows pattern from Codeware history (commit 4070e2a2, `Entity_OnAssemble`).** The pattern is `mov rax,[rdx]; mov [rcx+60h],rax; mov rax,[rdx+8]; mov [rcx+50h],rax; …`.
  - A scan of all 433k function starts finds exactly one 2.5.0 function that copies `[x1]→[x0+0x60]` and `[x1+8]→[x0+0x50]`: 0x1019AA048.
  - Its body is `ldr x8,[x1]; str x8,[x0,#0x60]; ldr x8,[x1,#8]; str x8,[x0,#0x50]; ldr x8,[x1,#0x10]; str x8,[x0,#0x58]`.
  - It then copies tags into `this+0x138` from `params+0x60`, calls `this->vt[+0x1B8](this, params, params+0x20)`, and fills the components storage at `this+0x70`.
  - Those offsets match Codeware Entity.hpp: AppearanceName 0x50, TemplatePath 0x60, ComponentsStorage 0x70, VisualTags 0x138.
  - In 2.3.1 the same scan also has one unique hit, 0x100C97E28.
- **Evidence 2, call graph.** The fmap independently maps 0x100C97E28 → 0x1019AA048 ("callee set").
  - 2.3.1 caller 0x100CA14B8 maps to 0x1019B48D4, which calls 0x1019AA048 at 0x1019B4C14.
  - The second caller is 0x1019BF62C (call at 0x1019BF784).
- **Signature.** The arguments are `(Entity* x0, params* x1)`, the same as Codeware's `(Entity*, uintptr_t)`.
  - The function is void: it ends with `ret` and does not set w0.
  - Both callers ignore x0 (the next instructions are `ldr x8,[x20,#0xb8]` and `mov x0,sp`).
  - Codeware's `bool` return type is harmless under HookAfter. Nothing should read the result.

## ISerializable_Clone: NOT FOUND
- **No Windows pattern exists.** Codeware added the hash after it moved to the address library (commit 793f00f0), so there is no Windows pattern or address comment.
- **No string or symbol anchor.**
  - The only "Clone" strings are memory-pool names ("BufferClone", "DynamicBufferClone") and "OnClone".
  - "OnClone" is used by 0x1017A625C, a class-specific copy that fires a script `OnClone` event. That is not the generic clone.
- **Unconfirmed lead.** It may dispatch through ISerializable's `+0x80` slot (SDK sub_78, sret Handle). This is not confirmed.
- **ABI note.** On Windows, `(Handle& out, const Handle& obj)` is a hidden return pointer. On macOS that out pointer would be in x8 and obj in x0, so Codeware's decl would need to change once the address is found.

## Summary
1. 10 of 11 FOUND, 1 NOT FOUND (ISerializable_Clone). 9 go into the JSON, because CEnum_FromString is found but held.
2. CEnum_FromString 0x1010CF45C takes `StringView` by value (x2 ptr, x3 len) on macOS, in both 2.3.1 and 2.5.0. The SDK `CEnum::FromString` func_t (`const CString&`) must change before its address is published.
3. The CBaseRTTIType base slots are the abstract IType vtable values (0x107833200), not the CClass overrides. Their bodies are opcode-identical to 2.3.1, so no SDK signature changes are needed. sub_A0 ignores x2/x3.
4. Entity_Assemble returns void on macOS; Codeware's `bool` return type must not be relied on (HookAfter is fine). CEnum and Entity field offsets (0x20/0x28/0x34/0x38, 0x50/0x58/0x60/0x70/0x138) are unchanged.
5. InitializeGameInstance is 0x101578050, settled by its job name "CGameFramework/GameInstance". The twin 0x1015780D4 is "CGameFramework/RuntimeScene". No Codeware change is needed.

## Script load assert "Failed to initialize scripts data!" (Codeware 343c7241, redscript 0.5.32)
- **Symptom.** Booting TweakXL + ArchiveXL + Codeware stops on the EXC_BREAKPOINT assert at 0x104D8316C ("Failed to initialize scripts data!"). redscript compiles and saves `final.redscripts` without errors (runs 20261104-093152-boot, 20261104-093655-boot). CET-only runs on the same redscript pass script init, so the 0.5.32 bundle format is not the cause.
- **Load path.**
  1. 0x104D7F128 → 0x104D7A9F8 → the loaders 0x104D76544 and 0x104D766BC.
  2. The loaders call the script loader singleton (getter 0x1011E6C1C, vtable 0x107837C80). Slot +0x8 is Load (0x1011E7114) and slot +0x10 is LoadWithMods (0x1011E914C).
  3. Load constructs the bundle (0x10111CBFC) and deserializes it (0x10111FF98). A deserialize failure reports "Failed to load scripts" instead.
  4. It then runs ScriptValidator::Validate (0x1011A7E28, with the validator constructor at 0x1011A7E24) and binds (0x101113E44).
  5. The result is stored to `[x19+0x54]`. A false result reaches the assert.
- **Validator.**
  - Validate dispatches by definition type. For a class or struct (0x1011A84B4), it looks up the RTTI type by name through `vt+0x108`. A null result branches to 0x1011A8628, the "Missing native class '%hs'" report (string at 0x1011A8640).
  - Failures are counted and Validate returns false.
  - The report object (vtable 0x107CD7C40, Error 0x104D76A78) keeps messages only when `([this+0x56] | byte 0x109D0DEB1) & 1`. They go into a DynArray<String> at +0xB0, capped at 10, and are never logged. That is why the game shows only the assert.
- **Cause.** Eight generated imports in Codeware `scripts/Base/Imports` declare `native` types that the macOS 2.5.0 binary does not contain. None of these names appears in the RTTI dump (run 20261103-220740-rttidump) or anywhere in the binary's strings:

  | Import | Kind |
  | --- | --- |
  | oauthAuthenticationToken | online service |
  | gsmMenuState_LoadSession | menu state |
  | toolsJiraService | editor tool |
  | InheritedStructs/Odyssey3DCustomData | editor |
  | InheritedStructs/inputInputSystemEditor | editor |
  | InheritedStructs/inputInputSystemWin32Base | Win32 |
  | InheritedStructs/inputInputSystemWin32Game | Win32 |
  | InheritedStructs/servicesGameServicesWin | Win32 |

  Nothing in Codeware's C++ or scripts references them.
- **Other checks, all clean.**
  - Every other `native class/struct` declared in Codeware, TweakXL, ArchiveXL and ModMenu scripts is either in the binary's strings or registered by the plugin's own C++.
  - Every native property declared on a dumped class is in RTTI or is registered by a Codeware `*Ex.hpp` RTTI_PROPERTY.
  - Every native function declared on a dumped class is in RTTI or is registered by Codeware.
  - Enum values were not checked: the dump has no enum values.
- **Fix.** Codeware 233fe79b removes the eight imports. `cp-dev` replaces the plugin's `Scripts/` folder wholesale, so no stale copies remain in the game.

## Script validator report: making its messages visible (Codeware 06596b94)
- **The assert persists after 233fe79b.** Run 20261104-105023-boot (crash Cyberpunk2077-2026-11-04-105029.ips) stops at `brk` 0x104D8317C. The caller is 0x104D7F690, reached by `tbz w0` at 0x104D7F12C after `bl 0x104D7A9F8`. That is the same path, called from ArchiveXL's after-hook on the engine-init function (hash 3273923080) through 0x10158B6E4.
- **Report object.** The loaders 0x104D76544 (Load) and 0x104D766BC (LoadWithMods) build the report on their stack:

  | Offset | Contents |
  | --- | --- |
  | +0x00 | vtable 0x107CD7C40 |
  | +0x08 | byte `enabled` (loader arg w2, or w1 for 0x104D766BC) |
  | +0x10 | local DynArray, destroyed on return |
  | +0x20 | `DynArray<String>* out` (arg x3, or x2) |
  | +0x28 | `uint32 cap` (arg w4, or w3) |

  - Both call sites (0x104D7B0A0..0x104D7B108 and 0x104D7B2F4..0x104D7B340) pass `enabled = ([loader+0x56] | byte 0x109D0DEB1) & 1`, `out = loader+0xB0` and `cap = 10`.
  - The result goes to `[loader+0x54]`, and 0x104D7AAE4 returns that byte.
- **Vtable 0x107CD7C40** has 5 entries, then 0:
  - +0x00 dtor 0x104D76638
  - +0x08 deleting dtor 0x104D769DC
  - +0x10 and +0x18 both 0x104D76A60: `x0 += 8; b 0x104D76A78`
  - +0x20 0x104D76A68: `(x0, x1 ignored, x2 msg, x3 len)` → 0x104D76A78
- **0x104D76A78 (`sub = report+8`, `msg`, `len`).**
  - It returns at once unless `byte [sub] == 1` and `out->size ([out+0xC]) < cap ([sub+0x20])`.
  - Otherwise it builds a `red::String` from `(msg, len)` (0x10002D170), grows `*out` (ptr +0, capacity +8, size +0xC; 0x20-byte elements, align 8; 0x100028674) and move-constructs the string into the new element (0x10002D558).
  - Nothing clears the array on entry. Nothing in the load path logs it.
- **Validate 0x1011A7E28 `bool(validator x0, bundle x1, report x2)`.**
  - It collects the bundle's definitions (0x10111EBCC) and dispatches each by `def->vt[+0x18]` type and `def->vt[+0x38]` native flag:
    - 0: 0x1011A803C (typeref)
    - 3, native: 0x1011A8128 (enum)
    - 4, native: 0x1011A8314 (bitfield)
    - 1, native: 0x1011A84B4 (class)
    - 5, native: 0x1011A8E58 (global function)
  - It counts failures and reports "Validation failed for %u type(s)". It returns w19, which is 1 only when there were no failures.
  - Tracking the report register (x2 at entry) through Validate and all five type validators gives only `ldr x8,[reg]` + `ldr x8,[x8,#0x10]` + `blr`, with `x0 = report`, `x1 = c_str` (0x100029328) and `w2 = length` (0x10002931C). No validator reads report fields or uses slots +0x18/+0x20.
- **Codeware change (macOS only).**
  - The Validate hook becomes a full `Hook`. It runs the existing OnValidateScripts fixups, then calls the original with a proxy report. The proxy's Itanium vtable, read back from the dylib's rebases, is: D1, D0, then Report10 at +0x10, Report18 at +0x18 and Report20 at +0x20.
  - Each slot records the message and forwards the call to the game report's matching slot, so the game sees the same calls.
  - After Validate returns, each message goes to `LogError` (Codeware.log) and to stderr as `[Codeware] Script validation: <msg>`, followed by `[Codeware] Script validation passed|FAILED (N messages)`.
  - It writes no game memory and uses no new address.
  - If stderr shows `passed` and the assert still fires, the failure is after validation (bind 0x101113E44). If no line appears, Load failed before Validate (deserialize 0x10111FF98).
- **Further offline checks of Codeware's scripts against the 2.5.0 binary, all clean.**
  - **Enums.** Every enum name and value name in `scripts/` occurs as a NUL-delimited string in the binary, apart from:
    - Codeware's own script enums (worldNodeFlag, OpenWorldActivityResult, DynamicEntityEventType, CallbackRunMode, CallbackLifetime, PlayerGender, EntryType, ERTTIType);
    - generated value names whose native name contains spaces or punctuation (`_228x128` for "228x128", `Very_dense` for "Very dense"). These are the same on Windows.
  - **Base classes.** For every dumped native class, the declared base matches the native parent, except two that OnValidateScripts patches before Validate (gameuiBaseUIData, scnChatter → ISerializable) and structs whose parent OnValidateScripts fills in. Script-alias parents were not resolved.
  - **Global native functions.** All are registered by Codeware (RTTI_FUNCTION, @addMethod statics).

## Script type aliases: checked offline, applied to the validator's verdict (Codeware, RED4ext tools/script_type_check.py)
- **Run 20261104-111828-boot.** With the validator messages visible (06596b94), the report holds 765 property messages and "Validation failed for 374 types". All but one are names Codeware's OnValidateTypeName accepts on Windows: `ResourceRef` for `rRef:*` (192, plus 22 in arrays), `ResourceAsyncRef` for `raRef:*` (303, plus 30 in arrays), `ResRef` for `raRef:CResource` (2), and `CurveData*` for `curveData:*` (212, some as static arrays `CurveDataFloat[8]` vs `[8]curveData:Float`). The one exception is `toolsMessage.created`, `Int64` in the script but `MemInt` natively; nothing reads that field.
- **Why Codeware's alias hooks do not act on macOS.** On Windows the aliases are applied in the hooked CompareTypeName. On macOS that function is inlined into the property and type validators, so the existing OnValidateProperty and CompareType hooks never see these comparisons.
- **Validate has no side effects beyond its report and its result.**
  - Validate (0x1011A7E28) and its type validators (0x1011A803C, 0x1011A8128, 0x1011A8314, 0x1011A84B4, 0x1011A8E58, helper 0x1011A8F30) contain 111 stores. Every one targets `sp` or `x29`.
  - The direct callees that store write only to stack objects the caller passes in. 0x10002DBEC formats a string into a stack sret. 0x104E33920 sets a vtable at `sp+0x18`. 0x100028564 and 0x10002858C initialize and free the local DynArray at `sp+0x8`.
  - The virtual calls fall into three groups. Calls on the RTTI system (0x1010B3288 returns it) are by-name lookups at slots +0x20/+0x28/+0x108/+0x110/+0x120, each followed by `cbz x0` to the "missing" report. Calls on a definition read its type (+0x18) and native flag (+0x38). The rest are the report's +0x10.
  - After the definition loop, the only difference between a pass and a failure is the "Validation failed" message and w19.
- **The loader after Validate (0x1011E7114).**
  - `cbz w0` at 0x1011E71DC goes to the failure path 0x1011E727C. Otherwise the loader continues into the bind at 0x101113E44, and bind's result decides the load.
  - Windows Codeware leaves bind alone and only widens the validator's name check. So after a pass forced by the alias check, bind receives the same bundle it receives on Windows.
- **Codeware change (macOS only).**
  - OnValidateScriptsLogged parses the recorded messages (`src/App/Scripting/ValidationReport.hpp`). If every message is an `Imported property ... type 'S' ... native one 'N'.` line that IsTypeNameAlias(S, N) accepts (array and static-array element types compared), it returns true. The final count line is ignored.
  - IsTypeNameAlias is OnValidateTypeName's table, unchanged. Any other message ("Missing native class", a non-alias type, an unparsed line) keeps the result false.
  - stderr shows `Script validation passed (type aliases only)`.
  - `tests/macos/validation_report_check` runs the parser on this run's log: all 765 messages minus MemInt pass, and with MemInt the check fails.
- **toolsMessage.created** is removed from Codeware's imports. It is the only non-alias mismatch.
- **Offline check (RED4ext `tools/script_type_check.py`, run by cp-gate and by cp-dev before a build).**
  - Inputs: the RTTI dump, the plugin's `.reds` native and importonly declarations, and the script names from the SDK's generated headers (ALIAS).
  - It reports native types missing from the dump that the plugin's sources don't register, and property type mismatches that the game's names and Codeware's alias table don't cover.
  - Calibration: with `--no-plugin-aliases` it finds 753 of the 765 logged mismatches and nothing extra. The other 12 are on classes the dump lacks (Codeware-registered `world*InnerNode`, `worlduiWidgetComponent`, `inkWidgetLibraryResource`, `Dynamic/StaticEntitySpec`), and all 12 are aliases.
  - On Codeware before 233fe79b it reports the 8 missing types that commit removed, plus MemInt.
- **inkWorldLayer.** The macOS size is 0x1B0 (SDK 0x1B8). `components`, at 0x170 on Windows, is not a reflected property, so its macOS offset is unverified. On macOS, Codeware's GetWorldWidgets returns an empty array. sdk_layout_diff.py now skips the `#else` side of `#ifdef __APPLE__` in plugin sources.
