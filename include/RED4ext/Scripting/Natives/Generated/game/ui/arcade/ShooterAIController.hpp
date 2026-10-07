#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/arcade/ShooterAIBase.hpp>

namespace RED4ext
{
namespace game::ui::arcade
{
struct __declspec(align(0x10)) ShooterAIController : game::ui::arcade::ShooterAIBase
{
    static constexpr const char* NAME = "gameuiarcadeShooterAIController";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk260[0x270 - 0x260]; // 260
#else
    uint8_t unk260[0x280 - 0x260]; // 260
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ShooterAIController, 0x270);
#else
RED4EXT_ASSERT_SIZE(ShooterAIController, 0x280);
#endif
} // namespace game::ui::arcade
using gameuiarcadeShooterAIController = game::ui::arcade::ShooterAIController;
} // namespace RED4ext

// clang-format on
