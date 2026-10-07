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
struct MarkerEvent : ink::anim::Event
{
    static constexpr const char* NAME = "inkanimMarkerEvent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x48 - 0x44]; // 44
    CName markerName; // 48
#else
    CName markerName; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MarkerEvent, 0x50);
RED4EXT_ASSERT_OFFSET(MarkerEvent, markerName, 0x48);
#else
RED4EXT_ASSERT_SIZE(MarkerEvent, 0x50);
#endif
} // namespace ink::anim
using inkanimMarkerEvent = ink::anim::MarkerEvent;
} // namespace RED4ext

// clang-format on
