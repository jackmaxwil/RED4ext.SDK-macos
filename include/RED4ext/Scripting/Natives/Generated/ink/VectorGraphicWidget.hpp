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
struct __declspec(align(0x10)) VectorGraphicWidget : ink::LeafWidget
{
    static constexpr const char* NAME = "inkVectorGraphicWidget";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk1FE[0x220 - 0x1FE]; // 1FE
#else
    uint8_t unk200[0x220 - 0x200]; // 200
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(VectorGraphicWidget, 0x220);
#else
RED4EXT_ASSERT_SIZE(VectorGraphicWidget, 0x220);
#endif
} // namespace ink
using inkVectorGraphicWidget = ink::VectorGraphicWidget;
} // namespace RED4ext

// clang-format on
