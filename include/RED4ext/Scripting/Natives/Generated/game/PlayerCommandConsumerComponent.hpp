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
struct PlayerCommandConsumerComponent : ent::IComponent
{
    static constexpr const char* NAME = "gamePlayerCommandConsumerComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk8D[0x170 - 0x8D]; // 8D
#else
    uint8_t unk90[0x170 - 0x90]; // 90
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PlayerCommandConsumerComponent, 0x170);
#else
RED4EXT_ASSERT_SIZE(PlayerCommandConsumerComponent, 0x170);
#endif
} // namespace game
using gamePlayerCommandConsumerComponent = game::PlayerCommandConsumerComponent;
} // namespace RED4ext

// clang-format on
