#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/NetAIState.hpp>
#include <RED4ext/Scripting/Natives/Generated/net/IComponentState.hpp>

namespace RED4ext
{
namespace game
{
struct AINetStateComponentReplicatedState : net::IComponentState
{
    static constexpr const char* NAME = "gameAINetStateComponentReplicatedState";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    game::NetAIState replHighLevelState; // 1C
    game::NetAIState replUpperBodyState; // 28
    game::NetAIState replStanceState; // 34
    game::NetAIState replHitReactionModeState; // 40
    game::NetAIState replBehaviorState; // 4C
    game::NetAIState replPhaseState; // 58
    game::NetAIState replDefenseMode; // 64
    game::NetAIState replLocomotionMode; // 70
    uint8_t unk7C[0x80 - 0x7C]; // 7C
#else
    game::NetAIState replHighLevelState; // 20
    game::NetAIState replUpperBodyState; // 2C
    game::NetAIState replStanceState; // 38
    game::NetAIState replHitReactionModeState; // 44
    game::NetAIState replBehaviorState; // 50
    game::NetAIState replPhaseState; // 5C
    game::NetAIState replDefenseMode; // 68
    game::NetAIState replLocomotionMode; // 74
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AINetStateComponentReplicatedState, 0x80);
RED4EXT_ASSERT_OFFSET(AINetStateComponentReplicatedState, replHighLevelState, 0x1C);
RED4EXT_ASSERT_OFFSET(AINetStateComponentReplicatedState, replUpperBodyState, 0x28);
RED4EXT_ASSERT_OFFSET(AINetStateComponentReplicatedState, replStanceState, 0x34);
RED4EXT_ASSERT_OFFSET(AINetStateComponentReplicatedState, replHitReactionModeState, 0x40);
RED4EXT_ASSERT_OFFSET(AINetStateComponentReplicatedState, replBehaviorState, 0x4C);
RED4EXT_ASSERT_OFFSET(AINetStateComponentReplicatedState, replPhaseState, 0x58);
RED4EXT_ASSERT_OFFSET(AINetStateComponentReplicatedState, replDefenseMode, 0x64);
RED4EXT_ASSERT_OFFSET(AINetStateComponentReplicatedState, replLocomotionMode, 0x70);
#else
RED4EXT_ASSERT_SIZE(AINetStateComponentReplicatedState, 0x80);
#endif
} // namespace game
using gameAINetStateComponentReplicatedState = game::AINetStateComponentReplicatedState;
} // namespace RED4ext

// clang-format on
