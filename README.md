# RED4ext.SDK (macOS arm64 fork)

C++20 headers for writing [RED4ext](https://github.com/jackmaxwil/RED4ext-macos) plugins for Cyberpunk 2077. This fork of
[WopsS/RED4ext.SDK](https://github.com/WopsS/RED4ext.SDK) adds macOS arm64 support for Cyberpunk 2077 **2.3.1** (game
binary UUID `A6656ADC-FBE2-36A4-9B9D-B4A9DE645089`). The Windows build is kept; CI still builds it.

What the fork adds:

- arm64/Itanium ABI fixes in the hand-written headers (see the rules below).
- macOS class layouts for the generated headers, produced from a live RTTI dump (`data/rtti_layout_macos.json`) by
  `scripts/gen_macos_layouts.py`.
- An address database, `cyberpunk2077_addresses.json`, that replaces the Windows Address Library.
- A small Windows compatibility layer (`include/RED4ext/Detail/WinCompat.hpp`) and pthread/atomic versions of the
  mutex and spinlocks.

## Use it in a plugin

Add this repo as a submodule (or a sibling checkout), then:

```cmake
set(CMAKE_CXX_STANDARD 20)
set(RED4EXT_HEADER_ONLY ON CACHE BOOL "" FORCE)   # recommended on macOS
add_subdirectory(deps/RED4ext.SDK)

add_library(MyPlugin SHARED src/Main.cpp)
target_link_libraries(MyPlugin PRIVATE RED4ext::SDK)
```

```cpp
#include <RED4ext/RED4ext.hpp>
```

Start from any project in `examples/`. Copy the built `.dylib` into `<game>/red4ext/plugins/MyPlugin/`; RED4ext loads
every `.dylib` it finds there.

Without `RED4EXT_HEADER_ONLY` the target is a static library; both modes build on macOS. TweakXL, ArchiveXL and ModMenu
instead add `include/` to their include path directly, which is equivalent to header-only mode.

## macOS rules for plugin authors

The full procedure, with checks for each step, is in [docs/PORTING_A_PLUGIN.md](docs/PORTING_A_PLUGIN.md).

- **Only verified addresses resolve.** An address hash whose DB entry is not `"verified": true` resolves to 0, and
  RED4ext refuses to load a plugin that needs one. Check your build:
  `python3 scripts/plugin_requirements.py path/to/MyPlugin.dylib` (exit 1 lists the unverified hashes).
- **Check the classes you touch.** `python3 scripts/sdk_layout_diff.py --plugin-sources path/to/src` fails if a class
  your code uses has a different macOS size or field offset than the SDK header says.
- **Struct results come back through x8.** A function that returns a non-trivial struct by value takes a hidden result
  pointer in x8, not as the first argument as on Windows. Declare such functions with the real return type.
- **Vtables have two destructor slots.** Slot 0 is the complete destructor, slot 1 the deleting destructor, so every
  later virtual is 8 bytes after its MSVC offset. Never index vtables with Windows offsets.
- **Member-function pointers are 16 bytes** (function plus this-adjustment), not 8.
- **Overloaded virtuals keep declaration order** under clang; MSVC can reverse them, so their slots can differ.
- **No TLS block.** `RED4ext::TLS::Get()` returns `nullptr` on macOS; the game keeps per-thread state in C++
  `thread_local` variables.

## Address database

`cyberpunk2077_addresses.json` maps 32-bit hashes (constants in `include/RED4ext/Detail/AddressHashes.hpp`) to
`segment:offset` (1 = `__TEXT`, 2 = `__DATA_CONST`, 3 = `__DATA`). At runtime the SDK reads it from
`$RED4EXT_SDK_ADDRESS_DB` or `<game>/red4ext/bin/x64/cyberpunk2077_addresses.json` (installed by RED4ext).

**Verified** means the address was identified in the 2.3.1 binary by static analysis, with the evidence written down in
[docs/ADDRESS_AUDIT.md](docs/ADDRESS_AUDIT.md) or [docs/re/](docs/README.md). Currently 187 of 278 entries are
verified, including every address TweakXL, ArchiveXL and ModMenu use. Unverified entries are kept for later work but do
not resolve.

```bash
python3 scripts/validate_addresses.py --verified-only --quiet   # checks against the game binary if installed
python3 scripts/plugin_requirements.py MyPlugin.dylib           # which hashes a plugin needs, and are they verified
```

### Patch day

A game update invalidates every address and the layout dump.

1. In RED4ext, run `tools/cp-run rttidump` and copy `logs/rtti_layout_macos.json` to `data/` here.
2. Run `python3 scripts/gen_macos_layouts.py --verify` to regenerate the macOS layouts.
3. Re-verify each verified DB entry against the new binary using the evidence in `docs/`. Update offsets and the `uuid`
   field, and set `"verified": false` on anything not re-confirmed.
4. In RED4ext, run `tools/cp-gate`. It checks the UUID, the DB, the layouts and every plugin's required hashes.

## Build and test

```bash
cmake -S . -B build -DRED4EXT_BUILD_EXAMPLES=ON          # add -DRED4EXT_HEADER_ONLY=ON for header-only
cmake --build build -j8

python3 scripts/validate_addresses.py --self-test
python3 scripts/validate_addresses.py --verified-only --quiet
python3 scripts/sdk_layout_diff.py --self-test
```

CI (`.github/workflows/build.yml`) runs the Windows build matrix and the three Python checks.

## Credits

Upstream: [WopsS/RED4ext.SDK](https://github.com/WopsS/RED4ext.SDK) by Octavian Dima and contributors, MIT licensed
(see [LICENSE.md](LICENSE.md) and [THIRD_PARTY_LICENSES.md](THIRD_PARTY_LICENSES.md)). The macOS port is by jackmaxwil.
