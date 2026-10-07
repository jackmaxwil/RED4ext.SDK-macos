#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/Command.hpp>

namespace RED4ext
{
namespace AI
{
struct VehicleCommand : AI::Command
{
    static constexpr const char* NAME = "AIVehicleCommand";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool useKinematic; // 60
    bool needDriver; // 61
#else
    bool useKinematic; // 60
    bool needDriver; // 61
    uint8_t unk62[0x68 - 0x62]; // 62
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(VehicleCommand, 0x68);
RED4EXT_ASSERT_OFFSET(VehicleCommand, useKinematic, 0x60);
RED4EXT_ASSERT_OFFSET(VehicleCommand, needDriver, 0x61);
#else
RED4EXT_ASSERT_SIZE(VehicleCommand, 0x68);
#endif
} // namespace AI
using AIVehicleCommand = AI::VehicleCommand;
} // namespace RED4ext

// clang-format on
