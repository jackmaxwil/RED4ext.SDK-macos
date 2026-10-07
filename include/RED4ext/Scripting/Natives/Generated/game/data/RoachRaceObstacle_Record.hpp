#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/RoachRaceObject_Record.hpp>

namespace RED4ext
{
namespace game::data
{
struct RoachRaceObstacle_Record : game::data::RoachRaceObject_Record
{
    static constexpr const char* NAME = "gamedataRoachRaceObstacle_Record";
    static constexpr const char* ALIAS = "RoachRaceObstacle_Record";

#ifdef __APPLE__
    uint8_t unkD8[0x108 - 0xD8]; // D8
#else
    uint8_t unkE0[0x110 - 0xE0]; // E0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(RoachRaceObstacle_Record, 0x108);
#else
RED4EXT_ASSERT_SIZE(RoachRaceObstacle_Record, 0x110);
#endif
} // namespace game::data
using gamedataRoachRaceObstacle_Record = game::data::RoachRaceObstacle_Record;
using RoachRaceObstacle_Record = game::data::RoachRaceObstacle_Record;
} // namespace RED4ext

// clang-format on
