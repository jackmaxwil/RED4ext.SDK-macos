#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/behavior/ConditionDefinition.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/behavior/StoryActionType.hpp>

namespace RED4ext
{
namespace AI::behavior
{
struct StoryActionConditionDefinition : AI::behavior::ConditionDefinition
{
    static constexpr const char* NAME = "AIbehaviorStoryActionConditionDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    AI::behavior::StoryActionType action; // 34
#else
    AI::behavior::StoryActionType action; // 38
    uint8_t unk3C[0x40 - 0x3C]; // 3C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(StoryActionConditionDefinition, 0x38);
RED4EXT_ASSERT_OFFSET(StoryActionConditionDefinition, action, 0x34);
#else
RED4EXT_ASSERT_SIZE(StoryActionConditionDefinition, 0x40);
#endif
} // namespace AI::behavior
using AIbehaviorStoryActionConditionDefinition = AI::behavior::StoryActionConditionDefinition;
} // namespace RED4ext

// clang-format on
