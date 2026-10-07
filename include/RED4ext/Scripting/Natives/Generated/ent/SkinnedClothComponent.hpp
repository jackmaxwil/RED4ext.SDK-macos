#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/ISkinTargetComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/MeshComponentLODMode.hpp>
#include <RED4ext/Scripting/Natives/Generated/mesh/CookedClothMeshTopologyData.hpp>

namespace RED4ext
{
struct CMesh;

namespace ent
{
struct __declspec(align(0x10)) SkinnedClothComponent : ent::ISkinTargetComponent
{
    static constexpr const char* NAME = "entSkinnedClothComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    RaRef<CMesh> graphicsMesh; // 1D8
    RaRef<CMesh> physicalMesh; // 1E0
    ent::MeshComponentLODMode LODMode; // 1E8
    uint8_t unk1E9[0x1F0 - 0x1E9]; // 1E9
    CName meshAppearance; // 1F0
    uint64_t chunkMask; // 1F8
    uint8_t unk200[0x210 - 0x200]; // 200
    mesh::CookedClothMeshTopologyData compiledTopologyData; // 210
    uint8_t unk2B0[0x2C0 - 0x2B0]; // 2B0
#else
    RaRef<CMesh> graphicsMesh; // 1E0
    RaRef<CMesh> physicalMesh; // 1E8
    ent::MeshComponentLODMode LODMode; // 1F0
    uint8_t unk1F1[0x1F8 - 0x1F1]; // 1F1
    CName meshAppearance; // 1F8
    uint64_t chunkMask; // 200
    uint8_t unk208[0x218 - 0x208]; // 208
    mesh::CookedClothMeshTopologyData compiledTopologyData; // 218
    uint8_t unk2B8[0x2D0 - 0x2B8]; // 2B8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SkinnedClothComponent, 0x2C0);
RED4EXT_ASSERT_OFFSET(SkinnedClothComponent, graphicsMesh, 0x1D8);
RED4EXT_ASSERT_OFFSET(SkinnedClothComponent, physicalMesh, 0x1E0);
RED4EXT_ASSERT_OFFSET(SkinnedClothComponent, LODMode, 0x1E8);
RED4EXT_ASSERT_OFFSET(SkinnedClothComponent, meshAppearance, 0x1F0);
RED4EXT_ASSERT_OFFSET(SkinnedClothComponent, chunkMask, 0x1F8);
RED4EXT_ASSERT_OFFSET(SkinnedClothComponent, compiledTopologyData, 0x210);
#else
RED4EXT_ASSERT_SIZE(SkinnedClothComponent, 0x2D0);
#endif
} // namespace ent
using entSkinnedClothComponent = ent::SkinnedClothComponent;
} // namespace RED4ext

// clang-format on
