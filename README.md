# RED4ext.SDK (macOS)

C++ SDK for building Cyberpunk 2077 mods on macOS ARM64.

**Status:** In progress. Only address DB entries marked `"verified": true` resolve, and most are not verified yet. RED4ext boots to the main menu with these headers and the SDK self-checks pass; ModMenu loads, TweakXL and ArchiveXL do not yet. See [docs/ADDRESS_AUDIT.md](docs/ADDRESS_AUDIT.md) and §0 of `~/Development/cyberpunk/RESUME_PLAN.md`.

## What it does

Provides header-only C++ types and address resolution for the Cyberpunk 2077 runtime. Plugins include this SDK to access game functions, RTTI types, TweakDB, and scripting APIs. On macOS, addresses resolve from `cyberpunk2077_addresses.json` instead of Windows Address Library.

## Usage

Add `include/` to your project's include path. Include the address resolver override header before any SDK headers if your plugin uses custom hashes:

```cpp
#include <RED4ext/RED4ext.hpp>
```

## Key files

| File | Purpose |
|------|---------|
| `include/RED4ext/Relocation-inl.hpp` | macOS address resolution (JSON loading) |
| `include/RED4ext/Detail/AddressHashes.hpp` | 126 address hash constants |
| `include/RED4ext/Common.hpp` | Platform compatibility types |
| `cyberpunk2077_addresses.json` | Hash-to-offset mapping for v2.3.1, with a `verified` flag per entry |
| `scripts/validate_addresses.py` | Validate address tables against the game binary (`--help`) |
| `scripts/plugin_requirements.py` | List the hashes a plugin dylib needs and whether each is verified |
| `docs/ADDRESS_AUDIT.md` | Evidence for each verified or refuted address |
| `docs/STATUS.md` | Port status |

## Validation

```bash
python3 scripts/validate_addresses.py   # uses the Steam binary if present, else segment checks only
python3 scripts/plugin_requirements.py <plugin.dylib>   # exit 1 if any required hash is unverified
```

## Related projects

| Project | Description |
|---------|-------------|
| [RED4ext](../RED4ext) | Mod loader that uses this SDK |
| [TweakXL](../cp2077-tweak-xl) | Plugin built on this SDK |
| [ArchiveXL](../cp2077-archive-xl-macos) | Plugin built on this SDK |

## Attribution

Forked from [WopsS/RED4ext.SDK](https://github.com/WopsS/RED4ext.SDK). macOS port by memaxo.
