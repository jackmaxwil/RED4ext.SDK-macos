#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/Condition.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/TriggerConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct TriggerCondition : quest::Condition
{
    static constexpr const char* NAME = "questTriggerCondition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    quest::TriggerConditionType type; // 34
    uint8_t unk35[0x38 - 0x35]; // 35
    NodeRef triggerAreaRef; // 38
    game::EntityReference activatorRef; // 40
    bool isPlayerActivator; // 78
    uint8_t unk79[0x80 - 0x79]; // 79
#else
    quest::TriggerConditionType type; // 38
    uint8_t unk39[0x40 - 0x39]; // 39
    NodeRef triggerAreaRef; // 40
    game::EntityReference activatorRef; // 48
    bool isPlayerActivator; // 80
    uint8_t unk81[0x88 - 0x81]; // 81
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TriggerCondition, 0x80);
RED4EXT_ASSERT_OFFSET(TriggerCondition, type, 0x34);
RED4EXT_ASSERT_OFFSET(TriggerCondition, triggerAreaRef, 0x38);
RED4EXT_ASSERT_OFFSET(TriggerCondition, activatorRef, 0x40);
RED4EXT_ASSERT_OFFSET(TriggerCondition, isPlayerActivator, 0x78);
#else
RED4EXT_ASSERT_SIZE(TriggerCondition, 0x88);
#endif
} // namespace quest
using questTriggerCondition = quest::TriggerCondition;
} // namespace RED4ext

// clang-format on
