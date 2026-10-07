#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/HDRColor.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector3.hpp>
#include <RED4ext/Scripting/Natives/Generated/env/UtilsNeighborMode.hpp>
#include <RED4ext/Scripting/Natives/Generated/env/UtilsReflectionProbeAmbientContributionMode.hpp>
#include <RED4ext/Scripting/Natives/Generated/rend/LightChannel.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Node.hpp>

namespace RED4ext
{
struct CReflectionProbeDataResource;

namespace world
{
struct __declspec(align(0x10)) ReflectionProbeNode : world::Node
{
    static constexpr const char* NAME = "worldReflectionProbeNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk32[0x38 - 0x32]; // 32
    RaRef<CReflectionProbeDataResource> probeDataRef; // 38
    uint8_t unk40[0x42 - 0x40]; // 40
    bool globalProbe; // 42
    env::UtilsReflectionProbeAmbientContributionMode ambientMode; // 43
    bool allInShadow; // 44
    bool hideSkyColor; // 45
    bool volFogAmbient; // 46
    bool boxProjection; // 47
    bool noFadeBlend; // 48
    bool subScene; // 49
    uint8_t unk4A[0x4C - 0x4A]; // 4A
    Vector3 edgeScale; // 4C
    Vector3 captureOffset; // 58
    uint8_t unk64[0x70 - 0x64]; // 64
    HDRColor simpleFogColor; // 70
    float simpleFogDensity; // 80
    float skyScale; // 84
    float emissiveScale; // 88
    float reflectionDimming; // 8C
    float nearClipDistance; // 90
    float farClipDistance; // 94
    float streamingHeight; // 98
    float streamingDistance; // 9C
    uint8_t blendRange; // A0
    uint8_t priority; // A1
    rend::LightChannel lightChannels; // A2
    rend::LightChannel volumeChannels; // A4
    env::UtilsNeighborMode neighborMode; // A6
    int8_t brightnessEVClamp; // A7
    uint8_t unkA8[0xB0 - 0xA8]; // A8
#else
    RaRef<CReflectionProbeDataResource> probeDataRef; // 38
    uint8_t unk40[0x42 - 0x40]; // 40
    bool globalProbe; // 42
    env::UtilsReflectionProbeAmbientContributionMode ambientMode; // 43
    bool allInShadow; // 44
    bool hideSkyColor; // 45
    bool volFogAmbient; // 46
    bool boxProjection; // 47
    bool noFadeBlend; // 48
    bool subScene; // 49
    uint8_t unk4A[0x4C - 0x4A]; // 4A
    Vector3 edgeScale; // 4C
    Vector3 captureOffset; // 58
    uint8_t unk64[0x70 - 0x64]; // 64
    HDRColor simpleFogColor; // 70
    float simpleFogDensity; // 80
    float skyScale; // 84
    float emissiveScale; // 88
    float reflectionDimming; // 8C
    float nearClipDistance; // 90
    float farClipDistance; // 94
    float streamingHeight; // 98
    float streamingDistance; // 9C
    uint8_t blendRange; // A0
    uint8_t priority; // A1
    rend::LightChannel lightChannels; // A2
    rend::LightChannel volumeChannels; // A4
    env::UtilsNeighborMode neighborMode; // A6
    int8_t brightnessEVClamp; // A7
    uint8_t unkA8[0xB0 - 0xA8]; // A8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ReflectionProbeNode, 0xB0);
RED4EXT_ASSERT_OFFSET(ReflectionProbeNode, probeDataRef, 0x38);
RED4EXT_ASSERT_OFFSET(ReflectionProbeNode, globalProbe, 0x42);
RED4EXT_ASSERT_OFFSET(ReflectionProbeNode, ambientMode, 0x43);
RED4EXT_ASSERT_OFFSET(ReflectionProbeNode, allInShadow, 0x44);
RED4EXT_ASSERT_OFFSET(ReflectionProbeNode, hideSkyColor, 0x45);
RED4EXT_ASSERT_OFFSET(ReflectionProbeNode, volFogAmbient, 0x46);
RED4EXT_ASSERT_OFFSET(ReflectionProbeNode, boxProjection, 0x47);
RED4EXT_ASSERT_OFFSET(ReflectionProbeNode, noFadeBlend, 0x48);
RED4EXT_ASSERT_OFFSET(ReflectionProbeNode, subScene, 0x49);
RED4EXT_ASSERT_OFFSET(ReflectionProbeNode, edgeScale, 0x4C);
RED4EXT_ASSERT_OFFSET(ReflectionProbeNode, captureOffset, 0x58);
RED4EXT_ASSERT_OFFSET(ReflectionProbeNode, simpleFogColor, 0x70);
RED4EXT_ASSERT_OFFSET(ReflectionProbeNode, simpleFogDensity, 0x80);
RED4EXT_ASSERT_OFFSET(ReflectionProbeNode, skyScale, 0x84);
RED4EXT_ASSERT_OFFSET(ReflectionProbeNode, emissiveScale, 0x88);
RED4EXT_ASSERT_OFFSET(ReflectionProbeNode, reflectionDimming, 0x8C);
RED4EXT_ASSERT_OFFSET(ReflectionProbeNode, nearClipDistance, 0x90);
RED4EXT_ASSERT_OFFSET(ReflectionProbeNode, farClipDistance, 0x94);
RED4EXT_ASSERT_OFFSET(ReflectionProbeNode, streamingHeight, 0x98);
RED4EXT_ASSERT_OFFSET(ReflectionProbeNode, streamingDistance, 0x9C);
RED4EXT_ASSERT_OFFSET(ReflectionProbeNode, blendRange, 0xA0);
RED4EXT_ASSERT_OFFSET(ReflectionProbeNode, priority, 0xA1);
RED4EXT_ASSERT_OFFSET(ReflectionProbeNode, lightChannels, 0xA2);
RED4EXT_ASSERT_OFFSET(ReflectionProbeNode, volumeChannels, 0xA4);
RED4EXT_ASSERT_OFFSET(ReflectionProbeNode, neighborMode, 0xA6);
RED4EXT_ASSERT_OFFSET(ReflectionProbeNode, brightnessEVClamp, 0xA7);
#else
RED4EXT_ASSERT_SIZE(ReflectionProbeNode, 0xB0);
#endif
} // namespace world
using worldReflectionProbeNode = world::ReflectionProbeNode;
} // namespace RED4ext

// clang-format on
