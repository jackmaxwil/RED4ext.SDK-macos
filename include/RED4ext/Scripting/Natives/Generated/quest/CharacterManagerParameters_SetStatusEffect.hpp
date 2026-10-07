#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ICharacterManagerParameters_NodeSubType.hpp>

namespace RED4ext
{
namespace quest { struct RecordSelector; }

namespace quest
{
struct CharacterManagerParameters_SetStatusEffect : quest::ICharacterManagerParameters_NodeSubType
{
    static constexpr const char* NAME = "questCharacterManagerParameters_SetStatusEffect";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool isPlayerStatusEffectSource; // 69
    bool set; // 6A
    uint8_t unk6B[0x70 - 0x6B]; // 6B
    Handle<quest::RecordSelector> recordSelector; // 70
    game::EntityReference statusEffectSourceObject; // 80
    TweakDBID statusEffectID; // B8
#else
    bool isPlayerStatusEffectSource; // 70
    bool set; // 71
    uint8_t unk72[0x78 - 0x72]; // 72
    Handle<quest::RecordSelector> recordSelector; // 78
    game::EntityReference statusEffectSourceObject; // 88
    TweakDBID statusEffectID; // C0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterManagerParameters_SetStatusEffect, 0xC0);
RED4EXT_ASSERT_OFFSET(CharacterManagerParameters_SetStatusEffect, isPlayerStatusEffectSource, 0x69);
RED4EXT_ASSERT_OFFSET(CharacterManagerParameters_SetStatusEffect, set, 0x6A);
RED4EXT_ASSERT_OFFSET(CharacterManagerParameters_SetStatusEffect, recordSelector, 0x70);
RED4EXT_ASSERT_OFFSET(CharacterManagerParameters_SetStatusEffect, statusEffectSourceObject, 0x80);
RED4EXT_ASSERT_OFFSET(CharacterManagerParameters_SetStatusEffect, statusEffectID, 0xB8);
#else
RED4EXT_ASSERT_SIZE(CharacterManagerParameters_SetStatusEffect, 0xC8);
#endif
} // namespace quest
using questCharacterManagerParameters_SetStatusEffect = quest::CharacterManagerParameters_SetStatusEffect;
} // namespace RED4ext

// clang-format on
