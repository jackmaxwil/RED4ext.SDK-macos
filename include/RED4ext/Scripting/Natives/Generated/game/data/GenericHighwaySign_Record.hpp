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
struct GenericHighwaySign_Record : game::data::BaseSign_Record
{
    static constexpr const char* NAME = "gamedataGenericHighwaySign_Record";
    static constexpr const char* ALIAS = "GenericHighwaySign_Record";

#ifdef __APPLE__
    uint8_t unk70[0x90 - 0x70]; // 70
#else
    uint8_t unk70[0x98 - 0x70]; // 70
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(GenericHighwaySign_Record, 0x90);
#else
RED4EXT_ASSERT_SIZE(GenericHighwaySign_Record, 0x98);
#endif
} // namespace game::data
using gamedataGenericHighwaySign_Record = game::data::GenericHighwaySign_Record;
using GenericHighwaySign_Record = game::data::GenericHighwaySign_Record;
} // namespace RED4ext

// clang-format on
