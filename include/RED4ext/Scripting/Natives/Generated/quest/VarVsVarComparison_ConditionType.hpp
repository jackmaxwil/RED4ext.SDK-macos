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
struct VarVsVarComparison_ConditionType : quest::IFactsDBConditionType
{
    static constexpr const char* NAME = "questVarVsVarComparison_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    CString factName1; // 38
    CString factName2; // 58
    EComparisonType comparisonType; // 78
    uint8_t unk7C[0x80 - 0x7C]; // 7C
#else
    CString factName1; // 38
    CString factName2; // 58
    EComparisonType comparisonType; // 78
    uint8_t unk7C[0x80 - 0x7C]; // 7C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(VarVsVarComparison_ConditionType, 0x80);
RED4EXT_ASSERT_OFFSET(VarVsVarComparison_ConditionType, factName1, 0x38);
RED4EXT_ASSERT_OFFSET(VarVsVarComparison_ConditionType, factName2, 0x58);
RED4EXT_ASSERT_OFFSET(VarVsVarComparison_ConditionType, comparisonType, 0x78);
#else
RED4EXT_ASSERT_SIZE(VarVsVarComparison_ConditionType, 0x80);
#endif
} // namespace quest
using questVarVsVarComparison_ConditionType = quest::VarVsVarComparison_ConditionType;
} // namespace RED4ext

// clang-format on
