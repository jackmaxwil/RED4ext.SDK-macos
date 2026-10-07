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
struct AttachToElevatorCommandTaskDefinition : AI::behavior::TaskDefinition
{
    static constexpr const char* NAME = "AIbehaviorAttachToElevatorCommandTaskDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk31[0x38 - 0x31]; // 31
    Handle<AI::ArgumentMapping> command; // 38
#else
    Handle<AI::ArgumentMapping> command; // 38
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AttachToElevatorCommandTaskDefinition, 0x48);
RED4EXT_ASSERT_OFFSET(AttachToElevatorCommandTaskDefinition, command, 0x38);
#else
RED4EXT_ASSERT_SIZE(AttachToElevatorCommandTaskDefinition, 0x48);
#endif
} // namespace AI::behavior
using AIbehaviorAttachToElevatorCommandTaskDefinition = AI::behavior::AttachToElevatorCommandTaskDefinition;
} // namespace RED4ext

// clang-format on
