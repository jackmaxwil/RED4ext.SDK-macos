#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ICharacterConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct CharacterWorkspot_ConditionType : quest::ICharacterConditionType
{
    static constexpr const char* NAME = "questCharacterWorkspot_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk71[0x78 - 0x71]; // 71
    NodeRef spotRef; // 78
    CName animationName; // 80
    bool waitForAnimEnd; // 88
    uint8_t unk89[0x90 - 0x89]; // 89
#else
    NodeRef spotRef; // 78
    CName animationName; // 80
    bool waitForAnimEnd; // 88
    uint8_t unk89[0x90 - 0x89]; // 89
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterWorkspot_ConditionType, 0x90);
RED4EXT_ASSERT_OFFSET(CharacterWorkspot_ConditionType, spotRef, 0x78);
RED4EXT_ASSERT_OFFSET(CharacterWorkspot_ConditionType, animationName, 0x80);
RED4EXT_ASSERT_OFFSET(CharacterWorkspot_ConditionType, waitForAnimEnd, 0x88);
#else
RED4EXT_ASSERT_SIZE(CharacterWorkspot_ConditionType, 0x90);
#endif
} // namespace quest
using questCharacterWorkspot_ConditionType = quest::CharacterWorkspot_ConditionType;
} // namespace RED4ext

// clang-format on
