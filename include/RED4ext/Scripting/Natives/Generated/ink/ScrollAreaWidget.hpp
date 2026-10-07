#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/CompoundWidget.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/FitToContentDirection.hpp>

namespace RED4ext
{
namespace ink
{
struct __declspec(align(0x10)) ScrollAreaWidget : ink::CompoundWidget
{
    static constexpr const char* NAME = "inkScrollAreaWidget";
    static constexpr const char* ALIAS = "inkScrollArea";

#ifdef __APPLE__
    uint8_t unk226[0x238 - 0x226]; // 226
    float horizontalScrolling; // 238
    float verticalScrolling; // 23C
    bool constrainContentPosition; // 240
    bool useInternalMask; // 241
    uint8_t unk242[0x24C - 0x242]; // 242
    ink::FitToContentDirection fitToContentDirection; // 24C
#else
    uint8_t unk230[0x240 - 0x230]; // 230
    float horizontalScrolling; // 240
    float verticalScrolling; // 244
    bool constrainContentPosition; // 248
    bool useInternalMask; // 249
    uint8_t unk24A[0x254 - 0x24A]; // 24A
    ink::FitToContentDirection fitToContentDirection; // 254
    uint8_t unk258[0x260 - 0x258]; // 258
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ScrollAreaWidget, 0x250);
RED4EXT_ASSERT_OFFSET(ScrollAreaWidget, horizontalScrolling, 0x238);
RED4EXT_ASSERT_OFFSET(ScrollAreaWidget, verticalScrolling, 0x23C);
RED4EXT_ASSERT_OFFSET(ScrollAreaWidget, constrainContentPosition, 0x240);
RED4EXT_ASSERT_OFFSET(ScrollAreaWidget, useInternalMask, 0x241);
RED4EXT_ASSERT_OFFSET(ScrollAreaWidget, fitToContentDirection, 0x24C);
#else
RED4EXT_ASSERT_SIZE(ScrollAreaWidget, 0x260);
#endif
} // namespace ink
using inkScrollAreaWidget = ink::ScrollAreaWidget;
using inkScrollArea = ink::ScrollAreaWidget;
} // namespace RED4ext

// clang-format on
