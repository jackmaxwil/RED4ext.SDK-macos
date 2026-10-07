#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ITimeConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct GameTimeDelay_ConditionType : quest::ITimeConditionType
{
    static constexpr const char* NAME = "questGameTimeDelay_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint32_t days; // 34
    uint32_t hours; // 38
    uint32_t minutes; // 3C
    uint32_t seconds; // 40
    uint8_t unk44[0x48 - 0x44]; // 44
#else
    uint32_t days; // 38
    uint32_t hours; // 3C
    uint32_t minutes; // 40
    uint32_t seconds; // 44
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(GameTimeDelay_ConditionType, 0x48);
RED4EXT_ASSERT_OFFSET(GameTimeDelay_ConditionType, days, 0x34);
RED4EXT_ASSERT_OFFSET(GameTimeDelay_ConditionType, hours, 0x38);
RED4EXT_ASSERT_OFFSET(GameTimeDelay_ConditionType, minutes, 0x3C);
RED4EXT_ASSERT_OFFSET(GameTimeDelay_ConditionType, seconds, 0x40);
#else
RED4EXT_ASSERT_SIZE(GameTimeDelay_ConditionType, 0x48);
#endif
} // namespace quest
using questGameTimeDelay_ConditionType = quest::GameTimeDelay_ConditionType;
} // namespace RED4ext

// clang-format on
