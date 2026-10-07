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
namespace quest { struct UseWorkspotParamsV1; }

namespace quest
{
struct UseWorkspotNodeDefinition : quest::AICommandNodeBase
{
    static constexpr const char* NAME = "questUseWorkspotNodeDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk42[0x48 - 0x42]; // 42
    game::EntityReference entityReference; // 48
    Handle<quest::UseWorkspotParamsV1> paramsV1; // 80
#else
    game::EntityReference entityReference; // 48
    Handle<quest::UseWorkspotParamsV1> paramsV1; // 80
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(UseWorkspotNodeDefinition, 0x90);
RED4EXT_ASSERT_OFFSET(UseWorkspotNodeDefinition, entityReference, 0x48);
RED4EXT_ASSERT_OFFSET(UseWorkspotNodeDefinition, paramsV1, 0x80);
#else
RED4EXT_ASSERT_SIZE(UseWorkspotNodeDefinition, 0x90);
#endif
} // namespace quest
using questUseWorkspotNodeDefinition = quest::UseWorkspotNodeDefinition;
} // namespace RED4ext

// clang-format on
