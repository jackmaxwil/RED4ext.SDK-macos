#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EffectExecutor.hpp>

namespace RED4ext
{
namespace game { struct EffectVectorEvaluator; }
namespace world { struct Effect; }

namespace game
{
struct EffectExecutor_VisualEffect : game::EffectExecutor
{
    static constexpr const char* NAME = "gameEffectExecutor_VisualEffect";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk41[0x48 - 0x41]; // 41
    RaRef<world::Effect> effect; // 48
    bool attached; // 50
    bool breakLoopOnDetach; // 51
    uint8_t unk52[0x58 - 0x52]; // 52
    CName effectTag; // 58
    Handle<game::EffectVectorEvaluator> vectorEvaluator; // 60
#else
    RaRef<world::Effect> effect; // 48
    bool attached; // 50
    bool breakLoopOnDetach; // 51
    uint8_t unk52[0x58 - 0x52]; // 52
    CName effectTag; // 58
    Handle<game::EffectVectorEvaluator> vectorEvaluator; // 60
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(EffectExecutor_VisualEffect, 0x70);
RED4EXT_ASSERT_OFFSET(EffectExecutor_VisualEffect, effect, 0x48);
RED4EXT_ASSERT_OFFSET(EffectExecutor_VisualEffect, attached, 0x50);
RED4EXT_ASSERT_OFFSET(EffectExecutor_VisualEffect, breakLoopOnDetach, 0x51);
RED4EXT_ASSERT_OFFSET(EffectExecutor_VisualEffect, effectTag, 0x58);
RED4EXT_ASSERT_OFFSET(EffectExecutor_VisualEffect, vectorEvaluator, 0x60);
#else
RED4EXT_ASSERT_SIZE(EffectExecutor_VisualEffect, 0x70);
#endif
} // namespace game
using gameEffectExecutor_VisualEffect = game::EffectExecutor_VisualEffect;
} // namespace RED4ext

// clang-format on
