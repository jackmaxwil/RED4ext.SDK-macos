#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/influence/EBumpPolicy.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ICharacterManagerParameters_NodeSubType.hpp>

namespace RED4ext
{
namespace quest
{
struct CharacterManagerParameters_EnableBumps : quest::ICharacterManagerParameters_NodeSubType
{
    static constexpr const char* NAME = "questCharacterManagerParameters_EnableBumps";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool enable; // 69
    AI::influence::EBumpPolicy policy; // 6A
    uint8_t unk6B[0x70 - 0x6B]; // 6B
#else
    bool enable; // 70
    AI::influence::EBumpPolicy policy; // 71
    uint8_t unk72[0x78 - 0x72]; // 72
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterManagerParameters_EnableBumps, 0x70);
RED4EXT_ASSERT_OFFSET(CharacterManagerParameters_EnableBumps, enable, 0x69);
RED4EXT_ASSERT_OFFSET(CharacterManagerParameters_EnableBumps, policy, 0x6A);
#else
RED4EXT_ASSERT_SIZE(CharacterManagerParameters_EnableBumps, 0x78);
#endif
} // namespace quest
using questCharacterManagerParameters_EnableBumps = quest::CharacterManagerParameters_EnableBumps;
} // namespace RED4ext

// clang-format on
