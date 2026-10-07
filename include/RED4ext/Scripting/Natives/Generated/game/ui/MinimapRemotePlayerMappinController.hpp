#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/BaseMinimapMappinController.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/WidgetReference.hpp>

namespace RED4ext
{
namespace game::ui
{
struct MinimapRemotePlayerMappinController : game::ui::BaseMinimapMappinController
{
    static constexpr const char* NAME = "gameuiMinimapRemotePlayerMappinController";
    static constexpr const char* ALIAS = "MinimapRemotePlayerMappinController";

#ifdef __APPLE__
    uint8_t unk224[0x228 - 0x224]; // 224
    ink::WidgetReference rootWidget; // 228
    ink::WidgetReference shapeWidget; // 240
    ink::WidgetReference dataWidget; // 258
#else
    ink::WidgetReference rootWidget; // 228
    ink::WidgetReference shapeWidget; // 240
    ink::WidgetReference dataWidget; // 258
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MinimapRemotePlayerMappinController, 0x270);
RED4EXT_ASSERT_OFFSET(MinimapRemotePlayerMappinController, rootWidget, 0x228);
RED4EXT_ASSERT_OFFSET(MinimapRemotePlayerMappinController, shapeWidget, 0x240);
RED4EXT_ASSERT_OFFSET(MinimapRemotePlayerMappinController, dataWidget, 0x258);
#else
RED4EXT_ASSERT_SIZE(MinimapRemotePlayerMappinController, 0x270);
#endif
} // namespace game::ui
using gameuiMinimapRemotePlayerMappinController = game::ui::MinimapRemotePlayerMappinController;
using MinimapRemotePlayerMappinController = game::ui::MinimapRemotePlayerMappinController;
} // namespace RED4ext

// clang-format on
