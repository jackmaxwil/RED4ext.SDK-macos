#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ICharacterConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct CharacterBodyType_CondtionType : quest::ICharacterConditionType
{
    static constexpr const char* NAME = "questCharacterBodyType_CondtionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk71[0x78 - 0x71]; // 71
    CName gender; // 78
#else
    CName gender; // 78
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterBodyType_CondtionType, 0x80);
RED4EXT_ASSERT_OFFSET(CharacterBodyType_CondtionType, gender, 0x78);
#else
RED4EXT_ASSERT_SIZE(CharacterBodyType_CondtionType, 0x80);
#endif
} // namespace quest
using questCharacterBodyType_CondtionType = quest::CharacterBodyType_CondtionType;
} // namespace RED4ext

// clang-format on
