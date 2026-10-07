#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/IWorldWidgetComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/ui/SceneWidgetProperties.hpp>

namespace RED4ext
{
struct CBitmapTexture;
namespace ink { struct WidgetLibraryResource; }

struct __declspec(align(0x10)) WorldWidgetComponent : IWorldWidgetComponent
{
    static constexpr const char* NAME = "WorldWidgetComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk2AC[0x2B8 - 0x2AC]; // 2AC
    Ref<ink::WidgetLibraryResource> cursorResource; // 2B8
    RaRef<ink::WidgetLibraryResource> widgetResource; // 2D0
    RaRef<CBitmapTexture> staticTextureResource; // 2D8
    uint8_t unk2E0[0x2F0 - 0x2E0]; // 2E0
    CName itemNameToSpawn; // 2F0
    float spawnDistanceOverride; // 2F8
    bool limitedSpawnDistanceFromVehicle; // 2FC
    uint8_t unk2FD[0x300 - 0x2FD]; // 2FD
    world::ui::SceneWidgetProperties sceneWidgetProperties; // 300
    uint8_t unk324[0x3A0 - 0x324]; // 324
#else
    uint8_t unk2B0[0x2B8 - 0x2B0]; // 2B0
    Ref<ink::WidgetLibraryResource> cursorResource; // 2B8
    RaRef<ink::WidgetLibraryResource> widgetResource; // 2D0
    RaRef<CBitmapTexture> staticTextureResource; // 2D8
    uint8_t unk2E0[0x2F0 - 0x2E0]; // 2E0
    CName itemNameToSpawn; // 2F0
    float spawnDistanceOverride; // 2F8
    bool limitedSpawnDistanceFromVehicle; // 2FC
    uint8_t unk2FD[0x300 - 0x2FD]; // 2FD
    world::ui::SceneWidgetProperties sceneWidgetProperties; // 300
    uint8_t unk324[0x3A0 - 0x324]; // 324
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(WorldWidgetComponent, 0x3A0);
RED4EXT_ASSERT_OFFSET(WorldWidgetComponent, cursorResource, 0x2B8);
RED4EXT_ASSERT_OFFSET(WorldWidgetComponent, widgetResource, 0x2D0);
RED4EXT_ASSERT_OFFSET(WorldWidgetComponent, staticTextureResource, 0x2D8);
RED4EXT_ASSERT_OFFSET(WorldWidgetComponent, itemNameToSpawn, 0x2F0);
RED4EXT_ASSERT_OFFSET(WorldWidgetComponent, spawnDistanceOverride, 0x2F8);
RED4EXT_ASSERT_OFFSET(WorldWidgetComponent, limitedSpawnDistanceFromVehicle, 0x2FC);
RED4EXT_ASSERT_OFFSET(WorldWidgetComponent, sceneWidgetProperties, 0x300);
#else
RED4EXT_ASSERT_SIZE(WorldWidgetComponent, 0x3A0);
#endif
} // namespace RED4ext

// clang-format on
