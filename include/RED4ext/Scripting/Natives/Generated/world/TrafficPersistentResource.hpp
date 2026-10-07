#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/res/StreamedResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/TrafficPersistentData.hpp>

namespace RED4ext
{
namespace world
{
struct TrafficPersistentResource : res::StreamedResource
{
    static constexpr const char* NAME = "worldTrafficPersistentResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    world::TrafficPersistentData data; // 40
#else
    world::TrafficPersistentData data; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TrafficPersistentResource, 0x150);
RED4EXT_ASSERT_OFFSET(TrafficPersistentResource, data, 0x40);
#else
RED4EXT_ASSERT_SIZE(TrafficPersistentResource, 0x150);
#endif
} // namespace world
using worldTrafficPersistentResource = world::TrafficPersistentResource;
} // namespace RED4ext

// clang-format on
