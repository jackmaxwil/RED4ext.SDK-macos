#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Node.hpp>

namespace RED4ext
{
namespace world { struct NavigationTileResource; }

namespace world
{
struct NavigationNode : world::Node
{
    static constexpr const char* NAME = "worldNavigationNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk32[0x38 - 0x32]; // 32
    RaRef<world::NavigationTileResource> navigationTileResource; // 38
#else
    RaRef<world::NavigationTileResource> navigationTileResource; // 38
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(NavigationNode, 0x40);
RED4EXT_ASSERT_OFFSET(NavigationNode, navigationTileResource, 0x38);
#else
RED4EXT_ASSERT_SIZE(NavigationNode, 0x40);
#endif
} // namespace world
using worldNavigationNode = world::NavigationNode;
} // namespace RED4ext

// clang-format on
