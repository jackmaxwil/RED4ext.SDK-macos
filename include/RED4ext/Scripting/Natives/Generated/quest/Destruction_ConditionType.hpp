#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IObjectConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct Destruction_ConditionType : quest::IObjectConditionType
{
    static constexpr const char* NAME = "questDestruction_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    game::EntityReference objectRef; // 38
    float threshold; // 70
    uint8_t unk74[0x78 - 0x74]; // 74
#else
    game::EntityReference objectRef; // 38
    float threshold; // 70
    uint8_t unk74[0x78 - 0x74]; // 74
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(Destruction_ConditionType, 0x78);
RED4EXT_ASSERT_OFFSET(Destruction_ConditionType, objectRef, 0x38);
RED4EXT_ASSERT_OFFSET(Destruction_ConditionType, threshold, 0x70);
#else
RED4EXT_ASSERT_SIZE(Destruction_ConditionType, 0x78);
#endif
} // namespace quest
using questDestruction_ConditionType = quest::Destruction_ConditionType;
} // namespace RED4ext

// clang-format on
