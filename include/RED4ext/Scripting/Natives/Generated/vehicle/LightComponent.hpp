#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/Color.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/LightComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/ELightType.hpp>

namespace RED4ext
{
namespace vehicle
{
struct __declspec(align(0x10)) LightComponent : game::LightComponent
{
    static constexpr const char* NAME = "vehicleLightComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    vehicle::ELightType lightType; // 300
    float highBeamPitchAngle; // 304
    float highBeamRadiusMultiplier; // 308
    float highBeamConeMultiplier; // 30C
    Color emissiveColor; // 310
    bool allowSeparateEmissiveColor; // 314
    uint8_t unk315[0x340 - 0x315]; // 315
#else
    vehicle::ELightType lightType; // 310
    float highBeamPitchAngle; // 314
    float highBeamRadiusMultiplier; // 318
    float highBeamConeMultiplier; // 31C
    Color emissiveColor; // 320
    bool allowSeparateEmissiveColor; // 324
    uint8_t unk325[0x350 - 0x325]; // 325
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(LightComponent, 0x340);
RED4EXT_ASSERT_OFFSET(LightComponent, lightType, 0x300);
RED4EXT_ASSERT_OFFSET(LightComponent, highBeamPitchAngle, 0x304);
RED4EXT_ASSERT_OFFSET(LightComponent, highBeamRadiusMultiplier, 0x308);
RED4EXT_ASSERT_OFFSET(LightComponent, highBeamConeMultiplier, 0x30C);
RED4EXT_ASSERT_OFFSET(LightComponent, emissiveColor, 0x310);
RED4EXT_ASSERT_OFFSET(LightComponent, allowSeparateEmissiveColor, 0x314);
#else
RED4EXT_ASSERT_SIZE(LightComponent, 0x350);
#endif
} // namespace vehicle
using vehicleLightComponent = vehicle::LightComponent;
} // namespace RED4ext

// clang-format on
