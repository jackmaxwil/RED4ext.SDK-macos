#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/CameraComponent.hpp>

namespace RED4ext
{
namespace vehicle
{
struct __declspec(align(0x10)) VehicleProxyBlendCamera : game::CameraComponent
{
    static constexpr const char* NAME = "vehicleVehicleProxyBlendCamera";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk318[0x380 - 0x318]; // 318
#else
    uint8_t unk320[0x380 - 0x320]; // 320
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(VehicleProxyBlendCamera, 0x380);
#else
RED4EXT_ASSERT_SIZE(VehicleProxyBlendCamera, 0x380);
#endif
} // namespace vehicle
using vehicleVehicleProxyBlendCamera = vehicle::VehicleProxyBlendCamera;
} // namespace RED4ext

// clang-format on
