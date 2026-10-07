#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/Gadget_Record.hpp>

namespace RED4ext
{
namespace game::data
{
struct Grenade_Record : game::data::Gadget_Record
{
    static constexpr const char* NAME = "gamedataGrenade_Record";
    static constexpr const char* ALIAS = "Grenade_Record";

#ifdef __APPLE__
    uint8_t unk5F8[0x828 - 0x5F8]; // 5F8
#else
    uint8_t unk5F8[0x830 - 0x5F8]; // 5F8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(Grenade_Record, 0x828);
#else
RED4EXT_ASSERT_SIZE(Grenade_Record, 0x830);
#endif
} // namespace game::data
using gamedataGrenade_Record = game::data::Grenade_Record;
using Grenade_Record = game::data::Grenade_Record;
} // namespace RED4ext

// clang-format on
