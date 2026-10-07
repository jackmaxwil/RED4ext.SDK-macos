#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector2.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/arcade/ShooterAIBase.hpp>

namespace RED4ext
{
namespace game::ui::arcade
{
struct __declspec(align(0x10)) ShooterBossController : game::ui::arcade::ShooterAIBase
{
    static constexpr const char* NAME = "gameuiarcadeShooterBossController";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk260[0x266 - 0x260]; // 260
    bool customBoundSize; // 266
    uint8_t unk267[0x26C - 0x267]; // 267
    Vector2 bossSize; // 26C
    uint8_t unk274[0x280 - 0x274]; // 274
#else
    uint8_t unk260[0x26E - 0x260]; // 260
    bool customBoundSize; // 26E
    uint8_t unk26F[0x274 - 0x26F]; // 26F
    Vector2 bossSize; // 274
    uint8_t unk27C[0x280 - 0x27C]; // 27C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ShooterBossController, 0x280);
RED4EXT_ASSERT_OFFSET(ShooterBossController, customBoundSize, 0x266);
RED4EXT_ASSERT_OFFSET(ShooterBossController, bossSize, 0x26C);
#else
RED4EXT_ASSERT_SIZE(ShooterBossController, 0x280);
#endif
} // namespace game::ui::arcade
using gameuiarcadeShooterBossController = game::ui::arcade::ShooterBossController;
} // namespace RED4ext

// clang-format on
