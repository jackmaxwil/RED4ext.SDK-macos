#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/DisableableNodeDefinition.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/TeleportPuppetParams.hpp>

namespace RED4ext
{
namespace quest
{
struct TeleportVehicleNodeDefinition : quest::DisableableNodeDefinition
{
    static constexpr const char* NAME = "questTeleportVehicleNodeDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk42[0x48 - 0x42]; // 42
    game::EntityReference entityReference; // 48
    quest::TeleportPuppetParams params; // 80
    bool resetVelocities; // A0
    uint8_t unkA1[0xA8 - 0xA1]; // A1
#else
    game::EntityReference entityReference; // 48
    quest::TeleportPuppetParams params; // 80
    bool resetVelocities; // A0
    uint8_t unkA1[0xA8 - 0xA1]; // A1
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TeleportVehicleNodeDefinition, 0xA8);
RED4EXT_ASSERT_OFFSET(TeleportVehicleNodeDefinition, entityReference, 0x48);
RED4EXT_ASSERT_OFFSET(TeleportVehicleNodeDefinition, params, 0x80);
RED4EXT_ASSERT_OFFSET(TeleportVehicleNodeDefinition, resetVelocities, 0xA0);
#else
RED4EXT_ASSERT_SIZE(TeleportVehicleNodeDefinition, 0xA8);
#endif
} // namespace quest
using questTeleportVehicleNodeDefinition = quest::TeleportVehicleNodeDefinition;
} // namespace RED4ext

// clang-format on
