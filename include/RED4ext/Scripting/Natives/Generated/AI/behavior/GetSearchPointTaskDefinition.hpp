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
struct GetSearchPointTaskDefinition : AI::behavior::TaskDefinition
{
    static constexpr const char* NAME = "AIbehaviorGetSearchPointTaskDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk31[0x38 - 0x31]; // 31
    Handle<AI::ArgumentMapping> inPlayerPositionDelay; // 38
    Handle<AI::ArgumentMapping> inSearchPositionMaxRadius; // 48
    Handle<AI::ArgumentMapping> inNearestNavmeshPolyExtent; // 58
    Handle<AI::ArgumentMapping> inPavementsOnly; // 68
    Handle<AI::ArgumentMapping> inLastKnownPosition; // 78
    Handle<AI::ArgumentMapping> outSearchPosition; // 88
#else
    Handle<AI::ArgumentMapping> inPlayerPositionDelay; // 38
    Handle<AI::ArgumentMapping> inSearchPositionMaxRadius; // 48
    Handle<AI::ArgumentMapping> inNearestNavmeshPolyExtent; // 58
    Handle<AI::ArgumentMapping> inPavementsOnly; // 68
    Handle<AI::ArgumentMapping> inLastKnownPosition; // 78
    Handle<AI::ArgumentMapping> outSearchPosition; // 88
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(GetSearchPointTaskDefinition, 0x98);
RED4EXT_ASSERT_OFFSET(GetSearchPointTaskDefinition, inPlayerPositionDelay, 0x38);
RED4EXT_ASSERT_OFFSET(GetSearchPointTaskDefinition, inSearchPositionMaxRadius, 0x48);
RED4EXT_ASSERT_OFFSET(GetSearchPointTaskDefinition, inNearestNavmeshPolyExtent, 0x58);
RED4EXT_ASSERT_OFFSET(GetSearchPointTaskDefinition, inPavementsOnly, 0x68);
RED4EXT_ASSERT_OFFSET(GetSearchPointTaskDefinition, inLastKnownPosition, 0x78);
RED4EXT_ASSERT_OFFSET(GetSearchPointTaskDefinition, outSearchPosition, 0x88);
#else
RED4EXT_ASSERT_SIZE(GetSearchPointTaskDefinition, 0x98);
#endif
} // namespace AI::behavior
using AIbehaviorGetSearchPointTaskDefinition = AI::behavior::GetSearchPointTaskDefinition;
} // namespace RED4ext

// clang-format on
