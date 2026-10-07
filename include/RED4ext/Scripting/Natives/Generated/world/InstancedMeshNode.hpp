#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/shadows/ShadowCastingMode.hpp>
#include <RED4ext/Scripting/Natives/Generated/vis/WorldOccluderType.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Node.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/RenderProxyTransformBuffer.hpp>

namespace RED4ext
{
struct CMesh;

namespace world
{
struct InstancedMeshNode : world::Node
{
    static constexpr const char* NAME = "worldInstancedMeshNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk32[0x38 - 0x32]; // 32
    world::RenderProxyTransformBuffer worldTransformsBuffer; // 38
    uint8_t unk50[0x80 - 0x50]; // 50
    RaRef<CMesh> mesh; // 80
    CName meshAppearance; // 88
    uint32_t meshLODScales; // 90
    vis::WorldOccluderType occluderType; // 94
    uint8_t occluderAutohideDistanceScale; // 95
    uint8_t unk96[0x97 - 0x96]; // 96
    shadows::ShadowCastingMode castShadows; // 97
    shadows::ShadowCastingMode castLocalShadows; // 98
    uint8_t version; // 99
    uint8_t unk9A[0xA0 - 0x9A]; // 9A
#else
    world::RenderProxyTransformBuffer worldTransformsBuffer; // 38
    uint8_t unk50[0x80 - 0x50]; // 50
    RaRef<CMesh> mesh; // 80
    CName meshAppearance; // 88
    uint32_t meshLODScales; // 90
    vis::WorldOccluderType occluderType; // 94
    uint8_t occluderAutohideDistanceScale; // 95
    uint8_t unk96[0x97 - 0x96]; // 96
    shadows::ShadowCastingMode castShadows; // 97
    shadows::ShadowCastingMode castLocalShadows; // 98
    uint8_t version; // 99
    uint8_t unk9A[0xA0 - 0x9A]; // 9A
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(InstancedMeshNode, 0xA0);
RED4EXT_ASSERT_OFFSET(InstancedMeshNode, worldTransformsBuffer, 0x38);
RED4EXT_ASSERT_OFFSET(InstancedMeshNode, mesh, 0x80);
RED4EXT_ASSERT_OFFSET(InstancedMeshNode, meshAppearance, 0x88);
RED4EXT_ASSERT_OFFSET(InstancedMeshNode, meshLODScales, 0x90);
RED4EXT_ASSERT_OFFSET(InstancedMeshNode, occluderType, 0x94);
RED4EXT_ASSERT_OFFSET(InstancedMeshNode, occluderAutohideDistanceScale, 0x95);
RED4EXT_ASSERT_OFFSET(InstancedMeshNode, castShadows, 0x97);
RED4EXT_ASSERT_OFFSET(InstancedMeshNode, castLocalShadows, 0x98);
RED4EXT_ASSERT_OFFSET(InstancedMeshNode, version, 0x99);
#else
RED4EXT_ASSERT_SIZE(InstancedMeshNode, 0xA0);
#endif
} // namespace world
using worldInstancedMeshNode = world::InstancedMeshNode;
} // namespace RED4ext

// clang-format on
