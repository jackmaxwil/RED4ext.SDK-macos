#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/AttachmentSlotReplicatedState.hpp>
#include <RED4ext/Scripting/Natives/Generated/net/IComponentState.hpp>

namespace RED4ext
{
namespace game
{
struct AttachmentSlotsReplicatedState : net::IComponentState
{
    static constexpr const char* NAME = "gameAttachmentSlotsReplicatedState";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint32_t stateVersion; // 1C
    DynArray<game::AttachmentSlotReplicatedState> slots; // 20
#else
    uint32_t stateVersion; // 20
    uint8_t unk24[0x28 - 0x24]; // 24
    DynArray<game::AttachmentSlotReplicatedState> slots; // 28
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AttachmentSlotsReplicatedState, 0x30);
RED4EXT_ASSERT_OFFSET(AttachmentSlotsReplicatedState, stateVersion, 0x1C);
RED4EXT_ASSERT_OFFSET(AttachmentSlotsReplicatedState, slots, 0x20);
#else
RED4EXT_ASSERT_SIZE(AttachmentSlotsReplicatedState, 0x38);
#endif
} // namespace game
using gameAttachmentSlotsReplicatedState = game::AttachmentSlotsReplicatedState;
} // namespace RED4ext

// clang-format on
