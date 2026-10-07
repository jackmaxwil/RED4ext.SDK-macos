#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/Box.hpp>
#include <RED4ext/Scripting/Natives/Generated/vis/WorldOccluderType.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Node.hpp>

namespace RED4ext
{
struct CMesh;

namespace world
{
struct __declspec(align(0x10)) InstancedOccluderNode : world::Node
{
    static constexpr const char* NAME = "worldInstancedOccluderNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk32[0x50 - 0x32]; // 32
    Box worldBounds; // 50
    RaRef<CMesh> mesh; // 70
    uint8_t autohideDistanceScale; // 78
    vis::WorldOccluderType occluderType; // 79
    uint8_t unk7A[0x80 - 0x7A]; // 7A
#else
    uint8_t unk38[0x50 - 0x38]; // 38
    Box worldBounds; // 50
    RaRef<CMesh> mesh; // 70
    uint8_t autohideDistanceScale; // 78
    vis::WorldOccluderType occluderType; // 79
    uint8_t unk7A[0x80 - 0x7A]; // 7A
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(InstancedOccluderNode, 0x80);
RED4EXT_ASSERT_OFFSET(InstancedOccluderNode, worldBounds, 0x50);
RED4EXT_ASSERT_OFFSET(InstancedOccluderNode, mesh, 0x70);
RED4EXT_ASSERT_OFFSET(InstancedOccluderNode, autohideDistanceScale, 0x78);
RED4EXT_ASSERT_OFFSET(InstancedOccluderNode, occluderType, 0x79);
#else
RED4EXT_ASSERT_SIZE(InstancedOccluderNode, 0x80);
#endif
} // namespace world
using worldInstancedOccluderNode = world::InstancedOccluderNode;
} // namespace RED4ext

// clang-format on
