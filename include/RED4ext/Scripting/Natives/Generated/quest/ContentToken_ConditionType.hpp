#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IContentConditionType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/QuestContentType.hpp>

namespace RED4ext
{
namespace quest
{
struct ContentToken_ConditionType : quest::IContentConditionType
{
    static constexpr const char* NAME = "questContentToken_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    quest::QuestContentType type; // 34
    uint8_t unk35[0x38 - 0x35]; // 35
#else
    quest::QuestContentType type; // 38
    uint8_t unk39[0x40 - 0x39]; // 39
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ContentToken_ConditionType, 0x38);
RED4EXT_ASSERT_OFFSET(ContentToken_ConditionType, type, 0x34);
#else
RED4EXT_ASSERT_SIZE(ContentToken_ConditionType, 0x40);
#endif
} // namespace quest
using questContentToken_ConditionType = quest::ContentToken_ConditionType;
} // namespace RED4ext

// clang-format on
