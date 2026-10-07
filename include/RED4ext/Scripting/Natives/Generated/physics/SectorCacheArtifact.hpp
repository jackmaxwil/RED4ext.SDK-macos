#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/Box.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/GeometryKey.hpp>

namespace RED4ext
{
namespace physics { struct GeometryCacheArtifact; }

namespace physics
{
struct __declspec(align(0x10)) SectorCacheArtifact : CResource
{
    static constexpr const char* NAME = "physicsSectorCacheArtifact";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    Handle<physics::GeometryCacheArtifact> sectorInPlaceGeometry; // 40
    DynArray<physics::GeometryKey> sectorGeometryKeys; // 50
    Box sectorBounds; // 60
#else
    Handle<physics::GeometryCacheArtifact> sectorInPlaceGeometry; // 40
    DynArray<physics::GeometryKey> sectorGeometryKeys; // 50
    Box sectorBounds; // 60
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SectorCacheArtifact, 0x80);
RED4EXT_ASSERT_OFFSET(SectorCacheArtifact, sectorInPlaceGeometry, 0x40);
RED4EXT_ASSERT_OFFSET(SectorCacheArtifact, sectorGeometryKeys, 0x50);
RED4EXT_ASSERT_OFFSET(SectorCacheArtifact, sectorBounds, 0x60);
#else
RED4EXT_ASSERT_SIZE(SectorCacheArtifact, 0x80);
#endif
} // namespace physics
using physicsSectorCacheArtifact = physics::SectorCacheArtifact;
} // namespace RED4ext

// clang-format on
