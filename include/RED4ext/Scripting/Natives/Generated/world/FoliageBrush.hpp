#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>

namespace RED4ext
{
namespace world { struct FoliageBrushItem; }

namespace world
{
struct FoliageBrush : CResource
{
    static constexpr const char* NAME = "worldFoliageBrush";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<Handle<world::FoliageBrushItem>> items; // 40
#else
    DynArray<Handle<world::FoliageBrushItem>> items; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(FoliageBrush, 0x50);
RED4EXT_ASSERT_OFFSET(FoliageBrush, items, 0x40);
#else
RED4EXT_ASSERT_SIZE(FoliageBrush, 0x50);
#endif
} // namespace world
using worldFoliageBrush = world::FoliageBrush;
} // namespace RED4ext

// clang-format on
