#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_MotionTableSwitch.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/FloatLink.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/PoseLink.hpp>

namespace RED4ext
{
namespace anim { struct IMotionTableProvider; }
namespace anim { struct ISyncMethod; }

namespace anim
{
struct AnimNode_Switch : anim::AnimNode_MotionTableSwitch
{
    static constexpr const char* NAME = "animAnimNode_Switch";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint32_t numInputs; // 44
    float blendTime; // 48
    uint8_t unk4C[0x50 - 0x4C]; // 4C
    Handle<anim::ISyncMethod> syncMethod; // 50
    Handle<anim::IMotionTableProvider> motionProvider; // 60
    CName pushDataByTag; // 70
    bool timeWarpingEnabled; // 78
    bool canRequestInertialization; // 79
    uint8_t unk7A[0xA0 - 0x7A]; // 7A
    anim::FloatLink weightNode; // A0
    DynArray<anim::PoseLink> inputNodes; // C0
#else
    uint32_t numInputs; // 48
    float blendTime; // 4C
    Handle<anim::ISyncMethod> syncMethod; // 50
    Handle<anim::IMotionTableProvider> motionProvider; // 60
    CName pushDataByTag; // 70
    bool timeWarpingEnabled; // 78
    bool canRequestInertialization; // 79
    uint8_t unk7A[0xA0 - 0x7A]; // 7A
    anim::FloatLink weightNode; // A0
    DynArray<anim::PoseLink> inputNodes; // C0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_Switch, 0xD0);
RED4EXT_ASSERT_OFFSET(AnimNode_Switch, numInputs, 0x44);
RED4EXT_ASSERT_OFFSET(AnimNode_Switch, blendTime, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_Switch, syncMethod, 0x50);
RED4EXT_ASSERT_OFFSET(AnimNode_Switch, motionProvider, 0x60);
RED4EXT_ASSERT_OFFSET(AnimNode_Switch, pushDataByTag, 0x70);
RED4EXT_ASSERT_OFFSET(AnimNode_Switch, timeWarpingEnabled, 0x78);
RED4EXT_ASSERT_OFFSET(AnimNode_Switch, canRequestInertialization, 0x79);
RED4EXT_ASSERT_OFFSET(AnimNode_Switch, weightNode, 0xA0);
RED4EXT_ASSERT_OFFSET(AnimNode_Switch, inputNodes, 0xC0);
#else
RED4EXT_ASSERT_SIZE(AnimNode_Switch, 0xD0);
#endif
} // namespace anim
using animAnimNode_Switch = anim::AnimNode_Switch;
} // namespace RED4ext

// clang-format on
