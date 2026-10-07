#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_FloatValue.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_Timer : anim::AnimNode_FloatValue
{
    static constexpr const char* NAME = "animAnimNode_Timer";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x58 - 0x44]; // 44
#else
    uint8_t unk48[0x58 - 0x48]; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_Timer, 0x58);
#else
RED4EXT_ASSERT_SIZE(AnimNode_Timer, 0x58);
#endif
} // namespace anim
using animAnimNode_Timer = anim::AnimNode_Timer;
} // namespace RED4ext

// clang-format on
