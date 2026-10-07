#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Node.hpp>

namespace RED4ext
{
namespace world { struct TrafficPersistentResource; }

namespace world
{
struct TrafficPersistentNode : world::Node
{
    static constexpr const char* NAME = "worldTrafficPersistentNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk32[0x38 - 0x32]; // 32
    RaRef<world::TrafficPersistentResource> resource; // 38
#else
    RaRef<world::TrafficPersistentResource> resource; // 38
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TrafficPersistentNode, 0x40);
RED4EXT_ASSERT_OFFSET(TrafficPersistentNode, resource, 0x38);
#else
RED4EXT_ASSERT_SIZE(TrafficPersistentNode, 0x40);
#endif
} // namespace world
using worldTrafficPersistentNode = world::TrafficPersistentNode;
} // namespace RED4ext

// clang-format on
