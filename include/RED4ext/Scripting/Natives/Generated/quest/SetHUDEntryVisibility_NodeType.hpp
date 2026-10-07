#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIManagerNodeType.hpp>

namespace RED4ext
{
namespace quest
{
struct SetHUDEntryVisibility_NodeType : quest::IUIManagerNodeType
{
    static constexpr const char* NAME = "questSetHUDEntryVisibility_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    DynArray<CName> hudEntryName; // 38
    TweakDBID hudVisibilityPreset; // 48
    bool usePreset; // 50
    bool visibility; // 51
    uint8_t unk52[0x58 - 0x52]; // 52
#else
    DynArray<CName> hudEntryName; // 38
    TweakDBID hudVisibilityPreset; // 48
    bool usePreset; // 50
    bool visibility; // 51
    uint8_t unk52[0x58 - 0x52]; // 52
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SetHUDEntryVisibility_NodeType, 0x58);
RED4EXT_ASSERT_OFFSET(SetHUDEntryVisibility_NodeType, hudEntryName, 0x38);
RED4EXT_ASSERT_OFFSET(SetHUDEntryVisibility_NodeType, hudVisibilityPreset, 0x48);
RED4EXT_ASSERT_OFFSET(SetHUDEntryVisibility_NodeType, usePreset, 0x50);
RED4EXT_ASSERT_OFFSET(SetHUDEntryVisibility_NodeType, visibility, 0x51);
#else
RED4EXT_ASSERT_SIZE(SetHUDEntryVisibility_NodeType, 0x58);
#endif
} // namespace quest
using questSetHUDEntryVisibility_NodeType = quest::SetHUDEntryVisibility_NodeType;
} // namespace RED4ext

// clang-format on
