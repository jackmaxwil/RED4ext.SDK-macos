#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_BoolValue.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_BoolConstant : anim::AnimNode_BoolValue
{
    static constexpr const char* NAME = "animAnimNode_BoolConstant";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool value; // 44
    uint8_t unk45[0x48 - 0x45]; // 45
#else
    bool value; // 48
    uint8_t unk49[0x50 - 0x49]; // 49
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_BoolConstant, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_BoolConstant, value, 0x44);
#else
RED4EXT_ASSERT_SIZE(AnimNode_BoolConstant, 0x50);
#endif
} // namespace anim
using animAnimNode_BoolConstant = anim::AnimNode_BoolConstant;
} // namespace RED4ext

// clang-format on
