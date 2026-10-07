#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IJournalConditionType.hpp>

namespace RED4ext
{
namespace game { struct JournalPath; }

namespace quest
{
struct JournalEntryVisited_ConditionType : quest::IJournalConditionType
{
    static constexpr const char* NAME = "questJournalEntryVisited_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    Handle<game::JournalPath> path; // 38
    bool visited; // 48
    uint8_t unk49[0x50 - 0x49]; // 49
#else
    Handle<game::JournalPath> path; // 38
    bool visited; // 48
    uint8_t unk49[0x50 - 0x49]; // 49
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(JournalEntryVisited_ConditionType, 0x50);
RED4EXT_ASSERT_OFFSET(JournalEntryVisited_ConditionType, path, 0x38);
RED4EXT_ASSERT_OFFSET(JournalEntryVisited_ConditionType, visited, 0x48);
#else
RED4EXT_ASSERT_SIZE(JournalEntryVisited_ConditionType, 0x50);
#endif
} // namespace quest
using questJournalEntryVisited_ConditionType = quest::JournalEntryVisited_ConditionType;
} // namespace RED4ext

// clang-format on
