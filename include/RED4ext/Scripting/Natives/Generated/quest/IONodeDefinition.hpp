#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/DisableableNodeDefinition.hpp>

namespace RED4ext
{
namespace quest
{
struct IONodeDefinition : quest::DisableableNodeDefinition
{
    static constexpr const char* NAME = "questIONodeDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk42[0x48 - 0x42]; // 42
    CName socketName; // 48
#else
    CName socketName; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(IONodeDefinition, 0x50);
RED4EXT_ASSERT_OFFSET(IONodeDefinition, socketName, 0x48);
#else
RED4EXT_ASSERT_SIZE(IONodeDefinition, 0x50);
#endif
} // namespace quest
using questIONodeDefinition = quest::IONodeDefinition;
} // namespace RED4ext

// clang-format on
