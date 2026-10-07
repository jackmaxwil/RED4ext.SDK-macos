#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/SWeaponPlaneParams.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IPlacedComponent.hpp>

namespace RED4ext
{
namespace ent
{
struct __declspec(align(0x10)) BaseCameraComponent : ent::IPlacedComponent
{
    static constexpr const char* NAME = "entBaseCameraComponent";
    static constexpr const char* ALIAS = "entCameraComponent";

#ifdef __APPLE__
    uint8_t unk120[0x128 - 0x120]; // 120
    float fov; // 128
    uint8_t unk12C[0x15C - 0x12C]; // 12C
    float zoom; // 15C
    uint8_t unk160[0x168 - 0x160]; // 160
    float nearPlaneOverride; // 168
    float farPlaneOverride; // 16C
    float motionBlurScale; // 170
    uint8_t unk174[0x178 - 0x174]; // 174
    SWeaponPlaneParams weaponPlane; // 178
    uint8_t unk194[0x1D8 - 0x194]; // 194
#else
    uint8_t unk120[0x128 - 0x120]; // 120
    float fov; // 128
    uint8_t unk12C[0x15C - 0x12C]; // 12C
    float zoom; // 15C
    uint8_t unk160[0x168 - 0x160]; // 160
    float nearPlaneOverride; // 168
    float farPlaneOverride; // 16C
    float motionBlurScale; // 170
    uint8_t unk174[0x178 - 0x174]; // 174
    SWeaponPlaneParams weaponPlane; // 178
    uint8_t unk194[0x1E0 - 0x194]; // 194
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(BaseCameraComponent, 0x1E0);
RED4EXT_ASSERT_OFFSET(BaseCameraComponent, fov, 0x128);
RED4EXT_ASSERT_OFFSET(BaseCameraComponent, zoom, 0x15C);
RED4EXT_ASSERT_OFFSET(BaseCameraComponent, nearPlaneOverride, 0x168);
RED4EXT_ASSERT_OFFSET(BaseCameraComponent, farPlaneOverride, 0x16C);
RED4EXT_ASSERT_OFFSET(BaseCameraComponent, motionBlurScale, 0x170);
RED4EXT_ASSERT_OFFSET(BaseCameraComponent, weaponPlane, 0x178);
#else
RED4EXT_ASSERT_SIZE(BaseCameraComponent, 0x1E0);
#endif
} // namespace ent
using entBaseCameraComponent = ent::BaseCameraComponent;
using entCameraComponent = ent::BaseCameraComponent;
} // namespace RED4ext

// clang-format on
