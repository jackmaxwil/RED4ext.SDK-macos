#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_FloatValue.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/FloatLink.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_SpringDamp : anim::AnimNode_FloatValue
{
    static constexpr const char* NAME = "animAnimNode_SpringDamp";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    float massFactor; // 44
    float springFactor; // 48
    float dampFactor; // 4C
    bool startFromDefaultValue; // 50
    uint8_t unk51[0x54 - 0x51]; // 51
    float defaultInitialValue; // 54
    bool wrapAroundRange; // 58
    uint8_t unk59[0x5C - 0x59]; // 59
    float rangeMin; // 5C
    float rangeMax; // 60
    float timeStep; // 64
    anim::FloatLink inputNode; // 68
    uint8_t unk88[0xA8 - 0x88]; // 88
#else
    float massFactor; // 48
    float springFactor; // 4C
    float dampFactor; // 50
    bool startFromDefaultValue; // 54
    uint8_t unk55[0x58 - 0x55]; // 55
    float defaultInitialValue; // 58
    bool wrapAroundRange; // 5C
    uint8_t unk5D[0x60 - 0x5D]; // 5D
    float rangeMin; // 60
    float rangeMax; // 64
    float timeStep; // 68
    uint8_t unk6C[0x70 - 0x6C]; // 6C
    anim::FloatLink inputNode; // 70
    uint8_t unk90[0xB0 - 0x90]; // 90
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_SpringDamp, 0xA8);
RED4EXT_ASSERT_OFFSET(AnimNode_SpringDamp, massFactor, 0x44);
RED4EXT_ASSERT_OFFSET(AnimNode_SpringDamp, springFactor, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_SpringDamp, dampFactor, 0x4C);
RED4EXT_ASSERT_OFFSET(AnimNode_SpringDamp, startFromDefaultValue, 0x50);
RED4EXT_ASSERT_OFFSET(AnimNode_SpringDamp, defaultInitialValue, 0x54);
RED4EXT_ASSERT_OFFSET(AnimNode_SpringDamp, wrapAroundRange, 0x58);
RED4EXT_ASSERT_OFFSET(AnimNode_SpringDamp, rangeMin, 0x5C);
RED4EXT_ASSERT_OFFSET(AnimNode_SpringDamp, rangeMax, 0x60);
RED4EXT_ASSERT_OFFSET(AnimNode_SpringDamp, timeStep, 0x64);
RED4EXT_ASSERT_OFFSET(AnimNode_SpringDamp, inputNode, 0x68);
#else
RED4EXT_ASSERT_SIZE(AnimNode_SpringDamp, 0xB0);
#endif
} // namespace anim
using animAnimNode_SpringDamp = anim::AnimNode_SpringDamp;
} // namespace RED4ext

// clang-format on
