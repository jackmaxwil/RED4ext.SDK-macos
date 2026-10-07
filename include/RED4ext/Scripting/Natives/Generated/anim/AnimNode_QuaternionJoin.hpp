#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_QuaternionValue.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/QuaternionLink.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_QuaternionJoin : anim::AnimNode_QuaternionValue
{
    static constexpr const char* NAME = "animAnimNode_QuaternionJoin";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x48 - 0x44]; // 44
    anim::QuaternionLink input; // 48
    uint8_t unk68[0x88 - 0x68]; // 68
#else
    anim::QuaternionLink input; // 48
    uint8_t unk68[0x88 - 0x68]; // 68
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_QuaternionJoin, 0x88);
RED4EXT_ASSERT_OFFSET(AnimNode_QuaternionJoin, input, 0x48);
#else
RED4EXT_ASSERT_SIZE(AnimNode_QuaternionJoin, 0x88);
#endif
} // namespace anim
using animAnimNode_QuaternionJoin = anim::AnimNode_QuaternionJoin;
} // namespace RED4ext

// clang-format on
