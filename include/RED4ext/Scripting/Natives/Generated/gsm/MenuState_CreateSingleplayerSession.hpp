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
struct MenuState_CreateSingleplayerSession : gsm::MenuState
{
    static constexpr const char* NAME = "gsmMenuState_CreateSingleplayerSession";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unkD0[0x120 - 0xD0]; // D0
#else
    uint8_t unkD8[0x128 - 0xD8]; // D8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MenuState_CreateSingleplayerSession, 0x120);
#else
RED4EXT_ASSERT_SIZE(MenuState_CreateSingleplayerSession, 0x128);
#endif
} // namespace gsm
using gsmMenuState_CreateSingleplayerSession = gsm::MenuState_CreateSingleplayerSession;
} // namespace RED4ext

// clang-format on
