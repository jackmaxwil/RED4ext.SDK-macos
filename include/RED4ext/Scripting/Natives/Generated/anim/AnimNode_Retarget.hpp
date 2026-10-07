#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_OnePoseInput.hpp>

namespace RED4ext
{
namespace anim { struct IAnimNode_PostProcess; }
namespace anim { struct Rig; }

namespace anim
{
struct AnimNode_Retarget : anim::AnimNode_OnePoseInput
{
    static constexpr const char* NAME = "animAnimNode_Retarget";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk60[0x70 - 0x60]; // 60
    Ref<anim::Rig> refRig; // 70
    Handle<anim::IAnimNode_PostProcess> postProcess; // 88
#else
    uint8_t unk60[0x78 - 0x60]; // 60
    Ref<anim::Rig> refRig; // 78
    Handle<anim::IAnimNode_PostProcess> postProcess; // 90
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_Retarget, 0x98);
RED4EXT_ASSERT_OFFSET(AnimNode_Retarget, refRig, 0x70);
RED4EXT_ASSERT_OFFSET(AnimNode_Retarget, postProcess, 0x88);
#else
RED4EXT_ASSERT_SIZE(AnimNode_Retarget, 0xA0);
#endif
} // namespace anim
using animAnimNode_Retarget = anim::AnimNode_Retarget;
} // namespace RED4ext

// clang-format on
