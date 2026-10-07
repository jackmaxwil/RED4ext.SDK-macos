#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector3.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/MeshNode.hpp>

namespace RED4ext
{
namespace world
{
struct MirrorNode : world::MeshNode
{
    static constexpr const char* NAME = "worldMirrorNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk5A[0x5C - 0x5A]; // 5A
    Vector3 cullingBoxExtents; // 5C
    Vector3 cullingBoxOffset; // 68
    uint8_t unk74[0x78 - 0x74]; // 74
#else
    Vector3 cullingBoxExtents; // 60
    Vector3 cullingBoxOffset; // 6C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MirrorNode, 0x78);
RED4EXT_ASSERT_OFFSET(MirrorNode, cullingBoxExtents, 0x5C);
RED4EXT_ASSERT_OFFSET(MirrorNode, cullingBoxOffset, 0x68);
#else
RED4EXT_ASSERT_SIZE(MirrorNode, 0x78);
#endif
} // namespace world
using worldMirrorNode = world::MirrorNode;
} // namespace RED4ext

// clang-format on
