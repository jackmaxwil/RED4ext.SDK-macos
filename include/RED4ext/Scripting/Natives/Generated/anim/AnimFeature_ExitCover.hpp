#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimFeature_AIAction.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimFeature_ExitCover : anim::AnimFeature_AIAction
{
    static constexpr const char* NAME = "animAnimFeature_ExitCover";
    static constexpr const char* ALIAS = "AnimFeature_ExitCover";

#ifdef __APPLE__
    int32_t coverStance; // 4C
    int32_t coverExitDirection; // 50
    uint8_t unk54[0x58 - 0x54]; // 54
#else
    int32_t coverStance; // 50
    int32_t coverExitDirection; // 54
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimFeature_ExitCover, 0x58);
RED4EXT_ASSERT_OFFSET(AnimFeature_ExitCover, coverStance, 0x4C);
RED4EXT_ASSERT_OFFSET(AnimFeature_ExitCover, coverExitDirection, 0x50);
#else
RED4EXT_ASSERT_SIZE(AnimFeature_ExitCover, 0x58);
#endif
} // namespace anim
using animAnimFeature_ExitCover = anim::AnimFeature_ExitCover;
using AnimFeature_ExitCover = anim::AnimFeature_ExitCover;
} // namespace RED4ext

// clang-format on
