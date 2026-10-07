#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IVisualComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/rend/LightChannel.hpp>

namespace RED4ext
{
struct GeometryShape;

namespace ent
{
struct __declspec(align(0x10)) LightChannelComponent : ent::IVisualComponent
{
    static constexpr const char* NAME = "entLightChannelComponent";
    static constexpr const char* ALIAS = "LightChannelComponent";

#ifdef __APPLE__
    uint8_t unk13C[0x150 - 0x13C]; // 13C
    Handle<GeometryShape> shape; // 150
    rend::LightChannel channels; // 160
    uint8_t unk162[0x170 - 0x162]; // 162
#else
    uint8_t unk140[0x150 - 0x140]; // 140
    Handle<GeometryShape> shape; // 150
    rend::LightChannel channels; // 160
    uint8_t unk162[0x170 - 0x162]; // 162
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(LightChannelComponent, 0x170);
RED4EXT_ASSERT_OFFSET(LightChannelComponent, shape, 0x150);
RED4EXT_ASSERT_OFFSET(LightChannelComponent, channels, 0x160);
#else
RED4EXT_ASSERT_SIZE(LightChannelComponent, 0x170);
#endif
} // namespace ent
using entLightChannelComponent = ent::LightChannelComponent;
using LightChannelComponent = ent::LightChannelComponent;
} // namespace RED4ext

// clang-format on
