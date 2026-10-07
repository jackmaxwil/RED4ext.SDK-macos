#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_FloatValue.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/BoolLink.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/FloatLink.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_FloatCumulative : anim::AnimNode_FloatValue
{
    static constexpr const char* NAME = "animAnimNode_FloatCumulative";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x58 - 0x44]; // 44
    bool clamp; // 58
    bool resetOnActivation; // 59
    bool normalize180; // 5A
    uint8_t unk5B[0x5C - 0x5B]; // 5B
    float defaultValue; // 5C
    CName resetExternalEventName; // 60
    anim::FloatLink inputNode; // 68
    anim::FloatLink minValue; // 88
    anim::FloatLink maxValue; // A8
    anim::FloatLink resetSpeed; // C8
    anim::BoolLink normalize180Input; // E8
    anim::BoolLink override; // 108
    anim::FloatLink curValue; // 128
#else
    uint8_t unk48[0x58 - 0x48]; // 48
    bool clamp; // 58
    bool resetOnActivation; // 59
    bool normalize180; // 5A
    uint8_t unk5B[0x5C - 0x5B]; // 5B
    float defaultValue; // 5C
    CName resetExternalEventName; // 60
    anim::FloatLink inputNode; // 68
    anim::FloatLink minValue; // 88
    anim::FloatLink maxValue; // A8
    anim::FloatLink resetSpeed; // C8
    anim::BoolLink normalize180Input; // E8
    anim::BoolLink override; // 108
    anim::FloatLink curValue; // 128
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_FloatCumulative, 0x148);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatCumulative, clamp, 0x58);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatCumulative, resetOnActivation, 0x59);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatCumulative, normalize180, 0x5A);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatCumulative, defaultValue, 0x5C);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatCumulative, resetExternalEventName, 0x60);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatCumulative, inputNode, 0x68);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatCumulative, minValue, 0x88);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatCumulative, maxValue, 0xA8);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatCumulative, resetSpeed, 0xC8);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatCumulative, normalize180Input, 0xE8);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatCumulative, override, 0x108);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatCumulative, curValue, 0x128);
#else
RED4EXT_ASSERT_SIZE(AnimNode_FloatCumulative, 0x148);
#endif
} // namespace anim
using animAnimNode_FloatCumulative = anim::AnimNode_FloatCumulative;
} // namespace RED4ext

// clang-format on
