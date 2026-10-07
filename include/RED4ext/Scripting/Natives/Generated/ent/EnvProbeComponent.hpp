#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector3.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IVisualComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/env/UtilsNeighborMode.hpp>
#include <RED4ext/Scripting/Natives/Generated/env/UtilsReflectionProbeAmbientContributionMode.hpp>
#include <RED4ext/Scripting/Natives/Generated/rend/LightChannel.hpp>

namespace RED4ext
{
struct CReflectionProbeDataResource;

namespace ent
{
struct __declspec(align(0x10)) EnvProbeComponent : ent::IVisualComponent
{
    static constexpr const char* NAME = "entEnvProbeComponent";
    static constexpr const char* ALIAS = "EnvProbeComponent";

#ifdef __APPLE__
    uint8_t unk13C[0x150 - 0x13C]; // 13C
    RaRef<CReflectionProbeDataResource> probeDataRef; // 150
    Vector3 size; // 158
    Vector3 edgeScale; // 164
    float emissiveScale; // 170
    float streamingDistance; // 174
    float streamingHeight; // 178
    uint8_t unk17C[0x17E - 0x17C]; // 17C
    bool globalProbe; // 17E
    env::UtilsReflectionProbeAmbientContributionMode ambientMode; // 17F
    bool allInShadow; // 180
    bool hideSkyColor; // 181
    bool boxProjection; // 182
    uint8_t brightnessEVClamp; // 183
    uint8_t priority; // 184
    uint8_t blendRange; // 185
    rend::LightChannel lightChannels; // 186
    rend::LightChannel volumeChannels; // 188
    env::UtilsNeighborMode neighborMode; // 18A
    uint8_t unk18B[0x190 - 0x18B]; // 18B
#else
    uint8_t unk140[0x150 - 0x140]; // 140
    RaRef<CReflectionProbeDataResource> probeDataRef; // 150
    Vector3 size; // 158
    Vector3 edgeScale; // 164
    float emissiveScale; // 170
    float streamingDistance; // 174
    float streamingHeight; // 178
    uint8_t unk17C[0x17E - 0x17C]; // 17C
    bool globalProbe; // 17E
    env::UtilsReflectionProbeAmbientContributionMode ambientMode; // 17F
    bool allInShadow; // 180
    bool hideSkyColor; // 181
    bool boxProjection; // 182
    uint8_t brightnessEVClamp; // 183
    uint8_t priority; // 184
    uint8_t blendRange; // 185
    rend::LightChannel lightChannels; // 186
    rend::LightChannel volumeChannels; // 188
    env::UtilsNeighborMode neighborMode; // 18A
    uint8_t unk18B[0x190 - 0x18B]; // 18B
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(EnvProbeComponent, 0x190);
RED4EXT_ASSERT_OFFSET(EnvProbeComponent, probeDataRef, 0x150);
RED4EXT_ASSERT_OFFSET(EnvProbeComponent, size, 0x158);
RED4EXT_ASSERT_OFFSET(EnvProbeComponent, edgeScale, 0x164);
RED4EXT_ASSERT_OFFSET(EnvProbeComponent, emissiveScale, 0x170);
RED4EXT_ASSERT_OFFSET(EnvProbeComponent, streamingDistance, 0x174);
RED4EXT_ASSERT_OFFSET(EnvProbeComponent, streamingHeight, 0x178);
RED4EXT_ASSERT_OFFSET(EnvProbeComponent, globalProbe, 0x17E);
RED4EXT_ASSERT_OFFSET(EnvProbeComponent, ambientMode, 0x17F);
RED4EXT_ASSERT_OFFSET(EnvProbeComponent, allInShadow, 0x180);
RED4EXT_ASSERT_OFFSET(EnvProbeComponent, hideSkyColor, 0x181);
RED4EXT_ASSERT_OFFSET(EnvProbeComponent, boxProjection, 0x182);
RED4EXT_ASSERT_OFFSET(EnvProbeComponent, brightnessEVClamp, 0x183);
RED4EXT_ASSERT_OFFSET(EnvProbeComponent, priority, 0x184);
RED4EXT_ASSERT_OFFSET(EnvProbeComponent, blendRange, 0x185);
RED4EXT_ASSERT_OFFSET(EnvProbeComponent, lightChannels, 0x186);
RED4EXT_ASSERT_OFFSET(EnvProbeComponent, volumeChannels, 0x188);
RED4EXT_ASSERT_OFFSET(EnvProbeComponent, neighborMode, 0x18A);
#else
RED4EXT_ASSERT_SIZE(EnvProbeComponent, 0x190);
#endif
} // namespace ent
using entEnvProbeComponent = ent::EnvProbeComponent;
using EnvProbeComponent = ent::EnvProbeComponent;
} // namespace RED4ext

// clang-format on
