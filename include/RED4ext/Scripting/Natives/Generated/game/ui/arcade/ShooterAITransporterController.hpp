#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/arcade/ShooterAIController.hpp>

namespace RED4ext
{
namespace game::ui::arcade
{
struct __declspec(align(0x10)) ShooterAITransporterController : game::ui::arcade::ShooterAIController
{
    static constexpr const char* NAME = "gameuiarcadeShooterAITransporterController";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk270[0x2B0 - 0x270]; // 270
#else
    uint8_t unk280[0x2C0 - 0x280]; // 280
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ShooterAITransporterController, 0x2B0);
#else
RED4EXT_ASSERT_SIZE(ShooterAITransporterController, 0x2C0);
#endif
} // namespace game::ui::arcade
using gameuiarcadeShooterAITransporterController = game::ui::arcade::ShooterAITransporterController;
} // namespace RED4ext

// clang-format on
