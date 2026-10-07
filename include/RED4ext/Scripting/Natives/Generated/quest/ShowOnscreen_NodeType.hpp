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
struct ShowOnscreen_NodeType : quest::IUIManagerNodeType
{
    static constexpr const char* NAME = "questShowOnscreen_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    CString message; // 38
    LocalizationString localizedMessage; // 58
    float duration; // 80
    bool show; // 84
    uint8_t unk85[0x88 - 0x85]; // 85
#else
    CString message; // 38
    LocalizationString localizedMessage; // 58
    float duration; // 80
    bool show; // 84
    uint8_t unk85[0x88 - 0x85]; // 85
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ShowOnscreen_NodeType, 0x88);
RED4EXT_ASSERT_OFFSET(ShowOnscreen_NodeType, message, 0x38);
RED4EXT_ASSERT_OFFSET(ShowOnscreen_NodeType, localizedMessage, 0x58);
RED4EXT_ASSERT_OFFSET(ShowOnscreen_NodeType, duration, 0x80);
RED4EXT_ASSERT_OFFSET(ShowOnscreen_NodeType, show, 0x84);
#else
RED4EXT_ASSERT_SIZE(ShowOnscreen_NodeType, 0x88);
#endif
} // namespace quest
using questShowOnscreen_NodeType = quest::ShowOnscreen_NodeType;
} // namespace RED4ext

// clang-format on
