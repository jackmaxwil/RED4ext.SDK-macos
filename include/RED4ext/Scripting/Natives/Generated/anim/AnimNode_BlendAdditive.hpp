#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_Base.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/EAnimGraphAdditiveType.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/EBlendTracksMode.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/FloatLink.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/NamedTrackIndex.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/PoseLink.hpp>

namespace RED4ext
{
namespace anim { struct IAnimNode_PostProcess; }
namespace anim { struct ISyncMethod; }

namespace anim
{
struct AnimNode_BlendAdditive : anim::AnimNode_Base
{
    static constexpr const char* NAME = "animAnimNode_BlendAdditive";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    float biasValue; // 44
    float scaleValue; // 48
    uint8_t unk4C[0x50 - 0x4C]; // 4C
    Handle<anim::ISyncMethod> syncMethod; // 50
    bool timeWarpingEnabled; // 60
    uint8_t unk61[0x64 - 0x61]; // 61
    anim::EAnimGraphAdditiveType additiveType; // 64
    anim::EBlendTracksMode blendTracks; // 68
    uint8_t unk6C[0x70 - 0x6C]; // 6C
    Handle<anim::IAnimNode_PostProcess> postProcess; // 70
    anim::NamedTrackIndex weightPreviousFrameFloatTrack; // 80
    float weightPreviousFrameFloatTrackDefaultValue; // 98
    uint8_t unk9C[0xE0 - 0x9C]; // 9C
    anim::PoseLink inputNode; // E0
    anim::PoseLink addedInputNode; // F8
    anim::FloatLink weightNode; // 110
    CName maskName; // 130
    uint8_t unk138[0x148 - 0x138]; // 138
#else
    float biasValue; // 48
    float scaleValue; // 4C
    Handle<anim::ISyncMethod> syncMethod; // 50
    bool timeWarpingEnabled; // 60
    uint8_t unk61[0x64 - 0x61]; // 61
    anim::EAnimGraphAdditiveType additiveType; // 64
    anim::EBlendTracksMode blendTracks; // 68
    uint8_t unk6C[0x70 - 0x6C]; // 6C
    Handle<anim::IAnimNode_PostProcess> postProcess; // 70
    anim::NamedTrackIndex weightPreviousFrameFloatTrack; // 80
    float weightPreviousFrameFloatTrackDefaultValue; // 98
    uint8_t unk9C[0xE0 - 0x9C]; // 9C
    anim::PoseLink inputNode; // E0
    anim::PoseLink addedInputNode; // F8
    anim::FloatLink weightNode; // 110
    CName maskName; // 130
    uint8_t unk138[0x148 - 0x138]; // 138
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_BlendAdditive, 0x148);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendAdditive, biasValue, 0x44);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendAdditive, scaleValue, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendAdditive, syncMethod, 0x50);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendAdditive, timeWarpingEnabled, 0x60);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendAdditive, additiveType, 0x64);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendAdditive, blendTracks, 0x68);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendAdditive, postProcess, 0x70);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendAdditive, weightPreviousFrameFloatTrack, 0x80);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendAdditive, weightPreviousFrameFloatTrackDefaultValue, 0x98);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendAdditive, inputNode, 0xE0);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendAdditive, addedInputNode, 0xF8);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendAdditive, weightNode, 0x110);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendAdditive, maskName, 0x130);
#else
RED4EXT_ASSERT_SIZE(AnimNode_BlendAdditive, 0x148);
#endif
} // namespace anim
using animAnimNode_BlendAdditive = anim::AnimNode_BlendAdditive;
} // namespace RED4ext

// clang-format on
