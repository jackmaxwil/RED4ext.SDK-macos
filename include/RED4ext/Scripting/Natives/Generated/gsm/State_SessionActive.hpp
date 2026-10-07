#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/gsm/State_SessionStreamingAware.hpp>

namespace RED4ext
{
namespace gsm
{
struct State_SessionActive : gsm::State_SessionStreamingAware
{
    static constexpr const char* NAME = "gsmState_SessionActive";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unkB8[0x108 - 0xB8]; // B8
#else
    uint8_t unkC0[0x110 - 0xC0]; // C0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(State_SessionActive, 0x108);
#else
RED4EXT_ASSERT_SIZE(State_SessionActive, 0x110);
#endif
} // namespace gsm
using gsmState_SessionActive = gsm::State_SessionActive;
} // namespace RED4ext

// clang-format on
