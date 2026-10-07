#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/behavior/TaskDefinition.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/BoolSignalAction.hpp>

namespace RED4ext
{
namespace game { struct SignalUserDataDefinition; }

namespace AI::behavior
{
struct SendSignalTaskDefinition : AI::behavior::TaskDefinition
{
    static constexpr const char* NAME = "AIbehaviorSendSignalTaskDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk31[0x38 - 0x31]; // 31
    CName signalName; // 38
    game::BoolSignalAction startAction; // 40
    uint8_t unk44[0x48 - 0x44]; // 44
    Handle<game::SignalUserDataDefinition> startActionUserData; // 48
    game::BoolSignalAction endAction; // 58
    uint8_t unk5C[0x60 - 0x5C]; // 5C
    Handle<game::SignalUserDataDefinition> endActionUserData; // 60
#else
    CName signalName; // 38
    game::BoolSignalAction startAction; // 40
    uint8_t unk44[0x48 - 0x44]; // 44
    Handle<game::SignalUserDataDefinition> startActionUserData; // 48
    game::BoolSignalAction endAction; // 58
    uint8_t unk5C[0x60 - 0x5C]; // 5C
    Handle<game::SignalUserDataDefinition> endActionUserData; // 60
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SendSignalTaskDefinition, 0x70);
RED4EXT_ASSERT_OFFSET(SendSignalTaskDefinition, signalName, 0x38);
RED4EXT_ASSERT_OFFSET(SendSignalTaskDefinition, startAction, 0x40);
RED4EXT_ASSERT_OFFSET(SendSignalTaskDefinition, startActionUserData, 0x48);
RED4EXT_ASSERT_OFFSET(SendSignalTaskDefinition, endAction, 0x58);
RED4EXT_ASSERT_OFFSET(SendSignalTaskDefinition, endActionUserData, 0x60);
#else
RED4EXT_ASSERT_SIZE(SendSignalTaskDefinition, 0x70);
#endif
} // namespace AI::behavior
using AIbehaviorSendSignalTaskDefinition = AI::behavior::SendSignalTaskDefinition;
} // namespace RED4ext

// clang-format on
