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
struct AnimNode_TagValue : anim::AnimNode_FloatValue
{
    static constexpr const char* NAME = "animAnimNode_TagValue";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x48 - 0x44]; // 44
    CName tag; // 48
    float defaultValue; // 50
    bool oneMinus; // 54
    uint8_t unk55[0x68 - 0x55]; // 55
#else
    CName tag; // 48
    float defaultValue; // 50
    bool oneMinus; // 54
    uint8_t unk55[0x68 - 0x55]; // 55
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_TagValue, 0x68);
RED4EXT_ASSERT_OFFSET(AnimNode_TagValue, tag, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_TagValue, defaultValue, 0x50);
RED4EXT_ASSERT_OFFSET(AnimNode_TagValue, oneMinus, 0x54);
#else
RED4EXT_ASSERT_SIZE(AnimNode_TagValue, 0x68);
#endif
} // namespace anim
using animAnimNode_TagValue = anim::AnimNode_TagValue;
} // namespace RED4ext

// clang-format on
