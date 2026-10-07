#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/behavior/ConditionDefinition.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/StoryTier.hpp>

namespace RED4ext
{
namespace AI { struct ArgumentMapping; }

namespace AI::behavior
{
struct StoryTierConditionDefinition : AI::behavior::ConditionDefinition
{
    static constexpr const char* NAME = "AIbehaviorStoryTierConditionDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    Handle<AI::ArgumentMapping> storyTier; // 38
    game::StoryTier tier; // 48
    uint8_t unk49[0x50 - 0x49]; // 49
#else
    Handle<AI::ArgumentMapping> storyTier; // 38
    game::StoryTier tier; // 48
    uint8_t unk49[0x50 - 0x49]; // 49
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(StoryTierConditionDefinition, 0x50);
RED4EXT_ASSERT_OFFSET(StoryTierConditionDefinition, storyTier, 0x38);
RED4EXT_ASSERT_OFFSET(StoryTierConditionDefinition, tier, 0x48);
#else
RED4EXT_ASSERT_SIZE(StoryTierConditionDefinition, 0x50);
#endif
} // namespace AI::behavior
using AIbehaviorStoryTierConditionDefinition = AI::behavior::StoryTierConditionDefinition;
} // namespace RED4ext

// clang-format on
