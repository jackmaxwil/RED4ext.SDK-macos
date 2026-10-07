#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/VehicleCommand.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector3.hpp>

namespace RED4ext
{
namespace AI
{
struct VehicleDriveToPointAutonomousCommand : AI::VehicleCommand
{
    static constexpr const char* NAME = "AIVehicleDriveToPointAutonomousCommand";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk62[0x64 - 0x62]; // 62
    Vector3 targetPosition; // 64
    float maxSpeed; // 70
    float minSpeed; // 74
    bool clearTrafficOnPath; // 78
    uint8_t unk79[0x7C - 0x79]; // 79
    float minimumDistanceToTarget; // 7C
    float forcedStartSpeed; // 80
    bool driveDownTheRoadIndefinitely; // 84
    uint8_t unk85[0x88 - 0x85]; // 85
#else
    Vector3 targetPosition; // 68
    float maxSpeed; // 74
    float minSpeed; // 78
    bool clearTrafficOnPath; // 7C
    uint8_t unk7D[0x80 - 0x7D]; // 7D
    float minimumDistanceToTarget; // 80
    float forcedStartSpeed; // 84
    bool driveDownTheRoadIndefinitely; // 88
    uint8_t unk89[0x90 - 0x89]; // 89
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(VehicleDriveToPointAutonomousCommand, 0x88);
RED4EXT_ASSERT_OFFSET(VehicleDriveToPointAutonomousCommand, targetPosition, 0x64);
RED4EXT_ASSERT_OFFSET(VehicleDriveToPointAutonomousCommand, maxSpeed, 0x70);
RED4EXT_ASSERT_OFFSET(VehicleDriveToPointAutonomousCommand, minSpeed, 0x74);
RED4EXT_ASSERT_OFFSET(VehicleDriveToPointAutonomousCommand, clearTrafficOnPath, 0x78);
RED4EXT_ASSERT_OFFSET(VehicleDriveToPointAutonomousCommand, minimumDistanceToTarget, 0x7C);
RED4EXT_ASSERT_OFFSET(VehicleDriveToPointAutonomousCommand, forcedStartSpeed, 0x80);
RED4EXT_ASSERT_OFFSET(VehicleDriveToPointAutonomousCommand, driveDownTheRoadIndefinitely, 0x84);
#else
RED4EXT_ASSERT_SIZE(VehicleDriveToPointAutonomousCommand, 0x90);
#endif
} // namespace AI
using AIVehicleDriveToPointAutonomousCommand = AI::VehicleDriveToPointAutonomousCommand;
} // namespace RED4ext

// clang-format on
