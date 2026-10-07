#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/SignalStoppingNodeDefinition.hpp>

namespace RED4ext
{
namespace quest
{
struct ClearForcedBehavioursNodeDefinition : quest::SignalStoppingNodeDefinition
{
    static constexpr const char* NAME = "questClearForcedBehavioursNodeDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk42[0x48 - 0x42]; // 42
    game::EntityReference puppet; // 48
#else
    game::EntityReference puppet; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ClearForcedBehavioursNodeDefinition, 0x80);
RED4EXT_ASSERT_OFFSET(ClearForcedBehavioursNodeDefinition, puppet, 0x48);
#else
RED4EXT_ASSERT_SIZE(ClearForcedBehavioursNodeDefinition, 0x80);
#endif
} // namespace quest
using questClearForcedBehavioursNodeDefinition = quest::ClearForcedBehavioursNodeDefinition;
} // namespace RED4ext

// clang-format on
