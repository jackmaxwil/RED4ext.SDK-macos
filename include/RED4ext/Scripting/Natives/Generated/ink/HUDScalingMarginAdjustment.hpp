#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/InitializedWidgetUserData.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/Margin.hpp>

namespace RED4ext
{
namespace ink
{
struct HUDScalingMarginAdjustment : ink::InitializedWidgetUserData
{
    static constexpr const char* NAME = "inkHUDScalingMarginAdjustment";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk48[0x54 - 0x48]; // 48
    ink::Margin adjustmentMargin; // 54
    uint8_t unk64[0x68 - 0x64]; // 64
#else
    uint8_t unk48[0x58 - 0x48]; // 48
    ink::Margin adjustmentMargin; // 58
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(HUDScalingMarginAdjustment, 0x68);
RED4EXT_ASSERT_OFFSET(HUDScalingMarginAdjustment, adjustmentMargin, 0x54);
#else
RED4EXT_ASSERT_SIZE(HUDScalingMarginAdjustment, 0x68);
#endif
} // namespace ink
using inkHUDScalingMarginAdjustment = ink::HUDScalingMarginAdjustment;
} // namespace RED4ext

// clang-format on
