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
struct BreachControllerComponent : ent::IComponent
{
    static constexpr const char* NAME = "gameBreachControllerComponent";
    static constexpr const char* ALIAS = "BreachControllerComponent";

#ifdef __APPLE__
    uint8_t unk8D[0xE0 - 0x8D]; // 8D
    bool canHaveBreaches; // E0
    bool allowNormalBreachesAfterWeakspotsAreDestroyed; // E1
    bool debugAllowBreachesAfterDestruction; // E2
    uint8_t unkE3[0xE4 - 0xE3]; // E3
    float breachesScale; // E4
    uint8_t unkE8[0x118 - 0xE8]; // E8
#else
    uint8_t unk90[0xE0 - 0x90]; // 90
    bool canHaveBreaches; // E0
    bool allowNormalBreachesAfterWeakspotsAreDestroyed; // E1
    bool debugAllowBreachesAfterDestruction; // E2
    uint8_t unkE3[0xE4 - 0xE3]; // E3
    float breachesScale; // E4
    uint8_t unkE8[0x118 - 0xE8]; // E8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(BreachControllerComponent, 0x118);
RED4EXT_ASSERT_OFFSET(BreachControllerComponent, canHaveBreaches, 0xE0);
RED4EXT_ASSERT_OFFSET(BreachControllerComponent, allowNormalBreachesAfterWeakspotsAreDestroyed, 0xE1);
RED4EXT_ASSERT_OFFSET(BreachControllerComponent, debugAllowBreachesAfterDestruction, 0xE2);
RED4EXT_ASSERT_OFFSET(BreachControllerComponent, breachesScale, 0xE4);
#else
RED4EXT_ASSERT_SIZE(BreachControllerComponent, 0x118);
#endif
} // namespace game
using gameBreachControllerComponent = game::BreachControllerComponent;
using BreachControllerComponent = game::BreachControllerComponent;
} // namespace RED4ext

// clang-format on
