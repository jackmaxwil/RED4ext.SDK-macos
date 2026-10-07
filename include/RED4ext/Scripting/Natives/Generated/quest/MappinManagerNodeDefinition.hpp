#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/DisableableNodeDefinition.hpp>

namespace RED4ext
{
namespace game { struct JournalPath; }

namespace quest
{
struct MappinManagerNodeDefinition : quest::DisableableNodeDefinition
{
    static constexpr const char* NAME = "questMappinManagerNodeDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk42[0x48 - 0x42]; // 42
    Handle<game::JournalPath> path; // 48
    bool disablePreviousMappins; // 58
    uint8_t unk59[0x60 - 0x59]; // 59
#else
    Handle<game::JournalPath> path; // 48
    bool disablePreviousMappins; // 58
    uint8_t unk59[0x60 - 0x59]; // 59
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MappinManagerNodeDefinition, 0x60);
RED4EXT_ASSERT_OFFSET(MappinManagerNodeDefinition, path, 0x48);
RED4EXT_ASSERT_OFFSET(MappinManagerNodeDefinition, disablePreviousMappins, 0x58);
#else
RED4EXT_ASSERT_SIZE(MappinManagerNodeDefinition, 0x60);
#endif
} // namespace quest
using questMappinManagerNodeDefinition = quest::MappinManagerNodeDefinition;
} // namespace RED4ext

// clang-format on
