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
struct AnimNode_StageFloatEntry : anim::AnimNode_FloatValue
{
    static constexpr const char* NAME = "animAnimNode_StageFloatEntry";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x68 - 0x44]; // 44
#else
    uint8_t unk48[0x68 - 0x48]; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_StageFloatEntry, 0x68);
#else
RED4EXT_ASSERT_SIZE(AnimNode_StageFloatEntry, 0x68);
#endif
} // namespace anim
using animAnimNode_StageFloatEntry = anim::AnimNode_StageFloatEntry;
} // namespace RED4ext

// clang-format on
