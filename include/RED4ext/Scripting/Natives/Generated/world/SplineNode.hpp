#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/SocketNode.hpp>

namespace RED4ext
{
struct Spline;

namespace world
{
struct SplineNode : world::SocketNode
{
    static constexpr const char* NAME = "worldSplineNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk32[0x40 - 0x32]; // 32
    Handle<Spline> splineData; // 40
    NodeRef destSnapedNode; // 50
    CName destSnapedSocketName; // 58
    NodeRef entrySnapedNode; // 60
    CName entrySnapedSocketName; // 68
#else
    uint8_t unk38[0x40 - 0x38]; // 38
    Handle<Spline> splineData; // 40
    NodeRef destSnapedNode; // 50
    CName destSnapedSocketName; // 58
    NodeRef entrySnapedNode; // 60
    CName entrySnapedSocketName; // 68
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SplineNode, 0x70);
RED4EXT_ASSERT_OFFSET(SplineNode, splineData, 0x40);
RED4EXT_ASSERT_OFFSET(SplineNode, destSnapedNode, 0x50);
RED4EXT_ASSERT_OFFSET(SplineNode, destSnapedSocketName, 0x58);
RED4EXT_ASSERT_OFFSET(SplineNode, entrySnapedNode, 0x60);
RED4EXT_ASSERT_OFFSET(SplineNode, entrySnapedSocketName, 0x68);
#else
RED4EXT_ASSERT_SIZE(SplineNode, 0x70);
#endif
} // namespace world
using worldSplineNode = world::SplineNode;
} // namespace RED4ext

// clang-format on
