#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/CombatSpaceSize.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ICharacterManagerCombat_NodeSubType.hpp>

namespace RED4ext
{
namespace quest
{
struct CharacterManagerParameters_SetCombatSpace : quest::ICharacterManagerCombat_NodeSubType
{
    static constexpr const char* NAME = "questCharacterManagerParameters_SetCombatSpace";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk69[0x6C - 0x69]; // 69
    AI::CombatSpaceSize combatSpaceSize; // 6C
#else
    AI::CombatSpaceSize combatSpaceSize; // 70
    uint8_t unk74[0x78 - 0x74]; // 74
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterManagerParameters_SetCombatSpace, 0x70);
RED4EXT_ASSERT_OFFSET(CharacterManagerParameters_SetCombatSpace, combatSpaceSize, 0x6C);
#else
RED4EXT_ASSERT_SIZE(CharacterManagerParameters_SetCombatSpace, 0x78);
#endif
} // namespace quest
using questCharacterManagerParameters_SetCombatSpace = quest::CharacterManagerParameters_SetCombatSpace;
} // namespace RED4ext

// clang-format on
