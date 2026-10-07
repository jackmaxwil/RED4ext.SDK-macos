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
#include <RED4ext/Scripting/Natives/Generated/ent/IVisualComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/rend/ContactShadowReciever.hpp>
#include <RED4ext/Scripting/Natives/Generated/rend/EPathTracingLightUsage.hpp>
#include <RED4ext/Scripting/Natives/Generated/rend/LightAttenuation.hpp>
#include <RED4ext/Scripting/Natives/Generated/rend/LightChannel.hpp>
#include <RED4ext/Scripting/Natives/Generated/rend/LightGroup.hpp>
#include <RED4ext/Scripting/Natives/Generated/rend/RayTracedShadowsPlatform.hpp>
#include <RED4ext/Scripting/Natives/Generated/rend/SLightFlickering.hpp>

namespace RED4ext
{
struct CIESDataResource;

namespace ent
{
struct __declspec(align(0x10)) LightComponent : ent::IVisualComponent
{
    static constexpr const char* NAME = "entLightComponent";
    static constexpr const char* ALIAS = "LightComponent";

#ifdef __APPLE__
    uint8_t unk13C[0x140 - 0x13C]; // 13C
    Color color; // 140
    float temperature; // 144
    float radius; // 148
    ELightUnit unit; // 14C
    float intensity; // 150
    float EV; // 154
    ELightType type; // 158
    uint8_t scaleGI; // 15C
    uint8_t scaleEnvProbes; // 15D
    uint8_t sceneSpecularScale; // 15E
    uint8_t scaleVolFog; // 15F
    int8_t roughnessBias; // 160
    bool useInTransparents; // 161
    bool useInParticles; // 162
    bool sceneDiffuse; // 163
    bool directional; // 164
    bool clampAttenuation; // 165
    rend::LightChannel lightChannel; // 166
    rend::LightGroup group; // 168
    rend::LightAttenuation attenuation; // 169
    bool enableLocalShadows; // 16A
    bool enableLocalShadowsForceStaticsOnly; // 16B
    rend::ContactShadowReciever contactShadows; // 16C
    uint8_t unk16D[0x170 - 0x16D]; // 16D
    float shadowFadeDistance; // 170
    float shadowFadeRange; // 174
    ELightShadowSoftnessMode shadowSoftnessMode; // 178
    rend::RayTracedShadowsPlatform rayTracedShadowsPlatform; // 17C
    uint8_t unk17D[0x180 - 0x17D]; // 17D
    float rayTracingLightSourceRadius; // 180
    float rayTracingContactShadowRange; // 184
    rend::SLightFlickering flicker; // 188
    EEnvColorGroup envColorGroup; // 194
    uint8_t colorGroupSaturation; // 195
    uint8_t portalAngleCutoff; // 196
    bool allowDistantLight; // 197
    rend::EPathTracingLightUsage pathTracingLightUsage; // 198
    bool pathTracingOverrideScaleGI; // 199
    uint8_t unk19A[0x19C - 0x19A]; // 19A
    float rayTracingIntensityScale; // 19C
    float rtxdiShadowStartingDistance; // 1A0
    float innerAngle; // 1A4
    float outerAngle; // 1A8
    float shadowAngle; // 1AC
    float shadowRadius; // 1B0
    float softness; // 1B4
    EAreaLightShape areaShape; // 1B8
    bool areaTwoSided; // 1BC
    bool spotCapsule; // 1BD
    uint8_t unk1BE[0x1C0 - 0x1BE]; // 1BE
    float sourceRadius; // 1C0
    float capsuleLength; // 1C4
    float areaRectSideA; // 1C8
    float areaRectSideB; // 1CC
    RaRef<CIESDataResource> iesProfile; // 1D0
    uint8_t unk1D8[0x1F8 - 0x1D8]; // 1D8
#else
    Color color; // 140
    float temperature; // 144
    float radius; // 148
    ELightUnit unit; // 14C
    float intensity; // 150
    float EV; // 154
    ELightType type; // 158
    uint8_t scaleGI; // 15C
    uint8_t scaleEnvProbes; // 15D
    uint8_t sceneSpecularScale; // 15E
    uint8_t scaleVolFog; // 15F
    int8_t roughnessBias; // 160
    bool useInTransparents; // 161
    bool useInParticles; // 162
    bool sceneDiffuse; // 163
    bool directional; // 164
    bool clampAttenuation; // 165
    rend::LightChannel lightChannel; // 166
    rend::LightGroup group; // 168
    rend::LightAttenuation attenuation; // 169
    bool enableLocalShadows; // 16A
    bool enableLocalShadowsForceStaticsOnly; // 16B
    rend::ContactShadowReciever contactShadows; // 16C
    uint8_t unk16D[0x170 - 0x16D]; // 16D
    float shadowFadeDistance; // 170
    float shadowFadeRange; // 174
    ELightShadowSoftnessMode shadowSoftnessMode; // 178
    rend::RayTracedShadowsPlatform rayTracedShadowsPlatform; // 17C
    uint8_t unk17D[0x180 - 0x17D]; // 17D
    float rayTracingLightSourceRadius; // 180
    float rayTracingContactShadowRange; // 184
    rend::SLightFlickering flicker; // 188
    EEnvColorGroup envColorGroup; // 194
    uint8_t colorGroupSaturation; // 195
    uint8_t portalAngleCutoff; // 196
    bool allowDistantLight; // 197
    rend::EPathTracingLightUsage pathTracingLightUsage; // 198
    bool pathTracingOverrideScaleGI; // 199
    uint8_t unk19A[0x19C - 0x19A]; // 19A
    float rayTracingIntensityScale; // 19C
    float rtxdiShadowStartingDistance; // 1A0
    float innerAngle; // 1A4
    float outerAngle; // 1A8
    float shadowAngle; // 1AC
    float shadowRadius; // 1B0
    float softness; // 1B4
    EAreaLightShape areaShape; // 1B8
    bool areaTwoSided; // 1BC
    bool spotCapsule; // 1BD
    uint8_t unk1BE[0x1C0 - 0x1BE]; // 1BE
    float sourceRadius; // 1C0
    float capsuleLength; // 1C4
    float areaRectSideA; // 1C8
    float areaRectSideB; // 1CC
    RaRef<CIESDataResource> iesProfile; // 1D0
    uint8_t unk1D8[0x200 - 0x1D8]; // 1D8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(LightComponent, 0x200);
RED4EXT_ASSERT_OFFSET(LightComponent, color, 0x140);
RED4EXT_ASSERT_OFFSET(LightComponent, temperature, 0x144);
RED4EXT_ASSERT_OFFSET(LightComponent, radius, 0x148);
RED4EXT_ASSERT_OFFSET(LightComponent, unit, 0x14C);
RED4EXT_ASSERT_OFFSET(LightComponent, intensity, 0x150);
RED4EXT_ASSERT_OFFSET(LightComponent, EV, 0x154);
RED4EXT_ASSERT_OFFSET(LightComponent, type, 0x158);
RED4EXT_ASSERT_OFFSET(LightComponent, scaleGI, 0x15C);
RED4EXT_ASSERT_OFFSET(LightComponent, scaleEnvProbes, 0x15D);
RED4EXT_ASSERT_OFFSET(LightComponent, sceneSpecularScale, 0x15E);
RED4EXT_ASSERT_OFFSET(LightComponent, scaleVolFog, 0x15F);
RED4EXT_ASSERT_OFFSET(LightComponent, roughnessBias, 0x160);
RED4EXT_ASSERT_OFFSET(LightComponent, useInTransparents, 0x161);
RED4EXT_ASSERT_OFFSET(LightComponent, useInParticles, 0x162);
RED4EXT_ASSERT_OFFSET(LightComponent, sceneDiffuse, 0x163);
RED4EXT_ASSERT_OFFSET(LightComponent, directional, 0x164);
RED4EXT_ASSERT_OFFSET(LightComponent, clampAttenuation, 0x165);
RED4EXT_ASSERT_OFFSET(LightComponent, lightChannel, 0x166);
RED4EXT_ASSERT_OFFSET(LightComponent, group, 0x168);
RED4EXT_ASSERT_OFFSET(LightComponent, attenuation, 0x169);
RED4EXT_ASSERT_OFFSET(LightComponent, enableLocalShadows, 0x16A);
RED4EXT_ASSERT_OFFSET(LightComponent, enableLocalShadowsForceStaticsOnly, 0x16B);
RED4EXT_ASSERT_OFFSET(LightComponent, contactShadows, 0x16C);
RED4EXT_ASSERT_OFFSET(LightComponent, shadowFadeDistance, 0x170);
RED4EXT_ASSERT_OFFSET(LightComponent, shadowFadeRange, 0x174);
RED4EXT_ASSERT_OFFSET(LightComponent, shadowSoftnessMode, 0x178);
RED4EXT_ASSERT_OFFSET(LightComponent, rayTracedShadowsPlatform, 0x17C);
RED4EXT_ASSERT_OFFSET(LightComponent, rayTracingLightSourceRadius, 0x180);
RED4EXT_ASSERT_OFFSET(LightComponent, rayTracingContactShadowRange, 0x184);
RED4EXT_ASSERT_OFFSET(LightComponent, flicker, 0x188);
RED4EXT_ASSERT_OFFSET(LightComponent, envColorGroup, 0x194);
RED4EXT_ASSERT_OFFSET(LightComponent, colorGroupSaturation, 0x195);
RED4EXT_ASSERT_OFFSET(LightComponent, portalAngleCutoff, 0x196);
RED4EXT_ASSERT_OFFSET(LightComponent, allowDistantLight, 0x197);
RED4EXT_ASSERT_OFFSET(LightComponent, pathTracingLightUsage, 0x198);
RED4EXT_ASSERT_OFFSET(LightComponent, pathTracingOverrideScaleGI, 0x199);
RED4EXT_ASSERT_OFFSET(LightComponent, rayTracingIntensityScale, 0x19C);
RED4EXT_ASSERT_OFFSET(LightComponent, rtxdiShadowStartingDistance, 0x1A0);
RED4EXT_ASSERT_OFFSET(LightComponent, innerAngle, 0x1A4);
RED4EXT_ASSERT_OFFSET(LightComponent, outerAngle, 0x1A8);
RED4EXT_ASSERT_OFFSET(LightComponent, shadowAngle, 0x1AC);
RED4EXT_ASSERT_OFFSET(LightComponent, shadowRadius, 0x1B0);
RED4EXT_ASSERT_OFFSET(LightComponent, softness, 0x1B4);
RED4EXT_ASSERT_OFFSET(LightComponent, areaShape, 0x1B8);
RED4EXT_ASSERT_OFFSET(LightComponent, areaTwoSided, 0x1BC);
RED4EXT_ASSERT_OFFSET(LightComponent, spotCapsule, 0x1BD);
RED4EXT_ASSERT_OFFSET(LightComponent, sourceRadius, 0x1C0);
RED4EXT_ASSERT_OFFSET(LightComponent, capsuleLength, 0x1C4);
RED4EXT_ASSERT_OFFSET(LightComponent, areaRectSideA, 0x1C8);
RED4EXT_ASSERT_OFFSET(LightComponent, areaRectSideB, 0x1CC);
RED4EXT_ASSERT_OFFSET(LightComponent, iesProfile, 0x1D0);
#else
RED4EXT_ASSERT_SIZE(LightComponent, 0x200);
#endif
} // namespace ent
using entLightComponent = ent::LightComponent;
using LightComponent = ent::LightComponent;
} // namespace RED4ext

// clang-format on
