#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/ITexture.hpp>
#include <RED4ext/Scripting/Natives/Generated/STextureGroupSetup.hpp>
#include <RED4ext/Scripting/Natives/Generated/rend/RenderTextureResource.hpp>

namespace RED4ext
{
struct IRenderResourceBlob;

struct CCubeTexture : ITexture
{
    static constexpr const char* NAME = "CCubeTexture";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk3C[0x48 - 0x3C]; // 3C
    uint32_t size; // 48
    STextureGroupSetup setup; // 4C
    uint8_t unk5C[0x68 - 0x5C]; // 5C
    Handle<IRenderResourceBlob> renderResourceBlob; // 68
    uint8_t unk78[0x80 - 0x78]; // 78
    rend::RenderTextureResource renderTextureResource; // 80
    uint8_t unk90[0xA0 - 0x90]; // 90
#else
    uint8_t unk40[0x48 - 0x40]; // 40
    uint32_t size; // 48
    STextureGroupSetup setup; // 4C
    uint8_t unk5C[0x68 - 0x5C]; // 5C
    Handle<IRenderResourceBlob> renderResourceBlob; // 68
    uint8_t unk78[0x80 - 0x78]; // 78
    rend::RenderTextureResource renderTextureResource; // 80
    uint8_t unk90[0xA0 - 0x90]; // 90
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CCubeTexture, 0xA0);
RED4EXT_ASSERT_OFFSET(CCubeTexture, size, 0x48);
RED4EXT_ASSERT_OFFSET(CCubeTexture, setup, 0x4C);
RED4EXT_ASSERT_OFFSET(CCubeTexture, renderResourceBlob, 0x68);
RED4EXT_ASSERT_OFFSET(CCubeTexture, renderTextureResource, 0x80);
#else
RED4EXT_ASSERT_SIZE(CCubeTexture, 0xA0);
#endif
} // namespace RED4ext

// clang-format on
