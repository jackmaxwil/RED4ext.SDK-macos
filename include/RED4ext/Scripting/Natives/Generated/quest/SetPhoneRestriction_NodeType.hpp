#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IPhoneManagerNodeType.hpp>

namespace RED4ext
{
namespace quest
{
struct SetPhoneRestriction_NodeType : quest::IPhoneManagerNodeType
{
    static constexpr const char* NAME = "questSetPhoneRestriction_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool applyPhoneRestriction; // 34
    bool blockSkipByLine; // 35
    bool forcedApply; // 36
    uint8_t unk37[0x38 - 0x37]; // 37
    CName forcedApplySource; // 38
#else
    bool applyPhoneRestriction; // 38
    bool blockSkipByLine; // 39
    bool forcedApply; // 3A
    uint8_t unk3B[0x40 - 0x3B]; // 3B
    CName forcedApplySource; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SetPhoneRestriction_NodeType, 0x40);
RED4EXT_ASSERT_OFFSET(SetPhoneRestriction_NodeType, applyPhoneRestriction, 0x34);
RED4EXT_ASSERT_OFFSET(SetPhoneRestriction_NodeType, blockSkipByLine, 0x35);
RED4EXT_ASSERT_OFFSET(SetPhoneRestriction_NodeType, forcedApply, 0x36);
RED4EXT_ASSERT_OFFSET(SetPhoneRestriction_NodeType, forcedApplySource, 0x38);
#else
RED4EXT_ASSERT_SIZE(SetPhoneRestriction_NodeType, 0x48);
#endif
} // namespace quest
using questSetPhoneRestriction_NodeType = quest::SetPhoneRestriction_NodeType;
} // namespace RED4ext

// clang-format on
