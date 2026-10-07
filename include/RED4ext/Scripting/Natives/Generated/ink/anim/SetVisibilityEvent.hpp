#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/anim/Event.hpp>

namespace RED4ext
{
namespace ink::anim
{
struct SetVisibilityEvent : ink::anim::Event
{
    static constexpr const char* NAME = "inkanimSetVisibilityEvent";
    static constexpr const char* ALIAS = "inkAnimSetVisibilityEvent";

#ifdef __APPLE__
    bool isVisible; // 44
    uint8_t unk45[0x48 - 0x45]; // 45
#else
    bool isVisible; // 48
    uint8_t unk49[0x50 - 0x49]; // 49
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SetVisibilityEvent, 0x48);
RED4EXT_ASSERT_OFFSET(SetVisibilityEvent, isVisible, 0x44);
#else
RED4EXT_ASSERT_SIZE(SetVisibilityEvent, 0x50);
#endif
} // namespace ink::anim
using inkanimSetVisibilityEvent = ink::anim::SetVisibilityEvent;
using inkAnimSetVisibilityEvent = ink::anim::SetVisibilityEvent;
} // namespace RED4ext

// clang-format on
