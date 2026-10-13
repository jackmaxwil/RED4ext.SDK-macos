# Address database corrections for rows the validator flags

Game: Cyberpunk 2077 2.3.1 for macOS (UUID A6656ADC-FBE2-36A4-9B9D-B4A9DE645089), compared with the Windows 2.3.1 build of the same
release. Every row here was unverified and failed `scripts/validate_addresses.py` (a placeholder offset, a shared address, an address that
is not a function start, or a global written as a code offset). The new values are proposals: they keep their unverified status, so the
loader and SDK go on ignoring them until you verify them. The rows were found with our address tools (string anchors, caller sets,
vtable slots) and each one was then checked by reading both disassemblies.

## Rows

| hash | name | Windows RVA | before | after |
|---|---|---|---|---|
| 302583262 | IRenderProxy_sub_00 | 0x2ac2688 | 1:0x1000100 | 1:0xE89C14 |
| 3505328647 | IRenderProxy_sub_08 | 0xb9dfcc | 1:0x1000180 | 1:0x16A386C |
| 2756580845 | IRenderProxy_sub_18 | 0x10bf30 | 1:0x1000200 | 1:0xE89C18 |
| 2462126272 | IRenderProxy_sub_58 | 0x1902260 | 1:0x1000300 | 1:0xE89C24 |
| 3491501770 | IRenderProxy_sub_60 | 0x1902270 | 1:0x1000380 | 1:0xE89C2C |
| 2542474580 | IRenderProxy_sub_78 | 0x6e6a10 | 1:0x1000400 | 1:0x1010B2C |
| 510274732 | IRenderProxy_sub_80 | 0x294898 | 1:0x1000480 | 1:0x1010B5C |
| 3724941976 | IRenderProxy_sub_88 | 0x6653c8 | 1:0x1000500 | 1:0x1010D20 |
| 1894391003 | IRenderProxy_sub_90 | 0x2906ec0 | 1:0x1000580 | 1:0x1010E68 |
| 3516862860 | IRenderProxy_sub_98 | 0x1902350 | 1:0x1000600 | 1:0x1010FEC |
| 4096926792 | IRenderProxy_sub_A8 | 0x2906e78 | 1:0x1000680 | 1:0x1011014 |
| 1468405902 | IRenderProxy_sub_B0 | 0xacec88 | 1:0x1000680 | 1:0x1010C98 |
| 3832485534 | CBaseRTTIType_sub_80 | 0x2066530 | 1:0x22EEAC | 1:0x21AFD4C |
| 2757309857 | CBaseRTTIType_sub_90 | 0x206636c | 1:0x22F04C | 1:0x21AFED4 |
| 2930319133 | CBaseRTTIType_sub_98 | 0x20665bc | 1:0x3228 | 1:0x21B007C |
| 2396396482 | CBaseRTTIType_sub_A0 | 0x2066354 | 1:0x3228 | 1:0x21B01E0 |
| 3414823260 | CRTTIScriptReferenceType_ctor | 0x2862b8 | 1:0x2200000 | 1:0x21AF014 |
| 586028847 | CRTTIScriptReferenceType_Set | 0x289030 | 1:0x2200100 | 1:0x21AF338 |
| 458427884 | Memory_Vault | 0x3438b00 | 1:0x24400 | 3:0x12CF80 |
| 859968306 | Memory_Vault_Free | 0x14455c | 1:0x2478C | 1:0xFB0C |
| 1997150124 | Memory_Vault_Realloc | 0x321d74 | 1:0x2478C | 1:0xF944 |
| 434901863 | Memory_Vault_Unk1 | 0x204e360 | 1:0x246E0 | 1:0x10490 |
| 1452677801 | Memory_Vault_ReallocAligned | 0x141cd8 | 1:0x246E0 | 1:0xFFAC |
| 3410956665 | BasePackageReader_ReadHeader | 0x26f7e4 | 1:0x21005D4 | 1:0x214FA38 |
| 677908004 | LaunchParameters | 0x32f67c8 | 1:0x7600000 | 3:0xF763E0 |
| 3063747982 | ResourceReference_Fetch | 0x1db158 | 1:0x12F055C | 1:0x21C9934 |
| 2589919757 | ResourceToken_dtor | 0x2422a8 | 1:0x12F066C | 1:0x21C4A14 |
| 2508398574 | ResourceToken_DestructUnk38 | 0x28b814 | 1:0x12F080C | 1:0x0 |

The last row is set to zero on purpose (see "Zero on purpose").

## Evidence

### IRenderProxy (12 rows): vtable slots

