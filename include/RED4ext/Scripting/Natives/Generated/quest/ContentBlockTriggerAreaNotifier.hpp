#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/ITriggerAreaNotifer.hpp>

namespace RED4ext
{
namespace quest
{
struct ContentBlockTriggerAreaNotifier : world::ITriggerAreaNotifer
{
    static constexpr const char* NAME = "questContentBlockTriggerAreaNotifier";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool resetTokenSpawnTimer; // B2
    uint8_t unkB3[0xB8 - 0xB3]; // B3
#else
    bool resetTokenSpawnTimer; // B8
    uint8_t unkB9[0xC0 - 0xB9]; // B9
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ContentBlockTriggerAreaNotifier, 0xB8);
RED4EXT_ASSERT_OFFSET(ContentBlockTriggerAreaNotifier, resetTokenSpawnTimer, 0xB2);
#else
RED4EXT_ASSERT_SIZE(ContentBlockTriggerAreaNotifier, 0xC0);
#endif
} // namespace quest
using questContentBlockTriggerAreaNotifier = quest::ContentBlockTriggerAreaNotifier;
} // namespace RED4ext

// clang-format on
