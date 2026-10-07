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
    Ref<ink::CreditsResource> creditsResourcePS4; // 130
    Ref<ink::CreditsResource> creditsResourceXBOXPC; // 148
    ink::CompoundWidgetReference sectionsContainer; // 160
    ink::TextWidgetReference singleTextWidget; // 178
    ink::TextWidgetReference speakerNameTextWidget; // 190
    ink::CompoundWidgetReference exitTooltipContainer; // 1A8
    uint8_t unk1C0[0x1F8 - 0x1C0]; // 1C0
    CName openVideoScreenAnimName; // 1F8
    CName closeVideoScreenAnimName; // 200
    CName swapBackgroundVideoAnimName; // 208
    CName singleAnimName; // 210
    uint8_t unk218[0x241 - 0x218]; // 218
    bool isPreVideoFinished; // 241
    bool isEp1CreditsImplementation; // 242
    uint8_t unk243[0x244 - 0x243]; // 243
    float exitNotificationDisplayTime; // 244
    uint8_t unk248[0x24D - 0x248]; // 248
    bool shouldShowRewardPrompt; // 24D
    bool isInFinalBoardsMode; // 24E
    uint8_t unk24F[0x250 - 0x24F]; // 24F
    ink::CompoundWidgetReference subtitlesContainer; // 250
    RaRef<CResource> subtitlesLibraryPath; // 268
    float scrollingSpeed; // 270
    float fastforwardScrollingSpeed; // 274
    float topCreditsMargin; // 278
    float bottomCreditsMargin; // 27C
    float startPosition; // 280
    uint8_t unk284[0x288 - 0x284]; // 284
    CName headerLibraryID; // 288
    CName boldLibraryID; // 290
    CName basicLibraryID; // 298
    CName basicTranslatableLibraryID; // 2A0
    uint8_t unk2A8[0x328 - 0x2A8]; // 2A8
#else
    uint8_t unkE0[0x130 - 0xE0]; // E0
    Ref<ink::CreditsResource> creditsResourcePS4; // 130
    Ref<ink::CreditsResource> creditsResourceXBOXPC; // 148
    ink::CompoundWidgetReference sectionsContainer; // 160
    ink::TextWidgetReference singleTextWidget; // 178
    ink::TextWidgetReference speakerNameTextWidget; // 190
    ink::CompoundWidgetReference exitTooltipContainer; // 1A8
    uint8_t unk1C0[0x1F8 - 0x1C0]; // 1C0
    CName openVideoScreenAnimName; // 1F8
    CName closeVideoScreenAnimName; // 200
    CName swapBackgroundVideoAnimName; // 208
    CName singleAnimName; // 210
    uint8_t unk218[0x241 - 0x218]; // 218
    bool isPreVideoFinished; // 241
    bool isEp1CreditsImplementation; // 242
    uint8_t unk243[0x244 - 0x243]; // 243
    float exitNotificationDisplayTime; // 244
    uint8_t unk248[0x24D - 0x248]; // 248
    bool shouldShowRewardPrompt; // 24D
    bool isInFinalBoardsMode; // 24E
    uint8_t unk24F[0x250 - 0x24F]; // 24F
    ink::CompoundWidgetReference subtitlesContainer; // 250
    RaRef<CResource> subtitlesLibraryPath; // 268
    float scrollingSpeed; // 270
    float fastforwardScrollingSpeed; // 274
    float topCreditsMargin; // 278
    float bottomCreditsMargin; // 27C
    float startPosition; // 280
    uint8_t unk284[0x288 - 0x284]; // 284
    CName headerLibraryID; // 288
    CName boldLibraryID; // 290
    CName basicLibraryID; // 298
    CName basicTranslatableLibraryID; // 2A0
    uint8_t unk2A8[0x328 - 0x2A8]; // 2A8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CreditsController, 0x328);
RED4EXT_ASSERT_OFFSET(CreditsController, creditsResourcePS4, 0x130);
RED4EXT_ASSERT_OFFSET(CreditsController, creditsResourceXBOXPC, 0x148);
RED4EXT_ASSERT_OFFSET(CreditsController, sectionsContainer, 0x160);
RED4EXT_ASSERT_OFFSET(CreditsController, singleTextWidget, 0x178);
RED4EXT_ASSERT_OFFSET(CreditsController, speakerNameTextWidget, 0x190);
RED4EXT_ASSERT_OFFSET(CreditsController, exitTooltipContainer, 0x1A8);
RED4EXT_ASSERT_OFFSET(CreditsController, openVideoScreenAnimName, 0x1F8);
RED4EXT_ASSERT_OFFSET(CreditsController, closeVideoScreenAnimName, 0x200);
RED4EXT_ASSERT_OFFSET(CreditsController, swapBackgroundVideoAnimName, 0x208);
RED4EXT_ASSERT_OFFSET(CreditsController, singleAnimName, 0x210);
RED4EXT_ASSERT_OFFSET(CreditsController, isPreVideoFinished, 0x241);
RED4EXT_ASSERT_OFFSET(CreditsController, isEp1CreditsImplementation, 0x242);
RED4EXT_ASSERT_OFFSET(CreditsController, exitNotificationDisplayTime, 0x244);
RED4EXT_ASSERT_OFFSET(CreditsController, shouldShowRewardPrompt, 0x24D);
RED4EXT_ASSERT_OFFSET(CreditsController, isInFinalBoardsMode, 0x24E);
RED4EXT_ASSERT_OFFSET(CreditsController, subtitlesContainer, 0x250);
RED4EXT_ASSERT_OFFSET(CreditsController, subtitlesLibraryPath, 0x268);
RED4EXT_ASSERT_OFFSET(CreditsController, scrollingSpeed, 0x270);
RED4EXT_ASSERT_OFFSET(CreditsController, fastforwardScrollingSpeed, 0x274);
RED4EXT_ASSERT_OFFSET(CreditsController, topCreditsMargin, 0x278);
RED4EXT_ASSERT_OFFSET(CreditsController, bottomCreditsMargin, 0x27C);
RED4EXT_ASSERT_OFFSET(CreditsController, startPosition, 0x280);
RED4EXT_ASSERT_OFFSET(CreditsController, headerLibraryID, 0x288);
RED4EXT_ASSERT_OFFSET(CreditsController, boldLibraryID, 0x290);
RED4EXT_ASSERT_OFFSET(CreditsController, basicLibraryID, 0x298);
RED4EXT_ASSERT_OFFSET(CreditsController, basicTranslatableLibraryID, 0x2A0);
#else
RED4EXT_ASSERT_SIZE(CreditsController, 0x328);
#endif
} // namespace game::ui
using gameuiCreditsController = game::ui::CreditsController;
} // namespace RED4ext

// clang-format on
