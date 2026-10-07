#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/red/TagList.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/SocketNode.hpp>

namespace RED4ext
{
namespace world { struct IMarker; }

namespace world
{
struct StaticMarkerNode : world::SocketNode
{
    static constexpr const char* NAME = "worldStaticMarkerNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk32[0x38 - 0x32]; // 32
    Handle<world::IMarker> data; // 38
    red::TagList tags; // 48
    bool isEnabled; // 58
    uint8_t unk59[0x60 - 0x59]; // 59
#else
    Handle<world::IMarker> data; // 38
    red::TagList tags; // 48
    bool isEnabled; // 58
    uint8_t unk59[0x60 - 0x59]; // 59
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(StaticMarkerNode, 0x60);
RED4EXT_ASSERT_OFFSET(StaticMarkerNode, data, 0x38);
RED4EXT_ASSERT_OFFSET(StaticMarkerNode, tags, 0x48);
RED4EXT_ASSERT_OFFSET(StaticMarkerNode, isEnabled, 0x58);
#else
RED4EXT_ASSERT_SIZE(StaticMarkerNode, 0x60);
#endif
} // namespace world
using worldStaticMarkerNode = world::StaticMarkerNode;
} // namespace RED4ext

// clang-format on
