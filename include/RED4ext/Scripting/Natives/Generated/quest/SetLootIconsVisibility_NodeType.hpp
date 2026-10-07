#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIManagerNodeType.hpp>

namespace RED4ext
{
namespace quest
{
struct SetLootIconsVisibility_NodeType : quest::IUIManagerNodeType
{
    static constexpr const char* NAME = "questSetLootIconsVisibility_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool lootIconsVisible; // 34
    uint8_t unk35[0x38 - 0x35]; // 35
#else
    bool lootIconsVisible; // 38
    uint8_t unk39[0x40 - 0x39]; // 39
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SetLootIconsVisibility_NodeType, 0x38);
RED4EXT_ASSERT_OFFSET(SetLootIconsVisibility_NodeType, lootIconsVisible, 0x34);
#else
RED4EXT_ASSERT_SIZE(SetLootIconsVisibility_NodeType, 0x40);
#endif
} // namespace quest
using questSetLootIconsVisibility_NodeType = quest::SetLootIconsVisibility_NodeType;
} // namespace RED4ext

// clang-format on
