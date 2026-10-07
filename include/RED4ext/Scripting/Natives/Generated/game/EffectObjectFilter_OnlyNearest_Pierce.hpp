#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EffectObjectFilter_OnlyNearest.hpp>

namespace RED4ext
{
namespace game
{
struct EffectObjectFilter_OnlyNearest_Pierce : game::EffectObjectFilter_OnlyNearest
{
    static constexpr const char* NAME = "gameEffectObjectFilter_OnlyNearest_Pierce";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool alwaysApplyFullWeaponCharge; // 45
    bool includePierced; // 46
    uint8_t unk47[0x48 - 0x47]; // 47
#else
    bool alwaysApplyFullWeaponCharge; // 48
    bool includePierced; // 49
    uint8_t unk4A[0x50 - 0x4A]; // 4A
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(EffectObjectFilter_OnlyNearest_Pierce, 0x48);
RED4EXT_ASSERT_OFFSET(EffectObjectFilter_OnlyNearest_Pierce, alwaysApplyFullWeaponCharge, 0x45);
RED4EXT_ASSERT_OFFSET(EffectObjectFilter_OnlyNearest_Pierce, includePierced, 0x46);
#else
RED4EXT_ASSERT_SIZE(EffectObjectFilter_OnlyNearest_Pierce, 0x50);
#endif
} // namespace game
using gameEffectObjectFilter_OnlyNearest_Pierce = game::EffectObjectFilter_OnlyNearest_Pierce;
} // namespace RED4ext

// clang-format on
