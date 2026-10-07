#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/WidgetGameController.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/BriefingPlayerType.hpp>

namespace RED4ext
{
namespace game::ui
{
struct BriefingGameController : game::ui::WidgetGameController
{
    static constexpr const char* NAME = "gameuiBriefingGameController";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unkDC[0x1D0 - 0xDC]; // DC
    quest::BriefingPlayerType briefingPlayerType; // 1D0
    uint8_t unk1D4[0x1E8 - 0x1D4]; // 1D4
#else
    uint8_t unkE0[0x1D8 - 0xE0]; // E0
    quest::BriefingPlayerType briefingPlayerType; // 1D8
    uint8_t unk1DC[0x1F0 - 0x1DC]; // 1DC
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(BriefingGameController, 0x1E8);
RED4EXT_ASSERT_OFFSET(BriefingGameController, briefingPlayerType, 0x1D0);
#else
RED4EXT_ASSERT_SIZE(BriefingGameController, 0x1F0);
#endif
} // namespace game::ui
using gameuiBriefingGameController = game::ui::BriefingGameController;
} // namespace RED4ext

// clang-format on
