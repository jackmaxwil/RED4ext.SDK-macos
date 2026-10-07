#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ICharacterConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct CharacterEquippedItem_ConditionType : quest::ICharacterConditionType
{
    static constexpr const char* NAME = "questCharacterEquippedItem_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool isPlayer; // 71
    uint8_t unk72[0x78 - 0x72]; // 72
    game::EntityReference puppetRef; // 78
    TweakDBID itemID; // B0
    CName itemTag; // B8
    DynArray<TweakDBID> excludedTweakDBIDs; // C0
    DynArray<CName> excludedTags; // D0
    bool inverted; // E0
    uint8_t unkE1[0xE8 - 0xE1]; // E1
#else
    bool isPlayer; // 78
    uint8_t unk79[0x80 - 0x79]; // 79
    game::EntityReference puppetRef; // 80
    TweakDBID itemID; // B8
    CName itemTag; // C0
    DynArray<TweakDBID> excludedTweakDBIDs; // C8
    DynArray<CName> excludedTags; // D8
    bool inverted; // E8
    uint8_t unkE9[0xF0 - 0xE9]; // E9
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterEquippedItem_ConditionType, 0xE8);
RED4EXT_ASSERT_OFFSET(CharacterEquippedItem_ConditionType, isPlayer, 0x71);
RED4EXT_ASSERT_OFFSET(CharacterEquippedItem_ConditionType, puppetRef, 0x78);
RED4EXT_ASSERT_OFFSET(CharacterEquippedItem_ConditionType, itemID, 0xB0);
RED4EXT_ASSERT_OFFSET(CharacterEquippedItem_ConditionType, itemTag, 0xB8);
RED4EXT_ASSERT_OFFSET(CharacterEquippedItem_ConditionType, excludedTweakDBIDs, 0xC0);
RED4EXT_ASSERT_OFFSET(CharacterEquippedItem_ConditionType, excludedTags, 0xD0);
RED4EXT_ASSERT_OFFSET(CharacterEquippedItem_ConditionType, inverted, 0xE0);
#else
RED4EXT_ASSERT_SIZE(CharacterEquippedItem_ConditionType, 0xF0);
#endif
} // namespace quest
using questCharacterEquippedItem_ConditionType = quest::CharacterEquippedItem_ConditionType;
} // namespace RED4ext

// clang-format on
