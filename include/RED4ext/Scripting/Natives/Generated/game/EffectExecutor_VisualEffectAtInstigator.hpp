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
struct EffectExecutor_VisualEffectAtInstigator : game::EffectExecutor
{
    static constexpr const char* NAME = "gameEffectExecutor_VisualEffectAtInstigator";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk41[0x48 - 0x41]; // 41
    RaRef<world::Effect> effect; // 48
#else
    RaRef<world::Effect> effect; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(EffectExecutor_VisualEffectAtInstigator, 0x50);
RED4EXT_ASSERT_OFFSET(EffectExecutor_VisualEffectAtInstigator, effect, 0x48);
#else
RED4EXT_ASSERT_SIZE(EffectExecutor_VisualEffectAtInstigator, 0x50);
#endif
} // namespace game
using gameEffectExecutor_VisualEffectAtInstigator = game::EffectExecutor_VisualEffectAtInstigator;
} // namespace RED4ext

// clang-format on
