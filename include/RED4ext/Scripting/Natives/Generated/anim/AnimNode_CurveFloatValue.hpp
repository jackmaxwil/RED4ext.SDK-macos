#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_FloatValue.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/FloatLink.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_CurveFloatValue : anim::AnimNode_FloatValue
{
    static constexpr const char* NAME = "animAnimNode_CurveFloatValue";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x48 - 0x44]; // 44
    CurveData<float> curveData; // 48
    anim::FloatLink argument; // 80
#else
    CurveData<float> curveData; // 48
    anim::FloatLink argument; // 80
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_CurveFloatValue, 0xA0);
RED4EXT_ASSERT_OFFSET(AnimNode_CurveFloatValue, curveData, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_CurveFloatValue, argument, 0x80);
#else
RED4EXT_ASSERT_SIZE(AnimNode_CurveFloatValue, 0xA0);
#endif
} // namespace anim
using animAnimNode_CurveFloatValue = anim::AnimNode_CurveFloatValue;
} // namespace RED4ext

// clang-format on
