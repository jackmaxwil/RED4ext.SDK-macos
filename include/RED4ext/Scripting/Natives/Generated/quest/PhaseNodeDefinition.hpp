#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/EmbeddedGraphNodeDefinition.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/QuestPrefabEntry.hpp>

namespace RED4ext
{
namespace quest { struct GraphDefinition; }
namespace quest { struct QuestPhaseResource; }

namespace quest
{
struct PhaseNodeDefinition : quest::EmbeddedGraphNodeDefinition
{
    static constexpr const char* NAME = "questPhaseNodeDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk42[0x60 - 0x42]; // 42
    Handle<quest::GraphDefinition> phaseGraph; // 60
    DynArray<quest::QuestPrefabEntry> phaseInstancePrefabs; // 70
    NodeRef unfreezingTriggerNodeRef; // 80
    RaRef<quest::QuestPhaseResource> phaseResource; // 88
    bool saveLock; // 90
    uint8_t unk91[0x98 - 0x91]; // 91
#else
    uint8_t unk48[0x60 - 0x48]; // 48
    Handle<quest::GraphDefinition> phaseGraph; // 60
    DynArray<quest::QuestPrefabEntry> phaseInstancePrefabs; // 70
    NodeRef unfreezingTriggerNodeRef; // 80
    RaRef<quest::QuestPhaseResource> phaseResource; // 88
    bool saveLock; // 90
    uint8_t unk91[0x98 - 0x91]; // 91
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PhaseNodeDefinition, 0x98);
RED4EXT_ASSERT_OFFSET(PhaseNodeDefinition, phaseGraph, 0x60);
RED4EXT_ASSERT_OFFSET(PhaseNodeDefinition, phaseInstancePrefabs, 0x70);
RED4EXT_ASSERT_OFFSET(PhaseNodeDefinition, unfreezingTriggerNodeRef, 0x80);
RED4EXT_ASSERT_OFFSET(PhaseNodeDefinition, phaseResource, 0x88);
RED4EXT_ASSERT_OFFSET(PhaseNodeDefinition, saveLock, 0x90);
#else
RED4EXT_ASSERT_SIZE(PhaseNodeDefinition, 0x98);
#endif
} // namespace quest
using questPhaseNodeDefinition = quest::PhaseNodeDefinition;
} // namespace RED4ext

// clang-format on
