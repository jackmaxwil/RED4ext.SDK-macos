#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IContentConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct ContentLock_ConditionType : quest::IContentConditionType
{
    static constexpr const char* NAME = "questContentLock_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool isContentBlocked; // 34
    uint8_t unk35[0x38 - 0x35]; // 35
#else
    bool isContentBlocked; // 38
    uint8_t unk39[0x40 - 0x39]; // 39
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ContentLock_ConditionType, 0x38);
RED4EXT_ASSERT_OFFSET(ContentLock_ConditionType, isContentBlocked, 0x34);
#else
RED4EXT_ASSERT_SIZE(ContentLock_ConditionType, 0x40);
#endif
} // namespace quest
using questContentLock_ConditionType = quest::ContentLock_ConditionType;
} // namespace RED4ext

// clang-format on
