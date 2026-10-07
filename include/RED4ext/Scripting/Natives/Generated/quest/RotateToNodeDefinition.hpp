#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/SignalStoppingNodeDefinition.hpp>

namespace RED4ext
{
namespace quest { struct RotateToParams; }

namespace quest
{
struct RotateToNodeDefinition : quest::SignalStoppingNodeDefinition
{
    static constexpr const char* NAME = "questRotateToNodeDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk42[0x48 - 0x42]; // 42
    game::EntityReference entityReference; // 48
    Handle<quest::RotateToParams> params; // 80
#else
    game::EntityReference entityReference; // 48
    Handle<quest::RotateToParams> params; // 80
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(RotateToNodeDefinition, 0x90);
RED4EXT_ASSERT_OFFSET(RotateToNodeDefinition, entityReference, 0x48);
RED4EXT_ASSERT_OFFSET(RotateToNodeDefinition, params, 0x80);
#else
RED4EXT_ASSERT_SIZE(RotateToNodeDefinition, 0x90);
#endif
} // namespace quest
using questRotateToNodeDefinition = quest::RotateToNodeDefinition;
} // namespace RED4ext

// clang-format on
