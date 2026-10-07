#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/CompositionPreset.hpp>

namespace RED4ext
{
struct CBitmapTexture;
namespace ink { struct CompositionPreviewSettings; }

namespace ink
{
struct FullscreenCompositionResource : CResource
{
    static constexpr const char* NAME = "inkFullscreenCompositionResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<ink::CompositionPreset> compositionPresets; // 40
    Handle<ink::CompositionPreviewSettings> previewSettings; // 50
    RaRef<CBitmapTexture> backgroundMenuTextureUHDRes; // 60
    RaRef<CBitmapTexture> backgroundMenuTextureFHDRes; // 68
#else
    DynArray<ink::CompositionPreset> compositionPresets; // 40
    Handle<ink::CompositionPreviewSettings> previewSettings; // 50
    RaRef<CBitmapTexture> backgroundMenuTextureUHDRes; // 60
    RaRef<CBitmapTexture> backgroundMenuTextureFHDRes; // 68
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(FullscreenCompositionResource, 0x70);
RED4EXT_ASSERT_OFFSET(FullscreenCompositionResource, compositionPresets, 0x40);
RED4EXT_ASSERT_OFFSET(FullscreenCompositionResource, previewSettings, 0x50);
RED4EXT_ASSERT_OFFSET(FullscreenCompositionResource, backgroundMenuTextureUHDRes, 0x60);
RED4EXT_ASSERT_OFFSET(FullscreenCompositionResource, backgroundMenuTextureFHDRes, 0x68);
#else
RED4EXT_ASSERT_SIZE(FullscreenCompositionResource, 0x70);
#endif
} // namespace ink
using inkFullscreenCompositionResource = ink::FullscreenCompositionResource;
} // namespace RED4ext

// clang-format on
