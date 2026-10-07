#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_Base.hpp>

namespace RED4ext
{
namespace anim { struct AnimNode_Base; }

namespace anim
{
struct AnimNode_Container : anim::AnimNode_Base
{
    static constexpr const char* NAME = "animAnimNode_Container";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x48 - 0x44]; // 44
    DynArray<Handle<anim::AnimNode_Base>> nodes; // 48
#else
    DynArray<Handle<anim::AnimNode_Base>> nodes; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_Container, 0x58);
RED4EXT_ASSERT_OFFSET(AnimNode_Container, nodes, 0x48);
#else
RED4EXT_ASSERT_SIZE(AnimNode_Container, 0x58);
#endif
} // namespace anim
using animAnimNode_Container = anim::AnimNode_Container;
} // namespace RED4ext

// clang-format on
