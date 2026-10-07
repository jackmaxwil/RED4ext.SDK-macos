#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/AIEvent.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/StoryTier.hpp>

namespace RED4ext
{
namespace game
{
struct StoryTierChangedEvent : AI::AIEvent
{
    static constexpr const char* NAME = "gameStoryTierChangedEvent";
    static constexpr const char* ALIAS = "StoryTierChangedEvent";

#ifdef __APPLE__
    game::StoryTier newTier; // 4C
    uint8_t unk4D[0x50 - 0x4D]; // 4D
#else
    game::StoryTier newTier; // 50
    uint8_t unk51[0x58 - 0x51]; // 51
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(StoryTierChangedEvent, 0x50);
RED4EXT_ASSERT_OFFSET(StoryTierChangedEvent, newTier, 0x4C);
#else
RED4EXT_ASSERT_SIZE(StoryTierChangedEvent, 0x58);
#endif
} // namespace game
using gameStoryTierChangedEvent = game::StoryTierChangedEvent;
using StoryTierChangedEvent = game::StoryTierChangedEvent;
} // namespace RED4ext

// clang-format on
