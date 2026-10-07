#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ISystemConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct Weather_ConditionType : quest::ISystemConditionType
{
    static constexpr const char* NAME = "questWeather_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    CName weather; // 38
    bool inverted; // 40
    uint8_t unk41[0x48 - 0x41]; // 41
#else
    CName weather; // 38
    bool inverted; // 40
    uint8_t unk41[0x48 - 0x41]; // 41
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(Weather_ConditionType, 0x48);
RED4EXT_ASSERT_OFFSET(Weather_ConditionType, weather, 0x38);
RED4EXT_ASSERT_OFFSET(Weather_ConditionType, inverted, 0x40);
#else
RED4EXT_ASSERT_SIZE(Weather_ConditionType, 0x48);
#endif
} // namespace quest
using questWeather_ConditionType = quest::Weather_ConditionType;
} // namespace RED4ext

// clang-format on
