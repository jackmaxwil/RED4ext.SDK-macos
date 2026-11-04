# 2.5.0 macOS port: Cyber Engine Tweaks addresses (batch 10)

Static analysis of the 2.5.0 binary (UUID 7D7382D0). Nothing was launched. The main session spot-checked the log-native registrations (name strings 0x1074EDA94.., fn pointers loaded into x3 before CGlobalFunction_ctor) and the four AddState callers.


None of these entries was verified on macOS 2.3.1, so each one was identified from scratch on the 2.5.0 binary
(`Cyberpunk2077-2.5.0-stock`, UUID 7D7382D0...). All FOUND addresses are in `__TEXT` (segment 1, offset = vmaddr - 0x100000000) and are in LC_FUNCTION_STARTS.

| hash | name | new address (vmaddr) | DB offset (seg:0xOFF) | FOUND/NOT FOUND | signature same? |
| --- | --- | --- | --- | --- | --- |
| 4233370276 | CBaseInitializationState_OnTick | 0x104D6B460 | 1:0x4D6B460 | FOUND | yes: `bool(IGameState* x0, CGameApplication* x1)` -> w0 |
| 1852772247 | CGame_Main (CBaseEngine::ProcessBaseLoopFrame) | - | - | NOT FOUND | n/a (CET does not use it) |
| 2447710505 | CInitializationState_OnTick | 0x104D6CB1C | 1:0x4D6CB1C | FOUND | yes: `bool(IGameState* x0, CGameApplication* x1)` -> w0 |
| 4052428712 | CPhotoMode_SetRecordID | - | - | NOT FOUND | - |
| 3592689218 | CRunningState_OnTick | 0x104D6CCAC | 1:0x4D6CCAC | FOUND | yes: `bool(IGameState* x0, CGameApplication* x1)` -> w0 |
| 160045886 | CScript_AllocateFunction | - (inlined) | - | NOT FOUND | NO: no out-of-line function exists (see notes) |
| 3455393801 | CScript_Log | 0x1011BAE18 | 1:0x11BAE18 | FOUND | yes: script native `(ctx x0, CStackFrame* x1, ret x2, type x3)` |
| 2135235617 | CScript_LogError | 0x1011BAEF8 | 1:0x11BAEF8 | FOUND | yes: script native |
| 3222609133 | CScript_LogWarning | 0x1011BAFD8 | 1:0x11BAFD8 | FOUND | yes: script native |
| 3515162577 | CScript_ToStringDEBUG | 0x1037D2AF8 | 1:0x37D2AF8 | FOUND | yes: script native, String result written to x2 when non-null |
| 1663049434 | CScript_LogChannel | 0x1011BB358 | 1:0x11BB358 | FOUND | yes: script native |
| 2841780134 | CScript_LogChannelWarning | 0x1011BB588 | 1:0x11BB588 | FOUND | yes: script native |
| 3442875632 | CScript_TranslateBytecode (CScriptDataBinder::LoadOpcodes) | - | - | NOT FOUND | - |
| 4069332669 | CShutdownState_OnTick | 0x104D6CE40 | 1:0x4D6CE40 | FOUND | yes: `bool(IGameState* x0, CGameApplication* x1)` -> w0 |
| 385618721 | gameIGameSystem_Initialize (spawn::Set::Initialize) | 0x1046DFBB8 | 1:0x46DFBB8 | FOUND | yes: `void(spawn::Set* x0, GameInstance* x1)` |
| 3313306514 | gameIGameSystem_UnInitialize (spawn::Set::Deinitialize) | 0x1046DFDFC | 1:0x46DFDFC | FOUND | yes: `void(spawn::Set* x0)` |
| 3168866665 | gameIGameSystem_Despawn (spawn::Set::DespawnObject) | 0x1046E1530 | 1:0x46E1530 | FOUND | yes: `void(spawn::Set* x0, IScriptable* x1)` |

Tools used: `re/d.py` (disassemble one function, with strings), `re/x.sh new call|adrp`, `re/fx-new.txt` (fixups), plus
`re2/b10_vt.py` (dump vtable slots from rebase fixups) and `re2/b10_str.py` (find exact C strings).
The Windows byte patterns quoted below come from CET's own history (`git show bcbd67e` in cp2077-cet, `Addresses.h` comments of the Windows build).

