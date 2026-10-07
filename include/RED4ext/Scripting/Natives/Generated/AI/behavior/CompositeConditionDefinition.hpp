#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/behavior/ConditionDefinition.hpp>

namespace RED4ext
{
namespace AI::behavior { struct ConditionDefinition; }

namespace AI::behavior
{
struct CompositeConditionDefinition : AI::behavior::ConditionDefinition
{
    static constexpr const char* NAME = "AIbehaviorCompositeConditionDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    DynArray<Handle<AI::behavior::ConditionDefinition>> conditions; // 38
#else
    DynArray<Handle<AI::behavior::ConditionDefinition>> conditions; // 38
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CompositeConditionDefinition, 0x48);
RED4EXT_ASSERT_OFFSET(CompositeConditionDefinition, conditions, 0x38);
#else
RED4EXT_ASSERT_SIZE(CompositeConditionDefinition, 0x48);
#endif
} // namespace AI::behavior
using AIbehaviorCompositeConditionDefinition = AI::behavior::CompositeConditionDefinition;
} // namespace RED4ext

// clang-format on
