#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/AvailableVehicleType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IVehicleConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct VehicleAvailable_ConditionType : quest::IVehicleConditionType
{
    static constexpr const char* NAME = "questVehicleAvailable_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    quest::AvailableVehicleType vehicleType; // 34
    CString vehicleName; // 38
#else
    quest::AvailableVehicleType vehicleType; // 38
    uint8_t unk3C[0x40 - 0x3C]; // 3C
    CString vehicleName; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(VehicleAvailable_ConditionType, 0x58);
RED4EXT_ASSERT_OFFSET(VehicleAvailable_ConditionType, vehicleType, 0x34);
RED4EXT_ASSERT_OFFSET(VehicleAvailable_ConditionType, vehicleName, 0x38);
#else
RED4EXT_ASSERT_SIZE(VehicleAvailable_ConditionType, 0x60);
#endif
} // namespace quest
using questVehicleAvailable_ConditionType = quest::VehicleAvailable_ConditionType;
} // namespace RED4ext

// clang-format on
