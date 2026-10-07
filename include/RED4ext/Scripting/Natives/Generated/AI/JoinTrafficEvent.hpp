#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/AIEvent.hpp>

namespace RED4ext
{
namespace AI
{
struct JoinTrafficEvent : AI::AIEvent
{
    static constexpr const char* NAME = "AIJoinTrafficEvent";
    static constexpr const char* ALIAS = "JoinTrafficEvent";

#ifdef __APPLE__
    uint8_t unk4C[0x100 - 0x4C]; // 4C
#else
    uint8_t unk50[0x100 - 0x50]; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(JoinTrafficEvent, 0x100);
#else
RED4EXT_ASSERT_SIZE(JoinTrafficEvent, 0x100);
#endif
} // namespace AI
using AIJoinTrafficEvent = AI::JoinTrafficEvent;
using JoinTrafficEvent = AI::JoinTrafficEvent;
} // namespace RED4ext

// clang-format on
