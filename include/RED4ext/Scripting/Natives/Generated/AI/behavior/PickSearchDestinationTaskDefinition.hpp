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
struct PickSearchDestinationTaskDefinition : AI::behavior::TaskDefinition
{
    static constexpr const char* NAME = "AIbehaviorPickSearchDestinationTaskDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk31[0x38 - 0x31]; // 31
    Handle<AI::ArgumentMapping> destinationPosition; // 38
    Handle<AI::ArgumentMapping> desiredDistance; // 48
    Handle<AI::ArgumentMapping> maxDistance; // 58
    Handle<AI::ArgumentMapping> clearedAreaRadius; // 68
    Handle<AI::ArgumentMapping> clearedAreaDistance; // 78
    Handle<AI::ArgumentMapping> clearedAreaAngle; // 88
    Handle<AI::ArgumentMapping> ignoreRestrictMovementArea; // 98
#else
    Handle<AI::ArgumentMapping> destinationPosition; // 38
    Handle<AI::ArgumentMapping> desiredDistance; // 48
    Handle<AI::ArgumentMapping> maxDistance; // 58
    Handle<AI::ArgumentMapping> clearedAreaRadius; // 68
    Handle<AI::ArgumentMapping> clearedAreaDistance; // 78
    Handle<AI::ArgumentMapping> clearedAreaAngle; // 88
    Handle<AI::ArgumentMapping> ignoreRestrictMovementArea; // 98
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PickSearchDestinationTaskDefinition, 0xA8);
RED4EXT_ASSERT_OFFSET(PickSearchDestinationTaskDefinition, destinationPosition, 0x38);
RED4EXT_ASSERT_OFFSET(PickSearchDestinationTaskDefinition, desiredDistance, 0x48);
RED4EXT_ASSERT_OFFSET(PickSearchDestinationTaskDefinition, maxDistance, 0x58);
RED4EXT_ASSERT_OFFSET(PickSearchDestinationTaskDefinition, clearedAreaRadius, 0x68);
RED4EXT_ASSERT_OFFSET(PickSearchDestinationTaskDefinition, clearedAreaDistance, 0x78);
RED4EXT_ASSERT_OFFSET(PickSearchDestinationTaskDefinition, clearedAreaAngle, 0x88);
RED4EXT_ASSERT_OFFSET(PickSearchDestinationTaskDefinition, ignoreRestrictMovementArea, 0x98);
#else
RED4EXT_ASSERT_SIZE(PickSearchDestinationTaskDefinition, 0xA8);
#endif
} // namespace AI::behavior
using AIbehaviorPickSearchDestinationTaskDefinition = AI::behavior::PickSearchDestinationTaskDefinition;
} // namespace RED4ext

// clang-format on
