#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/UICondition.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct UIElement_ConditionType : quest::IUIConditionType
{
    static constexpr const char* NAME = "questUIElement_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    TweakDBID element; // 34
    game::data::UICondition condition; // 3C
    bool value; // 40
    uint8_t unk41[0x48 - 0x41]; // 41
#else
    TweakDBID element; // 38
    game::data::UICondition condition; // 40
    bool value; // 44
    uint8_t unk45[0x48 - 0x45]; // 45
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(UIElement_ConditionType, 0x48);
RED4EXT_ASSERT_OFFSET(UIElement_ConditionType, element, 0x34);
RED4EXT_ASSERT_OFFSET(UIElement_ConditionType, condition, 0x3C);
RED4EXT_ASSERT_OFFSET(UIElement_ConditionType, value, 0x40);
#else
RED4EXT_ASSERT_SIZE(UIElement_ConditionType, 0x48);
#endif
} // namespace quest
using questUIElement_ConditionType = quest::UIElement_ConditionType;
} // namespace RED4ext

// clang-format on
