#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/MeshNode.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/RotatingMeshNodeAxis.hpp>

namespace RED4ext
{
namespace world
{
struct RotatingMeshNode : world::MeshNode
{
    static constexpr const char* NAME = "worldRotatingMeshNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk5A[0x5C - 0x5A]; // 5A
    world::RotatingMeshNodeAxis rotationAxis; // 5C
    float fullRotationTime; // 60
    bool reverseDirection; // 64
    uint8_t unk65[0x68 - 0x65]; // 65
#else
    world::RotatingMeshNodeAxis rotationAxis; // 60
    float fullRotationTime; // 64
    bool reverseDirection; // 68
    uint8_t unk69[0x70 - 0x69]; // 69
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(RotatingMeshNode, 0x68);
RED4EXT_ASSERT_OFFSET(RotatingMeshNode, rotationAxis, 0x5C);
RED4EXT_ASSERT_OFFSET(RotatingMeshNode, fullRotationTime, 0x60);
RED4EXT_ASSERT_OFFSET(RotatingMeshNode, reverseDirection, 0x64);
#else
RED4EXT_ASSERT_SIZE(RotatingMeshNode, 0x70);
#endif
} // namespace world
using worldRotatingMeshNode = world::RotatingMeshNode;
} // namespace RED4ext

// clang-format on
