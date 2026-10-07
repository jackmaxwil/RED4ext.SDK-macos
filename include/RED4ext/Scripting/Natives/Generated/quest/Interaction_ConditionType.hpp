#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IObjectConditionType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ObjectInteractionEventType.hpp>

namespace RED4ext
{
namespace quest
{
struct Interaction_ConditionType : quest::IObjectConditionType
{
    static constexpr const char* NAME = "questInteraction_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    NodeRef objectRef; // 38
    quest::ObjectInteractionEventType eventType; // 40
    uint8_t unk41[0x48 - 0x41]; // 41
#else
    NodeRef objectRef; // 38
    quest::ObjectInteractionEventType eventType; // 40
    uint8_t unk41[0x48 - 0x41]; // 41
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(Interaction_ConditionType, 0x48);
RED4EXT_ASSERT_OFFSET(Interaction_ConditionType, objectRef, 0x38);
RED4EXT_ASSERT_OFFSET(Interaction_ConditionType, eventType, 0x40);
#else
RED4EXT_ASSERT_SIZE(Interaction_ConditionType, 0x48);
#endif
} // namespace quest
using questInteraction_ConditionType = quest::Interaction_ConditionType;
} // namespace RED4ext

// clang-format on
