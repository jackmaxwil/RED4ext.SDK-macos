#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/anim/Event.hpp>

namespace RED4ext
{
namespace ink { struct StyleResource; }

namespace ink::anim
{
struct SetStyleEvent : ink::anim::Event
{
    static constexpr const char* NAME = "inkanimSetStyleEvent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x48 - 0x44]; // 44
    RaRef<ink::StyleResource> style; // 48
#else
    RaRef<ink::StyleResource> style; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SetStyleEvent, 0x50);
RED4EXT_ASSERT_OFFSET(SetStyleEvent, style, 0x48);
#else
RED4EXT_ASSERT_SIZE(SetStyleEvent, 0x50);
#endif
} // namespace ink::anim
using inkanimSetStyleEvent = ink::anim::SetStyleEvent;
} // namespace RED4ext

// clang-format on
