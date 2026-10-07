#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/JournalEntryState.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IJournalConditionType.hpp>

namespace RED4ext
{
namespace game { struct JournalPath; }

namespace quest
{
struct JournalEntryState_ConditionType : quest::IJournalConditionType
{
    static constexpr const char* NAME = "questJournalEntryState_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    Handle<game::JournalPath> path; // 38
    game::JournalEntryState state; // 48
    bool inverted; // 4C
    uint8_t unk4D[0x50 - 0x4D]; // 4D
#else
    Handle<game::JournalPath> path; // 38
    game::JournalEntryState state; // 48
    bool inverted; // 4C
    uint8_t unk4D[0x50 - 0x4D]; // 4D
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(JournalEntryState_ConditionType, 0x50);
RED4EXT_ASSERT_OFFSET(JournalEntryState_ConditionType, path, 0x38);
RED4EXT_ASSERT_OFFSET(JournalEntryState_ConditionType, state, 0x48);
RED4EXT_ASSERT_OFFSET(JournalEntryState_ConditionType, inverted, 0x4C);
#else
RED4EXT_ASSERT_SIZE(JournalEntryState_ConditionType, 0x50);
#endif
} // namespace quest
using questJournalEntryState_ConditionType = quest::JournalEntryState_ConditionType;
} // namespace RED4ext

// clang-format on
