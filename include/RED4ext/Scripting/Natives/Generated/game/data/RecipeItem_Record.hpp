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
struct RecipeItem_Record : game::data::Item_Record
{
    static constexpr const char* NAME = "gamedataRecipeItem_Record";
    static constexpr const char* ALIAS = "RecipeItem_Record";

#ifdef __APPLE__
    uint8_t unk480[0x490 - 0x480]; // 480
#else
    uint8_t unk488[0x498 - 0x488]; // 488
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(RecipeItem_Record, 0x490);
#else
RED4EXT_ASSERT_SIZE(RecipeItem_Record, 0x498);
#endif
} // namespace game::data
using gamedataRecipeItem_Record = game::data::RecipeItem_Record;
using RecipeItem_Record = game::data::RecipeItem_Record;
} // namespace RED4ext

// clang-format on
