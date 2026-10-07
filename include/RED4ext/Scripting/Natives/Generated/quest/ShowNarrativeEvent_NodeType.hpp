#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/Color.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIManagerNodeType.hpp>

namespace RED4ext
{
namespace quest
{
struct ShowNarrativeEvent_NodeType : quest::IUIManagerNodeType
{
    static constexpr const char* NAME = "questShowNarrativeEvent_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    CString eventText; // 38
    Color textColor; // 58
    float durationSec; // 5C
#else
    CString eventText; // 38
    Color textColor; // 58
    float durationSec; // 5C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ShowNarrativeEvent_NodeType, 0x60);
RED4EXT_ASSERT_OFFSET(ShowNarrativeEvent_NodeType, eventText, 0x38);
RED4EXT_ASSERT_OFFSET(ShowNarrativeEvent_NodeType, textColor, 0x58);
RED4EXT_ASSERT_OFFSET(ShowNarrativeEvent_NodeType, durationSec, 0x5C);
#else
RED4EXT_ASSERT_SIZE(ShowNarrativeEvent_NodeType, 0x60);
#endif
} // namespace quest
using questShowNarrativeEvent_NodeType = quest::ShowNarrativeEvent_NodeType;
} // namespace RED4ext

// clang-format on
