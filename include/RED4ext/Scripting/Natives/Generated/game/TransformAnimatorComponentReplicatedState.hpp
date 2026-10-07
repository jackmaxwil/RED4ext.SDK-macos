#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/net/IComponentState.hpp>

namespace RED4ext
{
namespace game
{
struct TransformAnimatorComponentReplicatedState : net::IComponentState
{
    static constexpr const char* NAME = "gameTransformAnimatorComponentReplicatedState";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk1C[0x48 - 0x1C]; // 1C
#else
    uint8_t unk20[0x48 - 0x20]; // 20
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TransformAnimatorComponentReplicatedState, 0x48);
#else
RED4EXT_ASSERT_SIZE(TransformAnimatorComponentReplicatedState, 0x48);
#endif
} // namespace game
using gameTransformAnimatorComponentReplicatedState = game::TransformAnimatorComponentReplicatedState;
} // namespace RED4ext

// clang-format on
