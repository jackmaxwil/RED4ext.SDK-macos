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
struct ApplyStatusEffectEffector_Record : game::data::Effector_Record
{
    static constexpr const char* NAME = "gamedataApplyStatusEffectEffector_Record";
    static constexpr const char* ALIAS = "ApplyStatusEffectEffector_Record";

#ifdef __APPLE__
    uint8_t unk88[0xD8 - 0x88]; // 88
#else
    uint8_t unk88[0xE0 - 0x88]; // 88
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ApplyStatusEffectEffector_Record, 0xD8);
#else
RED4EXT_ASSERT_SIZE(ApplyStatusEffectEffector_Record, 0xE0);
#endif
} // namespace game::data
using gamedataApplyStatusEffectEffector_Record = game::data::ApplyStatusEffectEffector_Record;
using ApplyStatusEffectEffector_Record = game::data::ApplyStatusEffectEffector_Record;
} // namespace RED4ext

// clang-format on
