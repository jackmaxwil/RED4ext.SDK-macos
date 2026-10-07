#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/Color.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector3.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IVisualComponent.hpp>

namespace RED4ext
{
namespace ent
{
struct __declspec(align(0x10)) FogVolumeComponent : ent::IVisualComponent
{
    static constexpr const char* NAME = "entFogVolumeComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    float blendFalloff; // 13C
    float densityFalloff; // 140
    float densityFactor; // 144
    float absorption; // 148
    Vector3 size; // 14C
    Color color; // 158
    uint8_t unk15C[0x170 - 0x15C]; // 15C
#else
    float blendFalloff; // 140
    float densityFalloff; // 144
    float densityFactor; // 148
    float absorption; // 14C
    Vector3 size; // 150
    Color color; // 15C
    uint8_t unk160[0x170 - 0x160]; // 160
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(FogVolumeComponent, 0x170);
RED4EXT_ASSERT_OFFSET(FogVolumeComponent, blendFalloff, 0x13C);
RED4EXT_ASSERT_OFFSET(FogVolumeComponent, densityFalloff, 0x140);
RED4EXT_ASSERT_OFFSET(FogVolumeComponent, densityFactor, 0x144);
RED4EXT_ASSERT_OFFSET(FogVolumeComponent, absorption, 0x148);
RED4EXT_ASSERT_OFFSET(FogVolumeComponent, size, 0x14C);
RED4EXT_ASSERT_OFFSET(FogVolumeComponent, color, 0x158);
#else
RED4EXT_ASSERT_SIZE(FogVolumeComponent, 0x170);
#endif
} // namespace ent
using entFogVolumeComponent = ent::FogVolumeComponent;
} // namespace RED4ext

// clang-format on
