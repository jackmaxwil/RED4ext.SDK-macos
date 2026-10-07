#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/SmartSpot.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/SocketsForRig.hpp>

namespace RED4ext
{
namespace work { struct WorkspotResource; }

namespace AI
{
struct ActionSpot : AI::SmartSpot
{
    static constexpr const char* NAME = "AIActionSpot";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    RaRef<work::WorkspotResource> resource; // 30
    NodeRef masterNodeRef; // 38
    bool enabledWhenMasterOccupied; // 40
    bool snapToGround; // 41
    uint8_t unk42[0x44 - 0x42]; // 42
    AI::SocketsForRig ActorBodytypeE3; // 44
    uint8_t unk48[0x49 - 0x48]; // 48
    bool useClippingSpace; // 49
    uint8_t unk4A[0x4C - 0x4A]; // 4A
    float clippingSpaceOrientation; // 4C
    float clippingSpaceRange; // 50
    uint8_t unk54[0xA8 - 0x54]; // 54
#else
    RaRef<work::WorkspotResource> resource; // 30
    NodeRef masterNodeRef; // 38
    bool enabledWhenMasterOccupied; // 40
    bool snapToGround; // 41
    uint8_t unk42[0x44 - 0x42]; // 42
    AI::SocketsForRig ActorBodytypeE3; // 44
    uint8_t unk48[0x49 - 0x48]; // 48
    bool useClippingSpace; // 49
    uint8_t unk4A[0x4C - 0x4A]; // 4A
    float clippingSpaceOrientation; // 4C
    float clippingSpaceRange; // 50
    uint8_t unk54[0xC8 - 0x54]; // 54
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ActionSpot, 0xA8);
RED4EXT_ASSERT_OFFSET(ActionSpot, resource, 0x30);
RED4EXT_ASSERT_OFFSET(ActionSpot, masterNodeRef, 0x38);
RED4EXT_ASSERT_OFFSET(ActionSpot, enabledWhenMasterOccupied, 0x40);
RED4EXT_ASSERT_OFFSET(ActionSpot, snapToGround, 0x41);
RED4EXT_ASSERT_OFFSET(ActionSpot, ActorBodytypeE3, 0x44);
RED4EXT_ASSERT_OFFSET(ActionSpot, useClippingSpace, 0x49);
RED4EXT_ASSERT_OFFSET(ActionSpot, clippingSpaceOrientation, 0x4C);
RED4EXT_ASSERT_OFFSET(ActionSpot, clippingSpaceRange, 0x50);
#else
RED4EXT_ASSERT_SIZE(ActionSpot, 0xC8);
#endif
} // namespace AI
using AIActionSpot = AI::ActionSpot;
} // namespace RED4ext

// clang-format on
