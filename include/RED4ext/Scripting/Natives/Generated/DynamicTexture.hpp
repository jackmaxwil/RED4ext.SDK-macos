#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/DynamicTextureDataFormat.hpp>
#include <RED4ext/Scripting/Natives/Generated/ITexture.hpp>

namespace RED4ext
{
struct IDynamicTextureGenerator;

struct DynamicTexture : ITexture
{
    static constexpr const char* NAME = "DynamicTexture";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint32_t width; // 3C
    uint32_t height; // 40
    bool scaleToViewport; // 44
    uint8_t unk45[0x48 - 0x45]; // 45
    float viewportScale; // 48
    uint8_t unk4C[0x54 - 0x4C]; // 4C
    DynamicTextureDataFormat dataFormat; // 54
    bool mipChain; // 55
    uint8_t samplesCount; // 56
    uint8_t unk57[0x88 - 0x57]; // 57
    Handle<IDynamicTextureGenerator> generator; // 88
    uint8_t unk98[0xA8 - 0x98]; // 98
#else
    uint32_t width; // 40
    uint32_t height; // 44
    bool scaleToViewport; // 48
    uint8_t unk49[0x4C - 0x49]; // 49
    float viewportScale; // 4C
    uint8_t unk50[0x58 - 0x50]; // 50
    DynamicTextureDataFormat dataFormat; // 58
    bool mipChain; // 59
    uint8_t samplesCount; // 5A
    uint8_t unk5B[0x88 - 0x5B]; // 5B
    Handle<IDynamicTextureGenerator> generator; // 88
    uint8_t unk98[0xA8 - 0x98]; // 98
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(DynamicTexture, 0xA8);
RED4EXT_ASSERT_OFFSET(DynamicTexture, width, 0x3C);
RED4EXT_ASSERT_OFFSET(DynamicTexture, height, 0x40);
RED4EXT_ASSERT_OFFSET(DynamicTexture, scaleToViewport, 0x44);
RED4EXT_ASSERT_OFFSET(DynamicTexture, viewportScale, 0x48);
RED4EXT_ASSERT_OFFSET(DynamicTexture, dataFormat, 0x54);
RED4EXT_ASSERT_OFFSET(DynamicTexture, mipChain, 0x55);
RED4EXT_ASSERT_OFFSET(DynamicTexture, samplesCount, 0x56);
RED4EXT_ASSERT_OFFSET(DynamicTexture, generator, 0x88);
#else
RED4EXT_ASSERT_SIZE(DynamicTexture, 0xA8);
#endif
} // namespace RED4ext

// clang-format on
