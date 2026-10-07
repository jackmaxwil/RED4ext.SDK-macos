#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ICharacterManagerParameters_NodeSubType.hpp>

namespace RED4ext
{
namespace quest { struct ReactionPresetRecordSelector; }

namespace quest
{
struct CharacterManagerParameters_SetReactionPreset : quest::ICharacterManagerParameters_NodeSubType
{
    static constexpr const char* NAME = "questCharacterManagerParameters_SetReactionPreset";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk69[0x70 - 0x69]; // 69
    Handle<quest::ReactionPresetRecordSelector> recordSelector; // 70
#else
    Handle<quest::ReactionPresetRecordSelector> recordSelector; // 70
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterManagerParameters_SetReactionPreset, 0x80);
RED4EXT_ASSERT_OFFSET(CharacterManagerParameters_SetReactionPreset, recordSelector, 0x70);
#else
RED4EXT_ASSERT_SIZE(CharacterManagerParameters_SetReactionPreset, 0x80);
#endif
} // namespace quest
using questCharacterManagerParameters_SetReactionPreset = quest::CharacterManagerParameters_SetReactionPreset;
} // namespace RED4ext

// clang-format on
