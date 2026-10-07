#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ICharacterConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct CharacterStatusEffect_CondtionType : quest::ICharacterConditionType
{
    static constexpr const char* NAME = "questCharacterStatusEffect_CondtionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk71[0x78 - 0x71]; // 71
    CString statusEffectID; // 78
    bool inverted; // 98
    uint8_t unk99[0xA0 - 0x99]; // 99
#else
    CString statusEffectID; // 78
    bool inverted; // 98
    uint8_t unk99[0xA0 - 0x99]; // 99
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterStatusEffect_CondtionType, 0xA0);
RED4EXT_ASSERT_OFFSET(CharacterStatusEffect_CondtionType, statusEffectID, 0x78);
RED4EXT_ASSERT_OFFSET(CharacterStatusEffect_CondtionType, inverted, 0x98);
#else
RED4EXT_ASSERT_SIZE(CharacterStatusEffect_CondtionType, 0xA0);
#endif
} // namespace quest
using questCharacterStatusEffect_CondtionType = quest::CharacterStatusEffect_CondtionType;
} // namespace RED4ext

// clang-format on
