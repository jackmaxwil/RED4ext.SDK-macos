# Address DB audit (macOS 2.3.1, build 5314028)

- **Binary:** Steam `Cyberpunk2077`, LC_UUID `A6656ADC-FBE2-36A4-9B9D-B4A9DE645089`. Addresses below are absolute, with image base `0x100000000`.
- **Last updated:** 2026-10-06.
- **Tools:** `scripts/validate_addresses.py`, `scripts/snap_prologue_offsets.py`, `scripts/xref_scan.py`, `xcrun llvm-objdump`.

## Systematic error: offsets inside prologues

Earlier discovery walked back from a reference site to the `stp x29, x30, [sp, #N]` frame setup and stopped there. That missed the `sub sp` and register-pair saves that come before it, so the stored offset sits 4–24 bytes into the function.

`snap_prologue_offsets.py` moves such an entry back to the containing `LC_FUNCTION_STARTS` entry. It only does this when every instruction in between is a prologue store. It fixed 33 entries, including 7 of the 8 core loader hooks.

A snapped offset is a real function start. **That does not prove it is the right function.** The identity of each core hook is checked separately below.

## Core loader hooks

The first launch (plan task 1B.3) uses only `CGameApplication_AddState`. No other core hook may be enabled until its identity reaches **confirmed**.

