#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIManagerNodeType.hpp>

namespace RED4ext
{
namespace quest
{
struct AddCombatLogMessage_NodeType : quest::IUIManagerNodeType
{
    static constexpr const char* NAME = "questAddCombatLogMessage_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    CString message; // 38
    LocalizationString localizedMessage; // 58
#else
    CString message; // 38
    LocalizationString localizedMessage; // 58
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AddCombatLogMessage_NodeType, 0x80);
RED4EXT_ASSERT_OFFSET(AddCombatLogMessage_NodeType, message, 0x38);
RED4EXT_ASSERT_OFFSET(AddCombatLogMessage_NodeType, localizedMessage, 0x58);
#else
RED4EXT_ASSERT_SIZE(AddCombatLogMessage_NodeType, 0x80);
#endif
} // namespace quest
using questAddCombatLogMessage_NodeType = quest::AddCombatLogMessage_NodeType;
} // namespace RED4ext

// clang-format on
