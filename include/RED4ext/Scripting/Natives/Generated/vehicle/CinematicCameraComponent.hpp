#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/WorldTransform.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/CameraComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/CinematicCameraShotGroup.hpp>

namespace RED4ext
{
namespace vehicle
{
struct __declspec(align(0x10)) CinematicCameraComponent : game::CameraComponent
{
    static constexpr const char* NAME = "vehicleCinematicCameraComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    DynArray<vehicle::CinematicCameraShotGroup> groups; // 318
    uint8_t unk328[0x368 - 0x328]; // 328
    bool teleportThisFrame; // 368
    uint8_t unk369[0x370 - 0x369]; // 369
    WorldTransform targetTransform; // 370
    uint8_t unk390[0x400 - 0x390]; // 390
#else
    DynArray<vehicle::CinematicCameraShotGroup> groups; // 320
    uint8_t unk330[0x370 - 0x330]; // 330
    bool teleportThisFrame; // 370
    uint8_t unk371[0x380 - 0x371]; // 371
    WorldTransform targetTransform; // 380
    uint8_t unk3A0[0x410 - 0x3A0]; // 3A0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CinematicCameraComponent, 0x400);
RED4EXT_ASSERT_OFFSET(CinematicCameraComponent, groups, 0x318);
RED4EXT_ASSERT_OFFSET(CinematicCameraComponent, teleportThisFrame, 0x368);
RED4EXT_ASSERT_OFFSET(CinematicCameraComponent, targetTransform, 0x370);
#else
RED4EXT_ASSERT_SIZE(CinematicCameraComponent, 0x410);
#endif
} // namespace vehicle
using vehicleCinematicCameraComponent = vehicle::CinematicCameraComponent;
} // namespace RED4ext

// clang-format on
