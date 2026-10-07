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
struct VehicleAVArrived_ConditionType : quest::IVehicleConditionType
{
    static constexpr const char* NAME = "questVehicleAVArrived_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    game::EntityReference vehicleRef; // 38
#else
    game::EntityReference vehicleRef; // 38
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(VehicleAVArrived_ConditionType, 0x70);
RED4EXT_ASSERT_OFFSET(VehicleAVArrived_ConditionType, vehicleRef, 0x38);
#else
RED4EXT_ASSERT_SIZE(VehicleAVArrived_ConditionType, 0x70);
#endif
} // namespace quest
using questVehicleAVArrived_ConditionType = quest::VehicleAVArrived_ConditionType;
} // namespace RED4ext

// clang-format on
