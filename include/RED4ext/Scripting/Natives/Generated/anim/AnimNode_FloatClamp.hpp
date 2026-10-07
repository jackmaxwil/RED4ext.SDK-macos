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
struct AnimNode_FloatClamp : anim::AnimNode_FloatValue
{
    static constexpr const char* NAME = "animAnimNode_FloatClamp";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    float min; // 44
    float max; // 48
    uint8_t unk4C[0x50 - 0x4C]; // 4C
    anim::FloatLink inputNode; // 50
#else
    float min; // 48
    float max; // 4C
    anim::FloatLink inputNode; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_FloatClamp, 0x70);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatClamp, min, 0x44);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatClamp, max, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatClamp, inputNode, 0x50);
#else
RED4EXT_ASSERT_SIZE(AnimNode_FloatClamp, 0x70);
#endif
} // namespace anim
using animAnimNode_FloatClamp = anim::AnimNode_FloatClamp;
} // namespace RED4ext

// clang-format on
