#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/UIGameContext.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIManagerNodeType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/UIGameContextRequestType.hpp>

namespace RED4ext
{
namespace quest
{
struct SetUIGameContext_NodeType : quest::IUIManagerNodeType
{
    static constexpr const char* NAME = "questSetUIGameContext_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    quest::UIGameContextRequestType requestType; // 34
    UIGameContext context; // 38
    uint8_t unk3C[0x40 - 0x3C]; // 3C
#else
    quest::UIGameContextRequestType requestType; // 38
    UIGameContext context; // 3C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SetUIGameContext_NodeType, 0x40);
RED4EXT_ASSERT_OFFSET(SetUIGameContext_NodeType, requestType, 0x34);
RED4EXT_ASSERT_OFFSET(SetUIGameContext_NodeType, context, 0x38);
#else
RED4EXT_ASSERT_SIZE(SetUIGameContext_NodeType, 0x40);
#endif
} // namespace quest
using questSetUIGameContext_NodeType = quest::SetUIGameContext_NodeType;
} // namespace RED4ext

// clang-format on
