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
    uint8_t unk380[0x3F0 - 0x380]; // 380
#else
    uint8_t unk350[0x400 - 0x350]; // 350
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(DebugGameEngine, 0x3F0);
#else
RED4EXT_ASSERT_SIZE(DebugGameEngine, 0x400);
#endif
} // namespace RED4ext

// clang-format on
