#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/ITriggerAreaNotifer.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/QuestPreventionNotifierActivation.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/QuestPreventionNotifierType.hpp>

namespace RED4ext
{
namespace world
{
struct QuestPreventionNotifier : world::ITriggerAreaNotifer
{
    static constexpr const char* NAME = "worldQuestPreventionNotifier";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    world::QuestPreventionNotifierActivation activation; // B2
    world::QuestPreventionNotifierType type; // B3
    uint8_t unkB4[0xB8 - 0xB4]; // B4
#else
    world::QuestPreventionNotifierActivation activation; // B8
    world::QuestPreventionNotifierType type; // B9
    uint8_t unkBA[0xC0 - 0xBA]; // BA
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(QuestPreventionNotifier, 0xB8);
RED4EXT_ASSERT_OFFSET(QuestPreventionNotifier, activation, 0xB2);
RED4EXT_ASSERT_OFFSET(QuestPreventionNotifier, type, 0xB3);
#else
RED4EXT_ASSERT_SIZE(QuestPreventionNotifier, 0xC0);
#endif
} // namespace world
using worldQuestPreventionNotifier = world::QuestPreventionNotifier;
} // namespace RED4ext

// clang-format on
