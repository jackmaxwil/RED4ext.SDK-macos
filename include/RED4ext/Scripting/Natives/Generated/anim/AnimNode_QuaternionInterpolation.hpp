#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_QuaternionValue.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/FloatLink.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/QuaternionInterpolationType.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/QuaternionLink.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_QuaternionInterpolation : anim::AnimNode_QuaternionValue
{
    static constexpr const char* NAME = "animAnimNode_QuaternionInterpolation";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    anim::QuaternionInterpolationType interpolationType; // 44
    anim::QuaternionLink firstInput; // 48
    anim::QuaternionLink secondInput; // 68
    anim::FloatLink weight; // 88
#else
    anim::QuaternionInterpolationType interpolationType; // 48
    uint8_t unk4C[0x50 - 0x4C]; // 4C
    anim::QuaternionLink firstInput; // 50
    anim::QuaternionLink secondInput; // 70
    anim::FloatLink weight; // 90
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_QuaternionInterpolation, 0xA8);
RED4EXT_ASSERT_OFFSET(AnimNode_QuaternionInterpolation, interpolationType, 0x44);
RED4EXT_ASSERT_OFFSET(AnimNode_QuaternionInterpolation, firstInput, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_QuaternionInterpolation, secondInput, 0x68);
RED4EXT_ASSERT_OFFSET(AnimNode_QuaternionInterpolation, weight, 0x88);
#else
RED4EXT_ASSERT_SIZE(AnimNode_QuaternionInterpolation, 0xB0);
#endif
} // namespace anim
using animAnimNode_QuaternionInterpolation = anim::AnimNode_QuaternionInterpolation;
} // namespace RED4ext

// clang-format on
