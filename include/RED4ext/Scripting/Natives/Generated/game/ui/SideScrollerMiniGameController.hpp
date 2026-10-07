#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/WidgetGameController.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/WidgetReference.hpp>

namespace RED4ext
{
namespace game::ui
{
struct SideScrollerMiniGameController : game::ui::WidgetGameController
{
    static constexpr const char* NAME = "gameuiSideScrollerMiniGameController";
    static constexpr const char* ALIAS = "MinigameController";

#ifdef __APPLE__
    uint8_t unkDC[0xE0 - 0xDC]; // DC
    CName gameName; // E0
    uint8_t unkE8[0x100 - 0xE8]; // E8
    ink::WidgetReference gameplayCanvas; // 100
#else
    CName gameName; // E0
    uint8_t unkE8[0x100 - 0xE8]; // E8
    ink::WidgetReference gameplayCanvas; // 100
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SideScrollerMiniGameController, 0x118);
RED4EXT_ASSERT_OFFSET(SideScrollerMiniGameController, gameName, 0xE0);
RED4EXT_ASSERT_OFFSET(SideScrollerMiniGameController, gameplayCanvas, 0x100);
#else
RED4EXT_ASSERT_SIZE(SideScrollerMiniGameController, 0x118);
#endif
} // namespace game::ui
using gameuiSideScrollerMiniGameController = game::ui::SideScrollerMiniGameController;
using MinigameController = game::ui::SideScrollerMiniGameController;
} // namespace RED4ext

// clang-format on
