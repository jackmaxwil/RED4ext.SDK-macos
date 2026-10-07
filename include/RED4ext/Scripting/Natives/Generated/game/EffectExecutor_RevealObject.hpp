#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EffectExecutor.hpp>

namespace RED4ext
{
namespace game
{
struct EffectExecutor_RevealObject : game::EffectExecutor
{
    static constexpr const char* NAME = "gameEffectExecutor_RevealObject";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk41[0x48 - 0x41]; // 41
    CName reason; // 48
#else
    CName reason; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(EffectExecutor_RevealObject, 0x50);
RED4EXT_ASSERT_OFFSET(EffectExecutor_RevealObject, reason, 0x48);
#else
RED4EXT_ASSERT_SIZE(EffectExecutor_RevealObject, 0x50);
#endif
} // namespace game
using gameEffectExecutor_RevealObject = game::EffectExecutor_RevealObject;
} // namespace RED4ext

// clang-format on
