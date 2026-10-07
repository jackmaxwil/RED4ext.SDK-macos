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
struct EffectExecutor_BulletImpact : game::EffectExecutor
{
    static constexpr const char* NAME = "gameEffectExecutor_BulletImpact";
    static constexpr const char* ALIAS = "EffectExecutor_BulletImpact";

#ifdef __APPLE__
    bool isBackfaceImpact; // 41
    bool noAudio; // 42
    bool isMeleeAttack; // 43
    uint8_t unk44[0x48 - 0x44]; // 44
#else
    bool isBackfaceImpact; // 48
    bool noAudio; // 49
    bool isMeleeAttack; // 4A
    uint8_t unk4B[0x50 - 0x4B]; // 4B
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(EffectExecutor_BulletImpact, 0x48);
RED4EXT_ASSERT_OFFSET(EffectExecutor_BulletImpact, isBackfaceImpact, 0x41);
RED4EXT_ASSERT_OFFSET(EffectExecutor_BulletImpact, noAudio, 0x42);
RED4EXT_ASSERT_OFFSET(EffectExecutor_BulletImpact, isMeleeAttack, 0x43);
#else
RED4EXT_ASSERT_SIZE(EffectExecutor_BulletImpact, 0x50);
#endif
} // namespace game
using gameEffectExecutor_BulletImpact = game::EffectExecutor_BulletImpact;
using EffectExecutor_BulletImpact = game::EffectExecutor_BulletImpact;
} // namespace RED4ext

// clang-format on
