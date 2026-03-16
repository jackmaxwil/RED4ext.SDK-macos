# RED4ext.SDK macOS Port — Status

> **Last updated:** 2026-02-08
> **Target game build:** Cyberpunk 2077 macOS **v2.3.1**
> **Target arch:** Apple Silicon (arm64)

## Scope

This repository provides a macOS ARM64-compatible fork of **RED4ext.SDK** for building Cyberpunk 2077 plugins on macOS, while maintaining Windows compatibility.

## Current state (high signal)

- **Address database**: `cyberpunk2077_addresses.json` contains **126 / 126** hashes for v2.3.1.
- **Loader address database**: `cyberpunk2077_addresses.loader.json` contains **134** loader hook targets for v2.3.1.
- **Image base resolution**: Fixed to correctly find game binary among DYLD-injected images (uses `_NSGetExecutablePath` + `_dyld_image_count` iteration instead of `_dyld_get_image_header(0)`).
- **Runtime smoke test**: `examples/macos_smoke_test/` validates address DB loading + resolution at runtime.
  - Result: `missing=0 dup=0`, TLS functional, type sizes correct (`CName`=8, `TweakDBID`=8, `CString`=32), `CRTTISystem_Get` and `TweakDB_Get` resolve to valid addresses.
- **Validation tooling**: `scripts/check_addresses.py` and `scripts/check_loader_addresses.py` enforce duplicates/zeros/missing checks.

## Quick validation (what to run)

From repo root:

```bash
python3 scripts/check_addresses.py --strict
python3 scripts/check_loader_addresses.py --strict
```

Build + run the smoke test plugin (see `docs/ADDRESS_VALIDATION.md` for full steps).

## Where to look next

- **Address DB validation**: `docs/ADDRESS_VALIDATION.md`
- **End-to-end integration checklist**: `docs/INTEGRATION_CHECKLIST.md`
- **Platform changes summary**: `MACOS_CHANGES.md`
