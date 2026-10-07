#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ICharacterManagerParameters_NodeSubType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/SetGender_NodeTypeParams.hpp>

namespace RED4ext
{
namespace quest
{
struct CharacterManagerParameters_SetGender : quest::ICharacterManagerParameters_NodeSubType
{
    static constexpr const char* NAME = "questCharacterManagerParameters_SetGender";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk69[0x70 - 0x69]; // 69
    DynArray<quest::SetGender_NodeTypeParams> params; // 70
#else
    DynArray<quest::SetGender_NodeTypeParams> params; // 70
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterManagerParameters_SetGender, 0x80);
RED4EXT_ASSERT_OFFSET(CharacterManagerParameters_SetGender, params, 0x70);
#else
RED4EXT_ASSERT_SIZE(CharacterManagerParameters_SetGender, 0x80);
#endif
} // namespace quest
using questCharacterManagerParameters_SetGender = quest::CharacterManagerParameters_SetGender;
} // namespace RED4ext

// clang-format on
