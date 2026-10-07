#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/ITriggerAreaNotifer.hpp>

namespace RED4ext
{
namespace world
{
struct WeatherAreaNotifier : world::ITriggerAreaNotifer
{
    static constexpr const char* NAME = "worldWeatherAreaNotifier";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unkB2[0xB4 - 0xB2]; // B2
    float horizontalFadeDistance; // B4
    float verticalFadeDistance; // B8
    uint8_t unkBC[0xC0 - 0xBC]; // BC
    DynArray<CName> weatherStateNames; // C0
    DynArray<float> weatherStateValues; // D0
#else
    float horizontalFadeDistance; // B8
    float verticalFadeDistance; // BC
    DynArray<CName> weatherStateNames; // C0
    DynArray<float> weatherStateValues; // D0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(WeatherAreaNotifier, 0xE0);
RED4EXT_ASSERT_OFFSET(WeatherAreaNotifier, horizontalFadeDistance, 0xB4);
RED4EXT_ASSERT_OFFSET(WeatherAreaNotifier, verticalFadeDistance, 0xB8);
RED4EXT_ASSERT_OFFSET(WeatherAreaNotifier, weatherStateNames, 0xC0);
RED4EXT_ASSERT_OFFSET(WeatherAreaNotifier, weatherStateValues, 0xD0);
#else
RED4EXT_ASSERT_SIZE(WeatherAreaNotifier, 0xE0);
#endif
} // namespace world
using worldWeatherAreaNotifier = world::WeatherAreaNotifier;
} // namespace RED4ext

// clang-format on
