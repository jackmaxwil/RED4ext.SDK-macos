#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/anim/Event.hpp>

namespace RED4ext
{
namespace ink::anim
{
struct PlayVOEvent : ink::anim::Event
{
    static constexpr const char* NAME = "inkanimPlayVOEvent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x48 - 0x44]; // 44
    CString VOLine; // 48
    CString speakerName; // 68
#else
    CString VOLine; // 48
    CString speakerName; // 68
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PlayVOEvent, 0x88);
RED4EXT_ASSERT_OFFSET(PlayVOEvent, VOLine, 0x48);
RED4EXT_ASSERT_OFFSET(PlayVOEvent, speakerName, 0x68);
#else
RED4EXT_ASSERT_SIZE(PlayVOEvent, 0x88);
#endif
} // namespace ink::anim
using inkanimPlayVOEvent = ink::anim::PlayVOEvent;
} // namespace RED4ext

// clang-format on
