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
struct CommandConditionDefinition : AI::behavior::ConditionDefinition
{
    static constexpr const char* NAME = "AIbehaviorCommandConditionDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    Handle<AI::ArgumentMapping> commandName; // 38
    Handle<AI::ArgumentMapping> commandOut; // 48
    bool useInheritance; // 58
    bool isWaiting; // 59
    bool isExecuting; // 5A
    uint8_t unk5B[0x60 - 0x5B]; // 5B
#else
    Handle<AI::ArgumentMapping> commandName; // 38
    Handle<AI::ArgumentMapping> commandOut; // 48
    bool useInheritance; // 58
    bool isWaiting; // 59
    bool isExecuting; // 5A
    uint8_t unk5B[0x60 - 0x5B]; // 5B
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CommandConditionDefinition, 0x60);
RED4EXT_ASSERT_OFFSET(CommandConditionDefinition, commandName, 0x38);
RED4EXT_ASSERT_OFFSET(CommandConditionDefinition, commandOut, 0x48);
RED4EXT_ASSERT_OFFSET(CommandConditionDefinition, useInheritance, 0x58);
RED4EXT_ASSERT_OFFSET(CommandConditionDefinition, isWaiting, 0x59);
RED4EXT_ASSERT_OFFSET(CommandConditionDefinition, isExecuting, 0x5A);
#else
RED4EXT_ASSERT_SIZE(CommandConditionDefinition, 0x60);
#endif
} // namespace AI::behavior
using AIbehaviorCommandConditionDefinition = AI::behavior::CommandConditionDefinition;
} // namespace RED4ext

// clang-format on
