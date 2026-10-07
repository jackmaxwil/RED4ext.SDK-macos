#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/Color.hpp>
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
    CName virtualCameraName; // 258
    Ref<world::EnvironmentAreaParameters> env; // 260
    WorldRenderAreaSettings params; // 278
    ent::RenderToTextureMode renderingMode; // 288
    uint8_t unk289[0x9D4 - 0x289]; // 289
    float streamingDistance; // 9D4
    float aspectRatio; // 9D8
    Color backgroundColor; // 9DC
    float depthCutDistance; // 9E0
    RenderSceneLayer renderSceneLayer; // 9E4
    bool overrideBackgroundColor; // 9E5
    ent::RenderToTextureFeatures features; // 9E6
    uint8_t unk9EE[0xA00 - 0x9EE]; // 9EE
#else
    RaRef<DynamicTexture> dynamicTextureRes; // 1E0
    uint8_t unk1E8[0x1F8 - 0x1E8]; // 1E8
    Ref<DynamicTexture> depthDynamicTextureRes; // 1F8
    Ref<DynamicTexture> albedoDynamicTextureRes; // 210
    Ref<DynamicTexture> normalsDynamicTextureRes; // 228
    Ref<DynamicTexture> particlesDynamicTextureRes; // 240
    uint32_t resolutionWidth; // 258
    uint32_t resolutionHeight; // 25C
    CName virtualCameraName; // 260
    Ref<world::EnvironmentAreaParameters> env; // 268
    WorldRenderAreaSettings params; // 280
    ent::RenderToTextureMode renderingMode; // 290
    uint8_t unk291[0x9E4 - 0x291]; // 291
    float streamingDistance; // 9E4
    float aspectRatio; // 9E8
    Color backgroundColor; // 9EC
    float depthCutDistance; // 9F0
    RenderSceneLayer renderSceneLayer; // 9F4
    bool overrideBackgroundColor; // 9F5
    ent::RenderToTextureFeatures features; // 9F6
    uint8_t unk9FE[0xA10 - 0x9FE]; // 9FE
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(RenderToTextureCameraComponent, 0xA00);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, dynamicTextureRes, 0x1D8);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, depthDynamicTextureRes, 0x1F0);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, albedoDynamicTextureRes, 0x208);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, normalsDynamicTextureRes, 0x220);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, particlesDynamicTextureRes, 0x238);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, resolutionWidth, 0x250);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, resolutionHeight, 0x254);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, virtualCameraName, 0x258);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, env, 0x260);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, params, 0x278);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, renderingMode, 0x288);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, streamingDistance, 0x9D4);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, aspectRatio, 0x9D8);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, backgroundColor, 0x9DC);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, depthCutDistance, 0x9E0);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, renderSceneLayer, 0x9E4);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, overrideBackgroundColor, 0x9E5);
RED4EXT_ASSERT_OFFSET(RenderToTextureCameraComponent, features, 0x9E6);
#else
RED4EXT_ASSERT_SIZE(RenderToTextureCameraComponent, 0xA10);
#endif
} // namespace ent
using entRenderToTextureCameraComponent = ent::RenderToTextureCameraComponent;
} // namespace RED4ext

// clang-format on
