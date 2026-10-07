#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/cloth/PhaseConfig.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/cloth/RuntimeInfo.hpp>

namespace RED4ext
{
namespace physics::cloth
{
struct __declspec(align(0x10)) State
{
    static constexpr const char* NAME = "physicsclothState";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk00[0x8 - 0x0]; // 0
    physics::cloth::PhaseConfig bendPhaseData; // 08
    physics::cloth::PhaseConfig shearPhaseData; // 18
    physics::cloth::PhaseConfig horizontalPhaseData; // 28
    physics::cloth::PhaseConfig verticalPhaseData; // 38
    uint8_t unk48[0x50 - 0x48]; // 48
    physics::cloth::RuntimeInfo runtimeInfo; // 50
#else
    uint8_t unk00[0x10 - 0x0]; // 0
    physics::cloth::PhaseConfig bendPhaseData; // 10
    physics::cloth::PhaseConfig shearPhaseData; // 20
    physics::cloth::PhaseConfig horizontalPhaseData; // 30
    physics::cloth::PhaseConfig verticalPhaseData; // 40
    physics::cloth::RuntimeInfo runtimeInfo; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(State, 0xC0);
RED4EXT_ASSERT_OFFSET(State, bendPhaseData, 0x8);
RED4EXT_ASSERT_OFFSET(State, shearPhaseData, 0x18);
RED4EXT_ASSERT_OFFSET(State, horizontalPhaseData, 0x28);
RED4EXT_ASSERT_OFFSET(State, verticalPhaseData, 0x38);
RED4EXT_ASSERT_OFFSET(State, runtimeInfo, 0x50);
#else
RED4EXT_ASSERT_SIZE(State, 0xC0);
#endif
} // namespace physics::cloth
using physicsclothState = physics::cloth::State;
} // namespace RED4ext

// clang-format on
