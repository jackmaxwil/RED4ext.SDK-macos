#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ConditionItem.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/DisableableNodeDefinition.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ESwitchBehaviourType.hpp>

namespace RED4ext
{
namespace quest
{
struct SwitchNodeDefinition : quest::DisableableNodeDefinition
{
    static constexpr const char* NAME = "questSwitchNodeDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk42[0x44 - 0x42]; // 42
    quest::ESwitchBehaviourType behaviour; // 44
    DynArray<quest::ConditionItem> conditions; // 48
#else
    quest::ESwitchBehaviourType behaviour; // 48
    uint8_t unk4C[0x50 - 0x4C]; // 4C
    DynArray<quest::ConditionItem> conditions; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SwitchNodeDefinition, 0x58);
RED4EXT_ASSERT_OFFSET(SwitchNodeDefinition, behaviour, 0x44);
RED4EXT_ASSERT_OFFSET(SwitchNodeDefinition, conditions, 0x48);
#else
RED4EXT_ASSERT_SIZE(SwitchNodeDefinition, 0x60);
#endif
} // namespace quest
using questSwitchNodeDefinition = quest::SwitchNodeDefinition;
} // namespace RED4ext

// clang-format on
