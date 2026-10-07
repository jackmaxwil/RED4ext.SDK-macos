#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/EChildOrder.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/Margin.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/Widget.hpp>

namespace RED4ext
{
namespace ink { struct MultiChildren; }

namespace ink
{
struct __declspec(align(0x10)) CompoundWidget : ink::Widget
{
    static constexpr const char* NAME = "inkCompoundWidget";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk1FE[0x200 - 0x1FE]; // 1FE
    Handle<ink::MultiChildren> children; // 200
    ink::EChildOrder childOrder; // 210
    uint8_t unk211[0x214 - 0x211]; // 211
    ink::Margin childMargin; // 214
    uint8_t unk224[0x226 - 0x224]; // 224
#else
    Handle<ink::MultiChildren> children; // 200
    ink::EChildOrder childOrder; // 210
    uint8_t unk211[0x214 - 0x211]; // 211
    ink::Margin childMargin; // 214
    uint8_t unk224[0x230 - 0x224]; // 224
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CompoundWidget, 0x230);
RED4EXT_ASSERT_OFFSET(CompoundWidget, children, 0x200);
RED4EXT_ASSERT_OFFSET(CompoundWidget, childOrder, 0x210);
RED4EXT_ASSERT_OFFSET(CompoundWidget, childMargin, 0x214);
#else
RED4EXT_ASSERT_SIZE(CompoundWidget, 0x230);
#endif
} // namespace ink
using inkCompoundWidget = ink::CompoundWidget;
} // namespace RED4ext

// clang-format on
