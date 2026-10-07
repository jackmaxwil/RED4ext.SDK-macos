#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIManagerNodeType.hpp>

namespace RED4ext
{
namespace game { struct JournalPath; }

namespace quest
{
struct OpenBriefing_NodeType : quest::IUIManagerNodeType
{
    static constexpr const char* NAME = "questOpenBriefing_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    Handle<game::JournalPath> briefingPath; // 38
#else
    Handle<game::JournalPath> briefingPath; // 38
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(OpenBriefing_NodeType, 0x48);
RED4EXT_ASSERT_OFFSET(OpenBriefing_NodeType, briefingPath, 0x38);
#else
RED4EXT_ASSERT_SIZE(OpenBriefing_NodeType, 0x48);
#endif
} // namespace quest
using questOpenBriefing_NodeType = quest::OpenBriefing_NodeType;
} // namespace RED4ext

// clang-format on
