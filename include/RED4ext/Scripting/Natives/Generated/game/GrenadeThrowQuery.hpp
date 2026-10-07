#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>

namespace RED4ext
{
namespace game
{
struct __declspec(align(0x10)) GrenadeThrowQuery
{
    static constexpr const char* NAME = "gameGrenadeThrowQuery";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk00[0x1C0 - 0x0]; // 0
#else
    uint8_t unk00[0x1D0 - 0x0]; // 0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(GrenadeThrowQuery, 0x1C0);
#else
RED4EXT_ASSERT_SIZE(GrenadeThrowQuery, 0x1D0);
#endif
} // namespace game
using gameGrenadeThrowQuery = game::GrenadeThrowQuery;
} // namespace RED4ext

// clang-format on
