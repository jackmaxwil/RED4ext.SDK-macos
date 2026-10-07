#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/ArcadeCollidableObject_Record.hpp>

namespace RED4ext
{
namespace game::data
{
struct TankPickup_Record : game::data::ArcadeCollidableObject_Record
{
    static constexpr const char* NAME = "gamedataTankPickup_Record";
    static constexpr const char* ALIAS = "TankPickup_Record";

#ifdef __APPLE__
    uint8_t unk90[0xA8 - 0x90]; // 90
#else
    uint8_t unk98[0xB0 - 0x98]; // 98
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TankPickup_Record, 0xA8);
#else
RED4EXT_ASSERT_SIZE(TankPickup_Record, 0xB0);
#endif
} // namespace game::data
using gamedataTankPickup_Record = game::data::TankPickup_Record;
using TankPickup_Record = game::data::TankPickup_Record;
} // namespace RED4ext

// clang-format on
