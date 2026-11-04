#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/EHorizontalAlign.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/EVerticalAlign.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/LeafWidget.hpp>
#include <RED4ext/Scripting/Natives/Generated/text/HorizontalAlignment.hpp>
#include <RED4ext/Scripting/Natives/Generated/text/JustificationType.hpp>
#include <RED4ext/Scripting/Natives/Generated/text/LetterCase.hpp>
#include <RED4ext/Scripting/Natives/Generated/text/OverflowPolicy.hpp>
#include <RED4ext/Scripting/Natives/Generated/text/VerticalAlignment.hpp>
#include <RED4ext/Scripting/Natives/Generated/text/WrappingInfo.hpp>

namespace RED4ext
{
namespace ink { struct FontFamilyResource; }
namespace rend { struct Font; }

namespace ink
{
struct __declspec(align(0x10)) TextWidget : ink::LeafWidget
{
    static constexpr const char* NAME = "inkTextWidget";
    static constexpr const char* ALIAS = "inkText";

#ifdef __APPLE__
    uint8_t unk1FE[0x248 - 0x1FE]; // 1FE
    CString text; // 248
    CName textIdKey; // 268
    RaRef<ink::FontFamilyResource> fontFamily; // 270
    CName fontStyle; // 278
    uint32_t fontSize; // 280
    uint8_t unk284[0x288 - 0x284]; // 284
    ink::EHorizontalAlign contentHAlign; // 288
    ink::EVerticalAlign contentVAlign; // 289
    uint8_t unk28A[0x2A0 - 0x28A]; // 28A
    Handle<rend::Font> font; // 2A0
    uint8_t unk2B0[0x2E8 - 0x2B0]; // 2B0
    text::LetterCase letterCase; // 2E8
    uint8_t unk2E9[0x2F0 - 0x2E9]; // 2E9
    uint32_t tracking; // 2F0
    bool lockFontInGame; // 2F4
    uint8_t unk2F5[0x2F8 - 0x2F5]; // 2F5
    LocalizationString localizationString; // 2F8
    uint8_t unk320[0x350 - 0x320]; // 320
    float lineHeightPercentage; // 350
    uint8_t unk354[0x358 - 0x354]; // 354
    float scrollTextSpeed; // 358
    uint16_t scrollDelay; // 35C
    uint8_t unk35E[0x370 - 0x35E]; // 35E
    text::WrappingInfo wrappingInfo; // 370
    text::JustificationType justification; // 37C
    text::VerticalAlignment textVerticalAlignment; // 37D
    text::HorizontalAlignment textHorizontalAlignment; // 37E
    uint8_t unk37F[0x380 - 0x37F]; // 37F
    text::OverflowPolicy textOverflowPolicy; // 380
    uint8_t unk381[0x450 - 0x381]; // 381
#else
    uint8_t unk210[0x258 - 0x210]; // 210
    CString text; // 258
    CName textIdKey; // 278
    RaRef<ink::FontFamilyResource> fontFamily; // 280
    CName fontStyle; // 288
    uint32_t fontSize; // 290
    uint8_t unk294[0x298 - 0x294]; // 294
    ink::EHorizontalAlign contentHAlign; // 298
    ink::EVerticalAlign contentVAlign; // 299
    uint8_t unk29A[0x2B0 - 0x29A]; // 29A
    Handle<rend::Font> font; // 2B0
    uint8_t unk2C0[0x2F8 - 0x2C0]; // 2C0
    text::LetterCase letterCase; // 2F8
    uint8_t unk2F9[0x300 - 0x2F9]; // 2F9
    uint32_t tracking; // 300
    bool lockFontInGame; // 304
    uint8_t unk305[0x308 - 0x305]; // 305
    LocalizationString localizationString; // 308
    uint8_t unk330[0x360 - 0x330]; // 330
    float lineHeightPercentage; // 360
    uint8_t unk364[0x368 - 0x364]; // 364
    float scrollTextSpeed; // 368
    uint16_t scrollDelay; // 36C
    uint8_t unk36E[0x380 - 0x36E]; // 36E
    text::WrappingInfo wrappingInfo; // 380
    text::JustificationType justification; // 38C
    text::VerticalAlignment textVerticalAlignment; // 38D
    text::HorizontalAlignment textHorizontalAlignment; // 38E
    uint8_t unk38F[0x390 - 0x38F]; // 38F
    text::OverflowPolicy textOverflowPolicy; // 390
    uint8_t unk391[0x460 - 0x391]; // 391
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TextWidget, 0x450);
RED4EXT_ASSERT_OFFSET(TextWidget, text, 0x248);
RED4EXT_ASSERT_OFFSET(TextWidget, textIdKey, 0x268);
RED4EXT_ASSERT_OFFSET(TextWidget, fontFamily, 0x270);
RED4EXT_ASSERT_OFFSET(TextWidget, fontStyle, 0x278);
RED4EXT_ASSERT_OFFSET(TextWidget, fontSize, 0x280);
RED4EXT_ASSERT_OFFSET(TextWidget, contentHAlign, 0x288);
RED4EXT_ASSERT_OFFSET(TextWidget, contentVAlign, 0x289);
RED4EXT_ASSERT_OFFSET(TextWidget, font, 0x2A0);
RED4EXT_ASSERT_OFFSET(TextWidget, letterCase, 0x2E8);
RED4EXT_ASSERT_OFFSET(TextWidget, tracking, 0x2F0);
RED4EXT_ASSERT_OFFSET(TextWidget, lockFontInGame, 0x2F4);
RED4EXT_ASSERT_OFFSET(TextWidget, localizationString, 0x2F8);
RED4EXT_ASSERT_OFFSET(TextWidget, lineHeightPercentage, 0x350);
RED4EXT_ASSERT_OFFSET(TextWidget, scrollTextSpeed, 0x358);
RED4EXT_ASSERT_OFFSET(TextWidget, scrollDelay, 0x35C);
RED4EXT_ASSERT_OFFSET(TextWidget, wrappingInfo, 0x370);
RED4EXT_ASSERT_OFFSET(TextWidget, justification, 0x37C);
RED4EXT_ASSERT_OFFSET(TextWidget, textVerticalAlignment, 0x37D);
RED4EXT_ASSERT_OFFSET(TextWidget, textHorizontalAlignment, 0x37E);
RED4EXT_ASSERT_OFFSET(TextWidget, textOverflowPolicy, 0x380);
#else
RED4EXT_ASSERT_SIZE(TextWidget, 0x460);
#endif
} // namespace ink
using inkTextWidget = ink::TextWidget;
using inkText = ink::TextWidget;
} // namespace RED4ext

// clang-format on
