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
struct AvoidPlayerTaskDefinition : AI::behavior::TaskDefinition
{
    static constexpr const char* NAME = "AIbehaviorAvoidPlayerTaskDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk31[0x38 - 0x31]; // 31
    Handle<AI::ArgumentMapping> threatRadius; // 38
#else
    Handle<AI::ArgumentMapping> threatRadius; // 38
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AvoidPlayerTaskDefinition, 0x48);
RED4EXT_ASSERT_OFFSET(AvoidPlayerTaskDefinition, threatRadius, 0x38);
#else
RED4EXT_ASSERT_SIZE(AvoidPlayerTaskDefinition, 0x48);
#endif
} // namespace AI::behavior
using AIbehaviorAvoidPlayerTaskDefinition = AI::behavior::AvoidPlayerTaskDefinition;
} // namespace RED4ext

// clang-format on
