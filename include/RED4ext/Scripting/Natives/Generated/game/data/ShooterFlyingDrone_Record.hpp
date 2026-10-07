#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/ShooterProjectileAI_Record.hpp>

namespace RED4ext
{
namespace game::data
{
struct ShooterFlyingDrone_Record : game::data::ShooterProjectileAI_Record
{
    static constexpr const char* NAME = "gamedataShooterFlyingDrone_Record";
    static constexpr const char* ALIAS = "ShooterFlyingDrone_Record";

#ifdef __APPLE__
    uint8_t unk100[0x120 - 0x100]; // 100
#else
    uint8_t unk108[0x130 - 0x108]; // 108
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ShooterFlyingDrone_Record, 0x120);
#else
RED4EXT_ASSERT_SIZE(ShooterFlyingDrone_Record, 0x130);
#endif
} // namespace game::data
using gamedataShooterFlyingDrone_Record = game::data::ShooterFlyingDrone_Record;
using ShooterFlyingDrone_Record = game::data::ShooterFlyingDrone_Record;
} // namespace RED4ext

// clang-format on
