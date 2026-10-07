#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_FloatValue.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/EAnimGraphMathOp.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/FloatLink.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_FloatMathOp : anim::AnimNode_FloatValue
{
    static constexpr const char* NAME = "animAnimNode_FloatMathOp";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    anim::EAnimGraphMathOp operationType; // 44
    anim::FloatLink firstInputNode; // 48
    anim::FloatLink secondInputNode; // 68
#else
    anim::EAnimGraphMathOp operationType; // 48
    uint8_t unk4C[0x50 - 0x4C]; // 4C
    anim::FloatLink firstInputNode; // 50
    anim::FloatLink secondInputNode; // 70
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_FloatMathOp, 0x88);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatMathOp, operationType, 0x44);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatMathOp, firstInputNode, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatMathOp, secondInputNode, 0x68);
#else
RED4EXT_ASSERT_SIZE(AnimNode_FloatMathOp, 0x90);
#endif
} // namespace anim
using animAnimNode_FloatMathOp = anim::AnimNode_FloatMathOp;
} // namespace RED4ext

// clang-format on
