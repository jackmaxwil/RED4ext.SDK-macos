#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>

namespace RED4ext
{
namespace world { struct TrafficStaticCollisionData; }

namespace world
{
struct TrafficCollisionResource : CResource
{
    static constexpr const char* NAME = "worldTrafficCollisionResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    Handle<world::TrafficStaticCollisionData> data; // 40
#else
    Handle<world::TrafficStaticCollisionData> data; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TrafficCollisionResource, 0x50);
RED4EXT_ASSERT_OFFSET(TrafficCollisionResource, data, 0x40);
#else
RED4EXT_ASSERT_SIZE(TrafficCollisionResource, 0x50);
#endif
} // namespace world
using worldTrafficCollisionResource = world::TrafficCollisionResource;
} // namespace RED4ext

// clang-format on
