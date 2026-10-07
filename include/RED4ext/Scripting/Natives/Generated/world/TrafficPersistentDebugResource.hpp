#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/res/StreamedResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/TrafficLaneUID.hpp>

namespace RED4ext
{
namespace world
{
struct TrafficPersistentDebugResource : res::StreamedResource
{
    static constexpr const char* NAME = "worldTrafficPersistentDebugResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<world::TrafficLaneUID> brokenUIDs; // 40
    DynArray<world::TrafficLaneUID> brokenUIDsDeadEnds; // 50
#else
    DynArray<world::TrafficLaneUID> brokenUIDs; // 40
    DynArray<world::TrafficLaneUID> brokenUIDsDeadEnds; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TrafficPersistentDebugResource, 0x60);
RED4EXT_ASSERT_OFFSET(TrafficPersistentDebugResource, brokenUIDs, 0x40);
RED4EXT_ASSERT_OFFSET(TrafficPersistentDebugResource, brokenUIDsDeadEnds, 0x50);
#else
RED4EXT_ASSERT_SIZE(TrafficPersistentDebugResource, 0x60);
#endif
} // namespace world
using worldTrafficPersistentDebugResource = world::TrafficPersistentDebugResource;
} // namespace RED4ext

// clang-format on
