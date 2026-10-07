#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/anim/Event.hpp>

namespace RED4ext
{
namespace ink::anim
{
struct ChangeStateEvent : ink::anim::Event
{
    static constexpr const char* NAME = "inkanimChangeStateEvent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x48 - 0x44]; // 44
    CName state; // 48
#else
    CName state; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ChangeStateEvent, 0x50);
RED4EXT_ASSERT_OFFSET(ChangeStateEvent, state, 0x48);
#else
RED4EXT_ASSERT_SIZE(ChangeStateEvent, 0x50);
#endif
} // namespace ink::anim
using inkanimChangeStateEvent = ink::anim::ChangeStateEvent;
} // namespace RED4ext

// clang-format on
