#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/LightComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EMaterialZone.hpp>

namespace RED4ext
{
struct CurveSet;
namespace world { struct Effect; }

namespace game
{
struct __declspec(align(0x10)) LightComponent : ent::LightComponent
{
    static constexpr const char* NAME = "gameLightComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool emissiveOnly; // 1F8
    bool turnOnByDefault; // 1F9
    game::EMaterialZone materialZone; // 1FA
    uint8_t unk1FB[0x200 - 0x1FB]; // 1FB
    CName meshBrokenAppearance; // 200
    float onStrength; // 208
    float turnOnTime; // 20C
    CName turnOnCurve; // 210
    float turnOffTime; // 218
    uint8_t unk21C[0x220 - 0x21C]; // 21C
    CName turnOffCurve; // 220
    float loopTime; // 228
    uint8_t unk22C[0x230 - 0x22C]; // 22C
    CName loopCurve; // 230
    bool synchronizedLoop; // 238
    bool isDestructible; // 239
    uint8_t unk23A[0x240 - 0x23A]; // 23A
    CName colliderName; // 240
    CName colliderTag; // 248
    RaRef<world::Effect> destructionEffect; // 250
    Ref<CurveSet> genericCurveSetOverride; // 258
    uint8_t unk270[0x300 - 0x270]; // 270
#else
    bool emissiveOnly; // 200
    bool turnOnByDefault; // 201
    game::EMaterialZone materialZone; // 202
    uint8_t unk203[0x208 - 0x203]; // 203
    CName meshBrokenAppearance; // 208
    float onStrength; // 210
    float turnOnTime; // 214
    CName turnOnCurve; // 218
    float turnOffTime; // 220
    uint8_t unk224[0x228 - 0x224]; // 224
    CName turnOffCurve; // 228
    float loopTime; // 230
    uint8_t unk234[0x238 - 0x234]; // 234
    CName loopCurve; // 238
    bool synchronizedLoop; // 240
    bool isDestructible; // 241
    uint8_t unk242[0x248 - 0x242]; // 242
    CName colliderName; // 248
    CName colliderTag; // 250
    RaRef<world::Effect> destructionEffect; // 258
    Ref<CurveSet> genericCurveSetOverride; // 260
    uint8_t unk278[0x310 - 0x278]; // 278
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(LightComponent, 0x300);
RED4EXT_ASSERT_OFFSET(LightComponent, emissiveOnly, 0x1F8);
RED4EXT_ASSERT_OFFSET(LightComponent, turnOnByDefault, 0x1F9);
RED4EXT_ASSERT_OFFSET(LightComponent, materialZone, 0x1FA);
RED4EXT_ASSERT_OFFSET(LightComponent, meshBrokenAppearance, 0x200);
RED4EXT_ASSERT_OFFSET(LightComponent, onStrength, 0x208);
RED4EXT_ASSERT_OFFSET(LightComponent, turnOnTime, 0x20C);
RED4EXT_ASSERT_OFFSET(LightComponent, turnOnCurve, 0x210);
RED4EXT_ASSERT_OFFSET(LightComponent, turnOffTime, 0x218);
RED4EXT_ASSERT_OFFSET(LightComponent, turnOffCurve, 0x220);
RED4EXT_ASSERT_OFFSET(LightComponent, loopTime, 0x228);
RED4EXT_ASSERT_OFFSET(LightComponent, loopCurve, 0x230);
RED4EXT_ASSERT_OFFSET(LightComponent, synchronizedLoop, 0x238);
RED4EXT_ASSERT_OFFSET(LightComponent, isDestructible, 0x239);
RED4EXT_ASSERT_OFFSET(LightComponent, colliderName, 0x240);
RED4EXT_ASSERT_OFFSET(LightComponent, colliderTag, 0x248);
RED4EXT_ASSERT_OFFSET(LightComponent, destructionEffect, 0x250);
RED4EXT_ASSERT_OFFSET(LightComponent, genericCurveSetOverride, 0x258);
#else
RED4EXT_ASSERT_SIZE(LightComponent, 0x310);
#endif
} // namespace game
using gameLightComponent = game::LightComponent;
} // namespace RED4ext

// clang-format on
