# RED4ext.SDK (macOS)

C++ SDK for building Cyberpunk 2077 mods on macOS ARM64.

**Status:** Complete — 126/126 address hashes resolve, type sizes verified, TLS functional.

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
| `cyberpunk2077_addresses.json` | Hash-to-offset mapping for v2.3.1 |
| `scripts/validate_addresses.py` | Validate address tables against the game binary (`--help`) |
| `scripts/check_addresses.py` | Legacy duplicate/zero check |
| `docs/STATUS.md` | Port status |

## Validation

```bash
python3 scripts/validate_addresses.py   # uses the Steam binary if present, else segment checks only
python3 scripts/check_addresses.py --strict
```

## Related projects

| Project | Description |
|---------|-------------|
| [RED4ext](../RED4ext) | Mod loader that uses this SDK |
| [TweakXL](../cp2077-tweak-xl) | Plugin built on this SDK |
| [ArchiveXL](../cp2077-archive-xl-macos) | Plugin built on this SDK |

## Attribution

Forked from [WopsS/RED4ext.SDK](https://github.com/WopsS/RED4ext.SDK). macOS port by memaxo.