## Game state ticks (4 FOUND)

**Anchor.** `CGameApplication_AddState` is verified at 1:0x4D6A27C (RED4ext hash 4223801011). Its only 4 callers are in the state-setup routine:
`0x1000324fc`, `0x100032510`, `0x100032524`, `0x100032538`. Before each call the routine builds one state on the stack:

- BaseInitialization: inline, `adrp/add x8 -> 0x1077CDEF0`, `str x8,[sp,#0x18]` (cpLauncher-derived vtable).
- Initialization: ctor `0x104D6C984` stores vtable `0x107CD70C0`.
- Running: ctor `0x104D6CC34` stores vtable `0x107CD7108`.
- Shutdown: ctor `0x104D6CDC0` stores vtable `0x107CD7150`.
- The plain BaseInitialization ctor `0x104D6AABC` stores vtable `0x107CD7068`.

**Slot.** With the Itanium ABI, slot 0/1 are the destructors, then GetName (+0x10), GetType (+0x18), OnEnter (+0x20), **OnUpdate/OnTick (+0x28, slot 5)**, OnExit (+0x30).
This agrees with RED4ext `GameStateHook.hpp` (`OnEnterSlot = 4` on macOS, OnUpdate is `OnEnterSlot + 1`) and with ADDRESS_AUDIT (ReadOptions is slot 7).

| state | vtable | slot 2 GetName (string) | slot 5 OnTick |
| --- | --- | --- | --- |
| BaseInitialization | 0x1077CDEF0 and 0x107CD7068 | 0x104D6AB18 "BaseInitialization" | 0x104D6B460 (same in both vtables) |
| Initialization | 0x107CD70C0 | 0x104D6C9C0 "Initialization" | 0x104D6CB1C |
| Running | 0x107CD7108 | 0x104D6CC70 "Running" | 0x104D6CCAC |
| Shutdown | 0x107CD7150 | 0x104D6CDFC "Shutdown" | 0x104D6CE40 |

Re-check: `python3 re2/b10_vt.py re 0x1077cdef0 0x107cd7068 0x107cd70c0 0x107cd7108 0x107cd7150`.

**Second evidence (2.3.1 cross-check and body).**
- The same walk on 2.3.1 (AddState 0x103D8ADD0, ctors 0x103D8D588/7A8/8CC, vtables 0x106E4B258 / 0x10726F0C0 / 0x10726F118 / 0x10726F160 / 0x10726F1A8) gives slot-5 functions 0x103D8C0CC, 0x103D8D710, 0x103D8D820, 0x103D8D94C.
- The function map maps 0x103D8D820 to 0x104D6CCAC and 0x103D8D94C to 0x104D6CE40 ("vtable slot round 1").
- The bodies match. BaseInitialization reads the engine global (0x109D0E288), checks `[engine+0x128]` and calls `app->RequestState(w1 = 3/2/1)` (0x104D6A444), in the same shape as old 0x103D8C0CC (RequestState 0x103D8AF90 with 3/1/2).
- Initialization checks state 5 and requests 3 or 2, like old 0x103D8D710.
- Running: `ret = 0x104D7A450(engine)`. If the loop ended, it calls `engine->vt[0x90](-42)` and `RequestState(app, 3)`, then returns `!ret`.
- Shutdown calls `0x104D6A434(app, code)`, tears down and returns 1.
- All four take x1 = app and return w0. That matches CET `TStateTick = bool(IGameState*, CGameApplication*)`.
- The functions are reached only through the vtables (no BL callers), so there is no duplicate-copy issue.
- **Caution:** RED4ext swaps these same vtable slots. CET's inline hook on the function bodies still runs, because RED4ext's saved original pointer points to them.

## CGame_Main (CBaseEngine::ProcessBaseLoopFrame): NOT FOUND

