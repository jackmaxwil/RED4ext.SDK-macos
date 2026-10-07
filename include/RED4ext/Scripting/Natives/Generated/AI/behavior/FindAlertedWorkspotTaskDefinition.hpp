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
struct FindAlertedWorkspotTaskDefinition : AI::behavior::TaskDefinition
{
    static constexpr const char* NAME = "AIbehaviorFindAlertedWorkspotTaskDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk31[0x38 - 0x31]; // 31
    Handle<AI::ArgumentMapping> usedTokens; // 38
    Handle<AI::ArgumentMapping> spots; // 48
    Handle<AI::ArgumentMapping> radius; // 58
    Handle<AI::ArgumentMapping> outWorkspotData; // 68
#else
    Handle<AI::ArgumentMapping> usedTokens; // 38
    Handle<AI::ArgumentMapping> spots; // 48
    Handle<AI::ArgumentMapping> radius; // 58
    Handle<AI::ArgumentMapping> outWorkspotData; // 68
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(FindAlertedWorkspotTaskDefinition, 0x78);
RED4EXT_ASSERT_OFFSET(FindAlertedWorkspotTaskDefinition, usedTokens, 0x38);
RED4EXT_ASSERT_OFFSET(FindAlertedWorkspotTaskDefinition, spots, 0x48);
RED4EXT_ASSERT_OFFSET(FindAlertedWorkspotTaskDefinition, radius, 0x58);
RED4EXT_ASSERT_OFFSET(FindAlertedWorkspotTaskDefinition, outWorkspotData, 0x68);
#else
RED4EXT_ASSERT_SIZE(FindAlertedWorkspotTaskDefinition, 0x78);
#endif
} // namespace AI::behavior
using AIbehaviorFindAlertedWorkspotTaskDefinition = AI::behavior::FindAlertedWorkspotTaskDefinition;
} // namespace RED4ext

// clang-format on
