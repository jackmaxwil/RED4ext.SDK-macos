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
struct ShooterAI_Record : game::data::ShooterObject_Record
{
    static constexpr const char* NAME = "gamedataShooterAI_Record";
    static constexpr const char* ALIAS = "ShooterAI_Record";

#ifdef __APPLE__
    uint8_t unkA8[0xF0 - 0xA8]; // A8
#else
    uint8_t unkB0[0xF8 - 0xB0]; // B0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ShooterAI_Record, 0xF0);
#else
RED4EXT_ASSERT_SIZE(ShooterAI_Record, 0xF8);
#endif
} // namespace game::data
using gamedataShooterAI_Record = game::data::ShooterAI_Record;
using ShooterAI_Record = game::data::ShooterAI_Record;
} // namespace RED4ext

// clang-format on
