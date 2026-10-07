#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/behavior/ConditionDefinition.hpp>

namespace RED4ext
{
namespace AI { struct ArgumentMapping; }

namespace AI::behavior
{
struct InstantJoinTrafficConditionDefinition : AI::behavior::ConditionDefinition
{
    static constexpr const char* NAME = "AIbehaviorInstantJoinTrafficConditionDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    Handle<AI::ArgumentMapping> joinTrafficSettings; // 38
    Handle<AI::ArgumentMapping> closestPointOnPath; // 48
    Handle<AI::ArgumentMapping> pathDirection; // 58
    Handle<AI::ArgumentMapping> runOnTraffic; // 68
#else
    Handle<AI::ArgumentMapping> joinTrafficSettings; // 38
    Handle<AI::ArgumentMapping> closestPointOnPath; // 48
    Handle<AI::ArgumentMapping> pathDirection; // 58
    Handle<AI::ArgumentMapping> runOnTraffic; // 68
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(InstantJoinTrafficConditionDefinition, 0x78);
RED4EXT_ASSERT_OFFSET(InstantJoinTrafficConditionDefinition, joinTrafficSettings, 0x38);
RED4EXT_ASSERT_OFFSET(InstantJoinTrafficConditionDefinition, closestPointOnPath, 0x48);
RED4EXT_ASSERT_OFFSET(InstantJoinTrafficConditionDefinition, pathDirection, 0x58);
RED4EXT_ASSERT_OFFSET(InstantJoinTrafficConditionDefinition, runOnTraffic, 0x68);
#else
RED4EXT_ASSERT_SIZE(InstantJoinTrafficConditionDefinition, 0x78);
#endif
} // namespace AI::behavior
using AIbehaviorInstantJoinTrafficConditionDefinition = AI::behavior::InstantJoinTrafficConditionDefinition;
} // namespace RED4ext

// clang-format on
