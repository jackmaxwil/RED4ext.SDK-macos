#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/EComparisonType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IFactsDBConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct VarComparison_ConditionType : quest::IFactsDBConditionType
{
    static constexpr const char* NAME = "questVarComparison_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    CString factName; // 38
    int32_t value; // 58
    EComparisonType comparisonType; // 5C
#else
    CString factName; // 38
    int32_t value; // 58
    EComparisonType comparisonType; // 5C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(VarComparison_ConditionType, 0x60);
RED4EXT_ASSERT_OFFSET(VarComparison_ConditionType, factName, 0x38);
RED4EXT_ASSERT_OFFSET(VarComparison_ConditionType, value, 0x58);
RED4EXT_ASSERT_OFFSET(VarComparison_ConditionType, comparisonType, 0x5C);
#else
RED4EXT_ASSERT_SIZE(VarComparison_ConditionType, 0x60);
#endif
} // namespace quest
using questVarComparison_ConditionType = quest::VarComparison_ConditionType;
} // namespace RED4ext

// clang-format on