- CET's `src/` does not reference `CGame_Main` (it appears only in Addresses.h).
- The candidate is `0x104D79E8C(engine x0, memfn ptr x1, adj x2)`. Running.OnTick reaches it through 0x104D7A450, which tail-calls it with x1 = 0x104D7A460 and x2 = 0. A second wrapper, 0x104D7A1D4, passes x1 = 0x104D7A1E4.
- The candidate does frame timing (dt clamp 0x3D872B02, about 0.066 s, an FPS window at +0x100/+0x108), then calls the Itanium pointer-to-member with s0 = dt.
- The Windows pattern for CRunningState_OnTick also builds a {fn, adj=0} member pointer and passes the engine, which supports this candidate.
- But the Windows CGame_Main pattern (`48 8B F9 0F 29 74 24 70 0F 29 7C 24 60 48 8D 4D C0`: this, xmm6/xmm7 saves, a stack object) fits either the wrapper or the per-frame body 0x104D7A460, which saves d8/d9.
- That is ambiguous, so fail-closed. Also, the macOS signature `(engine, memfn, adj)` would not match a one-argument `Main(engine)`.

## Script log natives (5 FOUND)

**Registration (evidence 1).** Each name string has exactly one ADRP reference in a registration thunk. The thunk builds a CName (0x1010B3160). On first use it calls an init function, which loads the native fn into x3 and calls the outlined `0x1010295B8` (`mov x1,x20; mov x2,x20; b 0x10109BAA8`, which is CGlobalFunction_ctor, verified 1:0x109BAA8).

| name | string | thunk | init | fn (x3) | ctor `this` in init |
| --- | --- | --- | --- | --- | --- |
| Log | 0x1074EDA94 | 0x1011C0484 | 0x1011C1488 | **0x1011BAE18** | x19+0x1F8 (=0x10806BAC8) |
| LogError | 0x1074EDA98 | 0x1011C04D8 | 0x1011C14D8 | **0x1011BAEF8** | x19+0x2E0 |
| LogWarning | 0x1074EDAA1 | 0x1011C052C | 0x1011C1528 | **0x1011BAFD8** | x19+0x3C8 |
| LogChannel | 0x1074EDAD6 | 0x1011C067C | 0x1011C1668 | **0x1011BB358** | x19+0x768 |
| LogChannelWarning | 0x1074EDAF1 | 0x1011C0724 | 0x1011C1708 | **0x1011BB588** | x19+0x938 |

Re-check: `sh re/x.sh new adrp 0x1074eda94 ...` and `python3 re/d.py new 0x1011c1488 0x60`. Each fn pointer has exactly one ADRP+ADD reference, in its own init.

**Body (evidence 2).**
- All five are standard script natives `(ctx, CStackFrame* x1, ret, type)`. In this release build they only consume their parameters (logging is compiled out).
- Log, LogError and LogWarning read one String parameter: `stp xzr,xzr,[x1,#0x30]`, the paramFlags/currentParam test at `[x1,#0x60]/[x1,#0x62]`, `ldr x0,[x1,#0x40]`, opcode fetch `[x1]++`, then dispatch through the opcode table 0x109A5C940.
- After normalising addresses, the three bodies hash identically. This matches the Windows note that one byte pattern hits 3 functions (`expected: 3`, index 0/1/2).
- LogChannel and LogChannelWarning read a CName (inline dispatch into an 8-byte local) and then a String. Their two bodies are identical, which matches the Windows `expected: 2`.
- The CStackFrame offsets used (code 0x00, data 0x30, dataType 0x38, context 0x40, paramFlags 0x60, currentParam 0x62) equal the SDK's 2.5.0 `CStackFrame` (size 0xA8). CET's HookLog and HookLogChannel need no change.

## CScript_ToStringDEBUG 0x1037D2AF8 (FOUND)

- **Registration.** The only exact string "ToStringDEBUG" (0x1074E9763) has two references:
  - `0x101186AB8` is a CName-cache initialiser and registers nothing.
  - `0x1037D2600` is inside the **TDBID** class native registration, which also registers TDBID, Create, IsValid, Prepend, Append, ToNumber, None and OpenRecordInVSCode.
