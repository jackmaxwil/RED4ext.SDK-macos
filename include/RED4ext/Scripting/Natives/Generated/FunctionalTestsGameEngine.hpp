#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/GameEngine.hpp>

namespace RED4ext
{
struct FunctionalTestsGameEngine : CGameEngine
{
    static constexpr const char* NAME = "FunctionalTestsGameEngine";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk3C0[0x28C8 - 0x3C0]; // 3C0
#else
    uint8_t unk390[0x3610 - 0x390]; // 390
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(FunctionalTestsGameEngine, 0x28C8);
#else
RED4EXT_ASSERT_SIZE(FunctionalTestsGameEngine, 0x3610);
#endif
} // namespace RED4ext

// clang-format on
