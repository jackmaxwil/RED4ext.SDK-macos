#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/PhantomEntityParameters.hpp>

namespace RED4ext
{
namespace game { struct EffectComponentBinding; }

namespace game
{
struct PhantomEntityComponent : ent::IComponent
{
    static constexpr const char* NAME = "gamePhantomEntityComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk8D[0x90 - 0x8D]; // 8D
    game::PhantomEntityParameters params; // 90
    Handle<game::EffectComponentBinding> effectBinding; // D0
#else
    game::PhantomEntityParameters params; // 90
    Handle<game::EffectComponentBinding> effectBinding; // D0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PhantomEntityComponent, 0xE0);
RED4EXT_ASSERT_OFFSET(PhantomEntityComponent, params, 0x90);
RED4EXT_ASSERT_OFFSET(PhantomEntityComponent, effectBinding, 0xD0);
#else
RED4EXT_ASSERT_SIZE(PhantomEntityComponent, 0xE0);
#endif
} // namespace game
using gamePhantomEntityComponent = game::PhantomEntityComponent;
} // namespace RED4ext

// clang-format on
