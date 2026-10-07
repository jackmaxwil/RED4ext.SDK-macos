#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_Base.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/PoseLink.hpp>

namespace RED4ext
{
namespace anim { struct IRuntimeCondition; }

namespace anim
{
struct AnimNode_RuntimeSwitch : anim::AnimNode_Base
{
    static constexpr const char* NAME = "animAnimNode_RuntimeSwitch";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x48 - 0x44]; // 44
    Handle<anim::IRuntimeCondition> condition; // 48
    uint8_t unk58[0x68 - 0x58]; // 58
    anim::PoseLink True; // 68
    anim::PoseLink False; // 80
#else
    Handle<anim::IRuntimeCondition> condition; // 48
    uint8_t unk58[0x68 - 0x58]; // 58
    anim::PoseLink True; // 68
    anim::PoseLink False; // 80
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_RuntimeSwitch, 0x98);
RED4EXT_ASSERT_OFFSET(AnimNode_RuntimeSwitch, condition, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_RuntimeSwitch, True, 0x68);
RED4EXT_ASSERT_OFFSET(AnimNode_RuntimeSwitch, False, 0x80);
#else
RED4EXT_ASSERT_SIZE(AnimNode_RuntimeSwitch, 0x98);
#endif
} // namespace anim
using animAnimNode_RuntimeSwitch = anim::AnimNode_RuntimeSwitch;
} // namespace RED4ext

// clang-format on
