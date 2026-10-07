#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_Base.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/FloatLink.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/FloatTrackOperationType.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/NamedTrackIndex.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/PoseLink.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_FloatTrackModifier : anim::AnimNode_Base
{
    static constexpr const char* NAME = "animAnimNode_FloatTrackModifier";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x48 - 0x44]; // 44
    anim::NamedTrackIndex floatTrack; // 48
    anim::FloatTrackOperationType operationType; // 60
    uint8_t unk64[0x68 - 0x64]; // 64
    anim::NamedTrackIndex inputFloatTrack; // 68
    anim::PoseLink poseInputNode; // 80
    anim::FloatLink floatInputNode; // 98
#else
    anim::NamedTrackIndex floatTrack; // 48
    anim::FloatTrackOperationType operationType; // 60
    uint8_t unk64[0x68 - 0x64]; // 64
    anim::NamedTrackIndex inputFloatTrack; // 68
    anim::PoseLink poseInputNode; // 80
    anim::FloatLink floatInputNode; // 98
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_FloatTrackModifier, 0xB8);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatTrackModifier, floatTrack, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatTrackModifier, operationType, 0x60);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatTrackModifier, inputFloatTrack, 0x68);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatTrackModifier, poseInputNode, 0x80);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatTrackModifier, floatInputNode, 0x98);
#else
RED4EXT_ASSERT_SIZE(AnimNode_FloatTrackModifier, 0xB8);
#endif
} // namespace anim
using animAnimNode_FloatTrackModifier = anim::AnimNode_FloatTrackModifier;
} // namespace RED4ext

// clang-format on
