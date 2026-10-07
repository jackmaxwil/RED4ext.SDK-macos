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
struct DisplayMessageBox_NodeType : quest::IUIManagerNodeType
{
    static constexpr const char* NAME = "questDisplayMessageBox_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    CString title; // 38
    LocalizationString localizedTitle; // 58
    CString message; // 80
    LocalizationString localizedMessage; // A0
#else
    CString title; // 38
    LocalizationString localizedTitle; // 58
    CString message; // 80
    LocalizationString localizedMessage; // A0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(DisplayMessageBox_NodeType, 0xC8);
RED4EXT_ASSERT_OFFSET(DisplayMessageBox_NodeType, title, 0x38);
RED4EXT_ASSERT_OFFSET(DisplayMessageBox_NodeType, localizedTitle, 0x58);
RED4EXT_ASSERT_OFFSET(DisplayMessageBox_NodeType, message, 0x80);
RED4EXT_ASSERT_OFFSET(DisplayMessageBox_NodeType, localizedMessage, 0xA0);
#else
RED4EXT_ASSERT_SIZE(DisplayMessageBox_NodeType, 0xC8);
#endif
} // namespace quest
using questDisplayMessageBox_NodeType = quest::DisplayMessageBox_NodeType;
} // namespace RED4ext

// clang-format on
