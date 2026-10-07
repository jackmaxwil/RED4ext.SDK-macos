#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/SignalStoppingNodeDefinition.hpp>

namespace RED4ext
{
namespace quest { struct MultiplayerAIDirectorParams; }

namespace quest
{
struct MultiplayerAIDirectorNodeDefinition : quest::SignalStoppingNodeDefinition
{
    static constexpr const char* NAME = "questMultiplayerAIDirectorNodeDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk42[0x48 - 0x42]; // 42
    Handle<quest::MultiplayerAIDirectorParams> params; // 48
#else
    Handle<quest::MultiplayerAIDirectorParams> params; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MultiplayerAIDirectorNodeDefinition, 0x58);
RED4EXT_ASSERT_OFFSET(MultiplayerAIDirectorNodeDefinition, params, 0x48);
#else
RED4EXT_ASSERT_SIZE(MultiplayerAIDirectorNodeDefinition, 0x58);
#endif
} // namespace quest
using questMultiplayerAIDirectorNodeDefinition = quest::MultiplayerAIDirectorNodeDefinition;
} // namespace RED4ext

// clang-format on
