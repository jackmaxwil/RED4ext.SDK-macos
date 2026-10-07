#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/PanzerEnemy.hpp>

namespace RED4ext
{
namespace game::ui
{
struct PanzerEnemyDrone : game::ui::PanzerEnemy
{
    static constexpr const char* NAME = "gameuiPanzerEnemyDrone";
    static constexpr const char* ALIAS = "PanzerEnemyDrone";

#ifdef __APPLE__
    float speed; // 134
    float shootIntervalMinimum; // 138
    float shootIntervalMaximum; // 13C
    uint8_t unk140[0x148 - 0x140]; // 140
#else
    float speed; // 138
    float shootIntervalMinimum; // 13C
    float shootIntervalMaximum; // 140
    uint8_t unk144[0x150 - 0x144]; // 144
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PanzerEnemyDrone, 0x148);
RED4EXT_ASSERT_OFFSET(PanzerEnemyDrone, speed, 0x134);
RED4EXT_ASSERT_OFFSET(PanzerEnemyDrone, shootIntervalMinimum, 0x138);
RED4EXT_ASSERT_OFFSET(PanzerEnemyDrone, shootIntervalMaximum, 0x13C);
#else
RED4EXT_ASSERT_SIZE(PanzerEnemyDrone, 0x150);
#endif
} // namespace game::ui
using gameuiPanzerEnemyDrone = game::ui::PanzerEnemyDrone;
using PanzerEnemyDrone = game::ui::PanzerEnemyDrone;
} // namespace RED4ext

// clang-format on
