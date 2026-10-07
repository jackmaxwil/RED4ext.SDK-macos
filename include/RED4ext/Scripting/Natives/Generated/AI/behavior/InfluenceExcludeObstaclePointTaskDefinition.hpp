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
struct InfluenceExcludeObstaclePointTaskDefinition : AI::behavior::TaskDefinition
{
    static constexpr const char* NAME = "AIbehaviorInfluenceExcludeObstaclePointTaskDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk31[0x38 - 0x31]; // 31
    Handle<AI::ArgumentMapping> workspotData; // 38
    Handle<AI::ArgumentMapping> mountData; // 48
#else
    Handle<AI::ArgumentMapping> workspotData; // 38
    Handle<AI::ArgumentMapping> mountData; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(InfluenceExcludeObstaclePointTaskDefinition, 0x58);
RED4EXT_ASSERT_OFFSET(InfluenceExcludeObstaclePointTaskDefinition, workspotData, 0x38);
RED4EXT_ASSERT_OFFSET(InfluenceExcludeObstaclePointTaskDefinition, mountData, 0x48);
#else
RED4EXT_ASSERT_SIZE(InfluenceExcludeObstaclePointTaskDefinition, 0x58);
#endif
} // namespace AI::behavior
using AIbehaviorInfluenceExcludeObstaclePointTaskDefinition = AI::behavior::InfluenceExcludeObstaclePointTaskDefinition;
} // namespace RED4ext

// clang-format on
