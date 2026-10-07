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
struct AnimNode_FloatConstant : anim::AnimNode_FloatValue
{
    static constexpr const char* NAME = "animAnimNode_FloatConstant";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    float value; // 44
#else
    float value; // 48
    uint8_t unk4C[0x50 - 0x4C]; // 4C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_FloatConstant, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatConstant, value, 0x44);
#else
RED4EXT_ASSERT_SIZE(AnimNode_FloatConstant, 0x50);
#endif
} // namespace anim
using animAnimNode_FloatConstant = anim::AnimNode_FloatConstant;
} // namespace RED4ext

// clang-format on
