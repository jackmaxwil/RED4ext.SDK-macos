#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IPhoneManagerNodeType.hpp>

namespace RED4ext
{
namespace game { struct JournalPath; }

namespace quest
{
struct SendMessage_NodeType : quest::IPhoneManagerNodeType
{
    static constexpr const char* NAME = "questSendMessage_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    Handle<game::JournalPath> msg; // 38
    bool sendNotification; // 48
    uint8_t unk49[0x50 - 0x49]; // 49
#else
    Handle<game::JournalPath> msg; // 38
    bool sendNotification; // 48
    uint8_t unk49[0x50 - 0x49]; // 49
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SendMessage_NodeType, 0x50);
RED4EXT_ASSERT_OFFSET(SendMessage_NodeType, msg, 0x38);
RED4EXT_ASSERT_OFFSET(SendMessage_NodeType, sendNotification, 0x48);
#else
RED4EXT_ASSERT_SIZE(SendMessage_NodeType, 0x50);
#endif
} // namespace quest
using questSendMessage_NodeType = quest::SendMessage_NodeType;
} // namespace RED4ext

// clang-format on
