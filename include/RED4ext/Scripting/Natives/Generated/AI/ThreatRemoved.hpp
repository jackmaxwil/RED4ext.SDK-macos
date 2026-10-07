#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/AIEvent.hpp>

namespace RED4ext
{
namespace ent { struct Entity; }

namespace AI
{
struct ThreatRemoved : AI::AIEvent
{
    static constexpr const char* NAME = "AIThreatRemoved";
    static constexpr const char* ALIAS = "ThreatRemoved";

#ifdef __APPLE__
    uint8_t unk4C[0x50 - 0x4C]; // 4C
    WeakHandle<ent::Entity> owner; // 50
    WeakHandle<ent::Entity> threat; // 60
    bool isHostile; // 70
    bool isEnemy; // 71
    bool isDead; // 72
    bool distanceBasedInstantDrop; // 73
    uint8_t unk74[0x78 - 0x74]; // 74
#else
    WeakHandle<ent::Entity> owner; // 50
    WeakHandle<ent::Entity> threat; // 60
    bool isHostile; // 70
    bool isEnemy; // 71
    bool isDead; // 72
    bool distanceBasedInstantDrop; // 73
    uint8_t unk74[0x78 - 0x74]; // 74
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ThreatRemoved, 0x78);
RED4EXT_ASSERT_OFFSET(ThreatRemoved, owner, 0x50);
RED4EXT_ASSERT_OFFSET(ThreatRemoved, threat, 0x60);
RED4EXT_ASSERT_OFFSET(ThreatRemoved, isHostile, 0x70);
RED4EXT_ASSERT_OFFSET(ThreatRemoved, isEnemy, 0x71);
RED4EXT_ASSERT_OFFSET(ThreatRemoved, isDead, 0x72);
RED4EXT_ASSERT_OFFSET(ThreatRemoved, distanceBasedInstantDrop, 0x73);
#else
RED4EXT_ASSERT_SIZE(ThreatRemoved, 0x78);
#endif
} // namespace AI
using AIThreatRemoved = AI::ThreatRemoved;
using ThreatRemoved = AI::ThreatRemoved;
} // namespace RED4ext

// clang-format on
