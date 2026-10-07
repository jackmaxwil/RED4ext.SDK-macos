#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Node.hpp>

namespace RED4ext
{
namespace world
{
struct InteriorMapNode : world::Node
{
    static constexpr const char* NAME = "worldInteriorMapNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk32[0x34 - 0x32]; // 32
    uint32_t version; // 34
    uint64_t coords; // 38
    DeferredDataBuffer buffer; // 40
#else
    uint32_t version; // 38
    uint8_t unk3C[0x40 - 0x3C]; // 3C
    uint64_t coords; // 40
    DeferredDataBuffer buffer; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(InteriorMapNode, 0x98);
RED4EXT_ASSERT_OFFSET(InteriorMapNode, version, 0x34);
RED4EXT_ASSERT_OFFSET(InteriorMapNode, coords, 0x38);
RED4EXT_ASSERT_OFFSET(InteriorMapNode, buffer, 0x40);
#else
RED4EXT_ASSERT_SIZE(InteriorMapNode, 0xA0);
#endif
} // namespace world
using worldInteriorMapNode = world::InteriorMapNode;
} // namespace RED4ext

// clang-format on
