#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/AIActionSubCondition_Record.hpp>

namespace RED4ext
{
namespace game::data
{
struct AIAssignedVehicleCanReachTargetCond_Record : game::data::AIActionSubCondition_Record
{
    static constexpr const char* NAME = "gamedataAIAssignedVehicleCanReachTargetCond_Record";
    static constexpr const char* ALIAS = "AIAssignedVehicleCanReachTargetCond_Record";

#ifdef __APPLE__
    uint8_t unk58[0x78 - 0x58]; // 58
#else
    uint8_t unk58[0x80 - 0x58]; // 58
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AIAssignedVehicleCanReachTargetCond_Record, 0x78);
#else
RED4EXT_ASSERT_SIZE(AIAssignedVehicleCanReachTargetCond_Record, 0x80);
#endif
} // namespace game::data
using gamedataAIAssignedVehicleCanReachTargetCond_Record = game::data::AIAssignedVehicleCanReachTargetCond_Record;
using AIAssignedVehicleCanReachTargetCond_Record = game::data::AIAssignedVehicleCanReachTargetCond_Record;
} // namespace RED4ext

// clang-format on
