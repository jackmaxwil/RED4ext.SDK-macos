#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/SignalStoppingNodeDefinition.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/UnequipItemParams.hpp>

namespace RED4ext
{
namespace quest
{
struct UnequipItemNodeDefinition : quest::SignalStoppingNodeDefinition
{
    static constexpr const char* NAME = "questUnequipItemNodeDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk42[0x48 - 0x42]; // 42
    game::EntityReference entityReference; // 48
    quest::UnequipItemParams params; // 80
    uint8_t unk8C[0x90 - 0x8C]; // 8C
#else
    game::EntityReference entityReference; // 48
    quest::UnequipItemParams params; // 80
    uint8_t unk8C[0x90 - 0x8C]; // 8C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(UnequipItemNodeDefinition, 0x90);
RED4EXT_ASSERT_OFFSET(UnequipItemNodeDefinition, entityReference, 0x48);
RED4EXT_ASSERT_OFFSET(UnequipItemNodeDefinition, params, 0x80);
#else
RED4EXT_ASSERT_SIZE(UnequipItemNodeDefinition, 0x90);
#endif
} // namespace quest
using questUnequipItemNodeDefinition = quest::UnequipItemNodeDefinition;
} // namespace RED4ext

// clang-format on
