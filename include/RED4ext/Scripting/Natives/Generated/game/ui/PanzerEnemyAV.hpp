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
struct PanzerEnemyAV : game::ui::PanzerEnemy
{
    static constexpr const char* NAME = "gameuiPanzerEnemyAV";
    static constexpr const char* ALIAS = "PanzerEnemyAV";

#ifdef __APPLE__
    float speed; // 134
    uint32_t shotsAmount; // 138
    float longShotInterval; // 13C
    float shortShotInterval; // 140
    uint8_t unk144[0x150 - 0x144]; // 144
#else
    float speed; // 138
    uint32_t shotsAmount; // 13C
    float longShotInterval; // 140
    float shortShotInterval; // 144
    uint8_t unk148[0x150 - 0x148]; // 148
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PanzerEnemyAV, 0x150);
RED4EXT_ASSERT_OFFSET(PanzerEnemyAV, speed, 0x134);
RED4EXT_ASSERT_OFFSET(PanzerEnemyAV, shotsAmount, 0x138);
RED4EXT_ASSERT_OFFSET(PanzerEnemyAV, longShotInterval, 0x13C);
RED4EXT_ASSERT_OFFSET(PanzerEnemyAV, shortShotInterval, 0x140);
#else
RED4EXT_ASSERT_SIZE(PanzerEnemyAV, 0x150);
#endif
} // namespace game::ui
using gameuiPanzerEnemyAV = game::ui::PanzerEnemyAV;
using PanzerEnemyAV = game::ui::PanzerEnemyAV;
} // namespace RED4ext

// clang-format on
