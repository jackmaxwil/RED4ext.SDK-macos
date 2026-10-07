#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ICharacterConditionType.hpp>

namespace RED4ext
{
namespace quest { struct ComparisonParam; }
namespace quest { struct UniversalRef; }

namespace quest
{
struct CharacterKilled_ConditionType : quest::ICharacterConditionType
{
    static constexpr const char* NAME = "questCharacterKilled_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk71[0x78 - 0x71]; // 71
    Handle<quest::ComparisonParam> comparisonParams; // 78
    Handle<quest::UniversalRef> source; // 88
    bool killed; // 98
    bool unconscious; // 99
    bool defeated; // 9A
    uint8_t unk9B[0xA0 - 0x9B]; // 9B
#else
    Handle<quest::ComparisonParam> comparisonParams; // 78
    Handle<quest::UniversalRef> source; // 88
    bool killed; // 98
    bool unconscious; // 99
    bool defeated; // 9A
    uint8_t unk9B[0xA0 - 0x9B]; // 9B
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterKilled_ConditionType, 0xA0);
RED4EXT_ASSERT_OFFSET(CharacterKilled_ConditionType, comparisonParams, 0x78);
RED4EXT_ASSERT_OFFSET(CharacterKilled_ConditionType, source, 0x88);
RED4EXT_ASSERT_OFFSET(CharacterKilled_ConditionType, killed, 0x98);
RED4EXT_ASSERT_OFFSET(CharacterKilled_ConditionType, unconscious, 0x99);
RED4EXT_ASSERT_OFFSET(CharacterKilled_ConditionType, defeated, 0x9A);
#else
RED4EXT_ASSERT_SIZE(CharacterKilled_ConditionType, 0xA0);
#endif
} // namespace quest
using questCharacterKilled_ConditionType = quest::CharacterKilled_ConditionType;
} // namespace RED4ext

// clang-format on
