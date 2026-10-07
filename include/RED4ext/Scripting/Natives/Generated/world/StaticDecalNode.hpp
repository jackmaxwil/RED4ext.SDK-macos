#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/EDecalRenderMode.hpp>
#include <RED4ext/Scripting/Natives/Generated/ERenderObjectType.hpp>
#include <RED4ext/Scripting/Natives/Generated/HDRColor.hpp>
#include <RED4ext/Scripting/Natives/Generated/RenderDecalNormalsBlendingMode.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Node.hpp>

namespace RED4ext
{
struct IMaterial;

namespace world
{
struct __declspec(align(0x10)) StaticDecalNode : world::Node
{
    static constexpr const char* NAME = "worldStaticDecalNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk32[0x38 - 0x32]; // 32
    RaRef<IMaterial> material; // 38
    HDRColor diffuseColorScale; // 40
    float autoHideDistance; // 50
    float forcedAutoHideDistance; // 54
    float alpha; // 58
    float normalThreshold; // 5C
    float roughnessScale; // 60
    uint16_t orderNo; // 64
    ERenderObjectType surfaceType; // 66
    EDecalRenderMode decalRenderMode; // 67
    RenderDecalNormalsBlendingMode normalsBlendingMode; // 68
    uint8_t decalNodeVersion; // 69
    bool isStretchingEnabled; // 6A
    bool verticalFlip; // 6B
    bool horizontalFlip; // 6C
    bool enableNormalTreshold; // 6D
    bool shouldCollectWithRayTracing; // 6E
    uint8_t unk6F[0x70 - 0x6F]; // 6F
#else
    RaRef<IMaterial> material; // 38
    HDRColor diffuseColorScale; // 40
    float autoHideDistance; // 50
    float forcedAutoHideDistance; // 54
    float alpha; // 58
    float normalThreshold; // 5C
    float roughnessScale; // 60
    uint16_t orderNo; // 64
    ERenderObjectType surfaceType; // 66
    EDecalRenderMode decalRenderMode; // 67
    RenderDecalNormalsBlendingMode normalsBlendingMode; // 68
    uint8_t decalNodeVersion; // 69
    bool isStretchingEnabled; // 6A
    bool verticalFlip; // 6B
    bool horizontalFlip; // 6C
    bool enableNormalTreshold; // 6D
    bool shouldCollectWithRayTracing; // 6E
    uint8_t unk6F[0x70 - 0x6F]; // 6F
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(StaticDecalNode, 0x70);
RED4EXT_ASSERT_OFFSET(StaticDecalNode, material, 0x38);
RED4EXT_ASSERT_OFFSET(StaticDecalNode, diffuseColorScale, 0x40);
RED4EXT_ASSERT_OFFSET(StaticDecalNode, autoHideDistance, 0x50);
RED4EXT_ASSERT_OFFSET(StaticDecalNode, forcedAutoHideDistance, 0x54);
RED4EXT_ASSERT_OFFSET(StaticDecalNode, alpha, 0x58);
RED4EXT_ASSERT_OFFSET(StaticDecalNode, normalThreshold, 0x5C);
RED4EXT_ASSERT_OFFSET(StaticDecalNode, roughnessScale, 0x60);
RED4EXT_ASSERT_OFFSET(StaticDecalNode, orderNo, 0x64);
RED4EXT_ASSERT_OFFSET(StaticDecalNode, surfaceType, 0x66);
RED4EXT_ASSERT_OFFSET(StaticDecalNode, decalRenderMode, 0x67);
RED4EXT_ASSERT_OFFSET(StaticDecalNode, normalsBlendingMode, 0x68);
RED4EXT_ASSERT_OFFSET(StaticDecalNode, decalNodeVersion, 0x69);
RED4EXT_ASSERT_OFFSET(StaticDecalNode, isStretchingEnabled, 0x6A);
RED4EXT_ASSERT_OFFSET(StaticDecalNode, verticalFlip, 0x6B);
RED4EXT_ASSERT_OFFSET(StaticDecalNode, horizontalFlip, 0x6C);
RED4EXT_ASSERT_OFFSET(StaticDecalNode, enableNormalTreshold, 0x6D);
RED4EXT_ASSERT_OFFSET(StaticDecalNode, shouldCollectWithRayTracing, 0x6E);
#else
RED4EXT_ASSERT_SIZE(StaticDecalNode, 0x70);
#endif
} // namespace world
using worldStaticDecalNode = world::StaticDecalNode;
} // namespace RED4ext

// clang-format on
