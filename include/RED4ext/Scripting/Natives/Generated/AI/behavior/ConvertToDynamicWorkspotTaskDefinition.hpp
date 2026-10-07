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
struct ConvertToDynamicWorkspotTaskDefinition : AI::behavior::TaskDefinition
{
    static constexpr const char* NAME = "AIbehaviorConvertToDynamicWorkspotTaskDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk31[0x38 - 0x31]; // 31
    Handle<AI::ArgumentMapping> workspotData; // 38
    Handle<AI::ArgumentMapping> spotInstance; // 48
    Handle<AI::ArgumentMapping> jumpToEntry; // 58
    Handle<AI::ArgumentMapping> entryId; // 68
#else
    Handle<AI::ArgumentMapping> workspotData; // 38
    Handle<AI::ArgumentMapping> spotInstance; // 48
    Handle<AI::ArgumentMapping> jumpToEntry; // 58
    Handle<AI::ArgumentMapping> entryId; // 68
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ConvertToDynamicWorkspotTaskDefinition, 0x78);
RED4EXT_ASSERT_OFFSET(ConvertToDynamicWorkspotTaskDefinition, workspotData, 0x38);
RED4EXT_ASSERT_OFFSET(ConvertToDynamicWorkspotTaskDefinition, spotInstance, 0x48);
RED4EXT_ASSERT_OFFSET(ConvertToDynamicWorkspotTaskDefinition, jumpToEntry, 0x58);
RED4EXT_ASSERT_OFFSET(ConvertToDynamicWorkspotTaskDefinition, entryId, 0x68);
#else
RED4EXT_ASSERT_SIZE(ConvertToDynamicWorkspotTaskDefinition, 0x78);
#endif
} // namespace AI::behavior
using AIbehaviorConvertToDynamicWorkspotTaskDefinition = AI::behavior::ConvertToDynamicWorkspotTaskDefinition;
} // namespace RED4ext

// clang-format on
