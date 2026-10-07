#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/AICommandNodeBase.hpp>

namespace RED4ext
{
namespace quest { struct AICommandParams; }

namespace quest
{
struct SendAICommandNodeDefinition : quest::AICommandNodeBase
{
    static constexpr const char* NAME = "questSendAICommandNodeDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk42[0x48 - 0x42]; // 42
    game::EntityReference puppet; // 48
    Handle<quest::AICommandParams> commandParams; // 80
#else
    game::EntityReference puppet; // 48
    Handle<quest::AICommandParams> commandParams; // 80
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SendAICommandNodeDefinition, 0x90);
RED4EXT_ASSERT_OFFSET(SendAICommandNodeDefinition, puppet, 0x48);
RED4EXT_ASSERT_OFFSET(SendAICommandNodeDefinition, commandParams, 0x80);
#else
RED4EXT_ASSERT_SIZE(SendAICommandNodeDefinition, 0x90);
#endif
} // namespace quest
using questSendAICommandNodeDefinition = quest::SendAICommandNodeDefinition;
} // namespace RED4ext

// clang-format on
