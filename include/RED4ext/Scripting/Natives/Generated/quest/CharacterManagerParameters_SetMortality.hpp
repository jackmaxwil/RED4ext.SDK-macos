#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/GodModeType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ICharacterManagerParameters_NodeSubType.hpp>

namespace RED4ext
{
namespace quest
{
struct CharacterManagerParameters_SetMortality : quest::ICharacterManagerParameters_NodeSubType
{
    static constexpr const char* NAME = "questCharacterManagerParameters_SetMortality";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk69[0x6C - 0x69]; // 69
    game::GodModeType state; // 6C
    bool resetToDefault; // 70
    uint8_t unk71[0x78 - 0x71]; // 71
    CName source; // 78
    uint8_t unk80[0x88 - 0x80]; // 80
#else
    game::GodModeType state; // 70
    bool resetToDefault; // 74
    uint8_t unk75[0x78 - 0x75]; // 75
    CName source; // 78
    uint8_t unk80[0x88 - 0x80]; // 80
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterManagerParameters_SetMortality, 0x88);
RED4EXT_ASSERT_OFFSET(CharacterManagerParameters_SetMortality, state, 0x6C);
RED4EXT_ASSERT_OFFSET(CharacterManagerParameters_SetMortality, resetToDefault, 0x70);
RED4EXT_ASSERT_OFFSET(CharacterManagerParameters_SetMortality, source, 0x78);
#else
RED4EXT_ASSERT_SIZE(CharacterManagerParameters_SetMortality, 0x88);
#endif
} // namespace quest
using questCharacterManagerParameters_SetMortality = quest::CharacterManagerParameters_SetMortality;
} // namespace RED4ext

// clang-format on
