#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/res/StreamedResource.hpp>

namespace RED4ext
{
struct CGIDataResource : res::StreamedResource
{
    static constexpr const char* NAME = "CGIDataResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DeferredDataBuffer data; // 40
    uint64_t sectorHash; // 98
#else
    DeferredDataBuffer data; // 40
    uint64_t sectorHash; // 98
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CGIDataResource, 0xA0);
RED4EXT_ASSERT_OFFSET(CGIDataResource, data, 0x40);
RED4EXT_ASSERT_OFFSET(CGIDataResource, sectorHash, 0x98);
#else
RED4EXT_ASSERT_SIZE(CGIDataResource, 0xA0);
#endif
} // namespace RED4ext

// clang-format on
