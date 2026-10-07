#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>

namespace RED4ext
{
namespace world
{
struct TrafficLightListenerComponent : ent::IComponent
{
    static constexpr const char* NAME = "worldTrafficLightListenerComponent";
    static constexpr const char* ALIAS = "TrafficLightListenerComponent";

#ifdef __APPLE__
    uint8_t unk8D[0xA8 - 0x8D]; // 8D
    NodeRef intersectionRef; // A8
    uint32_t groupIdx; // B0
    uint8_t unkB4[0xB8 - 0xB4]; // B4
#else
    uint8_t unk90[0xA8 - 0x90]; // 90
    NodeRef intersectionRef; // A8
    uint32_t groupIdx; // B0
    uint8_t unkB4[0xB8 - 0xB4]; // B4
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TrafficLightListenerComponent, 0xB8);
RED4EXT_ASSERT_OFFSET(TrafficLightListenerComponent, intersectionRef, 0xA8);
RED4EXT_ASSERT_OFFSET(TrafficLightListenerComponent, groupIdx, 0xB0);
#else
RED4EXT_ASSERT_SIZE(TrafficLightListenerComponent, 0xB8);
#endif
} // namespace world
using worldTrafficLightListenerComponent = world::TrafficLightListenerComponent;
using TrafficLightListenerComponent = world::TrafficLightListenerComponent;
} // namespace RED4ext

// clang-format on
