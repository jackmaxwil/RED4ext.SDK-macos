#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/ListControllerCallback.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/WidgetLogicController.hpp>

namespace RED4ext
{
namespace ink
{
struct ListController : ink::WidgetLogicController
{
    static constexpr const char* NAME = "inkListController";
    static constexpr const char* ALIAS = "ListController";

#ifdef __APPLE__
    ink::ListControllerCallback ItemSelected; // 78
    ink::ListControllerCallback ItemActivated; // B0
    uint8_t unkE8[0x118 - 0xE8]; // E8
    CName itemLibraryID; // 118
    bool cycledNavigation; // 120
    bool beginToggled; // 121
    uint8_t unk122[0x124 - 0x122]; // 122
#else
    ink::ListControllerCallback ItemSelected; // 78
    ink::ListControllerCallback ItemActivated; // B0
    uint8_t unkE8[0x118 - 0xE8]; // E8
    CName itemLibraryID; // 118
    bool cycledNavigation; // 120
    bool beginToggled; // 121
    uint8_t unk122[0x128 - 0x122]; // 122
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ListController, 0x128);
RED4EXT_ASSERT_OFFSET(ListController, ItemSelected, 0x78);
RED4EXT_ASSERT_OFFSET(ListController, ItemActivated, 0xB0);
RED4EXT_ASSERT_OFFSET(ListController, itemLibraryID, 0x118);
RED4EXT_ASSERT_OFFSET(ListController, cycledNavigation, 0x120);
RED4EXT_ASSERT_OFFSET(ListController, beginToggled, 0x121);
#else
RED4EXT_ASSERT_SIZE(ListController, 0x128);
#endif
} // namespace ink
using inkListController = ink::ListController;
using ListController = ink::ListController;
} // namespace RED4ext

// clang-format on
