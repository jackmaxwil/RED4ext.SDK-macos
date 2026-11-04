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
    uint8_t unk478[0x4B8 - 0x478]; // 478
#else
    uint8_t unk480[0x4C0 - 0x480]; // 480
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SubCharacter_Record, 0x4B8);
#else
RED4EXT_ASSERT_SIZE(SubCharacter_Record, 0x4C0);
#endif
} // namespace game::data
using gamedataSubCharacter_Record = game::data::SubCharacter_Record;
using SubCharacter_Record = game::data::SubCharacter_Record;
} // namespace RED4ext

// clang-format on
