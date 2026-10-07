#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/EDecalRenderMode.hpp>
#include <RED4ext/Scripting/Natives/Generated/ERenderObjectType.hpp>
#include <RED4ext/Scripting/Natives/Generated/RenderDecalNormalsBlendingMode.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector3.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IVisualComponent.hpp>

namespace RED4ext
{
struct IMaterial;

namespace ent
{
struct __declspec(align(0x10)) DecalComponent : ent::IVisualComponent
{
    static constexpr const char* NAME = "entDecalComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk13C[0x150 - 0x13C]; // 13C
    Ref<IMaterial> material; // 150
    Vector3 visualScale; // 168
    float aspectRatio; // 174
    float scale; // 178
    float alpha; // 17C
    float normalThreshold; // 180
    float roughnessScale; // 184
    uint16_t orderNo; // 188
    RenderDecalNormalsBlendingMode normalsBlendingMode; // 18A
    ERenderObjectType surfaceType; // 18B
    EDecalRenderMode decalRenderMode; // 18C
    bool verticalFlip; // 18D
    bool horizontalFlip; // 18E
    bool isStretchingEnabled; // 18F
    bool shouldCollectWithRayTracing; // 190
    uint8_t unk191[0x1A0 - 0x191]; // 191
#else
    uint8_t unk140[0x150 - 0x140]; // 140
    Ref<IMaterial> material; // 150
    Vector3 visualScale; // 168
    float aspectRatio; // 174
    float scale; // 178
    float alpha; // 17C
    float normalThreshold; // 180
    float roughnessScale; // 184
    uint16_t orderNo; // 188
    RenderDecalNormalsBlendingMode normalsBlendingMode; // 18A
    ERenderObjectType surfaceType; // 18B
    EDecalRenderMode decalRenderMode; // 18C
    bool verticalFlip; // 18D
    bool horizontalFlip; // 18E
    bool isStretchingEnabled; // 18F
    bool shouldCollectWithRayTracing; // 190
    uint8_t unk191[0x1A0 - 0x191]; // 191
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(DecalComponent, 0x1A0);
RED4EXT_ASSERT_OFFSET(DecalComponent, material, 0x150);
RED4EXT_ASSERT_OFFSET(DecalComponent, visualScale, 0x168);
RED4EXT_ASSERT_OFFSET(DecalComponent, aspectRatio, 0x174);
RED4EXT_ASSERT_OFFSET(DecalComponent, scale, 0x178);
RED4EXT_ASSERT_OFFSET(DecalComponent, alpha, 0x17C);
RED4EXT_ASSERT_OFFSET(DecalComponent, normalThreshold, 0x180);
RED4EXT_ASSERT_OFFSET(DecalComponent, roughnessScale, 0x184);
RED4EXT_ASSERT_OFFSET(DecalComponent, orderNo, 0x188);
RED4EXT_ASSERT_OFFSET(DecalComponent, normalsBlendingMode, 0x18A);
RED4EXT_ASSERT_OFFSET(DecalComponent, surfaceType, 0x18B);
RED4EXT_ASSERT_OFFSET(DecalComponent, decalRenderMode, 0x18C);
RED4EXT_ASSERT_OFFSET(DecalComponent, verticalFlip, 0x18D);
RED4EXT_ASSERT_OFFSET(DecalComponent, horizontalFlip, 0x18E);
RED4EXT_ASSERT_OFFSET(DecalComponent, isStretchingEnabled, 0x18F);
RED4EXT_ASSERT_OFFSET(DecalComponent, shouldCollectWithRayTracing, 0x190);
#else
RED4EXT_ASSERT_SIZE(DecalComponent, 0x1A0);
#endif
} // namespace ent
using entDecalComponent = ent::DecalComponent;
} // namespace RED4ext

// clang-format on
