#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_FloatValue.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_Event : anim::AnimNode_FloatValue
{
    static constexpr const char* NAME = "animAnimNode_Event";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x48 - 0x44]; // 44
    CName eventName; // 48
    float defaultValue; // 50
    float eventValue; // 54
    uint8_t unk58[0x68 - 0x58]; // 58
#else
    CName eventName; // 48
    float defaultValue; // 50
    float eventValue; // 54
    uint8_t unk58[0x68 - 0x58]; // 58
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_Event, 0x68);
RED4EXT_ASSERT_OFFSET(AnimNode_Event, eventName, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_Event, defaultValue, 0x50);
RED4EXT_ASSERT_OFFSET(AnimNode_Event, eventValue, 0x54);
#else
RED4EXT_ASSERT_SIZE(AnimNode_Event, 0x68);
#endif
} // namespace anim
using animAnimNode_Event = anim::AnimNode_Event;
} // namespace RED4ext

// clang-format on
