#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ISystemConditionType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/VisionModeType.hpp>

namespace RED4ext
{
namespace quest
{
struct VisionMode_ConditionType : quest::ISystemConditionType
{
    static constexpr const char* NAME = "questVisionMode_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    float timeInterval; // 34
    quest::VisionModeType visionModeType; // 38
    uint8_t unk3C[0x40 - 0x3C]; // 3C
#else
    float timeInterval; // 38
    quest::VisionModeType visionModeType; // 3C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(VisionMode_ConditionType, 0x40);
RED4EXT_ASSERT_OFFSET(VisionMode_ConditionType, timeInterval, 0x34);
RED4EXT_ASSERT_OFFSET(VisionMode_ConditionType, visionModeType, 0x38);
#else
RED4EXT_ASSERT_SIZE(VisionMode_ConditionType, 0x40);
#endif
} // namespace quest
using questVisionMode_ConditionType = quest::VisionMode_ConditionType;
} // namespace RED4ext

// clang-format on
