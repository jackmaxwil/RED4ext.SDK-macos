#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/TextAnimationController.hpp>

namespace RED4ext
{
namespace ink
{
struct TextOffsetAnimationController : ink::TextAnimationController
{
    static constexpr const char* NAME = "inkTextOffsetAnimationController";
    static constexpr const char* ALIAS = "inkTextOffsetController";

#ifdef __APPLE__
    uint8_t unkE9[0x174 - 0xE9]; // E9
    float timeToSkip; // 174
#else
    uint8_t unkF0[0x174 - 0xF0]; // F0
    float timeToSkip; // 174
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TextOffsetAnimationController, 0x178);
RED4EXT_ASSERT_OFFSET(TextOffsetAnimationController, timeToSkip, 0x174);
#else
RED4EXT_ASSERT_SIZE(TextOffsetAnimationController, 0x178);
#endif
} // namespace ink
using inkTextOffsetAnimationController = ink::TextOffsetAnimationController;
using inkTextOffsetController = ink::TextOffsetAnimationController;
} // namespace RED4ext

// clang-format on
