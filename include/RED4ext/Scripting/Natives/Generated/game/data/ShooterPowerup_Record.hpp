#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/ShooterObject_Record.hpp>

namespace RED4ext
{
namespace game::data
{
struct ShooterPowerup_Record : game::data::ShooterObject_Record
{
    static constexpr const char* NAME = "gamedataShooterPowerup_Record";
    static constexpr const char* ALIAS = "ShooterPowerup_Record";

#ifdef __APPLE__
    uint8_t unkA8[0xD8 - 0xA8]; // A8
#else
    uint8_t unkB0[0xE0 - 0xB0]; // B0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ShooterPowerup_Record, 0xD8);
#else
RED4EXT_ASSERT_SIZE(ShooterPowerup_Record, 0xE0);
#endif
} // namespace game::data
using gamedataShooterPowerup_Record = game::data::ShooterPowerup_Record;
using ShooterPowerup_Record = game::data::ShooterPowerup_Record;
} // namespace RED4ext

// clang-format on
