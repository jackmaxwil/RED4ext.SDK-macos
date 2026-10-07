#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/SplineNodeInstance.hpp>

namespace RED4ext
{
namespace world
{
struct __declspec(align(0x10)) SpeedSplineNodeInstance : world::SplineNodeInstance
{
    static constexpr const char* NAME = "worldSpeedSplineNodeInstance";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
#else
    uint8_t unkE0[0xF0 - 0xE0]; // E0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SpeedSplineNodeInstance, 0xE0);
#else
RED4EXT_ASSERT_SIZE(SpeedSplineNodeInstance, 0xF0);
#endif
} // namespace world
using worldSpeedSplineNodeInstance = world::SpeedSplineNodeInstance;
} // namespace RED4ext

// clang-format on
