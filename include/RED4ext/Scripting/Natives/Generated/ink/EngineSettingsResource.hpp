#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>

namespace RED4ext
{
struct CBitmapTexture;
struct CMaterialTemplate;
struct IMaterial;
struct JsonResource;
namespace ink { struct FontFamilyResource; }
namespace ink { struct FullscreenCompositionResource; }
namespace ink { struct ShapeCollectionResource; }
namespace ink { struct TextureAtlas; }

namespace ink
{
struct EngineSettingsResource : CResource
{
    static constexpr const char* NAME = "inkEngineSettingsResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    Ref<ink::FullscreenCompositionResource> fallbackCompositionResource; // 40
    Ref<ink::ShapeCollectionResource> fallbackShapeCollectionResource; // 58
    Ref<ink::TextureAtlas> fallbackIconAtlasResource; // 70
    Ref<ink::TextureAtlas> fallbackTextureAtlas; // 88
    Ref<ink::TextureAtlas> whiteMaskAtlas; // A0
    Ref<ink::FontFamilyResource> fallbackFontFamilyPath; // B8
    Ref<CBitmapTexture> blackTexture; // D0
    Ref<CBitmapTexture> advertMissingFormatTexture; // E8
    Ref<CBitmapTexture> advertWrongResourceTexture; // 100
    Ref<CBitmapTexture> tooManyBinksTexture; // 118
    Ref<CBitmapTexture> componentMissingTexture; // 130
    Ref<IMaterial> imageTilingMaterial; // 148
    Ref<IMaterial> imageNineSliceMaterial; // 160
    Ref<IMaterial> depthMaterial; // 178
    Ref<CMaterialTemplate> defaultBinkMaterial; // 190
    RaRef<JsonResource> inputKeyIconsDefinitionResource; // 1A8
#else
    Ref<ink::FullscreenCompositionResource> fallbackCompositionResource; // 40
    Ref<ink::ShapeCollectionResource> fallbackShapeCollectionResource; // 58
    Ref<ink::TextureAtlas> fallbackIconAtlasResource; // 70
    Ref<ink::TextureAtlas> fallbackTextureAtlas; // 88
    Ref<ink::TextureAtlas> whiteMaskAtlas; // A0
    Ref<ink::FontFamilyResource> fallbackFontFamilyPath; // B8
    Ref<CBitmapTexture> blackTexture; // D0
    Ref<CBitmapTexture> advertMissingFormatTexture; // E8
    Ref<CBitmapTexture> advertWrongResourceTexture; // 100
    Ref<CBitmapTexture> tooManyBinksTexture; // 118
    Ref<CBitmapTexture> componentMissingTexture; // 130
    Ref<IMaterial> imageTilingMaterial; // 148
    Ref<IMaterial> imageNineSliceMaterial; // 160
    Ref<IMaterial> depthMaterial; // 178
    Ref<CMaterialTemplate> defaultBinkMaterial; // 190
    RaRef<JsonResource> inputKeyIconsDefinitionResource; // 1A8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(EngineSettingsResource, 0x1B0);
RED4EXT_ASSERT_OFFSET(EngineSettingsResource, fallbackCompositionResource, 0x40);
RED4EXT_ASSERT_OFFSET(EngineSettingsResource, fallbackShapeCollectionResource, 0x58);
RED4EXT_ASSERT_OFFSET(EngineSettingsResource, fallbackIconAtlasResource, 0x70);
RED4EXT_ASSERT_OFFSET(EngineSettingsResource, fallbackTextureAtlas, 0x88);
RED4EXT_ASSERT_OFFSET(EngineSettingsResource, whiteMaskAtlas, 0xA0);
RED4EXT_ASSERT_OFFSET(EngineSettingsResource, fallbackFontFamilyPath, 0xB8);
RED4EXT_ASSERT_OFFSET(EngineSettingsResource, blackTexture, 0xD0);
RED4EXT_ASSERT_OFFSET(EngineSettingsResource, advertMissingFormatTexture, 0xE8);
RED4EXT_ASSERT_OFFSET(EngineSettingsResource, advertWrongResourceTexture, 0x100);
RED4EXT_ASSERT_OFFSET(EngineSettingsResource, tooManyBinksTexture, 0x118);
RED4EXT_ASSERT_OFFSET(EngineSettingsResource, componentMissingTexture, 0x130);
RED4EXT_ASSERT_OFFSET(EngineSettingsResource, imageTilingMaterial, 0x148);
RED4EXT_ASSERT_OFFSET(EngineSettingsResource, imageNineSliceMaterial, 0x160);
RED4EXT_ASSERT_OFFSET(EngineSettingsResource, depthMaterial, 0x178);
RED4EXT_ASSERT_OFFSET(EngineSettingsResource, defaultBinkMaterial, 0x190);
RED4EXT_ASSERT_OFFSET(EngineSettingsResource, inputKeyIconsDefinitionResource, 0x1A8);
#else
RED4EXT_ASSERT_SIZE(EngineSettingsResource, 0x1B0);
#endif
} // namespace ink
using inkEngineSettingsResource = ink::EngineSettingsResource;
} // namespace RED4ext

// clang-format on
