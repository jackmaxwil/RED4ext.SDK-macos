#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/RenderSceneLayerMask.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector3.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Node.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/PrefabInteriorMapContribution.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/PrefabProxyMeshOnly.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/PrefabStreamingImportance.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/PrefabStreamingOcclusion.hpp>

namespace RED4ext
{
namespace world { struct Prefab; }
namespace world { struct PrefabInstanceData; }
namespace world { struct PrefabVariantsList; }

namespace world
{
struct PrefabNode : world::Node
{
    static constexpr const char* NAME = "worldPrefabNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk32[0x40 - 0x32]; // 32
    RaRef<world::Prefab> prefab; // 40
    Handle<world::PrefabInstanceData> instanceData; // 48
    Handle<world::PrefabVariantsList> enabledVariants; // 58
    world::PrefabProxyMeshOnly proxyMeshOnly; // 68
    bool proxyScaleOverride; // 69
    uint8_t unk6A[0x6C - 0x6A]; // 6A
    Vector3 proxyScale; // 6C
    bool canBeToggledInGame; // 78
    uint8_t unk79[0x7A - 0x79]; // 79
    bool noCollisions; // 7A
    bool applyMaxStreamingDistance; // 7B
    bool ignoreMeshEmbeddedOccluders; // 7C
    bool ignoreAllOccluders; // 7D
    uint8_t occluderAutoHideDistanceScale; // 7E
    bool enableRenderSceneLayerOverride; // 7F
    RenderSceneLayerMask renderSceneLayerMask; // 80
    world::PrefabStreamingImportance streamingImportance; // 81
    world::PrefabStreamingOcclusion streamingOcclusionOverride; // 82
    world::PrefabInteriorMapContribution interiorMapContribution; // 83
    uint8_t unk84[0x88 - 0x84]; // 84
#else
    uint8_t unk38[0x40 - 0x38]; // 38
    RaRef<world::Prefab> prefab; // 40
    Handle<world::PrefabInstanceData> instanceData; // 48
    Handle<world::PrefabVariantsList> enabledVariants; // 58
    world::PrefabProxyMeshOnly proxyMeshOnly; // 68
    bool proxyScaleOverride; // 69
    uint8_t unk6A[0x6C - 0x6A]; // 6A
    Vector3 proxyScale; // 6C
    bool canBeToggledInGame; // 78
    uint8_t unk79[0x7A - 0x79]; // 79
    bool noCollisions; // 7A
    bool applyMaxStreamingDistance; // 7B
    bool ignoreMeshEmbeddedOccluders; // 7C
    bool ignoreAllOccluders; // 7D
    uint8_t occluderAutoHideDistanceScale; // 7E
    bool enableRenderSceneLayerOverride; // 7F
    RenderSceneLayerMask renderSceneLayerMask; // 80
    world::PrefabStreamingImportance streamingImportance; // 81
    world::PrefabStreamingOcclusion streamingOcclusionOverride; // 82
    world::PrefabInteriorMapContribution interiorMapContribution; // 83
    uint8_t unk84[0x88 - 0x84]; // 84
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PrefabNode, 0x88);
RED4EXT_ASSERT_OFFSET(PrefabNode, prefab, 0x40);
RED4EXT_ASSERT_OFFSET(PrefabNode, instanceData, 0x48);
RED4EXT_ASSERT_OFFSET(PrefabNode, enabledVariants, 0x58);
RED4EXT_ASSERT_OFFSET(PrefabNode, proxyMeshOnly, 0x68);
RED4EXT_ASSERT_OFFSET(PrefabNode, proxyScaleOverride, 0x69);
RED4EXT_ASSERT_OFFSET(PrefabNode, proxyScale, 0x6C);
RED4EXT_ASSERT_OFFSET(PrefabNode, canBeToggledInGame, 0x78);
RED4EXT_ASSERT_OFFSET(PrefabNode, noCollisions, 0x7A);
RED4EXT_ASSERT_OFFSET(PrefabNode, applyMaxStreamingDistance, 0x7B);
RED4EXT_ASSERT_OFFSET(PrefabNode, ignoreMeshEmbeddedOccluders, 0x7C);
RED4EXT_ASSERT_OFFSET(PrefabNode, ignoreAllOccluders, 0x7D);
RED4EXT_ASSERT_OFFSET(PrefabNode, occluderAutoHideDistanceScale, 0x7E);
RED4EXT_ASSERT_OFFSET(PrefabNode, enableRenderSceneLayerOverride, 0x7F);
RED4EXT_ASSERT_OFFSET(PrefabNode, renderSceneLayerMask, 0x80);
RED4EXT_ASSERT_OFFSET(PrefabNode, streamingImportance, 0x81);
RED4EXT_ASSERT_OFFSET(PrefabNode, streamingOcclusionOverride, 0x82);
RED4EXT_ASSERT_OFFSET(PrefabNode, interiorMapContribution, 0x83);
#else
RED4EXT_ASSERT_SIZE(PrefabNode, 0x88);
#endif
} // namespace world
using worldPrefabNode = world::PrefabNode;
} // namespace RED4ext

// clang-format on
