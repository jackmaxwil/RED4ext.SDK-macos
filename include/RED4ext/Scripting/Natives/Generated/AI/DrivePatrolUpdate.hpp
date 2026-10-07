#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/DriveCommandUpdate.hpp>

namespace RED4ext
{
namespace AI
{
struct DrivePatrolUpdate : AI::DriveCommandUpdate
{
    static constexpr const char* NAME = "AIDrivePatrolUpdate";
    static constexpr const char* ALIAS = "DrivePatrolUpdate";

#ifdef __APPLE__
    uint32_t numPatrolLoops; // 4C
    bool emergencyPatrol; // 50
    uint8_t unk51[0x58 - 0x51]; // 51
#else
    uint32_t numPatrolLoops; // 50
    bool emergencyPatrol; // 54
    uint8_t unk55[0x58 - 0x55]; // 55
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(DrivePatrolUpdate, 0x58);
RED4EXT_ASSERT_OFFSET(DrivePatrolUpdate, numPatrolLoops, 0x4C);
RED4EXT_ASSERT_OFFSET(DrivePatrolUpdate, emergencyPatrol, 0x50);
#else
RED4EXT_ASSERT_SIZE(DrivePatrolUpdate, 0x58);
#endif
} // namespace AI
using AIDrivePatrolUpdate = AI::DrivePatrolUpdate;
using DrivePatrolUpdate = AI::DrivePatrolUpdate;
} // namespace RED4ext

// clang-format on
