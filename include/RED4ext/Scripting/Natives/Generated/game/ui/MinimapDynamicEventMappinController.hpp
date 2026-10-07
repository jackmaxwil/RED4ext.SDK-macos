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
struct MinimapDynamicEventMappinController : game::ui::BaseMinimapMappinController
{
    static constexpr const char* NAME = "gameuiMinimapDynamicEventMappinController";
    static constexpr const char* ALIAS = "MinimapDynamicEventMappinController";

#ifdef __APPLE__
    bool pulseEnabled; // 224
    uint8_t unk225[0x228 - 0x225]; // 225
    ink::WidgetReference pulseWidget; // 228
    float hideAtDistance; // 240
    bool hideInCombat; // 244
    uint8_t unk245[0x248 - 0x245]; // 245
#else
    bool pulseEnabled; // 228
    uint8_t unk229[0x230 - 0x229]; // 229
    ink::WidgetReference pulseWidget; // 230
    float hideAtDistance; // 248
    bool hideInCombat; // 24C
    uint8_t unk24D[0x250 - 0x24D]; // 24D
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MinimapDynamicEventMappinController, 0x248);
RED4EXT_ASSERT_OFFSET(MinimapDynamicEventMappinController, pulseEnabled, 0x224);
RED4EXT_ASSERT_OFFSET(MinimapDynamicEventMappinController, pulseWidget, 0x228);
RED4EXT_ASSERT_OFFSET(MinimapDynamicEventMappinController, hideAtDistance, 0x240);
RED4EXT_ASSERT_OFFSET(MinimapDynamicEventMappinController, hideInCombat, 0x244);
#else
RED4EXT_ASSERT_SIZE(MinimapDynamicEventMappinController, 0x250);
#endif
} // namespace game::ui
using gameuiMinimapDynamicEventMappinController = game::ui::MinimapDynamicEventMappinController;
using MinimapDynamicEventMappinController = game::ui::MinimapDynamicEventMappinController;
} // namespace RED4ext

// clang-format on
