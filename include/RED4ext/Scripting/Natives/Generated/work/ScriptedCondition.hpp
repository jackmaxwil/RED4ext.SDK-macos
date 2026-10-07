#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/work/IWorkspotCondition.hpp>

namespace RED4ext
{
namespace work { struct IScriptedCondition; }

namespace work
{
struct ScriptedCondition : work::IWorkspotCondition
{
    static constexpr const char* NAME = "workScriptedCondition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk35[0x38 - 0x35]; // 35
    Handle<work::IScriptedCondition> script; // 38
#else
    Handle<work::IScriptedCondition> script; // 38
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ScriptedCondition, 0x48);
RED4EXT_ASSERT_OFFSET(ScriptedCondition, script, 0x38);
#else
RED4EXT_ASSERT_SIZE(ScriptedCondition, 0x48);
#endif
} // namespace work
using workScriptedCondition = work::ScriptedCondition;
} // namespace RED4ext

// clang-format on
