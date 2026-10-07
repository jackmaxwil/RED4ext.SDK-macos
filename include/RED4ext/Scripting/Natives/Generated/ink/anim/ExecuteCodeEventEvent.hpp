#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/anim/Event.hpp>

namespace RED4ext
{
namespace red { struct Event; }

namespace ink::anim
{
struct ExecuteCodeEventEvent : ink::anim::Event
{
    static constexpr const char* NAME = "inkanimExecuteCodeEventEvent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x48 - 0x44]; // 44
    Handle<red::Event> eventToExecute; // 48
#else
    Handle<red::Event> eventToExecute; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ExecuteCodeEventEvent, 0x58);
RED4EXT_ASSERT_OFFSET(ExecuteCodeEventEvent, eventToExecute, 0x48);
#else
RED4EXT_ASSERT_SIZE(ExecuteCodeEventEvent, 0x58);
#endif
} // namespace ink::anim
using inkanimExecuteCodeEventEvent = ink::anim::ExecuteCodeEventEvent;
} // namespace RED4ext

// clang-format on
