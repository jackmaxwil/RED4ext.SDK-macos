#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/DisableableNodeDefinition.hpp>

namespace RED4ext
{
namespace quest { struct IRecordingNodeType; }

namespace quest
{
struct RecordingNodeDefinition : quest::DisableableNodeDefinition
{
    static constexpr const char* NAME = "questRecordingNodeDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk42[0x48 - 0x42]; // 42
    Handle<quest::IRecordingNodeType> type; // 48
#else
    Handle<quest::IRecordingNodeType> type; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(RecordingNodeDefinition, 0x58);
RED4EXT_ASSERT_OFFSET(RecordingNodeDefinition, type, 0x48);
#else
RED4EXT_ASSERT_SIZE(RecordingNodeDefinition, 0x58);
#endif
} // namespace quest
using questRecordingNodeDefinition = quest::RecordingNodeDefinition;
} // namespace RED4ext

// clang-format on
