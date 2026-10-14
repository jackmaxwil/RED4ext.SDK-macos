#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/StaticArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector4.hpp>

namespace RED4ext
{
namespace rend
{
struct __declspec(align(0x10)) RenderMorphTargetMeshBlobTextureData
{
    static constexpr const char* NAME = "rendRenderMorphTargetMeshBlobTextureData";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
#pragma warning(suppress : 4324)
    alignas(16) StaticArray<Vector4, 3> targetDiffScale; // 00
#pragma warning(suppress : 4324)
    alignas(16) StaticArray<Vector4, 3> targetDiffOffset; // 40
    uint8_t unk74[0x80 - 0x74]; // 74
    StaticArray<uint32_t, 3> targetDiffsDataOffset; // 80
    StaticArray<uint32_t, 3> targetDiffsDataSize; // 90
    StaticArray<uint16_t, 3> targetDiffsWidth; // A0
    StaticArray<uint8_t, 3> targetDiffsMipLevelCounts; // AC
    uint8_t unkB4[0xC0 - 0xB4]; // B4
#else
#pragma warning(suppress : 4324)
    alignas(16) StaticArray<Vector4, 3> targetDiffScale; // 00
#pragma warning(suppress : 4324)
    alignas(16) StaticArray<Vector4, 3> targetDiffOffset; // 40
    StaticArray<uint32_t, 3> targetDiffsDataOffset; // 80
    StaticArray<uint32_t, 3> targetDiffsDataSize; // 90
    StaticArray<uint16_t, 3> targetDiffsWidth; // A0
    StaticArray<uint8_t, 3> targetDiffsMipLevelCounts; // AC
    uint8_t unkB4[0xC0 - 0xB4]; // B4
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(RenderMorphTargetMeshBlobTextureData, 0xC0);
RED4EXT_ASSERT_OFFSET(RenderMorphTargetMeshBlobTextureData, targetDiffScale, 0x0);
RED4EXT_ASSERT_OFFSET(RenderMorphTargetMeshBlobTextureData, targetDiffOffset, 0x40);
RED4EXT_ASSERT_OFFSET(RenderMorphTargetMeshBlobTextureData, targetDiffsDataOffset, 0x80);
RED4EXT_ASSERT_OFFSET(RenderMorphTargetMeshBlobTextureData, targetDiffsDataSize, 0x90);
RED4EXT_ASSERT_OFFSET(RenderMorphTargetMeshBlobTextureData, targetDiffsWidth, 0xA0);
RED4EXT_ASSERT_OFFSET(RenderMorphTargetMeshBlobTextureData, targetDiffsMipLevelCounts, 0xAC);
#else
RED4EXT_ASSERT_SIZE(RenderMorphTargetMeshBlobTextureData, 0xC0);
#endif
} // namespace rend
using rendRenderMorphTargetMeshBlobTextureData = rend::RenderMorphTargetMeshBlobTextureData;
} // namespace RED4ext

// clang-format on
