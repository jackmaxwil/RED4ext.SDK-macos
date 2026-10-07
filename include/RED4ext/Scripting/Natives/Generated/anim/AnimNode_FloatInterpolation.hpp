#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_FloatValue.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/EAnimGraphMathInterpolation.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/FloatLink.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_FloatInterpolation : anim::AnimNode_FloatValue
{
    static constexpr const char* NAME = "animAnimNode_FloatInterpolation";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    float x1; // 44
    float y1; // 48
    float x2; // 4C
    float y2; // 50
    anim::EAnimGraphMathInterpolation interpolationType; // 54
    anim::FloatLink inputNode; // 58
#else
    float x1; // 48
    float y1; // 4C
    float x2; // 50
    float y2; // 54
    anim::EAnimGraphMathInterpolation interpolationType; // 58
    uint8_t unk5C[0x60 - 0x5C]; // 5C
    anim::FloatLink inputNode; // 60
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_FloatInterpolation, 0x78);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatInterpolation, x1, 0x44);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatInterpolation, y1, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatInterpolation, x2, 0x4C);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatInterpolation, y2, 0x50);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatInterpolation, interpolationType, 0x54);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatInterpolation, inputNode, 0x58);
#else
RED4EXT_ASSERT_SIZE(AnimNode_FloatInterpolation, 0x80);
#endif
} // namespace anim
using animAnimNode_FloatInterpolation = anim::AnimNode_FloatInterpolation;
} // namespace RED4ext

// clang-format on
