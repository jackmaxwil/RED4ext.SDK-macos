#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_Base.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/PoseLink.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_TriggerBranch : anim::AnimNode_Base
{
    static constexpr const char* NAME = "animAnimNode_TriggerBranch";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x48 - 0x44]; // 44
    anim::PoseLink base; // 48
    anim::PoseLink overlay; // 60
    float blendIn; // 78
    float blendOut; // 7C
    CName startEvent; // 80
    CName endEvent; // 88
    float cooldown; // 90
    uint8_t unk94[0xD8 - 0x94]; // 94
#else
    anim::PoseLink base; // 48
    anim::PoseLink overlay; // 60
    float blendIn; // 78
    float blendOut; // 7C
    CName startEvent; // 80
    CName endEvent; // 88
    float cooldown; // 90
    uint8_t unk94[0xD8 - 0x94]; // 94
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_TriggerBranch, 0xD8);
RED4EXT_ASSERT_OFFSET(AnimNode_TriggerBranch, base, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_TriggerBranch, overlay, 0x60);
RED4EXT_ASSERT_OFFSET(AnimNode_TriggerBranch, blendIn, 0x78);
RED4EXT_ASSERT_OFFSET(AnimNode_TriggerBranch, blendOut, 0x7C);
RED4EXT_ASSERT_OFFSET(AnimNode_TriggerBranch, startEvent, 0x80);
RED4EXT_ASSERT_OFFSET(AnimNode_TriggerBranch, endEvent, 0x88);
RED4EXT_ASSERT_OFFSET(AnimNode_TriggerBranch, cooldown, 0x90);
#else
RED4EXT_ASSERT_SIZE(AnimNode_TriggerBranch, 0xD8);
#endif
} // namespace anim
using animAnimNode_TriggerBranch = anim::AnimNode_TriggerBranch;
} // namespace RED4ext

// clang-format on
