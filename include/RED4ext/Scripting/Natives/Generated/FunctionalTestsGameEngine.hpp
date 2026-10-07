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
    uint8_t unk380[0x2888 - 0x380]; // 380
#else
    uint8_t unk350[0x35D0 - 0x350]; // 350
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(FunctionalTestsGameEngine, 0x2888);
#else
RED4EXT_ASSERT_SIZE(FunctionalTestsGameEngine, 0x35D0);
#endif
} // namespace RED4ext

// clang-format on
