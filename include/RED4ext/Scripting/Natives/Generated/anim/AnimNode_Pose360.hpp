#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_Base.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/FloatLink.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_Pose360 : anim::AnimNode_Base
{
    static constexpr const char* NAME = "animAnimNode_Pose360";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x48 - 0x44]; // 44
    anim::FloatLink angle; // 48
    CName animation; // 68
    uint8_t unk70[0x98 - 0x70]; // 70
#else
    anim::FloatLink angle; // 48
    CName animation; // 68
    uint8_t unk70[0x98 - 0x70]; // 70
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_Pose360, 0x98);
RED4EXT_ASSERT_OFFSET(AnimNode_Pose360, angle, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_Pose360, animation, 0x68);
#else
RED4EXT_ASSERT_SIZE(AnimNode_Pose360, 0x98);
#endif
} // namespace anim
using animAnimNode_Pose360 = anim::AnimNode_Pose360;
} // namespace RED4ext

// clang-format on
