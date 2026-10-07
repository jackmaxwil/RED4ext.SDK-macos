#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/WeakSpotReplicatedInfo.hpp>
#include <RED4ext/Scripting/Natives/Generated/net/IComponentState.hpp>

namespace RED4ext
{
namespace game
{
struct WeakspotComponentReplicatedState : net::IComponentState
{
    static constexpr const char* NAME = "gameWeakspotComponentReplicatedState";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk1C[0x20 - 0x1C]; // 1C
    DynArray<game::WeakSpotReplicatedInfo> WeakspotRepInfos; // 20
#else
    DynArray<game::WeakSpotReplicatedInfo> WeakspotRepInfos; // 20
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(WeakspotComponentReplicatedState, 0x30);
RED4EXT_ASSERT_OFFSET(WeakspotComponentReplicatedState, WeakspotRepInfos, 0x20);
#else
RED4EXT_ASSERT_SIZE(WeakspotComponentReplicatedState, 0x30);
#endif
} // namespace game
using gameWeakspotComponentReplicatedState = game::WeakspotComponentReplicatedState;
} // namespace RED4ext

// clang-format on
