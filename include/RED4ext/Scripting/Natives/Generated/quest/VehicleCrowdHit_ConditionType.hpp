#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IVehicleConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct VehicleCrowdHit_ConditionType : quest::IVehicleConditionType
{
    static constexpr const char* NAME = "questVehicleCrowdHit_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool lethal; // 34
    uint8_t unk35[0x38 - 0x35]; // 35
#else
    bool lethal; // 38
    uint8_t unk39[0x40 - 0x39]; // 39
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(VehicleCrowdHit_ConditionType, 0x38);
RED4EXT_ASSERT_OFFSET(VehicleCrowdHit_ConditionType, lethal, 0x34);
#else
RED4EXT_ASSERT_SIZE(VehicleCrowdHit_ConditionType, 0x40);
#endif
} // namespace quest
using questVehicleCrowdHit_ConditionType = quest::VehicleCrowdHit_ConditionType;
} // namespace RED4ext

// clang-format on
