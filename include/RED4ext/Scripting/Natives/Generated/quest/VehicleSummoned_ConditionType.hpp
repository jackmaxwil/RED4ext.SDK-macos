#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IVehicleConditionType.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/ESummonedVehicleType.hpp>

namespace RED4ext
{
namespace quest
{
struct VehicleSummoned_ConditionType : quest::IVehicleConditionType
{
    static constexpr const char* NAME = "questVehicleSummoned_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    vehicle::ESummonedVehicleType type; // 34
#else
    vehicle::ESummonedVehicleType type; // 38
    uint8_t unk3C[0x40 - 0x3C]; // 3C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(VehicleSummoned_ConditionType, 0x38);
RED4EXT_ASSERT_OFFSET(VehicleSummoned_ConditionType, type, 0x34);
#else
RED4EXT_ASSERT_SIZE(VehicleSummoned_ConditionType, 0x40);
#endif
} // namespace quest
using questVehicleSummoned_ConditionType = quest::VehicleSummoned_ConditionType;
} // namespace RED4ext

// clang-format on
