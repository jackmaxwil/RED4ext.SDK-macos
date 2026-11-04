#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/Item_Record.hpp>

namespace RED4ext
{
namespace game::data
{
struct WeaponItem_Record : game::data::Item_Record
{
    static constexpr const char* NAME = "gamedataWeaponItem_Record";
    static constexpr const char* ALIAS = "WeaponItem_Record";

#ifdef __APPLE__
    uint8_t unk480[0x600 - 0x480]; // 480
#else
    uint8_t unk488[0x608 - 0x488]; // 488
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(WeaponItem_Record, 0x600);
#else
RED4EXT_ASSERT_SIZE(WeaponItem_Record, 0x608);
#endif
} // namespace game::data
using gamedataWeaponItem_Record = game::data::WeaponItem_Record;
using WeaponItem_Record = game::data::WeaponItem_Record;
} // namespace RED4ext

// clang-format on
