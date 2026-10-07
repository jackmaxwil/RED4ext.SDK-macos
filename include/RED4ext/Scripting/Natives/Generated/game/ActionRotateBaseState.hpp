#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ActionReplicatedState.hpp>

namespace RED4ext
{
namespace game
{
struct ActionRotateBaseState : game::ActionReplicatedState
{
    static constexpr const char* NAME = "gameActionRotateBaseState";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    float angleOffset; // 24
    float angleTolerance; // 28
    bool keepUpdatingTarget; // 2C
    bool useRotationTime; // 2D
    uint8_t unk2E[0x30 - 0x2E]; // 2E
    float rotationSpeed; // 30
    float rotationTime; // 34
#else
    float angleOffset; // 28
    float angleTolerance; // 2C
    bool keepUpdatingTarget; // 30
    bool useRotationTime; // 31
    uint8_t unk32[0x34 - 0x32]; // 32
    float rotationSpeed; // 34
    float rotationTime; // 38
    uint8_t unk3C[0x40 - 0x3C]; // 3C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ActionRotateBaseState, 0x38);
RED4EXT_ASSERT_OFFSET(ActionRotateBaseState, angleOffset, 0x24);
RED4EXT_ASSERT_OFFSET(ActionRotateBaseState, angleTolerance, 0x28);
RED4EXT_ASSERT_OFFSET(ActionRotateBaseState, keepUpdatingTarget, 0x2C);
RED4EXT_ASSERT_OFFSET(ActionRotateBaseState, useRotationTime, 0x2D);
RED4EXT_ASSERT_OFFSET(ActionRotateBaseState, rotationSpeed, 0x30);
RED4EXT_ASSERT_OFFSET(ActionRotateBaseState, rotationTime, 0x34);
#else
RED4EXT_ASSERT_SIZE(ActionRotateBaseState, 0x40);
#endif
} // namespace game
using gameActionRotateBaseState = game::ActionRotateBaseState;
} // namespace RED4ext

// clang-format on
