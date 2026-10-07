#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/HudWidgetSpawnEntry.hpp>

namespace RED4ext
{
namespace ink { struct WidgetLibraryResource; }

namespace ink
{
struct HudEntriesResource : CResource
{
    static constexpr const char* NAME = "inkHudEntriesResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    Ref<ink::WidgetLibraryResource> rootWidget; // 40
    DynArray<ink::HudWidgetSpawnEntry> entries; // 58
    CName themeOverride; // 68
#else
    Ref<ink::WidgetLibraryResource> rootWidget; // 40
    DynArray<ink::HudWidgetSpawnEntry> entries; // 58
    CName themeOverride; // 68
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(HudEntriesResource, 0x70);
RED4EXT_ASSERT_OFFSET(HudEntriesResource, rootWidget, 0x40);
RED4EXT_ASSERT_OFFSET(HudEntriesResource, entries, 0x58);
RED4EXT_ASSERT_OFFSET(HudEntriesResource, themeOverride, 0x68);
#else
RED4EXT_ASSERT_SIZE(HudEntriesResource, 0x70);
#endif
} // namespace ink
using inkHudEntriesResource = ink::HudEntriesResource;
} // namespace RED4ext

// clang-format on
