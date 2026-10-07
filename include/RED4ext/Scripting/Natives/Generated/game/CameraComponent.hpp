#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/BaseCameraComponent.hpp>

namespace RED4ext
{
namespace game
{
struct __declspec(align(0x10)) CameraComponent : ent::BaseCameraComponent
{
    static constexpr const char* NAME = "gameCameraComponent";
    static constexpr const char* ALIAS = "CameraComponent";

#ifdef __APPLE__
    uint8_t unk1D8[0x1E0 - 0x1D8]; // 1D8
    CName animParamFovOverrideWeight; // 1E0
    CName animParamFovOverrideValue; // 1E8
    CName animParamZoomOverrideWeight; // 1F0
    CName animParamZoomOverrideValue; // 1F8
    CName animParamZoomWeaponOverrideWeight; // 200
    CName animParamZoomWeaponOverrideValue; // 208
    CName animParamdofIntensity; // 210
    CName animParamdofNearBlur; // 218
    CName animParamdofNearFocus; // 220
    CName animParamdofFarBlur; // 228
    CName animParamdofFarFocus; // 230
    CName animParamWeaponNearPlaneCM; // 238
    CName animParamWeaponFarPlaneCM; // 240
    CName animParamWeaponEdgesSharpness; // 248
    CName animParamWeaponVignetteIntensity; // 250
    CName animParamWeaponVignetteRadius; // 258
    CName animParamWeaponVignetteCircular; // 260
    CName animParamWeaponBlurIntensity; // 268
    float zoomOverrideWeight; // 270
    float zoomOverrideValue; // 274
    float zoomWeaponOverrideWeight; // 278
    float zoomWeaponOverrideValue; // 27C
    uint8_t unk280[0x2A4 - 0x280]; // 280
    float fovOverrideWeight; // 2A4
    float fovOverrideValue; // 2A8
    uint8_t unk2AC[0x318 - 0x2AC]; // 2AC
#else
    uint8_t unk1E0[0x1E8 - 0x1E0]; // 1E0
    CName animParamFovOverrideWeight; // 1E8
    CName animParamFovOverrideValue; // 1F0
    CName animParamZoomOverrideWeight; // 1F8
    CName animParamZoomOverrideValue; // 200
    CName animParamZoomWeaponOverrideWeight; // 208
    CName animParamZoomWeaponOverrideValue; // 210
    CName animParamdofIntensity; // 218
    CName animParamdofNearBlur; // 220
    CName animParamdofNearFocus; // 228
    CName animParamdofFarBlur; // 230
    CName animParamdofFarFocus; // 238
    CName animParamWeaponNearPlaneCM; // 240
    CName animParamWeaponFarPlaneCM; // 248
    CName animParamWeaponEdgesSharpness; // 250
    CName animParamWeaponVignetteIntensity; // 258
    CName animParamWeaponVignetteRadius; // 260
    CName animParamWeaponVignetteCircular; // 268
    CName animParamWeaponBlurIntensity; // 270
    float zoomOverrideWeight; // 278
    float zoomOverrideValue; // 27C
    float zoomWeaponOverrideWeight; // 280
    float zoomWeaponOverrideValue; // 284
    uint8_t unk288[0x2AC - 0x288]; // 288
    float fovOverrideWeight; // 2AC
    float fovOverrideValue; // 2B0
    uint8_t unk2B4[0x320 - 0x2B4]; // 2B4
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CameraComponent, 0x320);
RED4EXT_ASSERT_OFFSET(CameraComponent, animParamFovOverrideWeight, 0x1E0);
RED4EXT_ASSERT_OFFSET(CameraComponent, animParamFovOverrideValue, 0x1E8);
RED4EXT_ASSERT_OFFSET(CameraComponent, animParamZoomOverrideWeight, 0x1F0);
RED4EXT_ASSERT_OFFSET(CameraComponent, animParamZoomOverrideValue, 0x1F8);
RED4EXT_ASSERT_OFFSET(CameraComponent, animParamZoomWeaponOverrideWeight, 0x200);
RED4EXT_ASSERT_OFFSET(CameraComponent, animParamZoomWeaponOverrideValue, 0x208);
RED4EXT_ASSERT_OFFSET(CameraComponent, animParamdofIntensity, 0x210);
RED4EXT_ASSERT_OFFSET(CameraComponent, animParamdofNearBlur, 0x218);
RED4EXT_ASSERT_OFFSET(CameraComponent, animParamdofNearFocus, 0x220);
RED4EXT_ASSERT_OFFSET(CameraComponent, animParamdofFarBlur, 0x228);
RED4EXT_ASSERT_OFFSET(CameraComponent, animParamdofFarFocus, 0x230);
RED4EXT_ASSERT_OFFSET(CameraComponent, animParamWeaponNearPlaneCM, 0x238);
RED4EXT_ASSERT_OFFSET(CameraComponent, animParamWeaponFarPlaneCM, 0x240);
RED4EXT_ASSERT_OFFSET(CameraComponent, animParamWeaponEdgesSharpness, 0x248);
RED4EXT_ASSERT_OFFSET(CameraComponent, animParamWeaponVignetteIntensity, 0x250);
RED4EXT_ASSERT_OFFSET(CameraComponent, animParamWeaponVignetteRadius, 0x258);
RED4EXT_ASSERT_OFFSET(CameraComponent, animParamWeaponVignetteCircular, 0x260);
RED4EXT_ASSERT_OFFSET(CameraComponent, animParamWeaponBlurIntensity, 0x268);
RED4EXT_ASSERT_OFFSET(CameraComponent, zoomOverrideWeight, 0x270);
RED4EXT_ASSERT_OFFSET(CameraComponent, zoomOverrideValue, 0x274);
RED4EXT_ASSERT_OFFSET(CameraComponent, zoomWeaponOverrideWeight, 0x278);
RED4EXT_ASSERT_OFFSET(CameraComponent, zoomWeaponOverrideValue, 0x27C);
RED4EXT_ASSERT_OFFSET(CameraComponent, fovOverrideWeight, 0x2A4);
RED4EXT_ASSERT_OFFSET(CameraComponent, fovOverrideValue, 0x2A8);
#else
RED4EXT_ASSERT_SIZE(CameraComponent, 0x320);
#endif
} // namespace game
using gameCameraComponent = game::CameraComponent;
using CameraComponent = game::CameraComponent;
} // namespace RED4ext

// clang-format on
