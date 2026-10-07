#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/AIEvent.hpp>

namespace RED4ext
{
namespace AI { struct TargetTrackerComponent; }

namespace AI
{
struct RemovedAsHostileThreat : AI::AIEvent
{
    static constexpr const char* NAME = "AIRemovedAsHostileThreat";
    static constexpr const char* ALIAS = "RemovedAsHostileThreat";

#ifdef __APPLE__
    uint8_t unk4C[0x50 - 0x4C]; // 4C
    WeakHandle<AI::TargetTrackerComponent> threateningEntity; // 50
    bool threateningEntityCanTriggersCombat; // 60
    uint8_t unk61[0x68 - 0x61]; // 61
#else
    WeakHandle<AI::TargetTrackerComponent> threateningEntity; // 50
    bool threateningEntityCanTriggersCombat; // 60
    uint8_t unk61[0x68 - 0x61]; // 61
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(RemovedAsHostileThreat, 0x68);
RED4EXT_ASSERT_OFFSET(RemovedAsHostileThreat, threateningEntity, 0x50);
RED4EXT_ASSERT_OFFSET(RemovedAsHostileThreat, threateningEntityCanTriggersCombat, 0x60);
#else
RED4EXT_ASSERT_SIZE(RemovedAsHostileThreat, 0x68);
#endif
} // namespace AI
using AIRemovedAsHostileThreat = AI::RemovedAsHostileThreat;
using RemovedAsHostileThreat = AI::RemovedAsHostileThreat;
} // namespace RED4ext

// clang-format on
