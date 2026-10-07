#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_Base.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/FloatLink.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/PoseLink.hpp>

namespace RED4ext
{
namespace anim { struct IMotionTableProvider; }
namespace anim { struct ISyncMethod; }

namespace anim
{
struct AnimNode_BlendMultiple : anim::AnimNode_Base
{
    static constexpr const char* NAME = "animAnimNode_BlendMultiple";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x48 - 0x44]; // 44
    DynArray<float> inputValues; // 48
    DynArray<float> sortedInputValues; // 58
    float minWeight; // 68
    float maxWeight; // 6C
    bool radialBlending; // 70
    bool timeWarpingEnabled; // 71
    uint8_t unk72[0x78 - 0x72]; // 72
    Handle<anim::ISyncMethod> syncMethod; // 78
    Handle<anim::IMotionTableProvider> motionProvider; // 88
    uint8_t unk98[0xE8 - 0x98]; // 98
    anim::FloatLink weightNode; // E8
    DynArray<anim::PoseLink> inputNodes; // 108
#else
    DynArray<float> inputValues; // 48
    DynArray<float> sortedInputValues; // 58
    float minWeight; // 68
    float maxWeight; // 6C
    bool radialBlending; // 70
    bool timeWarpingEnabled; // 71
    uint8_t unk72[0x78 - 0x72]; // 72
    Handle<anim::ISyncMethod> syncMethod; // 78
    Handle<anim::IMotionTableProvider> motionProvider; // 88
    uint8_t unk98[0xE8 - 0x98]; // 98
    anim::FloatLink weightNode; // E8
    DynArray<anim::PoseLink> inputNodes; // 108
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_BlendMultiple, 0x118);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendMultiple, inputValues, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendMultiple, sortedInputValues, 0x58);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendMultiple, minWeight, 0x68);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendMultiple, maxWeight, 0x6C);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendMultiple, radialBlending, 0x70);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendMultiple, timeWarpingEnabled, 0x71);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendMultiple, syncMethod, 0x78);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendMultiple, motionProvider, 0x88);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendMultiple, weightNode, 0xE8);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendMultiple, inputNodes, 0x108);
#else
RED4EXT_ASSERT_SIZE(AnimNode_BlendMultiple, 0x118);
#endif
} // namespace anim
using animAnimNode_BlendMultiple = anim::AnimNode_BlendMultiple;
} // namespace RED4ext

// clang-format on
