#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>

namespace RED4ext
{
namespace graph { struct GraphDefinition; }

namespace graph
{
struct GraphResource : CResource
{
    static constexpr const char* NAME = "graphGraphResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    Handle<graph::GraphDefinition> graph; // 40
#else
    Handle<graph::GraphDefinition> graph; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(GraphResource, 0x50);
RED4EXT_ASSERT_OFFSET(GraphResource, graph, 0x40);
#else
RED4EXT_ASSERT_SIZE(GraphResource, 0x50);
#endif
} // namespace graph
using graphGraphResource = graph::GraphResource;
} // namespace RED4ext

// clang-format on
