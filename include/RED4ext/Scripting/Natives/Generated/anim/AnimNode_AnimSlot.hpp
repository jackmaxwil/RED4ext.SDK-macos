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
struct AnimNode_AnimSlot : anim::AnimNode_Base
{
    static constexpr const char* NAME = "animAnimNode_AnimSlot";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x98 - 0x44]; // 44
    anim::PoseLink inputLink; // 98
#else
    uint8_t unk48[0xA8 - 0x48]; // 48
    anim::PoseLink inputLink; // A8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_AnimSlot, 0xB0);
RED4EXT_ASSERT_OFFSET(AnimNode_AnimSlot, inputLink, 0x98);
#else
RED4EXT_ASSERT_SIZE(AnimNode_AnimSlot, 0xC0);
#endif
} // namespace anim
using animAnimNode_AnimSlot = anim::AnimNode_AnimSlot;
} // namespace RED4ext

// clang-format on
