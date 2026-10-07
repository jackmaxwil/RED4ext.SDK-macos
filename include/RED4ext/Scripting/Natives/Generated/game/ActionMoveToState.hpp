#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector3.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ActionReplicatedState.hpp>

namespace RED4ext
{
namespace game
{
struct ActionMoveToState : game::ActionReplicatedState
{
    static constexpr const char* NAME = "gameActionMoveToState";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    Vector3 targetPos; // 24
    float toleranceRadius; // 30
    bool rotateEntity; // 34
    uint8_t unk35[0x38 - 0x35]; // 35
    uint32_t moveStyle; // 38
    uint8_t unk3C[0x40 - 0x3C]; // 3C
#else
    Vector3 targetPos; // 28
    float toleranceRadius; // 34
    bool rotateEntity; // 38
    uint8_t unk39[0x3C - 0x39]; // 39
    uint32_t moveStyle; // 3C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ActionMoveToState, 0x40);
RED4EXT_ASSERT_OFFSET(ActionMoveToState, targetPos, 0x24);
RED4EXT_ASSERT_OFFSET(ActionMoveToState, toleranceRadius, 0x30);
RED4EXT_ASSERT_OFFSET(ActionMoveToState, rotateEntity, 0x34);
RED4EXT_ASSERT_OFFSET(ActionMoveToState, moveStyle, 0x38);
#else
RED4EXT_ASSERT_SIZE(ActionMoveToState, 0x40);
#endif
} // namespace game
using gameActionMoveToState = game::ActionMoveToState;
} // namespace RED4ext

// clang-format on
