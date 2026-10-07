#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIManagerNodeType.hpp>

namespace RED4ext
{
namespace quest
{
struct PlayHUDEntryAnimation_NodeType : quest::IUIManagerNodeType
{
    static constexpr const char* NAME = "questPlayHUDEntryAnimation_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    CName hudEntryName; // 38
    CName animationName; // 40
    bool dependsOnTimeDilation; // 48
    uint8_t unk49[0x60 - 0x49]; // 49
#else
    CName hudEntryName; // 38
    CName animationName; // 40
    bool dependsOnTimeDilation; // 48
    uint8_t unk49[0x60 - 0x49]; // 49
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PlayHUDEntryAnimation_NodeType, 0x60);
RED4EXT_ASSERT_OFFSET(PlayHUDEntryAnimation_NodeType, hudEntryName, 0x38);
RED4EXT_ASSERT_OFFSET(PlayHUDEntryAnimation_NodeType, animationName, 0x40);
RED4EXT_ASSERT_OFFSET(PlayHUDEntryAnimation_NodeType, dependsOnTimeDilation, 0x48);
#else
RED4EXT_ASSERT_SIZE(PlayHUDEntryAnimation_NodeType, 0x60);
#endif
} // namespace quest
using questPlayHUDEntryAnimation_NodeType = quest::PlayHUDEntryAnimation_NodeType;
} // namespace RED4ext

// clang-format on
