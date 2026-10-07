#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/behavior/TaskDefinition.hpp>

namespace RED4ext
{
namespace AI { struct ArgumentMapping; }

namespace AI::behavior
{
struct GetPatrolPointTaskDefinition : AI::behavior::TaskDefinition
{
    static constexpr const char* NAME = "AIbehaviorGetPatrolPointTaskDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk31[0x38 - 0x31]; // 31
    Handle<AI::ArgumentMapping> inPatrolDistance; // 38
    Handle<AI::ArgumentMapping> inLastKnownPosition; // 48
    Handle<AI::ArgumentMapping> outFollowTrailPoint; // 58
#else
    Handle<AI::ArgumentMapping> inPatrolDistance; // 38
    Handle<AI::ArgumentMapping> inLastKnownPosition; // 48
    Handle<AI::ArgumentMapping> outFollowTrailPoint; // 58
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(GetPatrolPointTaskDefinition, 0x68);
RED4EXT_ASSERT_OFFSET(GetPatrolPointTaskDefinition, inPatrolDistance, 0x38);
RED4EXT_ASSERT_OFFSET(GetPatrolPointTaskDefinition, inLastKnownPosition, 0x48);
RED4EXT_ASSERT_OFFSET(GetPatrolPointTaskDefinition, outFollowTrailPoint, 0x58);
#else
RED4EXT_ASSERT_SIZE(GetPatrolPointTaskDefinition, 0x68);
#endif
} // namespace AI::behavior
using AIbehaviorGetPatrolPointTaskDefinition = AI::behavior::GetPatrolPointTaskDefinition;
} // namespace RED4ext

// clang-format on
