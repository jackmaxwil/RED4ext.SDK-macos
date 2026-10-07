#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EffectExecutor.hpp>

namespace RED4ext
{
namespace game
{
struct EffectExecutor_PhysicalImpulseFromInstigator_Value : game::EffectExecutor
{
    static constexpr const char* NAME = "gameEffectExecutor_PhysicalImpulseFromInstigator_Value";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk41[0x44 - 0x41]; // 41
    float magnitude; // 44
    bool forceUseHitPosition; // 48
    uint8_t unk49[0x50 - 0x49]; // 49
#else
    float magnitude; // 48
    bool forceUseHitPosition; // 4C
    uint8_t unk4D[0x50 - 0x4D]; // 4D
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(EffectExecutor_PhysicalImpulseFromInstigator_Value, 0x50);
RED4EXT_ASSERT_OFFSET(EffectExecutor_PhysicalImpulseFromInstigator_Value, magnitude, 0x44);
RED4EXT_ASSERT_OFFSET(EffectExecutor_PhysicalImpulseFromInstigator_Value, forceUseHitPosition, 0x48);
#else
RED4EXT_ASSERT_SIZE(EffectExecutor_PhysicalImpulseFromInstigator_Value, 0x50);
#endif
} // namespace game
using gameEffectExecutor_PhysicalImpulseFromInstigator_Value = game::EffectExecutor_PhysicalImpulseFromInstigator_Value;
} // namespace RED4ext

// clang-format on
