#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/InteractionMappinController.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/TextWidgetReference.hpp>

namespace RED4ext
{
namespace game::ui
{
struct __declspec(align(0x10)) QuestMappinController : game::ui::InteractionMappinController
{
    static constexpr const char* NAME = "gameuiQuestMappinController";
    static constexpr const char* ALIAS = "BaseQuestMappinController";

#ifdef __APPLE__
    uint8_t unk2B8[0x2D0 - 0x2B8]; // 2B8
    bool nameplateVisible; // 2D0
    uint8_t unk2D1[0x2D8 - 0x2D1]; // 2D1
    ink::TextWidgetReference distanceText; // 2D8
    ink::TextWidgetReference displayName; // 2F0
    uint8_t unk308[0x310 - 0x308]; // 308
#else
    uint8_t unk2C0[0x2D8 - 0x2C0]; // 2C0
    bool nameplateVisible; // 2D8
    uint8_t unk2D9[0x2E0 - 0x2D9]; // 2D9
    ink::TextWidgetReference distanceText; // 2E0
    ink::TextWidgetReference displayName; // 2F8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(QuestMappinController, 0x310);
RED4EXT_ASSERT_OFFSET(QuestMappinController, nameplateVisible, 0x2D0);
RED4EXT_ASSERT_OFFSET(QuestMappinController, distanceText, 0x2D8);
RED4EXT_ASSERT_OFFSET(QuestMappinController, displayName, 0x2F0);
#else
RED4EXT_ASSERT_SIZE(QuestMappinController, 0x310);
#endif
} // namespace game::ui
using gameuiQuestMappinController = game::ui::QuestMappinController;
using BaseQuestMappinController = game::ui::QuestMappinController;
} // namespace RED4ext

// clang-format on
