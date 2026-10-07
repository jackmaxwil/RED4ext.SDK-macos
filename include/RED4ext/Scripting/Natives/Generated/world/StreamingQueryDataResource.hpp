#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/StreamingQueryRoadData.hpp>

namespace RED4ext
{
namespace world
{
struct StreamingQueryDataResource : CResource
{
    static constexpr const char* NAME = "worldStreamingQueryDataResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<world::StreamingQueryRoadData> roadDatas; // 40
    DynArray<uint16_t> connectedRoadDataIndices; // 50
#else
    DynArray<world::StreamingQueryRoadData> roadDatas; // 40
    DynArray<uint16_t> connectedRoadDataIndices; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(StreamingQueryDataResource, 0x60);
RED4EXT_ASSERT_OFFSET(StreamingQueryDataResource, roadDatas, 0x40);
RED4EXT_ASSERT_OFFSET(StreamingQueryDataResource, connectedRoadDataIndices, 0x50);
#else
RED4EXT_ASSERT_SIZE(StreamingQueryDataResource, 0x60);
#endif
} // namespace world
using worldStreamingQueryDataResource = world::StreamingQueryDataResource;
} // namespace RED4ext

// clang-format on
