#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/WheeledBaseObject.hpp>

namespace RED4ext
{
namespace vehicle
{
struct __declspec(align(0x10)) CarBaseObject : vehicle::WheeledBaseObject
{
    static constexpr const char* NAME = "vehicleCarBaseObject";
    static constexpr const char* ALIAS = "CarObject";

#ifdef __APPLE__
    uint8_t unkBF0[0xC30 - 0xBF0]; // BF0
#else
    uint8_t unkC10[0xC60 - 0xC10]; // C10
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CarBaseObject, 0xC30);
#else
RED4EXT_ASSERT_SIZE(CarBaseObject, 0xC60);
#endif
} // namespace vehicle
using vehicleCarBaseObject = vehicle::CarBaseObject;
using CarObject = vehicle::CarBaseObject;
} // namespace RED4ext

// clang-format on
