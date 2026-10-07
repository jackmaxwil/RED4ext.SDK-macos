#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Node.hpp>

namespace RED4ext
{
namespace world
{
struct AcousticPortalNode : world::Node
{
    static constexpr const char* NAME = "worldAcousticPortalNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t radius; // 32
    uint8_t nominalRadius; // 33
    uint8_t unk34[0x38 - 0x34]; // 34
#else
    uint8_t radius; // 38
    uint8_t nominalRadius; // 39
    uint8_t unk3A[0x40 - 0x3A]; // 3A
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AcousticPortalNode, 0x38);
RED4EXT_ASSERT_OFFSET(AcousticPortalNode, radius, 0x32);
RED4EXT_ASSERT_OFFSET(AcousticPortalNode, nominalRadius, 0x33);
#else
RED4EXT_ASSERT_SIZE(AcousticPortalNode, 0x40);
#endif
} // namespace world
using worldAcousticPortalNode = world::AcousticPortalNode;
} // namespace RED4ext

// clang-format on
