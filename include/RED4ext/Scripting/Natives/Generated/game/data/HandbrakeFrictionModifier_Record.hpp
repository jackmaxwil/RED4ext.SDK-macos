#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/DriveHelper_Record.hpp>

namespace RED4ext
{
namespace game::data
{
struct HandbrakeFrictionModifier_Record : game::data::DriveHelper_Record
{
    static constexpr const char* NAME = "gamedataHandbrakeFrictionModifier_Record";
    static constexpr const char* ALIAS = "HandbrakeFrictionModifier_Record";

#ifdef __APPLE__
    uint8_t unk58[0x90 - 0x58]; // 58
#else
    uint8_t unk58[0x98 - 0x58]; // 58
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(HandbrakeFrictionModifier_Record, 0x90);
#else
RED4EXT_ASSERT_SIZE(HandbrakeFrictionModifier_Record, 0x98);
#endif
} // namespace game::data
using gamedataHandbrakeFrictionModifier_Record = game::data::HandbrakeFrictionModifier_Record;
using HandbrakeFrictionModifier_Record = game::data::HandbrakeFrictionModifier_Record;
} // namespace RED4ext

// clang-format on
