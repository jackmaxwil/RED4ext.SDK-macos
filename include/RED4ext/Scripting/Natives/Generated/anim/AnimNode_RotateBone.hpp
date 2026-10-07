#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_Base.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/ETransformAxis.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/FloatLink.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/PoseLink.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/TransformIndex.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_RotateBone : anim::AnimNode_Base
{
    static constexpr const char* NAME = "animAnimNode_RotateBone";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    float scale; // 44
    float biasAngle; // 48
    float minAngle; // 4C
    float maxAngle; // 50
    uint8_t unk54[0x58 - 0x54]; // 54
    anim::TransformIndex bone; // 58
    anim::ETransformAxis axis; // 70
    bool clampRotation; // 74
    bool useIncrementalMode; // 75
    bool resetOnActivation; // 76
    bool inModelSpace; // 77
    uint8_t unk78[0x88 - 0x78]; // 78
    anim::PoseLink inputNode; // 88
    anim::FloatLink angleNode; // A0
    anim::FloatLink minValueNode; // C0
    anim::FloatLink maxValueNode; // E0
#else
    float scale; // 48
    float biasAngle; // 4C
    float minAngle; // 50
    float maxAngle; // 54
    anim::TransformIndex bone; // 58
    anim::ETransformAxis axis; // 70
    bool clampRotation; // 74
    bool useIncrementalMode; // 75
    bool resetOnActivation; // 76
    bool inModelSpace; // 77
    uint8_t unk78[0x88 - 0x78]; // 78
    anim::PoseLink inputNode; // 88
    anim::FloatLink angleNode; // A0
    anim::FloatLink minValueNode; // C0
    anim::FloatLink maxValueNode; // E0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_RotateBone, 0x100);
RED4EXT_ASSERT_OFFSET(AnimNode_RotateBone, scale, 0x44);
RED4EXT_ASSERT_OFFSET(AnimNode_RotateBone, biasAngle, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_RotateBone, minAngle, 0x4C);
RED4EXT_ASSERT_OFFSET(AnimNode_RotateBone, maxAngle, 0x50);
RED4EXT_ASSERT_OFFSET(AnimNode_RotateBone, bone, 0x58);
RED4EXT_ASSERT_OFFSET(AnimNode_RotateBone, axis, 0x70);
RED4EXT_ASSERT_OFFSET(AnimNode_RotateBone, clampRotation, 0x74);
RED4EXT_ASSERT_OFFSET(AnimNode_RotateBone, useIncrementalMode, 0x75);
RED4EXT_ASSERT_OFFSET(AnimNode_RotateBone, resetOnActivation, 0x76);
RED4EXT_ASSERT_OFFSET(AnimNode_RotateBone, inModelSpace, 0x77);
RED4EXT_ASSERT_OFFSET(AnimNode_RotateBone, inputNode, 0x88);
RED4EXT_ASSERT_OFFSET(AnimNode_RotateBone, angleNode, 0xA0);
RED4EXT_ASSERT_OFFSET(AnimNode_RotateBone, minValueNode, 0xC0);
RED4EXT_ASSERT_OFFSET(AnimNode_RotateBone, maxValueNode, 0xE0);
#else
RED4EXT_ASSERT_SIZE(AnimNode_RotateBone, 0x100);
#endif
} // namespace anim
using animAnimNode_RotateBone = anim::AnimNode_RotateBone;
} // namespace RED4ext

// clang-format on
