#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/EComparisonType.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/StatPoolType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ICharacterConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct CharacterStatPool_ConditionType : quest::ICharacterConditionType
{
    static constexpr const char* NAME = "questCharacterStatPool_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk71[0x74 - 0x71]; // 71
    float percent; // 74
    EComparisonType comparisonType; // 78
    game::data::StatPoolType statPoolType; // 7C
#else
    float percent; // 78
    EComparisonType comparisonType; // 7C
    game::data::StatPoolType statPoolType; // 80
    uint8_t unk84[0x88 - 0x84]; // 84
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterStatPool_ConditionType, 0x80);
RED4EXT_ASSERT_OFFSET(CharacterStatPool_ConditionType, percent, 0x74);
RED4EXT_ASSERT_OFFSET(CharacterStatPool_ConditionType, comparisonType, 0x78);
RED4EXT_ASSERT_OFFSET(CharacterStatPool_ConditionType, statPoolType, 0x7C);
#else
RED4EXT_ASSERT_SIZE(CharacterStatPool_ConditionType, 0x88);
#endif
} // namespace quest
using questCharacterStatPool_ConditionType = quest::CharacterStatPool_ConditionType;
} // namespace RED4ext

// clang-format on
