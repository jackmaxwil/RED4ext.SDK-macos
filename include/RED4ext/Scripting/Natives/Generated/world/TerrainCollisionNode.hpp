#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector4.hpp>
#include <RED4ext/Scripting/Natives/Generated/WorldTransform.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Node.hpp>

namespace RED4ext
{
namespace world
{
struct __declspec(align(0x10)) TerrainCollisionNode : world::Node
{
    static constexpr const char* NAME = "worldTerrainCollisionNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk32[0x38 - 0x32]; // 32
    DynArray<CName> materials; // 38
    DynArray<uint8_t> materialIndices; // 48
    DeferredDataBuffer heightfieldGeometry; // 58
    WorldTransform actorTransform; // B0
    Vector4 extents; // D0
    float streamingDistance; // E0
    float rowScale; // E4
    float columnScale; // E8
    float heightScale; // EC
    bool increaseStreamingDistance; // F0
    uint8_t unkF1[0x100 - 0xF1]; // F1
#else
    DynArray<CName> materials; // 38
    DynArray<uint8_t> materialIndices; // 48
    DeferredDataBuffer heightfieldGeometry; // 58
    WorldTransform actorTransform; // B0
    Vector4 extents; // D0
    float streamingDistance; // E0
    float rowScale; // E4
    float columnScale; // E8
    float heightScale; // EC
    bool increaseStreamingDistance; // F0
    uint8_t unkF1[0x100 - 0xF1]; // F1
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TerrainCollisionNode, 0x100);
RED4EXT_ASSERT_OFFSET(TerrainCollisionNode, materials, 0x38);
RED4EXT_ASSERT_OFFSET(TerrainCollisionNode, materialIndices, 0x48);
RED4EXT_ASSERT_OFFSET(TerrainCollisionNode, heightfieldGeometry, 0x58);
RED4EXT_ASSERT_OFFSET(TerrainCollisionNode, actorTransform, 0xB0);
RED4EXT_ASSERT_OFFSET(TerrainCollisionNode, extents, 0xD0);
RED4EXT_ASSERT_OFFSET(TerrainCollisionNode, streamingDistance, 0xE0);
RED4EXT_ASSERT_OFFSET(TerrainCollisionNode, rowScale, 0xE4);
RED4EXT_ASSERT_OFFSET(TerrainCollisionNode, columnScale, 0xE8);
RED4EXT_ASSERT_OFFSET(TerrainCollisionNode, heightScale, 0xEC);
RED4EXT_ASSERT_OFFSET(TerrainCollisionNode, increaseStreamingDistance, 0xF0);
#else
RED4EXT_ASSERT_SIZE(TerrainCollisionNode, 0x100);
#endif
} // namespace world
using worldTerrainCollisionNode = world::TerrainCollisionNode;
} // namespace RED4ext

// clang-format on
