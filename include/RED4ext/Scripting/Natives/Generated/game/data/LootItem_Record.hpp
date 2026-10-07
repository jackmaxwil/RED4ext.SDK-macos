#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/LootTableElement_Record.hpp>

namespace RED4ext
{
namespace game::data
{
struct LootItem_Record : game::data::LootTableElement_Record
{
    static constexpr const char* NAME = "gamedataLootItem_Record";
    static constexpr const char* ALIAS = "LootItem_Record";

#ifdef __APPLE__
    uint8_t unkA0[0xA8 - 0xA0]; // A0
#else
    uint8_t unkA0[0xB0 - 0xA0]; // A0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(LootItem_Record, 0xA8);
#else
RED4EXT_ASSERT_SIZE(LootItem_Record, 0xB0);
#endif
} // namespace game::data
using gamedataLootItem_Record = game::data::LootItem_Record;
using LootItem_Record = game::data::LootItem_Record;
} // namespace RED4ext

// clang-format on
