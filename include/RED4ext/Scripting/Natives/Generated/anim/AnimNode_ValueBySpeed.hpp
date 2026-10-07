#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_FloatValue.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/ClampType.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/FloatLink.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_ValueBySpeed : anim::AnimNode_FloatValue
{
    static constexpr const char* NAME = "animAnimNode_ValueBySpeed";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    float defaultValue; // 44
    anim::ClampType clampType; // 48
    float rangeMin; // 4C
    float rangeMax; // 50
    bool resetOnActivation; // 54
    uint8_t unk55[0x58 - 0x55]; // 55
    anim::FloatLink speed; // 58
    uint8_t unk78[0x88 - 0x78]; // 78
#else
    float defaultValue; // 48
    anim::ClampType clampType; // 4C
    float rangeMin; // 50
    float rangeMax; // 54
    bool resetOnActivation; // 58
    uint8_t unk59[0x60 - 0x59]; // 59
    anim::FloatLink speed; // 60
    uint8_t unk80[0x90 - 0x80]; // 80
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_ValueBySpeed, 0x88);
RED4EXT_ASSERT_OFFSET(AnimNode_ValueBySpeed, defaultValue, 0x44);
RED4EXT_ASSERT_OFFSET(AnimNode_ValueBySpeed, clampType, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_ValueBySpeed, rangeMin, 0x4C);
RED4EXT_ASSERT_OFFSET(AnimNode_ValueBySpeed, rangeMax, 0x50);
RED4EXT_ASSERT_OFFSET(AnimNode_ValueBySpeed, resetOnActivation, 0x54);
RED4EXT_ASSERT_OFFSET(AnimNode_ValueBySpeed, speed, 0x58);
#else
RED4EXT_ASSERT_SIZE(AnimNode_ValueBySpeed, 0x90);
#endif
} // namespace anim
using animAnimNode_ValueBySpeed = anim::AnimNode_ValueBySpeed;
} // namespace RED4ext

// clang-format on
