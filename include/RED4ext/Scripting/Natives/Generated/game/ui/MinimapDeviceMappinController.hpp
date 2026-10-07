#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/BaseMinimapMappinController.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/CircleWidgetReference.hpp>

namespace RED4ext
{
namespace game::ui
{
struct MinimapDeviceMappinController : game::ui::BaseMinimapMappinController
{
    static constexpr const char* NAME = "gameuiMinimapDeviceMappinController";
    static constexpr const char* ALIAS = "MinimapDeviceMappinController";

#ifdef __APPLE__
    uint8_t unk224[0x228 - 0x224]; // 224
    ink::CircleWidgetReference effectAreaWidget; // 228
#else
    uint8_t unk228[0x230 - 0x228]; // 228
    ink::CircleWidgetReference effectAreaWidget; // 230
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MinimapDeviceMappinController, 0x240);
RED4EXT_ASSERT_OFFSET(MinimapDeviceMappinController, effectAreaWidget, 0x228);
#else
RED4EXT_ASSERT_SIZE(MinimapDeviceMappinController, 0x248);
#endif
} // namespace game::ui
using gameuiMinimapDeviceMappinController = game::ui::MinimapDeviceMappinController;
using MinimapDeviceMappinController = game::ui::MinimapDeviceMappinController;
} // namespace RED4ext

// clang-format on
