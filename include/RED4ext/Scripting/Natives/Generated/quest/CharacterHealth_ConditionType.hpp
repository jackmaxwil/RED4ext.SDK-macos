#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/EComparisonType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ICharacterConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct CharacterHealth_ConditionType : quest::ICharacterConditionType
{
    static constexpr const char* NAME = "questCharacterHealth_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk71[0x74 - 0x71]; // 71
    float percent; // 74
    EComparisonType comparisonType; // 78
    uint8_t unk7C[0x80 - 0x7C]; // 7C
#else
    float percent; // 78
    EComparisonType comparisonType; // 7C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterHealth_ConditionType, 0x80);
RED4EXT_ASSERT_OFFSET(CharacterHealth_ConditionType, percent, 0x74);
RED4EXT_ASSERT_OFFSET(CharacterHealth_ConditionType, comparisonType, 0x78);
#else
RED4EXT_ASSERT_SIZE(CharacterHealth_ConditionType, 0x80);
#endif
} // namespace quest
using questCharacterHealth_ConditionType = quest::CharacterHealth_ConditionType;
} // namespace RED4ext

// clang-format on
