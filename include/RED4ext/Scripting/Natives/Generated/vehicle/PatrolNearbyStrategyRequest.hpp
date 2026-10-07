#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector2.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/BaseStrategyRequest.hpp>

namespace RED4ext
{
namespace vehicle
{
struct PatrolNearbyStrategyRequest : vehicle::BaseStrategyRequest
{
    static constexpr const char* NAME = "vehiclePatrolNearbyStrategyRequest";
    static constexpr const char* ALIAS = "PatrolNearbyStrategyRequest";

#ifdef __APPLE__
    Vector2 angleRange; // 54
    uint8_t unk5C[0x60 - 0x5C]; // 5C
#else
    Vector2 angleRange; // 58
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PatrolNearbyStrategyRequest, 0x60);
RED4EXT_ASSERT_OFFSET(PatrolNearbyStrategyRequest, angleRange, 0x54);
#else
RED4EXT_ASSERT_SIZE(PatrolNearbyStrategyRequest, 0x60);
#endif
} // namespace vehicle
using vehiclePatrolNearbyStrategyRequest = vehicle::PatrolNearbyStrategyRequest;
using PatrolNearbyStrategyRequest = vehicle::PatrolNearbyStrategyRequest;
} // namespace RED4ext

// clang-format on
