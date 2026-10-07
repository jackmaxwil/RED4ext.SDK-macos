#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ICharacterConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct CharacterAttack_ConditionType : quest::ICharacterConditionType
{
    static constexpr const char* NAME = "questCharacterAttack_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk71[0x78 - 0x71]; // 71
    game::EntityReference targetRef; // 78
    bool isTargetPlayer; // B0
    uint8_t unkB1[0xB8 - 0xB1]; // B1
#else
    game::EntityReference targetRef; // 78
    bool isTargetPlayer; // B0
    uint8_t unkB1[0xB8 - 0xB1]; // B1
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterAttack_ConditionType, 0xB8);
RED4EXT_ASSERT_OFFSET(CharacterAttack_ConditionType, targetRef, 0x78);
RED4EXT_ASSERT_OFFSET(CharacterAttack_ConditionType, isTargetPlayer, 0xB0);
#else
RED4EXT_ASSERT_SIZE(CharacterAttack_ConditionType, 0xB8);
#endif
} // namespace quest
using questCharacterAttack_ConditionType = quest::CharacterAttack_ConditionType;
} // namespace RED4ext

// clang-format on
