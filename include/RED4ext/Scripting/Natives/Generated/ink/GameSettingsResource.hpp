#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/StyleThemeDescriptor.hpp>

namespace RED4ext
{
struct Bink;
struct CResource;
struct JsonResource;
namespace ent { struct EntityTemplate; }
namespace ink { struct FullscreenCompositionResource; }
namespace ink { struct LayersResource; }
namespace ink { struct ShapeCollectionResource; }
namespace ink { struct TextureAtlas; }
namespace ink { struct WidgetLibraryResource; }

namespace ink
{
struct GameSettingsResource : CResource
{
    static constexpr const char* NAME = "inkGameSettingsResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    Ref<ink::FullscreenCompositionResource> compositionResource; // 40
    DynArray<RaRef<ink::TextureAtlas>> permanentTextureAtlases; // 58
    DynArray<RaRef<ink::TextureAtlas>> permanentTextureAtlasesPC; // 68
    DynArray<RaRef<ink::TextureAtlas>> permanentTextureAtlasesDurango; // 78
    DynArray<RaRef<ink::TextureAtlas>> permanentTextureAtlasesOrbis; // 88
    DynArray<RaRef<ink::TextureAtlas>> permanentTextureAtlasesProspero; // 98
    DynArray<RaRef<ink::TextureAtlas>> permanentTextureAtlasesStadiaSwitch; // A8
    DynArray<RaRef<ink::TextureAtlas>> permanentTextureAtlasesStadia; // B8
    DynArray<RaRef<ink::TextureAtlas>> permanentTextureAtlasesStadiaDurango; // C8
    DynArray<RaRef<ink::TextureAtlas>> permanentTextureAtlasesStadiaOrbis; // D8
    DynArray<RaRef<ink::TextureAtlas>> permanentTextureAtlasesSwitch; // E8
    DynArray<RaRef<ink::TextureAtlas>> permanentTextureAtlasesSwitchTouch; // F8
    uint8_t unk108[0x118 - 0x108]; // 108
    Ref<ink::LayersResource> layersResource; // 118
    Ref<ink::ShapeCollectionResource> defaultShapeCollectionResource; // 130
    uint8_t unk148[0x160 - 0x148]; // 148
    RaRef<ink::TextureAtlas> iconReferenceFallbackTextureAtlas; // 160
    RaRef<Bink> initLoadingScreenLogoLoopVideo; // 168
    RaRef<JsonResource> globalTVBinkLengthDataResource; // 170
    RaRef<ink::WidgetLibraryResource> npcNameplateResource; // 178
    RaRef<ink::WidgetLibraryResource> worldMapFloorplanWidgetResource; // 180
    RaRef<CResource> malePresetResource; // 188
    RaRef<CResource> femalePresetResource; // 190
    RaRef<CResource> fallbackHeadCustomizationFpp; // 198
    RaRef<CResource> fallbackHeadCustomizationTpp; // 1A0
    RaRef<CResource> fallbackHeadCustomizationTppFaceRig; // 1A8
    RaRef<CResource> fallbackBodyCustomization; // 1B0
    RaRef<CResource> fallbackArmsCustomization; // 1B8
    RaRef<CResource> vsetSceneResource; // 1C0
    RaRef<ent::EntityTemplate> gpsAugmentedRealitySignEntity; // 1C8
    RaRef<ink::WidgetLibraryResource> gpsAugmentedRealityWidgetTurnLeft; // 1D0
    RaRef<ink::WidgetLibraryResource> gpsAugmentedRealityWidgetTurnRight; // 1D8
    RaRef<ink::WidgetLibraryResource> gpsAugmentedRealityWidgetTurnBack; // 1E0
    RaRef<ink::TextureAtlas> keyboardIconsAtlas; // 1E8
    RaRef<ink::TextureAtlas> steamIconsAtlas; // 1F0
    RaRef<ink::TextureAtlas> durangoIconsAtlas; // 1F8
    RaRef<ink::TextureAtlas> orbisIconsAtlas; // 200
    RaRef<ink::TextureAtlas> prosperoIconsAtlas; // 208
    RaRef<ink::TextureAtlas> nintendoSwitchIconsAtlas; // 210
    RaRef<ink::TextureAtlas> nintendoSwitchTouchIconsAtlas; // 218
    RaRef<ink::TextureAtlas> stadiaIconsAtlas; // 220
    RaRef<ink::TextureAtlas> stadiaDurangoIconsAtlas; // 228
    RaRef<ink::TextureAtlas> stadiaOrbisIconsAtlas; // 230
    uint8_t unk238[0x248 - 0x238]; // 238
    DynArray<ink::StyleThemeDescriptor> themes; // 248
    uint8_t unk258[0x260 - 0x258]; // 258
#else
    Ref<ink::FullscreenCompositionResource> compositionResource; // 40
    DynArray<RaRef<ink::TextureAtlas>> permanentTextureAtlases; // 58
    DynArray<RaRef<ink::TextureAtlas>> permanentTextureAtlasesPC; // 68
    DynArray<RaRef<ink::TextureAtlas>> permanentTextureAtlasesDurango; // 78
    DynArray<RaRef<ink::TextureAtlas>> permanentTextureAtlasesOrbis; // 88
    DynArray<RaRef<ink::TextureAtlas>> permanentTextureAtlasesProspero; // 98
    DynArray<RaRef<ink::TextureAtlas>> permanentTextureAtlasesStadiaSwitch; // A8
    DynArray<RaRef<ink::TextureAtlas>> permanentTextureAtlasesStadia; // B8
    DynArray<RaRef<ink::TextureAtlas>> permanentTextureAtlasesStadiaDurango; // C8
    DynArray<RaRef<ink::TextureAtlas>> permanentTextureAtlasesStadiaOrbis; // D8
    DynArray<RaRef<ink::TextureAtlas>> permanentTextureAtlasesSwitch; // E8
    DynArray<RaRef<ink::TextureAtlas>> permanentTextureAtlasesSwitchTouch; // F8
    uint8_t unk108[0x118 - 0x108]; // 108
    Ref<ink::LayersResource> layersResource; // 118
    Ref<ink::ShapeCollectionResource> defaultShapeCollectionResource; // 130
    uint8_t unk148[0x160 - 0x148]; // 148
    RaRef<ink::TextureAtlas> iconReferenceFallbackTextureAtlas; // 160
    RaRef<Bink> initLoadingScreenLogoLoopVideo; // 168
    RaRef<JsonResource> globalTVBinkLengthDataResource; // 170
    RaRef<ink::WidgetLibraryResource> npcNameplateResource; // 178
    RaRef<ink::WidgetLibraryResource> worldMapFloorplanWidgetResource; // 180
    RaRef<CResource> malePresetResource; // 188
    RaRef<CResource> femalePresetResource; // 190
    RaRef<CResource> fallbackHeadCustomizationFpp; // 198
    RaRef<CResource> fallbackHeadCustomizationTpp; // 1A0
    RaRef<CResource> fallbackHeadCustomizationTppFaceRig; // 1A8
    RaRef<CResource> fallbackBodyCustomization; // 1B0
    RaRef<CResource> fallbackArmsCustomization; // 1B8
    RaRef<CResource> vsetSceneResource; // 1C0
    RaRef<ent::EntityTemplate> gpsAugmentedRealitySignEntity; // 1C8
    RaRef<ink::WidgetLibraryResource> gpsAugmentedRealityWidgetTurnLeft; // 1D0
    RaRef<ink::WidgetLibraryResource> gpsAugmentedRealityWidgetTurnRight; // 1D8
    RaRef<ink::WidgetLibraryResource> gpsAugmentedRealityWidgetTurnBack; // 1E0
    RaRef<ink::TextureAtlas> keyboardIconsAtlas; // 1E8
    RaRef<ink::TextureAtlas> steamIconsAtlas; // 1F0
    RaRef<ink::TextureAtlas> durangoIconsAtlas; // 1F8
    RaRef<ink::TextureAtlas> orbisIconsAtlas; // 200
    RaRef<ink::TextureAtlas> prosperoIconsAtlas; // 208
    RaRef<ink::TextureAtlas> nintendoSwitchIconsAtlas; // 210
    RaRef<ink::TextureAtlas> nintendoSwitchTouchIconsAtlas; // 218
    RaRef<ink::TextureAtlas> stadiaIconsAtlas; // 220
    RaRef<ink::TextureAtlas> stadiaDurangoIconsAtlas; // 228
    RaRef<ink::TextureAtlas> stadiaOrbisIconsAtlas; // 230
    uint8_t unk238[0x248 - 0x238]; // 238
    DynArray<ink::StyleThemeDescriptor> themes; // 248
    uint8_t unk258[0x260 - 0x258]; // 258
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(GameSettingsResource, 0x260);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, compositionResource, 0x40);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, permanentTextureAtlases, 0x58);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, permanentTextureAtlasesPC, 0x68);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, permanentTextureAtlasesDurango, 0x78);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, permanentTextureAtlasesOrbis, 0x88);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, permanentTextureAtlasesProspero, 0x98);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, permanentTextureAtlasesStadiaSwitch, 0xA8);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, permanentTextureAtlasesStadia, 0xB8);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, permanentTextureAtlasesStadiaDurango, 0xC8);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, permanentTextureAtlasesStadiaOrbis, 0xD8);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, permanentTextureAtlasesSwitch, 0xE8);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, permanentTextureAtlasesSwitchTouch, 0xF8);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, layersResource, 0x118);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, defaultShapeCollectionResource, 0x130);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, iconReferenceFallbackTextureAtlas, 0x160);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, initLoadingScreenLogoLoopVideo, 0x168);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, globalTVBinkLengthDataResource, 0x170);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, npcNameplateResource, 0x178);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, worldMapFloorplanWidgetResource, 0x180);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, malePresetResource, 0x188);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, femalePresetResource, 0x190);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, fallbackHeadCustomizationFpp, 0x198);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, fallbackHeadCustomizationTpp, 0x1A0);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, fallbackHeadCustomizationTppFaceRig, 0x1A8);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, fallbackBodyCustomization, 0x1B0);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, fallbackArmsCustomization, 0x1B8);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, vsetSceneResource, 0x1C0);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, gpsAugmentedRealitySignEntity, 0x1C8);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, gpsAugmentedRealityWidgetTurnLeft, 0x1D0);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, gpsAugmentedRealityWidgetTurnRight, 0x1D8);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, gpsAugmentedRealityWidgetTurnBack, 0x1E0);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, keyboardIconsAtlas, 0x1E8);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, steamIconsAtlas, 0x1F0);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, durangoIconsAtlas, 0x1F8);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, orbisIconsAtlas, 0x200);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, prosperoIconsAtlas, 0x208);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, nintendoSwitchIconsAtlas, 0x210);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, nintendoSwitchTouchIconsAtlas, 0x218);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, stadiaIconsAtlas, 0x220);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, stadiaDurangoIconsAtlas, 0x228);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, stadiaOrbisIconsAtlas, 0x230);
RED4EXT_ASSERT_OFFSET(GameSettingsResource, themes, 0x248);
#else
RED4EXT_ASSERT_SIZE(GameSettingsResource, 0x260);
#endif
} // namespace ink
using inkGameSettingsResource = ink::GameSettingsResource;
} // namespace RED4ext

// clang-format on
