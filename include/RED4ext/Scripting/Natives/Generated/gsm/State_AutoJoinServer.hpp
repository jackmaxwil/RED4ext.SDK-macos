#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/gsm/MenuState.hpp>

namespace RED4ext
{
namespace gsm
{
struct State_AutoJoinServer : gsm::MenuState
{
    static constexpr const char* NAME = "gsmState_AutoJoinServer";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unkD0[0x138 - 0xD0]; // D0
#else
    uint8_t unkD8[0x140 - 0xD8]; // D8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(State_AutoJoinServer, 0x138);
#else
RED4EXT_ASSERT_SIZE(State_AutoJoinServer, 0x140);
#endif
} // namespace gsm
using gsmState_AutoJoinServer = gsm::State_AutoJoinServer;
} // namespace RED4ext

// clang-format on
