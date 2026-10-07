#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/SignalStoppingNodeDefinition.hpp>

namespace RED4ext
{
namespace quest { struct IBehaviourManager_NodeType; }
namespace work { struct IWorkspotQuestAction; }

namespace quest
{
struct BehaviourManagerNodeDefinition : quest::SignalStoppingNodeDefinition
{
    static constexpr const char* NAME = "questBehaviourManagerNodeDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk42[0x48 - 0x42]; // 42
    game::EntityReference puppet; // 48
    Handle<work::IWorkspotQuestAction> type; // 80
    Handle<quest::IBehaviourManager_NodeType> newType; // 90
#else
    game::EntityReference puppet; // 48
    Handle<work::IWorkspotQuestAction> type; // 80
    Handle<quest::IBehaviourManager_NodeType> newType; // 90
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(BehaviourManagerNodeDefinition, 0xA0);
RED4EXT_ASSERT_OFFSET(BehaviourManagerNodeDefinition, puppet, 0x48);
RED4EXT_ASSERT_OFFSET(BehaviourManagerNodeDefinition, type, 0x80);
RED4EXT_ASSERT_OFFSET(BehaviourManagerNodeDefinition, newType, 0x90);
#else
RED4EXT_ASSERT_SIZE(BehaviourManagerNodeDefinition, 0xA0);
#endif
} // namespace quest
using questBehaviourManagerNodeDefinition = quest::BehaviourManagerNodeDefinition;
} // namespace RED4ext

// clang-format on
