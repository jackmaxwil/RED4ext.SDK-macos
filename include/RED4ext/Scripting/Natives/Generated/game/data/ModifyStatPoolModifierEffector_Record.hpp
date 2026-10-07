#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/Effector_Record.hpp>

namespace RED4ext
{
namespace game::data
{
struct ModifyStatPoolModifierEffector_Record : game::data::Effector_Record
{
    static constexpr const char* NAME = "gamedataModifyStatPoolModifierEffector_Record";
    static constexpr const char* ALIAS = "ModifyStatPoolModifierEffector_Record";

#ifdef __APPLE__
    uint8_t unk88[0xA8 - 0x88]; // 88
#else
    uint8_t unk88[0xB0 - 0x88]; // 88
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ModifyStatPoolModifierEffector_Record, 0xA8);
#else
RED4EXT_ASSERT_SIZE(ModifyStatPoolModifierEffector_Record, 0xB0);
#endif
} // namespace game::data
using gamedataModifyStatPoolModifierEffector_Record = game::data::ModifyStatPoolModifierEffector_Record;
using ModifyStatPoolModifierEffector_Record = game::data::ModifyStatPoolModifierEffector_Record;
} // namespace RED4ext

// clang-format on
