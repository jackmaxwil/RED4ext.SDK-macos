#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_FloatValue.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/EAnimGraphCompareFunc.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/FloatLink.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_FloatComparator : anim::AnimNode_FloatValue
{
    static constexpr const char* NAME = "animAnimNode_FloatComparator";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    float firstValue; // 44
    float secondValue; // 48
    float trueValue; // 4C
    float falseValue; // 50
    anim::EAnimGraphCompareFunc operation; // 54
    anim::FloatLink firstInputLink; // 58
    anim::FloatLink secondInputLink; // 78
    anim::FloatLink trueInputLink; // 98
    anim::FloatLink falseInputLink; // B8
#else
    float firstValue; // 48
    float secondValue; // 4C
    float trueValue; // 50
    float falseValue; // 54
    anim::EAnimGraphCompareFunc operation; // 58
    uint8_t unk5C[0x60 - 0x5C]; // 5C
    anim::FloatLink firstInputLink; // 60
    anim::FloatLink secondInputLink; // 80
    anim::FloatLink trueInputLink; // A0
    anim::FloatLink falseInputLink; // C0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_FloatComparator, 0xD8);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatComparator, firstValue, 0x44);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatComparator, secondValue, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatComparator, trueValue, 0x4C);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatComparator, falseValue, 0x50);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatComparator, operation, 0x54);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatComparator, firstInputLink, 0x58);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatComparator, secondInputLink, 0x78);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatComparator, trueInputLink, 0x98);
RED4EXT_ASSERT_OFFSET(AnimNode_FloatComparator, falseInputLink, 0xB8);
#else
RED4EXT_ASSERT_SIZE(AnimNode_FloatComparator, 0xE0);
#endif
} // namespace anim
using animAnimNode_FloatComparator = anim::AnimNode_FloatComparator;
} // namespace RED4ext

// clang-format on
