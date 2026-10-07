#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ScriptableSystem.hpp>

namespace RED4ext
{
namespace game
{
struct IMarketSystem : game::ScriptableSystem
{
    static constexpr const char* NAME = "gameIMarketSystem";
    static constexpr const char* ALIAS = "IMarketSystem";

#ifdef __APPLE__
    uint8_t unk530[0x5D0 - 0x530]; // 530
#else
    uint8_t unk530[0x5B8 - 0x530]; // 530
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(IMarketSystem, 0x5D0);
#else
RED4EXT_ASSERT_SIZE(IMarketSystem, 0x5B8);
#endif
} // namespace game
using gameIMarketSystem = game::IMarketSystem;
using IMarketSystem = game::IMarketSystem;
} // namespace RED4ext

// clang-format on
