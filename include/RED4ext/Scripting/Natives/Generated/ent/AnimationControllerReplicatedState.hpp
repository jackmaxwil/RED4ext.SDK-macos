#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/ReplicatedAnimFeaturesState.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/ReplicatedAnimWrapperVars.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/ReplicatedInputSetters.hpp>
#include <RED4ext/Scripting/Natives/Generated/net/IComponentState.hpp>

namespace RED4ext
{
namespace ent
{
struct AnimationControllerReplicatedState : net::IComponentState
{
    static constexpr const char* NAME = "entAnimationControllerReplicatedState";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk1C[0x20 - 0x1C]; // 1C
    ent::ReplicatedAnimWrapperVars animWrapperVarsState; // 20
    uint8_t unk48[0x58 - 0x48]; // 48
    uint32_t lookAtReqs_m_replicatedVersionId; // 58 -- lookAtReqs.m_replicatedVersionId
    uint8_t unk5C[0x70 - 0x5C]; // 5C
    ent::ReplicatedAnimFeaturesState animFeaturesState; // 70
    ent::ReplicatedInputSetters inputSettersState; // A0
#else
    ent::ReplicatedAnimWrapperVars animWrapperVarsState; // 20
    uint8_t unk48[0x58 - 0x48]; // 48
    uint32_t lookAtReqs_m_replicatedVersionId; // 58 -- lookAtReqs.m_replicatedVersionId
    uint8_t unk5C[0x70 - 0x5C]; // 5C
    ent::ReplicatedAnimFeaturesState animFeaturesState; // 70
    ent::ReplicatedInputSetters inputSettersState; // A0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimationControllerReplicatedState, 0xC0);
RED4EXT_ASSERT_OFFSET(AnimationControllerReplicatedState, animWrapperVarsState, 0x20);
RED4EXT_ASSERT_OFFSET(AnimationControllerReplicatedState, lookAtReqs_m_replicatedVersionId, 0x58);
RED4EXT_ASSERT_OFFSET(AnimationControllerReplicatedState, animFeaturesState, 0x70);
RED4EXT_ASSERT_OFFSET(AnimationControllerReplicatedState, inputSettersState, 0xA0);
#else
RED4EXT_ASSERT_SIZE(AnimationControllerReplicatedState, 0xC0);
#endif
} // namespace ent
using entAnimationControllerReplicatedState = ent::AnimationControllerReplicatedState;
} // namespace RED4ext

// clang-format on
