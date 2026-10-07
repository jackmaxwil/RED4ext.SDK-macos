#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>

namespace RED4ext
{
namespace game { struct PersistentState; }

namespace game
{
struct Component : ent::IComponent
{
    static constexpr const char* NAME = "gameComponent";
    static constexpr const char* ALIAS = "GameComponent";

#ifdef __APPLE__
    uint8_t unk8D[0x98 - 0x8D]; // 8D
    Handle<game::PersistentState> persistentState; // 98
#else
    uint8_t unk90[0x98 - 0x90]; // 90
    Handle<game::PersistentState> persistentState; // 98
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(Component, 0xA8);
RED4EXT_ASSERT_OFFSET(Component, persistentState, 0x98);
#else
RED4EXT_ASSERT_SIZE(Component, 0xA8);
#endif
} // namespace game
using gameComponent = game::Component;
using GameComponent = game::Component;
} // namespace RED4ext

// clang-format on
