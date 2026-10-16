# Evidence: 4 rows for the entity spawner (spawn::Set)

Four rows that Cyber Engine Tweaks' `exEntitySpawner` needs on macOS and that `cyberpunk2077_addresses.json` on `main` (`f657158c0`) does
not have. The fifth function it uses, `Spawn` (2509382878), is already a verified row here at `1:0x14084B0`, the same address we found.

| Hash | Name (CET) | Windows RVA | Mac offset | What the Mac function does |
|---|---|---|---|---|
| 385618721 | `gameIGameSystem_Initialize` (`spawn::Set::Initialize`) | 0xAC7ED4 | `1:0x1407CA8` | reads `[gi+0x78]+0xA0`, then writes `this+0x60`, `+0x58`, `+0x48`, `+0x50` |
| 3313306514 | `gameIGameSystem_UnInitialize` (`spawn::Set::Deinitialize`) | 0x204D490 | `1:0x1407EEC` | lock byte `+0x42`, clears the 0x28 byte pending entries at `+0x20`, zeroes `+0x50`, `+0x48`, `+0x60` |
| 3168866665 | `gameIGameSystem_Despawn` (`spawn::Set::DespawnObject`) | 0x65CEFC | `1:0x140974C` | lock `+0x41`, array `+0x10`, listeners `+0x30`, then the entity dispose call |
| 2840271332 | `gameIGameSystem_SpawnCallback` (`world::RuntimeEntityRegistry::RegisterEntity`) | 0x8B57F4 | `1:0xD13C5C` | lock `+0x43`, map `+0x48` |

How they were found: each Mac function was matched to its Windows body by its field offsets and call sequence. On the Mac,
`Initialize`, `UnInitialize`, `Spawn` and `Despawn` sit next to each other (0x1407CA8 to 0x140974C).

Runtime: on Cyberpunk 2077 2.3.1 for macOS (Apple silicon), CET's `exEntitySpawner.Spawn` with these rows spawned a template entity, the
entity was found by its ID within 10 s, and `exEntitySpawner.Despawn` removed it, with no crash (automated test, 2026-10-16). The
initialise log line printed non-zero `+0x50` and `+0x60`, which `Spawn` requires.

`scripts/validate_addresses.py --binary <Cyberpunk2077>`: 36 errors and 41 warnings before and after (none on these rows).
