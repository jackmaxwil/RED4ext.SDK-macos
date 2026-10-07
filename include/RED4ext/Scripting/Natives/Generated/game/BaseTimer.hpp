#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/IScriptable.hpp>

namespace RED4ext
{
namespace game
{
struct BaseTimer : IScriptable
{
    static constexpr const char* NAME = "gameBaseTimer";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk40[0x70 - 0x40]; // 40
#else
    uint8_t unk40[0x90 - 0x40]; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(BaseTimer, 0x70);
#else
RED4EXT_ASSERT_SIZE(BaseTimer, 0x90);
#endif
} // namespace game
using gameBaseTimer = game::BaseTimer;
} // namespace RED4ext

// clang-format on
