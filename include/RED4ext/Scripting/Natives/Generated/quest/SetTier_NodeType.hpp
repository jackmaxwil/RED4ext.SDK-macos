#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/GameplayTier.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/MotionConstrainedTierDataParams.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ISceneManagerNodeType.hpp>

namespace RED4ext
{
namespace quest
{
struct SetTier_NodeType : quest::ISceneManagerNodeType
{
    static constexpr const char* NAME = "questSetTier_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    GameplayTier tier; // 34
    bool usePlayerWorkspot; // 38
    bool useEnterAnim; // 39
    bool useExitAnim; // 3A
    bool forceEmptyHands; // 3B
    uint8_t unk3C[0x40 - 0x3C]; // 3C
    game::MotionConstrainedTierDataParams motionConstrainedTierDataParams; // 40
#else
    GameplayTier tier; // 38
    bool usePlayerWorkspot; // 3C
    bool useEnterAnim; // 3D
    bool useExitAnim; // 3E
    bool forceEmptyHands; // 3F
    game::MotionConstrainedTierDataParams motionConstrainedTierDataParams; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SetTier_NodeType, 0x60);
RED4EXT_ASSERT_OFFSET(SetTier_NodeType, tier, 0x34);
RED4EXT_ASSERT_OFFSET(SetTier_NodeType, usePlayerWorkspot, 0x38);
RED4EXT_ASSERT_OFFSET(SetTier_NodeType, useEnterAnim, 0x39);
RED4EXT_ASSERT_OFFSET(SetTier_NodeType, useExitAnim, 0x3A);
RED4EXT_ASSERT_OFFSET(SetTier_NodeType, forceEmptyHands, 0x3B);
RED4EXT_ASSERT_OFFSET(SetTier_NodeType, motionConstrainedTierDataParams, 0x40);
#else
RED4EXT_ASSERT_SIZE(SetTier_NodeType, 0x60);
#endif
} // namespace quest
using questSetTier_NodeType = quest::SetTier_NodeType;
} // namespace RED4ext

// clang-format on
