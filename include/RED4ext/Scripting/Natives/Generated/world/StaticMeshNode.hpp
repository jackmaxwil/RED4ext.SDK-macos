#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/MeshNode.hpp>

namespace RED4ext
{
namespace world
{
struct StaticMeshNode : world::MeshNode
{
    static constexpr const char* NAME = "worldStaticMeshNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk5A[0x5C - 0x5A]; // 5A
#else
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(StaticMeshNode, 0x60);
#else
RED4EXT_ASSERT_SIZE(StaticMeshNode, 0x60);
#endif
} // namespace world
using worldStaticMeshNode = world::StaticMeshNode;
} // namespace RED4ext

// clang-format on
