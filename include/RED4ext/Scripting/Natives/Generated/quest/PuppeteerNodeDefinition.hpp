#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/DisableableNodeDefinition.hpp>

namespace RED4ext
{
namespace quest { struct PuppetsEffector; }

namespace quest
{
struct PuppeteerNodeDefinition : quest::DisableableNodeDefinition
{
    static constexpr const char* NAME = "questPuppeteerNodeDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk42[0x48 - 0x42]; // 42
    Handle<quest::PuppetsEffector> effector; // 48
    game::EntityReference reference; // 58
#else
    Handle<quest::PuppetsEffector> effector; // 48
    game::EntityReference reference; // 58
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PuppeteerNodeDefinition, 0x90);
RED4EXT_ASSERT_OFFSET(PuppeteerNodeDefinition, effector, 0x48);
RED4EXT_ASSERT_OFFSET(PuppeteerNodeDefinition, reference, 0x58);
#else
RED4EXT_ASSERT_SIZE(PuppeteerNodeDefinition, 0x90);
#endif
} // namespace quest
using questPuppeteerNodeDefinition = quest::PuppeteerNodeDefinition;
} // namespace RED4ext

// clang-format on
