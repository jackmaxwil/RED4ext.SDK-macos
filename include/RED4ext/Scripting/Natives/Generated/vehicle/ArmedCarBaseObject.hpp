#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/CarBaseObject.hpp>

namespace RED4ext
{
namespace vehicle
{
struct __declspec(align(0x10)) ArmedCarBaseObject : vehicle::CarBaseObject
{
    static constexpr const char* NAME = "vehicleArmedCarBaseObject";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unkC10[0xCD0 - 0xC10]; // C10
#else
    uint8_t unkC40[0xD00 - 0xC40]; // C40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ArmedCarBaseObject, 0xCD0);
#else
RED4EXT_ASSERT_SIZE(ArmedCarBaseObject, 0xD00);
#endif
} // namespace vehicle
using vehicleArmedCarBaseObject = vehicle::ArmedCarBaseObject;
} // namespace RED4ext

// clang-format on
