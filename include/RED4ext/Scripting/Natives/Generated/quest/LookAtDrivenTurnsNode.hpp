#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/LookAtDrivenTurnsMode.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/SignalStoppingNodeDefinition.hpp>

namespace RED4ext
{
namespace quest
{
struct LookAtDrivenTurnsNode : quest::SignalStoppingNodeDefinition
{
    static constexpr const char* NAME = "questLookAtDrivenTurnsNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk42[0x44 - 0x42]; // 42
    quest::LookAtDrivenTurnsMode mode; // 44
    game::EntityReference puppetRef; // 48
    game::EntityReference targetRef; // 80
    bool canLookAtDrivenTurnsInterruptGesture; // B8
    uint8_t unkB9[0xC0 - 0xB9]; // B9
#else
    quest::LookAtDrivenTurnsMode mode; // 48
    uint8_t unk4C[0x50 - 0x4C]; // 4C
    game::EntityReference puppetRef; // 50
    game::EntityReference targetRef; // 88
    bool canLookAtDrivenTurnsInterruptGesture; // C0
    uint8_t unkC1[0xC8 - 0xC1]; // C1
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(LookAtDrivenTurnsNode, 0xC0);
RED4EXT_ASSERT_OFFSET(LookAtDrivenTurnsNode, mode, 0x44);
RED4EXT_ASSERT_OFFSET(LookAtDrivenTurnsNode, puppetRef, 0x48);
RED4EXT_ASSERT_OFFSET(LookAtDrivenTurnsNode, targetRef, 0x80);
RED4EXT_ASSERT_OFFSET(LookAtDrivenTurnsNode, canLookAtDrivenTurnsInterruptGesture, 0xB8);
#else
RED4EXT_ASSERT_SIZE(LookAtDrivenTurnsNode, 0xC8);
#endif
} // namespace quest
using questLookAtDrivenTurnsNode = quest::LookAtDrivenTurnsNode;
} // namespace RED4ext

// clang-format on
