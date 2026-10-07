#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/BrushMirrorType.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/BrushTileType.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/EHorizontalAlign.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/EVerticalAlign.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/LeafWidget.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/Margin.hpp>

namespace RED4ext
{
namespace ink { struct TextureAtlas; }

namespace ink
{
struct __declspec(align(0x10)) ImageWidget : ink::LeafWidget
{
    static constexpr const char* NAME = "inkImageWidget";
    static constexpr const char* ALIAS = "inkImage";

#ifdef __APPLE__
    uint8_t unk1FE[0x200 - 0x1FE]; // 1FE
    RaRef<ink::TextureAtlas> textureAtlas; // 200
    CName texturePart; // 208
    CName externalDynamicTexture; // 210
    ink::EHorizontalAlign contentHAlign; // 218
    ink::EVerticalAlign contentVAlign; // 219
    ink::BrushMirrorType mirrorType; // 21A
    ink::BrushTileType tileType; // 21B
    float horizontalTileCrop; // 21C
    float verticalTileCrop; // 220
    bool useExternalDynamicTexture; // 224
    bool useNineSliceScale; // 225
    uint8_t unk226[0x228 - 0x226]; // 226
    ink::Margin nineSliceScale; // 228
    ink::EHorizontalAlign tileHAlign; // 238
    ink::EVerticalAlign tileVAlign; // 239
    uint8_t unk23A[0x338 - 0x23A]; // 23A
#else
    RaRef<ink::TextureAtlas> textureAtlas; // 200
    CName texturePart; // 208
    CName externalDynamicTexture; // 210
    ink::EHorizontalAlign contentHAlign; // 218
    ink::EVerticalAlign contentVAlign; // 219
    ink::BrushMirrorType mirrorType; // 21A
    ink::BrushTileType tileType; // 21B
    float horizontalTileCrop; // 21C
    float verticalTileCrop; // 220
    bool useExternalDynamicTexture; // 224
    bool useNineSliceScale; // 225
    uint8_t unk226[0x228 - 0x226]; // 226
    ink::Margin nineSliceScale; // 228
    ink::EHorizontalAlign tileHAlign; // 238
    ink::EVerticalAlign tileVAlign; // 239
    uint8_t unk23A[0x340 - 0x23A]; // 23A
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ImageWidget, 0x340);
RED4EXT_ASSERT_OFFSET(ImageWidget, textureAtlas, 0x200);
RED4EXT_ASSERT_OFFSET(ImageWidget, texturePart, 0x208);
RED4EXT_ASSERT_OFFSET(ImageWidget, externalDynamicTexture, 0x210);
RED4EXT_ASSERT_OFFSET(ImageWidget, contentHAlign, 0x218);
RED4EXT_ASSERT_OFFSET(ImageWidget, contentVAlign, 0x219);
RED4EXT_ASSERT_OFFSET(ImageWidget, mirrorType, 0x21A);
RED4EXT_ASSERT_OFFSET(ImageWidget, tileType, 0x21B);
RED4EXT_ASSERT_OFFSET(ImageWidget, horizontalTileCrop, 0x21C);
RED4EXT_ASSERT_OFFSET(ImageWidget, verticalTileCrop, 0x220);
RED4EXT_ASSERT_OFFSET(ImageWidget, useExternalDynamicTexture, 0x224);
RED4EXT_ASSERT_OFFSET(ImageWidget, useNineSliceScale, 0x225);
RED4EXT_ASSERT_OFFSET(ImageWidget, nineSliceScale, 0x228);
RED4EXT_ASSERT_OFFSET(ImageWidget, tileHAlign, 0x238);
RED4EXT_ASSERT_OFFSET(ImageWidget, tileVAlign, 0x239);
#else
RED4EXT_ASSERT_SIZE(ImageWidget, 0x340);
#endif
} // namespace ink
using inkImageWidget = ink::ImageWidget;
using inkImage = ink::ImageWidget;
} // namespace RED4ext

// clang-format on
