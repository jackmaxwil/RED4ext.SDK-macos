#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>

namespace RED4ext
{
namespace world
{
struct HeatmapLayer : CResource
{
    static constexpr const char* NAME = "worldHeatmapLayer";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x50 - 0x39]; // 39
    uint32_t minValue; // 50
    uint32_t maxValue; // 54
    CString name; // 58
    CString units; // 78
    bool invert; // 98
    uint8_t unk99[0xA0 - 0x99]; // 99
#else
    uint8_t unk40[0x50 - 0x40]; // 40
    uint32_t minValue; // 50
    uint32_t maxValue; // 54
    CString name; // 58
    CString units; // 78
    bool invert; // 98
    uint8_t unk99[0xA0 - 0x99]; // 99
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(HeatmapLayer, 0xA0);
RED4EXT_ASSERT_OFFSET(HeatmapLayer, minValue, 0x50);
RED4EXT_ASSERT_OFFSET(HeatmapLayer, maxValue, 0x54);
RED4EXT_ASSERT_OFFSET(HeatmapLayer, name, 0x58);
RED4EXT_ASSERT_OFFSET(HeatmapLayer, units, 0x78);
RED4EXT_ASSERT_OFFSET(HeatmapLayer, invert, 0x98);
#else
RED4EXT_ASSERT_SIZE(HeatmapLayer, 0xA0);
#endif
} // namespace world
using worldHeatmapLayer = world::HeatmapLayer;
} // namespace RED4ext

// clang-format on
