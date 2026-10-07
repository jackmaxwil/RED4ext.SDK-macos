#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IGameManagerNodeType.hpp>

namespace RED4ext
{
namespace quest
{
struct SetTimer_NodeType : quest::IGameManagerNodeType
{
    static constexpr const char* NAME = "questSetTimer_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool enable; // 34
    uint8_t unk35[0x38 - 0x35]; // 35
    float duration; // 38
    uint8_t unk3C[0x40 - 0x3C]; // 3C
#else
    bool enable; // 38
    uint8_t unk39[0x3C - 0x39]; // 39
    float duration; // 3C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SetTimer_NodeType, 0x40);
RED4EXT_ASSERT_OFFSET(SetTimer_NodeType, enable, 0x34);
RED4EXT_ASSERT_OFFSET(SetTimer_NodeType, duration, 0x38);
#else
RED4EXT_ASSERT_SIZE(SetTimer_NodeType, 0x40);
#endif
} // namespace quest
using questSetTimer_NodeType = quest::SetTimer_NodeType;
} // namespace RED4ext

// clang-format on
