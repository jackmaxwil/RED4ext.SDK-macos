#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/GameEngine.hpp>

namespace RED4ext
{
struct InternalFunctionalTestsGameEngine : CGameEngine
{
    static constexpr const char* NAME = "InternalFunctionalTestsGameEngine";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk3C0[0x28F0 - 0x3C0]; // 3C0
#else
    uint8_t unk390[0x3638 - 0x390]; // 390
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(InternalFunctionalTestsGameEngine, 0x28F0);
#else
RED4EXT_ASSERT_SIZE(InternalFunctionalTestsGameEngine, 0x3638);
#endif
} // namespace RED4ext

// clang-format on
