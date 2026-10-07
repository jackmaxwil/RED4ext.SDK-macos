#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/CustomQuestNotificationData.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIManagerNodeType.hpp>

namespace RED4ext
{
namespace quest
{
struct ShowCustomQuestNotification_NodeType : quest::IUIManagerNodeType
{
    static constexpr const char* NAME = "questShowCustomQuestNotification_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    quest::CustomQuestNotificationData customQuestNotificationData; // 38
#else
    quest::CustomQuestNotificationData customQuestNotificationData; // 38
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ShowCustomQuestNotification_NodeType, 0xA0);
RED4EXT_ASSERT_OFFSET(ShowCustomQuestNotification_NodeType, customQuestNotificationData, 0x38);
#else
RED4EXT_ASSERT_SIZE(ShowCustomQuestNotification_NodeType, 0xA0);
#endif
} // namespace quest
using questShowCustomQuestNotification_NodeType = quest::ShowCustomQuestNotification_NodeType;
} // namespace RED4ext

// clang-format on
