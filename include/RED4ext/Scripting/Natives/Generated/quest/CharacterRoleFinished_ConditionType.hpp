#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/FiniteRoleType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ICharacterConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct CharacterRoleFinished_ConditionType : quest::ICharacterConditionType
{
    static constexpr const char* NAME = "questCharacterRoleFinished_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk71[0x74 - 0x71]; // 71
    AI::FiniteRoleType role; // 74
#else
    AI::FiniteRoleType role; // 78
    uint8_t unk7C[0x80 - 0x7C]; // 7C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterRoleFinished_ConditionType, 0x78);
RED4EXT_ASSERT_OFFSET(CharacterRoleFinished_ConditionType, role, 0x74);
#else
RED4EXT_ASSERT_SIZE(CharacterRoleFinished_ConditionType, 0x80);
#endif
} // namespace quest
using questCharacterRoleFinished_ConditionType = quest::CharacterRoleFinished_ConditionType;
} // namespace RED4ext

// clang-format on
