#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>

namespace RED4ext
{
namespace world { struct BlockoutData; }

namespace world
{
struct BlockoutResource : CResource
{
    static constexpr const char* NAME = "worldBlockoutResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    Handle<world::BlockoutData> blockoutData; // 40
#else
    Handle<world::BlockoutData> blockoutData; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(BlockoutResource, 0x50);
RED4EXT_ASSERT_OFFSET(BlockoutResource, blockoutData, 0x40);
#else
RED4EXT_ASSERT_SIZE(BlockoutResource, 0x50);
#endif
} // namespace world
using worldBlockoutResource = world::BlockoutResource;
} // namespace RED4ext

// clang-format on
