#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_Base.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/PoseLink.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_RagdollControl : anim::AnimNode_Base
{
    static constexpr const char* NAME = "animAnimNode_RagdollControl";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x58 - 0x44]; // 44
    float blendInDuration; // 58
    float blendOutDuration; // 5C
    anim::PoseLink inputPoseNode; // 60
    uint8_t unk78[0xE8 - 0x78]; // 78
#else
    uint8_t unk48[0x58 - 0x48]; // 48
    float blendInDuration; // 58
    float blendOutDuration; // 5C
    anim::PoseLink inputPoseNode; // 60
    uint8_t unk78[0xE8 - 0x78]; // 78
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_RagdollControl, 0xE8);
RED4EXT_ASSERT_OFFSET(AnimNode_RagdollControl, blendInDuration, 0x58);
RED4EXT_ASSERT_OFFSET(AnimNode_RagdollControl, blendOutDuration, 0x5C);
RED4EXT_ASSERT_OFFSET(AnimNode_RagdollControl, inputPoseNode, 0x60);
#else
RED4EXT_ASSERT_SIZE(AnimNode_RagdollControl, 0xE8);
#endif
} // namespace anim
using animAnimNode_RagdollControl = anim::AnimNode_RagdollControl;
} // namespace RED4ext

// clang-format on
