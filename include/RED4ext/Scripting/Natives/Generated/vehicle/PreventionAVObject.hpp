#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/AVBaseObject.hpp>

namespace RED4ext
{
namespace vehicle
{
struct __declspec(align(0x10)) PreventionAVObject : vehicle::AVBaseObject
{
    static constexpr const char* NAME = "vehiclePreventionAVObject";
    static constexpr const char* ALIAS = "PreventionAVObject";

#ifdef __APPLE__
    uint8_t unkBA0[0xBB0 - 0xBA0]; // BA0
#else
    uint8_t unkBC0[0xBD0 - 0xBC0]; // BC0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PreventionAVObject, 0xBB0);
#else
RED4EXT_ASSERT_SIZE(PreventionAVObject, 0xBD0);
#endif
} // namespace vehicle
using vehiclePreventionAVObject = vehicle::PreventionAVObject;
using PreventionAVObject = vehicle::PreventionAVObject;
} // namespace RED4ext

// clang-format on
