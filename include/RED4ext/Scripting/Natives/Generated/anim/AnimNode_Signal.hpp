#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_FloatValue.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_Signal : anim::AnimNode_FloatValue
{
    static constexpr const char* NAME = "animAnimNode_Signal";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    float blendIn; // 44
    float blendOut; // 48
    uint8_t unk4C[0x50 - 0x4C]; // 4C
    CName startEvent; // 50
    CName endEvent; // 58
    bool defaultState; // 60
    uint8_t unk61[0x64 - 0x61]; // 61
    float cooldown; // 64
    uint8_t unk68[0x98 - 0x68]; // 68
#else
    float blendIn; // 48
    float blendOut; // 4C
    CName startEvent; // 50
    CName endEvent; // 58
    bool defaultState; // 60
    uint8_t unk61[0x64 - 0x61]; // 61
    float cooldown; // 64
    uint8_t unk68[0x98 - 0x68]; // 68
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_Signal, 0x98);
RED4EXT_ASSERT_OFFSET(AnimNode_Signal, blendIn, 0x44);
RED4EXT_ASSERT_OFFSET(AnimNode_Signal, blendOut, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_Signal, startEvent, 0x50);
RED4EXT_ASSERT_OFFSET(AnimNode_Signal, endEvent, 0x58);
RED4EXT_ASSERT_OFFSET(AnimNode_Signal, defaultState, 0x60);
RED4EXT_ASSERT_OFFSET(AnimNode_Signal, cooldown, 0x64);
#else
RED4EXT_ASSERT_SIZE(AnimNode_Signal, 0x98);
#endif
} // namespace anim
using animAnimNode_Signal = anim::AnimNode_Signal;
} // namespace RED4ext

// clang-format on
