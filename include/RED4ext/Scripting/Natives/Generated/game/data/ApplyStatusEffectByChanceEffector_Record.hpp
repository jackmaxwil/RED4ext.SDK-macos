#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/ApplyStatusEffectEffector_Record.hpp>

namespace RED4ext
{
namespace game::data
{
struct ApplyStatusEffectByChanceEffector_Record : game::data::ApplyStatusEffectEffector_Record
{
    static constexpr const char* NAME = "gamedataApplyStatusEffectByChanceEffector_Record";
    static constexpr const char* ALIAS = "ApplyStatusEffectByChanceEffector_Record";

#ifdef __APPLE__
    uint8_t unkD8[0xE8 - 0xD8]; // D8
#else
    uint8_t unkE0[0xF0 - 0xE0]; // E0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ApplyStatusEffectByChanceEffector_Record, 0xE8);
#else
RED4EXT_ASSERT_SIZE(ApplyStatusEffectByChanceEffector_Record, 0xF0);
#endif
} // namespace game::data
using gamedataApplyStatusEffectByChanceEffector_Record = game::data::ApplyStatusEffectByChanceEffector_Record;
using ApplyStatusEffectByChanceEffector_Record = game::data::ApplyStatusEffectByChanceEffector_Record;
} // namespace RED4ext

// clang-format on
