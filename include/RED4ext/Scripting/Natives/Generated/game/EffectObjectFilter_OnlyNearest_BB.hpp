#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EffectInputParameter_Int.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EffectObjectFilter_OnlyNearest.hpp>

namespace RED4ext
{
namespace game
{
struct EffectObjectFilter_OnlyNearest_BB : game::EffectObjectFilter_OnlyNearest
{
    static constexpr const char* NAME = "gameEffectObjectFilter_OnlyNearest_BB";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk45[0x48 - 0x45]; // 45
    game::EffectInputParameter_Int parameter; // 48
#else
    game::EffectInputParameter_Int parameter; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(EffectObjectFilter_OnlyNearest_BB, 0x60);
RED4EXT_ASSERT_OFFSET(EffectObjectFilter_OnlyNearest_BB, parameter, 0x48);
#else
RED4EXT_ASSERT_SIZE(EffectObjectFilter_OnlyNearest_BB, 0x60);
#endif
} // namespace game
using gameEffectObjectFilter_OnlyNearest_BB = game::EffectObjectFilter_OnlyNearest_BB;
} // namespace RED4ext

// clang-format on
