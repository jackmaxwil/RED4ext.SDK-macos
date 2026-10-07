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

struct CTextureArray : ITexture
{
    static constexpr const char* NAME = "CTextureArray";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk3C[0x60 - 0x3C]; // 3C
    STextureGroupSetup setup; // 60
    Handle<IRenderResourceBlob> renderResourceBlob; // 70
    uint8_t unk80[0x88 - 0x80]; // 80
    rend::RenderTextureResource renderTextureResource; // 88
#else
    uint8_t unk40[0x60 - 0x40]; // 40
    STextureGroupSetup setup; // 60
    Handle<IRenderResourceBlob> renderResourceBlob; // 70
    uint8_t unk80[0x88 - 0x80]; // 80
    rend::RenderTextureResource renderTextureResource; // 88
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CTextureArray, 0x98);
RED4EXT_ASSERT_OFFSET(CTextureArray, setup, 0x60);
RED4EXT_ASSERT_OFFSET(CTextureArray, renderResourceBlob, 0x70);
RED4EXT_ASSERT_OFFSET(CTextureArray, renderTextureResource, 0x88);
#else
RED4EXT_ASSERT_SIZE(CTextureArray, 0x98);
#endif
} // namespace RED4ext

// clang-format on
