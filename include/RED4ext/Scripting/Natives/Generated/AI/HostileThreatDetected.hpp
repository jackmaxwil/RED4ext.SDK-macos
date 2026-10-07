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
struct HostileThreatDetected : AI::AIEvent
{
    static constexpr const char* NAME = "AIHostileThreatDetected";
    static constexpr const char* ALIAS = "HostileThreatDetected";

#ifdef __APPLE__
    uint8_t unk4C[0x50 - 0x4C]; // 4C
    WeakHandle<ent::Entity> owner; // 50
    WeakHandle<ent::Entity> threat; // 60
    bool status; // 70
    uint8_t unk71[0x78 - 0x71]; // 71
#else
    WeakHandle<ent::Entity> owner; // 50
    WeakHandle<ent::Entity> threat; // 60
    bool status; // 70
    uint8_t unk71[0x78 - 0x71]; // 71
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(HostileThreatDetected, 0x78);
RED4EXT_ASSERT_OFFSET(HostileThreatDetected, owner, 0x50);
RED4EXT_ASSERT_OFFSET(HostileThreatDetected, threat, 0x60);
RED4EXT_ASSERT_OFFSET(HostileThreatDetected, status, 0x70);
#else
RED4EXT_ASSERT_SIZE(HostileThreatDetected, 0x78);
#endif
} // namespace AI
using AIHostileThreatDetected = AI::HostileThreatDetected;
using HostileThreatDetected = AI::HostileThreatDetected;
} // namespace RED4ext

// clang-format on
