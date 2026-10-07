#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/behavior/ConditionDefinition.hpp>

namespace RED4ext
{
namespace AI::behavior
{
struct RandomConditionDefinition : AI::behavior::ConditionDefinition
{
    static constexpr const char* NAME = "AIbehaviorRandomConditionDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    float chance; // 34
#else
    float chance; // 38
    uint8_t unk3C[0x40 - 0x3C]; // 3C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(RandomConditionDefinition, 0x38);
RED4EXT_ASSERT_OFFSET(RandomConditionDefinition, chance, 0x34);
#else
RED4EXT_ASSERT_SIZE(RandomConditionDefinition, 0x40);
#endif
} // namespace AI::behavior
using AIbehaviorRandomConditionDefinition = AI::behavior::RandomConditionDefinition;
} // namespace RED4ext

// clang-format on
