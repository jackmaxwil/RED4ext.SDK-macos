# Agent rules: RED4ext.SDK (macOS arm64 fork)

C++20 headers for RED4ext plugins, targeting Cyberpunk 2077 2.3.1 on macOS arm64 (binary UUID
`A6656ADC-FBE2-36A4-9B9D-B4A9DE645089`). Windows must keep building as upstream does. Read README.md first.

## Hard rules

1. **Never mark an address `"verified": true` without evidence** written in `docs/ADDRESS_AUDIT.md` or `docs/re/*.md`
   (function start in `LC_FUNCTION_STARTS`, identity from strings, callers, vtables or a struct layout, and an arm64
   signature that matches the plugin's declaration). Unverified entries must stay unverified; they resolve to 0 on
   purpose (`include/RED4ext/Relocation-inl.hpp`). Do not weaken that fail-closed check.
2. **Never delete RE evidence.** `docs/ADDRESS_AUDIT.md` and `docs/re/*.md` justify every verified address.
3. **macOS first.** Fix things for the macOS build. Guard platform differences with `#ifdef __APPLE__` /
   `#if defined(_WIN32)` and leave the Windows path unchanged.
4. **Static analysis and the loader only.** Static analysis (`xcrun llvm-objdump`, `dyld_info`, the scripts here) and
   the RED4ext loader are the tools; no external instrumentation frameworks.
5. **Do not launch the game or Steam** from tooling. Validation reads the binary from disk only.
6. Do not hand-edit `data/rtti_layout_macos.json` or the `#ifdef __APPLE__` blocks in
   `include/RED4ext/Scripting/Natives/Generated/`. Regenerate them (`scripts/gen_macos_layouts.py`).

## macOS ABI facts to respect in headers

- Non-trivial structs are returned through x8, not through a hidden first argument.
- Itanium vtables have two destructor slots, so virtuals sit 8 bytes after their MSVC offsets.
- Member-function pointers are 16 bytes.
- Clang keeps declaration order for overloaded virtuals; MSVC can reverse it.
- Class layouts can differ from Windows (tail-padding reuse, `pthread_mutex_t` is 64 bytes).

## Checks before finishing

```bash
python3 scripts/validate_addresses.py --self-test
python3 scripts/validate_addresses.py --verified-only --quiet
python3 scripts/sdk_layout_diff.py --self-test
cmake -S . -B build -DRED4EXT_BUILD_EXAMPLES=ON && cmake --build build -j8
```

For a plugin: `scripts/plugin_requirements.py <plugin.dylib>` and `scripts/sdk_layout_diff.py --plugin-sources <src>`.
The full offline gate is `tools/cp-gate` in the RED4ext repo.

## Adding an address

1. Add the hash constant to `include/RED4ext/Detail/AddressHashes.hpp`.
2. Add `{ "hash": "<decimal>", "offset": "<seg>:0x<off>" }` to `cyberpunk2077_addresses.json` (seg 1 `__TEXT`,
   2 `__DATA_CONST`, 3 `__DATA`), unverified.
3. Write the evidence in `docs/re/` or `docs/ADDRESS_AUDIT.md`, then set `"verified": true` and update `stats`.
