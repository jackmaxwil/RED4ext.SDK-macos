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
struct TankProjectile_Record : game::data::ArcadeCollidableObject_Record
{
    static constexpr const char* NAME = "gamedataTankProjectile_Record";
    static constexpr const char* ALIAS = "TankProjectile_Record";

#ifdef __APPLE__
    uint8_t unk90[0xA8 - 0x90]; // 90
#else
    uint8_t unk98[0xB0 - 0x98]; // 98
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TankProjectile_Record, 0xA8);
#else
RED4EXT_ASSERT_SIZE(TankProjectile_Record, 0xB0);
#endif
} // namespace game::data
using gamedataTankProjectile_Record = game::data::TankProjectile_Record;
using TankProjectile_Record = game::data::TankProjectile_Record;
} // namespace RED4ext

// clang-format on
