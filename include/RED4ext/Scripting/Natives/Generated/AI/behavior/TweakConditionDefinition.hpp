#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/behavior/ConditionDefinition.hpp>

namespace RED4ext
{
namespace AI::behavior
{
struct TweakConditionDefinition : AI::behavior::ConditionDefinition
{
    static constexpr const char* NAME = "AIbehaviorTweakConditionDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    TweakDBID recordId; // 34
    uint8_t unk3C[0x40 - 0x3C]; // 3C
#else
    TweakDBID recordId; // 38
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TweakConditionDefinition, 0x40);
RED4EXT_ASSERT_OFFSET(TweakConditionDefinition, recordId, 0x34);
#else
RED4EXT_ASSERT_SIZE(TweakConditionDefinition, 0x40);
#endif
} // namespace AI::behavior
using AIbehaviorTweakConditionDefinition = AI::behavior::TweakConditionDefinition;
} // namespace RED4ext

// clang-format on
