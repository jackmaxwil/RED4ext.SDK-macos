#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/GameEngine.hpp>

namespace RED4ext
{
struct HeadlessGameEngine : BaseGameEngine
{
    static constexpr const char* NAME = "HeadlessGameEngine";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk2F0[0x318 - 0x2F0]; // 2F0
#else
    uint8_t unk2E0[0x2E8 - 0x2E0]; // 2E0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(HeadlessGameEngine, 0x318);
#else
RED4EXT_ASSERT_SIZE(HeadlessGameEngine, 0x2E8);
#endif
} // namespace RED4ext

// clang-format on
