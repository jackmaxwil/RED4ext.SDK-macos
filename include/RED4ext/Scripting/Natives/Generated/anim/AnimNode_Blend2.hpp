#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_Base.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/FloatLink.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/PoseLink.hpp>

namespace RED4ext
{
namespace anim { struct ISyncMethod; }

namespace anim
{
struct AnimNode_Blend2 : anim::AnimNode_Base
{
    static constexpr const char* NAME = "animAnimNode_Blend2";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    float minInputValue; // 44
    float maxInputValue; // 48
    bool timeWarpingEnabled; // 4C
    uint8_t unk4D[0x50 - 0x4D]; // 4D
    Handle<anim::ISyncMethod> syncMethod; // 50
    uint8_t unk60[0x80 - 0x60]; // 60
    anim::PoseLink firstInputNode; // 80
    anim::PoseLink secondInputNode; // 98
    anim::FloatLink weightNode; // B0
#else
    float minInputValue; // 48
    float maxInputValue; // 4C
    bool timeWarpingEnabled; // 50
    uint8_t unk51[0x58 - 0x51]; // 51
    Handle<anim::ISyncMethod> syncMethod; // 58
    uint8_t unk68[0x88 - 0x68]; // 68
    anim::PoseLink firstInputNode; // 88
    anim::PoseLink secondInputNode; // A0
    anim::FloatLink weightNode; // B8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_Blend2, 0xD0);
RED4EXT_ASSERT_OFFSET(AnimNode_Blend2, minInputValue, 0x44);
RED4EXT_ASSERT_OFFSET(AnimNode_Blend2, maxInputValue, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_Blend2, timeWarpingEnabled, 0x4C);
RED4EXT_ASSERT_OFFSET(AnimNode_Blend2, syncMethod, 0x50);
RED4EXT_ASSERT_OFFSET(AnimNode_Blend2, firstInputNode, 0x80);
RED4EXT_ASSERT_OFFSET(AnimNode_Blend2, secondInputNode, 0x98);
RED4EXT_ASSERT_OFFSET(AnimNode_Blend2, weightNode, 0xB0);
#else
RED4EXT_ASSERT_SIZE(AnimNode_Blend2, 0xD8);
#endif
} // namespace anim
using animAnimNode_Blend2 = anim::AnimNode_Blend2;
} // namespace RED4ext

// clang-format on
