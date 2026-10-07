#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/HoldIndicatorProgressCallback.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/WidgetGameController.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/EmptyCallback.hpp>

namespace RED4ext
{
namespace game::ui
{
struct HoldIndicatorGameController : game::ui::WidgetGameController
{
    static constexpr const char* NAME = "gameuiHoldIndicatorGameController";
    static constexpr const char* ALIAS = "HoldIndicatorGameController";

#ifdef __APPLE__
    uint8_t unkDC[0xE0 - 0xDC]; // DC
    game::ui::HoldIndicatorProgressCallback HoldProgress; // E0
    ink::EmptyCallback HoldStart; // 118
    ink::EmptyCallback HoldFinish; // 150
    ink::EmptyCallback HoldStop; // 188
    uint8_t unk1C0[0x1E8 - 0x1C0]; // 1C0
#else
    game::ui::HoldIndicatorProgressCallback HoldProgress; // E0
    ink::EmptyCallback HoldStart; // 118
    ink::EmptyCallback HoldFinish; // 150
    ink::EmptyCallback HoldStop; // 188
    uint8_t unk1C0[0x1E8 - 0x1C0]; // 1C0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(HoldIndicatorGameController, 0x1E8);
RED4EXT_ASSERT_OFFSET(HoldIndicatorGameController, HoldProgress, 0xE0);
RED4EXT_ASSERT_OFFSET(HoldIndicatorGameController, HoldStart, 0x118);
RED4EXT_ASSERT_OFFSET(HoldIndicatorGameController, HoldFinish, 0x150);
RED4EXT_ASSERT_OFFSET(HoldIndicatorGameController, HoldStop, 0x188);
#else
RED4EXT_ASSERT_SIZE(HoldIndicatorGameController, 0x1E8);
#endif
} // namespace game::ui
using gameuiHoldIndicatorGameController = game::ui::HoldIndicatorGameController;
using HoldIndicatorGameController = game::ui::HoldIndicatorGameController;
} // namespace RED4ext

// clang-format on
