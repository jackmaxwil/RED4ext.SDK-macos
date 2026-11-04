#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/CanvasWidget.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/WidgetReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/minimap/ui/Settings.hpp>

namespace RED4ext
{
namespace minimap::ui
{
struct GeometryWidget : ink::CanvasWidget
{
    static constexpr const char* NAME = "minimapuiGeometryWidget";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk226[0x268 - 0x226]; // 226
    DynArray<ink::WidgetReference> widgetTemplates; // 268
    uint8_t unk278[0x284 - 0x278]; // 278
    minimap::ui::Settings settings; // 284
    uint8_t unk28C[0x380 - 0x28C]; // 28C
#else
    uint8_t unk240[0x280 - 0x240]; // 240
    DynArray<ink::WidgetReference> widgetTemplates; // 280
    uint8_t unk290[0x29C - 0x290]; // 290
    minimap::ui::Settings settings; // 29C
    uint8_t unk2A4[0x380 - 0x2A4]; // 2A4
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(GeometryWidget, 0x380);
RED4EXT_ASSERT_OFFSET(GeometryWidget, widgetTemplates, 0x268);
RED4EXT_ASSERT_OFFSET(GeometryWidget, settings, 0x284);
#else
RED4EXT_ASSERT_SIZE(GeometryWidget, 0x380);
#endif
} // namespace minimap::ui
using minimapuiGeometryWidget = minimap::ui::GeometryWidget;
} // namespace RED4ext

// clang-format on
