#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/Color.hpp>
#include <RED4ext/Scripting/Natives/Generated/ECameraRenderingQuality.hpp>
#include <RED4ext/Scripting/Natives/Generated/RenderSceneLayer.hpp>
#include <RED4ext/Scripting/Natives/Generated/WorldRenderAreaSettings.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/BaseCameraComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/RenderToTextureFeatures.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/RenderToTextureMode.hpp>

namespace RED4ext
{
struct DynamicTexture;
namespace world { struct EnvironmentAreaParameters; }

namespace ent
{
struct __declspec(align(0x10)) RenderToTextureCameraComponent : ent::BaseCameraComponent
{
    static constexpr const char* NAME = "entRenderToTextureCameraComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    RaRef<DynamicTexture> dynamicTextureRes; // 1D8
    uint8_t unk1E0[0x1F0 - 0x1E0]; // 1E0
    Ref<DynamicTexture> depthDynamicTextureRes; // 1F0
    Ref<DynamicTexture> albedoDynamicTextureRes; // 208
    Ref<DynamicTexture> normalsDynamicTextureRes; // 220
    Ref<DynamicTexture> particlesDynamicTextureRes; // 238
    uint32_t resolutionWidth; // 250
    uint32_t resolutionHeight; // 254
    uint8_t unk258[0x268 - 0x258]; // 258
    CName virtualCameraName; // 268
    Ref<world::EnvironmentAreaParameters> env; // 270
    WorldRenderAreaSettings params; // 288
    ent::RenderToTextureMode renderingMode; // 298
    uint8_t unk299[0x29C - 0x299]; // 299
    ECameraRenderingQuality renderingQuality; // 29C
    uint8_t unk2A0[0x9E4 - 0x2A0]; // 2A0
    float streamingDistance; // 9E4
    float aspectRatio; // 9E8
    Color backgroundColor; // 9EC
    float depthCutDistance; // 9F0
    RenderSceneLayer renderSceneLayer; // 9F4
    bool overrideBackgroundColor; // 9F5
    uint8_t unk9F6[0x9F8 - 0x9F6]; // 9F6
    uint32_t renderFrequency; // 9F8
    uint32_t renderPhase; // 9FC
    uint8_t unkA00[0xA01 - 0xA00]; // A00
    ent::RenderToTextureFeatures features; // A01
    uint8_t unkA0C[0xA20 - 0xA0C]; // A0C
#else
    RaRef<DynamicTexture> dynamicTextureRes; // 1E0
    uint8_t unk1E8[0x1F8 - 0x1E8]; // 1E8
    Ref<DynamicTexture> depthDynamicTextureRes; // 1F8
    Ref<DynamicTexture> albedoDynamicTextureRes; // 210
    Ref<DynamicTexture> normalsDynamicTextureRes; // 228
    Ref<DynamicTexture> particlesDynamicTextureRes; // 240
    uint32_t resolutionWidth; // 258
    uint32_t resolutionHeight; // 25C
    uint8_t unk260[0x270 - 0x260]; // 260
    CName virtualCameraName; // 270
    Ref<world::EnvironmentAreaParameters> env; // 278
    WorldRenderAreaSettings params; // 290
    ent::RenderToTextureMode renderingMode; // 2A0
    uint8_t unk2A1[0x2A4 - 0x2A1]; // 2A1
    ECameraRenderingQuality renderingQuality; // 2A4
    uint8_t unk2A8[0xA34 - 0x2A8]; // 2A8
    float streamingDistance; // A34
    float aspectRatio; // A38
    Color backgroundColor; // A3C
    float depthCutDistance; // A40
    RenderSceneLayer renderSceneLayer; // A44
    bool overrideBackgroundColor; // A45
    uint8_t unkA46[0xA48 - 0xA46]; // A46
    uint32_t renderFrequency; // A48
    uint32_t renderPhase; // A4C
    uint8_t unkA50[0xA51 - 0xA50]; // A50
    ent::RenderToTextureFeatures features; // A51
    uint8_t unkA5C[0xA70 - 0xA5C]; // A5C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(RenderToTextureCameraComponent, 0xA20);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, dynamicTextureRes, 0x1D8);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, depthDynamicTextureRes, 0x1F0);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, albedoDynamicTextureRes, 0x208);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, normalsDynamicTextureRes, 0x220);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, particlesDynamicTextureRes, 0x238);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, resolutionWidth, 0x250);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, resolutionHeight, 0x254);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, virtualCameraName, 0x268);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, env, 0x270);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, params, 0x288);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, renderingMode, 0x298);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, renderingQuality, 0x29C);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, streamingDistance, 0x9E4);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, aspectRatio, 0x9E8);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, backgroundColor, 0x9EC);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, depthCutDistance, 0x9F0);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, renderSceneLayer, 0x9F4);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, overrideBackgroundColor, 0x9F5);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, renderFrequency, 0x9F8);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, renderPhase, 0x9FC);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, features, 0xA01);
#else
RED4EXT_ASSERT_SIZE(RenderToTextureCameraComponent, 0xA70);
#endif
} // namespace ent
using entRenderToTextureCameraComponent = ent::RenderToTextureCameraComponent;
} // namespace RED4ext

// clang-format on
