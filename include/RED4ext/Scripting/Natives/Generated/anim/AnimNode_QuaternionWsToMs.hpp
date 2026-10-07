#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_QuaternionValue.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/QuaternionLink.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_QuaternionWsToMs : anim::AnimNode_QuaternionValue
{
    static constexpr const char* NAME = "animAnimNode_QuaternionWsToMs";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x48 - 0x44]; // 44
    anim::QuaternionLink quaternionWs; // 48
#else
    anim::QuaternionLink quaternionWs; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_QuaternionWsToMs, 0x68);
RED4EXT_ASSERT_OFFSET(AnimNode_QuaternionWsToMs, quaternionWs, 0x48);
#else
RED4EXT_ASSERT_SIZE(AnimNode_QuaternionWsToMs, 0x68);
#endif
} // namespace anim
using animAnimNode_QuaternionWsToMs = anim::AnimNode_QuaternionWsToMs;
} // namespace RED4ext

// clang-format on
