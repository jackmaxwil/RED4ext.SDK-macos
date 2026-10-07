#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IRetNodeType.hpp>

namespace RED4ext
{
namespace quest
{
struct PuppetNodeType : quest::IRetNodeType
{
    static constexpr const char* NAME = "questPuppetNodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    game::EntityReference puppetRef; // 30
    bool isPlayer; // 68
#else
    game::EntityReference puppetRef; // 30
    bool isPlayer; // 68
    uint8_t unk69[0x70 - 0x69]; // 69
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PuppetNodeType, 0x70);
RED4EXT_ASSERT_OFFSET(PuppetNodeType, puppetRef, 0x30);
RED4EXT_ASSERT_OFFSET(PuppetNodeType, isPlayer, 0x68);
#else
RED4EXT_ASSERT_SIZE(PuppetNodeType, 0x70);
#endif
} // namespace quest
using questPuppetNodeType = quest::PuppetNodeType;
} // namespace RED4ext

// clang-format on
