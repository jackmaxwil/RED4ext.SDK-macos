#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/EComparisonType.hpp>
#include <RED4ext/Scripting/Natives/Generated/LibTreeDefTreeVariableBoolBase.hpp>

namespace RED4ext
{
namespace AI
{
struct DefTreeVariableComparison : LibTreeDefTreeVariableBoolBase
{
    static constexpr const char* NAME = "AIDefTreeVariableComparison";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint16_t referenceVariableId; // 42
    uint8_t unk44[0x48 - 0x44]; // 44
    CName referenceVariableName; // 48
    CName referenceVariableShortName; // 50
    CName referenceType; // 58
    Variant referenceValue; // 60
    EComparisonType operator; // 78
    uint8_t unk7C[0x80 - 0x7C]; // 7C
#else
    uint16_t referenceVariableId; // 48
    uint8_t unk4A[0x50 - 0x4A]; // 4A
    CName referenceVariableName; // 50
    CName referenceVariableShortName; // 58
    CName referenceType; // 60
    Variant referenceValue; // 68
    EComparisonType operator; // 80
    uint8_t unk84[0x88 - 0x84]; // 84
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(DefTreeVariableComparison, 0x80);
RED4EXT_ASSERT_OFFSET(DefTreeVariableComparison, referenceVariableId, 0x42);
RED4EXT_ASSERT_OFFSET(DefTreeVariableComparison, referenceVariableName, 0x48);
RED4EXT_ASSERT_OFFSET(DefTreeVariableComparison, referenceVariableShortName, 0x50);
RED4EXT_ASSERT_OFFSET(DefTreeVariableComparison, referenceType, 0x58);
RED4EXT_ASSERT_OFFSET(DefTreeVariableComparison, referenceValue, 0x60);
#else
RED4EXT_ASSERT_SIZE(DefTreeVariableComparison, 0x88);
#endif
} // namespace AI
using AIDefTreeVariableComparison = AI::DefTreeVariableComparison;
} // namespace RED4ext

// clang-format on
