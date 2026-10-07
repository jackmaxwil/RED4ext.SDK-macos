#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_Base.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/PoseLink.hpp>

namespace RED4ext
{
namespace anim { struct ISyncMethod; }

namespace anim
{
struct AnimNode_BaseSwitch : anim::AnimNode_Base
{
    static constexpr const char* NAME = "animAnimNode_BaseSwitch";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    float blendTime; // 44
    bool timeWarpingEnabled; // 48
    uint8_t unk49[0x50 - 0x49]; // 49
    Handle<anim::ISyncMethod> syncMethod; // 50
    bool canRequestInertialization; // 60
    uint8_t unk61[0xB8 - 0x61]; // 61
    DynArray<anim::PoseLink> inputNodes; // B8
#else
    float blendTime; // 48
    bool timeWarpingEnabled; // 4C
    uint8_t unk4D[0x50 - 0x4D]; // 4D
    Handle<anim::ISyncMethod> syncMethod; // 50
    bool canRequestInertialization; // 60
    uint8_t unk61[0xB8 - 0x61]; // 61
    DynArray<anim::PoseLink> inputNodes; // B8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_BaseSwitch, 0xC8);
RED4EXT_ASSERT_OFFSET(AnimNode_BaseSwitch, blendTime, 0x44);
RED4EXT_ASSERT_OFFSET(AnimNode_BaseSwitch, timeWarpingEnabled, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_BaseSwitch, syncMethod, 0x50);
RED4EXT_ASSERT_OFFSET(AnimNode_BaseSwitch, canRequestInertialization, 0x60);
RED4EXT_ASSERT_OFFSET(AnimNode_BaseSwitch, inputNodes, 0xB8);
#else
RED4EXT_ASSERT_SIZE(AnimNode_BaseSwitch, 0xC8);
#endif
} // namespace anim
using animAnimNode_BaseSwitch = anim::AnimNode_BaseSwitch;
} // namespace RED4ext

// clang-format on
