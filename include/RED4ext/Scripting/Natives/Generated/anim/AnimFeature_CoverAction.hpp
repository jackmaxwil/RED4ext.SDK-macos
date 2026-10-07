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
struct AnimFeature_CoverAction : anim::AnimFeature_AIAction
{
    static constexpr const char* NAME = "animAnimFeature_CoverAction";
    static constexpr const char* ALIAS = "AnimFeature_CoverAction";

#ifdef __APPLE__
    int32_t coverStance; // 4C
    int32_t coverActionType; // 50
    int32_t coverShootType; // 54
    int32_t movementType; // 58
    uint8_t unk5C[0x60 - 0x5C]; // 5C
#else
    int32_t coverStance; // 50
    int32_t coverActionType; // 54
    int32_t coverShootType; // 58
    int32_t movementType; // 5C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimFeature_CoverAction, 0x60);
RED4EXT_ASSERT_OFFSET(AnimFeature_CoverAction, coverStance, 0x4C);
RED4EXT_ASSERT_OFFSET(AnimFeature_CoverAction, coverActionType, 0x50);
RED4EXT_ASSERT_OFFSET(AnimFeature_CoverAction, coverShootType, 0x54);
RED4EXT_ASSERT_OFFSET(AnimFeature_CoverAction, movementType, 0x58);
#else
RED4EXT_ASSERT_SIZE(AnimFeature_CoverAction, 0x60);
#endif
} // namespace anim
using animAnimFeature_CoverAction = anim::AnimFeature_CoverAction;
using AnimFeature_CoverAction = anim::AnimFeature_CoverAction;
} // namespace RED4ext

// clang-format on
