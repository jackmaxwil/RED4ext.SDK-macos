#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/gsm/State_Session.hpp>

namespace RED4ext
{
namespace gsm
{
struct __declspec(align(0x10)) State_PreGameSession : gsm::State_Session
{
    static constexpr const char* NAME = "gsmState_PreGameSession";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk310[0x320 - 0x310]; // 310
#else
    uint8_t unk330[0x340 - 0x330]; // 330
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(State_PreGameSession, 0x320);
#else
RED4EXT_ASSERT_SIZE(State_PreGameSession, 0x340);
#endif
} // namespace gsm
using gsmState_PreGameSession = gsm::State_PreGameSession;
} // namespace RED4ext

// clang-format on
