#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_TransformValue.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/TransformLink.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_TransformLatch : anim::AnimNode_TransformValue
{
    static constexpr const char* NAME = "animAnimNode_TransformLatch";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x48 - 0x44]; // 44
    anim::TransformLink input; // 48
    uint8_t unk68[0x78 - 0x68]; // 68
#else
    anim::TransformLink input; // 48
    uint8_t unk68[0x78 - 0x68]; // 68
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_TransformLatch, 0x78);
RED4EXT_ASSERT_OFFSET(AnimNode_TransformLatch, input, 0x48);
#else
RED4EXT_ASSERT_SIZE(AnimNode_TransformLatch, 0x78);
#endif
} // namespace anim
using animAnimNode_TransformLatch = anim::AnimNode_TransformLatch;
} // namespace RED4ext

// clang-format on
