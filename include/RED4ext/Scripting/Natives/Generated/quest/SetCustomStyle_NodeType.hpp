#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/CustomStyle.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IPhoneManagerNodeType.hpp>

namespace RED4ext
{
namespace quest
{
struct SetCustomStyle_NodeType : quest::IPhoneManagerNodeType
{
    static constexpr const char* NAME = "questSetCustomStyle_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    quest::CustomStyle style; // 34
    bool isActive; // 38
    uint8_t unk39[0x40 - 0x39]; // 39
#else
    quest::CustomStyle style; // 38
    bool isActive; // 3C
    uint8_t unk3D[0x40 - 0x3D]; // 3D
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SetCustomStyle_NodeType, 0x40);
RED4EXT_ASSERT_OFFSET(SetCustomStyle_NodeType, style, 0x34);
RED4EXT_ASSERT_OFFSET(SetCustomStyle_NodeType, isActive, 0x38);
#else
RED4EXT_ASSERT_SIZE(SetCustomStyle_NodeType, 0x40);
#endif
} // namespace quest
using questSetCustomStyle_NodeType = quest::SetCustomStyle_NodeType;
} // namespace RED4ext

// clang-format on
