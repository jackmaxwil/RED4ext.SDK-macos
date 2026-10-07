#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/InitializedWidgetUserData.hpp>

namespace RED4ext
{
namespace ink
{
struct EnableHUDScaleOverride : ink::InitializedWidgetUserData
{
    static constexpr const char* NAME = "inkEnableHUDScaleOverride";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk48[0x4C - 0x48]; // 48
    float scalingInterpolationValue; // 4C
#else
    uint8_t unk48[0x50 - 0x48]; // 48
    float scalingInterpolationValue; // 50
    uint8_t unk54[0x58 - 0x54]; // 54
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(EnableHUDScaleOverride, 0x50);
RED4EXT_ASSERT_OFFSET(EnableHUDScaleOverride, scalingInterpolationValue, 0x4C);
#else
RED4EXT_ASSERT_SIZE(EnableHUDScaleOverride, 0x58);
#endif
} // namespace ink
using inkEnableHUDScaleOverride = ink::EnableHUDScaleOverride;
} // namespace RED4ext

// clang-format on
