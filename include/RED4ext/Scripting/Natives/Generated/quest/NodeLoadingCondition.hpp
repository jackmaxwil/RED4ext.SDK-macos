#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/Condition.hpp>

namespace RED4ext
{
namespace quest
{
struct NodeLoadingCondition : quest::Condition
{
    static constexpr const char* NAME = "questNodeLoadingCondition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    NodeRef objectRef; // 38
    bool inverted; // 40
    uint8_t unk41[0x48 - 0x41]; // 41
#else
    NodeRef objectRef; // 38
    bool inverted; // 40
    uint8_t unk41[0x48 - 0x41]; // 41
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(NodeLoadingCondition, 0x48);
RED4EXT_ASSERT_OFFSET(NodeLoadingCondition, objectRef, 0x38);
RED4EXT_ASSERT_OFFSET(NodeLoadingCondition, inverted, 0x40);
#else
RED4EXT_ASSERT_SIZE(NodeLoadingCondition, 0x48);
#endif
} // namespace quest
using questNodeLoadingCondition = quest::NodeLoadingCondition;
} // namespace RED4ext

// clang-format on
