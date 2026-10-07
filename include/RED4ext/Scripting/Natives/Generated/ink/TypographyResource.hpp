#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/LanguageDefinition.hpp>

namespace RED4ext
{
namespace ink
{
struct TypographyResource : CResource
{
    static constexpr const char* NAME = "inkTypographyResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<ink::LanguageDefinition> languages; // 40
#else
    DynArray<ink::LanguageDefinition> languages; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TypographyResource, 0x50);
RED4EXT_ASSERT_OFFSET(TypographyResource, languages, 0x40);
#else
RED4EXT_ASSERT_SIZE(TypographyResource, 0x50);
#endif
} // namespace ink
using inkTypographyResource = ink::TypographyResource;
} // namespace RED4ext

// clang-format on
