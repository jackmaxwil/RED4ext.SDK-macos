#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IVehicleConditionType.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/EVehicleDoor.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/VehicleDoorState.hpp>

namespace RED4ext
{
namespace quest
{
struct VehicleDoor_ConditionType : quest::IVehicleConditionType
{
    static constexpr const char* NAME = "questVehicleDoor_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    game::EntityReference vehicleRef; // 38
    vehicle::EVehicleDoor door; // 70
    vehicle::VehicleDoorState state; // 74
#else
    game::EntityReference vehicleRef; // 38
    vehicle::EVehicleDoor door; // 70
    vehicle::VehicleDoorState state; // 74
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(VehicleDoor_ConditionType, 0x78);
RED4EXT_ASSERT_OFFSET(VehicleDoor_ConditionType, vehicleRef, 0x38);
RED4EXT_ASSERT_OFFSET(VehicleDoor_ConditionType, door, 0x70);
RED4EXT_ASSERT_OFFSET(VehicleDoor_ConditionType, state, 0x74);
#else
RED4EXT_ASSERT_SIZE(VehicleDoor_ConditionType, 0x78);
#endif
} // namespace quest
using questVehicleDoor_ConditionType = quest::VehicleDoor_ConditionType;
} // namespace RED4ext

// clang-format on
