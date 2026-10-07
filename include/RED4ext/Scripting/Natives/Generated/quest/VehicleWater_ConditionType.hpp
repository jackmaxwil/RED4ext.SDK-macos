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
struct VehicleWater_ConditionType : quest::IVehicleConditionType
{
    static constexpr const char* NAME = "questVehicleWater_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    game::EntityReference vehicleRef; // 38
    bool anyVehicle; // 70
    bool submergedOnly; // 71
    bool onEnter; // 72
    uint8_t unk73[0x78 - 0x73]; // 73
#else
    game::EntityReference vehicleRef; // 38
    bool anyVehicle; // 70
    bool submergedOnly; // 71
    bool onEnter; // 72
    uint8_t unk73[0x78 - 0x73]; // 73
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(VehicleWater_ConditionType, 0x78);
RED4EXT_ASSERT_OFFSET(VehicleWater_ConditionType, vehicleRef, 0x38);
RED4EXT_ASSERT_OFFSET(VehicleWater_ConditionType, anyVehicle, 0x70);
RED4EXT_ASSERT_OFFSET(VehicleWater_ConditionType, submergedOnly, 0x71);
RED4EXT_ASSERT_OFFSET(VehicleWater_ConditionType, onEnter, 0x72);
#else
RED4EXT_ASSERT_SIZE(VehicleWater_ConditionType, 0x78);
#endif
} // namespace quest
using questVehicleWater_ConditionType = quest::VehicleWater_ConditionType;
} // namespace RED4ext

// clang-format on
