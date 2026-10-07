#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/ui/IWidgetGameController.hpp>

namespace RED4ext
{
namespace game::ui
{
struct WidgetGameController : world::ui::IWidgetGameController
{
    static constexpr const char* NAME = "gameuiWidgetGameController";
    static constexpr const char* ALIAS = "inkGameController";

#ifdef __APPLE__
    uint8_t unkD0[0xDC - 0xD0]; // D0
#else
    uint8_t unkD0[0xE0 - 0xD0]; // D0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(WidgetGameController, 0xE0);
#else
RED4EXT_ASSERT_SIZE(WidgetGameController, 0xE0);
#endif
} // namespace game::ui
using gameuiWidgetGameController = game::ui::WidgetGameController;
using inkGameController = game::ui::WidgetGameController;
} // namespace RED4ext

// clang-format on
