#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/ISerializable.hpp>

namespace RED4ext
{
namespace vis
{
struct IOccluderResource : ISerializable
{
    static constexpr const char* NAME = "visIOccluderResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint32_t resourceHash; // 30
#else
    uint32_t resourceHash; // 30
    uint8_t unk34[0x38 - 0x34]; // 34
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(IOccluderResource, 0x38);
RED4EXT_ASSERT_OFFSET(IOccluderResource, resourceHash, 0x30);
#else
RED4EXT_ASSERT_SIZE(IOccluderResource, 0x38);
#endif
} // namespace vis
using visIOccluderResource = vis::IOccluderResource;
} // namespace RED4ext

// clang-format on
