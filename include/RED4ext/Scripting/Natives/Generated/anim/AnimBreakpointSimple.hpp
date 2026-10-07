#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/IAnimBreakpoint.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimBreakpointSimple : anim::IAnimBreakpoint
{
    static constexpr const char* NAME = "animAnimBreakpointSimple";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint32_t hitCount; // 0C
    uint8_t unk10[0x20 - 0x10]; // 10
#else
    uint32_t hitCount; // 10
    uint8_t unk14[0x28 - 0x14]; // 14
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimBreakpointSimple, 0x20);
RED4EXT_ASSERT_OFFSET(AnimBreakpointSimple, hitCount, 0xC);
#else
RED4EXT_ASSERT_SIZE(AnimBreakpointSimple, 0x28);
#endif
} // namespace anim
using animAnimBreakpointSimple = anim::AnimBreakpointSimple;
} // namespace RED4ext

// clang-format on
