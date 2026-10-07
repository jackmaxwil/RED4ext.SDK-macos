#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/SimpleMessageType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIManagerNodeType.hpp>

namespace RED4ext
{
namespace quest
{
struct WarningMessage_NodeType : quest::IUIManagerNodeType
{
    static constexpr const char* NAME = "questWarningMessage_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    CString message; // 38
    LocalizationString localizedMessage; // 58
    float duration; // 80
    bool show; // 84
    bool instant; // 85
    uint8_t unk86[0x88 - 0x86]; // 86
    game::SimpleMessageType type; // 88
    uint8_t unk8C[0x90 - 0x8C]; // 8C
#else
    CString message; // 38
    LocalizationString localizedMessage; // 58
    float duration; // 80
    bool show; // 84
    bool instant; // 85
    uint8_t unk86[0x88 - 0x86]; // 86
    game::SimpleMessageType type; // 88
    uint8_t unk8C[0x90 - 0x8C]; // 8C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(WarningMessage_NodeType, 0x90);
RED4EXT_ASSERT_OFFSET(WarningMessage_NodeType, message, 0x38);
RED4EXT_ASSERT_OFFSET(WarningMessage_NodeType, localizedMessage, 0x58);
RED4EXT_ASSERT_OFFSET(WarningMessage_NodeType, duration, 0x80);
RED4EXT_ASSERT_OFFSET(WarningMessage_NodeType, show, 0x84);
RED4EXT_ASSERT_OFFSET(WarningMessage_NodeType, instant, 0x85);
RED4EXT_ASSERT_OFFSET(WarningMessage_NodeType, type, 0x88);
#else
RED4EXT_ASSERT_SIZE(WarningMessage_NodeType, 0x90);
#endif
} // namespace quest
using questWarningMessage_NodeType = quest::WarningMessage_NodeType;
} // namespace RED4ext

// clang-format on
