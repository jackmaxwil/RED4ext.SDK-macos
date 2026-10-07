#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/behavior/DelegateTaskRef.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/behavior/TaskDefinition.hpp>

namespace RED4ext
{
namespace AI::behavior
{
struct DelegateTaskDefinition : AI::behavior::TaskDefinition
{
    static constexpr const char* NAME = "AIbehaviorDelegateTaskDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk31[0x38 - 0x31]; // 31
    AI::behavior::DelegateTaskRef onActivate; // 38
    AI::behavior::DelegateTaskRef onUpdate; // 40
    AI::behavior::DelegateTaskRef onDeactivate; // 48
#else
    AI::behavior::DelegateTaskRef onActivate; // 38
    AI::behavior::DelegateTaskRef onUpdate; // 40
    AI::behavior::DelegateTaskRef onDeactivate; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(DelegateTaskDefinition, 0x50);
RED4EXT_ASSERT_OFFSET(DelegateTaskDefinition, onActivate, 0x38);
RED4EXT_ASSERT_OFFSET(DelegateTaskDefinition, onUpdate, 0x40);
RED4EXT_ASSERT_OFFSET(DelegateTaskDefinition, onDeactivate, 0x48);
#else
RED4EXT_ASSERT_SIZE(DelegateTaskDefinition, 0x50);
#endif
} // namespace AI::behavior
using AIbehaviorDelegateTaskDefinition = AI::behavior::DelegateTaskDefinition;
} // namespace RED4ext

// clang-format on
