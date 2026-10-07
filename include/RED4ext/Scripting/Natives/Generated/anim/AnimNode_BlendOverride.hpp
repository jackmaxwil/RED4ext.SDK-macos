#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_Base.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/EBlendTracksMode.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/FloatLink.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/OverrideBlendBoneInfo.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/OverrideBlendTrackInfo.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/PoseLink.hpp>

namespace RED4ext
{
namespace anim { struct IAnimNode_PostProcess; }
namespace anim { struct IPoseBlendMethod; }
namespace anim { struct ISyncMethod; }

namespace anim
{
struct AnimNode_BlendOverride : anim::AnimNode_Base
{
    static constexpr const char* NAME = "animAnimNode_BlendOverride";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool getDeltaMotionFromOverride; // 44
    bool timeWarpingEnabled; // 45
    uint8_t unk46[0x48 - 0x46]; // 46
    Handle<anim::ISyncMethod> syncMethod; // 48
    Handle<anim::IPoseBlendMethod> blendMethod; // 58
    DynArray<anim::OverrideBlendBoneInfo> bones; // 68
    DynArray<anim::OverrideBlendTrackInfo> tracks; // 78
    anim::EBlendTracksMode blendTrackMode; // 88
    bool blendAllTracks; // 8C
    uint8_t unk8D[0x90 - 0x8D]; // 8D
    Handle<anim::IAnimNode_PostProcess> postProcess; // 90
    uint8_t unkA0[0xD0 - 0xA0]; // A0
    anim::PoseLink inputNode; // D0
    anim::PoseLink overrideInputNode; // E8
    anim::FloatLink weightNode; // 100
#else
    bool getDeltaMotionFromOverride; // 48
    bool timeWarpingEnabled; // 49
    uint8_t unk4A[0x50 - 0x4A]; // 4A
    Handle<anim::ISyncMethod> syncMethod; // 50
    Handle<anim::IPoseBlendMethod> blendMethod; // 60
    DynArray<anim::OverrideBlendBoneInfo> bones; // 70
    DynArray<anim::OverrideBlendTrackInfo> tracks; // 80
    anim::EBlendTracksMode blendTrackMode; // 90
    bool blendAllTracks; // 94
    uint8_t unk95[0x98 - 0x95]; // 95
    Handle<anim::IAnimNode_PostProcess> postProcess; // 98
    uint8_t unkA8[0xD8 - 0xA8]; // A8
    anim::PoseLink inputNode; // D8
    anim::PoseLink overrideInputNode; // F0
    anim::FloatLink weightNode; // 108
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_BlendOverride, 0x120);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendOverride, getDeltaMotionFromOverride, 0x44);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendOverride, timeWarpingEnabled, 0x45);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendOverride, syncMethod, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendOverride, blendMethod, 0x58);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendOverride, bones, 0x68);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendOverride, tracks, 0x78);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendOverride, blendTrackMode, 0x88);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendOverride, blendAllTracks, 0x8C);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendOverride, postProcess, 0x90);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendOverride, inputNode, 0xD0);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendOverride, overrideInputNode, 0xE8);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendOverride, weightNode, 0x100);
#else
RED4EXT_ASSERT_SIZE(AnimNode_BlendOverride, 0x128);
#endif
} // namespace anim
using animAnimNode_BlendOverride = anim::AnimNode_BlendOverride;
} // namespace RED4ext

// clang-format on
