#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ICharacterManagerParameters_NodeSubType.hpp>

namespace RED4ext
{
namespace quest
{
struct CharacterManagerParameters_HealPlayer : quest::ICharacterManagerParameters_NodeSubType
{
    static constexpr const char* NAME = "questCharacterManagerParameters_HealPlayer";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool heal; // 69
    bool removeStatusEffects; // 6A
    bool removeBuffs; // 6B
    bool removeDebuffs; // 6C
    bool resetCyberdeckRAM; // 6D
    uint8_t unk6E[0x70 - 0x6E]; // 6E
#else
    bool heal; // 70
    bool removeStatusEffects; // 71
    bool removeBuffs; // 72
    bool removeDebuffs; // 73
    bool resetCyberdeckRAM; // 74
    uint8_t unk75[0x78 - 0x75]; // 75
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterManagerParameters_HealPlayer, 0x70);
RED4EXT_ASSERT_OFFSET(CharacterManagerParameters_HealPlayer, heal, 0x69);
RED4EXT_ASSERT_OFFSET(CharacterManagerParameters_HealPlayer, removeStatusEffects, 0x6A);
RED4EXT_ASSERT_OFFSET(CharacterManagerParameters_HealPlayer, removeBuffs, 0x6B);
RED4EXT_ASSERT_OFFSET(CharacterManagerParameters_HealPlayer, removeDebuffs, 0x6C);
RED4EXT_ASSERT_OFFSET(CharacterManagerParameters_HealPlayer, resetCyberdeckRAM, 0x6D);
#else
RED4EXT_ASSERT_SIZE(CharacterManagerParameters_HealPlayer, 0x78);
#endif
} // namespace quest
using questCharacterManagerParameters_HealPlayer = quest::CharacterManagerParameters_HealPlayer;
} // namespace RED4ext

// clang-format on
