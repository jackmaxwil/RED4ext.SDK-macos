#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/GameTime.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ITimeConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct TimePeriod_ConditionType : quest::ITimeConditionType
{
    static constexpr const char* NAME = "questTimePeriod_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    GameTime begin; // 34
    GameTime end; // 38
    uint8_t unk3C[0x40 - 0x3C]; // 3C
#else
    GameTime begin; // 38
    GameTime end; // 3C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TimePeriod_ConditionType, 0x40);
RED4EXT_ASSERT_OFFSET(TimePeriod_ConditionType, begin, 0x34);
RED4EXT_ASSERT_OFFSET(TimePeriod_ConditionType, end, 0x38);
#else
RED4EXT_ASSERT_SIZE(TimePeriod_ConditionType, 0x40);
#endif
} // namespace quest
using questTimePeriod_ConditionType = quest::TimePeriod_ConditionType;
} // namespace RED4ext

// clang-format on
