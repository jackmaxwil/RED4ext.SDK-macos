#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ICharacterManagerParameters_NodeSubType.hpp>

namespace RED4ext
{
namespace quest
{
struct CharacterManagerParameters_SetLowGravity : quest::ICharacterManagerParameters_NodeSubType
{
    static constexpr const char* NAME = "questCharacterManagerParameters_SetLowGravity";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool enable; // 69
    uint8_t unk6A[0x70 - 0x6A]; // 6A
#else
    bool enable; // 70
    uint8_t unk71[0x78 - 0x71]; // 71
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterManagerParameters_SetLowGravity, 0x70);
RED4EXT_ASSERT_OFFSET(CharacterManagerParameters_SetLowGravity, enable, 0x69);
#else
RED4EXT_ASSERT_SIZE(CharacterManagerParameters_SetLowGravity, 0x78);
#endif
} // namespace quest
using questCharacterManagerParameters_SetLowGravity = quest::CharacterManagerParameters_SetLowGravity;
} // namespace RED4ext

// clang-format on
