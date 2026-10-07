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
struct AnimNode_DampFloat : anim::AnimNode_FloatValue
{
    static constexpr const char* NAME = "animAnimNode_DampFloat";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    float defaultIncreaseSpeed; // 44
    float defaultDecreaseSpeed; // 48
    bool startFromDefaultValue; // 4C
    uint8_t unk4D[0x50 - 0x4D]; // 4D
    float defaultInitialValue; // 50
    bool wrapAroundRange; // 54
    uint8_t unk55[0x58 - 0x55]; // 55
    float rangeMin; // 58
    float rangeMax; // 5C
    anim::FloatLink inputNode; // 60
    anim::FloatLink increaseSpeedNode; // 80
    anim::FloatLink decreaseSpeedNode; // A0
    uint8_t unkC0[0xD0 - 0xC0]; // C0
#else
    float defaultIncreaseSpeed; // 48
    float defaultDecreaseSpeed; // 4C
    bool startFromDefaultValue; // 50
    uint8_t unk51[0x54 - 0x51]; // 51
    float defaultInitialValue; // 54
    bool wrapAroundRange; // 58
    uint8_t unk59[0x5C - 0x59]; // 59
    float rangeMin; // 5C
    float rangeMax; // 60
    uint8_t unk64[0x68 - 0x64]; // 64
    anim::FloatLink inputNode; // 68
    anim::FloatLink increaseSpeedNode; // 88
    anim::FloatLink decreaseSpeedNode; // A8
    uint8_t unkC8[0xD8 - 0xC8]; // C8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_DampFloat, 0xD0);
RED4EXT_ASSERT_OFFSET(AnimNode_DampFloat, defaultIncreaseSpeed, 0x44);
RED4EXT_ASSERT_OFFSET(AnimNode_DampFloat, defaultDecreaseSpeed, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_DampFloat, startFromDefaultValue, 0x4C);
RED4EXT_ASSERT_OFFSET(AnimNode_DampFloat, defaultInitialValue, 0x50);
RED4EXT_ASSERT_OFFSET(AnimNode_DampFloat, wrapAroundRange, 0x54);
RED4EXT_ASSERT_OFFSET(AnimNode_DampFloat, rangeMin, 0x58);
RED4EXT_ASSERT_OFFSET(AnimNode_DampFloat, rangeMax, 0x5C);
RED4EXT_ASSERT_OFFSET(AnimNode_DampFloat, inputNode, 0x60);
RED4EXT_ASSERT_OFFSET(AnimNode_DampFloat, increaseSpeedNode, 0x80);
RED4EXT_ASSERT_OFFSET(AnimNode_DampFloat, decreaseSpeedNode, 0xA0);
#else
RED4EXT_ASSERT_SIZE(AnimNode_DampFloat, 0xD8);
#endif
} // namespace anim
using animAnimNode_DampFloat = anim::AnimNode_DampFloat;
} // namespace RED4ext

// clang-format on
