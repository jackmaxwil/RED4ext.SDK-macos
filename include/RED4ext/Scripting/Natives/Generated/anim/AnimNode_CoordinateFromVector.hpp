#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_FloatValue.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/VectorCoordinateType.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/VectorLink.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_CoordinateFromVector : anim::AnimNode_FloatValue
{
    static constexpr const char* NAME = "animAnimNode_CoordinateFromVector";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    anim::VectorCoordinateType vectorCoodrinateType; // 44
    anim::VectorLink input; // 48
#else
    anim::VectorCoordinateType vectorCoodrinateType; // 48
    uint8_t unk4C[0x50 - 0x4C]; // 4C
    anim::VectorLink input; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_CoordinateFromVector, 0x68);
RED4EXT_ASSERT_OFFSET(AnimNode_CoordinateFromVector, vectorCoodrinateType, 0x44);
RED4EXT_ASSERT_OFFSET(AnimNode_CoordinateFromVector, input, 0x48);
#else
RED4EXT_ASSERT_SIZE(AnimNode_CoordinateFromVector, 0x70);
#endif
} // namespace anim
using animAnimNode_CoordinateFromVector = anim::AnimNode_CoordinateFromVector;
} // namespace RED4ext

// clang-format on
