#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EffectExecutor.hpp>

namespace RED4ext
{
namespace world { struct Effect; }

namespace game
{
struct EffectExecutor_GroundSlamEffects : game::EffectExecutor
{
    static constexpr const char* NAME = "gameEffectExecutor_GroundSlamEffects";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk41[0x48 - 0x41]; // 41
    RaRef<world::Effect> groundEffect; // 48
    RaRef<world::Effect> waterEffect; // 50
    RaRef<world::Effect> earthquakeLevel1; // 58
    RaRef<world::Effect> earthquakeLevel2; // 60
    float earthquakeLevel1ChargeThreshold; // 68
    float earthquakeLevel2ChargeThreshold; // 6C
#else
    RaRef<world::Effect> groundEffect; // 48
    RaRef<world::Effect> waterEffect; // 50
    RaRef<world::Effect> earthquakeLevel1; // 58
    RaRef<world::Effect> earthquakeLevel2; // 60
    float earthquakeLevel1ChargeThreshold; // 68
    float earthquakeLevel2ChargeThreshold; // 6C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(EffectExecutor_GroundSlamEffects, 0x70);
RED4EXT_ASSERT_OFFSET(EffectExecutor_GroundSlamEffects, groundEffect, 0x48);
RED4EXT_ASSERT_OFFSET(EffectExecutor_GroundSlamEffects, waterEffect, 0x50);
RED4EXT_ASSERT_OFFSET(EffectExecutor_GroundSlamEffects, earthquakeLevel1, 0x58);
RED4EXT_ASSERT_OFFSET(EffectExecutor_GroundSlamEffects, earthquakeLevel2, 0x60);
RED4EXT_ASSERT_OFFSET(EffectExecutor_GroundSlamEffects, earthquakeLevel1ChargeThreshold, 0x68);
RED4EXT_ASSERT_OFFSET(EffectExecutor_GroundSlamEffects, earthquakeLevel2ChargeThreshold, 0x6C);
#else
RED4EXT_ASSERT_SIZE(EffectExecutor_GroundSlamEffects, 0x70);
#endif
} // namespace game
using gameEffectExecutor_GroundSlamEffects = game::EffectExecutor_GroundSlamEffects;
} // namespace RED4ext

// clang-format on
