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
struct EffectExecutor_NewEffect : game::EffectExecutor
{
    static constexpr const char* NAME = "gameEffectExecutor_NewEffect";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk41[0x48 - 0x41]; // 41
    CName tagInThisFile; // 48
    float forwardOffset; // 50
    bool childEffect; // 54
    uint8_t unk55[0x58 - 0x55]; // 55
    CName childEffectTag; // 58
#else
    CName tagInThisFile; // 48
    float forwardOffset; // 50
    bool childEffect; // 54
    uint8_t unk55[0x58 - 0x55]; // 55
    CName childEffectTag; // 58
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(EffectExecutor_NewEffect, 0x60);
RED4EXT_ASSERT_OFFSET(EffectExecutor_NewEffect, tagInThisFile, 0x48);
RED4EXT_ASSERT_OFFSET(EffectExecutor_NewEffect, forwardOffset, 0x50);
RED4EXT_ASSERT_OFFSET(EffectExecutor_NewEffect, childEffect, 0x54);
RED4EXT_ASSERT_OFFSET(EffectExecutor_NewEffect, childEffectTag, 0x58);
#else
RED4EXT_ASSERT_SIZE(EffectExecutor_NewEffect, 0x60);
#endif
} // namespace game
using gameEffectExecutor_NewEffect = game::EffectExecutor_NewEffect;
} // namespace RED4ext

// clang-format on
