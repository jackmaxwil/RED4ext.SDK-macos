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
struct PrefabProxyMeshNode : world::MeshNode
{
    static constexpr const char* NAME = "worldPrefabProxyMeshNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk5A[0x5C - 0x5A]; // 5A
    uint32_t nbNodesUnderProxy; // 5C
    float nearAutoHideDistance; // 60
    uint8_t unk64[0x68 - 0x64]; // 64
#else
    uint32_t nbNodesUnderProxy; // 60
    float nearAutoHideDistance; // 64
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PrefabProxyMeshNode, 0x68);
RED4EXT_ASSERT_OFFSET(PrefabProxyMeshNode, nbNodesUnderProxy, 0x5C);
RED4EXT_ASSERT_OFFSET(PrefabProxyMeshNode, nearAutoHideDistance, 0x60);
#else
RED4EXT_ASSERT_SIZE(PrefabProxyMeshNode, 0x68);
#endif
} // namespace world
using worldPrefabProxyMeshNode = world::PrefabProxyMeshNode;
} // namespace RED4ext

// clang-format on
