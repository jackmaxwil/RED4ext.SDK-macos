#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IWorldDataManagerNodeType.hpp>

namespace RED4ext
{
namespace quest
{
struct ShowWorldNode_NodeType : quest::IWorldDataManagerNodeType
{
    static constexpr const char* NAME = "questShowWorldNode_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    NodeRef objectRef; // 38
    bool isPlayer; // 40
    bool show; // 41
    uint8_t unk42[0x48 - 0x42]; // 42
    CName componentName; // 48
#else
    NodeRef objectRef; // 38
    bool isPlayer; // 40
    bool show; // 41
    uint8_t unk42[0x48 - 0x42]; // 42
    CName componentName; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ShowWorldNode_NodeType, 0x50);
RED4EXT_ASSERT_OFFSET(ShowWorldNode_NodeType, objectRef, 0x38);
RED4EXT_ASSERT_OFFSET(ShowWorldNode_NodeType, isPlayer, 0x40);
RED4EXT_ASSERT_OFFSET(ShowWorldNode_NodeType, show, 0x41);
RED4EXT_ASSERT_OFFSET(ShowWorldNode_NodeType, componentName, 0x48);
#else
RED4EXT_ASSERT_SIZE(ShowWorldNode_NodeType, 0x50);
#endif
} // namespace quest
using questShowWorldNode_NodeType = quest::ShowWorldNode_NodeType;
} // namespace RED4ext

// clang-format on
