#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/StreamingBlockIndex.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/StreamingSectorDescriptor.hpp>

namespace RED4ext
{
namespace world
{
struct StreamingBlock : CResource
{
    static constexpr const char* NAME = "worldStreamingBlock";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<world::StreamingSectorDescriptor> descriptors; // 40
    world::StreamingBlockIndex index; // 50
#else
    DynArray<world::StreamingSectorDescriptor> descriptors; // 40
    world::StreamingBlockIndex index; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(StreamingBlock, 0x58);
RED4EXT_ASSERT_OFFSET(StreamingBlock, descriptors, 0x40);
RED4EXT_ASSERT_OFFSET(StreamingBlock, index, 0x50);
#else
RED4EXT_ASSERT_SIZE(StreamingBlock, 0x58);
#endif
} // namespace world
using worldStreamingBlock = world::StreamingBlock;
} // namespace RED4ext

// clang-format on
