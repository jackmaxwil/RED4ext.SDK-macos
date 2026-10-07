# Porting a RED4ext plugin to macOS

This is the procedure used to port TweakXL, ArchiveXL and ModMenu. Follow the steps in order; each has a check that
fails if the step is not done.

## 1. Build it

1. Add a CMake build next to the Windows one. Keep the Windows build files, so the fork stays rebaseable.
2. Point it at this SDK with one option, `RED4EXT_SDK_DIR` (the repository root), defaulting to a pinned
   `vendor/RED4ext.SDK` submodule:
   ```cmake
   set(RED4EXT_SDK_DIR "${CMAKE_SOURCE_DIR}/vendor/RED4ext.SDK" CACHE PATH "RED4ext.SDK repository root")
   target_include_directories(MyPlugin PRIVATE "${RED4EXT_SDK_DIR}/include")
   ```
3. Replace Win32 calls with POSIX ones, and Windows-only libraries (MinHook, Detours, TiltedCore) with the standard
   library or RED4ext's hooking API. Put macOS code behind `#ifdef __APPLE__`.
4. The game root is three folders above the executable (`Cyberpunk2077.app/Contents/MacOS/Cyberpunk2077`), not two.

Check: the `.dylib` builds with clang and `-Wall`.

## 2. Use only verified addresses

Every game address resolves through `cyberpunk2077_addresses.json`. Only entries marked `"verified": true` resolve;
anything else resolves to 0, and RED4ext refuses to load a plugin that needs it.

```bash
python3 scripts/plugin_requirements.py path/to/MyPlugin.dylib
```

It lists every address hash compiled into the plugin and whether it is verified (exit 1 if any is not). For each
unverified one, either:

- verify it with evidence (string or call references, vtable slots, matching code) and record the evidence in
  `docs/re/` or `docs/ADDRESS_AUDIT.md` before setting `verified`; or
- turn the feature off on macOS and log that it is off. The game must never call through an address nobody checked.

Check: `plugin_requirements.py` exits 0.

## 3. Fix the arm64 calling and layout differences

The Windows code was written against MSVC x64. On macOS arm64 with clang:

| Difference | What to do |
| --- | --- |
| A non-trivial struct returned by value comes back through a hidden pointer in `x8`, not as the first argument. | Declare the function with its real return type; do not pass the result pointer as an argument. |
| Vtables have two destructor slots (complete and deleting). | Every virtual after the destructor is 8 bytes later than its MSVC offset. Never index vtables with Windows offsets. |
| Member-function pointers are 16 bytes (function plus this-adjustment). | Do not cast them to `void*` or store them in 8 bytes. |
| Overloaded virtuals keep declaration order; MSVC can reverse them. | Check the slot order of overloaded virtuals against the game. |
| Tail padding of a base class can hold derived fields. | Check derived layouts (step 4). |
| `__declspec(thread)`/TLS block access does not exist; `RED4ext::TLS::Get()` returns `nullptr`. | Do not read game state through the TLS block. |
| Static members of class templates are only instantiated when used. | Explicitly instantiate registrars that rely on static initialization (TweakXL's RedLib registrars needed this). |
| `typeid`/`nameof` type names differ (no `enum ` prefix, `RED4ext::` namespace). | Do not match type names as strings without normalizing them. |
| The game inlines some functions that are separate on Windows. | Hook the caller instead, or rebuild the small function in your code. |

## 4. Check the classes you touch

```bash
python3 scripts/sdk_layout_diff.py --plugin-sources path/to/src
```

It compares every SDK class your code uses against the game's macOS layout (from `data/rtti_layout_macos.json`, a
live RTTI dump) and fails on a size or field-offset difference. For writes into classes whose layout differs, check
the field offset at runtime through the game's RTTI and skip the write if it does not match.

## 5. Test it in the game

In the [workspace](https://github.com/jackmaxwil/cp2077-macos), add a scenario under
`RED4ext/tools/autotest/scenarios/` and run it in the background:

```bash
RED4ext/tools/cp-dev myscenario --plugins MyPlugin
```

Menu scenarios define `CpRunMenuChecks`; in-world scenarios define `CpRunWorldStep` (load the last save, then run
steps). Add it to `tools/cp-regress` once it passes.

## 6. Shut down cleanly

The game destroys its systems before plugins unload. Do not release game handles or call into the game from static
destructors on macOS; leak them at unload instead (ArchiveXL's `LeakAtExit`).
