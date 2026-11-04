#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/CompoundWidget.hpp>

namespace RED4ext
{
namespace ink
{
struct __declspec(align(0x10)) CanvasWidget : ink::CompoundWidget
{
    static constexpr const char* NAME = "inkCanvasWidget";
    static constexpr const char* ALIAS = "inkCanvas";

#ifdef __APPLE__
#else
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CanvasWidget, 0x230);
#else
RED4EXT_ASSERT_SIZE(CanvasWidget, 0x240);
#endif
} // namespace ink
using inkCanvasWidget = ink::CanvasWidget;
using inkCanvas = ink::CanvasWidget;
} // namespace RED4ext

// clang-format on
