#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/BaseSign_Record.hpp>

namespace RED4ext
{
namespace game::data
{
struct LCDScreen_Record : game::data::BaseSign_Record
{
    static constexpr const char* NAME = "gamedataLCDScreen_Record";
    static constexpr const char* ALIAS = "LCDScreen_Record";

#ifdef __APPLE__
    uint8_t unk70[0x78 - 0x70]; // 70
#else
    uint8_t unk70[0x80 - 0x70]; // 70
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(LCDScreen_Record, 0x78);
#else
RED4EXT_ASSERT_SIZE(LCDScreen_Record, 0x80);
#endif
} // namespace game::data
using gamedataLCDScreen_Record = game::data::LCDScreen_Record;
using LCDScreen_Record = game::data::LCDScreen_Record;
} // namespace RED4ext

// clang-format on
