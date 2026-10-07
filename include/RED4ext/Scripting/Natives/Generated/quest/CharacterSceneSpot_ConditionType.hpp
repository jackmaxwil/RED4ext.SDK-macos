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
struct CharacterSceneSpot_ConditionType : quest::ICharacterConditionType
{
    static constexpr const char* NAME = "questCharacterSceneSpot_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk71[0x78 - 0x71]; // 71
    CName workName; // 78
    bool waitForEnd; // 80
    uint8_t unk81[0x88 - 0x81]; // 81
#else
    CName workName; // 78
    bool waitForEnd; // 80
    uint8_t unk81[0x88 - 0x81]; // 81
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterSceneSpot_ConditionType, 0x88);
RED4EXT_ASSERT_OFFSET(CharacterSceneSpot_ConditionType, workName, 0x78);
RED4EXT_ASSERT_OFFSET(CharacterSceneSpot_ConditionType, waitForEnd, 0x80);
#else
RED4EXT_ASSERT_SIZE(CharacterSceneSpot_ConditionType, 0x88);
#endif
} // namespace quest
using questCharacterSceneSpot_ConditionType = quest::CharacterSceneSpot_ConditionType;
} // namespace RED4ext

// clang-format on
