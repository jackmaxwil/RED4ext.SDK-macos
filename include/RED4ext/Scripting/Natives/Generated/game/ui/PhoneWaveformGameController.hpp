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
struct PhoneWaveformGameController : game::ui::WidgetGameController
{
    static constexpr const char* NAME = "gameuiPhoneWaveformGameController";
    static constexpr const char* ALIAS = "PhoneWaveformGameController";

#ifdef __APPLE__
    uint8_t unkDC[0xF0 - 0xDC]; // DC
    int32_t measurementsCount; // F0
    float measurementsIntreval; // F4
    uint8_t unkF8[0x100 - 0xF8]; // F8
#else
    uint8_t unkE0[0xF0 - 0xE0]; // E0
    int32_t measurementsCount; // F0
    float measurementsIntreval; // F4
    uint8_t unkF8[0x100 - 0xF8]; // F8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PhoneWaveformGameController, 0x100);
RED4EXT_ASSERT_OFFSET(PhoneWaveformGameController, measurementsCount, 0xF0);
RED4EXT_ASSERT_OFFSET(PhoneWaveformGameController, measurementsIntreval, 0xF4);
#else
RED4EXT_ASSERT_SIZE(PhoneWaveformGameController, 0x100);
#endif
} // namespace game::ui
using gameuiPhoneWaveformGameController = game::ui::PhoneWaveformGameController;
using PhoneWaveformGameController = game::ui::PhoneWaveformGameController;
} // namespace RED4ext

// clang-format on
