#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/GeometryKey.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/SectorCacheEntry.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/SectorEntry.hpp>

namespace RED4ext
{
namespace physics
{
struct __declspec(align(0x10)) GeometryCache : CResource
{
    static constexpr const char* NAME = "physicsGeometryCache";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<DeferredDataBuffer> bufferTableSectors; // 40
    DynArray<physics::SectorEntry> sectorEntries; // 50
    DynArray<physics::GeometryKey> sectorGeometries; // 60
    DynArray<physics::SectorCacheEntry> sectorCacheEntries; // 70
    DeferredDataBuffer alwaysLoadedSectorDDB; // 80
    uint8_t unkD8[0xE0 - 0xD8]; // D8
    physics::SectorEntry alwaysLoadedSector; // E0
    uint8_t unk120[0x190 - 0x120]; // 120
#else
    DynArray<DeferredDataBuffer> bufferTableSectors; // 40
    DynArray<physics::SectorEntry> sectorEntries; // 50
    DynArray<physics::GeometryKey> sectorGeometries; // 60
    DynArray<physics::SectorCacheEntry> sectorCacheEntries; // 70
    DeferredDataBuffer alwaysLoadedSectorDDB; // 80
    uint8_t unkD8[0xE0 - 0xD8]; // D8
    physics::SectorEntry alwaysLoadedSector; // E0
    uint8_t unk120[0x190 - 0x120]; // 120
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(GeometryCache, 0x190);
RED4EXT_ASSERT_OFFSET(GeometryCache, bufferTableSectors, 0x40);
RED4EXT_ASSERT_OFFSET(GeometryCache, sectorEntries, 0x50);
RED4EXT_ASSERT_OFFSET(GeometryCache, sectorGeometries, 0x60);
RED4EXT_ASSERT_OFFSET(GeometryCache, sectorCacheEntries, 0x70);
RED4EXT_ASSERT_OFFSET(GeometryCache, alwaysLoadedSectorDDB, 0x80);
RED4EXT_ASSERT_OFFSET(GeometryCache, alwaysLoadedSector, 0xE0);
#else
RED4EXT_ASSERT_SIZE(GeometryCache, 0x190);
#endif
} // namespace physics
using physicsGeometryCache = physics::GeometryCache;
} // namespace RED4ext

// clang-format on
