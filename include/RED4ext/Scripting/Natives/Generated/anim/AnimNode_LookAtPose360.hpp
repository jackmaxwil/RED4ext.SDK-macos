#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_Base.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/FloatLink.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_LookAtPose360 : anim::AnimNode_Base
{
    static constexpr const char* NAME = "animAnimNode_LookAtPose360";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x48 - 0x44]; // 44
    CName animation; // 48
    float speedInDegreesPerSecond; // 50
    float durationCut; // 54
    CName animEndEventName; // 58
    uint8_t unk60[0xB0 - 0x60]; // 60
    anim::FloatLink targetAngleOffsetNode; // B0
    anim::FloatLink angleOffsetNode; // D0
    anim::FloatLink weightNode; // F0
#else
    CName animation; // 48
    float speedInDegreesPerSecond; // 50
    float durationCut; // 54
    CName animEndEventName; // 58
    uint8_t unk60[0xB0 - 0x60]; // 60
    anim::FloatLink targetAngleOffsetNode; // B0
    anim::FloatLink angleOffsetNode; // D0
    anim::FloatLink weightNode; // F0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_LookAtPose360, 0x110);
RED4EXT_ASSERT_OFFSET(AnimNode_LookAtPose360, animation, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_LookAtPose360, speedInDegreesPerSecond, 0x50);
RED4EXT_ASSERT_OFFSET(AnimNode_LookAtPose360, durationCut, 0x54);
RED4EXT_ASSERT_OFFSET(AnimNode_LookAtPose360, animEndEventName, 0x58);
RED4EXT_ASSERT_OFFSET(AnimNode_LookAtPose360, targetAngleOffsetNode, 0xB0);
RED4EXT_ASSERT_OFFSET(AnimNode_LookAtPose360, angleOffsetNode, 0xD0);
RED4EXT_ASSERT_OFFSET(AnimNode_LookAtPose360, weightNode, 0xF0);
#else
RED4EXT_ASSERT_SIZE(AnimNode_LookAtPose360, 0x110);
#endif
} // namespace anim
using animAnimNode_LookAtPose360 = anim::AnimNode_LookAtPose360;
} // namespace RED4ext

// clang-format on
