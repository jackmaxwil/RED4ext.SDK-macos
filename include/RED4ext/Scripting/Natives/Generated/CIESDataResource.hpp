#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>

namespace RED4ext
{
struct CIESDataResource : CResource
{
    static constexpr const char* NAME = "CIESDataResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    NativeArray<uint16_t, 128> samples; // 40
    uint8_t unk140[0x148 - 0x140]; // 140
#else
    uint8_t unk40[0x44 - 0x40]; // 40
    NativeArray<uint16_t, 128> samples; // 44
    uint8_t unk144[0x148 - 0x144]; // 144
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CIESDataResource, 0x148);
RED4EXT_ASSERT_OFFSET(CIESDataResource, samples, 0x40);
#else
RED4EXT_ASSERT_SIZE(CIESDataResource, 0x148);
#endif
} // namespace RED4ext

// clang-format on
