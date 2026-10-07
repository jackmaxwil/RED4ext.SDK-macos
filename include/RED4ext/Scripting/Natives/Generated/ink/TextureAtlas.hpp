#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/DynamicTextureSlot.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/ETextureResolution.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/TextureAtlasMapper.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/TextureAtlasSlice.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/TextureType.hpp>

namespace RED4ext
{
struct CBitmapTexture;
struct DynamicTexture;

namespace ink
{
struct TextureAtlas : CResource
{
    static constexpr const char* NAME = "inkTextureAtlas";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    ink::TextureType activeTexture; // 39
    ink::ETextureResolution textureResolution; // 3A
    uint8_t unk3B[0x40 - 0x3B]; // 3B
    RaRef<CBitmapTexture> texture; // 40
    uint8_t unk48[0x58 - 0x48]; // 48
    RaRef<DynamicTexture> dynamicTexture; // 58
    uint8_t unk60[0x70 - 0x60]; // 60
    DynArray<ink::TextureAtlasSlice> slices; // 70
    DynArray<ink::TextureAtlasMapper> parts; // 80
    std::array<uint8_t, 120>/* UNHANDLED: [3]inkTextureSlot (RT_FixedArray) */ slots; // 90
    ink::DynamicTextureSlot dynamicTextureSlot; // 108
    bool isSingleTextureMode; // 120
    uint8_t unk121[0x130 - 0x121]; // 121
#else
    ink::TextureType activeTexture; // 40
    ink::ETextureResolution textureResolution; // 41
    uint8_t unk42[0x48 - 0x42]; // 42
    RaRef<CBitmapTexture> texture; // 48
    uint8_t unk50[0x60 - 0x50]; // 50
    RaRef<DynamicTexture> dynamicTexture; // 60
    uint8_t unk68[0x78 - 0x68]; // 68
    DynArray<ink::TextureAtlasSlice> slices; // 78
    DynArray<ink::TextureAtlasMapper> parts; // 88
    std::array<uint8_t, 120>/* UNHANDLED: [3]inkTextureSlot (RT_FixedArray) */ slots; // 98
    ink::DynamicTextureSlot dynamicTextureSlot; // 110
    bool isSingleTextureMode; // 128
    uint8_t unk129[0x138 - 0x129]; // 129
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TextureAtlas, 0x130);
RED4EXT_ASSERT_OFFSET(TextureAtlas, activeTexture, 0x39);
RED4EXT_ASSERT_OFFSET(TextureAtlas, textureResolution, 0x3A);
RED4EXT_ASSERT_OFFSET(TextureAtlas, texture, 0x40);
RED4EXT_ASSERT_OFFSET(TextureAtlas, dynamicTexture, 0x58);
RED4EXT_ASSERT_OFFSET(TextureAtlas, slices, 0x70);
RED4EXT_ASSERT_OFFSET(TextureAtlas, parts, 0x80);
RED4EXT_ASSERT_OFFSET(TextureAtlas, slots, 0x90);
RED4EXT_ASSERT_OFFSET(TextureAtlas, dynamicTextureSlot, 0x108);
RED4EXT_ASSERT_OFFSET(TextureAtlas, isSingleTextureMode, 0x120);
#else
RED4EXT_ASSERT_SIZE(TextureAtlas, 0x138);
#endif
} // namespace ink
using inkTextureAtlas = ink::TextureAtlas;
} // namespace RED4ext

// clang-format on
