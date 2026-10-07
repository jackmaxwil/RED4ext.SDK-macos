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
struct PlayerLookAt_NodeType : quest::ISceneManagerNodeType
{
    static constexpr const char* NAME = "questPlayerLookAt_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool useOffsetToPlayer; // 34
    uint8_t unk35[0x38 - 0x35]; // 35
    game::EntityReference objectRef; // 38
    CName slotName; // 70
    Vector3 offsetPos; // 78
    float duration; // 84
    bool adjustPitch; // 88
    bool adjustYaw; // 89
    bool endOnTargetReached; // 8A
    bool endOnCameraInputApplied; // 8B
    bool endOnTimeExceeded; // 8C
    uint8_t unk8D[0x90 - 0x8D]; // 8D
    float cameraInputMagToBreak; // 90
    float precision; // 94
    float maxDuration; // 98
    bool easeIn; // 9C
    bool easeOut; // 9D
    uint8_t unk9E[0xA0 - 0x9E]; // 9E
#else
    bool useOffsetToPlayer; // 38
    uint8_t unk39[0x40 - 0x39]; // 39
    game::EntityReference objectRef; // 40
    CName slotName; // 78
    Vector3 offsetPos; // 80
    float duration; // 8C
    bool adjustPitch; // 90
    bool adjustYaw; // 91
    bool endOnTargetReached; // 92
    bool endOnCameraInputApplied; // 93
    bool endOnTimeExceeded; // 94
    uint8_t unk95[0x98 - 0x95]; // 95
    float cameraInputMagToBreak; // 98
    float precision; // 9C
    float maxDuration; // A0
    bool easeIn; // A4
    bool easeOut; // A5
    uint8_t unkA6[0xA8 - 0xA6]; // A6
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PlayerLookAt_NodeType, 0xA0);
RED4EXT_ASSERT_OFFSET(PlayerLookAt_NodeType, useOffsetToPlayer, 0x34);
RED4EXT_ASSERT_OFFSET(PlayerLookAt_NodeType, objectRef, 0x38);
RED4EXT_ASSERT_OFFSET(PlayerLookAt_NodeType, slotName, 0x70);
RED4EXT_ASSERT_OFFSET(PlayerLookAt_NodeType, offsetPos, 0x78);
RED4EXT_ASSERT_OFFSET(PlayerLookAt_NodeType, duration, 0x84);
RED4EXT_ASSERT_OFFSET(PlayerLookAt_NodeType, adjustPitch, 0x88);
RED4EXT_ASSERT_OFFSET(PlayerLookAt_NodeType, adjustYaw, 0x89);
RED4EXT_ASSERT_OFFSET(PlayerLookAt_NodeType, endOnTargetReached, 0x8A);
RED4EXT_ASSERT_OFFSET(PlayerLookAt_NodeType, endOnCameraInputApplied, 0x8B);
RED4EXT_ASSERT_OFFSET(PlayerLookAt_NodeType, endOnTimeExceeded, 0x8C);
RED4EXT_ASSERT_OFFSET(PlayerLookAt_NodeType, cameraInputMagToBreak, 0x90);
RED4EXT_ASSERT_OFFSET(PlayerLookAt_NodeType, precision, 0x94);
RED4EXT_ASSERT_OFFSET(PlayerLookAt_NodeType, maxDuration, 0x98);
RED4EXT_ASSERT_OFFSET(PlayerLookAt_NodeType, easeIn, 0x9C);
RED4EXT_ASSERT_OFFSET(PlayerLookAt_NodeType, easeOut, 0x9D);
#else
RED4EXT_ASSERT_SIZE(PlayerLookAt_NodeType, 0xA8);
#endif
} // namespace quest
using questPlayerLookAt_NodeType = quest::PlayerLookAt_NodeType;
} // namespace RED4ext

// clang-format on
