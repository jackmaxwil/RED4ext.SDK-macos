#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/WidgetGameController.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/CompoundWidgetReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/WidgetLibraryReference.hpp>

namespace RED4ext
{
namespace game::ui
{
struct InputHintManagerGameController : game::ui::WidgetGameController
{
    static constexpr const char* NAME = "gameuiInputHintManagerGameController";
    static constexpr const char* ALIAS = "InputHintManagerGameController";

#ifdef __APPLE__
    uint8_t unkDC[0x178 - 0xDC]; // DC
    ink::CompoundWidgetReference baseGroupContainer; // 178
    ink::CompoundWidgetReference groupsContainer; // 190
    ink::WidgetLibraryReference hintLibRef; // 1A8
    ink::WidgetLibraryReference groupLibRef; // 1B8
    uint8_t unk1C8[0x1D8 - 0x1C8]; // 1C8
    CName hintContainerId; // 1D8
    uint8_t unk1E0[0x1F8 - 0x1E0]; // 1E0
#else
    uint8_t unkE0[0x178 - 0xE0]; // E0
    ink::CompoundWidgetReference baseGroupContainer; // 178
    ink::CompoundWidgetReference groupsContainer; // 190
    ink::WidgetLibraryReference hintLibRef; // 1A8
    ink::WidgetLibraryReference groupLibRef; // 1B8
    uint8_t unk1C8[0x1D8 - 0x1C8]; // 1C8
    CName hintContainerId; // 1D8
    uint8_t unk1E0[0x1F8 - 0x1E0]; // 1E0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(InputHintManagerGameController, 0x1F8);
RED4EXT_ASSERT_OFFSET(InputHintManagerGameController, baseGroupContainer, 0x178);
RED4EXT_ASSERT_OFFSET(InputHintManagerGameController, groupsContainer, 0x190);
RED4EXT_ASSERT_OFFSET(InputHintManagerGameController, hintLibRef, 0x1A8);
RED4EXT_ASSERT_OFFSET(InputHintManagerGameController, groupLibRef, 0x1B8);
RED4EXT_ASSERT_OFFSET(InputHintManagerGameController, hintContainerId, 0x1D8);
#else
RED4EXT_ASSERT_SIZE(InputHintManagerGameController, 0x1F8);
#endif
} // namespace game::ui
using gameuiInputHintManagerGameController = game::ui::InputHintManagerGameController;
using InputHintManagerGameController = game::ui::InputHintManagerGameController;
} // namespace RED4ext

// clang-format on
