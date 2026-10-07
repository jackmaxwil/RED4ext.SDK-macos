#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/StatModifierBase.hpp>

namespace RED4ext
{
namespace game
{
struct RandomStatModifier : game::StatModifierBase
{
    static constexpr const char* NAME = "gameRandomStatModifier";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk18[0x28 - 0x18]; // 18
#else
    uint8_t unk18[0x30 - 0x18]; // 18
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(RandomStatModifier, 0x28);
#else
RED4EXT_ASSERT_SIZE(RandomStatModifier, 0x30);
#endif
} // namespace game
using gameRandomStatModifier = game::RandomStatModifier;
} // namespace RED4ext

// clang-format on
