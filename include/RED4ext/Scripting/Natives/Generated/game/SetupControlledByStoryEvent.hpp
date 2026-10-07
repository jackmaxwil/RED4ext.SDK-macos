#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/AIEvent.hpp>

namespace RED4ext
{
namespace game
{
struct SetupControlledByStoryEvent : AI::AIEvent
{
    static constexpr const char* NAME = "gameSetupControlledByStoryEvent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk4C[0x78 - 0x4C]; // 4C
#else
    uint8_t unk50[0x80 - 0x50]; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SetupControlledByStoryEvent, 0x78);
#else
RED4EXT_ASSERT_SIZE(SetupControlledByStoryEvent, 0x80);
#endif
} // namespace game
using gameSetupControlledByStoryEvent = game::SetupControlledByStoryEvent;
} // namespace RED4ext

// clang-format on
