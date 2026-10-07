#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ISystemConditionType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/PhoneCallPhase.hpp>

namespace RED4ext
{
namespace game { struct JournalPath; }

namespace quest
{
struct Phone_ConditionType : quest::ISystemConditionType
{
    static constexpr const char* NAME = "questPhone_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    Handle<game::JournalPath> caller; // 38
    Handle<game::JournalPath> addressee; // 48
    quest::PhoneCallPhase callPhase; // 58
    uint8_t unk5C[0x60 - 0x5C]; // 5C
#else
    Handle<game::JournalPath> caller; // 38
    Handle<game::JournalPath> addressee; // 48
    quest::PhoneCallPhase callPhase; // 58
    uint8_t unk5C[0x60 - 0x5C]; // 5C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(Phone_ConditionType, 0x60);
RED4EXT_ASSERT_OFFSET(Phone_ConditionType, caller, 0x38);
RED4EXT_ASSERT_OFFSET(Phone_ConditionType, addressee, 0x48);
RED4EXT_ASSERT_OFFSET(Phone_ConditionType, callPhase, 0x58);
#else
RED4EXT_ASSERT_SIZE(Phone_ConditionType, 0x60);
#endif
} // namespace quest
using questPhone_ConditionType = quest::Phone_ConditionType;
} // namespace RED4ext

// clang-format on
