#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/BaseShapeWidget.hpp>

namespace RED4ext
{
namespace ink
{
struct __declspec(align(0x10)) CircleWidget : ink::BaseShapeWidget
{
    static constexpr const char* NAME = "inkCircleWidget";
    static constexpr const char* ALIAS = "inkCircle";

#ifdef __APPLE__
    uint8_t unk220[0x224 - 0x220]; // 220
    uint32_t segmentsNumber; // 224
    uint8_t unk228[0x230 - 0x228]; // 228
#else
    uint8_t unk240[0x244 - 0x240]; // 240
    uint32_t segmentsNumber; // 244
    uint8_t unk248[0x250 - 0x248]; // 248
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CircleWidget, 0x230);
RED4EXT_ASSERT_OFFSET(CircleWidget, segmentsNumber, 0x224);
#else
RED4EXT_ASSERT_SIZE(CircleWidget, 0x250);
#endif
} // namespace ink
using inkCircleWidget = ink::CircleWidget;
using inkCircle = ink::CircleWidget;
} // namespace RED4ext

// clang-format on
