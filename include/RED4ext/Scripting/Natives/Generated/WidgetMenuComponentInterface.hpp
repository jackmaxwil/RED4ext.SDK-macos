#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/WidgetBaseComponent.hpp>

namespace RED4ext
{
struct CMaterialTemplate;
namespace ink { struct WidgetLibraryResource; }
namespace world::ui { struct MeshTargetBinding; }

struct __declspec(align(0x10)) WidgetMenuComponentInterface : WidgetBaseComponent
{
    static constexpr const char* NAME = "WidgetMenuComponentInterface";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    Handle<world::ui::MeshTargetBinding> meshTargetBinding; // 198
    Ref<CMaterialTemplate> externalMaterial; // 1A8
    Ref<ink::WidgetLibraryResource> widgetResource; // 1C0
    Ref<ink::WidgetLibraryResource> cursorResource; // 1D8
#else
    Handle<world::ui::MeshTargetBinding> meshTargetBinding; // 1A0
    Ref<CMaterialTemplate> externalMaterial; // 1B0
    Ref<ink::WidgetLibraryResource> widgetResource; // 1C8
    Ref<ink::WidgetLibraryResource> cursorResource; // 1E0
    uint8_t unk1F8[0x200 - 0x1F8]; // 1F8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(WidgetMenuComponentInterface, 0x1F0);
RED4EXT_ASSERT_OFFSET(WidgetMenuComponentInterface, meshTargetBinding, 0x198);
RED4EXT_ASSERT_OFFSET(WidgetMenuComponentInterface, externalMaterial, 0x1A8);
RED4EXT_ASSERT_OFFSET(WidgetMenuComponentInterface, widgetResource, 0x1C0);
RED4EXT_ASSERT_OFFSET(WidgetMenuComponentInterface, cursorResource, 0x1D8);
#else
RED4EXT_ASSERT_SIZE(WidgetMenuComponentInterface, 0x200);
#endif
} // namespace RED4ext

// clang-format on
