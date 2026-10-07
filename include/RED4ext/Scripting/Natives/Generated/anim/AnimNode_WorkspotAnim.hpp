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
struct AnimNode_WorkspotAnim : anim::AnimNode_Base
{
    static constexpr const char* NAME = "animAnimNode_WorkspotAnim";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x58 - 0x44]; // 44
    bool collectEvents; // 58
    uint8_t unk59[0x108 - 0x59]; // 59
    anim::PoseLink inputLink; // 108
#else
    uint8_t unk48[0x58 - 0x48]; // 48
    bool collectEvents; // 58
    uint8_t unk59[0x108 - 0x59]; // 59
    anim::PoseLink inputLink; // 108
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_WorkspotAnim, 0x120);
RED4EXT_ASSERT_OFFSET(AnimNode_WorkspotAnim, collectEvents, 0x58);
RED4EXT_ASSERT_OFFSET(AnimNode_WorkspotAnim, inputLink, 0x108);
#else
RED4EXT_ASSERT_SIZE(AnimNode_WorkspotAnim, 0x120);
#endif
} // namespace anim
using animAnimNode_WorkspotAnim = anim::AnimNode_WorkspotAnim;
} // namespace RED4ext

// clang-format on
