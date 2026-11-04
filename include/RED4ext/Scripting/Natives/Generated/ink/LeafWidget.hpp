#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/Widget.hpp>

namespace RED4ext
{
namespace ink
{
struct __declspec(align(0x10)) LeafWidget : ink::Widget
{
    static constexpr const char* NAME = "inkLeafWidget";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
#else
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(LeafWidget, 0x200);
#else
RED4EXT_ASSERT_SIZE(LeafWidget, 0x210);
#endif
} // namespace ink
using inkLeafWidget = ink::LeafWidget;
} // namespace RED4ext

// clang-format on
