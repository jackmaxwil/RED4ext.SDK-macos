#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/EComparisonType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IDistanceConditionType.hpp>

namespace RED4ext
{
namespace quest { struct ObjectDistance; }

namespace quest
{
struct DistanceVsDistanceComparison_ConditionType : quest::IDistanceConditionType
{
    static constexpr const char* NAME = "questDistanceVsDistanceComparison_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    Handle<quest::ObjectDistance> distanceDefinition1; // 38
    Handle<quest::ObjectDistance> distanceDefinition2; // 48
    EComparisonType comparisonType; // 58
    uint8_t unk5C[0x60 - 0x5C]; // 5C
#else
    Handle<quest::ObjectDistance> distanceDefinition1; // 38
    Handle<quest::ObjectDistance> distanceDefinition2; // 48
    EComparisonType comparisonType; // 58
    uint8_t unk5C[0x60 - 0x5C]; // 5C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(DistanceVsDistanceComparison_ConditionType, 0x60);
RED4EXT_ASSERT_OFFSET(DistanceVsDistanceComparison_ConditionType, distanceDefinition1, 0x38);
RED4EXT_ASSERT_OFFSET(DistanceVsDistanceComparison_ConditionType, distanceDefinition2, 0x48);
RED4EXT_ASSERT_OFFSET(DistanceVsDistanceComparison_ConditionType, comparisonType, 0x58);
#else
RED4EXT_ASSERT_SIZE(DistanceVsDistanceComparison_ConditionType, 0x60);
#endif
} // namespace quest
using questDistanceVsDistanceComparison_ConditionType = quest::DistanceVsDistanceComparison_ConditionType;
} // namespace RED4ext

// clang-format on
