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
struct CheckLineOfFireTaskDefinition : AI::behavior::TaskDefinition
{
    static constexpr const char* NAME = "AIbehaviorCheckLineOfFireTaskDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk31[0x38 - 0x31]; // 31
    Handle<AI::ArgumentMapping> slotName; // 38
    Handle<AI::ArgumentMapping> attachmentName; // 48
    Handle<AI::ArgumentMapping> spread; // 58
    Handle<AI::ArgumentMapping> maxRange; // 68
#else
    Handle<AI::ArgumentMapping> slotName; // 38
    Handle<AI::ArgumentMapping> attachmentName; // 48
    Handle<AI::ArgumentMapping> spread; // 58
    Handle<AI::ArgumentMapping> maxRange; // 68
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CheckLineOfFireTaskDefinition, 0x78);
RED4EXT_ASSERT_OFFSET(CheckLineOfFireTaskDefinition, slotName, 0x38);
RED4EXT_ASSERT_OFFSET(CheckLineOfFireTaskDefinition, attachmentName, 0x48);
RED4EXT_ASSERT_OFFSET(CheckLineOfFireTaskDefinition, spread, 0x58);
RED4EXT_ASSERT_OFFSET(CheckLineOfFireTaskDefinition, maxRange, 0x68);
#else
RED4EXT_ASSERT_SIZE(CheckLineOfFireTaskDefinition, 0x78);
#endif
} // namespace AI::behavior
using AIbehaviorCheckLineOfFireTaskDefinition = AI::behavior::CheckLineOfFireTaskDefinition;
} // namespace RED4ext

// clang-format on
