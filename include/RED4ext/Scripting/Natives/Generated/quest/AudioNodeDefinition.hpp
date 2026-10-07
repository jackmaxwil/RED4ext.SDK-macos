#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/SignalStoppingNodeDefinition.hpp>

namespace RED4ext
{
namespace quest { struct IAudioNodeType; }

namespace quest
{
struct AudioNodeDefinition : quest::SignalStoppingNodeDefinition
{
    static constexpr const char* NAME = "questAudioNodeDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk42[0x48 - 0x42]; // 42
    Handle<quest::IAudioNodeType> type; // 48
#else
    Handle<quest::IAudioNodeType> type; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AudioNodeDefinition, 0x58);
RED4EXT_ASSERT_OFFSET(AudioNodeDefinition, type, 0x48);
#else
RED4EXT_ASSERT_SIZE(AudioNodeDefinition, 0x58);
#endif
} // namespace quest
using questAudioNodeDefinition = quest::AudioNodeDefinition;
} // namespace RED4ext

// clang-format on
