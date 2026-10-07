#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/MultiplayerTeleportPuppetParams.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/SignalStoppingNodeDefinition.hpp>

namespace RED4ext
{
namespace quest
{
struct MultiplayerTeleportPuppetNodeDefinition : quest::SignalStoppingNodeDefinition
{
    static constexpr const char* NAME = "questMultiplayerTeleportPuppetNodeDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk42[0x48 - 0x42]; // 42
    quest::MultiplayerTeleportPuppetParams params; // 48
#else
    quest::MultiplayerTeleportPuppetParams params; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MultiplayerTeleportPuppetNodeDefinition, 0xD8);
RED4EXT_ASSERT_OFFSET(MultiplayerTeleportPuppetNodeDefinition, params, 0x48);
#else
RED4EXT_ASSERT_SIZE(MultiplayerTeleportPuppetNodeDefinition, 0xD8);
#endif
} // namespace quest
using questMultiplayerTeleportPuppetNodeDefinition = quest::MultiplayerTeleportPuppetNodeDefinition;
} // namespace RED4ext

// clang-format on
