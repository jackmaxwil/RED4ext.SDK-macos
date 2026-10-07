#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/behavior/TaskDefinition.hpp>

namespace RED4ext
{
namespace AI { struct ArgumentMapping; }
namespace AI::behavior { struct MovementPolicyTaskItemDefinition; }

namespace AI::behavior
{
struct MovementPolicyTaskDefinition : AI::behavior::TaskDefinition
{
    static constexpr const char* NAME = "AIbehaviorMovementPolicyTaskDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool useCurrentPolicy; // 31
    bool waitForPolicy; // 32
    uint8_t unk33[0x38 - 0x33]; // 33
    Handle<AI::ArgumentMapping> stopWhenDestinationReached; // 38
    DynArray<Handle<AI::behavior::MovementPolicyTaskItemDefinition>> policies; // 48
#else
    bool useCurrentPolicy; // 38
    bool waitForPolicy; // 39
    uint8_t unk3A[0x40 - 0x3A]; // 3A
    Handle<AI::ArgumentMapping> stopWhenDestinationReached; // 40
    DynArray<Handle<AI::behavior::MovementPolicyTaskItemDefinition>> policies; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MovementPolicyTaskDefinition, 0x58);
RED4EXT_ASSERT_OFFSET(MovementPolicyTaskDefinition, useCurrentPolicy, 0x31);
RED4EXT_ASSERT_OFFSET(MovementPolicyTaskDefinition, waitForPolicy, 0x32);
RED4EXT_ASSERT_OFFSET(MovementPolicyTaskDefinition, stopWhenDestinationReached, 0x38);
RED4EXT_ASSERT_OFFSET(MovementPolicyTaskDefinition, policies, 0x48);
#else
RED4EXT_ASSERT_SIZE(MovementPolicyTaskDefinition, 0x60);
#endif
} // namespace AI::behavior
using AIbehaviorMovementPolicyTaskDefinition = AI::behavior::MovementPolicyTaskDefinition;
} // namespace RED4ext

// clang-format on
