#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/LeafWidget.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/MaskDataSource.hpp>

namespace RED4ext
{
namespace ink { struct TextureAtlas; }

namespace ink
{
struct __declspec(align(0x10)) MaskWidget : ink::LeafWidget
{
    static constexpr const char* NAME = "inkMaskWidget";
    static constexpr const char* ALIAS = "inkMask";

#ifdef __APPLE__
    uint8_t unk1FE[0x204 - 0x1FE]; // 1FE
    float maskTransparency; // 204
    RaRef<ink::TextureAtlas> textureAtlas; // 208
    CName dynamicTextureMask; // 210
    CName texturePart; // 218
    ink::MaskDataSource dataSource; // 220
    bool invertMask; // 221
    uint8_t unk222[0x270 - 0x222]; // 222
#else
    uint8_t unk200[0x208 - 0x200]; // 200
    float maskTransparency; // 208
    uint8_t unk20C[0x210 - 0x20C]; // 20C
    RaRef<ink::TextureAtlas> textureAtlas; // 210
    CName dynamicTextureMask; // 218
    CName texturePart; // 220
    ink::MaskDataSource dataSource; // 228
    bool invertMask; // 229
    uint8_t unk22A[0x280 - 0x22A]; // 22A
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MaskWidget, 0x270);
RED4EXT_ASSERT_OFFSET(MaskWidget, maskTransparency, 0x204);
RED4EXT_ASSERT_OFFSET(MaskWidget, textureAtlas, 0x208);
RED4EXT_ASSERT_OFFSET(MaskWidget, dynamicTextureMask, 0x210);
RED4EXT_ASSERT_OFFSET(MaskWidget, texturePart, 0x218);
RED4EXT_ASSERT_OFFSET(MaskWidget, dataSource, 0x220);
RED4EXT_ASSERT_OFFSET(MaskWidget, invertMask, 0x221);
#else
RED4EXT_ASSERT_SIZE(MaskWidget, 0x280);
#endif
} // namespace ink
using inkMaskWidget = ink::MaskWidget;
using inkMask = ink::MaskWidget;
} // namespace RED4ext

// clang-format on
