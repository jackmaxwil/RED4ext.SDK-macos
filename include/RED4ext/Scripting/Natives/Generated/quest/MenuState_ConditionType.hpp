#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/EUIMenuState.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct MenuState_ConditionType : quest::IUIConditionType
{
    static constexpr const char* NAME = "questMenuState_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    quest::EUIMenuState state; // 34
#else
    quest::EUIMenuState state; // 38
    uint8_t unk3C[0x40 - 0x3C]; // 3C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MenuState_ConditionType, 0x38);
RED4EXT_ASSERT_OFFSET(MenuState_ConditionType, state, 0x34);
#else
RED4EXT_ASSERT_SIZE(MenuState_ConditionType, 0x40);
#endif
} // namespace quest
using questMenuState_ConditionType = quest::MenuState_ConditionType;
} // namespace RED4ext

// clang-format on
