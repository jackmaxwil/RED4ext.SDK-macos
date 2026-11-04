#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/AllLanguagesCheckboxCallback.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/FilterTagsReceivedCallback.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/MenuGameController.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/MenuIntCallback.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/MenuIntIntCallback.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/ReceivedHiddenModsListCallback.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/RequestMediaForWidgetCallback.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/SendModGridInfoCallback.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/SendModUpdateVerificationInfo.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/SendProcessedModProgressInfoCallback.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/SendSelectedModInfoCallback.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/UpdatePageLayoutCallback.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/BoolCallback.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/EmptyCallback.hpp>

namespace RED4ext
{
namespace game::ui
{
struct ModioBrowserMenuGameController : game::ui::MenuGameController
{
    static constexpr const char* NAME = "gameuiModioBrowserMenuGameController";
    static constexpr const char* ALIAS = "ModioBrowserMenuGameController";

#ifdef __APPLE__
    uint8_t unk100[0x108 - 0x100]; // 100
    game::ui::SendSelectedModInfoCallback NewModSelected; // 108
    game::ui::SendProcessedModProgressInfoCallback ProcessedModProgressUpdate; // 140
    game::ui::SendModGridInfoCallback ListOfModsToDisplayUpdated; // 178
    game::ui::UpdatePageLayoutCallback PagesLayoutChanged; // 1B0
    ink::BoolCallback SwitchBetweenBrowserAndCollectionMenu; // 1E8
    game::ui::MenuIntIntCallback MenuUpdate; // 220
    ink::BoolCallback CheckIfEnabledModsListChanged; // 258
    game::ui::MenuIntCallback ModDetailsUpdate; // 290
    ink::EmptyCallback SearchbarUpdate; // 2C8
    ink::EmptyCallback ButtonHintsUpdateRequested; // 300
    game::ui::RequestMediaForWidgetCallback RequestLogoForWidget; // 338
    game::ui::MenuIntCallback RequestedGalleryOnServer; // 370
    game::ui::RequestMediaForWidgetCallback RequestGalleryForWidget; // 3A8
    game::ui::MenuIntCallback LogoDownloadRequested; // 3E0
    game::ui::AllLanguagesCheckboxCallback AllLanguagesCheckboxClicked; // 418
    ink::EmptyCallback RateLimitedErrorReceived; // 450
    ink::EmptyCallback RateLimitedErrorLifted; // 488
    game::ui::SendModUpdateVerificationInfo UpdateModVerificationPopupCount; // 4C0
    game::ui::FilterTagsReceivedCallback ModTagsReceived; // 4F8
    ink::EmptyCallback DelayedSpawnForFilters; // 530
    ink::EmptyCallback DelayedSliderAdjustForDrawer; // 568
    game::ui::ReceivedHiddenModsListCallback HiddenModListUpdated; // 5A0
    ink::EmptyCallback AskedForNewModList; // 5D8
    bool bIsInBrowserMode; // 610
    bool bIsUserSubscribedToCurrentlySelectedMod; // 611
    bool bHasAtLeastOneModEnabled; // 612
    bool bHasAtLeastOneModDisabled; // 613
    bool bIsPregame; // 614
    uint8_t unk615[0xD58 - 0x615]; // 615
#else
    uint8_t unk100[0x108 - 0x100]; // 100
    game::ui::SendSelectedModInfoCallback NewModSelected; // 108
    game::ui::SendProcessedModProgressInfoCallback ProcessedModProgressUpdate; // 140
    game::ui::SendModGridInfoCallback ListOfModsToDisplayUpdated; // 178
    game::ui::UpdatePageLayoutCallback PagesLayoutChanged; // 1B0
    ink::BoolCallback SwitchBetweenBrowserAndCollectionMenu; // 1E8
    game::ui::MenuIntIntCallback MenuUpdate; // 220
    ink::BoolCallback CheckIfEnabledModsListChanged; // 258
    game::ui::MenuIntCallback ModDetailsUpdate; // 290
    ink::EmptyCallback SearchbarUpdate; // 2C8
    ink::EmptyCallback ButtonHintsUpdateRequested; // 300
    game::ui::RequestMediaForWidgetCallback RequestLogoForWidget; // 338
    game::ui::MenuIntCallback RequestedGalleryOnServer; // 370
    game::ui::RequestMediaForWidgetCallback RequestGalleryForWidget; // 3A8
    game::ui::MenuIntCallback LogoDownloadRequested; // 3E0
    game::ui::AllLanguagesCheckboxCallback AllLanguagesCheckboxClicked; // 418
    ink::EmptyCallback RateLimitedErrorReceived; // 450
    ink::EmptyCallback RateLimitedErrorLifted; // 488
    game::ui::SendModUpdateVerificationInfo UpdateModVerificationPopupCount; // 4C0
    game::ui::FilterTagsReceivedCallback ModTagsReceived; // 4F8
    ink::EmptyCallback DelayedSpawnForFilters; // 530
    ink::EmptyCallback DelayedSliderAdjustForDrawer; // 568
    game::ui::ReceivedHiddenModsListCallback HiddenModListUpdated; // 5A0
    ink::EmptyCallback AskedForNewModList; // 5D8
    bool bIsInBrowserMode; // 610
    bool bIsUserSubscribedToCurrentlySelectedMod; // 611
    bool bHasAtLeastOneModEnabled; // 612
    bool bHasAtLeastOneModDisabled; // 613
    bool bIsPregame; // 614
    uint8_t unk615[0xDA8 - 0x615]; // 615
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ModioBrowserMenuGameController, 0xD58);
RED4EXT_ASSERT_OFFSET(ModioBrowserMenuGameController, NewModSelected, 0x108);
RED4EXT_ASSERT_OFFSET(ModioBrowserMenuGameController, ProcessedModProgressUpdate, 0x140);
RED4EXT_ASSERT_OFFSET(ModioBrowserMenuGameController, ListOfModsToDisplayUpdated, 0x178);
RED4EXT_ASSERT_OFFSET(ModioBrowserMenuGameController, PagesLayoutChanged, 0x1B0);
RED4EXT_ASSERT_OFFSET(ModioBrowserMenuGameController, SwitchBetweenBrowserAndCollectionMenu, 0x1E8);
RED4EXT_ASSERT_OFFSET(ModioBrowserMenuGameController, MenuUpdate, 0x220);
RED4EXT_ASSERT_OFFSET(ModioBrowserMenuGameController, CheckIfEnabledModsListChanged, 0x258);
RED4EXT_ASSERT_OFFSET(ModioBrowserMenuGameController, ModDetailsUpdate, 0x290);
RED4EXT_ASSERT_OFFSET(ModioBrowserMenuGameController, SearchbarUpdate, 0x2C8);
RED4EXT_ASSERT_OFFSET(ModioBrowserMenuGameController, ButtonHintsUpdateRequested, 0x300);
RED4EXT_ASSERT_OFFSET(ModioBrowserMenuGameController, RequestLogoForWidget, 0x338);
RED4EXT_ASSERT_OFFSET(ModioBrowserMenuGameController, RequestedGalleryOnServer, 0x370);
RED4EXT_ASSERT_OFFSET(ModioBrowserMenuGameController, RequestGalleryForWidget, 0x3A8);
RED4EXT_ASSERT_OFFSET(ModioBrowserMenuGameController, LogoDownloadRequested, 0x3E0);
RED4EXT_ASSERT_OFFSET(ModioBrowserMenuGameController, AllLanguagesCheckboxClicked, 0x418);
RED4EXT_ASSERT_OFFSET(ModioBrowserMenuGameController, RateLimitedErrorReceived, 0x450);
RED4EXT_ASSERT_OFFSET(ModioBrowserMenuGameController, RateLimitedErrorLifted, 0x488);
RED4EXT_ASSERT_OFFSET(ModioBrowserMenuGameController, UpdateModVerificationPopupCount, 0x4C0);
RED4EXT_ASSERT_OFFSET(ModioBrowserMenuGameController, ModTagsReceived, 0x4F8);
RED4EXT_ASSERT_OFFSET(ModioBrowserMenuGameController, DelayedSpawnForFilters, 0x530);
RED4EXT_ASSERT_OFFSET(ModioBrowserMenuGameController, DelayedSliderAdjustForDrawer, 0x568);
RED4EXT_ASSERT_OFFSET(ModioBrowserMenuGameController, HiddenModListUpdated, 0x5A0);
RED4EXT_ASSERT_OFFSET(ModioBrowserMenuGameController, AskedForNewModList, 0x5D8);
RED4EXT_ASSERT_OFFSET(ModioBrowserMenuGameController, bIsInBrowserMode, 0x610);
RED4EXT_ASSERT_OFFSET(ModioBrowserMenuGameController, bIsUserSubscribedToCurrentlySelectedMod, 0x611);
RED4EXT_ASSERT_OFFSET(ModioBrowserMenuGameController, bHasAtLeastOneModEnabled, 0x612);
RED4EXT_ASSERT_OFFSET(ModioBrowserMenuGameController, bHasAtLeastOneModDisabled, 0x613);
RED4EXT_ASSERT_OFFSET(ModioBrowserMenuGameController, bIsPregame, 0x614);
#else
RED4EXT_ASSERT_SIZE(ModioBrowserMenuGameController, 0xDA8);
#endif
} // namespace game::ui
using gameuiModioBrowserMenuGameController = game::ui::ModioBrowserMenuGameController;
using ModioBrowserMenuGameController = game::ui::ModioBrowserMenuGameController;
} // namespace RED4ext

// clang-format on
