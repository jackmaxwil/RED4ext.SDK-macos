#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/ITriggerAreaNotifer.hpp>

namespace RED4ext
{
namespace audio { struct AmbientAreaSettings; }

namespace audio
{
struct AmbientAreaNotifier : world::ITriggerAreaNotifer
{
    static constexpr const char* NAME = "audioAmbientAreaNotifier";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unkB2[0xB8 - 0xB2]; // B2
    Handle<audio::AmbientAreaSettings> Settings; // B8
    bool usePhysicsObstruction; // C8
    bool occlusionEnabled; // C9
    bool acousticRepositioningEnabled; // CA
    uint8_t unkCB[0xCC - 0xCB]; // CB
    float obstructionChangeTime; // CC
    bool overrideRolloff; // D0
    uint8_t unkD1[0xD4 - 0xD1]; // D1
    float rolloffOverride; // D4
    bool useAutoOutdoorness; // D8
    uint8_t unkD9[0xE0 - 0xD9]; // D9
#else
    Handle<audio::AmbientAreaSettings> Settings; // B8
    bool usePhysicsObstruction; // C8
    bool occlusionEnabled; // C9
    bool acousticRepositioningEnabled; // CA
    uint8_t unkCB[0xCC - 0xCB]; // CB
    float obstructionChangeTime; // CC
    bool overrideRolloff; // D0
    uint8_t unkD1[0xD4 - 0xD1]; // D1
    float rolloffOverride; // D4
    bool useAutoOutdoorness; // D8
    uint8_t unkD9[0xE0 - 0xD9]; // D9
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AmbientAreaNotifier, 0xE0);
RED4EXT_ASSERT_OFFSET(AmbientAreaNotifier, Settings, 0xB8);
RED4EXT_ASSERT_OFFSET(AmbientAreaNotifier, usePhysicsObstruction, 0xC8);
RED4EXT_ASSERT_OFFSET(AmbientAreaNotifier, occlusionEnabled, 0xC9);
RED4EXT_ASSERT_OFFSET(AmbientAreaNotifier, acousticRepositioningEnabled, 0xCA);
RED4EXT_ASSERT_OFFSET(AmbientAreaNotifier, obstructionChangeTime, 0xCC);
RED4EXT_ASSERT_OFFSET(AmbientAreaNotifier, overrideRolloff, 0xD0);
RED4EXT_ASSERT_OFFSET(AmbientAreaNotifier, rolloffOverride, 0xD4);
RED4EXT_ASSERT_OFFSET(AmbientAreaNotifier, useAutoOutdoorness, 0xD8);
#else
RED4EXT_ASSERT_SIZE(AmbientAreaNotifier, 0xE0);
#endif
} // namespace audio
using audioAmbientAreaNotifier = audio::AmbientAreaNotifier;
} // namespace RED4ext

// clang-format on
