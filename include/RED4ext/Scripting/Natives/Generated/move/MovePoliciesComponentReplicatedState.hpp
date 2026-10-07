#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/move/ReplicatedMovePoliciesState.hpp>
#include <RED4ext/Scripting/Natives/Generated/net/IComponentState.hpp>

namespace RED4ext
{
namespace move
{
struct MovePoliciesComponentReplicatedState : net::IComponentState
{
    static constexpr const char* NAME = "moveMovePoliciesComponentReplicatedState";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk1C[0x20 - 0x1C]; // 1C
    move::ReplicatedMovePoliciesState movePolicies; // 20
#else
    move::ReplicatedMovePoliciesState movePolicies; // 20
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MovePoliciesComponentReplicatedState, 0x60);
RED4EXT_ASSERT_OFFSET(MovePoliciesComponentReplicatedState, movePolicies, 0x20);
#else
RED4EXT_ASSERT_SIZE(MovePoliciesComponentReplicatedState, 0x60);
#endif
} // namespace move
using moveMovePoliciesComponentReplicatedState = move::MovePoliciesComponentReplicatedState;
} // namespace RED4ext

// clang-format on
