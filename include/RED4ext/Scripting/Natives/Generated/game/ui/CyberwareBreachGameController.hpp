#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector2.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/WidgetGameController.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/WidgetReference.hpp>

namespace RED4ext
{
namespace game::ui
{
struct CyberwareBreachGameController : game::ui::WidgetGameController
{
    static constexpr const char* NAME = "gameuiCyberwareBreachGameController";
    static constexpr const char* ALIAS = "gameaiCyberwareBreachGameController";

#ifdef __APPLE__
    uint8_t unkDC[0xE0 - 0xDC]; // DC
    ink::WidgetReference strokeHealthDepleation; // E0
    Vector2 adjustedScreenPosition; // F8
    uint8_t unk100[0x114 - 0x100]; // 100
    float maxHealth; // 114
    float currentHealth; // 118
    float lastHealth; // 11C
    uint8_t unk120[0x128 - 0x120]; // 120
#else
    ink::WidgetReference strokeHealthDepleation; // E0
    Vector2 adjustedScreenPosition; // F8
    uint8_t unk100[0x114 - 0x100]; // 100
    float maxHealth; // 114
    float currentHealth; // 118
    float lastHealth; // 11C
    uint8_t unk120[0x128 - 0x120]; // 120
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CyberwareBreachGameController, 0x128);
RED4EXT_ASSERT_OFFSET(CyberwareBreachGameController, strokeHealthDepleation, 0xE0);
RED4EXT_ASSERT_OFFSET(CyberwareBreachGameController, adjustedScreenPosition, 0xF8);
RED4EXT_ASSERT_OFFSET(CyberwareBreachGameController, maxHealth, 0x114);
RED4EXT_ASSERT_OFFSET(CyberwareBreachGameController, currentHealth, 0x118);
RED4EXT_ASSERT_OFFSET(CyberwareBreachGameController, lastHealth, 0x11C);
#else
RED4EXT_ASSERT_SIZE(CyberwareBreachGameController, 0x128);
#endif
} // namespace game::ui
using gameuiCyberwareBreachGameController = game::ui::CyberwareBreachGameController;
using gameaiCyberwareBreachGameController = game::ui::CyberwareBreachGameController;
} // namespace RED4ext

// clang-format on
