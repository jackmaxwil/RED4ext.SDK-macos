#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/projectile/LaunchEvent.hpp>

namespace RED4ext
{
namespace game::projectile { struct TrajectoryParams; }

namespace game::projectile
{
struct __declspec(align(0x10)) SetUpAndLaunchEvent : game::projectile::LaunchEvent
{
    static constexpr const char* NAME = "gameprojectileSetUpAndLaunchEvent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    Handle<game::projectile::TrajectoryParams> trajectoryParams; // 198
    float lerpMultiplier; // 1A8
    uint8_t unk1AC[0x1B0 - 0x1AC]; // 1AC
#else
    Handle<game::projectile::TrajectoryParams> trajectoryParams; // 1A0
    float lerpMultiplier; // 1B0
    uint8_t unk1B4[0x1C0 - 0x1B4]; // 1B4
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SetUpAndLaunchEvent, 0x1B0);
RED4EXT_ASSERT_OFFSET(SetUpAndLaunchEvent, trajectoryParams, 0x198);
RED4EXT_ASSERT_OFFSET(SetUpAndLaunchEvent, lerpMultiplier, 0x1A8);
#else
RED4EXT_ASSERT_SIZE(SetUpAndLaunchEvent, 0x1C0);
#endif
} // namespace game::projectile
using gameprojectileSetUpAndLaunchEvent = game::projectile::SetUpAndLaunchEvent;
} // namespace RED4ext

// clang-format on
