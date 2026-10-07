#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/SideScrollerMiniGameLogicControllerAdvanced.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/TextWidgetReference.hpp>

namespace RED4ext
{
namespace game::ui
{
struct PanzerGameLogicController : game::ui::SideScrollerMiniGameLogicControllerAdvanced
{
    static constexpr const char* NAME = "gameuiPanzerGameLogicController";
    static constexpr const char* ALIAS = "PanzerGameLogicController";

#ifdef __APPLE__
    uint8_t unk148[0x17C - 0x148]; // 148
    float gameOverDelay; // 17C
    uint8_t unk180[0x188 - 0x180]; // 180
    CName mainMenuLibraryName; // 188
    CName scoreboardLibraryName; // 190
    CName panelsLayer; // 198
    CName gameLayer; // 1A0
    CName cloudsLayer; // 1A8
    CName backgroundLibraryName; // 1B0
    DynArray<CName> cloudsLibraryNames; // 1B8
    float minCloudSpawnInterval; // 1C8
    float maxCloudSpawnInterval; // 1CC
    float minCloudSpeed; // 1D0
    float maxCloudSpeed; // 1D4
    ink::TextWidgetReference scoreCounter; // 1D8
    ink::TextWidgetReference livesCounter; // 1F0
    CName moveUpKey; // 208
    CName moveDownKey; // 210
    CName moveLeftKey; // 218
    CName moveRightKey; // 220
    CName shootKey; // 228
    CName backKey; // 230
    CName submitKey; // 238
    float axisDeadZone; // 240
    uint8_t unk244[0x248 - 0x244]; // 244
    CName moveXAxis; // 248
    CName moveYAxis; // 250
    CName shootAxis; // 258
    CName droneLibraryName; // 260
    float minDroneSpawnInterval; // 268
    float maxDroneSpawnInterval; // 26C
    CName avLibraryName; // 270
    float minAvSpawnInterval; // 278
    float maxAvSpawnInterval; // 27C
#else
    uint8_t unk148[0x184 - 0x148]; // 148
    float gameOverDelay; // 184
    uint8_t unk188[0x190 - 0x188]; // 188
    CName mainMenuLibraryName; // 190
    CName scoreboardLibraryName; // 198
    CName panelsLayer; // 1A0
    CName gameLayer; // 1A8
    CName cloudsLayer; // 1B0
    CName backgroundLibraryName; // 1B8
    DynArray<CName> cloudsLibraryNames; // 1C0
    float minCloudSpawnInterval; // 1D0
    float maxCloudSpawnInterval; // 1D4
    float minCloudSpeed; // 1D8
    float maxCloudSpeed; // 1DC
    ink::TextWidgetReference scoreCounter; // 1E0
    ink::TextWidgetReference livesCounter; // 1F8
    CName moveUpKey; // 210
    CName moveDownKey; // 218
    CName moveLeftKey; // 220
    CName moveRightKey; // 228
    CName shootKey; // 230
    CName backKey; // 238
    CName submitKey; // 240
    float axisDeadZone; // 248
    uint8_t unk24C[0x250 - 0x24C]; // 24C
    CName moveXAxis; // 250
    CName moveYAxis; // 258
    CName shootAxis; // 260
    CName droneLibraryName; // 268
    float minDroneSpawnInterval; // 270
    float maxDroneSpawnInterval; // 274
    CName avLibraryName; // 278
    float minAvSpawnInterval; // 280
    float maxAvSpawnInterval; // 284
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PanzerGameLogicController, 0x280);
RED4EXT_ASSERT_OFFSET(PanzerGameLogicController, gameOverDelay, 0x17C);
RED4EXT_ASSERT_OFFSET(PanzerGameLogicController, mainMenuLibraryName, 0x188);
RED4EXT_ASSERT_OFFSET(PanzerGameLogicController, scoreboardLibraryName, 0x190);
RED4EXT_ASSERT_OFFSET(PanzerGameLogicController, panelsLayer, 0x198);
RED4EXT_ASSERT_OFFSET(PanzerGameLogicController, gameLayer, 0x1A0);
RED4EXT_ASSERT_OFFSET(PanzerGameLogicController, cloudsLayer, 0x1A8);
RED4EXT_ASSERT_OFFSET(PanzerGameLogicController, backgroundLibraryName, 0x1B0);
RED4EXT_ASSERT_OFFSET(PanzerGameLogicController, cloudsLibraryNames, 0x1B8);
RED4EXT_ASSERT_OFFSET(PanzerGameLogicController, minCloudSpawnInterval, 0x1C8);
RED4EXT_ASSERT_OFFSET(PanzerGameLogicController, maxCloudSpawnInterval, 0x1CC);
RED4EXT_ASSERT_OFFSET(PanzerGameLogicController, minCloudSpeed, 0x1D0);
RED4EXT_ASSERT_OFFSET(PanzerGameLogicController, maxCloudSpeed, 0x1D4);
RED4EXT_ASSERT_OFFSET(PanzerGameLogicController, scoreCounter, 0x1D8);
RED4EXT_ASSERT_OFFSET(PanzerGameLogicController, livesCounter, 0x1F0);
RED4EXT_ASSERT_OFFSET(PanzerGameLogicController, moveUpKey, 0x208);
RED4EXT_ASSERT_OFFSET(PanzerGameLogicController, moveDownKey, 0x210);
RED4EXT_ASSERT_OFFSET(PanzerGameLogicController, moveLeftKey, 0x218);
RED4EXT_ASSERT_OFFSET(PanzerGameLogicController, moveRightKey, 0x220);
RED4EXT_ASSERT_OFFSET(PanzerGameLogicController, shootKey, 0x228);
RED4EXT_ASSERT_OFFSET(PanzerGameLogicController, backKey, 0x230);
RED4EXT_ASSERT_OFFSET(PanzerGameLogicController, submitKey, 0x238);
RED4EXT_ASSERT_OFFSET(PanzerGameLogicController, axisDeadZone, 0x240);
RED4EXT_ASSERT_OFFSET(PanzerGameLogicController, moveXAxis, 0x248);
RED4EXT_ASSERT_OFFSET(PanzerGameLogicController, moveYAxis, 0x250);
RED4EXT_ASSERT_OFFSET(PanzerGameLogicController, shootAxis, 0x258);
RED4EXT_ASSERT_OFFSET(PanzerGameLogicController, droneLibraryName, 0x260);
RED4EXT_ASSERT_OFFSET(PanzerGameLogicController, minDroneSpawnInterval, 0x268);
RED4EXT_ASSERT_OFFSET(PanzerGameLogicController, maxDroneSpawnInterval, 0x26C);
RED4EXT_ASSERT_OFFSET(PanzerGameLogicController, avLibraryName, 0x270);
RED4EXT_ASSERT_OFFSET(PanzerGameLogicController, minAvSpawnInterval, 0x278);
RED4EXT_ASSERT_OFFSET(PanzerGameLogicController, maxAvSpawnInterval, 0x27C);
#else
RED4EXT_ASSERT_SIZE(PanzerGameLogicController, 0x288);
#endif
} // namespace game::ui
using gameuiPanzerGameLogicController = game::ui::PanzerGameLogicController;
using PanzerGameLogicController = game::ui::PanzerGameLogicController;
} // namespace RED4ext

// clang-format on
