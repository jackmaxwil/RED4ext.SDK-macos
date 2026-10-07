#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EffectExecutor_KatanaBulletBendingEffectEntry.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EffectExecutor_Scripted.hpp>

namespace RED4ext
{
namespace game
{
struct EffectExecutor_KatanaBulletBending : game::EffectExecutor_Scripted
{
    static constexpr const char* NAME = "gameEffectExecutor_KatanaBulletBending";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk41[0x48 - 0x41]; // 41
    DynArray<game::EffectExecutor_KatanaBulletBendingEffectEntry> effects; // 48
#else
    DynArray<game::EffectExecutor_KatanaBulletBendingEffectEntry> effects; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(EffectExecutor_KatanaBulletBending, 0x58);
RED4EXT_ASSERT_OFFSET(EffectExecutor_KatanaBulletBending, effects, 0x48);
#else
RED4EXT_ASSERT_SIZE(EffectExecutor_KatanaBulletBending, 0x58);
#endif
} // namespace game
using gameEffectExecutor_KatanaBulletBending = game::EffectExecutor_KatanaBulletBending;
} // namespace RED4ext

// clang-format on
