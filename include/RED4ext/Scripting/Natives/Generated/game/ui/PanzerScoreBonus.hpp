#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/PanzerBonus.hpp>

namespace RED4ext
{
namespace game::ui
{
struct PanzerScoreBonus : game::ui::PanzerBonus
{
    static constexpr const char* NAME = "gameuiPanzerScoreBonus";
    static constexpr const char* ALIAS = "PanzerScoreBonus";

#ifdef __APPLE__
#else
    uint8_t unkE8[0xF0 - 0xE8]; // E8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PanzerScoreBonus, 0xE8);
#else
RED4EXT_ASSERT_SIZE(PanzerScoreBonus, 0xF0);
#endif
} // namespace game::ui
using gameuiPanzerScoreBonus = game::ui::PanzerScoreBonus;
using PanzerScoreBonus = game::ui::PanzerScoreBonus;
} // namespace RED4ext

// clang-format on
