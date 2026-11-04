#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/ModLogoInfoReceivedCallback.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/WidgetGameController.hpp>

namespace RED4ext
{
namespace game::ui
{
struct UpdateModsPopupController : game::ui::WidgetGameController
{
    static constexpr const char* NAME = "gameuiUpdateModsPopupController";
    static constexpr const char* ALIAS = "UpdateModsPopupController";

#ifdef __APPLE__
    uint8_t unkDC[0xE8 - 0xDC]; // DC
    game::ui::ModLogoInfoReceivedCallback ReceivedModLogo; // E8
    uint8_t unk120[0x148 - 0x120]; // 120
#else
    uint8_t unkE0[0xE8 - 0xE0]; // E0
    game::ui::ModLogoInfoReceivedCallback ReceivedModLogo; // E8
    uint8_t unk120[0x148 - 0x120]; // 120
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(UpdateModsPopupController, 0x148);
RED4EXT_ASSERT_OFFSET(UpdateModsPopupController, ReceivedModLogo, 0xE8);
#else
RED4EXT_ASSERT_SIZE(UpdateModsPopupController, 0x148);
#endif
} // namespace game::ui
using gameuiUpdateModsPopupController = game::ui::UpdateModsPopupController;
using UpdateModsPopupController = game::ui::UpdateModsPopupController;
} // namespace RED4ext

// clang-format on
