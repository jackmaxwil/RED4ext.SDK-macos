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
struct VehiclePanicCommand : AI::VehicleCommand
{
    static constexpr const char* NAME = "AIVehiclePanicCommand";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool allowSimplifiedMovement; // 62
    bool ignoreTickets; // 63
    bool disableStuckDetection; // 64
    bool useSpeedBasedLookupRange; // 65
    bool tryDriveAwayFromPlayer; // 66
    uint8_t unk67[0x68 - 0x67]; // 67
#else
    bool allowSimplifiedMovement; // 68
    bool ignoreTickets; // 69
    bool disableStuckDetection; // 6A
    bool useSpeedBasedLookupRange; // 6B
    bool tryDriveAwayFromPlayer; // 6C
    uint8_t unk6D[0x70 - 0x6D]; // 6D
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(VehiclePanicCommand, 0x68);
RED4EXT_ASSERT_OFFSET(VehiclePanicCommand, allowSimplifiedMovement, 0x62);
RED4EXT_ASSERT_OFFSET(VehiclePanicCommand, ignoreTickets, 0x63);
RED4EXT_ASSERT_OFFSET(VehiclePanicCommand, disableStuckDetection, 0x64);
RED4EXT_ASSERT_OFFSET(VehiclePanicCommand, useSpeedBasedLookupRange, 0x65);
RED4EXT_ASSERT_OFFSET(VehiclePanicCommand, tryDriveAwayFromPlayer, 0x66);
#else
RED4EXT_ASSERT_SIZE(VehiclePanicCommand, 0x70);
#endif
} // namespace AI
using AIVehiclePanicCommand = AI::VehiclePanicCommand;
} // namespace RED4ext

// clang-format on
