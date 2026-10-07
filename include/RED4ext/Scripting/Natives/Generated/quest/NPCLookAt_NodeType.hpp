#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ISceneManagerNodeType.hpp>

namespace RED4ext
{
namespace quest
{
struct NPCLookAt_NodeType : quest::ISceneManagerNodeType
{
    static constexpr const char* NAME = "questNPCLookAt_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool assignLookAt; // 34
    bool refPlayer; // 35
    uint8_t unk36[0x38 - 0x36]; // 36
    game::EntityReference puppetRef; // 38
    game::EntityReference lookAtTargetRef; // 70
#else
    bool assignLookAt; // 38
    bool refPlayer; // 39
    uint8_t unk3A[0x40 - 0x3A]; // 3A
    game::EntityReference puppetRef; // 40
    game::EntityReference lookAtTargetRef; // 78
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(NPCLookAt_NodeType, 0xA8);
RED4EXT_ASSERT_OFFSET(NPCLookAt_NodeType, assignLookAt, 0x34);
RED4EXT_ASSERT_OFFSET(NPCLookAt_NodeType, refPlayer, 0x35);
RED4EXT_ASSERT_OFFSET(NPCLookAt_NodeType, puppetRef, 0x38);
RED4EXT_ASSERT_OFFSET(NPCLookAt_NodeType, lookAtTargetRef, 0x70);
#else
RED4EXT_ASSERT_SIZE(NPCLookAt_NodeType, 0xB0);
#endif
} // namespace quest
using questNPCLookAt_NodeType = quest::NPCLookAt_NodeType;
} // namespace RED4ext

// clang-format on
