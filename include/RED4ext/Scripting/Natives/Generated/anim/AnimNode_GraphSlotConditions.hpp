#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_GraphSlot.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/GraphSlotCondition.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_GraphSlotConditions : anim::AnimNode_GraphSlot
{
    static constexpr const char* NAME = "animAnimNode_GraphSlotConditions";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    DynArray<anim::GraphSlotCondition> conditions; // B0
    uint8_t unkC0[0xF0 - 0xC0]; // C0
#else
    DynArray<anim::GraphSlotCondition> conditions; // B0
    uint8_t unkC0[0x100 - 0xC0]; // C0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_GraphSlotConditions, 0xF0);
RED4EXT_ASSERT_OFFSET(AnimNode_GraphSlotConditions, conditions, 0xB0);
#else
RED4EXT_ASSERT_SIZE(AnimNode_GraphSlotConditions, 0x100);
#endif
} // namespace anim
using animAnimNode_GraphSlotConditions = anim::AnimNode_GraphSlotConditions;
} // namespace RED4ext

// clang-format on
