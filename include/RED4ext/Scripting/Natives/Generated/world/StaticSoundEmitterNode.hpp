#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Node.hpp>

namespace RED4ext
{
namespace audio { struct AmbientAreaSettings; }

namespace world
{
struct StaticSoundEmitterNode : world::Node
{
    static constexpr const char* NAME = "worldStaticSoundEmitterNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk32[0x34 - 0x32]; // 32
    float radius; // 34
    CName audioName; // 38
    Handle<audio::AmbientAreaSettings> Settings; // 40
    bool usePhysicsObstruction; // 50
    bool occlusionEnabled; // 51
    bool acousticRepositioningEnabled; // 52
    uint8_t unk53[0x54 - 0x53]; // 53
    float obstructionChangeTime; // 54
    bool useDoppler; // 58
    uint8_t unk59[0x5C - 0x59]; // 59
    float dopplerFactor; // 5C
    bool setOpenDoorEmitter; // 60
    uint8_t unk61[0x68 - 0x61]; // 61
    CName emitterMetadataName; // 68
    bool overrideRolloff; // 70
    uint8_t unk71[0x74 - 0x71]; // 71
    float rolloffOverride; // 74
    CName ambientPaletteTag; // 78
#else
    float radius; // 38
    uint8_t unk3C[0x40 - 0x3C]; // 3C
    CName audioName; // 40
    Handle<audio::AmbientAreaSettings> Settings; // 48
    bool usePhysicsObstruction; // 58
    bool occlusionEnabled; // 59
    bool acousticRepositioningEnabled; // 5A
    uint8_t unk5B[0x5C - 0x5B]; // 5B
    float obstructionChangeTime; // 5C
    bool useDoppler; // 60
    uint8_t unk61[0x64 - 0x61]; // 61
    float dopplerFactor; // 64
    bool setOpenDoorEmitter; // 68
    uint8_t unk69[0x70 - 0x69]; // 69
    CName emitterMetadataName; // 70
    bool overrideRolloff; // 78
    uint8_t unk79[0x7C - 0x79]; // 79
    float rolloffOverride; // 7C
    CName ambientPaletteTag; // 80
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(StaticSoundEmitterNode, 0x80);
RED4EXT_ASSERT_OFFSET(StaticSoundEmitterNode, radius, 0x34);
RED4EXT_ASSERT_OFFSET(StaticSoundEmitterNode, audioName, 0x38);
RED4EXT_ASSERT_OFFSET(StaticSoundEmitterNode, Settings, 0x40);
RED4EXT_ASSERT_OFFSET(StaticSoundEmitterNode, usePhysicsObstruction, 0x50);
RED4EXT_ASSERT_OFFSET(StaticSoundEmitterNode, occlusionEnabled, 0x51);
RED4EXT_ASSERT_OFFSET(StaticSoundEmitterNode, acousticRepositioningEnabled, 0x52);
RED4EXT_ASSERT_OFFSET(StaticSoundEmitterNode, obstructionChangeTime, 0x54);
RED4EXT_ASSERT_OFFSET(StaticSoundEmitterNode, useDoppler, 0x58);
RED4EXT_ASSERT_OFFSET(StaticSoundEmitterNode, dopplerFactor, 0x5C);
RED4EXT_ASSERT_OFFSET(StaticSoundEmitterNode, setOpenDoorEmitter, 0x60);
RED4EXT_ASSERT_OFFSET(StaticSoundEmitterNode, emitterMetadataName, 0x68);
RED4EXT_ASSERT_OFFSET(StaticSoundEmitterNode, overrideRolloff, 0x70);
RED4EXT_ASSERT_OFFSET(StaticSoundEmitterNode, rolloffOverride, 0x74);
RED4EXT_ASSERT_OFFSET(StaticSoundEmitterNode, ambientPaletteTag, 0x78);
#else
RED4EXT_ASSERT_SIZE(StaticSoundEmitterNode, 0x88);
#endif
} // namespace world
using worldStaticSoundEmitterNode = world::StaticSoundEmitterNode;
} // namespace RED4ext

// clang-format on
