#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/HDRColor.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/BaseShapeWidget.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/EEndCapStyle.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/EHorizontalAlign.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/EJointStyle.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/EShapeVariant.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/EVerticalAlign.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/Margin.hpp>

namespace RED4ext
{
namespace ink { struct ShapeCollectionResource; }

namespace ink
{
struct __declspec(align(0x10)) ShapeWidget : ink::BaseShapeWidget
{
    static constexpr const char* NAME = "inkShapeWidget";
    static constexpr const char* ALIAS = "inkShape";

#ifdef __APPLE__
    Ref<ink::ShapeCollectionResource> shapeResource; // 220
    CName shapeName; // 238
    bool keepInBounds; // 240
    uint8_t unk241[0x244 - 0x241]; // 241
    float lineThickness; // 244
    uint8_t unk248[0x250 - 0x248]; // 248
    HDRColor borderColor; // 250
    float borderOpacity; // 260
    float fillOpacity; // 264
    ink::EShapeVariant shapeVariant; // 268
    ink::EEndCapStyle endCapStyle; // 26C
    ink::EJointStyle jointStyle; // 270
    ink::EHorizontalAlign contentHAlign; // 274
    ink::EVerticalAlign contentVAlign; // 275
    bool useNineSlice; // 276
    uint8_t unk277[0x278 - 0x277]; // 277
    ink::Margin nineSliceScale; // 278
    uint8_t unk288[0x360 - 0x288]; // 288
#else
    Ref<ink::ShapeCollectionResource> shapeResource; // 240
    CName shapeName; // 258
    bool keepInBounds; // 260
    uint8_t unk261[0x264 - 0x261]; // 261
    float lineThickness; // 264
    uint8_t unk268[0x270 - 0x268]; // 268
    HDRColor borderColor; // 270
    float borderOpacity; // 280
    float fillOpacity; // 284
    ink::EShapeVariant shapeVariant; // 288
    ink::EEndCapStyle endCapStyle; // 28C
    ink::EJointStyle jointStyle; // 290
    ink::EHorizontalAlign contentHAlign; // 294
    ink::EVerticalAlign contentVAlign; // 295
    bool useNineSlice; // 296
    uint8_t unk297[0x298 - 0x297]; // 297
    ink::Margin nineSliceScale; // 298
    uint8_t unk2A8[0x380 - 0x2A8]; // 2A8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ShapeWidget, 0x360);
RED4EXT_ASSERT_OFFSET(ShapeWidget, shapeResource, 0x220);
RED4EXT_ASSERT_OFFSET(ShapeWidget, shapeName, 0x238);
RED4EXT_ASSERT_OFFSET(ShapeWidget, keepInBounds, 0x240);
RED4EXT_ASSERT_OFFSET(ShapeWidget, lineThickness, 0x244);
RED4EXT_ASSERT_OFFSET(ShapeWidget, borderColor, 0x250);
RED4EXT_ASSERT_OFFSET(ShapeWidget, borderOpacity, 0x260);
RED4EXT_ASSERT_OFFSET(ShapeWidget, fillOpacity, 0x264);
RED4EXT_ASSERT_OFFSET(ShapeWidget, shapeVariant, 0x268);
RED4EXT_ASSERT_OFFSET(ShapeWidget, endCapStyle, 0x26C);
RED4EXT_ASSERT_OFFSET(ShapeWidget, jointStyle, 0x270);
RED4EXT_ASSERT_OFFSET(ShapeWidget, contentHAlign, 0x274);
RED4EXT_ASSERT_OFFSET(ShapeWidget, contentVAlign, 0x275);
RED4EXT_ASSERT_OFFSET(ShapeWidget, useNineSlice, 0x276);
RED4EXT_ASSERT_OFFSET(ShapeWidget, nineSliceScale, 0x278);
#else
RED4EXT_ASSERT_SIZE(ShapeWidget, 0x380);
#endif
} // namespace ink
using inkShapeWidget = ink::ShapeWidget;
using inkShape = ink::ShapeWidget;
} // namespace RED4ext

// clang-format on
