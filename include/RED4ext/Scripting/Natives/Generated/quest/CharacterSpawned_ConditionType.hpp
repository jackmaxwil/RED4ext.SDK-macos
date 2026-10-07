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

namespace quest
{
struct CharacterSpawned_ConditionType : quest::ICharacterConditionType
{
    static constexpr const char* NAME = "questCharacterSpawned_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk71[0x78 - 0x71]; // 71
    Handle<quest::ComparisonParam> comparisonParams; // 78
#else
    Handle<quest::ComparisonParam> comparisonParams; // 78
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterSpawned_ConditionType, 0x88);
RED4EXT_ASSERT_OFFSET(CharacterSpawned_ConditionType, comparisonParams, 0x78);
#else
RED4EXT_ASSERT_SIZE(CharacterSpawned_ConditionType, 0x88);
#endif
} // namespace quest
using questCharacterSpawned_ConditionType = quest::CharacterSpawned_ConditionType;
} // namespace RED4ext

// clang-format on
