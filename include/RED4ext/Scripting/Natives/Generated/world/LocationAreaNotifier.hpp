#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/ITriggerAreaNotifer.hpp>

namespace RED4ext
{
namespace world
{
struct LocationAreaNotifier : world::ITriggerAreaNotifer
{
    static constexpr const char* NAME = "worldLocationAreaNotifier";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unkB2[0xB4 - 0xB2]; // B2
    TweakDBID districtID; // B4
    bool sendNewLocationNotification; // BC
    uint8_t unkBD[0xC0 - 0xBD]; // BD
#else
    TweakDBID districtID; // B8
    bool sendNewLocationNotification; // C0
    uint8_t unkC1[0xC8 - 0xC1]; // C1
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(LocationAreaNotifier, 0xC0);
RED4EXT_ASSERT_OFFSET(LocationAreaNotifier, districtID, 0xB4);
RED4EXT_ASSERT_OFFSET(LocationAreaNotifier, sendNewLocationNotification, 0xBC);
#else
RED4EXT_ASSERT_SIZE(LocationAreaNotifier, 0xC8);
#endif
} // namespace world
using worldLocationAreaNotifier = world::LocationAreaNotifier;
} // namespace RED4ext

// clang-format on
