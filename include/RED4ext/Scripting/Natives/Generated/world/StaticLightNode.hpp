#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/Color.hpp>
#include <RED4ext/Scripting/Natives/Generated/EAreaLightShape.hpp>
#include <RED4ext/Scripting/Natives/Generated/EEnvColorGroup.hpp>
#include <RED4ext/Scripting/Natives/Generated/ELightShadowSoftnessMode.hpp>
#include <RED4ext/Scripting/Natives/Generated/ELightType.hpp>
#include <RED4ext/Scripting/Natives/Generated/ELightUnit.hpp>
#include <RED4ext/Scripting/Natives/Generated/rend/ContactShadowReciever.hpp>
#include <RED4ext/Scripting/Natives/Generated/rend/EPathTracingLightUsage.hpp>
#include <RED4ext/Scripting/Natives/Generated/rend/LightAttenuation.hpp>
#include <RED4ext/Scripting/Natives/Generated/rend/LightChannel.hpp>
#include <RED4ext/Scripting/Natives/Generated/rend/LightGroup.hpp>
#include <RED4ext/Scripting/Natives/Generated/rend/RayTracedShadowsPlatform.hpp>
#include <RED4ext/Scripting/Natives/Generated/rend/SLightFlickering.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Node.hpp>

namespace RED4ext
{
struct CIESDataResource;

namespace world
{
struct StaticLightNode : world::Node
{
    static constexpr const char* NAME = "worldStaticLightNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk32[0x38 - 0x32]; // 32
    Color color; // 38
    float temperature; // 3C
    float radius; // 40
    ELightUnit unit; // 44
    float intensity; // 48
    float EV; // 4C
    ELightType type; // 50
    uint8_t scaleGI; // 54
    uint8_t scaleEnvProbes; // 55
    uint8_t sceneSpecularScale; // 56
    uint8_t scaleVolFog; // 57
    int8_t roughnessBias; // 58
    bool useInTransparents; // 59
    bool useInParticles; // 5A
    bool sceneDiffuse; // 5B
    bool directional; // 5C
    bool clampAttenuation; // 5D
    rend::LightChannel lightChannel; // 5E
    rend::LightGroup group; // 60
    rend::LightAttenuation attenuation; // 61
    bool enableLocalShadows; // 62
    bool enableLocalShadowsForceStaticsOnly; // 63
    rend::ContactShadowReciever contactShadows; // 64
    uint8_t unk65[0x68 - 0x65]; // 65
    float shadowFadeDistance; // 68
    float shadowFadeRange; // 6C
    ELightShadowSoftnessMode shadowSoftnessMode; // 70
    rend::RayTracedShadowsPlatform rayTracedShadowsPlatform; // 74
    uint8_t unk75[0x78 - 0x75]; // 75
    float rayTracingLightSourceRadius; // 78
    float rayTracingContactShadowRange; // 7C
    rend::SLightFlickering flicker; // 80
    EEnvColorGroup envColorGroup; // 8C
    uint8_t colorGroupSaturation; // 8D
    uint8_t portalAngleCutoff; // 8E
    bool allowDistantLight; // 8F
    rend::EPathTracingLightUsage pathTracingLightUsage; // 90
    bool pathTracingOverrideScaleGI; // 91
    uint8_t unk92[0x94 - 0x92]; // 92
    float rayTracingIntensityScale; // 94
    float rtxdiShadowStartingDistance; // 98
    float innerAngle; // 9C
    float outerAngle; // A0
    float shadowAngle; // A4
    float shadowRadius; // A8
    float softness; // AC
    EAreaLightShape areaShape; // B0
    bool areaTwoSided; // B4
    bool spotCapsule; // B5
    uint8_t unkB6[0xB8 - 0xB6]; // B6
    float sourceRadius; // B8
    float capsuleLength; // BC
    float areaRectSideA; // C0
    float areaRectSideB; // C4
    RaRef<CIESDataResource> iesProfile; // C8
    float autoHideDistance; // D0
    uint8_t unkD4[0xD8 - 0xD4]; // D4
#else
    Color color; // 38
    float temperature; // 3C
    float radius; // 40
    ELightUnit unit; // 44
    float intensity; // 48
    float EV; // 4C
    ELightType type; // 50
    uint8_t scaleGI; // 54
    uint8_t scaleEnvProbes; // 55
    uint8_t sceneSpecularScale; // 56
    uint8_t scaleVolFog; // 57
    int8_t roughnessBias; // 58
    bool useInTransparents; // 59
    bool useInParticles; // 5A
    bool sceneDiffuse; // 5B
    bool directional; // 5C
    bool clampAttenuation; // 5D
    rend::LightChannel lightChannel; // 5E
    rend::LightGroup group; // 60
    rend::LightAttenuation attenuation; // 61
    bool enableLocalShadows; // 62
    bool enableLocalShadowsForceStaticsOnly; // 63
    rend::ContactShadowReciever contactShadows; // 64
    uint8_t unk65[0x68 - 0x65]; // 65
    float shadowFadeDistance; // 68
    float shadowFadeRange; // 6C
    ELightShadowSoftnessMode shadowSoftnessMode; // 70
    rend::RayTracedShadowsPlatform rayTracedShadowsPlatform; // 74
    uint8_t unk75[0x78 - 0x75]; // 75
    float rayTracingLightSourceRadius; // 78
    float rayTracingContactShadowRange; // 7C
    rend::SLightFlickering flicker; // 80
    EEnvColorGroup envColorGroup; // 8C
    uint8_t colorGroupSaturation; // 8D
    uint8_t portalAngleCutoff; // 8E
    bool allowDistantLight; // 8F
    rend::EPathTracingLightUsage pathTracingLightUsage; // 90
    bool pathTracingOverrideScaleGI; // 91
    uint8_t unk92[0x94 - 0x92]; // 92
    float rayTracingIntensityScale; // 94
    float rtxdiShadowStartingDistance; // 98
    float innerAngle; // 9C
    float outerAngle; // A0
    float shadowAngle; // A4
    float shadowRadius; // A8
    float softness; // AC
    EAreaLightShape areaShape; // B0
    bool areaTwoSided; // B4
    bool spotCapsule; // B5
    uint8_t unkB6[0xB8 - 0xB6]; // B6
    float sourceRadius; // B8
    float capsuleLength; // BC
    float areaRectSideA; // C0
    float areaRectSideB; // C4
    RaRef<CIESDataResource> iesProfile; // C8
    float autoHideDistance; // D0
    uint8_t unkD4[0xD8 - 0xD4]; // D4
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(StaticLightNode, 0xD8);
RED4EXT_ASSERT_OFFSET(StaticLightNode, color, 0x38);
RED4EXT_ASSERT_OFFSET(StaticLightNode, temperature, 0x3C);
RED4EXT_ASSERT_OFFSET(StaticLightNode, radius, 0x40);
RED4EXT_ASSERT_OFFSET(StaticLightNode, unit, 0x44);
RED4EXT_ASSERT_OFFSET(StaticLightNode, intensity, 0x48);
RED4EXT_ASSERT_OFFSET(StaticLightNode, EV, 0x4C);
RED4EXT_ASSERT_OFFSET(StaticLightNode, type, 0x50);
RED4EXT_ASSERT_OFFSET(StaticLightNode, scaleGI, 0x54);
RED4EXT_ASSERT_OFFSET(StaticLightNode, scaleEnvProbes, 0x55);
RED4EXT_ASSERT_OFFSET(StaticLightNode, sceneSpecularScale, 0x56);
RED4EXT_ASSERT_OFFSET(StaticLightNode, scaleVolFog, 0x57);
RED4EXT_ASSERT_OFFSET(StaticLightNode, roughnessBias, 0x58);
RED4EXT_ASSERT_OFFSET(StaticLightNode, useInTransparents, 0x59);
RED4EXT_ASSERT_OFFSET(StaticLightNode, useInParticles, 0x5A);
RED4EXT_ASSERT_OFFSET(StaticLightNode, sceneDiffuse, 0x5B);
RED4EXT_ASSERT_OFFSET(StaticLightNode, directional, 0x5C);
RED4EXT_ASSERT_OFFSET(StaticLightNode, clampAttenuation, 0x5D);
RED4EXT_ASSERT_OFFSET(StaticLightNode, lightChannel, 0x5E);
RED4EXT_ASSERT_OFFSET(StaticLightNode, group, 0x60);
RED4EXT_ASSERT_OFFSET(StaticLightNode, attenuation, 0x61);
RED4EXT_ASSERT_OFFSET(StaticLightNode, enableLocalShadows, 0x62);
RED4EXT_ASSERT_OFFSET(StaticLightNode, enableLocalShadowsForceStaticsOnly, 0x63);
RED4EXT_ASSERT_OFFSET(StaticLightNode, contactShadows, 0x64);
RED4EXT_ASSERT_OFFSET(StaticLightNode, shadowFadeDistance, 0x68);
RED4EXT_ASSERT_OFFSET(StaticLightNode, shadowFadeRange, 0x6C);
RED4EXT_ASSERT_OFFSET(StaticLightNode, shadowSoftnessMode, 0x70);
RED4EXT_ASSERT_OFFSET(StaticLightNode, rayTracedShadowsPlatform, 0x74);
RED4EXT_ASSERT_OFFSET(StaticLightNode, rayTracingLightSourceRadius, 0x78);
RED4EXT_ASSERT_OFFSET(StaticLightNode, rayTracingContactShadowRange, 0x7C);
RED4EXT_ASSERT_OFFSET(StaticLightNode, flicker, 0x80);
RED4EXT_ASSERT_OFFSET(StaticLightNode, envColorGroup, 0x8C);
RED4EXT_ASSERT_OFFSET(StaticLightNode, colorGroupSaturation, 0x8D);
RED4EXT_ASSERT_OFFSET(StaticLightNode, portalAngleCutoff, 0x8E);
RED4EXT_ASSERT_OFFSET(StaticLightNode, allowDistantLight, 0x8F);
RED4EXT_ASSERT_OFFSET(StaticLightNode, pathTracingLightUsage, 0x90);
RED4EXT_ASSERT_OFFSET(StaticLightNode, pathTracingOverrideScaleGI, 0x91);
RED4EXT_ASSERT_OFFSET(StaticLightNode, rayTracingIntensityScale, 0x94);
RED4EXT_ASSERT_OFFSET(StaticLightNode, rtxdiShadowStartingDistance, 0x98);
RED4EXT_ASSERT_OFFSET(StaticLightNode, innerAngle, 0x9C);
RED4EXT_ASSERT_OFFSET(StaticLightNode, outerAngle, 0xA0);
RED4EXT_ASSERT_OFFSET(StaticLightNode, shadowAngle, 0xA4);
RED4EXT_ASSERT_OFFSET(StaticLightNode, shadowRadius, 0xA8);
RED4EXT_ASSERT_OFFSET(StaticLightNode, softness, 0xAC);
RED4EXT_ASSERT_OFFSET(StaticLightNode, areaShape, 0xB0);
RED4EXT_ASSERT_OFFSET(StaticLightNode, areaTwoSided, 0xB4);
RED4EXT_ASSERT_OFFSET(StaticLightNode, spotCapsule, 0xB5);
RED4EXT_ASSERT_OFFSET(StaticLightNode, sourceRadius, 0xB8);
RED4EXT_ASSERT_OFFSET(StaticLightNode, capsuleLength, 0xBC);
RED4EXT_ASSERT_OFFSET(StaticLightNode, areaRectSideA, 0xC0);
RED4EXT_ASSERT_OFFSET(StaticLightNode, areaRectSideB, 0xC4);
RED4EXT_ASSERT_OFFSET(StaticLightNode, iesProfile, 0xC8);
RED4EXT_ASSERT_OFFSET(StaticLightNode, autoHideDistance, 0xD0);
#else
RED4EXT_ASSERT_SIZE(StaticLightNode, 0xD8);
#endif
} // namespace world
using worldStaticLightNode = world::StaticLightNode;
} // namespace RED4ext

// clang-format on
