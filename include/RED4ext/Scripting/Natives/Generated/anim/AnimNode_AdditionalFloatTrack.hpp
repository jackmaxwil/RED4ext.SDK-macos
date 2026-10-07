#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AdditionalFloatTrackContainer.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_Base.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/PoseLink.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_AdditionalFloatTrack : anim::AnimNode_Base
{
    static constexpr const char* NAME = "animAnimNode_AdditionalFloatTrack";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x58 - 0x44]; // 44
    anim::PoseLink poseInputNode; // 58
    anim::AdditionalFloatTrackContainer additionalTracks; // 70
#else
    uint8_t unk48[0x58 - 0x48]; // 48
    anim::PoseLink poseInputNode; // 58
    anim::AdditionalFloatTrackContainer additionalTracks; // 70
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_AdditionalFloatTrack, 0x88);
RED4EXT_ASSERT_OFFSET(AnimNode_AdditionalFloatTrack, poseInputNode, 0x58);
RED4EXT_ASSERT_OFFSET(AnimNode_AdditionalFloatTrack, additionalTracks, 0x70);
#else
RED4EXT_ASSERT_SIZE(AnimNode_AdditionalFloatTrack, 0x88);
#endif
} // namespace anim
using animAnimNode_AdditionalFloatTrack = anim::AnimNode_AdditionalFloatTrack;
} // namespace RED4ext

// clang-format on
