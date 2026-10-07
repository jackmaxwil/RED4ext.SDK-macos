#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/IRPGPrereq.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/StatType.hpp>

namespace RED4ext
{
namespace game
{
struct StatPrereq : game::IRPGPrereq
{
    static constexpr const char* NAME = "gameStatPrereq";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    game::data::StatType statType; // 44
    float valueToCheck; // 48
    uint8_t unk4C[0x50 - 0x4C]; // 4C
#else
    game::data::StatType statType; // 48
    float valueToCheck; // 4C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(StatPrereq, 0x50);
RED4EXT_ASSERT_OFFSET(StatPrereq, statType, 0x44);
RED4EXT_ASSERT_OFFSET(StatPrereq, valueToCheck, 0x48);
#else
RED4EXT_ASSERT_SIZE(StatPrereq, 0x50);
#endif
} // namespace game
using gameStatPrereq = game::StatPrereq;
} // namespace RED4ext

// clang-format on
