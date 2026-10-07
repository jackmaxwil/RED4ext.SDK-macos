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
namespace game { struct Object; }

namespace AI
{
struct VehicleRacingCommand : AI::VehicleCommand
{
    static constexpr const char* NAME = "AIVehicleRacingCommand";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk62[0x68 - 0x62]; // 62
    NodeRef splineRef; // 68
    float secureTimeOut; // 70
    bool reverseSpline; // 74
    bool driveBackwards; // 75
    bool startFromClosest; // 76
    bool rubberBandingBool; // 77
    WeakHandle<game::Object> rubberBandingTargetRef; // 78
    float rubberBandingTargetForwardOffset; // 88
    float rubberBandingMinDistance; // 8C
    float rubberBandingMaxDistance; // 90
    bool rubberBandingStopAndWait; // 94
    bool rubberBandingTeleportToCatchUp; // 95
    bool rubberBandingStayInFront; // 96
    uint8_t unk97[0x98 - 0x97]; // 97
#else
    NodeRef splineRef; // 68
    float secureTimeOut; // 70
    bool reverseSpline; // 74
    bool driveBackwards; // 75
    bool startFromClosest; // 76
    bool rubberBandingBool; // 77
    WeakHandle<game::Object> rubberBandingTargetRef; // 78
    float rubberBandingTargetForwardOffset; // 88
    float rubberBandingMinDistance; // 8C
    float rubberBandingMaxDistance; // 90
    bool rubberBandingStopAndWait; // 94
    bool rubberBandingTeleportToCatchUp; // 95
    bool rubberBandingStayInFront; // 96
    uint8_t unk97[0x98 - 0x97]; // 97
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(VehicleRacingCommand, 0x98);
RED4EXT_ASSERT_OFFSET(VehicleRacingCommand, splineRef, 0x68);
RED4EXT_ASSERT_OFFSET(VehicleRacingCommand, secureTimeOut, 0x70);
RED4EXT_ASSERT_OFFSET(VehicleRacingCommand, reverseSpline, 0x74);
RED4EXT_ASSERT_OFFSET(VehicleRacingCommand, driveBackwards, 0x75);
RED4EXT_ASSERT_OFFSET(VehicleRacingCommand, startFromClosest, 0x76);
RED4EXT_ASSERT_OFFSET(VehicleRacingCommand, rubberBandingBool, 0x77);
RED4EXT_ASSERT_OFFSET(VehicleRacingCommand, rubberBandingTargetRef, 0x78);
RED4EXT_ASSERT_OFFSET(VehicleRacingCommand, rubberBandingTargetForwardOffset, 0x88);
RED4EXT_ASSERT_OFFSET(VehicleRacingCommand, rubberBandingMinDistance, 0x8C);
RED4EXT_ASSERT_OFFSET(VehicleRacingCommand, rubberBandingMaxDistance, 0x90);
RED4EXT_ASSERT_OFFSET(VehicleRacingCommand, rubberBandingStopAndWait, 0x94);
RED4EXT_ASSERT_OFFSET(VehicleRacingCommand, rubberBandingTeleportToCatchUp, 0x95);
RED4EXT_ASSERT_OFFSET(VehicleRacingCommand, rubberBandingStayInFront, 0x96);
#else
RED4EXT_ASSERT_SIZE(VehicleRacingCommand, 0x98);
#endif
} // namespace AI
using AIVehicleRacingCommand = AI::VehicleRacingCommand;
} // namespace RED4ext

// clang-format on
