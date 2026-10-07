#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/SignalStoppingNodeDefinition.hpp>

namespace RED4ext
{
namespace quest
{
struct MinigameNodeDefinition : quest::SignalStoppingNodeDefinition
{
    static constexpr const char* NAME = "questMinigameNodeDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool start; // 42
    bool skipSummaryScreen; // 43
    uint8_t unk44[0x48 - 0x44]; // 44
    game::EntityReference networkRef; // 48
#else
    bool start; // 48
    bool skipSummaryScreen; // 49
    uint8_t unk4A[0x50 - 0x4A]; // 4A
    game::EntityReference networkRef; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MinigameNodeDefinition, 0x80);
RED4EXT_ASSERT_OFFSET(MinigameNodeDefinition, start, 0x42);
RED4EXT_ASSERT_OFFSET(MinigameNodeDefinition, skipSummaryScreen, 0x43);
RED4EXT_ASSERT_OFFSET(MinigameNodeDefinition, networkRef, 0x48);
#else
RED4EXT_ASSERT_SIZE(MinigameNodeDefinition, 0x88);
#endif
} // namespace quest
using questMinigameNodeDefinition = quest::MinigameNodeDefinition;
} // namespace RED4ext

// clang-format on
