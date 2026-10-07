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
struct State_ReconnectController : gsm::State
{
    static constexpr const char* NAME = "gsmState_ReconnectController";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unkB8[0xD8 - 0xB8]; // B8
#else
    uint8_t unkB8[0xE8 - 0xB8]; // B8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(State_ReconnectController, 0xD8);
#else
RED4EXT_ASSERT_SIZE(State_ReconnectController, 0xE8);
#endif
} // namespace gsm
using gsmState_ReconnectController = gsm::State_ReconnectController;
} // namespace RED4ext

// clang-format on
