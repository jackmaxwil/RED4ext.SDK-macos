#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIConditionType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/TimeSkipMode.hpp>

namespace RED4ext
{
namespace quest
{
struct TimeSkipped_ConditionType : quest::IUIConditionType
{
    static constexpr const char* NAME = "questTimeSkipped_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    quest::TimeSkipMode mode; // 34
    uint8_t unk35[0x38 - 0x35]; // 35
#else
    quest::TimeSkipMode mode; // 38
    uint8_t unk39[0x40 - 0x39]; // 39
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TimeSkipped_ConditionType, 0x38);
RED4EXT_ASSERT_OFFSET(TimeSkipped_ConditionType, mode, 0x34);
#else
RED4EXT_ASSERT_SIZE(TimeSkipped_ConditionType, 0x40);
#endif
} // namespace quest
using questTimeSkipped_ConditionType = quest::TimeSkipped_ConditionType;
} // namespace RED4ext

// clang-format on
