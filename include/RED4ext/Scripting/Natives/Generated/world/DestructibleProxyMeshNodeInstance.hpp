#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/PrefabProxyMeshNodeInstance.hpp>

namespace RED4ext
{
namespace world
{
struct __declspec(align(0x10)) DestructibleProxyMeshNodeInstance : world::PrefabProxyMeshNodeInstance
{
    static constexpr const char* NAME = "worldDestructibleProxyMeshNodeInstance";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk110[0x120 - 0x110]; // 110
#else
    uint8_t unk110[0x130 - 0x110]; // 110
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(DestructibleProxyMeshNodeInstance, 0x120);
#else
RED4EXT_ASSERT_SIZE(DestructibleProxyMeshNodeInstance, 0x130);
#endif
} // namespace world
using worldDestructibleProxyMeshNodeInstance = world::DestructibleProxyMeshNodeInstance;
} // namespace RED4ext

// clang-format on
