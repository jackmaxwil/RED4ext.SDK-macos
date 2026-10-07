#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector2.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/SideScrollerMiniGameDynObjectLogicAdvanced.hpp>

namespace RED4ext
{
namespace game::ui
{
struct PanzerEnemy : game::ui::SideScrollerMiniGameDynObjectLogicAdvanced
{
    static constexpr const char* NAME = "gameuiPanzerEnemy";
    static constexpr const char* ALIAS = "PanzerEnemy";

#ifdef __APPLE__
    uint8_t unkD0[0xDC - 0xD0]; // D0
    int32_t health; // DC
    uint32_t score; // E0
    Vector2 shootPoint; // E4
    float bulletSpeed; // EC
    CName bulletLibraryName; // F0
    CName gameLayerName; // F8
    CName explosionLibraryName; // 100
    CName lifeBonusLibraryName; // 108
    uint32_t lifeBonusChanceCoeff; // 110
    uint8_t unk114[0x118 - 0x114]; // 114
    CName scoreBonusLibraryName; // 118
    uint32_t scoreBonusChanceCoeff; // 120
    uint32_t score50ChanceCoeff; // 124
    uint32_t score100ChanceCoeff; // 128
    uint32_t score200ChanceCoeff; // 12C
    uint32_t noBonusChanceCoeff; // 130
#else
    uint8_t unkD0[0xDC - 0xD0]; // D0
    int32_t health; // DC
    uint32_t score; // E0
    Vector2 shootPoint; // E4
    float bulletSpeed; // EC
    CName bulletLibraryName; // F0
    CName gameLayerName; // F8
    CName explosionLibraryName; // 100
    CName lifeBonusLibraryName; // 108
    uint32_t lifeBonusChanceCoeff; // 110
    uint8_t unk114[0x118 - 0x114]; // 114
    CName scoreBonusLibraryName; // 118
    uint32_t scoreBonusChanceCoeff; // 120
    uint32_t score50ChanceCoeff; // 124
    uint32_t score100ChanceCoeff; // 128
    uint32_t score200ChanceCoeff; // 12C
    uint32_t noBonusChanceCoeff; // 130
    uint8_t unk134[0x138 - 0x134]; // 134
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PanzerEnemy, 0x138);
RED4EXT_ASSERT_OFFSET(PanzerEnemy, health, 0xDC);
RED4EXT_ASSERT_OFFSET(PanzerEnemy, score, 0xE0);
RED4EXT_ASSERT_OFFSET(PanzerEnemy, shootPoint, 0xE4);
RED4EXT_ASSERT_OFFSET(PanzerEnemy, bulletSpeed, 0xEC);
RED4EXT_ASSERT_OFFSET(PanzerEnemy, bulletLibraryName, 0xF0);
RED4EXT_ASSERT_OFFSET(PanzerEnemy, gameLayerName, 0xF8);
RED4EXT_ASSERT_OFFSET(PanzerEnemy, explosionLibraryName, 0x100);
RED4EXT_ASSERT_OFFSET(PanzerEnemy, lifeBonusLibraryName, 0x108);
RED4EXT_ASSERT_OFFSET(PanzerEnemy, lifeBonusChanceCoeff, 0x110);
RED4EXT_ASSERT_OFFSET(PanzerEnemy, scoreBonusLibraryName, 0x118);
RED4EXT_ASSERT_OFFSET(PanzerEnemy, scoreBonusChanceCoeff, 0x120);
RED4EXT_ASSERT_OFFSET(PanzerEnemy, score50ChanceCoeff, 0x124);
RED4EXT_ASSERT_OFFSET(PanzerEnemy, score100ChanceCoeff, 0x128);
RED4EXT_ASSERT_OFFSET(PanzerEnemy, score200ChanceCoeff, 0x12C);
RED4EXT_ASSERT_OFFSET(PanzerEnemy, noBonusChanceCoeff, 0x130);
#else
RED4EXT_ASSERT_SIZE(PanzerEnemy, 0x138);
#endif
} // namespace game::ui
using gameuiPanzerEnemy = game::ui::PanzerEnemy;
using PanzerEnemy = game::ui::PanzerEnemy;
} // namespace RED4ext

// clang-format on
