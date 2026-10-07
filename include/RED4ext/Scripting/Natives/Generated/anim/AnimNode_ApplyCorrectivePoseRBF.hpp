#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_OnePoseInput.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/CorrectivePoseEntry.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_ApplyCorrectivePoseRBF : anim::AnimNode_OnePoseInput
{
    static constexpr const char* NAME = "animAnimNode_ApplyCorrectivePoseRBF";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    DynArray<anim::CorrectivePoseEntry> correctives; // 60
    float rbfCoefficient; // 70
    float rbfPowValue; // 74
    float correctiveFrame; // 78
    uint8_t unk7C[0xD0 - 0x7C]; // 7C
#else
    DynArray<anim::CorrectivePoseEntry> correctives; // 60
    float rbfCoefficient; // 70
    float rbfPowValue; // 74
    float correctiveFrame; // 78
    uint8_t unk7C[0xF0 - 0x7C]; // 7C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_ApplyCorrectivePoseRBF, 0xD0);
RED4EXT_ASSERT_OFFSET(AnimNode_ApplyCorrectivePoseRBF, correctives, 0x60);
RED4EXT_ASSERT_OFFSET(AnimNode_ApplyCorrectivePoseRBF, rbfCoefficient, 0x70);
RED4EXT_ASSERT_OFFSET(AnimNode_ApplyCorrectivePoseRBF, rbfPowValue, 0x74);
RED4EXT_ASSERT_OFFSET(AnimNode_ApplyCorrectivePoseRBF, correctiveFrame, 0x78);
#else
RED4EXT_ASSERT_SIZE(AnimNode_ApplyCorrectivePoseRBF, 0xF0);
#endif
} // namespace anim
using animAnimNode_ApplyCorrectivePoseRBF = anim::AnimNode_ApplyCorrectivePoseRBF;
} // namespace RED4ext

// clang-format on
