#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/res/StreamedResource.hpp>

namespace RED4ext
{
namespace world
{
struct TrafficPersistentSpatialResource : res::StreamedResource
{
    static constexpr const char* NAME = "worldTrafficPersistentSpatialResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<DynArray<uint16_t>> neighborGroups; // 40
    uint8_t unk50[0x128 - 0x50]; // 50
#else
    DynArray<DynArray<uint16_t>> neighborGroups; // 40
    uint8_t unk50[0x128 - 0x50]; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TrafficPersistentSpatialResource, 0x128);
RED4EXT_ASSERT_OFFSET(TrafficPersistentSpatialResource, neighborGroups, 0x40);
#else
RED4EXT_ASSERT_SIZE(TrafficPersistentSpatialResource, 0x128);
#endif
} // namespace world
using worldTrafficPersistentSpatialResource = world::TrafficPersistentSpatialResource;
} // namespace RED4ext

// clang-format on
