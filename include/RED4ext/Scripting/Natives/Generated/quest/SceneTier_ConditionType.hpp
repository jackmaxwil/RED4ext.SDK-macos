#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/GameplayTier.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ISceneConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct SceneTier_ConditionType : quest::ISceneConditionType
{
    static constexpr const char* NAME = "questSceneTier_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    GameplayTier tier; // 34
    bool isInverted; // 38
    uint8_t unk39[0x40 - 0x39]; // 39
#else
    GameplayTier tier; // 38
    bool isInverted; // 3C
    uint8_t unk3D[0x40 - 0x3D]; // 3D
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SceneTier_ConditionType, 0x40);
RED4EXT_ASSERT_OFFSET(SceneTier_ConditionType, tier, 0x34);
RED4EXT_ASSERT_OFFSET(SceneTier_ConditionType, isInverted, 0x38);
#else
RED4EXT_ASSERT_SIZE(SceneTier_ConditionType, 0x40);
#endif
} // namespace quest
using questSceneTier_ConditionType = quest::SceneTier_ConditionType;
} // namespace RED4ext

// clang-format on
