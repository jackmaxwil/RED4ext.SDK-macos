#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/Vendor_Record.hpp>

namespace RED4ext
{
namespace game::data
{
struct Glamdoc_Record : game::data::Vendor_Record
{
    static constexpr const char* NAME = "gamedataGlamdoc_Record";
    static constexpr const char* ALIAS = "Glamdoc_Record";

#ifdef __APPLE__
    uint8_t unk100[0x108 - 0x100]; // 100
#else
    uint8_t unk100[0x110 - 0x100]; // 100
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(Glamdoc_Record, 0x108);
#else
RED4EXT_ASSERT_SIZE(Glamdoc_Record, 0x110);
#endif
} // namespace game::data
using gamedataGlamdoc_Record = game::data::Glamdoc_Record;
using Glamdoc_Record = game::data::Glamdoc_Record;
} // namespace RED4ext

// clang-format on
