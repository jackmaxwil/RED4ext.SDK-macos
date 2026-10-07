#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_StateMachine.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_LocomotionMachine : anim::AnimNode_StateMachine
{
    static constexpr const char* NAME = "animAnimNode_LocomotionMachine";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool usePlanner; // 140
    uint8_t unk141[0x148 - 0x141]; // 141
    CName group; // 148
    CName logic; // 150
    CName distance; // 158
    CName duration; // 160
    CName motion; // 168
    CName state; // 170
    CName requestId; // 178
    float transitionTime; // 180
    uint32_t numVariants; // 184
    uint8_t unk188[0x268 - 0x188]; // 188
#else
    bool usePlanner; // 140
    uint8_t unk141[0x148 - 0x141]; // 141
    CName group; // 148
    CName logic; // 150
    CName distance; // 158
    CName duration; // 160
    CName motion; // 168
    CName state; // 170
    CName requestId; // 178
    float transitionTime; // 180
    uint32_t numVariants; // 184
    uint8_t unk188[0x278 - 0x188]; // 188
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_LocomotionMachine, 0x268);
RED4EXT_ASSERT_OFFSET(AnimNode_LocomotionMachine, usePlanner, 0x140);
RED4EXT_ASSERT_OFFSET(AnimNode_LocomotionMachine, group, 0x148);
RED4EXT_ASSERT_OFFSET(AnimNode_LocomotionMachine, logic, 0x150);
RED4EXT_ASSERT_OFFSET(AnimNode_LocomotionMachine, distance, 0x158);
RED4EXT_ASSERT_OFFSET(AnimNode_LocomotionMachine, duration, 0x160);
RED4EXT_ASSERT_OFFSET(AnimNode_LocomotionMachine, motion, 0x168);
RED4EXT_ASSERT_OFFSET(AnimNode_LocomotionMachine, state, 0x170);
RED4EXT_ASSERT_OFFSET(AnimNode_LocomotionMachine, requestId, 0x178);
RED4EXT_ASSERT_OFFSET(AnimNode_LocomotionMachine, transitionTime, 0x180);
RED4EXT_ASSERT_OFFSET(AnimNode_LocomotionMachine, numVariants, 0x184);
#else
RED4EXT_ASSERT_SIZE(AnimNode_LocomotionMachine, 0x278);
#endif
} // namespace anim
using animAnimNode_LocomotionMachine = anim::AnimNode_LocomotionMachine;
} // namespace RED4ext

// clang-format on
