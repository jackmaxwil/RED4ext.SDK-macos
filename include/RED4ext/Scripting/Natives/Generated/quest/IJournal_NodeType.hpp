#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IRetNodeType.hpp>

namespace RED4ext
{
namespace game { struct JournalPath; }

namespace quest
{
struct IJournal_NodeType : quest::IRetNodeType
{
    static constexpr const char* NAME = "questIJournal_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk30[0x38 - 0x30]; // 30
    Handle<game::JournalPath> path; // 38
    uint8_t unk48[0x4C - 0x48]; // 48
#else
    uint8_t unk30[0x38 - 0x30]; // 30
    Handle<game::JournalPath> path; // 38
    uint8_t unk48[0x50 - 0x48]; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(IJournal_NodeType, 0x50);
RED4EXT_ASSERT_OFFSET(IJournal_NodeType, path, 0x38);
#else
RED4EXT_ASSERT_SIZE(IJournal_NodeType, 0x50);
#endif
} // namespace quest
using questIJournal_NodeType = quest::IJournal_NodeType;
} // namespace RED4ext

// clang-format on