| Hash name | Old | Now | Identity | Evidence |
|---|---|---|---|---|
| `CGameApplication_AddState` | `0x3F22E98` (inside another function's epilogue) | `0x3D8ADD0` | **confirmed in game** (hooked: 4 hits, all four states seen) | The state-setup routine at `0x100031EC0` builds the app on the stack, then constructs the four states (ctors `0x103D8B6F0`, `0x103D8D588`, `0x103D8D7A8`, `0x103D8D8CC`; vtables found through their `GetName` strings "BaseInitialization", "Initialization", "Running" and "Shutdown"). After each one it calls `0x103D8ADD0(app, &state)`. These are the function's only 4 callers. It calls `state->vtbl[0x18]` (`GetType`, see below) and inserts into a map at `app+0x268`. |
| `CBaseEngine_LoadScripts` | `0x3D9A03C` | `0x3D9A028` | likely | References `final.redscripts`, `final_noopts.redscripts`, `master.redscripts` and `profiling.redscripts`. One direct caller. |
| `CBaseEngine_InitScripts` | `0x3D8C1A0` | **zeroed** | **refuted** | The containing function `0x3D8C188` is vtable slot 7 of BaseInitializationState (`0x10726F0C0`) and reads `unattended`, `scriptVersion`, `windowCaption`, `tweakdbBlobPath`. That is `ReadOptions`, not `CBaseEngine::InitScripts`. |
| `Global_ExecuteProcess` | `0x1D46808` | **zeroed** | **refuted** | The containing function `0x1D467FC` runs `/usr/sbin/system_profiler SPDisplaysDataType` (GPU detection). It is not a generic process launcher. It is open whether the macOS build spawns `scc` at all, since redscript on macOS compiles before launch. |
| `ScriptValidator_Validate` | `0x3D96BFC` | `0x3D96BF4` | unverified | No strings and no direct callers. Not found in any vtable. |
| `AssertionFailed` | `0x3C3D4C` | `0x3C3D48` | unverified | No direct callers. It is slot 2 of the vtable at `0x106E60328`, which makes it a virtual method. The Windows hook is a free function. Its prologue (`sub sp, #0x420`, then it saves x1–x3) fits a formatter. |
| `GameInstance_CollectSaveableSystems` | `0x87FEC` | `0x87FD4` | doubtful | 11 KB function with a `0xC10` stack frame and 2 callers. Too large for a collector. |
| `GsmState_SessionActive_ReportErrorCode` | `0x3F5E9B0` | `0x3F5E9A8` | unverified | Slot 45 in 5 related vtables. The RE function map names different functions as `gsmState_SessionActive` methods (`0x103F6F810`, `0x103F72574`). |

## ABI note: Itanium vtables

The game is built with clang, so game-state vtables follow the Itanium ABI. Slot 0 is the complete destructor and slot 1 is the deleting destructor. Every later virtual sits 8 bytes after the MSVC offsets in the `GameStates.hpp` comments. For example, `GetType` is at `+0x18`, not `+0x10`, as `AddState` itself shows.

Calls made by name through clang-compiled SDK headers are unaffected. Any code that indexes vtables by hard-coded MSVC offsets is wrong on macOS. RED4ext `GameStateHook.hpp` had this bug (it swapped GetType, OnEnter and OnUpdate); it now uses platform slot indices.

## Remaining validator errors

After the prologue snap and the fixes above, `validate_addresses.py` reports 71 errors on the canonical DB. They are mostly:

- data entries tagged as segment 1;
- suspiciously round offsets (`0x1000100`, `0x2200100`, ...);
- offsets into `__cstring`;
- the four zeroed entries.

They are the Phase 2.3 backlog. Fix the hashes that will be patched first.

## Memory allocator: exported symbols instead of addresses

The `Memory_Vault*` entries were not the vault:

- `Memory_Vault_Alloc` (`0x24584`) is an allocator-class constructor.
- `Memory_Vault` (`0x24400`) points inside another allocator constructor.
- Two pairs share an address.

The macOS game exports `red::memory::PoolStorageProxy<Pool>::{Allocate, AllocateAligned, Reallocate, ReallocateAligned, Free, GetHandle}` for every memory pool (658 pools). These are static functions taking and returning `red::memory::Block {void*, size_t}`, which has the same layout as `AllocationResult`.

On macOS, `Memory/Allocators.hpp` resolves them with `dlsym(RTLD_MAIN_ONLY, ...)`. `Memory/PoolSymbols.hpp` is generated by `scripts/gen_pool_symbols.py` and maps SDK pool names to the mangled template argument; it covers 591 of 630 pools, and the misses are names the SDK truncates.

**Verified in game (2026-10-06):** `DefaultAllocator` alloc 64, realloc to 4096 with the data preserved, then free, passed. The `Memory_Vault*` DB entries are unused on macOS.

**Prefer exported symbols over DB offsets wherever the game exports them.** They are exact by construction and survive game patches.

## CRTTISystem_Get: wrong

`1:0x3452734` is a guarded singleton getter in the streaming code with zero direct callers. At runtime its object's first qword is null, so it has no vtable.

The Running-state self-check `rtti_get_type` fails as expected, and it refuses to call through the object.

The real getter is still being located. Every RTTI-dependent feature is blocked on it: native function registration, TweakXL and ArchiveXL.

## RTTI system, function constructor, name pool (2026-10-06)

| Hash name | Old | Now | Evidence |
|---|---|---|---|
| `CRTTISystem_Get` | `0x3452734` (the CNamePool singleton getter) | `0x2188E8C` | **Guarded singleton.** Returns `0x107D6A288` in `__bss`. Its constructor stores vtable `0x106FFBD70`, which has 41 slots, with the destructor pair last because the header declares the destructor last. **Callers:** thunk `0x21885A0` has 2914 BL callers. Callers use slots `+0x08`, `+0x10` and `+0x18` with 64-bit name hashes. The register wrapper at `0x21884A4` calls slot `+0xA0`. **Path from `GetTypeObject<CName>`:** found through the GOT. Exported weak symbols are reached only via `__got`, so ADRP scans on the symbols themselves find nothing. |
| `CGlobalFunction_ctor` | `0x21E8C88` (walks a DynArray) | `0x21739E8` | **Stores** the base vtable, names, and DynArrays at `+0x28` and `+0x38`, then the `CGlobalFunction` vtable and `regIndex` at `+0xB0`. **Callers:** thunk `0x2173AD4` has 653 callers; the `NameToString` registration calls it. |
| `CNamePool_Get` | `0x90E7D8` (inside a strtoul parser) | `0x3452D84` | `ldr x0,[x0]; b 0x3452BDC`. The target looks up the hash in the name-pool singleton and returns `{ptr, len}` in x0 and x1. 1240 callers. |

`CNamePool_AddCstr`, `CNamePool_AddPair` and `CNamePool_AddCString` sit in the same misplaced block of text-formatting code and are wrong. The real add-a-C-string function appears to be `0x3452DDC` (thunk `0x2188524`). It returns the `CName` in x0, so the SDK binding has to change too. Pending confirmation.

## Fail-closed resolution (2026-10-06)

Database entries carry `"verified": true` only when this audit has evidence for them. Both the RED4ext loader (`Addresses.cpp`) and the SDK (`Relocation-inl.hpp`) resolve **only** verified entries. Every other hash resolves to null:

- a hook on a null address is refused;
- an SDK call through a null address stops at pc 0;
- no wrong address is ever called or written through.

`RED4EXT_ALLOW_UNVERIFIED_ADDRESSES=1` disables the gate. Use it for reverse-engineering sessions only.

CI runs `validate_addresses.py --verified-only`. A verified entry with any finding fails the build.

**Verified (12):**
- `CGameApplication_AddState`
- `Main`
- `CRTTISystem_Get`
- `CGlobalFunction_ctor`
- `CNamePool_Get`
- `CNamePool_AddCstr`
- `CNamePool_AddPair`
- `CNamePool_AddCString`
- `CString_ctor_str`
- `CString_ctor_span`
- `CString_dtor`
- `CString_copy`

**`DynArray_Realloc` (`0x2C524`) is wrong.** It is `String::reserve` (it has the 19-character inline-capacity check). Using it for `CBaseFunction::AddParam` wrote into read-only memory (crash 2026-10-06 21:23).

## DynArray_Realloc (2026-10-06): fixed, verified

`0x2C524` → **`0x286E8`**. The call graph pins it down:

- **Callers.** 21,709 BL plus 75 B call sites.
- **Through the move callbacks.** About 6,030 of 2,378 `MoveAfterReallocation` GOT slots lead straight to it, loaded into x4 just before the call. The next-best candidate gets 2.

The body matches the SDK signature `(array, capacity, elemSize, alignment, move)`:

1. It returns early if the capacity is unchanged.
2. It allocates, then calls the move callback with a byte count and the source array.
3. It stores the new pointer at `+0` and the capacity at `+8`.
4. It keeps the allocator handle after the buffer.

**Caveat:** a null move callback selects the realloc/raw-copy path. That is fine only for trivially relocatable element types.

## OpcodeHandlers (2026-10-06): fixed, verified

The old value, `1:0x6E40000`, was a fabricated round number. The correct value is **`3:0x1CF7798`**, the script VM's opcode handler table at absolute `0x10908B798`.

**Evidence:** the 502 exported script natives (`funcOperator*<T>(IScriptable*, CScriptStackFrame&, void*, rtti::IType const*)`) read each parameter the same way:
1. `ldrb w8, [frame.code], #1`, then `adrp/add x21, table`.
2. `ldr x8, [x21, x8, lsl #3]`.
3. `blr x8` with `(frame.context, frame, out, 0)`.

7,417 code sites load the table address. The frame fields touched (`data @0x30`, `dataType @0x38`, `context @0x40`, `currentParam @0x62`) match the SDK's `CStackFrame` exactly.

## TweakXL addresses (2026-10-06): 11 replaced, all verified

All 11 of TweakXL's previous macOS candidates were wrong: seven were unrelated functions and four pointed into the middle of a prologue or body. Each replacement below is in `LC_FUNCTION_STARTS` and was checked by disassembly.

| Name | Hash | Old | New | Evidence |
| --- | --- | --- | --- | --- |
| `TweakDB_Init` | 3062572522 | `0x2B79AC0` (TDBID script native) | `0x35F1BAC` | Job lambda that engine init `0x1035F0A48` registers (ADRP+ADD at `0x1035F0D88`), third in the same order as the "BaseGameEngine/Initialization/LoadTweakDB" label. It is the only engine-init caller of `TweakDB_Load`. |
| `TweakDB_Load` | 3602585178 | `0x2B7BE94` | `0x2B75570` | `(TweakDB*, CString&)`. Its failure path asserts "Failed to load optimized TweakDB file!". It calls `TryLoad` twice. |
| `TweakDB_TryLoad` | 3512345737 | `0x2B7BAB0` (`.tweak` parser) | `0x2B7CC9C` | `bool(x0, TweakDB*, CString*, x3)`. It references "Binary blob not found" and "Binary blob header is not valid", then runs the four section loaders. |
| `TweakDB_CreateRecord` | 838931066 | `0x2B737AC` (RTTI registration) | `0x26B8DB8` | `(TweakDB*, w1 typeHash, x2 TweakDBID)`. It starts with `and w8, w1, #0x1f` to dispatch on the hash. The records loader `0x2B16B64` calls it with `(db, hash, id)`. |
| `TweakDBID_Derive` | 326438016 | `0x2B7D228` | `0x3453B14` | **arm64 signature is `TweakDBID(const TweakDBID* base, const char* name)`, returned in x0.** It computes the string length, then tail-calls the CRC routine `0x34535C0` seeded with `*base`. The Windows `(base, out, name)` form must not be used. |
| `StatsDataSystem_InitializeRecords` | 1299190886 | `0x3A939B8` (mid-prologue) | `0x3A939A0` | Loops 1709 (`0x6AD`) times over the stat enum. Called at `0x3A9532C`, directly before `InitializeParams`. |
| `StatsDataSystem_InitializeParams` | 3652194890 | `0x3A932C4` (mid-function) | `0x3A932A8` | Fills the array at `+0xE8` from the one at `+0xD8`. Calls the verified `DynArray_Realloc`. |
| `StatsDataSystem_GetStatRange` | 1444748215 | `0x3A94744` (mid-function) | `0x3A9472C` | Vtable `0x107239E60`. **Returns `{float min, float max}` in s0/s1 with `(this, stat)`.** There is no hidden return pointer. |
| `StatsDataSystem_GetStatFlags` | 3123320294 | `0x3A93F00` (mid-function) | `0x3A93EF0` | Vtable `0x107239E68`. `uint32(this, stat)`. The `cmp`/`b.hi` bounds check comes before the prologue. |
| `StatsDataSystem_CheckStatFlag` | 2954893634 | `0x3A93E7C` (mid-prologue) | `0x3A93E74` | Vtable `0x107239E70`. `bool(this, stat, flag)`, ending in `tst flags, w2`. |
| `CBaseFunction_InternalExecute` | 404169501 | `0x94FE44` (functional-test routine) | `0x2173120` | `bool(func, ctx, frame, ret, retType)`. It tests `func+0xA8` bit 0 to choose the native path. It is called from the call opcode handlers `0x2250114` and `0x22501F4`. |

The three StatsDataSystem accessors sit in consecutive vtable slots. They take the reader lock at `+0xFC` and read 12-byte `StatParams` from the array at `+0xE8`, which confirms TweakXL's offsets.

## SharedSpinLock encoding differs on macOS (2026-10-06)

The game's macOS lock routines are at `0x100002098` (lock shared), `0x1000020C0` (lock), `0x1000020E8` (try lock) and `0x100002100` (try lock shared). The releases are inlined: `ldaddalb -1` for a reader and `ldclralb 0x80` for the writer. These routines use a different byte encoding from Windows:

- **Windows:** `-1` means a writer holds the lock. A writer releases by storing 0. A reader enters by compare-and-swap, and only while the value is not `-1`.
- **macOS:** bit 7 means a writer holds the lock, and bits 0–6 count readers.
  - A reader increments the count first, then waits for bit 7 to clear.
  - A writer waits for 0, then compare-and-swaps in `0x80`.
  - A writer releases by clearing only bit 7, so the counts of readers waiting meanwhile survive.

With the Windows encoding, SDK code would let a plugin reader in while a game writer held the lock, and an SDK writer's release would erase the game's reader counts. That affects every SDK struct that embeds `SharedSpinLock`, including TweakDB, RTTISystem, ResourceLoader, ink widgets and memory pools. `SharedSpinLock-inl.hpp` now implements the macOS encoding under `__APPLE__`.

`Mutex` (`CRITICAL_SECTION` on Windows, `pthread_mutex_t` here) differs in size. Any SDK struct that embeds it, such as `CRTTISystem`, is not layout-compatible on macOS and must not be accessed by field offset.

## Plugin worklist pass (2026-10-06): jobs, core, appearance, character customization, resources

These groups were reverse-engineered statically. The per-entry evidence (strings, call graph, vtable slots, struct fingerprints) is in `docs/re/<group>.md`. Only entries marked "confirmed" there are `"verified": true` in the database. Entries marked "likely" have their offset updated but are left unverified.

- **jobs:** 11 of 11 confirmed. The SDK now returns `JobQueue::Capture` through x8 and passes `JobInternalHandle_Acquire` its name argument.
- **core:** 25 confirmed and 1 likely (`CClass_GetProperties`).
  - `Handle_ctor` has no out-of-line copy on macOS, so the SDK now inlines it.
  - `ISerializable::sub_78`, `sub_B0` and `sub_C8` return through x8 on macOS.
  - `CGameEngine` is 0x380 bytes on macOS. `ResourceDepot` has a different layout (`rootPath` at +0x48).
- **appearance:** 20 confirmed and 7 likely.
  - 2 are inlined on macOS: `TPPRepresentationComponent_IsAffectedSlot` and `AppearanceChanger_GetSuffixValue`.
  - 8 were not found.
- **charcustom:** 15 confirmed. `GetHairColor` is inlined, and `GetResource` exists but is never called.
- **resources:** 29 confirmed and 3 likely.
  - `ResourceLoader_OnUpdate` was not found.
  - `ResourceToken_DestructUnk38` is inlined.
  - The earlier ArchiveXL crash at `0x1D50D24` is in the game's input-context code (`0x101D50CE8`), not in any resource function.

**`verified` covers the address only.** Many confirmed functions have arm64 signatures that differ from ArchiveXL's Windows declarations. The most common difference is a result returned through x8 that the Windows declaration passes as a hidden second argument. Each group file lists them under "signature" or "ABI". ArchiveXL must be ported to those signatures, and must drop or replace its hooks on inlined or missing functions, before it can be enabled. The loader keeps refusing it while any hash it uses is unverified.
