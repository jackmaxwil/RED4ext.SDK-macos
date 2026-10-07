#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/TextAnimationController.hpp>

namespace RED4ext
{
namespace ink
{
struct TextValueProgressAnimationController : ink::TextAnimationController
{
    static constexpr const char* NAME = "inkTextValueProgressAnimationController";
    static constexpr const char* ALIAS = "inkTextValueProgressController";

#ifdef __APPLE__
    uint8_t unkE9[0xEC - 0xE9]; // E9
    float baseValue; // EC
    float targetValue; // F0
    int32_t numbersAfterDot; // F4
    float stepValue; // F8
    uint8_t unkFC[0x120 - 0xFC]; // FC
    CString suffix; // 120
#else
    float baseValue; // F0
    float targetValue; // F4
    int32_t numbersAfterDot; // F8
    float stepValue; // FC
    uint8_t unk100[0x128 - 0x100]; // 100
    CString suffix; // 128
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TextValueProgressAnimationController, 0x140);
RED4EXT_ASSERT_OFFSET(TextValueProgressAnimationController, baseValue, 0xEC);
RED4EXT_ASSERT_OFFSET(TextValueProgressAnimationController, targetValue, 0xF0);
RED4EXT_ASSERT_OFFSET(TextValueProgressAnimationController, numbersAfterDot, 0xF4);
RED4EXT_ASSERT_OFFSET(TextValueProgressAnimationController, stepValue, 0xF8);
RED4EXT_ASSERT_OFFSET(TextValueProgressAnimationController, suffix, 0x120);
#else
RED4EXT_ASSERT_SIZE(TextValueProgressAnimationController, 0x148);
#endif
} // namespace ink
using inkTextValueProgressAnimationController = ink::TextValueProgressAnimationController;
using inkTextValueProgressController = ink::TextValueProgressAnimationController;
} // namespace RED4ext

// clang-format on
