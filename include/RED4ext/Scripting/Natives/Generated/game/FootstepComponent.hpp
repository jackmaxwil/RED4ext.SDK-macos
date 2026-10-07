#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>

namespace RED4ext
{
namespace game
{
struct FootstepComponent : ent::IComponent
{
    static constexpr const char* NAME = "gameFootstepComponent";
    static constexpr const char* ALIAS = "FootstepComponent";

#ifdef __APPLE__
    uint8_t unk8D[0x90 - 0x8D]; // 8D
    TweakDBID tweakDBID; // 90
    CName leftFootSlot; // 98
    CName rightFootSlot; // A0
    uint8_t unkA8[0xB0 - 0xA8]; // A8
#else
    TweakDBID tweakDBID; // 90
    CName leftFootSlot; // 98
    CName rightFootSlot; // A0
    uint8_t unkA8[0xB0 - 0xA8]; // A8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(FootstepComponent, 0xB0);
RED4EXT_ASSERT_OFFSET(FootstepComponent, tweakDBID, 0x90);
RED4EXT_ASSERT_OFFSET(FootstepComponent, leftFootSlot, 0x98);
RED4EXT_ASSERT_OFFSET(FootstepComponent, rightFootSlot, 0xA0);
#else
RED4EXT_ASSERT_SIZE(FootstepComponent, 0xB0);
#endif
} // namespace game
using gameFootstepComponent = game::FootstepComponent;
using FootstepComponent = game::FootstepComponent;
} // namespace RED4ext

// clang-format on
