#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/Box.hpp>
#include <RED4ext/Scripting/Natives/Generated/NavGenAgentSize.hpp>
#include <RED4ext/Scripting/Natives/Generated/res/StreamedResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/NavigationTileData.hpp>

namespace RED4ext
{
namespace world
{
struct __declspec(align(0x10)) NavigationTileResource : res::StreamedResource
{
    static constexpr const char* NAME = "worldNavigationTileResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    Box localBoundingBox; // 40
    DynArray<world::NavigationTileData> tilesData; // 60
    DynArray<DataBuffer> tileBuffers; // 70
    NavGenAgentSize agentSize; // 80
    uint8_t unk84[0x90 - 0x84]; // 84
#else
    Box localBoundingBox; // 40
    DynArray<world::NavigationTileData> tilesData; // 60
    DynArray<DataBuffer> tileBuffers; // 70
    NavGenAgentSize agentSize; // 80
    uint8_t unk84[0x90 - 0x84]; // 84
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(NavigationTileResource, 0x90);
RED4EXT_ASSERT_OFFSET(NavigationTileResource, localBoundingBox, 0x40);
RED4EXT_ASSERT_OFFSET(NavigationTileResource, tilesData, 0x60);
RED4EXT_ASSERT_OFFSET(NavigationTileResource, tileBuffers, 0x70);
RED4EXT_ASSERT_OFFSET(NavigationTileResource, agentSize, 0x80);
#else
RED4EXT_ASSERT_SIZE(NavigationTileResource, 0x90);
#endif
} // namespace world
using worldNavigationTileResource = world::NavigationTileResource;
} // namespace RED4ext

// clang-format on
