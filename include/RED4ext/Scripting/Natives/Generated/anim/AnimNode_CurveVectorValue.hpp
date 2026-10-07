#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector4.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_VectorValue.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/FloatLink.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_CurveVectorValue : anim::AnimNode_VectorValue
{
    static constexpr const char* NAME = "animAnimNode_CurveVectorValue";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x48 - 0x44]; // 44
    CurveData<Vector4> curveData; // 48
    anim::FloatLink argument; // 80
#else
    CurveData<Vector4> curveData; // 48
    anim::FloatLink argument; // 80
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_CurveVectorValue, 0xA0);
RED4EXT_ASSERT_OFFSET(AnimNode_CurveVectorValue, curveData, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_CurveVectorValue, argument, 0x80);
#else
RED4EXT_ASSERT_SIZE(AnimNode_CurveVectorValue, 0xA0);
#endif
} // namespace anim
using animAnimNode_CurveVectorValue = anim::AnimNode_CurveVectorValue;
} // namespace RED4ext

// clang-format on
