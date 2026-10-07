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
struct MinimapPingSystemMappinController : game::ui::BaseMinimapMappinController
{
    static constexpr const char* NAME = "gameuiMinimapPingSystemMappinController";
    static constexpr const char* ALIAS = "MinimapPingSystemMappinController";

#ifdef __APPLE__
    uint8_t unk224[0x228 - 0x224]; // 224
    ink::WidgetReference rootWidget; // 228
#else
    ink::WidgetReference rootWidget; // 228
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MinimapPingSystemMappinController, 0x240);
RED4EXT_ASSERT_OFFSET(MinimapPingSystemMappinController, rootWidget, 0x228);
#else
RED4EXT_ASSERT_SIZE(MinimapPingSystemMappinController, 0x240);
#endif
} // namespace game::ui
using gameuiMinimapPingSystemMappinController = game::ui::MinimapPingSystemMappinController;
using MinimapPingSystemMappinController = game::ui::MinimapPingSystemMappinController;
} // namespace RED4ext

// clang-format on
