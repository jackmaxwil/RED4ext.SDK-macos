#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/behavior/ConditionDefinition.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/behavior/EntityLODConditions.hpp>

namespace RED4ext
{
namespace AI::behavior
{
struct EntityLODConditionDefinition : AI::behavior::ConditionDefinition
{
    static constexpr const char* NAME = "AIbehaviorEntityLODConditionDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    DynArray<AI::behavior::EntityLODConditions> any; // 38
    DynArray<AI::behavior::EntityLODConditions> all; // 48
    DynArray<AI::behavior::EntityLODConditions> none; // 58
#else
    DynArray<AI::behavior::EntityLODConditions> any; // 38
    DynArray<AI::behavior::EntityLODConditions> all; // 48
    DynArray<AI::behavior::EntityLODConditions> none; // 58
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(EntityLODConditionDefinition, 0x68);
RED4EXT_ASSERT_OFFSET(EntityLODConditionDefinition, any, 0x38);
RED4EXT_ASSERT_OFFSET(EntityLODConditionDefinition, all, 0x48);
RED4EXT_ASSERT_OFFSET(EntityLODConditionDefinition, none, 0x58);
#else
RED4EXT_ASSERT_SIZE(EntityLODConditionDefinition, 0x68);
#endif
} // namespace AI::behavior
using AIbehaviorEntityLODConditionDefinition = AI::behavior::EntityLODConditionDefinition;
} // namespace RED4ext

// clang-format on
