#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_Base.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_BlendSpace_InternalsBlendSpace.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/FloatLink.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_BlendSpace : anim::AnimNode_Base
{
    static constexpr const char* NAME = "animAnimNode_BlendSpace";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x48 - 0x44]; // 44
    anim::AnimNode_BlendSpace_InternalsBlendSpace blendSpace; // 48
    DynArray<anim::FloatLink> inputLinks; // 1B8
    anim::FloatLink progressLink; // 1C8
    bool fireAnimEndEvent; // 1E8
    uint8_t unk1E9[0x1F0 - 0x1E9]; // 1E9
    CName animEndEventName; // 1F0
    bool isLooped; // 1F8
    uint8_t unk1F9[0x200 - 0x1F9]; // 1F9
#else
    anim::AnimNode_BlendSpace_InternalsBlendSpace blendSpace; // 48
    DynArray<anim::FloatLink> inputLinks; // 210
    anim::FloatLink progressLink; // 220
    bool fireAnimEndEvent; // 240
    uint8_t unk241[0x248 - 0x241]; // 241
    CName animEndEventName; // 248
    bool isLooped; // 250
    uint8_t unk251[0x258 - 0x251]; // 251
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_BlendSpace, 0x200);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendSpace, blendSpace, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendSpace, inputLinks, 0x1B8);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendSpace, progressLink, 0x1C8);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendSpace, fireAnimEndEvent, 0x1E8);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendSpace, animEndEventName, 0x1F0);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendSpace, isLooped, 0x1F8);
#else
RED4EXT_ASSERT_SIZE(AnimNode_BlendSpace, 0x258);
#endif
} // namespace anim
using animAnimNode_BlendSpace = anim::AnimNode_BlendSpace;
} // namespace RED4ext

// clang-format on
