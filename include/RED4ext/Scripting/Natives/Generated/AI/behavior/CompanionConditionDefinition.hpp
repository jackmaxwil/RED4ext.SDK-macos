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
struct CompanionConditionDefinition : AI::behavior::ConditionDefinition
{
    static constexpr const char* NAME = "AIbehaviorCompanionConditionDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    Handle<AI::ArgumentMapping> companion; // 38
    Handle<AI::ArgumentMapping> spline; // 48
#else
    Handle<AI::ArgumentMapping> companion; // 38
    Handle<AI::ArgumentMapping> spline; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CompanionConditionDefinition, 0x58);
RED4EXT_ASSERT_OFFSET(CompanionConditionDefinition, companion, 0x38);
RED4EXT_ASSERT_OFFSET(CompanionConditionDefinition, spline, 0x48);
#else
RED4EXT_ASSERT_SIZE(CompanionConditionDefinition, 0x58);
#endif
} // namespace AI::behavior
using AIbehaviorCompanionConditionDefinition = AI::behavior::CompanionConditionDefinition;
} // namespace RED4ext

// clang-format on
