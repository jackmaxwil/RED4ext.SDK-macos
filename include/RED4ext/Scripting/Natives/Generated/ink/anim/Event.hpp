#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/IScriptable.hpp>

namespace RED4ext
{
namespace ink::anim
{
struct Event : IScriptable
{
    static constexpr const char* NAME = "inkanimEvent";
    static constexpr const char* ALIAS = "inkAnimEvent";

#ifdef __APPLE__
    float startTime; // 40
#else
    float startTime; // 40
    uint8_t unk44[0x48 - 0x44]; // 44
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(Event, 0x48);
RED4EXT_ASSERT_OFFSET(Event, startTime, 0x40);
#else
RED4EXT_ASSERT_SIZE(Event, 0x48);
#endif
} // namespace ink::anim
using inkanimEvent = ink::anim::Event;
using inkAnimEvent = ink::anim::Event;
} // namespace RED4ext

// clang-format on
