#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/behavior/TaskDefinition.hpp>

namespace RED4ext
{
namespace AI { struct ArgumentMapping; }

namespace AI::behavior
{
struct SelectWorkspotEntryTaskDefinition : AI::behavior::TaskDefinition
{
    static constexpr const char* NAME = "AIbehaviorSelectWorkspotEntryTaskDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk31[0x38 - 0x31]; // 31
    Handle<AI::ArgumentMapping> workspotData; // 38
    Handle<AI::ArgumentMapping> destinationPosition; // 48
    Handle<AI::ArgumentMapping> tangentPoint; // 58
    Handle<AI::ArgumentMapping> entranceFromStand; // 68
#else
    Handle<AI::ArgumentMapping> workspotData; // 38
    Handle<AI::ArgumentMapping> destinationPosition; // 48
    Handle<AI::ArgumentMapping> tangentPoint; // 58
    Handle<AI::ArgumentMapping> entranceFromStand; // 68
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SelectWorkspotEntryTaskDefinition, 0x78);
RED4EXT_ASSERT_OFFSET(SelectWorkspotEntryTaskDefinition, workspotData, 0x38);
RED4EXT_ASSERT_OFFSET(SelectWorkspotEntryTaskDefinition, destinationPosition, 0x48);
RED4EXT_ASSERT_OFFSET(SelectWorkspotEntryTaskDefinition, tangentPoint, 0x58);
RED4EXT_ASSERT_OFFSET(SelectWorkspotEntryTaskDefinition, entranceFromStand, 0x68);
#else
RED4EXT_ASSERT_SIZE(SelectWorkspotEntryTaskDefinition, 0x78);
#endif
} // namespace AI::behavior
using AIbehaviorSelectWorkspotEntryTaskDefinition = AI::behavior::SelectWorkspotEntryTaskDefinition;
} // namespace RED4ext

// clang-format on
