#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_Base.hpp>

namespace RED4ext
{
namespace anim { struct IMotionTableProvider; }

namespace anim
{
struct AnimNode_SkAnim : anim::AnimNode_Base
{
    static constexpr const char* NAME = "animAnimNode_SkAnim";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x48 - 0x44]; // 44
    CName animLoopEventName; // 48
    bool applyMotion; // 50
    bool isLooped; // 51
    bool collectEvents; // 52
    bool fireAnimLoopEvent; // 53
    float clipFront; // 54
    float clipEnd; // 58
    bool convertToAdditive; // 5C
    bool resume; // 5D
    bool applyInertializationOnAnimSetSwap; // 5E
    uint8_t unk5F[0x60 - 0x5F]; // 5F
    CName clipFrontByEvent; // 60
    CName clipEndByEvent; // 68
    Handle<anim::IMotionTableProvider> motionProvider; // 70
    CName pushDataByTag; // 80
    CName popDataByTag; // 88
    CName pushSafeCutTag; // 90
    uint8_t unk98[0xC8 - 0x98]; // 98
    CName animation; // C8
#else
    CName animLoopEventName; // 48
    bool applyMotion; // 50
    bool isLooped; // 51
    bool collectEvents; // 52
    bool fireAnimLoopEvent; // 53
    float clipFront; // 54
    float clipEnd; // 58
    bool convertToAdditive; // 5C
    bool resume; // 5D
    bool applyInertializationOnAnimSetSwap; // 5E
    uint8_t unk5F[0x60 - 0x5F]; // 5F
    CName clipFrontByEvent; // 60
    CName clipEndByEvent; // 68
    Handle<anim::IMotionTableProvider> motionProvider; // 70
    CName pushDataByTag; // 80
    CName popDataByTag; // 88
    CName pushSafeCutTag; // 90
    uint8_t unk98[0xC8 - 0x98]; // 98
    CName animation; // C8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_SkAnim, 0xD0);
RED4EXT_ASSERT_OFFSET(AnimNode_SkAnim, animLoopEventName, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_SkAnim, applyMotion, 0x50);
RED4EXT_ASSERT_OFFSET(AnimNode_SkAnim, isLooped, 0x51);
RED4EXT_ASSERT_OFFSET(AnimNode_SkAnim, collectEvents, 0x52);
RED4EXT_ASSERT_OFFSET(AnimNode_SkAnim, fireAnimLoopEvent, 0x53);
RED4EXT_ASSERT_OFFSET(AnimNode_SkAnim, clipFront, 0x54);
RED4EXT_ASSERT_OFFSET(AnimNode_SkAnim, clipEnd, 0x58);
RED4EXT_ASSERT_OFFSET(AnimNode_SkAnim, convertToAdditive, 0x5C);
RED4EXT_ASSERT_OFFSET(AnimNode_SkAnim, resume, 0x5D);
RED4EXT_ASSERT_OFFSET(AnimNode_SkAnim, applyInertializationOnAnimSetSwap, 0x5E);
RED4EXT_ASSERT_OFFSET(AnimNode_SkAnim, clipFrontByEvent, 0x60);
RED4EXT_ASSERT_OFFSET(AnimNode_SkAnim, clipEndByEvent, 0x68);
RED4EXT_ASSERT_OFFSET(AnimNode_SkAnim, motionProvider, 0x70);
RED4EXT_ASSERT_OFFSET(AnimNode_SkAnim, pushDataByTag, 0x80);
RED4EXT_ASSERT_OFFSET(AnimNode_SkAnim, popDataByTag, 0x88);
RED4EXT_ASSERT_OFFSET(AnimNode_SkAnim, pushSafeCutTag, 0x90);
RED4EXT_ASSERT_OFFSET(AnimNode_SkAnim, animation, 0xC8);
#else
RED4EXT_ASSERT_SIZE(AnimNode_SkAnim, 0xD0);
#endif
} // namespace anim
using animAnimNode_SkAnim = anim::AnimNode_SkAnim;
} // namespace RED4ext

// clang-format on
