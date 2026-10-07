#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/Color.hpp>
#include <RED4ext/Scripting/Natives/Generated/vis/WorldOccluderType.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Node.hpp>

namespace RED4ext
{
struct CMesh;

namespace world
{
struct StaticOccluderMeshNode : world::Node
{
    static constexpr const char* NAME = "worldStaticOccluderMeshNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk32[0x38 - 0x32]; // 32
    RaRef<CMesh> mesh; // 38
    Color color; // 40
    uint8_t autohideDistanceScale; // 44
    vis::WorldOccluderType occluderType; // 45
    uint8_t unk46[0x48 - 0x46]; // 46
#else
    RaRef<CMesh> mesh; // 38
    Color color; // 40
    uint8_t autohideDistanceScale; // 44
    vis::WorldOccluderType occluderType; // 45
    uint8_t unk46[0x48 - 0x46]; // 46
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(StaticOccluderMeshNode, 0x48);
RED4EXT_ASSERT_OFFSET(StaticOccluderMeshNode, mesh, 0x38);
RED4EXT_ASSERT_OFFSET(StaticOccluderMeshNode, color, 0x40);
RED4EXT_ASSERT_OFFSET(StaticOccluderMeshNode, autohideDistanceScale, 0x44);
RED4EXT_ASSERT_OFFSET(StaticOccluderMeshNode, occluderType, 0x45);
#else
RED4EXT_ASSERT_SIZE(StaticOccluderMeshNode, 0x48);
#endif
} // namespace world
using worldStaticOccluderMeshNode = world::StaticOccluderMeshNode;
} // namespace RED4ext

// clang-format on
