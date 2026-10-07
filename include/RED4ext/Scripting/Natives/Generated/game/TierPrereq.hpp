#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/GameplayTier.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/IComparisonPrereq.hpp>

namespace RED4ext
{
namespace game
{
struct TierPrereq : game::IComparisonPrereq
{
    static constexpr const char* NAME = "gameTierPrereq";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    GameplayTier tier; // 44
#else
    GameplayTier tier; // 48
    uint8_t unk4C[0x50 - 0x4C]; // 4C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TierPrereq, 0x48);
RED4EXT_ASSERT_OFFSET(TierPrereq, tier, 0x44);
#else
RED4EXT_ASSERT_SIZE(TierPrereq, 0x50);
#endif
} // namespace game
using gameTierPrereq = game::TierPrereq;
} // namespace RED4ext

// clang-format on
