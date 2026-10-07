#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/AutoFoliageMappingItem.hpp>

namespace RED4ext
{
namespace world
{
struct AutoFoliageMapping : CResource
{
    static constexpr const char* NAME = "worldAutoFoliageMapping";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<world::AutoFoliageMappingItem> Items; // 40
#else
    DynArray<world::AutoFoliageMappingItem> Items; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AutoFoliageMapping, 0x50);
RED4EXT_ASSERT_OFFSET(AutoFoliageMapping, Items, 0x40);
#else
RED4EXT_ASSERT_SIZE(AutoFoliageMapping, 0x50);
#endif
} // namespace world
using worldAutoFoliageMapping = world::AutoFoliageMapping;
} // namespace RED4ext

// clang-format on
