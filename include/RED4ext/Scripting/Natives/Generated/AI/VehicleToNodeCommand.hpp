#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/VehicleCommand.hpp>

namespace RED4ext
{
namespace vehicle { struct PortalsList; }

namespace AI
{
struct VehicleToNodeCommand : AI::VehicleCommand
{
    static constexpr const char* NAME = "AIVehicleToNodeCommand";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk62[0x68 - 0x62]; // 62
    NodeRef nodeRef; // 68
    bool stopAtPathEnd; // 70
    uint8_t unk71[0x74 - 0x71]; // 71
    float secureTimeOut; // 74
    bool isPlayer; // 78
    bool useTraffic; // 79
    uint8_t unk7A[0x7C - 0x7A]; // 7A
    float speedInTraffic; // 7C
    bool forceGreenLights; // 80
    uint8_t unk81[0x88 - 0x81]; // 81
    Handle<vehicle::PortalsList> portals; // 88
    bool trafficTryNeighborsForStart; // 98
    bool trafficTryNeighborsForEnd; // 99
    bool ignoreNoAIDrivingLanes; // 9A
    uint8_t unk9B[0xA0 - 0x9B]; // 9B
#else
    NodeRef nodeRef; // 68
    bool stopAtPathEnd; // 70
    uint8_t unk71[0x74 - 0x71]; // 71
    float secureTimeOut; // 74
    bool isPlayer; // 78
    bool useTraffic; // 79
    uint8_t unk7A[0x7C - 0x7A]; // 7A
    float speedInTraffic; // 7C
    bool forceGreenLights; // 80
    uint8_t unk81[0x88 - 0x81]; // 81
    Handle<vehicle::PortalsList> portals; // 88
    bool trafficTryNeighborsForStart; // 98
    bool trafficTryNeighborsForEnd; // 99
    bool ignoreNoAIDrivingLanes; // 9A
    uint8_t unk9B[0xA0 - 0x9B]; // 9B
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(VehicleToNodeCommand, 0xA0);
RED4EXT_ASSERT_OFFSET(VehicleToNodeCommand, nodeRef, 0x68);
RED4EXT_ASSERT_OFFSET(VehicleToNodeCommand, stopAtPathEnd, 0x70);
RED4EXT_ASSERT_OFFSET(VehicleToNodeCommand, secureTimeOut, 0x74);
RED4EXT_ASSERT_OFFSET(VehicleToNodeCommand, isPlayer, 0x78);
RED4EXT_ASSERT_OFFSET(VehicleToNodeCommand, useTraffic, 0x79);
RED4EXT_ASSERT_OFFSET(VehicleToNodeCommand, speedInTraffic, 0x7C);
RED4EXT_ASSERT_OFFSET(VehicleToNodeCommand, forceGreenLights, 0x80);
RED4EXT_ASSERT_OFFSET(VehicleToNodeCommand, portals, 0x88);
RED4EXT_ASSERT_OFFSET(VehicleToNodeCommand, trafficTryNeighborsForStart, 0x98);
RED4EXT_ASSERT_OFFSET(VehicleToNodeCommand, trafficTryNeighborsForEnd, 0x99);
RED4EXT_ASSERT_OFFSET(VehicleToNodeCommand, ignoreNoAIDrivingLanes, 0x9A);
#else
RED4EXT_ASSERT_SIZE(VehicleToNodeCommand, 0xA0);
#endif
} // namespace AI
using AIVehicleToNodeCommand = AI::VehicleToNodeCommand;
} // namespace RED4ext

// clang-format on
