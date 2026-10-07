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
struct EffectExecutor_NewEffect_ReflectedVector : game::EffectExecutor
{
    static constexpr const char* NAME = "gameEffectExecutor_NewEffect_ReflectedVector";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk41[0x60 - 0x41]; // 41
#else
    uint8_t unk48[0x60 - 0x48]; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(EffectExecutor_NewEffect_ReflectedVector, 0x60);
#else
RED4EXT_ASSERT_SIZE(EffectExecutor_NewEffect_ReflectedVector, 0x60);
#endif
} // namespace game
using gameEffectExecutor_NewEffect_ReflectedVector = game::EffectExecutor_NewEffect_ReflectedVector;
} // namespace RED4ext

// clang-format on
