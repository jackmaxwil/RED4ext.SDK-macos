#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>

namespace RED4ext
{
namespace game
{
struct PlayerMappinComponent : ent::IComponent
{
    static constexpr const char* NAME = "gamePlayerMappinComponent";
    static constexpr const char* ALIAS = "PlayerMappinComponent";

#ifdef __APPLE__
    uint8_t unk8D[0xA8 - 0x8D]; // 8D
#else
    uint8_t unk90[0xA8 - 0x90]; // 90
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PlayerMappinComponent, 0xA8);
#else
RED4EXT_ASSERT_SIZE(PlayerMappinComponent, 0xA8);
#endif
} // namespace game
using gamePlayerMappinComponent = game::PlayerMappinComponent;
using PlayerMappinComponent = game::PlayerMappinComponent;
} // namespace RED4ext

// clang-format on
