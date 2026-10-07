#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/DisableableNodeDefinition.hpp>

namespace RED4ext
{
namespace quest { struct IVoicesetManager_NodeType; }

namespace quest
{
struct VoicesetManagerNodeDefinition : quest::DisableableNodeDefinition
{
    static constexpr const char* NAME = "questVoicesetManagerNodeDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk42[0x48 - 0x42]; // 42
    Handle<quest::IVoicesetManager_NodeType> type; // 48
#else
    Handle<quest::IVoicesetManager_NodeType> type; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(VoicesetManagerNodeDefinition, 0x58);
RED4EXT_ASSERT_OFFSET(VoicesetManagerNodeDefinition, type, 0x48);
#else
RED4EXT_ASSERT_SIZE(VoicesetManagerNodeDefinition, 0x58);
#endif
} // namespace quest
using questVoicesetManagerNodeDefinition = quest::VoicesetManagerNodeDefinition;
} // namespace RED4ext

// clang-format on
