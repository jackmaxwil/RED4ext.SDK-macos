#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/DisableableNodeDefinition.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/PuppetAIManagerNodeDefinitionEntry.hpp>

namespace RED4ext
{
namespace quest
{
struct PuppetAIManagerNodeDefinition : quest::DisableableNodeDefinition
{
    static constexpr const char* NAME = "questPuppetAIManagerNodeDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk42[0x48 - 0x42]; // 42
    DynArray<quest::PuppetAIManagerNodeDefinitionEntry> entries; // 48
#else
    DynArray<quest::PuppetAIManagerNodeDefinitionEntry> entries; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PuppetAIManagerNodeDefinition, 0x58);
RED4EXT_ASSERT_OFFSET(PuppetAIManagerNodeDefinition, entries, 0x48);
#else
RED4EXT_ASSERT_SIZE(PuppetAIManagerNodeDefinition, 0x58);
#endif
} // namespace quest
using questPuppetAIManagerNodeDefinition = quest::PuppetAIManagerNodeDefinition;
} // namespace RED4ext

// clang-format on
