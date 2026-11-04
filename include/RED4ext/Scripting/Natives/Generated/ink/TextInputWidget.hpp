#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/TextWidget.hpp>

namespace RED4ext
{
namespace ink
{
struct __declspec(align(0x10)) TextInputWidget : ink::TextWidget
{
    static constexpr const char* NAME = "inkTextInputWidget";
    static constexpr const char* ALIAS = "inkTextInput";

#ifdef __APPLE__
    uint8_t unk450[0x490 - 0x450]; // 450
#else
    uint8_t unk460[0x4A0 - 0x460]; // 460
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TextInputWidget, 0x490);
#else
RED4EXT_ASSERT_SIZE(TextInputWidget, 0x4A0);
#endif
} // namespace ink
using inkTextInputWidget = ink::TextInputWidget;
using inkTextInput = ink::TextInputWidget;
} // namespace RED4ext

// clang-format on
