#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector3.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Node.hpp>

namespace RED4ext
{
namespace world
{
struct StaticVectorFieldNode : world::Node
{
    static constexpr const char* NAME = "worldStaticVectorFieldNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk32[0x34 - 0x32]; // 32
    Vector3 direction; // 34
    float autoHideDistance; // 40
    uint8_t unk44[0x48 - 0x44]; // 44
#else
    Vector3 direction; // 38
    float autoHideDistance; // 44
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(StaticVectorFieldNode, 0x48);
RED4EXT_ASSERT_OFFSET(StaticVectorFieldNode, direction, 0x34);
RED4EXT_ASSERT_OFFSET(StaticVectorFieldNode, autoHideDistance, 0x40);
#else
RED4EXT_ASSERT_SIZE(StaticVectorFieldNode, 0x48);
#endif
} // namespace world
using worldStaticVectorFieldNode = world::StaticVectorFieldNode;
} // namespace RED4ext

// clang-format on
