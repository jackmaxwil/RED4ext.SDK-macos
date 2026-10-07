#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/behavior/TaskDefinition.hpp>

namespace RED4ext
{
namespace AI::behavior::task { struct Script; }

namespace AI::behavior
{
struct ScriptTaskDefinition : AI::behavior::TaskDefinition
{
    static constexpr const char* NAME = "AIbehaviorScriptTaskDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk31[0x38 - 0x31]; // 31
    Handle<AI::behavior::task::Script> script; // 38
    bool disableLazyInitialization; // 48
    uint8_t unk49[0x50 - 0x49]; // 49
#else
    Handle<AI::behavior::task::Script> script; // 38
    bool disableLazyInitialization; // 48
    uint8_t unk49[0x50 - 0x49]; // 49
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ScriptTaskDefinition, 0x50);
RED4EXT_ASSERT_OFFSET(ScriptTaskDefinition, script, 0x38);
RED4EXT_ASSERT_OFFSET(ScriptTaskDefinition, disableLazyInitialization, 0x48);
#else
RED4EXT_ASSERT_SIZE(ScriptTaskDefinition, 0x50);
#endif
} // namespace AI::behavior
using AIbehaviorScriptTaskDefinition = AI::behavior::ScriptTaskDefinition;
} // namespace RED4ext

// clang-format on
