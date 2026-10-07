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
struct FindClosestPointOnTrafficPathTaskDefinition : AI::behavior::TaskDefinition
{
    static constexpr const char* NAME = "AIbehaviorFindClosestPointOnTrafficPathTaskDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk31[0x38 - 0x31]; // 31
    Handle<AI::ArgumentMapping> positionOnPath; // 38
    Handle<AI::ArgumentMapping> enterClosest; // 48
    Handle<AI::ArgumentMapping> pathDirection; // 58
    Handle<AI::ArgumentMapping> avoidedPosition; // 68
    Handle<AI::ArgumentMapping> useThreatPosAsAvoidedPos; // 78
    Handle<AI::ArgumentMapping> avoidedPositionDistance; // 88
    Handle<AI::ArgumentMapping> usePreviousPosition; // 98
    Handle<AI::ArgumentMapping> checkRoadIntersection; // A8
    Handle<AI::ArgumentMapping> joinTrafficSettings; // B8
    Handle<AI::ArgumentMapping> workspotData; // C8
#else
    Handle<AI::ArgumentMapping> positionOnPath; // 38
    Handle<AI::ArgumentMapping> enterClosest; // 48
    Handle<AI::ArgumentMapping> pathDirection; // 58
    Handle<AI::ArgumentMapping> avoidedPosition; // 68
    Handle<AI::ArgumentMapping> useThreatPosAsAvoidedPos; // 78
    Handle<AI::ArgumentMapping> avoidedPositionDistance; // 88
    Handle<AI::ArgumentMapping> usePreviousPosition; // 98
    Handle<AI::ArgumentMapping> checkRoadIntersection; // A8
    Handle<AI::ArgumentMapping> joinTrafficSettings; // B8
    Handle<AI::ArgumentMapping> workspotData; // C8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(FindClosestPointOnTrafficPathTaskDefinition, 0xD8);
RED4EXT_ASSERT_OFFSET(FindClosestPointOnTrafficPathTaskDefinition, positionOnPath, 0x38);
RED4EXT_ASSERT_OFFSET(FindClosestPointOnTrafficPathTaskDefinition, enterClosest, 0x48);
RED4EXT_ASSERT_OFFSET(FindClosestPointOnTrafficPathTaskDefinition, pathDirection, 0x58);
RED4EXT_ASSERT_OFFSET(FindClosestPointOnTrafficPathTaskDefinition, avoidedPosition, 0x68);
RED4EXT_ASSERT_OFFSET(FindClosestPointOnTrafficPathTaskDefinition, useThreatPosAsAvoidedPos, 0x78);
RED4EXT_ASSERT_OFFSET(FindClosestPointOnTrafficPathTaskDefinition, avoidedPositionDistance, 0x88);
RED4EXT_ASSERT_OFFSET(FindClosestPointOnTrafficPathTaskDefinition, usePreviousPosition, 0x98);
RED4EXT_ASSERT_OFFSET(FindClosestPointOnTrafficPathTaskDefinition, checkRoadIntersection, 0xA8);
RED4EXT_ASSERT_OFFSET(FindClosestPointOnTrafficPathTaskDefinition, joinTrafficSettings, 0xB8);
RED4EXT_ASSERT_OFFSET(FindClosestPointOnTrafficPathTaskDefinition, workspotData, 0xC8);
#else
RED4EXT_ASSERT_SIZE(FindClosestPointOnTrafficPathTaskDefinition, 0xD8);
#endif
} // namespace AI::behavior
using AIbehaviorFindClosestPointOnTrafficPathTaskDefinition = AI::behavior::FindClosestPointOnTrafficPathTaskDefinition;
} // namespace RED4ext

// clang-format on
