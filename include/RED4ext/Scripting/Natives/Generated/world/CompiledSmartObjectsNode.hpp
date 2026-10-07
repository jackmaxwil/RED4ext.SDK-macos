#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Node.hpp>

namespace RED4ext
{
namespace game { struct SmartObjectsCompiledResource; }

namespace world
{
struct CompiledSmartObjectsNode : world::Node
{
    static constexpr const char* NAME = "worldCompiledSmartObjectsNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk32[0x38 - 0x32]; // 32
    RaRef<game::SmartObjectsCompiledResource> resource; // 38
#else
    RaRef<game::SmartObjectsCompiledResource> resource; // 38
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CompiledSmartObjectsNode, 0x40);
RED4EXT_ASSERT_OFFSET(CompiledSmartObjectsNode, resource, 0x38);
#else
RED4EXT_ASSERT_SIZE(CompiledSmartObjectsNode, 0x40);
#endif
} // namespace world
using worldCompiledSmartObjectsNode = world::CompiledSmartObjectsNode;
} // namespace RED4ext

// clang-format on
