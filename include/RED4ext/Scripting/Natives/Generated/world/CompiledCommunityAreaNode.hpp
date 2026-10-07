#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/EntityID.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Node.hpp>

namespace RED4ext
{
namespace community { struct Area; }

namespace world
{
struct CompiledCommunityAreaNode : world::Node
{
    static constexpr const char* NAME = "worldCompiledCommunityAreaNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk32[0x38 - 0x32]; // 32
    Handle<community::Area> area; // 38
    ent::EntityID sourceObjectId; // 48
#else
    Handle<community::Area> area; // 38
    ent::EntityID sourceObjectId; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CompiledCommunityAreaNode, 0x50);
RED4EXT_ASSERT_OFFSET(CompiledCommunityAreaNode, area, 0x38);
RED4EXT_ASSERT_OFFSET(CompiledCommunityAreaNode, sourceObjectId, 0x48);
#else
RED4EXT_ASSERT_SIZE(CompiledCommunityAreaNode, 0x50);
#endif
} // namespace world
using worldCompiledCommunityAreaNode = world::CompiledCommunityAreaNode;
} // namespace RED4ext

// clang-format on
