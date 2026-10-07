#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IVehicleConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct VehicleTrunk_ConditionType : quest::IVehicleConditionType
{
    static constexpr const char* NAME = "questVehicleTrunk_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool playerVehicle; // 34
    uint8_t unk35[0x38 - 0x35]; // 35
    game::EntityReference vehicleRef; // 38
    game::EntityReference objectRef; // 70
    bool inverted; // A8
    bool isInside; // A9
    bool anyVehicle; // AA
    bool anyObject; // AB
    uint8_t unkAC[0xB0 - 0xAC]; // AC
#else
    bool playerVehicle; // 38
    uint8_t unk39[0x40 - 0x39]; // 39
    game::EntityReference vehicleRef; // 40
    game::EntityReference objectRef; // 78
    bool inverted; // B0
    bool isInside; // B1
    bool anyVehicle; // B2
    bool anyObject; // B3
    uint8_t unkB4[0xB8 - 0xB4]; // B4
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(VehicleTrunk_ConditionType, 0xB0);
RED4EXT_ASSERT_OFFSET(VehicleTrunk_ConditionType, playerVehicle, 0x34);
RED4EXT_ASSERT_OFFSET(VehicleTrunk_ConditionType, vehicleRef, 0x38);
RED4EXT_ASSERT_OFFSET(VehicleTrunk_ConditionType, objectRef, 0x70);
RED4EXT_ASSERT_OFFSET(VehicleTrunk_ConditionType, inverted, 0xA8);
RED4EXT_ASSERT_OFFSET(VehicleTrunk_ConditionType, isInside, 0xA9);
RED4EXT_ASSERT_OFFSET(VehicleTrunk_ConditionType, anyVehicle, 0xAA);
RED4EXT_ASSERT_OFFSET(VehicleTrunk_ConditionType, anyObject, 0xAB);
#else
RED4EXT_ASSERT_SIZE(VehicleTrunk_ConditionType, 0xB8);
#endif
} // namespace quest
using questVehicleTrunk_ConditionType = quest::VehicleTrunk_ConditionType;
} // namespace RED4ext

// clang-format on
