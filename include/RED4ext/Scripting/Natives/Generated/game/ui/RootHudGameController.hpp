#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/WidgetGameController.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/CompoundWidgetReference.hpp>

namespace RED4ext
{
namespace game::ui
{
struct RootHudGameController : game::ui::WidgetGameController
{
    static constexpr const char* NAME = "gameuiRootHudGameController";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unkDC[0x2C0 - 0xDC]; // DC
    DynArray<ink::CompoundWidgetReference> resolutionSensitiveRoots; // 2C0
    uint8_t unk2D0[0x328 - 0x2D0]; // 2D0
#else
    uint8_t unkE0[0x2C0 - 0xE0]; // E0
    DynArray<ink::CompoundWidgetReference> resolutionSensitiveRoots; // 2C0
    uint8_t unk2D0[0x328 - 0x2D0]; // 2D0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(RootHudGameController, 0x328);
RED4EXT_ASSERT_OFFSET(RootHudGameController, resolutionSensitiveRoots, 0x2C0);
#else
RED4EXT_ASSERT_SIZE(RootHudGameController, 0x328);
#endif
} // namespace game::ui
using gameuiRootHudGameController = game::ui::RootHudGameController;
} // namespace RED4ext

// clang-format on
