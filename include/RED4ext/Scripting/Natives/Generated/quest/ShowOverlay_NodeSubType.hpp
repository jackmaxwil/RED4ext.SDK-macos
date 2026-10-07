#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ITutorial_NodeSubType.hpp>

namespace RED4ext
{
namespace ink { struct WidgetLibraryResource; }

namespace quest
{
struct ShowOverlay_NodeSubType : quest::ITutorial_NodeSubType
{
    static constexpr const char* NAME = "questShowOverlay_NodeSubType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    RaRef<ink::WidgetLibraryResource> overlayLibrary; // 38
    CName libraryItemName; // 40
    bool visible; // 48
    bool pauseGame; // 49
    bool lockPlayerMovement; // 4A
    bool hideOnInput; // 4B
    uint8_t unk4C[0x50 - 0x4C]; // 4C
#else
    RaRef<ink::WidgetLibraryResource> overlayLibrary; // 38
    CName libraryItemName; // 40
    bool visible; // 48
    bool pauseGame; // 49
    bool lockPlayerMovement; // 4A
    bool hideOnInput; // 4B
    uint8_t unk4C[0x50 - 0x4C]; // 4C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ShowOverlay_NodeSubType, 0x50);
RED4EXT_ASSERT_OFFSET(ShowOverlay_NodeSubType, overlayLibrary, 0x38);
RED4EXT_ASSERT_OFFSET(ShowOverlay_NodeSubType, libraryItemName, 0x40);
RED4EXT_ASSERT_OFFSET(ShowOverlay_NodeSubType, visible, 0x48);
RED4EXT_ASSERT_OFFSET(ShowOverlay_NodeSubType, pauseGame, 0x49);
RED4EXT_ASSERT_OFFSET(ShowOverlay_NodeSubType, lockPlayerMovement, 0x4A);
RED4EXT_ASSERT_OFFSET(ShowOverlay_NodeSubType, hideOnInput, 0x4B);
#else
RED4EXT_ASSERT_SIZE(ShowOverlay_NodeSubType, 0x50);
#endif
} // namespace quest
using questShowOverlay_NodeSubType = quest::ShowOverlay_NodeSubType;
} // namespace RED4ext

// clang-format on
