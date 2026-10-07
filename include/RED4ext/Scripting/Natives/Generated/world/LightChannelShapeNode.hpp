#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/rend/LightChannel.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/GeometryShapeNode.hpp>

namespace RED4ext
{
namespace world
{
struct LightChannelShapeNode : world::GeometryShapeNode
{
    static constexpr const char* NAME = "worldLightChannelShapeNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk4D[0x50 - 0x4D]; // 4D
    float streamingDistanceFactor; // 50
    uint8_t unk54[0x58 - 0x54]; // 54
#else
    rend::LightChannel channels; // 50
    uint8_t unk52[0x54 - 0x52]; // 52
    float streamingDistanceFactor; // 54
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(LightChannelShapeNode, 0x58);
RED4EXT_ASSERT_OFFSET(LightChannelShapeNode, streamingDistanceFactor, 0x50);
#else
RED4EXT_ASSERT_SIZE(LightChannelShapeNode, 0x58);
#endif
} // namespace world
using worldLightChannelShapeNode = world::LightChannelShapeNode;
} // namespace RED4ext

// clang-format on
