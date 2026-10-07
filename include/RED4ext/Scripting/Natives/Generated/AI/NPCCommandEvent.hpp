#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/AIEvent.hpp>

namespace RED4ext
{
namespace AI { struct Command; }

namespace AI
{
struct NPCCommandEvent : AI::AIEvent
{
    static constexpr const char* NAME = "AINPCCommandEvent";
    static constexpr const char* ALIAS = "AICommandEvent";

#ifdef __APPLE__
    uint8_t unk4C[0x50 - 0x4C]; // 4C
    Handle<AI::Command> command; // 50
#else
    Handle<AI::Command> command; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(NPCCommandEvent, 0x60);
RED4EXT_ASSERT_OFFSET(NPCCommandEvent, command, 0x50);
#else
RED4EXT_ASSERT_SIZE(NPCCommandEvent, 0x60);
#endif
} // namespace AI
using AINPCCommandEvent = AI::NPCCommandEvent;
using AICommandEvent = AI::NPCCommandEvent;
} // namespace RED4ext

// clang-format on