Windows vtable `0x2AC2688` (stored by the constructor `0x23763C`), Mac vtable `__DATA_CONST` image RVA `0x6EFB228` (stored at
`0x1010790`). Slots correspond with the usual Itanium offset: +8 after the destructor pair (Mac `0x10`/`0x18` are the complete and
deleting destructors), and +16 from Windows `0x78` on, because Mac has one extra virtual at slot `0x80` (`0x1010B14`:
`ldr x8,[x1]; stur x8,[x0,#0x74]; ret`) that Windows does not have. The shared stubs confirm the alignment on both sides of it: Windows
`0x14A700` (`ret 0`) at `0xA0` is Mac `0x1011010` (`ret`) at `0xB0`, and Windows `0x9C4600` at `0x38`/`0xB8` is Mac `0x22CAB4` at
`0x40`/`0xC8`. Bodies:

- `sub_18` `movzx eax,[rcx+0x7D]; shr al,3` = `ldrb w8,[x0,#0x7d]; lsr w0,w8,#3`.
- `sub_58` / `sub_60` the float at `+0x84` and its square = `ldr s0,[x0,#0x84]` (`fmul s0,s0,s0`).
- `sub_78` stores the second argument at `+0x68` and an id at `+0x70` = `str x1,[x0,#0x68]` ... `str w0,[x19,#0x70]`.
- `sub_80` reads `[this+0x70]` first on both sides. `sub_88` works on the third argument's `+0x10` (`lea rcx,[r8+0x10]` =
  `ldr q0,[x2,#0x10]`); `sub_90` on the second argument's `+0x10`. `sub_98` copies the argument into `+0x50..+0x58`.
- `sub_A8` loads `[this+0x68]` and passes the argument on (Mac tail call `b 0x10443E4`). `sub_B0` calls a virtual of `this`.
- `sub_08` null-checks, calls slot 0, the destructor slot and slot `0x20` (Mac through the `ldr x2,[x8,#0x20]; br x2` thunk `0x1AFD0`).
- `sub_00`: the Windows row points at the vtable itself (`.rdata`), but `RenderProxy-inl.hpp` calls this hash as a function
  (`UniversalRelocFunc<void (*)(void)>`), so the Mac row is the function in slot 0, `0xE89C14` (`b 0x164A5FC`, the twin of the Windows
  slot-0 thunk `0x2942B4` `jmp 0x2942BC`).

The old `sub_A8` and `sub_B0` rows shared `1:0x1000680`; the old offsets were evenly spaced placeholders.

### CBaseRTTIType (4 rows): vtable slots

Windows slots `0x80` `rtti::IType::SerializeToText`, `0x90` `ReadValue`, `0x98` `WriteValue`, `0xA0` are Mac slots `0x88`, `0x98`,
`0xA0`, `0xA8` in the same vtables; the neighbours match too (Windows `0x88` = Mac `0x90`, Windows `0xA8`
`0x9C4600` = Mac `0xB0` `0x22CAB4`). Inside, the calls to the type's own virtuals move by 8 (ToString `[this+0x68]` -> `[this+0x70]`).
`sub_A0` passes the string `Type does not contain any properties` on both sides (Mac `0x21B01F0`). The old `sub_98`/`sub_A0` rows shared `1:0x3228`
(`mov w0,#0; ret`).

### CRTTIScriptReferenceType (2 rows)

- `ctor`: vtable store, `+0x18`/`+0x20` zeroed, inner type at `+0x10`, then GetName of the inner type (Windows `[vtable+8]`, Mac
  `[vtable+0x10]`) and the name at `+0x20`. Mac `0x21AF014`: `stp xzr,xzr,[x0,#0x18]; str x20,[x0,#0x10]` ... `str x0,[x19,#0x20]`.
- `Set`: type at `+0x10`, second argument at `+0x18` (`stp x1,x2,[x0,#0x10]`), then the virtual at Windows `+0x30` / Mac `+0x38`, and
  the name at `+0x20`.

### Memory::Vault (5 rows)

The Windows functions dispatch on three heaps inside the vault: small `[this+0xC900, this+0xC908)`, medium at `this+0xCD80`, large at
`this+0xCE40`. The Mac functions build the same three offsets (`mov w8,#0xc900`, `#0xcd80`, `#0xce40`):

- `Free` (`red::memory::DefaultAllocator::Free`) `0xFB0C` and `Unk1` (`GetBlockSize`, returns the size in `w0`) `0x10490`.
- `Realloc` `0xF944` and `ReallocAligned` `0xFFAC` (alignment in `x3`). Both return the 16-byte result in `x0`/`x1`; Windows writes
  through a hidden pointer, so a caller must use the Mac signature.
- `Memory_Vault` is a global: `__DATA` offset `0x12CF80` (image RVA `0x74C0F80`, `__bss`), the object the allocator's only
  constructor builds (`0x37554`: `adrp/add` to `0x74C0F80`, then `bl 0x27CA0`). The old `1:0x24400` was inside `__text`.

The old `Free`/`Realloc` rows shared `1:0x2478C`, and `Unk1`/`ReallocAligned` shared `1:0x246E0` (the out-of-memory reporter).

