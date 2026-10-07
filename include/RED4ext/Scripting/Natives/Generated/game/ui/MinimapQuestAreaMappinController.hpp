#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/BaseMinimapMappinController.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/ShapeWidgetReference.hpp>

namespace RED4ext
{
namespace game::ui
{
struct MinimapQuestAreaMappinController : game::ui::BaseMinimapMappinController
{
    static constexpr const char* NAME = "gameuiMinimapQuestAreaMappinController";
    static constexpr const char* ALIAS = "MinimapQuestAreaMappinController";

#ifdef __APPLE__
    uint8_t unk224[0x228 - 0x224]; // 224
    ink::ShapeWidgetReference areaShapeWidget; // 228
#else
    uint8_t unk228[0x230 - 0x228]; // 228
    ink::ShapeWidgetReference areaShapeWidget; // 230
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MinimapQuestAreaMappinController, 0x240);
RED4EXT_ASSERT_OFFSET(MinimapQuestAreaMappinController, areaShapeWidget, 0x228);
#else
RED4EXT_ASSERT_SIZE(MinimapQuestAreaMappinController, 0x248);
#endif
} // namespace game::ui
using gameuiMinimapQuestAreaMappinController = game::ui::MinimapQuestAreaMappinController;
using MinimapQuestAreaMappinController = game::ui::MinimapQuestAreaMappinController;
} // namespace RED4ext

// clang-format on
