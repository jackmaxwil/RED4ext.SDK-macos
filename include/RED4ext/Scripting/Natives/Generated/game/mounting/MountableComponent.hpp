#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>

namespace RED4ext
{
namespace game::mounting
{
struct MountableComponent : ent::IComponent
{
    static constexpr const char* NAME = "gamemountingMountableComponent";
    static constexpr const char* ALIAS = "MountableComponent";

#ifdef __APPLE__
    uint8_t unk8D[0x98 - 0x8D]; // 8D
#else
    uint8_t unk90[0x98 - 0x90]; // 90
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MountableComponent, 0x98);
#else
RED4EXT_ASSERT_SIZE(MountableComponent, 0x98);
#endif
} // namespace game::mounting
using gamemountingMountableComponent = game::mounting::MountableComponent;
using MountableComponent = game::mounting::MountableComponent;
} // namespace RED4ext

// clang-format on
