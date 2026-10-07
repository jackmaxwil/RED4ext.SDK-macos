#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/VehicleCommand.hpp>

namespace RED4ext
{
namespace game { struct Object; }

namespace AI
{
struct VehicleChaseCommand : AI::VehicleCommand
{
    static constexpr const char* NAME = "AIVehicleChaseCommand";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk62[0x68 - 0x62]; // 62
    WeakHandle<game::Object> target; // 68
    float distanceMin; // 78
    float distanceMax; // 7C
    float forcedStartSpeed; // 80
    bool aggressiveRamming; // 84
    bool ignoreChaseVehiclesLimit; // 85
    bool boostDrivingStats; // 86
    uint8_t unk87[0x88 - 0x87]; // 87
#else
    WeakHandle<game::Object> target; // 68
    float distanceMin; // 78
    float distanceMax; // 7C
    float forcedStartSpeed; // 80
    bool aggressiveRamming; // 84
    bool ignoreChaseVehiclesLimit; // 85
    bool boostDrivingStats; // 86
    uint8_t unk87[0x88 - 0x87]; // 87
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(VehicleChaseCommand, 0x88);
RED4EXT_ASSERT_OFFSET(VehicleChaseCommand, target, 0x68);
RED4EXT_ASSERT_OFFSET(VehicleChaseCommand, distanceMin, 0x78);
RED4EXT_ASSERT_OFFSET(VehicleChaseCommand, distanceMax, 0x7C);
RED4EXT_ASSERT_OFFSET(VehicleChaseCommand, forcedStartSpeed, 0x80);
RED4EXT_ASSERT_OFFSET(VehicleChaseCommand, aggressiveRamming, 0x84);
RED4EXT_ASSERT_OFFSET(VehicleChaseCommand, ignoreChaseVehiclesLimit, 0x85);
RED4EXT_ASSERT_OFFSET(VehicleChaseCommand, boostDrivingStats, 0x86);
#else
RED4EXT_ASSERT_SIZE(VehicleChaseCommand, 0x88);
#endif
} // namespace AI
using AIVehicleChaseCommand = AI::VehicleChaseCommand;
} // namespace RED4ext

// clang-format on
