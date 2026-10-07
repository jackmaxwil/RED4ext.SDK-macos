#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector4.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Node.hpp>

namespace RED4ext
{
namespace world
{
struct __declspec(align(0x10)) CollisionNode : world::Node
{
    static constexpr const char* NAME = "worldCollisionNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk32[0xC8 - 0x32]; // 32
    DataBuffer compiledData; // C8
    uint64_t sectorHash; // F0
    uint16_t numActors; // F8
    uint16_t numShapeInfos; // FA
    uint16_t numShapePositions; // FC
    uint16_t numShapeRotations; // FE
    uint16_t numScales; // 100
    uint16_t numMaterials; // 102
    uint16_t numPresets; // 104
    uint16_t numShapeIndices; // 106
    uint16_t numMaterialIndices; // 108
    uint8_t lod; // 10A
    uint8_t resourceVersion; // 10B
    uint8_t unk10C[0x110 - 0x10C]; // 10C
    Vector4 extents; // 110
#else
    uint8_t unk38[0xC8 - 0x38]; // 38
    DataBuffer compiledData; // C8
    uint64_t sectorHash; // F0
    uint16_t numActors; // F8
    uint16_t numShapeInfos; // FA
    uint16_t numShapePositions; // FC
    uint16_t numShapeRotations; // FE
    uint16_t numScales; // 100
    uint16_t numMaterials; // 102
    uint16_t numPresets; // 104
    uint16_t numShapeIndices; // 106
    uint16_t numMaterialIndices; // 108
    uint8_t lod; // 10A
    uint8_t resourceVersion; // 10B
    uint8_t unk10C[0x110 - 0x10C]; // 10C
    Vector4 extents; // 110
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CollisionNode, 0x120);
RED4EXT_ASSERT_OFFSET(CollisionNode, compiledData, 0xC8);
RED4EXT_ASSERT_OFFSET(CollisionNode, sectorHash, 0xF0);
RED4EXT_ASSERT_OFFSET(CollisionNode, numActors, 0xF8);
RED4EXT_ASSERT_OFFSET(CollisionNode, numShapeInfos, 0xFA);
RED4EXT_ASSERT_OFFSET(CollisionNode, numShapePositions, 0xFC);
RED4EXT_ASSERT_OFFSET(CollisionNode, numShapeRotations, 0xFE);
RED4EXT_ASSERT_OFFSET(CollisionNode, numScales, 0x100);
RED4EXT_ASSERT_OFFSET(CollisionNode, numMaterials, 0x102);
RED4EXT_ASSERT_OFFSET(CollisionNode, numPresets, 0x104);
RED4EXT_ASSERT_OFFSET(CollisionNode, numShapeIndices, 0x106);
RED4EXT_ASSERT_OFFSET(CollisionNode, numMaterialIndices, 0x108);
RED4EXT_ASSERT_OFFSET(CollisionNode, lod, 0x10A);
RED4EXT_ASSERT_OFFSET(CollisionNode, resourceVersion, 0x10B);
RED4EXT_ASSERT_OFFSET(CollisionNode, extents, 0x110);
#else
RED4EXT_ASSERT_SIZE(CollisionNode, 0x120);
#endif
} // namespace world
using worldCollisionNode = world::CollisionNode;
} // namespace RED4ext

// clang-format on
