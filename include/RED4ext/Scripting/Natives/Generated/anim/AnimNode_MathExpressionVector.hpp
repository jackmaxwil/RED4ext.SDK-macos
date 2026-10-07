#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_VectorValue.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/MathExpressionNodeData.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_MathExpressionVector : anim::AnimNode_VectorValue
{
    static constexpr const char* NAME = "animAnimNode_MathExpressionVector";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x48 - 0x44]; // 44
    anim::MathExpressionNodeData expressionData; // 48
#else
    anim::MathExpressionNodeData expressionData; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_MathExpressionVector, 0x88);
RED4EXT_ASSERT_OFFSET(AnimNode_MathExpressionVector, expressionData, 0x48);
#else
RED4EXT_ASSERT_SIZE(AnimNode_MathExpressionVector, 0x88);
#endif
} // namespace anim
using animAnimNode_MathExpressionVector = anim::AnimNode_MathExpressionVector;
} // namespace RED4ext

// clang-format on
