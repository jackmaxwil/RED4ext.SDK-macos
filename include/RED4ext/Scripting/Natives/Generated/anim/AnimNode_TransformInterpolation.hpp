#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_TransformValue.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/FloatLink.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/QuaternionInterpolationType.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/TransformLink.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_TransformInterpolation : anim::AnimNode_TransformValue
{
    static constexpr const char* NAME = "animAnimNode_TransformInterpolation";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    anim::QuaternionInterpolationType interpolationType; // 44
    anim::TransformLink firstInput; // 48
    anim::TransformLink secondInput; // 68
    anim::FloatLink weight; // 88
#else
    anim::QuaternionInterpolationType interpolationType; // 48
    uint8_t unk4C[0x50 - 0x4C]; // 4C
    anim::TransformLink firstInput; // 50
    anim::TransformLink secondInput; // 70
    anim::FloatLink weight; // 90
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_TransformInterpolation, 0xA8);
RED4EXT_ASSERT_OFFSET(AnimNode_TransformInterpolation, interpolationType, 0x44);
RED4EXT_ASSERT_OFFSET(AnimNode_TransformInterpolation, firstInput, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_TransformInterpolation, secondInput, 0x68);
RED4EXT_ASSERT_OFFSET(AnimNode_TransformInterpolation, weight, 0x88);
#else
RED4EXT_ASSERT_SIZE(AnimNode_TransformInterpolation, 0xB0);
#endif
} // namespace anim
using animAnimNode_TransformInterpolation = anim::AnimNode_TransformInterpolation;
} // namespace RED4ext

// clang-format on
