# Docs

Evidence for the macOS address database (`../cyberpunk2077_addresses.json`) and the macOS layouts. Every entry marked
`"verified": true` must be justified in one of these files. All work is static analysis of the 2.3.1 arm64 binary
(UUID `A6656ADC-FBE2-36A4-9B9D-B4A9DE645089`) unless a section says it was confirmed in game.

| File | Contents |
|---|---|
| [ADDRESS_AUDIT.md](ADDRESS_AUDIT.md) | Main audit log: the prologue-offset fix, core loader hooks, Itanium vtable note, validator results, dated changes. |
| [re/core.md](re/core.md) | Core SDK addresses: RTTI classes, script function calls, handles, TweakDB, engine singletons. |
| [re/gamesystem.md](re/gamesystem.md) | GameInstance and the GetGameSystem chain, including the crash it caused. |
| [re/jobs.md](re/jobs.md) | Job dispatcher and job queue functions. |
| [re/resources.md](re/resources.md) | Resource loading, meshes, factory index and package extraction. |
| [re/world.md](re/world.md) | Journal, localization, mappins, quests, ink widgets and other world hooks. |
| [re/appearance.md](re/appearance.md) | ArchiveXL appearance hooks. |
| [re/charcustom.md](re/charcustom.md) | CharacterCustomization hooks used by ArchiveXL. |
| [re/archivexl_port.md](re/archivexl_port.md) | Other hook targets for the ArchiveXL port. |
| [re/pass2.md](re/pass2.md) | Second pass over appearance, resources, world and core entries. |
| [re/rttireg.md](re/rttireg.md) | RTTI native-type registration used by TweakXL (RedLib). |
| [re/tweakxl_layout.md](re/tweakxl_layout.md) | Struct and container layouts that TweakXL reads or writes. |
| [re/reflection_layout.md](re/reflection_layout.md) | Reflection object layout used by the live RTTI dumper. |
