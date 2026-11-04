#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/WidgetGameController.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/CompoundWidgetReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/TextWidgetReference.hpp>

namespace RED4ext
{
struct CResource;
namespace ink { struct CreditsResource; }

namespace game::ui
{
struct CreditsController : game::ui::WidgetGameController
{
    static constexpr const char* NAME = "gameuiCreditsController";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unkDC[0x130 - 0xDC]; // DC
    Ref<ink::CreditsResource> creditsResourceXBOX; // 130
    Ref<ink::CreditsResource> creditsResourcePC; // 148
    Ref<ink::CreditsResource> creditsResourceEmporium; // 160
    Ref<ink::CreditsResource> creditsResourceMac; // 178
    Ref<ink::CreditsResource> creditsResourcePS5; // 190
    ink::CompoundWidgetReference sectionsContainer; // 1A8
    ink::TextWidgetReference singleTextWidget; // 1C0
    ink::TextWidgetReference speakerNameTextWidget; // 1D8
    ink::CompoundWidgetReference exitTooltipContainer; // 1F0
    uint8_t unk208[0x240 - 0x208]; // 208
    CName openVideoScreenAnimName; // 240
    CName closeVideoScreenAnimName; // 248
    CName swapBackgroundVideoAnimName; // 250
    CName singleAnimName; // 258
    uint8_t unk260[0x289 - 0x260]; // 260
    bool isPreVideoFinished; // 289
    bool isEp1CreditsImplementation; // 28A
    uint8_t unk28B[0x28C - 0x28B]; // 28B
    float exitNotificationDisplayTime; // 28C
    uint8_t unk290[0x295 - 0x290]; // 290
    bool shouldShowRewardPrompt; // 295
    bool isInFinalBoardsMode; // 296
    uint8_t unk297[0x298 - 0x297]; // 297
    ink::CompoundWidgetReference subtitlesContainer; // 298
    RaRef<CResource> subtitlesLibraryPath; // 2B0
    float scrollingSpeed; // 2B8
    float fastforwardScrollingSpeed; // 2BC
    float topCreditsMargin; // 2C0
    float bottomCreditsMargin; // 2C4
    float startPosition; // 2C8
    uint8_t unk2CC[0x2D0 - 0x2CC]; // 2CC
    CName headerLibraryID; // 2D0
    CName boldLibraryID; // 2D8
    CName basicLibraryID; // 2E0
    CName basicTranslatableLibraryID; // 2E8
    uint8_t unk2F0[0x370 - 0x2F0]; // 2F0
#else
    uint8_t unkE0[0x130 - 0xE0]; // E0
    Ref<ink::CreditsResource> creditsResourceXBOX; // 130
    Ref<ink::CreditsResource> creditsResourcePC; // 148
    Ref<ink::CreditsResource> creditsResourceEmporium; // 160
    Ref<ink::CreditsResource> creditsResourceMac; // 178
    Ref<ink::CreditsResource> creditsResourcePS5; // 190
    ink::CompoundWidgetReference sectionsContainer; // 1A8
    ink::TextWidgetReference singleTextWidget; // 1C0
    ink::TextWidgetReference speakerNameTextWidget; // 1D8
    ink::CompoundWidgetReference exitTooltipContainer; // 1F0
    uint8_t unk208[0x240 - 0x208]; // 208
    CName openVideoScreenAnimName; // 240
    CName closeVideoScreenAnimName; // 248
    CName swapBackgroundVideoAnimName; // 250
    CName singleAnimName; // 258
    uint8_t unk260[0x289 - 0x260]; // 260
    bool isPreVideoFinished; // 289
    bool isEp1CreditsImplementation; // 28A
    uint8_t unk28B[0x28C - 0x28B]; // 28B
    float exitNotificationDisplayTime; // 28C
    uint8_t unk290[0x295 - 0x290]; // 290
    bool shouldShowRewardPrompt; // 295
    bool isInFinalBoardsMode; // 296
    uint8_t unk297[0x298 - 0x297]; // 297
    ink::CompoundWidgetReference subtitlesContainer; // 298
    RaRef<CResource> subtitlesLibraryPath; // 2B0
    float scrollingSpeed; // 2B8
    float fastforwardScrollingSpeed; // 2BC
    float topCreditsMargin; // 2C0
    float bottomCreditsMargin; // 2C4
    float startPosition; // 2C8
    uint8_t unk2CC[0x2D0 - 0x2CC]; // 2CC
    CName headerLibraryID; // 2D0
    CName boldLibraryID; // 2D8
    CName basicLibraryID; // 2E0
    CName basicTranslatableLibraryID; // 2E8
    uint8_t unk2F0[0x370 - 0x2F0]; // 2F0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CreditsController, 0x370);
RED4EXT_ASSERT_OFFSET(CreditsController, creditsResourceXBOX, 0x130);
RED4EXT_ASSERT_OFFSET(CreditsController, creditsResourcePC, 0x148);
RED4EXT_ASSERT_OFFSET(CreditsController, creditsResourceEmporium, 0x160);
RED4EXT_ASSERT_OFFSET(CreditsController, creditsResourceMac, 0x178);
RED4EXT_ASSERT_OFFSET(CreditsController, creditsResourcePS5, 0x190);
RED4EXT_ASSERT_OFFSET(CreditsController, sectionsContainer, 0x1A8);
RED4EXT_ASSERT_OFFSET(CreditsController, singleTextWidget, 0x1C0);
RED4EXT_ASSERT_OFFSET(CreditsController, speakerNameTextWidget, 0x1D8);
RED4EXT_ASSERT_OFFSET(CreditsController, exitTooltipContainer, 0x1F0);
RED4EXT_ASSERT_OFFSET(CreditsController, openVideoScreenAnimName, 0x240);
RED4EXT_ASSERT_OFFSET(CreditsController, closeVideoScreenAnimName, 0x248);
RED4EXT_ASSERT_OFFSET(CreditsController, swapBackgroundVideoAnimName, 0x250);
RED4EXT_ASSERT_OFFSET(CreditsController, singleAnimName, 0x258);
RED4EXT_ASSERT_OFFSET(CreditsController, isPreVideoFinished, 0x289);
RED4EXT_ASSERT_OFFSET(CreditsController, isEp1CreditsImplementation, 0x28A);
RED4EXT_ASSERT_OFFSET(CreditsController, exitNotificationDisplayTime, 0x28C);
RED4EXT_ASSERT_OFFSET(CreditsController, shouldShowRewardPrompt, 0x295);
RED4EXT_ASSERT_OFFSET(CreditsController, isInFinalBoardsMode, 0x296);
RED4EXT_ASSERT_OFFSET(CreditsController, subtitlesContainer, 0x298);
RED4EXT_ASSERT_OFFSET(CreditsController, subtitlesLibraryPath, 0x2B0);
RED4EXT_ASSERT_OFFSET(CreditsController, scrollingSpeed, 0x2B8);
RED4EXT_ASSERT_OFFSET(CreditsController, fastforwardScrollingSpeed, 0x2BC);
RED4EXT_ASSERT_OFFSET(CreditsController, topCreditsMargin, 0x2C0);
RED4EXT_ASSERT_OFFSET(CreditsController, bottomCreditsMargin, 0x2C4);
RED4EXT_ASSERT_OFFSET(CreditsController, startPosition, 0x2C8);
RED4EXT_ASSERT_OFFSET(CreditsController, headerLibraryID, 0x2D0);
RED4EXT_ASSERT_OFFSET(CreditsController, boldLibraryID, 0x2D8);
RED4EXT_ASSERT_OFFSET(CreditsController, basicLibraryID, 0x2E0);
RED4EXT_ASSERT_OFFSET(CreditsController, basicTranslatableLibraryID, 0x2E8);
#else
RED4EXT_ASSERT_SIZE(CreditsController, 0x370);
#endif
} // namespace game::ui
using gameuiCreditsController = game::ui::CreditsController;
} // namespace RED4ext

// clang-format on
