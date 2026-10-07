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
struct NewPhoneRelatedGameController : game::ui::WidgetGameController
{
    static constexpr const char* NAME = "gameuiNewPhoneRelatedGameController";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool isNewPhoneEnabled; // DC
    uint8_t unkDD[0xE0 - 0xDD]; // DD
#else
    bool isNewPhoneEnabled; // E0
    uint8_t unkE1[0xE8 - 0xE1]; // E1
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(NewPhoneRelatedGameController, 0xE0);
RED4EXT_ASSERT_OFFSET(NewPhoneRelatedGameController, isNewPhoneEnabled, 0xDC);
#else
RED4EXT_ASSERT_SIZE(NewPhoneRelatedGameController, 0xE8);
#endif
} // namespace game::ui
using gameuiNewPhoneRelatedGameController = game::ui::NewPhoneRelatedGameController;
} // namespace RED4ext

// clang-format on
