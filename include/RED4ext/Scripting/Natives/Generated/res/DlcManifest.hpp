#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>

namespace RED4ext
{
struct CResource;

namespace res
{
struct DlcManifest : CResource
{
    static constexpr const char* NAME = "resDlcManifest";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    RaRef<CResource> tweakBlob; // 40
    RaRef<CResource> quest; // 48
    RaRef<CResource> journal; // 50
    RaRef<CResource> factories; // 58
    RaRef<CResource> weaponAppearances; // 60
    RaRef<CResource> vehicleAppearances; // 68
    RaRef<CResource> communitySpawnsets; // 70
    RaRef<CResource> archetypeSet; // 78
    RaRef<CResource> vehicleCovers; // 80
    RaRef<CResource> cookedAudioMetadata; // 88
    RaRef<CResource> voiceTags; // 90
    RaRef<CResource> widgetsLibrariesOverrides; // 98
    RaRef<CResource> gameDefsList; // A0
    RaRef<CResource> cookedMultilayerSetup; // A8
    RaRef<CResource> visualTagsToAppearanceNames; // B0
    RaRef<CResource> appearanceNameToVisualTags; // B8
    RaRef<CResource> defaultAppearances; // C0
    RaRef<CResource> colorVariantsMap; // C8
#else
    RaRef<CResource> tweakBlob; // 40
    RaRef<CResource> quest; // 48
    RaRef<CResource> journal; // 50
    RaRef<CResource> factories; // 58
    RaRef<CResource> weaponAppearances; // 60
    RaRef<CResource> vehicleAppearances; // 68
    RaRef<CResource> communitySpawnsets; // 70
    RaRef<CResource> archetypeSet; // 78
    RaRef<CResource> vehicleCovers; // 80
    RaRef<CResource> cookedAudioMetadata; // 88
    RaRef<CResource> voiceTags; // 90
    RaRef<CResource> widgetsLibrariesOverrides; // 98
    RaRef<CResource> gameDefsList; // A0
    RaRef<CResource> cookedMultilayerSetup; // A8
    RaRef<CResource> visualTagsToAppearanceNames; // B0
    RaRef<CResource> appearanceNameToVisualTags; // B8
    RaRef<CResource> defaultAppearances; // C0
    RaRef<CResource> colorVariantsMap; // C8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(DlcManifest, 0xD0);
RED4EXT_ASSERT_OFFSET(DlcManifest, tweakBlob, 0x40);
RED4EXT_ASSERT_OFFSET(DlcManifest, quest, 0x48);
RED4EXT_ASSERT_OFFSET(DlcManifest, journal, 0x50);
RED4EXT_ASSERT_OFFSET(DlcManifest, factories, 0x58);
RED4EXT_ASSERT_OFFSET(DlcManifest, weaponAppearances, 0x60);
RED4EXT_ASSERT_OFFSET(DlcManifest, vehicleAppearances, 0x68);
RED4EXT_ASSERT_OFFSET(DlcManifest, communitySpawnsets, 0x70);
RED4EXT_ASSERT_OFFSET(DlcManifest, archetypeSet, 0x78);
RED4EXT_ASSERT_OFFSET(DlcManifest, vehicleCovers, 0x80);
RED4EXT_ASSERT_OFFSET(DlcManifest, cookedAudioMetadata, 0x88);
RED4EXT_ASSERT_OFFSET(DlcManifest, voiceTags, 0x90);
RED4EXT_ASSERT_OFFSET(DlcManifest, widgetsLibrariesOverrides, 0x98);
RED4EXT_ASSERT_OFFSET(DlcManifest, gameDefsList, 0xA0);
RED4EXT_ASSERT_OFFSET(DlcManifest, cookedMultilayerSetup, 0xA8);
RED4EXT_ASSERT_OFFSET(DlcManifest, visualTagsToAppearanceNames, 0xB0);
RED4EXT_ASSERT_OFFSET(DlcManifest, appearanceNameToVisualTags, 0xB8);
RED4EXT_ASSERT_OFFSET(DlcManifest, defaultAppearances, 0xC0);
RED4EXT_ASSERT_OFFSET(DlcManifest, colorVariantsMap, 0xC8);
#else
RED4EXT_ASSERT_SIZE(DlcManifest, 0xD0);
#endif
} // namespace res
using resDlcManifest = res::DlcManifest;
} // namespace RED4ext

// clang-format on
