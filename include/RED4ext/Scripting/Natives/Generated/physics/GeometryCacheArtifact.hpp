#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/CacheEntry.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/CacheKey.hpp>

namespace RED4ext
{
namespace physics
{
struct GeometryCacheArtifact : CResource
{
    static constexpr const char* NAME = "physicsGeometryCacheArtifact";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DeferredDataBuffer buffer; // 40
    DynArray<physics::CacheKey> entryKeys; // 98
    DynArray<physics::CacheEntry> entryTable; // A8
#else
    DeferredDataBuffer buffer; // 40
    DynArray<physics::CacheKey> entryKeys; // 98
    DynArray<physics::CacheEntry> entryTable; // A8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(GeometryCacheArtifact, 0xB8);
RED4EXT_ASSERT_OFFSET(GeometryCacheArtifact, buffer, 0x40);
RED4EXT_ASSERT_OFFSET(GeometryCacheArtifact, entryKeys, 0x98);
RED4EXT_ASSERT_OFFSET(GeometryCacheArtifact, entryTable, 0xA8);
#else
RED4EXT_ASSERT_SIZE(GeometryCacheArtifact, 0xB8);
#endif
} // namespace physics
using physicsGeometryCacheArtifact = physics::GeometryCacheArtifact;
} // namespace RED4ext

// clang-format on
