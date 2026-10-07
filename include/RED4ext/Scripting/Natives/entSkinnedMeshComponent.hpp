#pragma once

#include <RED4ext/CName.hpp>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/RenderProxy.hpp>
#include <RED4ext/Scripting/Natives/Generated/CMesh.hpp>
#include <RED4ext/Scripting/Natives/Generated/NavGenNavigationSetting.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/ForcedLodDistance.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/ISkinTargetComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/MeshComponentLODMode.hpp>
#include <RED4ext/Scripting/Natives/Generated/shadows/ShadowCastingMode.hpp>

#include <cstdint>

namespace RED4ext
{
namespace ent
{
struct __declspec(align(0x10)) SkinnedMeshComponent : ent::ISkinTargetComponent
{
    static constexpr const char* NAME = "entSkinnedMeshComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    // macOS 2.3.1: clang and the game start this class in ISkinTargetComponent's tail padding (dsize 0x1D8; the RTTI
    // dump has entSkinnedClothComponent::graphicsMesh at 0x1D8), so every member sits 8 bytes lower than on Windows.
    // The RTTI properties from mesh on confirm it; renderProxy/appearanceHandle/meshHandle are native, not in RTTI.
    // Derived classes reuse the tail from 0x268 (entCharacterCustomizationSkinnedMeshComponent::tags).
    SharedPtr<IRenderProxy> renderProxy;           // 1D8
    Handle<mesh::MeshAppearance> appearanceHandle; // 1E8
    Handle<CMesh> meshHandle;                      // 1F8
    uint8_t unk208[0x220 - 0x208];                 // 208
    RaRef<CMesh> mesh;                             // 220
    CName meshAppearance;                          // 228
    CName renderingPlaneAnimationParam;            // 230
    CName visibilityAnimationParam;                // 238
    uint64_t chunkMask;                            // 240
    NavGenNavigationSetting navigationImpact;      // 248
    ent::MeshComponentLODMode LODMode;             // 24A
    uint8_t unk24B[0x24D - 0x24B];                 // 24B
    uint8_t order;                                 // 24D
    shadows::ShadowCastingMode castShadows;        // 24E
    shadows::ShadowCastingMode castLocalShadows;   // 24F
    bool useProxyMeshAsShadowMesh;                 // 250
    bool acceptDismemberment;                      // 251
    bool overrideMeshNavigationImpact;             // 252
    uint8_t unk253[0x255 - 0x253];                 // 253
    ent::ForcedLodDistance forcedLodDistance;      // 255
    uint8_t unk256[0x260 - 0x256];                 // 256
    uint8_t version;                               // 260
    uint8_t unk261[0x268 - 0x261];                 // 261
#else
    SharedPtr<IRenderProxy> renderProxy;           // 1E0
    Handle<mesh::MeshAppearance> appearanceHandle; // 1F0
    Handle<CMesh> meshHandle;                      // 200
    uint8_t unk1F0[0x228 - 0x210];                 // 210
    RaRef<CMesh> mesh;                             // 228
    CName meshAppearance;                          // 230
    CName renderingPlaneAnimationParam;            // 238
    CName visibilityAnimationParam;                // 240
    uint64_t chunkMask;                            // 248
    NavGenNavigationSetting navigationImpact;      // 250
    ent::MeshComponentLODMode LODMode;             // 252
    uint8_t unk253[0x255 - 0x253];                 // 253
    uint8_t order;                                 // 255
    shadows::ShadowCastingMode castShadows;        // 256
    shadows::ShadowCastingMode castLocalShadows;   // 257
    bool useProxyMeshAsShadowMesh;                 // 258
    bool acceptDismemberment;                      // 259
    bool overrideMeshNavigationImpact;             // 25A
    uint8_t unk25B[0x25D - 0x25B];                 // 25B
    ent::ForcedLodDistance forcedLodDistance;      // 25D
    uint8_t unk25E[0x268 - 0x25E];                 // 25E
    uint8_t version;                               // 268
    uint8_t unk269[0x270 - 0x269];                 // 269
#endif
};
RED4EXT_ASSERT_SIZE(SkinnedMeshComponent, 0x270);
#ifdef __APPLE__
RED4EXT_ASSERT_OFFSET(SkinnedMeshComponent, mesh, 0x220);
RED4EXT_ASSERT_OFFSET(SkinnedMeshComponent, chunkMask, 0x240);
RED4EXT_ASSERT_OFFSET(SkinnedMeshComponent, forcedLodDistance, 0x255);
RED4EXT_ASSERT_OFFSET(SkinnedMeshComponent, version, 0x260);
#endif
} // namespace ent
} // namespace RED4ext
