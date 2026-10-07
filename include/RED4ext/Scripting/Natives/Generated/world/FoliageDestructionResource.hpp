#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>

namespace RED4ext
{
namespace world { struct FoliageDestructionMapping; }

namespace world
{
struct FoliageDestructionResource : CResource
{
    static constexpr const char* NAME = "worldFoliageDestructionResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<Handle<world::FoliageDestructionMapping>> mappings; // 40
#else
    DynArray<Handle<world::FoliageDestructionMapping>> mappings; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(FoliageDestructionResource, 0x50);
RED4EXT_ASSERT_OFFSET(FoliageDestructionResource, mappings, 0x40);
#else
RED4EXT_ASSERT_SIZE(FoliageDestructionResource, 0x50);
#endif
} // namespace world
using worldFoliageDestructionResource = world::FoliageDestructionResource;
} // namespace RED4ext

// clang-format on
