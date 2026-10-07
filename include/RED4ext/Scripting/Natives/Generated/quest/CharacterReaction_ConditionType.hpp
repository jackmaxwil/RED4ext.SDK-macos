#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ICharacterConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct CharacterReaction_ConditionType : quest::ICharacterConditionType
{
    static constexpr const char* NAME = "questCharacterReaction_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk71[0x78 - 0x71]; // 71
    game::EntityReference puppetRef; // 78
    TweakDBID reactionBehaviorID; // B0
    bool isAnyReaction; // B8
    uint8_t unkB9[0xC0 - 0xB9]; // B9
#else
    game::EntityReference puppetRef; // 78
    TweakDBID reactionBehaviorID; // B0
    bool isAnyReaction; // B8
    uint8_t unkB9[0xC0 - 0xB9]; // B9
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterReaction_ConditionType, 0xC0);
RED4EXT_ASSERT_OFFSET(CharacterReaction_ConditionType, puppetRef, 0x78);
RED4EXT_ASSERT_OFFSET(CharacterReaction_ConditionType, reactionBehaviorID, 0xB0);
RED4EXT_ASSERT_OFFSET(CharacterReaction_ConditionType, isAnyReaction, 0xB8);
#else
RED4EXT_ASSERT_SIZE(CharacterReaction_ConditionType, 0xC0);
#endif
} // namespace quest
using questCharacterReaction_ConditionType = quest::CharacterReaction_ConditionType;
} // namespace RED4ext

// clang-format on
