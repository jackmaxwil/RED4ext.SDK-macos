#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/CharacterHitEventType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ICharacterConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct CharacterControlledObjectHit_ConditionType : quest::ICharacterConditionType
{
    static constexpr const char* NAME = "questCharacterControlledObjectHit_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk71[0x78 - 0x71]; // 71
    game::EntityReference targetRef; // 78
    bool isTargetPlayer; // B0
    uint8_t unkB1[0xB8 - 0xB1]; // B1
    DynArray<quest::CharacterHitEventType> includeHitTypes; // B8
    DynArray<quest::CharacterHitEventType> excludeHitTypes; // C8
    DynArray<CName> includeHitShapes; // D8
    DynArray<CName> excludeHitShapes; // E8
#else
    game::EntityReference targetRef; // 78
    bool isTargetPlayer; // B0
    uint8_t unkB1[0xB8 - 0xB1]; // B1
    DynArray<quest::CharacterHitEventType> includeHitTypes; // B8
    DynArray<quest::CharacterHitEventType> excludeHitTypes; // C8
    DynArray<CName> includeHitShapes; // D8
    DynArray<CName> excludeHitShapes; // E8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterControlledObjectHit_ConditionType, 0xF8);
RED4EXT_ASSERT_OFFSET(CharacterControlledObjectHit_ConditionType, targetRef, 0x78);
RED4EXT_ASSERT_OFFSET(CharacterControlledObjectHit_ConditionType, isTargetPlayer, 0xB0);
RED4EXT_ASSERT_OFFSET(CharacterControlledObjectHit_ConditionType, includeHitTypes, 0xB8);
RED4EXT_ASSERT_OFFSET(CharacterControlledObjectHit_ConditionType, excludeHitTypes, 0xC8);
RED4EXT_ASSERT_OFFSET(CharacterControlledObjectHit_ConditionType, includeHitShapes, 0xD8);
RED4EXT_ASSERT_OFFSET(CharacterControlledObjectHit_ConditionType, excludeHitShapes, 0xE8);
#else
RED4EXT_ASSERT_SIZE(CharacterControlledObjectHit_ConditionType, 0xF8);
#endif
} // namespace quest
using questCharacterControlledObjectHit_ConditionType = quest::CharacterControlledObjectHit_ConditionType;
} // namespace RED4ext

// clang-format on
