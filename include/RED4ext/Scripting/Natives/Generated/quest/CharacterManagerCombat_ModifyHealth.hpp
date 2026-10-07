#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ICharacterManagerCombat_NodeSubType.hpp>

namespace RED4ext
{
namespace quest
{
struct CharacterManagerCombat_ModifyHealth : quest::ICharacterManagerCombat_NodeSubType
{
    static constexpr const char* NAME = "questCharacterManagerCombat_ModifyHealth";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk69[0x6C - 0x69]; // 69
    float percent; // 6C
    bool setExactValue; // 70
    bool noDamageIndicator; // 71
    uint8_t unk72[0x78 - 0x72]; // 72
    game::EntityReference damageSourceRef; // 78
#else
    float percent; // 70
    bool setExactValue; // 74
    bool noDamageIndicator; // 75
    uint8_t unk76[0x78 - 0x76]; // 76
    game::EntityReference damageSourceRef; // 78
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterManagerCombat_ModifyHealth, 0xB0);
RED4EXT_ASSERT_OFFSET(CharacterManagerCombat_ModifyHealth, percent, 0x6C);
RED4EXT_ASSERT_OFFSET(CharacterManagerCombat_ModifyHealth, setExactValue, 0x70);
RED4EXT_ASSERT_OFFSET(CharacterManagerCombat_ModifyHealth, noDamageIndicator, 0x71);
RED4EXT_ASSERT_OFFSET(CharacterManagerCombat_ModifyHealth, damageSourceRef, 0x78);
#else
RED4EXT_ASSERT_SIZE(CharacterManagerCombat_ModifyHealth, 0xB0);
#endif
} // namespace quest
using questCharacterManagerCombat_ModifyHealth = quest::CharacterManagerCombat_ModifyHealth;
} // namespace RED4ext

// clang-format on
