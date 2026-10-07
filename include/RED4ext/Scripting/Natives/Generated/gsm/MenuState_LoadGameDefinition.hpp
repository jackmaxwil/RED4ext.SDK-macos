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
struct MenuState_LoadGameDefinition : gsm::MenuState
{
    static constexpr const char* NAME = "gsmMenuState_LoadGameDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unkD0[0xF8 - 0xD0]; // D0
#else
    uint8_t unkD8[0x100 - 0xD8]; // D8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MenuState_LoadGameDefinition, 0xF8);
#else
RED4EXT_ASSERT_SIZE(MenuState_LoadGameDefinition, 0x100);
#endif
} // namespace gsm
using gsmMenuState_LoadGameDefinition = gsm::MenuState_LoadGameDefinition;
} // namespace RED4ext

// clang-format on
