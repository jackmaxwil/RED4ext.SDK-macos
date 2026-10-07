#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/Box.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>

namespace RED4ext
{
struct CResource;
namespace world { struct AutoFoliageMapping; }
namespace world { struct EnvironmentDefinition; }
namespace world { struct StreamingBlock; }
namespace world { struct StreamingQueryDataResource; }

namespace world
{
struct __declspec(align(0x10)) StreamingWorld : CResource
{
    static constexpr const char* NAME = "worldStreamingWorld";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x3C - 0x39]; // 39
    uint32_t version; // 3C
    Box worldBoundingBox; // 40
    DynArray<Ref<world::StreamingBlock>> blockRefs; // 60
    uint8_t unk70[0x80 - 0x70]; // 70
    Ref<world::EnvironmentDefinition> environmentDefinition; // 80
    Ref<CResource> persistentStateData; // 98
    Ref<CResource> deviceResource; // B0
    Ref<CResource> deviceInitResource; // C8
    Ref<CResource> mappinResource; // E0
    Ref<CResource> poiMappinResource; // F8
    Ref<CResource> areaResource; // 110
    Ref<CResource> lootResource; // 128
    Ref<CResource> locationResource; // 140
    Ref<CResource> geometryCacheResource; // 158
    RaRef<CResource> locomotionPathResource; // 170
    RaRef<world::AutoFoliageMapping> autoFoliageMapping; // 178
    RaRef<CResource> trafficPersistentResource; // 180
    RaRef<CResource> trafficLaneConnectivityResource; // 188
    RaRef<CResource> trafficLanePolygonsResource; // 190
    RaRef<CResource> trafficLaneSpotsResource; // 198
    RaRef<CResource> trafficSpatialRepresentationResource; // 1A0
    RaRef<CResource> trafficCollisionResource; // 1A8
    RaRef<CResource> trafficNullAreaCollisionResource; // 1B0
    RaRef<CResource> smartObjectCompiledRootResource; // 1B8
    RaRef<world::StreamingQueryDataResource> streamingQueryDataResource; // 1C0
    uint8_t unk1C8[0x1F8 - 0x1C8]; // 1C8
    bool wasBuiltForSceneRecording; // 1F8
    uint8_t unk1F9[0x200 - 0x1F9]; // 1F9
#else
    uint32_t version; // 40
    uint8_t unk44[0x50 - 0x44]; // 44
    Box worldBoundingBox; // 50
    DynArray<Ref<world::StreamingBlock>> blockRefs; // 70
    uint8_t unk80[0x90 - 0x80]; // 80
    Ref<world::EnvironmentDefinition> environmentDefinition; // 90
    Ref<CResource> persistentStateData; // A8
    Ref<CResource> deviceResource; // C0
    Ref<CResource> deviceInitResource; // D8
    Ref<CResource> mappinResource; // F0
    Ref<CResource> poiMappinResource; // 108
    Ref<CResource> areaResource; // 120
    Ref<CResource> lootResource; // 138
    Ref<CResource> locationResource; // 150
    Ref<CResource> geometryCacheResource; // 168
    RaRef<CResource> locomotionPathResource; // 180
    RaRef<world::AutoFoliageMapping> autoFoliageMapping; // 188
    RaRef<CResource> trafficPersistentResource; // 190
    RaRef<CResource> trafficLaneConnectivityResource; // 198
    RaRef<CResource> trafficLanePolygonsResource; // 1A0
    RaRef<CResource> trafficLaneSpotsResource; // 1A8
    RaRef<CResource> trafficSpatialRepresentationResource; // 1B0
    RaRef<CResource> trafficCollisionResource; // 1B8
    RaRef<CResource> trafficNullAreaCollisionResource; // 1C0
    RaRef<CResource> smartObjectCompiledRootResource; // 1C8
    RaRef<world::StreamingQueryDataResource> streamingQueryDataResource; // 1D0
    uint8_t unk1D8[0x208 - 0x1D8]; // 1D8
    bool wasBuiltForSceneRecording; // 208
    uint8_t unk209[0x210 - 0x209]; // 209
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(StreamingWorld, 0x200);
RED4EXT_ASSERT_OFFSET(StreamingWorld, version, 0x3C);
RED4EXT_ASSERT_OFFSET(StreamingWorld, worldBoundingBox, 0x40);
RED4EXT_ASSERT_OFFSET(StreamingWorld, blockRefs, 0x60);
RED4EXT_ASSERT_OFFSET(StreamingWorld, environmentDefinition, 0x80);
RED4EXT_ASSERT_OFFSET(StreamingWorld, persistentStateData, 0x98);
RED4EXT_ASSERT_OFFSET(StreamingWorld, deviceResource, 0xB0);
RED4EXT_ASSERT_OFFSET(StreamingWorld, deviceInitResource, 0xC8);
RED4EXT_ASSERT_OFFSET(StreamingWorld, mappinResource, 0xE0);
RED4EXT_ASSERT_OFFSET(StreamingWorld, poiMappinResource, 0xF8);
RED4EXT_ASSERT_OFFSET(StreamingWorld, areaResource, 0x110);
RED4EXT_ASSERT_OFFSET(StreamingWorld, lootResource, 0x128);
RED4EXT_ASSERT_OFFSET(StreamingWorld, locationResource, 0x140);
RED4EXT_ASSERT_OFFSET(StreamingWorld, geometryCacheResource, 0x158);
RED4EXT_ASSERT_OFFSET(StreamingWorld, locomotionPathResource, 0x170);
RED4EXT_ASSERT_OFFSET(StreamingWorld, autoFoliageMapping, 0x178);
RED4EXT_ASSERT_OFFSET(StreamingWorld, trafficPersistentResource, 0x180);
RED4EXT_ASSERT_OFFSET(StreamingWorld, trafficLaneConnectivityResource, 0x188);
RED4EXT_ASSERT_OFFSET(StreamingWorld, trafficLanePolygonsResource, 0x190);
RED4EXT_ASSERT_OFFSET(StreamingWorld, trafficLaneSpotsResource, 0x198);
RED4EXT_ASSERT_OFFSET(StreamingWorld, trafficSpatialRepresentationResource, 0x1A0);
RED4EXT_ASSERT_OFFSET(StreamingWorld, trafficCollisionResource, 0x1A8);
RED4EXT_ASSERT_OFFSET(StreamingWorld, trafficNullAreaCollisionResource, 0x1B0);
RED4EXT_ASSERT_OFFSET(StreamingWorld, smartObjectCompiledRootResource, 0x1B8);
RED4EXT_ASSERT_OFFSET(StreamingWorld, streamingQueryDataResource, 0x1C0);
RED4EXT_ASSERT_OFFSET(StreamingWorld, wasBuiltForSceneRecording, 0x1F8);
#else
RED4EXT_ASSERT_SIZE(StreamingWorld, 0x210);
#endif
} // namespace world
using worldStreamingWorld = world::StreamingWorld;
} // namespace RED4ext

// clang-format on
