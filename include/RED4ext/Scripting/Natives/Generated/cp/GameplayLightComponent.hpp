#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/GameTime.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/LightComponent.hpp>

namespace RED4ext
{
namespace cp
{
struct __declspec(align(0x10)) GameplayLightComponent : ent::LightComponent
{
    static constexpr const char* NAME = "cpGameplayLightComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool reactToTime; // 1F8
    uint8_t unk1F9[0x1FC - 0x1F9]; // 1F9
    GameTime begin; // 1FC
    GameTime end; // 200
    float probability; // 204
    GameTime delayRange; // 208
    uint8_t unk20C[0x220 - 0x20C]; // 20C
#else
    bool reactToTime; // 200
    uint8_t unk201[0x204 - 0x201]; // 201
    GameTime begin; // 204
    GameTime end; // 208
    float probability; // 20C
    GameTime delayRange; // 210
    uint8_t unk214[0x220 - 0x214]; // 214
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(GameplayLightComponent, 0x220);
RED4EXT_ASSERT_OFFSET(GameplayLightComponent, reactToTime, 0x1F8);
RED4EXT_ASSERT_OFFSET(GameplayLightComponent, begin, 0x1FC);
RED4EXT_ASSERT_OFFSET(GameplayLightComponent, end, 0x200);
RED4EXT_ASSERT_OFFSET(GameplayLightComponent, probability, 0x204);
RED4EXT_ASSERT_OFFSET(GameplayLightComponent, delayRange, 0x208);
#else
RED4EXT_ASSERT_SIZE(GameplayLightComponent, 0x220);
#endif
} // namespace cp
using cpGameplayLightComponent = cp::GameplayLightComponent;
} // namespace RED4ext

// clang-format on
