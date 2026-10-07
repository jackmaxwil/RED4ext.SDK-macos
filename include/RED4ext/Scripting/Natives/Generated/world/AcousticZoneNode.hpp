#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Node.hpp>

namespace RED4ext
{
namespace world
{
struct AcousticZoneNode : world::Node
{
    static constexpr const char* NAME = "worldAcousticZoneNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool isBlocker; // 32
    uint8_t unk33[0x38 - 0x33]; // 33
    CName tagName; // 38
    float tagSpread; // 40
    uint8_t unk44[0x48 - 0x44]; // 44
#else
    bool isBlocker; // 38
    uint8_t unk39[0x40 - 0x39]; // 39
    CName tagName; // 40
    float tagSpread; // 48
    uint8_t unk4C[0x50 - 0x4C]; // 4C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AcousticZoneNode, 0x48);
RED4EXT_ASSERT_OFFSET(AcousticZoneNode, isBlocker, 0x32);
RED4EXT_ASSERT_OFFSET(AcousticZoneNode, tagName, 0x38);
RED4EXT_ASSERT_OFFSET(AcousticZoneNode, tagSpread, 0x40);
#else
RED4EXT_ASSERT_SIZE(AcousticZoneNode, 0x50);
#endif
} // namespace world
using worldAcousticZoneNode = world::AcousticZoneNode;
} // namespace RED4ext

// clang-format on
