#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/Box.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector3.hpp>
#include <RED4ext/Scripting/Natives/Generated/res/StreamedResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/PrefabInteriorMapContribution.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/PrefabMinimapContribution.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/PrefabOwnership.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/PrefabStreamingImportance.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/PrefabStreamingOcclusion.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/PrefabType.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/ProxyMeshBuildParams.hpp>

namespace RED4ext
{
struct CMesh;
struct Multilayer_Setup;
namespace world { struct AutoFoliageMapping; }
namespace world { struct EnvironmentDefinition; }
namespace world { struct NodesGroup; }
namespace world { struct PrefabMetadata; }
namespace world { struct PrefabVariantsList; }

namespace world
{
struct __declspec(align(0x10)) Prefab : res::StreamedResource
{
    static constexpr const char* NAME = "worldPrefab";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    RaRef<world::EnvironmentDefinition> environmentDefinition; // 40
    RaRef<Multilayer_Setup> terrainMultilayerSetup; // 48
    RaRef<world::AutoFoliageMapping> foliageBrushToTerrainLayerMapping; // 50
    RaRef<CMesh> proxyMesh; // 58
    Vector3 proxyScale; // 60
    float maxProxyStreamingDistance; // 6C
    float proxyDistanceFactor; // 70
    float averageNodeDiagonal; // 74
    RaRef<world::Prefab> booleanProxyHelper; // 78
    RaRef<world::Prefab> proxyLimiterHelper; // 80
    RaRef<CMesh> customProxyMeshHelper; // 88
    Handle<world::PrefabVariantsList> defaultVariants; // 90
    Handle<world::NodesGroup> mainGroup; // A0
    uint8_t unkB0[0xE0 - 0xB0]; // B0
    world::ProxyMeshBuildParams proxyMeshBuildParams; // E0
    world::PrefabOwnership teamOwnership; // 1C8
    world::PrefabStreamingOcclusion streamingOcclusion; // 1C9
    world::PrefabStreamingImportance streamingImportance; // 1CA
    world::PrefabType type; // 1CB
    bool isLocked; // 1CC
    uint8_t unk1CD[0x1D0 - 0x1CD]; // 1CD
    Box maxBounds; // 1D0
    bool isMerged; // 1F0
    bool isProxyMeshOnly; // 1F1
    bool boostInnerNodesToProxyDistance; // 1F2
    bool overrideStreamingPosWithBBoxCenter; // 1F3
    uint8_t unk1F4[0x1F5 - 0x1F4]; // 1F4
    bool ignoreMeshEmbeddedOccluders; // 1F5
    bool ignoreAllOccluders; // 1F6
    bool isTerrainPrefab; // 1F7
    bool excludeOnConsole; // 1F8
    bool excludeOnNextGenConsoles; // 1F9
    world::PrefabMinimapContribution minimapContribution; // 1FA
    world::PrefabInteriorMapContribution interiorMapContribution; // 1FB
    uint8_t unk1FC[0x210 - 0x1FC]; // 1FC
    CRUID prefabUniqueId; // 210
    uint8_t unk218[0x370 - 0x218]; // 218
    DynArray<Handle<world::PrefabMetadata>> metadataArray; // 370
#else
    RaRef<world::EnvironmentDefinition> environmentDefinition; // 40
    RaRef<Multilayer_Setup> terrainMultilayerSetup; // 48
    RaRef<world::AutoFoliageMapping> foliageBrushToTerrainLayerMapping; // 50
    RaRef<CMesh> proxyMesh; // 58
    Vector3 proxyScale; // 60
    float maxProxyStreamingDistance; // 6C
    float proxyDistanceFactor; // 70
    float averageNodeDiagonal; // 74
    RaRef<world::Prefab> booleanProxyHelper; // 78
    RaRef<world::Prefab> proxyLimiterHelper; // 80
    RaRef<CMesh> customProxyMeshHelper; // 88
    Handle<world::PrefabVariantsList> defaultVariants; // 90
    Handle<world::NodesGroup> mainGroup; // A0
    uint8_t unkB0[0xE0 - 0xB0]; // B0
    world::ProxyMeshBuildParams proxyMeshBuildParams; // E0
    world::PrefabOwnership teamOwnership; // 1C8
    world::PrefabStreamingOcclusion streamingOcclusion; // 1C9
    world::PrefabStreamingImportance streamingImportance; // 1CA
    world::PrefabType type; // 1CB
    bool isLocked; // 1CC
    uint8_t unk1CD[0x1D0 - 0x1CD]; // 1CD
    Box maxBounds; // 1D0
    bool isMerged; // 1F0
    bool isProxyMeshOnly; // 1F1
    bool boostInnerNodesToProxyDistance; // 1F2
    bool overrideStreamingPosWithBBoxCenter; // 1F3
    uint8_t unk1F4[0x1F5 - 0x1F4]; // 1F4
    bool ignoreMeshEmbeddedOccluders; // 1F5
    bool ignoreAllOccluders; // 1F6
    bool isTerrainPrefab; // 1F7
    bool excludeOnConsole; // 1F8
    bool excludeOnNextGenConsoles; // 1F9
    world::PrefabMinimapContribution minimapContribution; // 1FA
    world::PrefabInteriorMapContribution interiorMapContribution; // 1FB
    uint8_t unk1FC[0x210 - 0x1FC]; // 1FC
    CRUID prefabUniqueId; // 210
    uint8_t unk218[0x2B0 - 0x218]; // 218
    DynArray<Handle<world::PrefabMetadata>> metadataArray; // 2B0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(Prefab, 0x380);
RED4EXT_ASSERT_OFFSET(Prefab, environmentDefinition, 0x40);
RED4EXT_ASSERT_OFFSET(Prefab, terrainMultilayerSetup, 0x48);
RED4EXT_ASSERT_OFFSET(Prefab, foliageBrushToTerrainLayerMapping, 0x50);
RED4EXT_ASSERT_OFFSET(Prefab, proxyMesh, 0x58);
RED4EXT_ASSERT_OFFSET(Prefab, proxyScale, 0x60);
RED4EXT_ASSERT_OFFSET(Prefab, maxProxyStreamingDistance, 0x6C);
RED4EXT_ASSERT_OFFSET(Prefab, proxyDistanceFactor, 0x70);
RED4EXT_ASSERT_OFFSET(Prefab, averageNodeDiagonal, 0x74);
RED4EXT_ASSERT_OFFSET(Prefab, booleanProxyHelper, 0x78);
RED4EXT_ASSERT_OFFSET(Prefab, proxyLimiterHelper, 0x80);
RED4EXT_ASSERT_OFFSET(Prefab, customProxyMeshHelper, 0x88);
RED4EXT_ASSERT_OFFSET(Prefab, defaultVariants, 0x90);
RED4EXT_ASSERT_OFFSET(Prefab, mainGroup, 0xA0);
RED4EXT_ASSERT_OFFSET(Prefab, proxyMeshBuildParams, 0xE0);
RED4EXT_ASSERT_OFFSET(Prefab, teamOwnership, 0x1C8);
RED4EXT_ASSERT_OFFSET(Prefab, streamingOcclusion, 0x1C9);
RED4EXT_ASSERT_OFFSET(Prefab, streamingImportance, 0x1CA);
RED4EXT_ASSERT_OFFSET(Prefab, type, 0x1CB);
RED4EXT_ASSERT_OFFSET(Prefab, isLocked, 0x1CC);
RED4EXT_ASSERT_OFFSET(Prefab, maxBounds, 0x1D0);
RED4EXT_ASSERT_OFFSET(Prefab, isMerged, 0x1F0);
RED4EXT_ASSERT_OFFSET(Prefab, isProxyMeshOnly, 0x1F1);
RED4EXT_ASSERT_OFFSET(Prefab, boostInnerNodesToProxyDistance, 0x1F2);
RED4EXT_ASSERT_OFFSET(Prefab, overrideStreamingPosWithBBoxCenter, 0x1F3);
RED4EXT_ASSERT_OFFSET(Prefab, ignoreMeshEmbeddedOccluders, 0x1F5);
RED4EXT_ASSERT_OFFSET(Prefab, ignoreAllOccluders, 0x1F6);
RED4EXT_ASSERT_OFFSET(Prefab, isTerrainPrefab, 0x1F7);
RED4EXT_ASSERT_OFFSET(Prefab, excludeOnConsole, 0x1F8);
RED4EXT_ASSERT_OFFSET(Prefab, excludeOnNextGenConsoles, 0x1F9);
RED4EXT_ASSERT_OFFSET(Prefab, minimapContribution, 0x1FA);
RED4EXT_ASSERT_OFFSET(Prefab, interiorMapContribution, 0x1FB);
RED4EXT_ASSERT_OFFSET(Prefab, prefabUniqueId, 0x210);
RED4EXT_ASSERT_OFFSET(Prefab, metadataArray, 0x370);
#else
RED4EXT_ASSERT_SIZE(Prefab, 0x2C0);
#endif
} // namespace world
using worldPrefab = world::Prefab;
} // namespace RED4ext

// clang-format on
