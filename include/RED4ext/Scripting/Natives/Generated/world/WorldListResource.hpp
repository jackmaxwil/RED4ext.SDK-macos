#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/WorldListResourceEntry.hpp>

namespace RED4ext
{
namespace world
{
struct WorldListResource : CResource
{
    static constexpr const char* NAME = "worldWorldListResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<world::WorldListResourceEntry> worlds; // 40
#else
    DynArray<world::WorldListResourceEntry> worlds; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(WorldListResource, 0x50);
RED4EXT_ASSERT_OFFSET(WorldListResource, worlds, 0x40);
#else
RED4EXT_ASSERT_SIZE(WorldListResource, 0x50);
#endif
} // namespace world
using worldWorldListResource = world::WorldListResource;
} // namespace RED4ext

// clang-format on
