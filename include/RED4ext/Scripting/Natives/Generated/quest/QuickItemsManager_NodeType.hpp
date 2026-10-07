#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIManagerNodeType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/QuickItemsSet.hpp>

namespace RED4ext
{
namespace quest
{
struct QuickItemsManager_NodeType : quest::IUIManagerNodeType
{
    static constexpr const char* NAME = "questQuickItemsManager_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    quest::QuickItemsSet set; // 34
#else
    quest::QuickItemsSet set; // 38
    uint8_t unk3C[0x40 - 0x3C]; // 3C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(QuickItemsManager_NodeType, 0x38);
RED4EXT_ASSERT_OFFSET(QuickItemsManager_NodeType, set, 0x34);
#else
RED4EXT_ASSERT_SIZE(QuickItemsManager_NodeType, 0x40);
#endif
} // namespace quest
using questQuickItemsManager_NodeType = quest::QuickItemsManager_NodeType;
} // namespace RED4ext

// clang-format on
