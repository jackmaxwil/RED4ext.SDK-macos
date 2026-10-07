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
struct CharacterCyberdeckProgram_ConditionType : quest::ICharacterConditionType
{
    static constexpr const char* NAME = "questCharacterCyberdeckProgram_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk71[0x74 - 0x71]; // 71
    TweakDBID cyberdeckProgramID; // 74
    uint8_t unk7C[0x80 - 0x7C]; // 7C
#else
    TweakDBID cyberdeckProgramID; // 78
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterCyberdeckProgram_ConditionType, 0x80);
RED4EXT_ASSERT_OFFSET(CharacterCyberdeckProgram_ConditionType, cyberdeckProgramID, 0x74);
#else
RED4EXT_ASSERT_SIZE(CharacterCyberdeckProgram_ConditionType, 0x80);
#endif
} // namespace quest
using questCharacterCyberdeckProgram_ConditionType = quest::CharacterCyberdeckProgram_ConditionType;
} // namespace RED4ext

// clang-format on
