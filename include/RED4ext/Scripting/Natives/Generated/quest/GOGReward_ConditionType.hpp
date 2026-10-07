#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ISystemConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct GOGReward_ConditionType : quest::ISystemConditionType
{
    static constexpr const char* NAME = "questGOGReward_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    TweakDBID rewardRecordId; // 34
    uint8_t unk3C[0x40 - 0x3C]; // 3C
#else
    TweakDBID rewardRecordId; // 38
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(GOGReward_ConditionType, 0x40);
RED4EXT_ASSERT_OFFSET(GOGReward_ConditionType, rewardRecordId, 0x34);
#else
RED4EXT_ASSERT_SIZE(GOGReward_ConditionType, 0x40);
#endif
} // namespace quest
using questGOGReward_ConditionType = quest::GOGReward_ConditionType;
} // namespace RED4ext

// clang-format on
