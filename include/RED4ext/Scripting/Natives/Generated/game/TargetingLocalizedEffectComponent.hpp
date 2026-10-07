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
struct TargetingLocalizedEffectComponent : ent::IComponent
{
    static constexpr const char* NAME = "gameTargetingLocalizedEffectComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk8D[0x90 - 0x8D]; // 8D
    float streamingDistance; // 90
    float visibleTargetRange; // 94
#else
    float streamingDistance; // 90
    float visibleTargetRange; // 94
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TargetingLocalizedEffectComponent, 0x98);
RED4EXT_ASSERT_OFFSET(TargetingLocalizedEffectComponent, streamingDistance, 0x90);
RED4EXT_ASSERT_OFFSET(TargetingLocalizedEffectComponent, visibleTargetRange, 0x94);
#else
RED4EXT_ASSERT_SIZE(TargetingLocalizedEffectComponent, 0x98);
#endif
} // namespace game
using gameTargetingLocalizedEffectComponent = game::TargetingLocalizedEffectComponent;
} // namespace RED4ext

// clang-format on
