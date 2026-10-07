#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/AlwaysSpawnedState.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/SpawnInViewState.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Node.hpp>

namespace RED4ext
{
namespace world
{
struct PopulationSpawnerNode : world::Node
{
    static constexpr const char* NAME = "worldPopulationSpawnerNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk32[0x34 - 0x32]; // 32
    TweakDBID objectRecordId; // 34
    uint8_t unk3C[0x40 - 0x3C]; // 3C
    CName appearanceName; // 40
    bool spawnOnStart; // 48
    game::AlwaysSpawnedState alwaysSpawned; // 49
    game::SpawnInViewState spawnInView; // 4A
    bool prefetchAppearance; // 4B
    bool isVehicle; // 4C
    uint8_t unk4D[0x50 - 0x4D]; // 4D
#else
    TweakDBID objectRecordId; // 38
    CName appearanceName; // 40
    bool spawnOnStart; // 48
    game::AlwaysSpawnedState alwaysSpawned; // 49
    game::SpawnInViewState spawnInView; // 4A
    bool prefetchAppearance; // 4B
    bool isVehicle; // 4C
    uint8_t unk4D[0x50 - 0x4D]; // 4D
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PopulationSpawnerNode, 0x50);
RED4EXT_ASSERT_OFFSET(PopulationSpawnerNode, objectRecordId, 0x34);
RED4EXT_ASSERT_OFFSET(PopulationSpawnerNode, appearanceName, 0x40);
RED4EXT_ASSERT_OFFSET(PopulationSpawnerNode, spawnOnStart, 0x48);
RED4EXT_ASSERT_OFFSET(PopulationSpawnerNode, alwaysSpawned, 0x49);
RED4EXT_ASSERT_OFFSET(PopulationSpawnerNode, spawnInView, 0x4A);
RED4EXT_ASSERT_OFFSET(PopulationSpawnerNode, prefetchAppearance, 0x4B);
RED4EXT_ASSERT_OFFSET(PopulationSpawnerNode, isVehicle, 0x4C);
#else
RED4EXT_ASSERT_SIZE(PopulationSpawnerNode, 0x50);
#endif
} // namespace world
using worldPopulationSpawnerNode = world::PopulationSpawnerNode;
} // namespace RED4ext

// clang-format on
