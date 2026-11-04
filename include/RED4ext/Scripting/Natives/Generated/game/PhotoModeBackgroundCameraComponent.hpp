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

namespace RED4ext
{
struct DynamicTexture;
namespace world { struct EnvironmentAreaParameters; }

namespace game
{
struct __declspec(align(0x10)) PhotoModeBackgroundCameraComponent : ent::BaseCameraComponent
{
    static constexpr const char* NAME = "gamePhotoModeBackgroundCameraComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    RaRef<DynamicTexture> dynamicTextureRes; // 1D8
    uint8_t unk1E0[0x1F8 - 0x1E0]; // 1E0
    CName virtualCameraName; // 1F8
    Ref<world::EnvironmentAreaParameters> env; // 200
    WorldRenderAreaSettings params; // 218
    uint8_t unk228[0x900 - 0x228]; // 228
    float streamingDistance; // 900
    Color backgroundColor; // 904
    float depthCutDistance; // 908
    RenderSceneLayer renderSceneLayer; // 90C
    bool overrideBackgroundColor; // 90D
    uint8_t unk90E[0x910 - 0x90E]; // 90E
#else
    RaRef<DynamicTexture> dynamicTextureRes; // 1E0
    uint8_t unk1E8[0x200 - 0x1E8]; // 1E8
    CName virtualCameraName; // 200
    Ref<world::EnvironmentAreaParameters> env; // 208
    WorldRenderAreaSettings params; // 220
    uint8_t unk230[0x950 - 0x230]; // 230
    float streamingDistance; // 950
    Color backgroundColor; // 954
    float depthCutDistance; // 958
    RenderSceneLayer renderSceneLayer; // 95C
    bool overrideBackgroundColor; // 95D
    uint8_t unk95E[0x960 - 0x95E]; // 95E
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PhotoModeBackgroundCameraComponent, 0x910);
RED4EXT_ASSERT_OFFSET(PhotoModeBackgroundCameraComponent, dynamicTextureRes, 0x1D8);
RED4EXT_ASSERT_OFFSET(PhotoModeBackgroundCameraComponent, virtualCameraName, 0x1F8);
RED4EXT_ASSERT_OFFSET(PhotoModeBackgroundCameraComponent, env, 0x200);
RED4EXT_ASSERT_OFFSET(PhotoModeBackgroundCameraComponent, params, 0x218);
RED4EXT_ASSERT_OFFSET(PhotoModeBackgroundCameraComponent, streamingDistance, 0x900);
RED4EXT_ASSERT_OFFSET(PhotoModeBackgroundCameraComponent, backgroundColor, 0x904);
RED4EXT_ASSERT_OFFSET(PhotoModeBackgroundCameraComponent, depthCutDistance, 0x908);
RED4EXT_ASSERT_OFFSET(PhotoModeBackgroundCameraComponent, renderSceneLayer, 0x90C);
RED4EXT_ASSERT_OFFSET(PhotoModeBackgroundCameraComponent, overrideBackgroundColor, 0x90D);
#else
RED4EXT_ASSERT_SIZE(PhotoModeBackgroundCameraComponent, 0x960);
#endif
} // namespace game
using gamePhotoModeBackgroundCameraComponent = game::PhotoModeBackgroundCameraComponent;
} // namespace RED4ext

// clang-format on
