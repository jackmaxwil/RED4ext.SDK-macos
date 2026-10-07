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
