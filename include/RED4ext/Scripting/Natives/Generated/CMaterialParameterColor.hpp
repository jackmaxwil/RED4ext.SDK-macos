#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/CMaterialParameter.hpp>
#include <RED4ext/Scripting/Natives/Generated/Color.hpp>

namespace RED4ext
{
struct CMaterialParameterColor : CMaterialParameter
{
    static constexpr const char* NAME = "CMaterialParameterColor";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    Color color; // 3C
#else
    Color color; // 40
    uint8_t unk44[0x48 - 0x44]; // 44
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CMaterialParameterColor, 0x40);
RED4EXT_ASSERT_OFFSET(CMaterialParameterColor, color, 0x3C);
#else
RED4EXT_ASSERT_SIZE(CMaterialParameterColor, 0x48);
#endif
} // namespace RED4ext

// clang-format on
