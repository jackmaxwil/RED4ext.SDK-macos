# RED4ext.SDK macOS Port: Status

Target: Cyberpunk 2077 macOS 2.3.1 (arm64).

The authoritative progress table is §0 of `~/Development/cyberpunk/RESUME_PLAN.md` (a workspace file outside this repo). Per-address evidence is in [ADDRESS_AUDIT.md](ADDRESS_AUDIT.md).

## Current state

- `cyberpunk2077_addresses.json` is the single canonical DB. Only entries marked `"verified": true` resolve; every other hash resolves to 0 (fail closed). Most entries are not verified yet.
- The memory allocator resolves through the game's exported `PoolStorageProxy<Pool>` symbols, not DB offsets.
- RED4ext boots to the main menu with these headers and the SDK self-checks pass.
- ModMenu's required hashes are all verified. TweakXL and ArchiveXL still need unverified hashes, so RED4ext refuses to load them.

## Checks

```bash
python3 scripts/validate_addresses.py                   # DB vs. game binary
python3 scripts/plugin_requirements.py <plugin.dylib>   # a plugin's required hashes and their verified state
```

## Other docs

- [ADDRESS_AUDIT.md](ADDRESS_AUDIT.md): address evidence and remaining validator errors
- [../MACOS_CHANGES.md](../MACOS_CHANGES.md): platform changes vs. upstream
