#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/SpawnableObject_Record.hpp>

namespace RED4ext
{
namespace game::data
{
struct Prop_Record : game::data::SpawnableObject_Record
{
    static constexpr const char* NAME = "gamedataProp_Record";
    static constexpr const char* ALIAS = "Prop_Record";

#ifdef __APPLE__
    uint8_t unkF0[0x100 - 0xF0]; // F0
#else
    uint8_t unkF8[0x108 - 0xF8]; // F8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(Prop_Record, 0x100);
#else
RED4EXT_ASSERT_SIZE(Prop_Record, 0x108);
#endif
} // namespace game::data
using gamedataProp_Record = game::data::Prop_Record;
using Prop_Record = game::data::Prop_Record;
} // namespace RED4ext

// clang-format on
