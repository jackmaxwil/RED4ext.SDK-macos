#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/Character_Record.hpp>

namespace RED4ext
{
namespace game::data
{
struct SubCharacter_Record : game::data::Character_Record
{
    static constexpr const char* NAME = "gamedataSubCharacter_Record";
    static constexpr const char* ALIAS = "SubCharacter_Record";

#ifdef __APPLE__
    uint8_t unk468[0x4A8 - 0x468]; // 468
#else
    uint8_t unk470[0x4B0 - 0x470]; // 470
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SubCharacter_Record, 0x4A8);
#else
RED4EXT_ASSERT_SIZE(SubCharacter_Record, 0x4B0);
#endif
} // namespace game::data
using gamedataSubCharacter_Record = game::data::SubCharacter_Record;
using SubCharacter_Record = game::data::SubCharacter_Record;
} // namespace RED4ext

// clang-format on
