#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/WidgetMenuComponentInterface.hpp>

namespace RED4ext
{
struct __declspec(align(0x10)) WidgetMenuComponent : WidgetMenuComponentInterface
{
    static constexpr const char* NAME = "WidgetMenuComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk1F0[0x210 - 0x1F0]; // 1F0
#else
    uint8_t unk200[0x220 - 0x200]; // 200
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(WidgetMenuComponent, 0x210);
#else
RED4EXT_ASSERT_SIZE(WidgetMenuComponent, 0x220);
#endif
} // namespace RED4ext

// clang-format on
