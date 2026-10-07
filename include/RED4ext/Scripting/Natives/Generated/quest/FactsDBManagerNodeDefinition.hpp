#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/DisableableNodeDefinition.hpp>

namespace RED4ext
{
namespace quest { struct IFactsDBManagerNodeType; }

namespace quest
{
struct FactsDBManagerNodeDefinition : quest::DisableableNodeDefinition
{
    static constexpr const char* NAME = "questFactsDBManagerNodeDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk42[0x48 - 0x42]; // 42
    Handle<quest::IFactsDBManagerNodeType> type; // 48
#else
    Handle<quest::IFactsDBManagerNodeType> type; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(FactsDBManagerNodeDefinition, 0x58);
RED4EXT_ASSERT_OFFSET(FactsDBManagerNodeDefinition, type, 0x48);
#else
RED4EXT_ASSERT_SIZE(FactsDBManagerNodeDefinition, 0x58);
#endif
} // namespace quest
using questFactsDBManagerNodeDefinition = quest::FactsDBManagerNodeDefinition;
} // namespace RED4ext

// clang-format on
