#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/CollisionGroupEntry.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Node.hpp>

namespace RED4ext
{
namespace world
{
struct TrafficCollisionGroupNode : world::Node
{
    static constexpr const char* NAME = "worldTrafficCollisionGroupNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk32[0x38 - 0x32]; // 32
    DynArray<world::CollisionGroupEntry> collisionEntries; // 38
#else
    DynArray<world::CollisionGroupEntry> collisionEntries; // 38
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TrafficCollisionGroupNode, 0x48);
RED4EXT_ASSERT_OFFSET(TrafficCollisionGroupNode, collisionEntries, 0x38);
#else
RED4EXT_ASSERT_SIZE(TrafficCollisionGroupNode, 0x48);
#endif
} // namespace world
using worldTrafficCollisionGroupNode = world::TrafficCollisionGroupNode;
} // namespace RED4ext

// clang-format on
