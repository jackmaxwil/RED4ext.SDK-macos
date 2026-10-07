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
struct __declspec(align(0x10)) TankBaseObject : vehicle::BaseObject
{
    static constexpr const char* NAME = "vehicleTankBaseObject";
    static constexpr const char* ALIAS = "TankObject";

#ifdef __APPLE__
    uint8_t unkB80[0xBE0 - 0xB80]; // B80
#else
    uint8_t unkBA0[0xC00 - 0xBA0]; // BA0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TankBaseObject, 0xBE0);
#else
RED4EXT_ASSERT_SIZE(TankBaseObject, 0xC00);
#endif
} // namespace vehicle
using vehicleTankBaseObject = vehicle::TankBaseObject;
using TankObject = vehicle::TankBaseObject;
} // namespace RED4ext

// clang-format on
