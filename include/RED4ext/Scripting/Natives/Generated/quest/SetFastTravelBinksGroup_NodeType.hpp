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
struct SetFastTravelBinksGroup_NodeType : quest::IUIManagerNodeType
{
    static constexpr const char* NAME = "questSetFastTravelBinksGroup_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    TweakDBID selectedBinkDataGroup; // 34
    uint8_t unk3C[0x40 - 0x3C]; // 3C
#else
    TweakDBID selectedBinkDataGroup; // 38
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SetFastTravelBinksGroup_NodeType, 0x40);
RED4EXT_ASSERT_OFFSET(SetFastTravelBinksGroup_NodeType, selectedBinkDataGroup, 0x34);
#else
RED4EXT_ASSERT_SIZE(SetFastTravelBinksGroup_NodeType, 0x40);
#endif
} // namespace quest
using questSetFastTravelBinksGroup_NodeType = quest::SetFastTravelBinksGroup_NodeType;
} // namespace RED4ext

// clang-format on
