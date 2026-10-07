#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/EClothCollisionMaskEnum.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/MeshNode.hpp>

namespace RED4ext
{
namespace world
{
struct ClothMeshNode : world::MeshNode
{
    static constexpr const char* NAME = "worldClothMeshNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool affectedByWind; // 5A
    uint8_t unk5B[0x5C - 0x5B]; // 5B
    physics::EClothCollisionMaskEnum collisionMask; // 5C
#else
    bool affectedByWind; // 60
    uint8_t unk61[0x64 - 0x61]; // 61
    physics::EClothCollisionMaskEnum collisionMask; // 64
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ClothMeshNode, 0x60);
RED4EXT_ASSERT_OFFSET(ClothMeshNode, affectedByWind, 0x5A);
RED4EXT_ASSERT_OFFSET(ClothMeshNode, collisionMask, 0x5C);
#else
RED4EXT_ASSERT_SIZE(ClothMeshNode, 0x68);
#endif
} // namespace world
using worldClothMeshNode = world::ClothMeshNode;
} // namespace RED4ext

// clang-format on
