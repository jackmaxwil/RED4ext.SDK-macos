#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ICharacterManagerParameters_NodeSubType.hpp>

namespace RED4ext
{
namespace quest
{
struct CharacterManagerParameters_SetSensePreset : quest::ICharacterManagerParameters_NodeSubType
{
    static constexpr const char* NAME = "questCharacterManagerParameters_SetSensePreset";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk69[0x6C - 0x69]; // 69
    TweakDBID presetID; // 6C
    bool main; // 74
    bool resetToMain; // 75
    uint8_t unk76[0x78 - 0x76]; // 76
#else
    TweakDBID presetID; // 70
    bool main; // 78
    bool resetToMain; // 79
    uint8_t unk7A[0x80 - 0x7A]; // 7A
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterManagerParameters_SetSensePreset, 0x78);
RED4EXT_ASSERT_OFFSET(CharacterManagerParameters_SetSensePreset, presetID, 0x6C);
RED4EXT_ASSERT_OFFSET(CharacterManagerParameters_SetSensePreset, main, 0x74);
RED4EXT_ASSERT_OFFSET(CharacterManagerParameters_SetSensePreset, resetToMain, 0x75);
#else
RED4EXT_ASSERT_SIZE(CharacterManagerParameters_SetSensePreset, 0x80);
#endif
} // namespace quest
using questCharacterManagerParameters_SetSensePreset = quest::CharacterManagerParameters_SetSensePreset;
} // namespace RED4ext

// clang-format on
