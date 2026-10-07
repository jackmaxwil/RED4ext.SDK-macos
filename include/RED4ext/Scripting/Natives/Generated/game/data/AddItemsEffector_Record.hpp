#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/Effector_Record.hpp>

namespace RED4ext
{
namespace game::data
{
struct AddItemsEffector_Record : game::data::Effector_Record
{
    static constexpr const char* NAME = "gamedataAddItemsEffector_Record";
    static constexpr const char* ALIAS = "AddItemsEffector_Record";

#ifdef __APPLE__
    uint8_t unk88[0x90 - 0x88]; // 88
#else
    uint8_t unk88[0x98 - 0x88]; // 88
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AddItemsEffector_Record, 0x90);
#else
RED4EXT_ASSERT_SIZE(AddItemsEffector_Record, 0x98);
#endif
} // namespace game::data
using gamedataAddItemsEffector_Record = game::data::AddItemsEffector_Record;
using AddItemsEffector_Record = game::data::AddItemsEffector_Record;
} // namespace RED4ext

// clang-format on
