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
struct CharacterCover_ConditionType : quest::ICharacterConditionType
{
    static constexpr const char* NAME = "questCharacterCover_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk71[0x78 - 0x71]; // 71
    NodeRef coverRef; // 78
#else
    NodeRef coverRef; // 78
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterCover_ConditionType, 0x80);
RED4EXT_ASSERT_OFFSET(CharacterCover_ConditionType, coverRef, 0x78);
#else
RED4EXT_ASSERT_SIZE(CharacterCover_ConditionType, 0x80);
#endif
} // namespace quest
using questCharacterCover_ConditionType = quest::CharacterCover_ConditionType;
} // namespace RED4ext

// clang-format on
