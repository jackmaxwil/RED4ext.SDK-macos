#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/rend/GIGroup.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/GeometryShapeNode.hpp>

namespace RED4ext
{
namespace world
{
struct GIShapeNode : world::GeometryShapeNode
{
    static constexpr const char* NAME = "worldGIShapeNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    rend::GIGroup group; // 4D
    uint8_t unk4E[0x50 - 0x4E]; // 4E
    uint32_t priority; // 50
    bool interior; // 54
    bool runtime; // 55
    uint8_t unk56[0x57 - 0x56]; // 56
    bool updated; // 57
#else
    rend::GIGroup group; // 50
    uint8_t unk51[0x54 - 0x51]; // 51
    uint32_t priority; // 54
    bool interior; // 58
    bool runtime; // 59
    uint8_t unk5A[0x5B - 0x5A]; // 5A
    bool updated; // 5B
    uint8_t unk5C[0x60 - 0x5C]; // 5C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(GIShapeNode, 0x58);
RED4EXT_ASSERT_OFFSET(GIShapeNode, group, 0x4D);
RED4EXT_ASSERT_OFFSET(GIShapeNode, priority, 0x50);
RED4EXT_ASSERT_OFFSET(GIShapeNode, interior, 0x54);
RED4EXT_ASSERT_OFFSET(GIShapeNode, runtime, 0x55);
RED4EXT_ASSERT_OFFSET(GIShapeNode, updated, 0x57);
#else
RED4EXT_ASSERT_SIZE(GIShapeNode, 0x60);
#endif
} // namespace world
using worldGIShapeNode = world::GIShapeNode;
} // namespace RED4ext

// clang-format on
