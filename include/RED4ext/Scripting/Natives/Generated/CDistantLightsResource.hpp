#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/res/StreamedResource.hpp>

namespace RED4ext
{
struct CDistantLightsResource : res::StreamedResource
{
    static constexpr const char* NAME = "CDistantLightsResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DataBuffer data; // 40
#else
    DataBuffer data; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CDistantLightsResource, 0x68);
RED4EXT_ASSERT_OFFSET(CDistantLightsResource, data, 0x40);
#else
RED4EXT_ASSERT_SIZE(CDistantLightsResource, 0x68);
#endif
} // namespace RED4ext

// clang-format on
