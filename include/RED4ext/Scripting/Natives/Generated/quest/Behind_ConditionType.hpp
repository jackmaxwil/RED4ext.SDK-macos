#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/BehindInteractionEventType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ISensesConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct Behind_ConditionType : quest::ISensesConditionType
{
    static constexpr const char* NAME = "questBehind_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    game::EntityReference targetRef; // 38
    quest::BehindInteractionEventType eventType; // 70
    uint8_t unk71[0x78 - 0x71]; // 71
#else
    game::EntityReference targetRef; // 38
    quest::BehindInteractionEventType eventType; // 70
    uint8_t unk71[0x78 - 0x71]; // 71
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(Behind_ConditionType, 0x78);
RED4EXT_ASSERT_OFFSET(Behind_ConditionType, targetRef, 0x38);
RED4EXT_ASSERT_OFFSET(Behind_ConditionType, eventType, 0x70);
#else
RED4EXT_ASSERT_SIZE(Behind_ConditionType, 0x78);
#endif
} // namespace quest
using questBehind_ConditionType = quest::Behind_ConditionType;
} // namespace RED4ext

// clang-format on
