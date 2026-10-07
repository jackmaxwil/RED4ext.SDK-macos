#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/WidgetGameController.hpp>

namespace RED4ext
{
namespace game::ui
{
struct HUDGameController : game::ui::WidgetGameController
{
    static constexpr const char* NAME = "gameuiHUDGameController";
    static constexpr const char* ALIAS = "inkHUDGameController";

#ifdef __APPLE__
    uint8_t unkDC[0xF8 - 0xDC]; // DC
#else
    uint8_t unkE0[0xF8 - 0xE0]; // E0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(HUDGameController, 0xF8);
#else
RED4EXT_ASSERT_SIZE(HUDGameController, 0xF8);
#endif
} // namespace game::ui
using gameuiHUDGameController = game::ui::HUDGameController;
using inkHUDGameController = game::ui::HUDGameController;
} // namespace RED4ext

// clang-format on
