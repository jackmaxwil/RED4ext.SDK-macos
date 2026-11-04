#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector2.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/CompoundWidget.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/EOrientation.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/Margin.hpp>

namespace RED4ext
{
namespace ink
{
struct __declspec(align(0x10)) GridWidget : ink::CompoundWidget
{
    static constexpr const char* NAME = "inkGridWidget";
    static constexpr const char* ALIAS = "inkGrid";

#ifdef __APPLE__
    ink::EOrientation orientation; // 226
    uint8_t unk227[0x228 - 0x227]; // 227
    ink::Margin childPadding; // 228
    Vector2 childSizeStep; // 238
    uint8_t unk240[0x270 - 0x240]; // 240
#else
    ink::EOrientation orientation; // 240
    uint8_t unk241[0x244 - 0x241]; // 241
    ink::Margin childPadding; // 244
    Vector2 childSizeStep; // 254
    uint8_t unk25C[0x290 - 0x25C]; // 25C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(GridWidget, 0x270);
RED4EXT_ASSERT_OFFSET(GridWidget, orientation, 0x226);
RED4EXT_ASSERT_OFFSET(GridWidget, childPadding, 0x228);
RED4EXT_ASSERT_OFFSET(GridWidget, childSizeStep, 0x238);
#else
RED4EXT_ASSERT_SIZE(GridWidget, 0x290);
#endif
} // namespace ink
using inkGridWidget = ink::GridWidget;
using inkGrid = ink::GridWidget;
} // namespace RED4ext

// clang-format on
