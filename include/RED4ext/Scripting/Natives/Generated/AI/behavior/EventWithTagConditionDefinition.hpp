#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/behavior/ConditionDefinition.hpp>

namespace RED4ext
{
namespace AI::behavior
{
struct EventWithTagConditionDefinition : AI::behavior::ConditionDefinition
{
    static constexpr const char* NAME = "AIbehaviorEventWithTagConditionDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    CName tag; // 38
    bool consumeEvent; // 40
    uint8_t unk41[0x48 - 0x41]; // 41
#else
    CName tag; // 38
    bool consumeEvent; // 40
    uint8_t unk41[0x48 - 0x41]; // 41
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(EventWithTagConditionDefinition, 0x48);
RED4EXT_ASSERT_OFFSET(EventWithTagConditionDefinition, tag, 0x38);
RED4EXT_ASSERT_OFFSET(EventWithTagConditionDefinition, consumeEvent, 0x40);
#else
RED4EXT_ASSERT_SIZE(EventWithTagConditionDefinition, 0x48);
#endif
} // namespace AI::behavior
using AIbehaviorEventWithTagConditionDefinition = AI::behavior::EventWithTagConditionDefinition;
} // namespace RED4ext

// clang-format on
