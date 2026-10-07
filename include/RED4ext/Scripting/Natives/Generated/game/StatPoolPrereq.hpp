#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/IComparisonPrereq.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/StatPoolType.hpp>

namespace RED4ext
{
namespace game
{
struct StatPoolPrereq : game::IComparisonPrereq
{
    static constexpr const char* NAME = "gameStatPoolPrereq";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    game::data::StatPoolType statPoolType; // 44
    float valueToCheck; // 48
    uint8_t unk4C[0x50 - 0x4C]; // 4C
#else
    game::data::StatPoolType statPoolType; // 48
    float valueToCheck; // 4C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(StatPoolPrereq, 0x50);
RED4EXT_ASSERT_OFFSET(StatPoolPrereq, statPoolType, 0x44);
RED4EXT_ASSERT_OFFSET(StatPoolPrereq, valueToCheck, 0x48);
#else
RED4EXT_ASSERT_SIZE(StatPoolPrereq, 0x50);
#endif
} // namespace game
using gameStatPoolPrereq = game::StatPoolPrereq;
} // namespace RED4ext

// clang-format on
