#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/RenderSettingFactors.hpp>
#include <RED4ext/Scripting/Natives/Generated/WorldLightingConfig.hpp>
#include <RED4ext/Scripting/Natives/Generated/WorldRenderAreaSettings.hpp>
#include <RED4ext/Scripting/Natives/Generated/WorldShadowConfig.hpp>

namespace RED4ext
{
namespace world { struct EnvironmentAreaParameters; }
namespace world { struct WeatherState; }
namespace world { struct WeatherStateTransition; }

namespace world
{
struct EnvironmentDefinition : CResource
{
    static constexpr const char* NAME = "worldEnvironmentDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    WorldRenderAreaSettings worldRenderSettings; // 40
    WorldShadowConfig worldShadowConfig; // 50
    WorldLightingConfig worldLightingConfig; // 78
    uint8_t unk7C[0x80 - 0x7C]; // 7C
    RenderSettingFactors renderSettingFactors; // 80
    DynArray<Ref<world::EnvironmentAreaParameters>> areaEnvironmentParameterLayers; // 160
    uint8_t unk170[0x180 - 0x170]; // 170
    uint8_t resourceVersion; // 180
    uint8_t unk181[0x188 - 0x181]; // 181
    DynArray<Handle<world::WeatherState>> weatherStates; // 188
    DynArray<Handle<world::WeatherStateTransition>> weatherStateTransitions; // 198
#else
    WorldRenderAreaSettings worldRenderSettings; // 40
    WorldShadowConfig worldShadowConfig; // 50
    WorldLightingConfig worldLightingConfig; // 78
    uint8_t unk7C[0x80 - 0x7C]; // 7C
    RenderSettingFactors renderSettingFactors; // 80
    DynArray<Ref<world::EnvironmentAreaParameters>> areaEnvironmentParameterLayers; // 160
    uint8_t unk170[0x180 - 0x170]; // 170
    uint8_t resourceVersion; // 180
    uint8_t unk181[0x188 - 0x181]; // 181
    DynArray<Handle<world::WeatherState>> weatherStates; // 188
    DynArray<Handle<world::WeatherStateTransition>> weatherStateTransitions; // 198
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(EnvironmentDefinition, 0x1A8);
RED4EXT_ASSERT_OFFSET(EnvironmentDefinition, worldRenderSettings, 0x40);
RED4EXT_ASSERT_OFFSET(EnvironmentDefinition, worldShadowConfig, 0x50);
RED4EXT_ASSERT_OFFSET(EnvironmentDefinition, worldLightingConfig, 0x78);
RED4EXT_ASSERT_OFFSET(EnvironmentDefinition, renderSettingFactors, 0x80);
RED4EXT_ASSERT_OFFSET(EnvironmentDefinition, areaEnvironmentParameterLayers, 0x160);
RED4EXT_ASSERT_OFFSET(EnvironmentDefinition, resourceVersion, 0x180);
RED4EXT_ASSERT_OFFSET(EnvironmentDefinition, weatherStates, 0x188);
RED4EXT_ASSERT_OFFSET(EnvironmentDefinition, weatherStateTransitions, 0x198);
#else
RED4EXT_ASSERT_SIZE(EnvironmentDefinition, 0x1A8);
#endif
} // namespace world
using worldEnvironmentDefinition = world::EnvironmentDefinition;
} // namespace RED4ext

// clang-format on
