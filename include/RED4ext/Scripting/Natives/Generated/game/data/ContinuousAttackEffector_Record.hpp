#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/ContinuousEffector_Record.hpp>

namespace RED4ext
{
namespace game::data
{
struct ContinuousAttackEffector_Record : game::data::ContinuousEffector_Record
{
    static constexpr const char* NAME = "gamedataContinuousAttackEffector_Record";
    static constexpr const char* ALIAS = "ContinuousAttackEffector_Record";

#ifdef __APPLE__
    uint8_t unkA0[0xA8 - 0xA0]; // A0
#else
    uint8_t unkA0[0xB0 - 0xA0]; // A0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ContinuousAttackEffector_Record, 0xA8);
#else
RED4EXT_ASSERT_SIZE(ContinuousAttackEffector_Record, 0xB0);
#endif
} // namespace game::data
using gamedataContinuousAttackEffector_Record = game::data::ContinuousAttackEffector_Record;
using ContinuousAttackEffector_Record = game::data::ContinuousAttackEffector_Record;
} // namespace RED4ext

// clang-format on
