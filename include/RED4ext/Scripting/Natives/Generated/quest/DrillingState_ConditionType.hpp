#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/DrillingState.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IObjectConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct DrillingState_ConditionType : quest::IObjectConditionType
{
    static constexpr const char* NAME = "questDrillingState_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    NodeRef objectRef; // 38
    quest::DrillingState state; // 40
    uint8_t unk44[0x48 - 0x44]; // 44
#else
    NodeRef objectRef; // 38
    quest::DrillingState state; // 40
    uint8_t unk44[0x48 - 0x44]; // 44
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(DrillingState_ConditionType, 0x48);
RED4EXT_ASSERT_OFFSET(DrillingState_ConditionType, objectRef, 0x38);
RED4EXT_ASSERT_OFFSET(DrillingState_ConditionType, state, 0x40);
#else
RED4EXT_ASSERT_SIZE(DrillingState_ConditionType, 0x48);
#endif
} // namespace quest
using questDrillingState_ConditionType = quest::DrillingState_ConditionType;
} // namespace RED4ext

// clang-format on
