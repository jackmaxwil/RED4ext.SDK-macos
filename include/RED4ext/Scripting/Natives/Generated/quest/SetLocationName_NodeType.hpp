#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIManagerNodeType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/LocationAction.hpp>

namespace RED4ext
{
namespace quest
{
struct SetLocationName_NodeType : quest::IUIManagerNodeType
{
    static constexpr const char* NAME = "questSetLocationName_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    CString locationName; // 38
    quest::LocationAction action; // 58
    TweakDBID districtID; // 5C
    bool isNewLocation; // 64
    uint8_t unk65[0x68 - 0x65]; // 65
#else
    CString locationName; // 38
    quest::LocationAction action; // 58
    TweakDBID districtID; // 5C
    bool isNewLocation; // 64
    uint8_t unk65[0x68 - 0x65]; // 65
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SetLocationName_NodeType, 0x68);
RED4EXT_ASSERT_OFFSET(SetLocationName_NodeType, locationName, 0x38);
RED4EXT_ASSERT_OFFSET(SetLocationName_NodeType, action, 0x58);
RED4EXT_ASSERT_OFFSET(SetLocationName_NodeType, districtID, 0x5C);
RED4EXT_ASSERT_OFFSET(SetLocationName_NodeType, isNewLocation, 0x64);
#else
RED4EXT_ASSERT_SIZE(SetLocationName_NodeType, 0x68);
#endif
} // namespace quest
using questSetLocationName_NodeType = quest::SetLocationName_NodeType;
} // namespace RED4ext

// clang-format on
