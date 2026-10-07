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
struct VehicleFollowCommand : AI::VehicleCommand
{
    static constexpr const char* NAME = "AIVehicleFollowCommand";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk62[0x68 - 0x62]; // 62
    WeakHandle<game::Object> target; // 68
    float secureTimeOut; // 78
    float distanceMin; // 7C
    float distanceMax; // 80
    bool stopWhenTargetReached; // 84
    bool useTraffic; // 85
    bool trafficTryNeighborsForStart; // 86
    bool trafficTryNeighborsForEnd; // 87
#else
    WeakHandle<game::Object> target; // 68
    float secureTimeOut; // 78
    float distanceMin; // 7C
    float distanceMax; // 80
    bool stopWhenTargetReached; // 84
    bool useTraffic; // 85
    bool trafficTryNeighborsForStart; // 86
    bool trafficTryNeighborsForEnd; // 87
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(VehicleFollowCommand, 0x88);
RED4EXT_ASSERT_OFFSET(VehicleFollowCommand, target, 0x68);
RED4EXT_ASSERT_OFFSET(VehicleFollowCommand, secureTimeOut, 0x78);
RED4EXT_ASSERT_OFFSET(VehicleFollowCommand, distanceMin, 0x7C);
RED4EXT_ASSERT_OFFSET(VehicleFollowCommand, distanceMax, 0x80);
RED4EXT_ASSERT_OFFSET(VehicleFollowCommand, stopWhenTargetReached, 0x84);
RED4EXT_ASSERT_OFFSET(VehicleFollowCommand, useTraffic, 0x85);
RED4EXT_ASSERT_OFFSET(VehicleFollowCommand, trafficTryNeighborsForStart, 0x86);
RED4EXT_ASSERT_OFFSET(VehicleFollowCommand, trafficTryNeighborsForEnd, 0x87);
#else
RED4EXT_ASSERT_SIZE(VehicleFollowCommand, 0x88);
#endif
} // namespace AI
using AIVehicleFollowCommand = AI::VehicleFollowCommand;
} // namespace RED4ext

// clang-format on
