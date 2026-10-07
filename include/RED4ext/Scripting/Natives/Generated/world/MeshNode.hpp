#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/RenderSceneLayerMask.hpp>
#include <RED4ext/Scripting/Natives/Generated/shadows/ShadowCastingMode.hpp>
#include <RED4ext/Scripting/Natives/Generated/vis/WorldOccluderType.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Node.hpp>

namespace RED4ext
{
struct CMesh;

namespace world
{
struct MeshNode : world::Node
{
    static constexpr const char* NAME = "worldMeshNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk32[0x38 - 0x32]; // 32
    RaRef<CMesh> mesh; // 38
    CName meshAppearance; // 40
    float forceAutoHideDistance; // 48
    uint32_t lodLevelScales; // 4C
    vis::WorldOccluderType occluderType; // 50
    uint8_t occluderAutohideDistanceScale; // 51
    RenderSceneLayerMask renderSceneLayerMask; // 52
    shadows::ShadowCastingMode castShadows; // 53
    shadows::ShadowCastingMode castLocalShadows; // 54
    shadows::ShadowCastingMode castRayTracedGlobalShadows; // 55
    shadows::ShadowCastingMode castRayTracedLocalShadows; // 56
    bool windImpulseEnabled; // 57
    bool removeFromRainMap; // 58
    uint8_t version; // 59
#else
    RaRef<CMesh> mesh; // 38
    CName meshAppearance; // 40
    float forceAutoHideDistance; // 48
    uint32_t lodLevelScales; // 4C
    vis::WorldOccluderType occluderType; // 50
    uint8_t occluderAutohideDistanceScale; // 51
    RenderSceneLayerMask renderSceneLayerMask; // 52
    shadows::ShadowCastingMode castShadows; // 53
    shadows::ShadowCastingMode castLocalShadows; // 54
    shadows::ShadowCastingMode castRayTracedGlobalShadows; // 55
    shadows::ShadowCastingMode castRayTracedLocalShadows; // 56
    bool windImpulseEnabled; // 57
    bool removeFromRainMap; // 58
    uint8_t version; // 59
    uint8_t unk5A[0x60 - 0x5A]; // 5A
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MeshNode, 0x60);
RED4EXT_ASSERT_OFFSET(MeshNode, mesh, 0x38);
RED4EXT_ASSERT_OFFSET(MeshNode, meshAppearance, 0x40);
RED4EXT_ASSERT_OFFSET(MeshNode, forceAutoHideDistance, 0x48);
RED4EXT_ASSERT_OFFSET(MeshNode, lodLevelScales, 0x4C);
RED4EXT_ASSERT_OFFSET(MeshNode, occluderType, 0x50);
RED4EXT_ASSERT_OFFSET(MeshNode, occluderAutohideDistanceScale, 0x51);
RED4EXT_ASSERT_OFFSET(MeshNode, renderSceneLayerMask, 0x52);
RED4EXT_ASSERT_OFFSET(MeshNode, castShadows, 0x53);
RED4EXT_ASSERT_OFFSET(MeshNode, castLocalShadows, 0x54);
RED4EXT_ASSERT_OFFSET(MeshNode, castRayTracedGlobalShadows, 0x55);
RED4EXT_ASSERT_OFFSET(MeshNode, castRayTracedLocalShadows, 0x56);
RED4EXT_ASSERT_OFFSET(MeshNode, windImpulseEnabled, 0x57);
RED4EXT_ASSERT_OFFSET(MeshNode, removeFromRainMap, 0x58);
RED4EXT_ASSERT_OFFSET(MeshNode, version, 0x59);
#else
RED4EXT_ASSERT_SIZE(MeshNode, 0x60);
#endif
} // namespace world
using worldMeshNode = world::MeshNode;
} // namespace RED4ext

// clang-format on
