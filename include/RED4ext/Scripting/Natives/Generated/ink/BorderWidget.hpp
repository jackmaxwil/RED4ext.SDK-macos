#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/LeafWidget.hpp>

namespace RED4ext
{
namespace ink
{
struct __declspec(align(0x10)) BorderWidget : ink::LeafWidget
{
    static constexpr const char* NAME = "inkBorderWidget";
    static constexpr const char* ALIAS = "inkBorder";

#ifdef __APPLE__
    uint8_t unk1FE[0x200 - 0x1FE]; // 1FE
    float thickness; // 200
    uint8_t unk204[0x210 - 0x204]; // 204
#else
    float thickness; // 200
    uint8_t unk204[0x210 - 0x204]; // 204
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(BorderWidget, 0x210);
RED4EXT_ASSERT_OFFSET(BorderWidget, thickness, 0x200);
#else
RED4EXT_ASSERT_SIZE(BorderWidget, 0x210);
#endif
} // namespace ink
using inkBorderWidget = ink::BorderWidget;
using inkBorder = ink::BorderWidget;
} // namespace RED4ext

// clang-format on
