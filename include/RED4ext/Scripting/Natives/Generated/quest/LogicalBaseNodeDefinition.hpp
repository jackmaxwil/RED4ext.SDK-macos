#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/SignalStoppingNodeDefinition.hpp>

namespace RED4ext
{
namespace quest
{
struct LogicalBaseNodeDefinition : quest::SignalStoppingNodeDefinition
{
    static constexpr const char* NAME = "questLogicalBaseNodeDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk42[0x44 - 0x42]; // 42
    uint32_t inputSocketCount; // 44
    uint32_t outputSocketCount; // 48
    uint8_t unk4C[0x50 - 0x4C]; // 4C
#else
    uint32_t inputSocketCount; // 48
    uint32_t outputSocketCount; // 4C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(LogicalBaseNodeDefinition, 0x50);
RED4EXT_ASSERT_OFFSET(LogicalBaseNodeDefinition, inputSocketCount, 0x44);
RED4EXT_ASSERT_OFFSET(LogicalBaseNodeDefinition, outputSocketCount, 0x48);
#else
RED4EXT_ASSERT_SIZE(LogicalBaseNodeDefinition, 0x50);
#endif
} // namespace quest
using questLogicalBaseNodeDefinition = quest::LogicalBaseNodeDefinition;
} // namespace RED4ext

// clang-format on
