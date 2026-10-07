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
struct FindClosestPointOnPathTaskDefinition : AI::behavior::TaskDefinition
{
    static constexpr const char* NAME = "AIbehaviorFindClosestPointOnPathTaskDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk31[0x38 - 0x31]; // 31
    Handle<AI::ArgumentMapping> path; // 38
    Handle<AI::ArgumentMapping> forceStartFromClosest; // 48
    Handle<AI::ArgumentMapping> patrolProgress; // 58
    Handle<AI::ArgumentMapping> positionOnPath; // 68
    Handle<AI::ArgumentMapping> entryTangent; // 78
#else
    Handle<AI::ArgumentMapping> path; // 38
    Handle<AI::ArgumentMapping> forceStartFromClosest; // 48
    Handle<AI::ArgumentMapping> patrolProgress; // 58
    Handle<AI::ArgumentMapping> positionOnPath; // 68
    Handle<AI::ArgumentMapping> entryTangent; // 78
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(FindClosestPointOnPathTaskDefinition, 0x88);
RED4EXT_ASSERT_OFFSET(FindClosestPointOnPathTaskDefinition, path, 0x38);
RED4EXT_ASSERT_OFFSET(FindClosestPointOnPathTaskDefinition, forceStartFromClosest, 0x48);
RED4EXT_ASSERT_OFFSET(FindClosestPointOnPathTaskDefinition, patrolProgress, 0x58);
RED4EXT_ASSERT_OFFSET(FindClosestPointOnPathTaskDefinition, positionOnPath, 0x68);
RED4EXT_ASSERT_OFFSET(FindClosestPointOnPathTaskDefinition, entryTangent, 0x78);
#else
RED4EXT_ASSERT_SIZE(FindClosestPointOnPathTaskDefinition, 0x88);
#endif
} // namespace AI::behavior
using AIbehaviorFindClosestPointOnPathTaskDefinition = AI::behavior::FindClosestPointOnPathTaskDefinition;
} // namespace RED4ext

// clang-format on
