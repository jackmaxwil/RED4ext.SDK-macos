#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_Base.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/FloatLink.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/IntLink.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/PoseLink.hpp>

namespace RED4ext
{
namespace anim { struct ISyncMethod; }

namespace anim
{
struct AnimNode_BlendByMaskDynamic : anim::AnimNode_Base
{
    static constexpr const char* NAME = "animAnimNode_BlendByMaskDynamic";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x48 - 0x44]; // 44
    anim::PoseLink base; // 48
    anim::PoseLink blend; // 60
    anim::IntLink mask; // 78
    anim::FloatLink weight; // 98
    Handle<anim::ISyncMethod> syncMethod; // B8
    DynArray<CName> masks; // C8
    uint8_t unkD8[0x108 - 0xD8]; // D8
#else
    anim::PoseLink base; // 48
    anim::PoseLink blend; // 60
    anim::IntLink mask; // 78
    anim::FloatLink weight; // 98
    Handle<anim::ISyncMethod> syncMethod; // B8
    DynArray<CName> masks; // C8
    uint8_t unkD8[0x108 - 0xD8]; // D8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_BlendByMaskDynamic, 0x108);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendByMaskDynamic, base, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendByMaskDynamic, blend, 0x60);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendByMaskDynamic, mask, 0x78);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendByMaskDynamic, weight, 0x98);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendByMaskDynamic, syncMethod, 0xB8);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendByMaskDynamic, masks, 0xC8);
#else
RED4EXT_ASSERT_SIZE(AnimNode_BlendByMaskDynamic, 0x108);
#endif
} // namespace anim
using animAnimNode_BlendByMaskDynamic = anim::AnimNode_BlendByMaskDynamic;
} // namespace RED4ext

// clang-format on
