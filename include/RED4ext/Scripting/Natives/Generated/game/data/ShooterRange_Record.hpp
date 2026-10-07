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
struct ShooterRange_Record : game::data::ShooterProjectileAI_Record
{
    static constexpr const char* NAME = "gamedataShooterRange_Record";
    static constexpr const char* ALIAS = "ShooterRange_Record";

#ifdef __APPLE__
    uint8_t unk100[0x168 - 0x100]; // 100
#else
    uint8_t unk108[0x178 - 0x108]; // 108
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ShooterRange_Record, 0x168);
#else
RED4EXT_ASSERT_SIZE(ShooterRange_Record, 0x178);
#endif
} // namespace game::data
using gamedataShooterRange_Record = game::data::ShooterRange_Record;
using ShooterRange_Record = game::data::ShooterRange_Record;
} // namespace RED4ext

// clang-format on
