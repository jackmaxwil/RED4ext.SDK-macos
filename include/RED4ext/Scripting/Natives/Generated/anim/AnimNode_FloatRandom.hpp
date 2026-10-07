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
struct AnimNode_FloatRandom : anim::AnimNode_FloatValue
{
    static constexpr const char* NAME = "animAnimNode_FloatRandom";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    float cooldown; // 44
    float min; // 48
    float max; // 4C
    bool rand; // 50
    uint8_t unk51[0x78 - 0x51]; // 51
#else
    float cooldown; // 48
    float min; // 4C
    float max; // 50
    bool rand; // 54
    uint8_t unk55[0x78 - 0x55]; // 55
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_FloatRandom, 0x78);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatRandom, cooldown, 0x44);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatRandom, min, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatRandom, max, 0x4C);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatRandom, rand, 0x50);
#else
RED4EXT_ASSERT_SIZE(AnimNode_FloatRandom, 0x78);
#endif
} // namespace anim
using animAnimNode_FloatRandom = anim::AnimNode_FloatRandom;
} // namespace RED4ext

// clang-format on
