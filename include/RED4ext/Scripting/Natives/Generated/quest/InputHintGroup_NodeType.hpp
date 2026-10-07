#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIManagerNodeType.hpp>

namespace RED4ext
{
namespace quest
{
struct InputHintGroup_NodeType : quest::IUIManagerNodeType
{
    static constexpr const char* NAME = "questInputHintGroup_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    TweakDBID iconID; // 34
    uint8_t unk3C[0x40 - 0x3C]; // 3C
    CName groupId; // 40
    CString localizedTitle; // 48
    CString localizedDescription; // 68
    bool show; // 88
    uint8_t unk89[0x90 - 0x89]; // 89
#else
    TweakDBID iconID; // 38
    CName groupId; // 40
    CString localizedTitle; // 48
    CString localizedDescription; // 68
    bool show; // 88
    uint8_t unk89[0x90 - 0x89]; // 89
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(InputHintGroup_NodeType, 0x90);
RED4EXT_ASSERT_OFFSET(InputHintGroup_NodeType, iconID, 0x34);
RED4EXT_ASSERT_OFFSET(InputHintGroup_NodeType, groupId, 0x40);
RED4EXT_ASSERT_OFFSET(InputHintGroup_NodeType, localizedTitle, 0x48);
RED4EXT_ASSERT_OFFSET(InputHintGroup_NodeType, localizedDescription, 0x68);
RED4EXT_ASSERT_OFFSET(InputHintGroup_NodeType, show, 0x88);
#else
RED4EXT_ASSERT_SIZE(InputHintGroup_NodeType, 0x90);
#endif
} // namespace quest
using questInputHintGroup_NodeType = quest::InputHintGroup_NodeType;
} // namespace RED4ext

// clang-format on
