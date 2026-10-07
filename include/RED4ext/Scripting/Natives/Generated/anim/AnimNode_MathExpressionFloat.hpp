#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_FloatValue.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/MathExpressionNodeData.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_MathExpressionFloat : anim::AnimNode_FloatValue
{
    static constexpr const char* NAME = "animAnimNode_MathExpressionFloat";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x48 - 0x44]; // 44
    anim::MathExpressionNodeData expressionData; // 48
#else
    anim::MathExpressionNodeData expressionData; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_MathExpressionFloat, 0x88);
RED4EXT_ASSERT_OFFSET(AnimNode_MathExpressionFloat, expressionData, 0x48);
#else
RED4EXT_ASSERT_SIZE(AnimNode_MathExpressionFloat, 0x88);
#endif
} // namespace anim
using animAnimNode_MathExpressionFloat = anim::AnimNode_MathExpressionFloat;
} // namespace RED4ext

// clang-format on
