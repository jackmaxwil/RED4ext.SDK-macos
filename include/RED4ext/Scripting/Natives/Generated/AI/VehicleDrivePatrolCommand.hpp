#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/VehicleCommand.hpp>

namespace RED4ext
{
namespace AI
{
struct VehicleDrivePatrolCommand : AI::VehicleCommand
{
    static constexpr const char* NAME = "AIVehicleDrivePatrolCommand";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk62[0x64 - 0x62]; // 62
    float maxSpeed; // 64
    float minSpeed; // 68
    bool clearTrafficOnPath; // 6C
    bool emergencyPatrol; // 6D
    uint8_t unk6E[0x70 - 0x6E]; // 6E
    uint32_t numPatrolLoops; // 70
    float forcedStartSpeed; // 74
#else
    float maxSpeed; // 68
    float minSpeed; // 6C
    bool clearTrafficOnPath; // 70
    bool emergencyPatrol; // 71
    uint8_t unk72[0x74 - 0x72]; // 72
    uint32_t numPatrolLoops; // 74
    float forcedStartSpeed; // 78
    uint8_t unk7C[0x80 - 0x7C]; // 7C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(VehicleDrivePatrolCommand, 0x78);
RED4EXT_ASSERT_OFFSET(VehicleDrivePatrolCommand, maxSpeed, 0x64);
RED4EXT_ASSERT_OFFSET(VehicleDrivePatrolCommand, minSpeed, 0x68);
RED4EXT_ASSERT_OFFSET(VehicleDrivePatrolCommand, clearTrafficOnPath, 0x6C);
RED4EXT_ASSERT_OFFSET(VehicleDrivePatrolCommand, emergencyPatrol, 0x6D);
RED4EXT_ASSERT_OFFSET(VehicleDrivePatrolCommand, numPatrolLoops, 0x70);
RED4EXT_ASSERT_OFFSET(VehicleDrivePatrolCommand, forcedStartSpeed, 0x74);
#else
RED4EXT_ASSERT_SIZE(VehicleDrivePatrolCommand, 0x80);
#endif
} // namespace AI
using AIVehicleDrivePatrolCommand = AI::VehicleDrivePatrolCommand;
} // namespace RED4ext

// clang-format on
