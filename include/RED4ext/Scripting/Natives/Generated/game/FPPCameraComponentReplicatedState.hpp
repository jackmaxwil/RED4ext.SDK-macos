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
struct FPPCameraComponentReplicatedState : net::IComponentState
{
    static constexpr const char* NAME = "gameFPPCameraComponentReplicatedState";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    float lookAtData_m_pitchInput; // 1C -- lookAtData.m_pitchInput
    float lookAtData_m_pitchRef; // 20 -- lookAtData.m_pitchRef
    float lookAtData_m_yawInput; // 24 -- lookAtData.m_yawInput
    float lookAtData_m_yawRef; // 28 -- lookAtData.m_yawRef
    uint8_t unk2C[0x30 - 0x2C]; // 2C
#else
    float lookAtData_m_pitchInput; // 20 -- lookAtData.m_pitchInput
    float lookAtData_m_pitchRef; // 24 -- lookAtData.m_pitchRef
    float lookAtData_m_yawInput; // 28 -- lookAtData.m_yawInput
    float lookAtData_m_yawRef; // 2C -- lookAtData.m_yawRef
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(FPPCameraComponentReplicatedState, 0x30);
RED4EXT_ASSERT_OFFSET(FPPCameraComponentReplicatedState, lookAtData_m_pitchInput, 0x1C);
RED4EXT_ASSERT_OFFSET(FPPCameraComponentReplicatedState, lookAtData_m_pitchRef, 0x20);
RED4EXT_ASSERT_OFFSET(FPPCameraComponentReplicatedState, lookAtData_m_yawInput, 0x24);
RED4EXT_ASSERT_OFFSET(FPPCameraComponentReplicatedState, lookAtData_m_yawRef, 0x28);
#else
RED4EXT_ASSERT_SIZE(FPPCameraComponentReplicatedState, 0x30);
#endif
} // namespace game
using gameFPPCameraComponentReplicatedState = game::FPPCameraComponentReplicatedState;
} // namespace RED4ext

// clang-format on
