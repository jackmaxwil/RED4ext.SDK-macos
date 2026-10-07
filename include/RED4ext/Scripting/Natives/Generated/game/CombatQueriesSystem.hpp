#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ICombatQueriesSystem.hpp>

namespace RED4ext
{
namespace game
{
struct __declspec(align(0x10)) CombatQueriesSystem : game::ICombatQueriesSystem
{
    static constexpr const char* NAME = "gameCombatQueriesSystem";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk48[0x1CD0 - 0x48]; // 48
#else
    uint8_t unk48[0x1DD0 - 0x48]; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CombatQueriesSystem, 0x1CD0);
#else
RED4EXT_ASSERT_SIZE(CombatQueriesSystem, 0x1DD0);
#endif
} // namespace game
using gameCombatQueriesSystem = game::CombatQueriesSystem;
} // namespace RED4ext

// clang-format on
