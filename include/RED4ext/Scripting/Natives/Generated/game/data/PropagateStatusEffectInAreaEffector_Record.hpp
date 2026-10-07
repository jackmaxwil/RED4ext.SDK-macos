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
struct PropagateStatusEffectInAreaEffector_Record : game::data::Effector_Record
{
    static constexpr const char* NAME = "gamedataPropagateStatusEffectInAreaEffector_Record";
    static constexpr const char* ALIAS = "PropagateStatusEffectInAreaEffector_Record";

#ifdef __APPLE__
    uint8_t unk88[0xC0 - 0x88]; // 88
#else
    uint8_t unk88[0xC8 - 0x88]; // 88
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PropagateStatusEffectInAreaEffector_Record, 0xC0);
#else
RED4EXT_ASSERT_SIZE(PropagateStatusEffectInAreaEffector_Record, 0xC8);
#endif
} // namespace game::data
using gamedataPropagateStatusEffectInAreaEffector_Record = game::data::PropagateStatusEffectInAreaEffector_Record;
using PropagateStatusEffectInAreaEffector_Record = game::data::PropagateStatusEffectInAreaEffector_Record;
} // namespace RED4ext

// clang-format on
