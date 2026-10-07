#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_IntValue.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/IntLink.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_IntLatch : anim::AnimNode_IntValue
{
    static constexpr const char* NAME = "animAnimNode_IntLatch";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x48 - 0x44]; // 44
    anim::IntLink input; // 48
    uint8_t unk68[0x78 - 0x68]; // 68
#else
    anim::IntLink input; // 48
    uint8_t unk68[0x78 - 0x68]; // 68
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_IntLatch, 0x78);
RED4EXT_ASSERT_OFFSET(AnimNode_IntLatch, input, 0x48);
#else
RED4EXT_ASSERT_SIZE(AnimNode_IntLatch, 0x78);
#endif
} // namespace anim
using animAnimNode_IntLatch = anim::AnimNode_IntLatch;
} // namespace RED4ext

// clang-format on