- Its init `0x1037D3674` passes `x4 = 0x1037D2AF8` to `0x100F66DB4` (which branches to CClassFunction ctor 0x10109B8A4; the same ctor as IsA in the plugins2 notes).
- So on macOS this is a static native of class TDBID, not a CGlobalFunction. The hook target is the same native fn either way.
- **Body.**
  - `str xzr,[sp,#8]` (TweakDBID local = 0), `stp xzr,xzr,[x1,#0x30]`, `currentParam++` at `[x1,#0x62]`, then one opcode dispatch into the local and `code++` (ParamEnd).
  - Then `0x104E3967C(&id)` builds the debug string, and `if (x2) 0x10002AA74(x2, str)` assigns the String result.
  - This is the Windows pattern exactly (`83 64 24 38 00` local cleared, `FE 42 62` currentParam++, result only if non-null). It also matches CET's HookTDBIDToStringDEBUG (it writes `*apResult` only when it is non-null). Signature unchanged.

## CScript_AllocateFunction: NOT FOUND (inlined; the hook point does not exist on macOS)

- On Windows the function is a standalone `push rbx; sub rsp,30h; mov edx,0B8h; lea rcx,[rsp+20h]; call Alloc`. 0xB8 is the 2.x Windows CScriptedFunction size.
- On macOS 2.5.0, CScriptedFunction is 0xF8 (SDK). Its ctor 0x10109BBA0 sets vtable 0x10782FF40 and stores the parent at +0xF0.
- The ctor has 3 callers, all inside the script loader 0x101116C70. Each site inlines the allocation: `mov w0,#0xf8; bl 0x1052A623C` (stub -> GOT 0x1077A4048, which binds weak `red::memory::PoolStorageProxy<PoolRTTIFunction>::Allocate(unsigned long long)`, defined at 0x1010A268C), then `bl _bzero`.
- `PoolStorageProxy<PoolRTTIFunction>::Allocate` has no direct callers (105 call sites, all through the stub). No out-of-line "allocate a scripted function" exists.
- CET needs a different approach. Options: hook the 3 sites in 0x101116C70, or interpose the weak GOT slot 0x1077A4048, which also serves the CGlobalFunction/CClassFunction allocations at registration. CET's `void*(pool, size)` signature does not apply.

## CScript_TranslateBytecode (CScriptDataBinder::LoadOpcodes): NOT FOUND

- No symbol or string anchor. "Binder", "Opcode" and "Bytecode" are absent from strings and nm.
- The binder pipeline was located: loader 0x1011E914C ("Failed to load scripts"), then 0x10111FF98, then orchestrator **0x101120050(binder, data)**.
- After parsing, the orchestrator runs phases over the definitions DynArray (`[x1]` = ptr, `[x1+0xC]` = count, which is the shape of the Windows pattern `mov rbx,[rdx] ... mov eax,[rdx+0Ch]`):
  - 0x10112027C (types 3/4/5/9)
  - inlined LoadTypes (its uncalled twin is 0x1011206F8)
  - 0x10112076C (with a failure flag)
  - 0x101120B70
  - 0x101120F1C (classes and functions, only if not failed)
  - 0x1011211BC
- None of the phases is clearly the opcode translator, and no out-of-line function has the small prologue the Windows pattern implies.
- The opcode-switch functions (`cmp w,#0x67`, 0x68 opcodes) are a disassembler (0x10118B4DC, "Function code:"), a code comparer (0x10118DD08) and a walker over already-translated code (0x10118FBE8). None is the file-to-memory translator.
- Fail-closed. A next step would be a dynamic check: break on the 6 phases and see which one writes `CBaseFunction::bytecode` (+0x78).

## CPhotoMode_SetRecordID: NOT FOUND

- Windows shape: `void(TweakDBID rcx, Handle<IScriptable>& rdx)`, calling `X(&tmp, &id)` and then assigning the handle.
- Photo-mode anchors were found: PhotoModeSystem reads "general.recordIDForPhotoModePuppet" into this+0x868 at 0x101C4E304.
- The Spawn caller near photo mode (0x101C7FA8C) did not show a `(id, &request.field)` call of that shape.
- No conclusive second piece of evidence, so fail-closed.

## spawn::Set (CET's TEMP_Spawner): 3 FOUND

