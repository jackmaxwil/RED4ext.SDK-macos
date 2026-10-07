#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/AICommandNodeBase.hpp>

namespace RED4ext
{
namespace quest { struct VehicleCommandParams; }

namespace quest
{
struct VehicleNodeCommandDefinition : quest::AICommandNodeBase
{
    static constexpr const char* NAME = "questVehicleNodeCommandDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk42[0x48 - 0x42]; // 42
    game::EntityReference vehicle; // 48
    Handle<quest::VehicleCommandParams> commandParams; // 80
#else
    game::EntityReference vehicle; // 48
    Handle<quest::VehicleCommandParams> commandParams; // 80
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(VehicleNodeCommandDefinition, 0x90);
RED4EXT_ASSERT_OFFSET(VehicleNodeCommandDefinition, vehicle, 0x48);
RED4EXT_ASSERT_OFFSET(VehicleNodeCommandDefinition, commandParams, 0x80);
#else
RED4EXT_ASSERT_SIZE(VehicleNodeCommandDefinition, 0x90);
#endif
} // namespace quest
using questVehicleNodeCommandDefinition = quest::VehicleNodeCommandDefinition;
} // namespace RED4ext

// clang-format on
