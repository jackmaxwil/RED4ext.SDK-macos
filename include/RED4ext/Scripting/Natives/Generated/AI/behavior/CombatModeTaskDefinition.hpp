#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/behavior/CombatModes.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/behavior/TaskDefinition.hpp>

namespace RED4ext
{
namespace AI::behavior
{
struct CombatModeTaskDefinition : AI::behavior::TaskDefinition
{
    static constexpr const char* NAME = "AIbehaviorCombatModeTaskDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    AI::behavior::CombatModes mode; // 31
    uint8_t unk32[0x34 - 0x32]; // 32
    int32_t priority; // 34
    float timeToLive; // 38
    uint8_t unk3C[0x40 - 0x3C]; // 3C
#else
    AI::behavior::CombatModes mode; // 38
    uint8_t unk39[0x3C - 0x39]; // 39
    int32_t priority; // 3C
    float timeToLive; // 40
    uint8_t unk44[0x48 - 0x44]; // 44
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CombatModeTaskDefinition, 0x40);
RED4EXT_ASSERT_OFFSET(CombatModeTaskDefinition, mode, 0x31);
RED4EXT_ASSERT_OFFSET(CombatModeTaskDefinition, priority, 0x34);
RED4EXT_ASSERT_OFFSET(CombatModeTaskDefinition, timeToLive, 0x38);
#else
RED4EXT_ASSERT_SIZE(CombatModeTaskDefinition, 0x48);
#endif
} // namespace AI::behavior
using AIbehaviorCombatModeTaskDefinition = AI::behavior::CombatModeTaskDefinition;
} // namespace RED4ext

// clang-format on
