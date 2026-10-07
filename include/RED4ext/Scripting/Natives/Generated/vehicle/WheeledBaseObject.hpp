#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/BaseObject.hpp>

namespace RED4ext
{
namespace vehicle
{
struct __declspec(align(0x10)) WheeledBaseObject : vehicle::BaseObject
{
    static constexpr const char* NAME = "vehicleWheeledBaseObject";
    static constexpr const char* ALIAS = "WheeledObject";

#ifdef __APPLE__
    uint8_t unkB80[0xBD0 - 0xB80]; // B80
#else
    uint8_t unkBA0[0xBF0 - 0xBA0]; // BA0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(WheeledBaseObject, 0xBD0);
#else
RED4EXT_ASSERT_SIZE(WheeledBaseObject, 0xBF0);
#endif
} // namespace vehicle
using vehicleWheeledBaseObject = vehicle::WheeledBaseObject;
using WheeledObject = vehicle::WheeledBaseObject;
} // namespace RED4ext

// clang-format on
