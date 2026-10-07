#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimFeature.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimFeature_AIAction : anim::AnimFeature
{
    static constexpr const char* NAME = "animAnimFeature_AIAction";
    static constexpr const char* ALIAS = "AnimFeature_AIAction";

#ifdef __APPLE__
    int32_t state; // 40
    int32_t animVariation; // 44
    float stateDuration; // 48
#else
    int32_t state; // 40
    int32_t animVariation; // 44
    float stateDuration; // 48
    uint8_t unk4C[0x50 - 0x4C]; // 4C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimFeature_AIAction, 0x50);
RED4EXT_ASSERT_OFFSET(AnimFeature_AIAction, state, 0x40);
RED4EXT_ASSERT_OFFSET(AnimFeature_AIAction, animVariation, 0x44);
RED4EXT_ASSERT_OFFSET(AnimFeature_AIAction, stateDuration, 0x48);
#else
RED4EXT_ASSERT_SIZE(AnimFeature_AIAction, 0x50);
#endif
} // namespace anim
using animAnimFeature_AIAction = anim::AnimFeature_AIAction;
using AnimFeature_AIAction = anim::AnimFeature_AIAction;
} // namespace RED4ext

// clang-format on
