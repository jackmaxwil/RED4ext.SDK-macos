#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ICharacterManagerParameters_NodeSubType.hpp>

namespace RED4ext
{
namespace quest
{
struct CharacterManagerParameters_SetLifePath : quest::ICharacterManagerParameters_NodeSubType
{
    static constexpr const char* NAME = "questCharacterManagerParameters_SetLifePath";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk69[0x6C - 0x69]; // 69
    TweakDBID lifePathID; // 6C
    uint8_t unk74[0x78 - 0x74]; // 74
#else
    TweakDBID lifePathID; // 70
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterManagerParameters_SetLifePath, 0x78);
RED4EXT_ASSERT_OFFSET(CharacterManagerParameters_SetLifePath, lifePathID, 0x6C);
#else
RED4EXT_ASSERT_SIZE(CharacterManagerParameters_SetLifePath, 0x78);
#endif
} // namespace quest
using questCharacterManagerParameters_SetLifePath = quest::CharacterManagerParameters_SetLifePath;
} // namespace RED4ext

// clang-format on
