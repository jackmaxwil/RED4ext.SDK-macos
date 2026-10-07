#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ICharacterManagerParameters_NodeSubType.hpp>

namespace RED4ext
{
namespace quest
{
struct CharacterManagerParameters_SetAnimset : quest::ICharacterManagerParameters_NodeSubType
{
    static constexpr const char* NAME = "questCharacterManagerParameters_SetAnimset";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk69[0x70 - 0x69]; // 69
    CName variableName; // 70
    float value; // 78
    uint8_t unk7C[0x80 - 0x7C]; // 7C
#else
    CName variableName; // 70
    float value; // 78
    uint8_t unk7C[0x80 - 0x7C]; // 7C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterManagerParameters_SetAnimset, 0x80);
RED4EXT_ASSERT_OFFSET(CharacterManagerParameters_SetAnimset, variableName, 0x70);
RED4EXT_ASSERT_OFFSET(CharacterManagerParameters_SetAnimset, value, 0x78);
#else
RED4EXT_ASSERT_SIZE(CharacterManagerParameters_SetAnimset, 0x80);
#endif
} // namespace quest
using questCharacterManagerParameters_SetAnimset = quest::CharacterManagerParameters_SetAnimset;
} // namespace RED4ext

// clang-format on
