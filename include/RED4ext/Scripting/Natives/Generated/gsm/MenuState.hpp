#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/gsm/State.hpp>

namespace RED4ext
{
namespace gsm
{
struct MenuState : gsm::State
{
    static constexpr const char* NAME = "gsmMenuState";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unkB8[0xD0 - 0xB8]; // B8
#else
    uint8_t unkB8[0xD8 - 0xB8]; // B8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MenuState, 0xD0);
#else
RED4EXT_ASSERT_SIZE(MenuState, 0xD8);
#endif
} // namespace gsm
using gsmMenuState = gsm::MenuState;
} // namespace RED4ext

// clang-format on
