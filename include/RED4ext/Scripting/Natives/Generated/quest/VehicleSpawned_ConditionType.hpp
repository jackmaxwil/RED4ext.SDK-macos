#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/EComparisonType.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IVehicleConditionType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/SpawnedVehicleType.hpp>

namespace RED4ext
{
namespace quest
{
struct VehicleSpawned_ConditionType : quest::IVehicleConditionType
{
    static constexpr const char* NAME = "questVehicleSpawned_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    game::EntityReference vehicleRef; // 38
    EComparisonType comparisonType; // 70
    uint32_t count; // 74
    quest::SpawnedVehicleType vehicleType; // 78
    uint8_t unk7C[0x80 - 0x7C]; // 7C
    CString vehicleName; // 80
    CName vehicleGlobalName; // A0
#else
    game::EntityReference vehicleRef; // 38
    EComparisonType comparisonType; // 70
    uint32_t count; // 74
    quest::SpawnedVehicleType vehicleType; // 78
    uint8_t unk7C[0x80 - 0x7C]; // 7C
    CString vehicleName; // 80
    CName vehicleGlobalName; // A0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(VehicleSpawned_ConditionType, 0xA8);
RED4EXT_ASSERT_OFFSET(VehicleSpawned_ConditionType, vehicleRef, 0x38);
RED4EXT_ASSERT_OFFSET(VehicleSpawned_ConditionType, comparisonType, 0x70);
RED4EXT_ASSERT_OFFSET(VehicleSpawned_ConditionType, count, 0x74);
RED4EXT_ASSERT_OFFSET(VehicleSpawned_ConditionType, vehicleType, 0x78);
RED4EXT_ASSERT_OFFSET(VehicleSpawned_ConditionType, vehicleName, 0x80);
RED4EXT_ASSERT_OFFSET(VehicleSpawned_ConditionType, vehicleGlobalName, 0xA0);
#else
RED4EXT_ASSERT_SIZE(VehicleSpawned_ConditionType, 0xA8);
#endif
} // namespace quest
using questVehicleSpawned_ConditionType = quest::VehicleSpawned_ConditionType;
} // namespace RED4ext

// clang-format on
