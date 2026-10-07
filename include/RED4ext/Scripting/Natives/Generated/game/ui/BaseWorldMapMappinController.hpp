#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/InteractionMappinController.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/MappinGroupState.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/TextWidgetReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/WidgetReference.hpp>

namespace RED4ext
{
namespace game::ui
{
struct __declspec(align(0x10)) BaseWorldMapMappinController : game::ui::InteractionMappinController
{
    static constexpr const char* NAME = "gameuiBaseWorldMapMappinController";
    static constexpr const char* ALIAS = "BaseWorldMapMappinController";

#ifdef __APPLE__
    bool selected; // 2B8
    bool inZoomLevel; // 2B9
    bool inCustomFilter; // 2BA
    bool hasCustomFilter; // 2BB
    bool isFastTravelEnabled; // 2BC
    bool isVisibleInFilterAndZoom; // 2BD
    uint8_t unk2BE[0x2D8 - 0x2BE]; // 2BE
    game::ui::MappinGroupState groupState; // 2D8
    uint8_t collectionCount; // 2DC
    uint8_t unk2DD[0x308 - 0x2DD]; // 2DD
    ink::WidgetReference groupContainerWidget; // 308
    ink::TextWidgetReference groupCountTextWidget; // 320
    uint8_t unk338[0x340 - 0x338]; // 338
#else
    bool selected; // 2C0
    bool inZoomLevel; // 2C1
    bool inCustomFilter; // 2C2
    bool hasCustomFilter; // 2C3
    bool isFastTravelEnabled; // 2C4
    bool isVisibleInFilterAndZoom; // 2C5
    uint8_t unk2C6[0x2E0 - 0x2C6]; // 2C6
    game::ui::MappinGroupState groupState; // 2E0
    uint8_t collectionCount; // 2E4
    uint8_t unk2E5[0x310 - 0x2E5]; // 2E5
    ink::WidgetReference groupContainerWidget; // 310
    ink::TextWidgetReference groupCountTextWidget; // 328
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(BaseWorldMapMappinController, 0x340);
RED4EXT_ASSERT_OFFSET(BaseWorldMapMappinController, selected, 0x2B8);
RED4EXT_ASSERT_OFFSET(BaseWorldMapMappinController, inZoomLevel, 0x2B9);
RED4EXT_ASSERT_OFFSET(BaseWorldMapMappinController, inCustomFilter, 0x2BA);
RED4EXT_ASSERT_OFFSET(BaseWorldMapMappinController, hasCustomFilter, 0x2BB);
RED4EXT_ASSERT_OFFSET(BaseWorldMapMappinController, isFastTravelEnabled, 0x2BC);
RED4EXT_ASSERT_OFFSET(BaseWorldMapMappinController, isVisibleInFilterAndZoom, 0x2BD);
RED4EXT_ASSERT_OFFSET(BaseWorldMapMappinController, groupState, 0x2D8);
RED4EXT_ASSERT_OFFSET(BaseWorldMapMappinController, collectionCount, 0x2DC);
RED4EXT_ASSERT_OFFSET(BaseWorldMapMappinController, groupContainerWidget, 0x308);
RED4EXT_ASSERT_OFFSET(BaseWorldMapMappinController, groupCountTextWidget, 0x320);
#else
RED4EXT_ASSERT_SIZE(BaseWorldMapMappinController, 0x340);
#endif
} // namespace game::ui
using gameuiBaseWorldMapMappinController = game::ui::BaseWorldMapMappinController;
using BaseWorldMapMappinController = game::ui::BaseWorldMapMappinController;
} // namespace RED4ext

// clang-format on
