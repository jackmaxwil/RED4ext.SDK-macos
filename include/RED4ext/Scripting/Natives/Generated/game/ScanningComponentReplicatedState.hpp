#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/StaticArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ScanningState.hpp>
#include <RED4ext/Scripting/Natives/Generated/net/IComponentState.hpp>
#include <RED4ext/Scripting/Natives/Generated/net/PeerID.hpp>

namespace RED4ext
{
namespace game
{
struct ScanningComponentReplicatedState : net::IComponentState
{
    static constexpr const char* NAME = "gameScanningComponentReplicatedState";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    game::ScanningState scanningState; // 1C
    float pctScanned; // 20
    uint8_t unk24[0x28 - 0x24]; // 24
    StaticArray<net::PeerID, 8> controllingPeerIDs; // 28
    uint8_t unk34[0x38 - 0x34]; // 34
#else
    game::ScanningState scanningState; // 20
    float pctScanned; // 24
    uint8_t unk28[0x2C - 0x28]; // 28
    StaticArray<net::PeerID, 8> controllingPeerIDs; // 2C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ScanningComponentReplicatedState, 0x38);
RED4EXT_ASSERT_OFFSET(ScanningComponentReplicatedState, scanningState, 0x1C);
RED4EXT_ASSERT_OFFSET(ScanningComponentReplicatedState, pctScanned, 0x20);
RED4EXT_ASSERT_OFFSET(ScanningComponentReplicatedState, controllingPeerIDs, 0x28);
#else
RED4EXT_ASSERT_SIZE(ScanningComponentReplicatedState, 0x38);
#endif
} // namespace game
using gameScanningComponentReplicatedState = game::ScanningComponentReplicatedState;
} // namespace RED4ext

// clang-format on
