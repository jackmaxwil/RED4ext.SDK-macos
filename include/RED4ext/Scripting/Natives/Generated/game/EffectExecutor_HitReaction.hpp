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
struct EffectExecutor_HitReaction : game::EffectExecutor
{
    static constexpr const char* NAME = "gameEffectExecutor_HitReaction";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool npcMissEvents; // 41
    uint8_t unk42[0x48 - 0x42]; // 42
#else
    bool npcMissEvents; // 48
    uint8_t unk49[0x50 - 0x49]; // 49
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(EffectExecutor_HitReaction, 0x48);
RED4EXT_ASSERT_OFFSET(EffectExecutor_HitReaction, npcMissEvents, 0x41);
#else
RED4EXT_ASSERT_SIZE(EffectExecutor_HitReaction, 0x50);
#endif
} // namespace game
using gameEffectExecutor_HitReaction = game::EffectExecutor_HitReaction;
} // namespace RED4ext

// clang-format on
