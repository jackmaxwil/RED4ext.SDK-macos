#pragma once

#include <RED4ext/CName.hpp>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Rendering/RenderProxy.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/ISkinTargetComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/red/TagList.hpp>
#include <RED4ext/Scripting/Natives/Generated/shadows/ShadowCastingMode.hpp>

#include <cstdint>

namespace RED4ext
{
struct MorphTargetMesh;

namespace ent
{
struct __declspec(align(0x10)) MorphTargetSkinnedMeshComponent : ent::ISkinTargetComponent
{
    static constexpr const char* NAME = "entMorphTargetSkinnedMeshComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    // macOS 2.3.1: clang and the game start this class in ISkinTargetComponent's tail padding (dsize 0x1D8; the RTTI
    // dump has entSkinnedClothComponent::graphicsMesh at 0x1D8), so every member sits 8 bytes lower than on Windows.
    // The RTTI properties confirm it; renderProxy and meshHandle are native, not in RTTI.
    uint8_t unk1D8[0x1E0 - 0x1D8];               // 1D8
    SharedPtr<IRenderProxy> renderProxy;         // 1E0
    uint8_t unk1F0[0x1F8 - 0x1F0];               // 1F0
    RaRef<MorphTargetMesh> morphResource;        // 1F8
    Handle<MorphTargetMesh> meshHandle;          // 200
    uint8_t unk210[0x230 - 0x210];               // 210
    CName meshAppearance;                        // 230
    uint64_t chunkMask;                          // 238
    uint8_t unk240[0x2E0 - 0x240];               // 240
    CName renderingPlaneAnimationParam;          // 2E0
    CName visibilityAnimationParam;              // 2E8
    uint8_t unk2F0[0x300 - 0x2F0];               // 2F0
    red::TagList tags;                           // 300
    uint8_t unk310[0x354 - 0x310];               // 310
    shadows::ShadowCastingMode castShadows;      // 354
    shadows::ShadowCastingMode castLocalShadows; // 355
    bool acceptDismemberment;                    // 356
    uint8_t unk357[0x359 - 0x357];               // 357
    uint8_t version;                             // 359
    uint8_t unk35A[0x360 - 0x35A];               // 35A
#else
    uint8_t unk1E0[0x1E8 - 0x1E0];               // 1E0
    SharedPtr<IRenderProxy> renderProxy;         // 1E8
    uint8_t unk1F0[0x200 - 0x1F8];               // 1F8
    RaRef<MorphTargetMesh> morphResource;        // 200
    Handle<MorphTargetMesh> meshHandle;          // 208
    uint8_t unk208[0x238 - 0x218];               // 218
    CName meshAppearance;                        // 238
    uint64_t chunkMask;                          // 240
    uint8_t unk248[0x2E8 - 0x248];               // 248
    CName renderingPlaneAnimationParam;          // 2E8
    CName visibilityAnimationParam;              // 2F0
    uint8_t unk2F8[0x308 - 0x2F8];               // 2F8
    red::TagList tags;                           // 308
    uint8_t unk318[0x35C - 0x318];               // 318
    shadows::ShadowCastingMode castShadows;      // 35C
    shadows::ShadowCastingMode castLocalShadows; // 35D
    bool acceptDismemberment;                    // 35E
    uint8_t unk35F[0x361 - 0x35F];               // 35F
    uint8_t version;                             // 361
    uint8_t unk362[0x370 - 0x362];               // 362
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MorphTargetSkinnedMeshComponent, 0x360);
RED4EXT_ASSERT_OFFSET(MorphTargetSkinnedMeshComponent, morphResource, 0x1F8);
RED4EXT_ASSERT_OFFSET(MorphTargetSkinnedMeshComponent, meshAppearance, 0x230);
RED4EXT_ASSERT_OFFSET(MorphTargetSkinnedMeshComponent, tags, 0x300);
RED4EXT_ASSERT_OFFSET(MorphTargetSkinnedMeshComponent, version, 0x359);
#else
RED4EXT_ASSERT_SIZE(MorphTargetSkinnedMeshComponent, 0x370);
#endif
} // namespace ent
} // namespace RED4ext