### Other rows

- `BasePackageReader_ReadHeader` `0x214FA38`: the Mac twin of the callers anchor it (Windows `0x8A9980` and Mac `0x4922C90` both use the string
  `UI/WidgetLibraryItem/AsyncSpawnFromDefPack`; Windows calls ReadHeader at `0x8A99E2`, Mac calls `0x214FA38` at `0x4922D88`). The header comes back through `x8` on the Mac.
- `LaunchParameters` `3:0xF763E0` (image RVA `0x830A3E0`): the getter `0x344D0EC` returns it (`adrp/add; ret`), and its callers look up
  launch parameter names (`noBinksOnLoadingScreens` at `0x237286C`) in it as a hash map, like the Windows readers of `0x32F67C8`.
- `ResourceReference_Fetch` (`res::ResourceReference::Get`) `0x21C9934`: EnsureLoaded, then the token's data or the empty-handle
  global when the token is null, on both sides.
- `ResourceToken_dtor` `0x21C4A14`: on Mac the IsFinished test is inlined (`[this+0x58]`, `[this+0x5C]`), then RequestCancel on
  `[this+0x38]` and the same member teardown as Windows.

## Zero on purpose

Added to `ALLOW_ZERO` in `scripts/validate_addresses.py`:

- `2203918127` `Global_ExecuteProcess` (`CProcessRunner::Run`): the Windows process runner; no macOS twin was found. Already zero.
- `2875532677` `CBaseEngine_InitScripts`: inlined into its caller (function `0x3D9E494`, from `0x3D9E5E8`: the same calls to `0x3449690`
  and `0x3D99E44` as the copy). An out-of-line copy exists at `0x3D9ED9C`, but nothing calls, jumps to or takes the address of it, so a
  hook there would never run. Already zero.
- `2508398574` `ResourceToken_DestructUnk38`: inlined into its callers on macOS. Was `1:0x12F080C` (not a function start); now zero.

## Not changed

- `1518151849` `CBaseFunction_Handlers`: macOS keeps two native handler tables, one of 16-byte pointer-to-member entries for member
  functions (image RVA `0x900B798`) and one of 8-byte entries for static functions (`0x908B798`); the game picks one by the function's
  static flag. `CBaseFunction::GetHandler` indexes a single 8-byte array, so no one address fits it: this needs an SDK change, not a row.
- `CommandListContext_Close`, `CommandListContext_AddPendingBarrier`, `CommandListContext_FlushPendingBarriers`: not found, so left as
  they are rather than guessed.
  - The class exists on the Mac (`GpuApi::CommandListContext` appears in a template symbol), but the string Windows `Close` uses as an
    anchor, `FinalFlushBarriers`, is not in the Mac binary, and neither are `FlushBarriers` or `PendingBarrier`. Resource barriers are a
    D3D12 idea that Metal handles differently, so these functions may be reshaped or gone on the Mac.
  - On Windows `FlushPendingBarriers` is 0x36 bytes: read the barrier count at `+0x534`, return if zero, pass the list at `+0x528` to a
    command-list virtual, clear the count. 22 Mac functions read a word at `+0x534`; none has that size or shape. The three that clear
    it are 0x884 bytes and larger (the flush may be inlined there), and the smallest that also uses `+0x528`, `0x1EDA124`, appends to a
    list of 8-byte entries (`AddPendingBarrier` appends 0x20-byte barriers on Windows).
  - The current values are not these functions either:
    - `1:0xF040F8` is listed for both `Close` and `AddPendingBarrier`, and one address cannot be two different functions (the
      validator's shared-address error). It also matches neither: it is a 0x2B4-byte function that starts by reading `[x0,#0x34]` and
      comparing `[x0,#0x20]` with 4, and never touches the barrier list at `+0x528`/`+0x534`. Windows `Close` uses the
      `FinalFlushBarriers` string and calls `FlushPendingBarriers`, and Windows `AddPendingBarrier` reads and writes `+0x528`/`+0x534`.
    - `1:0xF041BC` (`FlushPendingBarriers`) is 0xC4 bytes into that same function, not a function start (the validator's other error),
      so it cannot be called as a function.
  - If they have no Metal equivalent, they belong in `ALLOW_ZERO`, like `g_DeviceData` and `Allocator_CreateResource`.
- `15404457` `ResourceReference_Load`: the Windows row points at a string in `.rdata` (`GetPositionRangeCount`), so there is nothing
  to map.

## Validator

`scripts/validate_addresses.py --binary <Cyberpunk2077> -q`: 36 errors and 41 warnings on main `f657158c0`, 10 errors and 31 warnings with
this change. Six of the ten are the rows of the address database PR #2; the other four are the rows under "Not changed". With
`--verified-only`: 0 errors before and after. `--self-test` passes.
