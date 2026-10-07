#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/EChildOrder.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/ImageWidget.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/LineVertex.hpp>

namespace RED4ext
{
namespace ink
{
struct __declspec(align(0x10)) LinePatternWidget : ink::ImageWidget
{
    static constexpr const char* NAME = "inkLinePatternWidget";
    static constexpr const char* ALIAS = "inkLinePattern";

#ifdef __APPLE__
    DynArray<ink::LineVertex> vertexList; // 338
    uint8_t unk348[0x34C - 0x348]; // 348
    float spacing; // 34C
    float looseSpacing; // 350
    float startOffset; // 354
    float endOffset; // 358
    float fadeInLength; // 35C
    bool rotateWithSegment; // 360
    ink::EChildOrder patternDirection; // 361
    uint8_t unk362[0x370 - 0x362]; // 362
#else
    DynArray<ink::LineVertex> vertexList; // 340
    uint8_t unk350[0x354 - 0x350]; // 350
    float spacing; // 354
    float looseSpacing; // 358
    float startOffset; // 35C
    float endOffset; // 360
    float fadeInLength; // 364
    bool rotateWithSegment; // 368
    ink::EChildOrder patternDirection; // 369
    uint8_t unk36A[0x370 - 0x36A]; // 36A
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(LinePatternWidget, 0x370);
RED4EXT_ASSERT_OFFSET(LinePatternWidget, vertexList, 0x338);
RED4EXT_ASSERT_OFFSET(LinePatternWidget, spacing, 0x34C);
RED4EXT_ASSERT_OFFSET(LinePatternWidget, looseSpacing, 0x350);
RED4EXT_ASSERT_OFFSET(LinePatternWidget, startOffset, 0x354);
RED4EXT_ASSERT_OFFSET(LinePatternWidget, endOffset, 0x358);
RED4EXT_ASSERT_OFFSET(LinePatternWidget, fadeInLength, 0x35C);
RED4EXT_ASSERT_OFFSET(LinePatternWidget, rotateWithSegment, 0x360);
RED4EXT_ASSERT_OFFSET(LinePatternWidget, patternDirection, 0x361);
#else
RED4EXT_ASSERT_SIZE(LinePatternWidget, 0x370);
#endif
} // namespace ink
using inkLinePatternWidget = ink::LinePatternWidget;
using inkLinePattern = ink::LinePatternWidget;
} // namespace RED4ext

// clang-format on
