#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IJournal_NodeType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/JournalQuestEntry_NodeTypeNodeVersion.hpp>

namespace RED4ext
{
namespace quest
{
struct JournalQuestEntry_NodeType : quest::IJournal_NodeType
{
    static constexpr const char* NAME = "questJournalQuestEntry_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool sendNotification; // 4C
    bool trackQuest; // 4D
    uint8_t unk4E[0x60 - 0x4E]; // 4E
    bool optional; // 60
    quest::JournalQuestEntry_NodeTypeNodeVersion version; // 61
    uint8_t unk62[0x68 - 0x62]; // 62
#else
    bool sendNotification; // 50
    bool trackQuest; // 51
    uint8_t unk52[0x68 - 0x52]; // 52
    bool optional; // 68
    quest::JournalQuestEntry_NodeTypeNodeVersion version; // 69
    uint8_t unk6A[0x70 - 0x6A]; // 6A
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(JournalQuestEntry_NodeType, 0x68);
RED4EXT_ASSERT_OFFSET(JournalQuestEntry_NodeType, sendNotification, 0x4C);
RED4EXT_ASSERT_OFFSET(JournalQuestEntry_NodeType, trackQuest, 0x4D);
RED4EXT_ASSERT_OFFSET(JournalQuestEntry_NodeType, optional, 0x60);
RED4EXT_ASSERT_OFFSET(JournalQuestEntry_NodeType, version, 0x61);
#else
RED4EXT_ASSERT_SIZE(JournalQuestEntry_NodeType, 0x70);
#endif
} // namespace quest
using questJournalQuestEntry_NodeType = quest::JournalQuestEntry_NodeType;
} // namespace RED4ext

// clang-format on
