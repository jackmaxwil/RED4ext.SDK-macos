#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_FloatValue.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/FloatLink.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_CriticalSpringDamp : anim::AnimNode_FloatValue
{
    static constexpr const char* NAME = "animAnimNode_CriticalSpringDamp";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    float smoothTime; // 44
    bool useRange; // 48
    uint8_t unk49[0x4C - 0x49]; // 49
    float rangeMin; // 4C
    float rangeMax; // 50
    bool useRawTime; // 54
    uint8_t unk55[0x58 - 0x55]; // 55
    anim::FloatLink inputNode; // 58
    uint8_t unk78[0x98 - 0x78]; // 78
#else
    float smoothTime; // 48
    bool useRange; // 4C
    uint8_t unk4D[0x50 - 0x4D]; // 4D
    float rangeMin; // 50
    float rangeMax; // 54
    bool useRawTime; // 58
    uint8_t unk59[0x60 - 0x59]; // 59
    anim::FloatLink inputNode; // 60
    uint8_t unk80[0xA0 - 0x80]; // 80
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_CriticalSpringDamp, 0x98);
RED4EXT_ASSERT_OFFSET(AnimNode_CriticalSpringDamp, smoothTime, 0x44);
RED4EXT_ASSERT_OFFSET(AnimNode_CriticalSpringDamp, useRange, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_CriticalSpringDamp, rangeMin, 0x4C);
RED4EXT_ASSERT_OFFSET(AnimNode_CriticalSpringDamp, rangeMax, 0x50);
RED4EXT_ASSERT_OFFSET(AnimNode_CriticalSpringDamp, useRawTime, 0x54);
RED4EXT_ASSERT_OFFSET(AnimNode_CriticalSpringDamp, inputNode, 0x58);
#else
RED4EXT_ASSERT_SIZE(AnimNode_CriticalSpringDamp, 0xA0);
#endif
} // namespace anim
using animAnimNode_CriticalSpringDamp = anim::AnimNode_CriticalSpringDamp;
} // namespace RED4ext

// clang-format on
