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
struct IsThreatOnPathConditionDefinition : AI::behavior::ConditionDefinition
{
    static constexpr const char* NAME = "AIbehaviorIsThreatOnPathConditionDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    Handle<AI::ArgumentMapping> threatObject; // 38
    Handle<AI::ArgumentMapping> threatRadius; // 48
#else
    Handle<AI::ArgumentMapping> threatObject; // 38
    Handle<AI::ArgumentMapping> threatRadius; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(IsThreatOnPathConditionDefinition, 0x58);
RED4EXT_ASSERT_OFFSET(IsThreatOnPathConditionDefinition, threatObject, 0x38);
RED4EXT_ASSERT_OFFSET(IsThreatOnPathConditionDefinition, threatRadius, 0x48);
#else
RED4EXT_ASSERT_SIZE(IsThreatOnPathConditionDefinition, 0x58);
#endif
} // namespace AI::behavior
using AIbehaviorIsThreatOnPathConditionDefinition = AI::behavior::IsThreatOnPathConditionDefinition;
} // namespace RED4ext

// clang-format on
