#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector3.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ISceneManagerNodeType.hpp>

namespace RED4ext
{
namespace quest
{
struct SetTier3Params_NodeType : quest::ISceneManagerNodeType
{
    static constexpr const char* NAME = "questSetTier3Params_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    float yawLeftLimit; // 38
    float yawRightLimit; // 3C
    float pitchUpLimit; // 40
    float pitchDownLimit; // 44
    float yawSpeedMultiplier; // 48
    float pitchSpeedMultiplier; // 4C
    game::EntityReference objectRef; // 50
    CName slotName; // 88
    Vector3 offsetPos; // 90
    float rotationTime; // 9C
    bool rotateHeadOnly; // A0
    bool usePlayerWorkspot; // A1
    bool useEnterAnim; // A2
    bool useExitAnim; // A3
    uint8_t unkA4[0xA8 - 0xA4]; // A4
#else
    uint8_t unk38[0x3C - 0x38]; // 38
    float yawLeftLimit; // 3C
    float yawRightLimit; // 40
    float pitchUpLimit; // 44
    float pitchDownLimit; // 48
    float yawSpeedMultiplier; // 4C
    float pitchSpeedMultiplier; // 50
    uint8_t unk54[0x58 - 0x54]; // 54
    game::EntityReference objectRef; // 58
    CName slotName; // 90
    Vector3 offsetPos; // 98
    float rotationTime; // A4
    bool rotateHeadOnly; // A8
    bool usePlayerWorkspot; // A9
    bool useEnterAnim; // AA
    bool useExitAnim; // AB
    uint8_t unkAC[0xB0 - 0xAC]; // AC
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SetTier3Params_NodeType, 0xA8);
RED4EXT_ASSERT_OFFSET(SetTier3Params_NodeType, yawLeftLimit, 0x38);
RED4EXT_ASSERT_OFFSET(SetTier3Params_NodeType, yawRightLimit, 0x3C);
RED4EXT_ASSERT_OFFSET(SetTier3Params_NodeType, pitchUpLimit, 0x40);
RED4EXT_ASSERT_OFFSET(SetTier3Params_NodeType, pitchDownLimit, 0x44);
RED4EXT_ASSERT_OFFSET(SetTier3Params_NodeType, yawSpeedMultiplier, 0x48);
RED4EXT_ASSERT_OFFSET(SetTier3Params_NodeType, pitchSpeedMultiplier, 0x4C);
RED4EXT_ASSERT_OFFSET(SetTier3Params_NodeType, objectRef, 0x50);
RED4EXT_ASSERT_OFFSET(SetTier3Params_NodeType, slotName, 0x88);
RED4EXT_ASSERT_OFFSET(SetTier3Params_NodeType, offsetPos, 0x90);
RED4EXT_ASSERT_OFFSET(SetTier3Params_NodeType, rotationTime, 0x9C);
RED4EXT_ASSERT_OFFSET(SetTier3Params_NodeType, rotateHeadOnly, 0xA0);
RED4EXT_ASSERT_OFFSET(SetTier3Params_NodeType, usePlayerWorkspot, 0xA1);
RED4EXT_ASSERT_OFFSET(SetTier3Params_NodeType, useEnterAnim, 0xA2);
RED4EXT_ASSERT_OFFSET(SetTier3Params_NodeType, useExitAnim, 0xA3);
#else
RED4EXT_ASSERT_SIZE(SetTier3Params_NodeType, 0xB0);
#endif
} // namespace quest
using questSetTier3Params_NodeType = quest::SetTier3Params_NodeType;
} // namespace RED4ext

// clang-format on
