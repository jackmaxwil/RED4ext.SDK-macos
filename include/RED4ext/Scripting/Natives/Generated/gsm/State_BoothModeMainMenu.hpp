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
struct State_BoothModeMainMenu : gsm::MenuState
{
    static constexpr const char* NAME = "gsmState_BoothModeMainMenu";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unkD0[0xD8 - 0xD0]; // D0
#else
    uint8_t unkD8[0xE0 - 0xD8]; // D8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(State_BoothModeMainMenu, 0xD8);
#else
RED4EXT_ASSERT_SIZE(State_BoothModeMainMenu, 0xE0);
#endif
} // namespace gsm
using gsmState_BoothModeMainMenu = gsm::State_BoothModeMainMenu;
} // namespace RED4ext

// clang-format on
