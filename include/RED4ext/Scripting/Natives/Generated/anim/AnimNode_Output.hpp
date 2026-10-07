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
struct AnimNode_Output : anim::AnimNode_Base
{
    static constexpr const char* NAME = "animAnimNode_Output";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x48 - 0x44]; // 44
    anim::PoseLink node; // 48
#else
    anim::PoseLink node; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_Output, 0x60);
RED4EXT_ASSERT_OFFSET(AnimNode_Output, node, 0x48);
#else
RED4EXT_ASSERT_SIZE(AnimNode_Output, 0x60);
#endif
} // namespace anim
using animAnimNode_Output = anim::AnimNode_Output;
} // namespace RED4ext

// clang-format on
