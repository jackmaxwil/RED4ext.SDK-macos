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
struct ThreatUnconscious : AI::AIEvent
{
    static constexpr const char* NAME = "AIThreatUnconscious";
    static constexpr const char* ALIAS = "ThreatUnconscious";

#ifdef __APPLE__
    uint8_t unk4C[0x50 - 0x4C]; // 4C
    WeakHandle<ent::Entity> owner; // 50
    WeakHandle<ent::Entity> threat; // 60
    uint32_t id; // 70
    bool detected; // 74
    uint8_t unk75[0x78 - 0x75]; // 75
#else
    WeakHandle<ent::Entity> owner; // 50
    WeakHandle<ent::Entity> threat; // 60
    uint32_t id; // 70
    bool detected; // 74
    uint8_t unk75[0x78 - 0x75]; // 75
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ThreatUnconscious, 0x78);
RED4EXT_ASSERT_OFFSET(ThreatUnconscious, owner, 0x50);
RED4EXT_ASSERT_OFFSET(ThreatUnconscious, threat, 0x60);
RED4EXT_ASSERT_OFFSET(ThreatUnconscious, id, 0x70);
RED4EXT_ASSERT_OFFSET(ThreatUnconscious, detected, 0x74);
#else
RED4EXT_ASSERT_SIZE(ThreatUnconscious, 0x78);
#endif
} // namespace AI
using AIThreatUnconscious = AI::ThreatUnconscious;
using ThreatUnconscious = AI::ThreatUnconscious;
} // namespace RED4ext

// clang-format on
