#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimMultiBoolToFloatEntry.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_FloatValue.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_MultiBoolToFloatValue : anim::AnimNode_FloatValue
{
    static constexpr const char* NAME = "animAnimNode_MultiBoolToFloatValue";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool allMustBeTrue; // 44
    uint8_t unk45[0x48 - 0x45]; // 45
    float onTrue; // 48
    float onFalse; // 4C
    DynArray<anim::AnimMultiBoolToFloatEntry> inputsData; // 50
    uint8_t unk60[0x70 - 0x60]; // 60
#else
    bool allMustBeTrue; // 48
    uint8_t unk49[0x4C - 0x49]; // 49
    float onTrue; // 4C
    float onFalse; // 50
    uint8_t unk54[0x58 - 0x54]; // 54
    DynArray<anim::AnimMultiBoolToFloatEntry> inputsData; // 58
    uint8_t unk68[0x78 - 0x68]; // 68
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_MultiBoolToFloatValue, 0x70);
RED4EXT_ASSERT_OFFSET(AnimNode_MultiBoolToFloatValue, allMustBeTrue, 0x44);
RED4EXT_ASSERT_OFFSET(AnimNode_MultiBoolToFloatValue, onTrue, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_MultiBoolToFloatValue, onFalse, 0x4C);
RED4EXT_ASSERT_OFFSET(AnimNode_MultiBoolToFloatValue, inputsData, 0x50);
#else
RED4EXT_ASSERT_SIZE(AnimNode_MultiBoolToFloatValue, 0x78);
#endif
} // namespace anim
using animAnimNode_MultiBoolToFloatValue = anim::AnimNode_MultiBoolToFloatValue;
} // namespace RED4ext

// clang-format on
