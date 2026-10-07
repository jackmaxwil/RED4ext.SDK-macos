#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/EMeshStreamType.hpp>

namespace RED4ext
{
struct SMeshStream
{
    static constexpr const char* NAME = "SMeshStream";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk00[0x8 - 0x0]; // 0
    DeferredDataBuffer data; // 08
    EMeshStreamType type; // 60
    uint8_t unk64[0x68 - 0x64]; // 64
#else
    DeferredDataBuffer data; // 00
    EMeshStreamType type; // 58
    uint8_t unk5C[0x60 - 0x5C]; // 5C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SMeshStream, 0x68);
RED4EXT_ASSERT_OFFSET(SMeshStream, data, 0x8);
RED4EXT_ASSERT_OFFSET(SMeshStream, type, 0x60);
#else
RED4EXT_ASSERT_SIZE(SMeshStream, 0x60);
#endif
} // namespace RED4ext

// clang-format on
