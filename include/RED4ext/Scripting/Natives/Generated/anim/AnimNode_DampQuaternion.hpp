#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/EulerAngles.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_QuaternionValue.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/FloatLink.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/QuaternionLink.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_DampQuaternion : anim::AnimNode_QuaternionValue
{
    static constexpr const char* NAME = "animAnimNode_DampQuaternion";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    float defaultRotationSpeed; // 44
    EulerAngles defaultInitialValue; // 48
    uint8_t unk54[0x58 - 0x54]; // 54
    anim::QuaternionLink inputNode; // 58
    anim::FloatLink rotationSpeedNode; // 78
    anim::QuaternionLink initialValueNode; // 98
    uint8_t unkB8[0xC8 - 0xB8]; // B8
#else
    float defaultRotationSpeed; // 48
    EulerAngles defaultInitialValue; // 4C
    anim::QuaternionLink inputNode; // 58
    anim::FloatLink rotationSpeedNode; // 78
    anim::QuaternionLink initialValueNode; // 98
    uint8_t unkB8[0xC8 - 0xB8]; // B8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_DampQuaternion, 0xC8);
RED4EXT_ASSERT_OFFSET(AnimNode_DampQuaternion, defaultRotationSpeed, 0x44);
RED4EXT_ASSERT_OFFSET(AnimNode_DampQuaternion, defaultInitialValue, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_DampQuaternion, inputNode, 0x58);
RED4EXT_ASSERT_OFFSET(AnimNode_DampQuaternion, rotationSpeedNode, 0x78);
RED4EXT_ASSERT_OFFSET(AnimNode_DampQuaternion, initialValueNode, 0x98);
#else
RED4EXT_ASSERT_SIZE(AnimNode_DampQuaternion, 0xC8);
#endif
} // namespace anim
using animAnimNode_DampQuaternion = anim::AnimNode_DampQuaternion;
} // namespace RED4ext

// clang-format on
