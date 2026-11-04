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
    uint8_t unk330[0x358 - 0x330]; // 330
#else
    uint8_t unk320[0x328 - 0x320]; // 320
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(HeadlessGameEngine, 0x358);
#else
RED4EXT_ASSERT_SIZE(HeadlessGameEngine, 0x328);
#endif
} // namespace RED4ext

// clang-format on
