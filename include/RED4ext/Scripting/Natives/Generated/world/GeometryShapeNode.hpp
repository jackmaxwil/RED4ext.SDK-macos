#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/Color.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Node.hpp>

namespace RED4ext
{
struct GeometryShape;

namespace world
{
struct GeometryShapeNode : world::Node
{
    static constexpr const char* NAME = "worldGeometryShapeNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk32[0x38 - 0x32]; // 32
    Handle<GeometryShape> shape; // 38
    Color color; // 48
    uint8_t unk4C[0x4D - 0x4C]; // 4C
#else
    Handle<GeometryShape> shape; // 38
    Color color; // 48
    uint8_t unk4C[0x50 - 0x4C]; // 4C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(GeometryShapeNode, 0x50);
RED4EXT_ASSERT_OFFSET(GeometryShapeNode, shape, 0x38);
RED4EXT_ASSERT_OFFSET(GeometryShapeNode, color, 0x48);
#else
RED4EXT_ASSERT_SIZE(GeometryShapeNode, 0x50);
#endif
} // namespace world
using worldGeometryShapeNode = world::GeometryShapeNode;
} // namespace RED4ext

// clang-format on
