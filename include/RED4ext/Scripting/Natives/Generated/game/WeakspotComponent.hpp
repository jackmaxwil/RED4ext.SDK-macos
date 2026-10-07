#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/WeakspotPhysicalDestructionProperties.hpp>

namespace RED4ext
{
namespace game
{
struct WeakspotComponent : ent::IComponent
{
    static constexpr const char* NAME = "gameWeakspotComponent";
    static constexpr const char* ALIAS = "WeakspotComponent";

#ifdef __APPLE__
    uint8_t unk8D[0xA0 - 0x8D]; // 8D
    game::WeakspotPhysicalDestructionProperties defaultPhysicalDestructionProperties; // A0
    uint8_t unkA4[0xA8 - 0xA4]; // A4
#else
    uint8_t unk90[0xA0 - 0x90]; // 90
    game::WeakspotPhysicalDestructionProperties defaultPhysicalDestructionProperties; // A0
    uint8_t unkA4[0xA8 - 0xA4]; // A4
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(WeakspotComponent, 0xA8);
RED4EXT_ASSERT_OFFSET(WeakspotComponent, defaultPhysicalDestructionProperties, 0xA0);
#else
RED4EXT_ASSERT_SIZE(WeakspotComponent, 0xA8);
#endif
} // namespace game
using gameWeakspotComponent = game::WeakspotComponent;
using WeakspotComponent = game::WeakspotComponent;
} // namespace RED4ext

// clang-format on
