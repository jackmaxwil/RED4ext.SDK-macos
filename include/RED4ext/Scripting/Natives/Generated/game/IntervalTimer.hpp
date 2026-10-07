#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/BaseTimer.hpp>

namespace RED4ext
{
namespace game
{
struct IntervalTimer : game::BaseTimer
{
    static constexpr const char* NAME = "gameIntervalTimer";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk70[0x80 - 0x70]; // 70
#else
    uint8_t unk90[0xA0 - 0x90]; // 90
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(IntervalTimer, 0x80);
#else
RED4EXT_ASSERT_SIZE(IntervalTimer, 0xA0);
#endif
} // namespace game
using gameIntervalTimer = game::IntervalTimer;
} // namespace RED4ext

// clang-format on
