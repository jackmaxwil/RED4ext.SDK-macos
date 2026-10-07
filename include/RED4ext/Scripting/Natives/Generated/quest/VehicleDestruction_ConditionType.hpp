#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/EComparisonType.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IVehicleConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct VehicleDestruction_ConditionType : quest::IVehicleConditionType
{
    static constexpr const char* NAME = "questVehicleDestruction_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    game::EntityReference vehicleRef; // 38
    float destruction; // 70
    EComparisonType comparisonType; // 74
#else
    game::EntityReference vehicleRef; // 38
    float destruction; // 70
    EComparisonType comparisonType; // 74
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(VehicleDestruction_ConditionType, 0x78);
RED4EXT_ASSERT_OFFSET(VehicleDestruction_ConditionType, vehicleRef, 0x38);
RED4EXT_ASSERT_OFFSET(VehicleDestruction_ConditionType, destruction, 0x70);
RED4EXT_ASSERT_OFFSET(VehicleDestruction_ConditionType, comparisonType, 0x74);
#else
RED4EXT_ASSERT_SIZE(VehicleDestruction_ConditionType, 0x78);
#endif
} // namespace quest
using questVehicleDestruction_ConditionType = quest::VehicleDestruction_ConditionType;
} // namespace RED4ext

// clang-format on