**Region anchor.**
- The verified Spawn 1:0x46E03B8 (hash 2509382878, `spawn::Set::SpawnObject`) uses `[this+0x50]`, `[this+0x58]` and locks `this+0x42` (pendingEntitiesMtx). This is the CET layout.
- The DynArray symbol `spawn::Set::PendingTicketEntry` at 0x1046E3B14 confirms the class region.
- The spawn::Set destructor 0x1046DFA7C frees DynArrays at +0x00, +0x10 (16-byte handles), +0x20 (0x28-byte entries) and +0x30. These are exactly TEMP_Spawner's unk00, spawnedEntities, pendingEntities and unk30.

**Initialize 0x1046DFBB8.**
- Body: `mov x21,x1; mov x19,x0; ldr x8,[x1,#0x78]; ldr x20,[x8,#0xa0]`. It then sets `this+0x60`, `this+0x58` (= `gi->vt[0x10](type)`, a system lookup), `this+0x48` (handle checked by IsA 0x1010C6BF4) and `this+0x50`.
- This matches the Windows pattern `mov rax,[rdx+78h]; mov r9,rdx; mov rbx,rcx`. It also matches CET's fields 0x48..0x60, which Spawn then reads at +0x50/+0x58.
- It has 52 call sites from many game systems.
- Note: CET's hash comment says the Windows hash may be a twin of `spawn::Set::Initialize` (3114931869). This address is spawn::Set::Initialize itself, which is what CET's `TEMP_Spawner::Initialize` needs.

**UnInitialize 0x1046DFDFC.**
- Body: locks `this+0x42` (exclusive lock 0x1000015F0), cancels the pending tickets (`strb #1,[ticket+0x10e]`), destroys the 0x28-byte pending entries, unlocks (`ldclralb #0x80`), calls 0x1046E1964 (despawn all), then **clears +0x60, +0x48 and +0x50**, undoing Initialize.
- This matches the Windows pattern `lea rdx,[rcx+42h]`.
- The Windows pattern hits 2 functions (index 1). The macOS twin 0x1046DFEB8 is the same body without the field reset.
- Pairing evidence: in 9 game-system vtables, the slot that calls 0x1046DFDFC is 1 or 2 slots after the slot that calls Initialize, i.e. an OnWorldAttached/OnBeforeWorldDetach pair. Examples:
  - 0x107968D88 -> 0x107968D90
  - 0x107BC5A98 -> 0x107BC5AA0
  - 0x107825568 -> 0x107825570

  0x1046DFEB8 has no such pairing (0 of 6 slots).

**Despawn 0x1046E1530.**
- `mov x19,x1; mov x20,x0; stp xzr,xzr,[sp]` (16-byte local cleared), then lock `this+0x41` (exclusive).
- It scans spawnedEntities at `this+0x10` (16-byte handles, size at +0x1C) for `handle.instance == x1`, moves the handle out, removes the element (0x101874834) and unlocks `this+0x41`.
- This matches the Windows pattern `mov rbp,rcx; xorps xmm0; add rcx,41h; mov rsi,rdx; movdqu [rax-28h],xmm0; call lock`. It has 35 callers.
- The sibling 0x1046E1C78 is an sret (x8) variant and was rejected.

## Summary

- 13 FOUND, 4 NOT FOUND (CGame_Main, CPhotoMode_SetRecordID, CScript_AllocateFunction, CScript_TranslateBytecode); every FOUND signature is unchanged from CET's declarations.
- CScript_AllocateFunction does not exist out of line on macOS: scripted functions are allocated inline (`PoolRTTIFunction::Allocate(0xF8)` through weak GOT slot 0x1077A4048, then bzero) at 3 sites in 0x101116C70, so CET's FunctionOverride size-override hook needs a code change.
- CScript_ToStringDEBUG is a TDBID static class native on macOS (registered through the CClassFunction ctor), not a CGlobalFunction; the hook signature still matches.
- CScriptedFunction is 0xF8 on 2.5.0 (Windows 0xB8); CET's `kOverrideAllocationSize = max(s_cMaxFunctionSize, sizeof(CScriptedFunction))` must use the 2.5.0 SDK size. CStackFrame offsets used by the log natives match SDK 0xA8.
- Layout to check (not re-verified here): pass2.md puts the macOS spawn Request's appearanceName at 0xA0 and recordID at 0xC0, but CET's TEMP_SpawnSettings asserts recordID at 0xE0. If 2.5.0 matches pass2.md, CET's SpawnRecord needs a fix.
