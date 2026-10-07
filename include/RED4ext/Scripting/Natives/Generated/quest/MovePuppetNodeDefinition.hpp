#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ConfigurableAICommandNode.hpp>

namespace RED4ext
{
namespace quest { struct AICommandParams; }

namespace quest
{
struct MovePuppetNodeDefinition : quest::ConfigurableAICommandNode
{
    static constexpr const char* NAME = "questMovePuppetNodeDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk42[0x48 - 0x42]; // 42
    game::EntityReference entityReference; // 48
    CName moveType; // 80
    Handle<quest::AICommandParams> nodeParams; // 88
#else
    game::EntityReference entityReference; // 48
    CName moveType; // 80
    Handle<quest::AICommandParams> nodeParams; // 88
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MovePuppetNodeDefinition, 0x98);
RED4EXT_ASSERT_OFFSET(MovePuppetNodeDefinition, entityReference, 0x48);
RED4EXT_ASSERT_OFFSET(MovePuppetNodeDefinition, moveType, 0x80);
RED4EXT_ASSERT_OFFSET(MovePuppetNodeDefinition, nodeParams, 0x88);
#else
RED4EXT_ASSERT_SIZE(MovePuppetNodeDefinition, 0x98);
#endif
} // namespace quest
using questMovePuppetNodeDefinition = quest::MovePuppetNodeDefinition;
} // namespace RED4ext

// clang-format on
