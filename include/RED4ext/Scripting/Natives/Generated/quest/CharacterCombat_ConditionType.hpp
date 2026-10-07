#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ICharacterConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct CharacterCombat_ConditionType : quest::ICharacterConditionType
{
    static constexpr const char* NAME = "questCharacterCombat_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool inverted; // 71
    uint8_t unk72[0x78 - 0x72]; // 72
#else
    bool inverted; // 78
    uint8_t unk79[0x80 - 0x79]; // 79
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterCombat_ConditionType, 0x78);
RED4EXT_ASSERT_OFFSET(CharacterCombat_ConditionType, inverted, 0x71);
#else
RED4EXT_ASSERT_SIZE(CharacterCombat_ConditionType, 0x80);
#endif
} // namespace quest
using questCharacterCombat_ConditionType = quest::CharacterCombat_ConditionType;
} // namespace RED4ext

// clang-format on
