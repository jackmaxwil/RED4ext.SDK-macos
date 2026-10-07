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
struct RoachRaceCloudSpawnerController : game::ui::arcade::ArcadeSpawnerController
{
    static constexpr const char* NAME = "gameuiarcadeRoachRaceCloudSpawnerController";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    float minCloudRelativeVelocity; // D0
    float maxCloudRelativeVelocity; // D4
    float cloudSpawnTime; // D8
    uint8_t unkDC[0xE0 - 0xDC]; // DC
#else
    uint8_t unkD0[0xD4 - 0xD0]; // D0
    float minCloudRelativeVelocity; // D4
    float maxCloudRelativeVelocity; // D8
    float cloudSpawnTime; // DC
    uint8_t unkE0[0xE8 - 0xE0]; // E0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(RoachRaceCloudSpawnerController, 0xE0);
RED4EXT_ASSERT_OFFSET(RoachRaceCloudSpawnerController, minCloudRelativeVelocity, 0xD0);
RED4EXT_ASSERT_OFFSET(RoachRaceCloudSpawnerController, maxCloudRelativeVelocity, 0xD4);
RED4EXT_ASSERT_OFFSET(RoachRaceCloudSpawnerController, cloudSpawnTime, 0xD8);
#else
RED4EXT_ASSERT_SIZE(RoachRaceCloudSpawnerController, 0xE8);
#endif
} // namespace game::ui::arcade
using gameuiarcadeRoachRaceCloudSpawnerController = game::ui::arcade::RoachRaceCloudSpawnerController;
} // namespace RED4ext

// clang-format on
