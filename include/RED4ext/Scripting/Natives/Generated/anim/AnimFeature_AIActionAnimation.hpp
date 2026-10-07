#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimFeature_AIAction.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimFeature_AIActionAnimation : anim::AnimFeature_AIAction
{
    static constexpr const char* NAME = "animAnimFeature_AIActionAnimation";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk4C[0x50 - 0x4C]; // 4C
    CName animFeatureName; // 50
#else
    CName animFeatureName; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimFeature_AIActionAnimation, 0x58);
RED4EXT_ASSERT_OFFSET(AnimFeature_AIActionAnimation, animFeatureName, 0x50);
#else
RED4EXT_ASSERT_SIZE(AnimFeature_AIActionAnimation, 0x58);
#endif
} // namespace anim
using animAnimFeature_AIActionAnimation = anim::AnimFeature_AIActionAnimation;
} // namespace RED4ext

// clang-format on
