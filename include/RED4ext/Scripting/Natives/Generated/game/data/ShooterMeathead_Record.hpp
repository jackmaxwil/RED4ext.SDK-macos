#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/ShooterBossAI_Record.hpp>

namespace RED4ext
{
namespace game::data
{
struct ShooterMeathead_Record : game::data::ShooterBossAI_Record
{
    static constexpr const char* NAME = "gamedataShooterMeathead_Record";
    static constexpr const char* ALIAS = "ShooterMeathead_Record";

#ifdef __APPLE__
    uint8_t unk108[0x1C0 - 0x108]; // 108
#else
    uint8_t unk110[0x1C8 - 0x110]; // 110
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ShooterMeathead_Record, 0x1C0);
#else
RED4EXT_ASSERT_SIZE(ShooterMeathead_Record, 0x1C8);
#endif
} // namespace game::data
using gamedataShooterMeathead_Record = game::data::ShooterMeathead_Record;
using ShooterMeathead_Record = game::data::ShooterMeathead_Record;
} // namespace RED4ext

// clang-format on
