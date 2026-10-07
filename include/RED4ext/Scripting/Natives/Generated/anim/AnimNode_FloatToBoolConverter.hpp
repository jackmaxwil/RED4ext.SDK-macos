#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_BoolValue.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/FloatLink.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_FloatToBoolConverter : anim::AnimNode_BoolValue
{
    static constexpr const char* NAME = "animAnimNode_FloatToBoolConverter";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x48 - 0x44]; // 44
    anim::FloatLink inputNode; // 48
#else
    anim::FloatLink inputNode; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_FloatToBoolConverter, 0x68);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatToBoolConverter, inputNode, 0x48);
#else
RED4EXT_ASSERT_SIZE(AnimNode_FloatToBoolConverter, 0x68);
#endif
} // namespace anim
using animAnimNode_FloatToBoolConverter = anim::AnimNode_FloatToBoolConverter;
} // namespace RED4ext

// clang-format on
