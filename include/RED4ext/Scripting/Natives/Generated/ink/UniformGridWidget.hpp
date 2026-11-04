#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/CompoundWidget.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/EOrientation.hpp>

namespace RED4ext
{
namespace ink
{
struct __declspec(align(0x10)) UniformGridWidget : ink::CompoundWidget
{
    static constexpr const char* NAME = "inkUniformGridWidget";
    static constexpr const char* ALIAS = "inkUniformGrid";

#ifdef __APPLE__
    uint8_t unk226[0x228 - 0x226]; // 226
    uint32_t wrappingWidgetCount; // 228
    ink::EOrientation orientation; // 22C
    uint8_t unk22D[0x230 - 0x22D]; // 22D
#else
    uint32_t wrappingWidgetCount; // 240
    ink::EOrientation orientation; // 244
    uint8_t unk245[0x250 - 0x245]; // 245
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(UniformGridWidget, 0x230);
RED4EXT_ASSERT_OFFSET(UniformGridWidget, wrappingWidgetCount, 0x228);
RED4EXT_ASSERT_OFFSET(UniformGridWidget, orientation, 0x22C);
#else
RED4EXT_ASSERT_SIZE(UniformGridWidget, 0x250);
#endif
} // namespace ink
using inkUniformGridWidget = ink::UniformGridWidget;
using inkUniformGrid = ink::UniformGridWidget;
} // namespace RED4ext

// clang-format on
