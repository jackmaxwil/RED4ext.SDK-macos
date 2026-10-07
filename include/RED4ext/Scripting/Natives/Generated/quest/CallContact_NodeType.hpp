#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IPhoneManagerNodeType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/PhoneCallMode.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/PhoneCallPhase.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/PhoneCallVisuals.hpp>

namespace RED4ext
{
namespace game { struct JournalPath; }

namespace quest
{
struct CallContact_NodeType : quest::IPhoneManagerNodeType
{
    static constexpr const char* NAME = "questCallContact_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    Handle<game::JournalPath> caller; // 38
    Handle<game::JournalPath> addressee; // 48
    quest::PhoneCallPhase phase; // 58
    quest::PhoneCallMode mode; // 5C
    NodeRef prefabNodeRef; // 60
    bool applyPhoneRestriction; // 68
    bool isRejectable; // 69
    bool showAvatar; // 6A
    uint8_t unk6B[0x6C - 0x6B]; // 6B
    quest::PhoneCallVisuals visuals; // 6C
#else
    Handle<game::JournalPath> caller; // 38
    Handle<game::JournalPath> addressee; // 48
    quest::PhoneCallPhase phase; // 58
    quest::PhoneCallMode mode; // 5C
    NodeRef prefabNodeRef; // 60
    bool applyPhoneRestriction; // 68
    bool isRejectable; // 69
    bool showAvatar; // 6A
    uint8_t unk6B[0x6C - 0x6B]; // 6B
    quest::PhoneCallVisuals visuals; // 6C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CallContact_NodeType, 0x70);
RED4EXT_ASSERT_OFFSET(CallContact_NodeType, caller, 0x38);
RED4EXT_ASSERT_OFFSET(CallContact_NodeType, addressee, 0x48);
RED4EXT_ASSERT_OFFSET(CallContact_NodeType, phase, 0x58);
RED4EXT_ASSERT_OFFSET(CallContact_NodeType, mode, 0x5C);
RED4EXT_ASSERT_OFFSET(CallContact_NodeType, prefabNodeRef, 0x60);
RED4EXT_ASSERT_OFFSET(CallContact_NodeType, applyPhoneRestriction, 0x68);
RED4EXT_ASSERT_OFFSET(CallContact_NodeType, isRejectable, 0x69);
RED4EXT_ASSERT_OFFSET(CallContact_NodeType, showAvatar, 0x6A);
RED4EXT_ASSERT_OFFSET(CallContact_NodeType, visuals, 0x6C);
#else
RED4EXT_ASSERT_SIZE(CallContact_NodeType, 0x70);
#endif
} // namespace quest
using questCallContact_NodeType = quest::CallContact_NodeType;
} // namespace RED4ext

// clang-format on
