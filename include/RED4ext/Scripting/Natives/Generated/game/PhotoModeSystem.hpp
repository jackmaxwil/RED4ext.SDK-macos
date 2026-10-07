#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/IPhotoModeSystem.hpp>

namespace RED4ext
{
namespace game
{
struct __declspec(align(0x10)) PhotoModeSystem : game::IPhotoModeSystem
{
    static constexpr const char* NAME = "gamePhotoModeSystem";
    static constexpr const char* ALIAS = "PhotoModeSystem";

#ifdef __APPLE__
    uint8_t unk48[0xBC0 - 0x48]; // 48
#else
    uint8_t unk48[0xBA0 - 0x48]; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PhotoModeSystem, 0xBC0);
#else
RED4EXT_ASSERT_SIZE(PhotoModeSystem, 0xBA0);
#endif
} // namespace game
using gamePhotoModeSystem = game::PhotoModeSystem;
using PhotoModeSystem = game::PhotoModeSystem;
} // namespace RED4ext

// clang-format on
