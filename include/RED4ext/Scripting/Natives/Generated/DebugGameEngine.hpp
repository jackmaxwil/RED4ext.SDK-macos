#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/GameEngine.hpp>

namespace RED4ext
{
struct DebugGameEngine : CGameEngine
{
    static constexpr const char* NAME = "DebugGameEngine";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk3C0[0x430 - 0x3C0]; // 3C0
#else
    uint8_t unk390[0x440 - 0x390]; // 390
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(DebugGameEngine, 0x430);
#else
RED4EXT_ASSERT_SIZE(DebugGameEngine, 0x440);
#endif
} // namespace RED4ext

// clang-format on
