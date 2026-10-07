#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/arcade/ArcadeSpawnerController.hpp>

namespace RED4ext
{
namespace game::ui::arcade
{
struct RoachRaceObstacleSpawnerController : game::ui::arcade::ArcadeSpawnerController
{
    static constexpr const char* NAME = "gameuiarcadeRoachRaceObstacleSpawnerController";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unkD0[0x11C - 0xD0]; // D0
    float initialMinimumSpawnTime; // 11C
    uint8_t unk120[0x124 - 0x120]; // 120
    float spawnRateIncreasePerCycle; // 124
    float doubleSpawnDelay; // 128
    float initialDoubleSpawnChance; // 12C
    float doubleSpawnChanceIncreasePerLevel; // 130
    uint8_t unk134[0x148 - 0x134]; // 134
    float powerupSpawnTimeDelayMultiplier; // 148
    float carrotSpawnTime; // 14C
    uint8_t unk150[0x154 - 0x150]; // 150
    float appleSpawnTime; // 154
    uint8_t unk158[0x168 - 0x158]; // 158
#else
    uint8_t unkD0[0x13C - 0xD0]; // D0
    float initialMinimumSpawnTime; // 13C
    uint8_t unk140[0x144 - 0x140]; // 140
    float spawnRateIncreasePerCycle; // 144
    float doubleSpawnDelay; // 148
    float initialDoubleSpawnChance; // 14C
    float doubleSpawnChanceIncreasePerLevel; // 150
    uint8_t unk154[0x168 - 0x154]; // 154
    float powerupSpawnTimeDelayMultiplier; // 168
    float carrotSpawnTime; // 16C
    uint8_t unk170[0x174 - 0x170]; // 170
    float appleSpawnTime; // 174
    uint8_t unk178[0x188 - 0x178]; // 178
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(RoachRaceObstacleSpawnerController, 0x168);
RED4EXT_ASSERT_OFFSET(RoachRaceObstacleSpawnerController, initialMinimumSpawnTime, 0x11C);
RED4EXT_ASSERT_OFFSET(RoachRaceObstacleSpawnerController, spawnRateIncreasePerCycle, 0x124);
RED4EXT_ASSERT_OFFSET(RoachRaceObstacleSpawnerController, doubleSpawnDelay, 0x128);
RED4EXT_ASSERT_OFFSET(RoachRaceObstacleSpawnerController, initialDoubleSpawnChance, 0x12C);
RED4EXT_ASSERT_OFFSET(RoachRaceObstacleSpawnerController, doubleSpawnChanceIncreasePerLevel, 0x130);
RED4EXT_ASSERT_OFFSET(RoachRaceObstacleSpawnerController, powerupSpawnTimeDelayMultiplier, 0x148);
RED4EXT_ASSERT_OFFSET(RoachRaceObstacleSpawnerController, carrotSpawnTime, 0x14C);
RED4EXT_ASSERT_OFFSET(RoachRaceObstacleSpawnerController, appleSpawnTime, 0x154);
#else
RED4EXT_ASSERT_SIZE(RoachRaceObstacleSpawnerController, 0x188);
#endif
} // namespace game::ui::arcade
using gameuiarcadeRoachRaceObstacleSpawnerController = game::ui::arcade::RoachRaceObstacleSpawnerController;
} // namespace RED4ext

// clang-format on
