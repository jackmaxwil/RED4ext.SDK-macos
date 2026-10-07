#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/Style.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/StyleOverride.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/StyleTheme.hpp>

namespace RED4ext
{

namespace ink
{
struct StyleResource : CResource
{
    static constexpr const char* NAME = "inkStyleResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<ink::Style> styles; // 40
    DynArray<ink::StyleTheme> themes; // 50
    DynArray<ink::StyleOverride> overrides; // 60
    DynArray<Ref<ink::StyleResource>> styleImports; // 70
    bool hideInInheritingStyles; // 80
    uint8_t unk81[0xC0 - 0x81]; // 81
#else
    DynArray<ink::Style> styles; // 40
    DynArray<ink::StyleTheme> themes; // 50
    DynArray<ink::StyleOverride> overrides; // 60
    DynArray<Ref<ink::StyleResource>> styleImports; // 70
    bool hideInInheritingStyles; // 80
    uint8_t unk81[0xC0 - 0x81]; // 81
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(StyleResource, 0xC0);
RED4EXT_ASSERT_OFFSET(StyleResource, styles, 0x40);
RED4EXT_ASSERT_OFFSET(StyleResource, themes, 0x50);
RED4EXT_ASSERT_OFFSET(StyleResource, overrides, 0x60);
RED4EXT_ASSERT_OFFSET(StyleResource, styleImports, 0x70);
RED4EXT_ASSERT_OFFSET(StyleResource, hideInInheritingStyles, 0x80);
#else
RED4EXT_ASSERT_SIZE(StyleResource, 0xC0);
#endif
} // namespace ink
using inkStyleResource = ink::StyleResource;
} // namespace RED4ext

// clang-format on
